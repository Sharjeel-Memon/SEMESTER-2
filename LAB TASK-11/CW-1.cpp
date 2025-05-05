#include <iostream>
#include <any>
#include <string>
#include <exception>

class BadTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "BadTypeException: Requested type does not match stored type.";
    }
};

class TypeSafeContainer {
private:
    std::any data;

public:
    // Store any type
    template <typename T>
    void store(const T& value) {
        data = value;
    }

    // Get the stored value safely
    template <typename T>
    T get() const {
        if (!data.has_value()) {
            throw BadTypeException();
        }

        try {
            return std::any_cast<T>(data);
        } catch (const std::bad_any_cast&) {
            throw BadTypeException();
        }
    }
};

int main() {
    TypeSafeContainer container;

    container.store<std::string>("Hello World");

    try {
        std::string str = container.get<std::string>();
        std::cout << "Retrieved: " << str << "\n";

        int num = container.get<int>(); // Will throw
        std::cout << "Retrieved number: " << num << "\n";
    } catch (const BadTypeException& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
