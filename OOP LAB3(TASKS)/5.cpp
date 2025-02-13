#include <iostream>
#include <string>

// ./5 "Harry Potter and the Sorcerer's Stone" "978-0439708180" "J.K. Rowling" "Scholastic" "Harry Potter and the Chamber of Secrets" "978-0439064873" "J.K. Rowling" "Scholastic" "Harry Potter and the Prisoner of Azkaban" "978-0439136365" "J.K. Rowling" "Scholastic" "Harry Potter and the Goblet of Fire" "978-0439139601" "J.K. Rowling" "Scholastic" "Harry Potter and the Order of the Phoenix" "978-0439358071" "J.K. Rowling" "Scholastic"

using namespace std;

class Book {
public:
    string name;
    string isbn;
    string author;
    string publisher;

    Book() {
        this->name = "";
        this->isbn = "";
        this->author = "";
        this->publisher = "";
    }

    // Parameterized Constructor
    Book(string w, string x, string y, string z) {
        this->name = w;
        this->isbn = x;
        this->author = y;
        this->publisher = z;
    }

    // Getter methods
    string getname() {
        return this->name;
    }

    string getisbn() {
        return this->isbn;
    }

    string getauthor() {
        return this->author;
    }

    string getpublisher() {
        return this->publisher;
    }

    // Display Method
    string getBookInfo() {
        return "Name: " + this->name + "\nISBN: " + this->isbn + "\nAuthor: " + this->author + "\nPublisher: " + this->publisher;
    }
};

int main(int argc, char* argv[]) {
    // Checking arguments
    if (argc < 21) {
        cout << "Not enough arguments. Please provide 5 books with 4 properties /attributes each." << endl;
        return 1;
    }

    // Objects array
    Book books[5];

    int count = 1;
    for (int i = 0; i < 5; i++) {
        books[i] = Book(argv[count], argv[count + 1], argv[count + 2], argv[count + 3]);
        count += 4;  // +4 so move to next book arguments
    }

    // Output
    for (int i = 0; i < 5; i++) {
        cout << "\nBook " << i + 1 << " Information:" << endl;
        cout << books[i].getBookInfo() << endl;
    }

    return 0;
}