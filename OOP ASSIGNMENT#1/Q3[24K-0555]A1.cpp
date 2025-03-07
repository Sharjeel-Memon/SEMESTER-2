#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string model;
    double rentalPricePerDay;
    string requiredLicenseType;
    bool isRented;

public:
    Vehicle(const string& model = "", double rentalPricePerDay = 0.0, const string& requiredLicenseType = "")
        : model(model), rentalPricePerDay(rentalPricePerDay), requiredLicenseType(requiredLicenseType), isRented(false) {}

    ~Vehicle() {
        cout << "Vehicle " << model << " has been deleted." << endl;
    }

    void setModel(const string& model) { this->model = model; }
    void setRentalPricePerDay(double rentalPricePerDay) { this->rentalPricePerDay = rentalPricePerDay; }
    void setRequiredLicenseType(const string& requiredLicenseType) { this->requiredLicenseType = requiredLicenseType; }

    string getModel() const { return model; }
    double getRentalPricePerDay() const { return rentalPricePerDay; }
    string getRequiredLicenseType() const { return requiredLicenseType; }
    bool getIsRented() const { return isRented; }
    void rentVehicle() { isRented = true; }
    void returnVehicle() { isRented = false; }

    bool isEligible(const string& userLicenseType) const {
        if (userLicenseType == "Full") return true;
        if (userLicenseType == "Intermediate" && (requiredLicenseType == "Learner" || requiredLicenseType == "Intermediate")) return true;
        return userLicenseType == requiredLicenseType;
    }
};

class User {
private:
    string name;
    int age;
    string licenseType;
    string contactInfo;
    string userID;
    Vehicle* rentedVehicle;

public:
    User(const string& name = "", int age = 0, const string& licenseType = "", const string& contactInfo = "", const string& userID = "")
        : name(name), age(age), licenseType(licenseType), contactInfo(contactInfo), userID(userID), rentedVehicle(nullptr) {}

    ~User() {
        cout << "User " << name << " has been deleted." << endl;
    }

    void updateInfo() {
        cout << "Enter updated Name: ";
        getline(cin, name);
        cout << "Enter updated Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter updated License Type (Learner/Intermediate/Full): ";
        getline(cin, licenseType);
        cout << "Enter updated Contact Info: ";
        getline(cin, contactInfo);
        cout << "User information updated successfully!" << endl;
    }

    string getUserID() const { return userID; }
    string getLicenseType() const { return licenseType; }

    void rentVehicle(Vehicle* vehicle) {
        if (vehicle->isEligible(licenseType) && !vehicle->getIsRented()) {
            rentedVehicle = vehicle;
            vehicle->rentVehicle();
            cout << name << " has successfully rented " << vehicle->getModel() << " for $" << vehicle->getRentalPricePerDay() << " per day." << endl;
        } else {
            cout << name << " is not eligible or vehicle is already rented." << endl;
        }
    }

    void viewRentedVehicle() const {
        if (rentedVehicle)
            cout << name << " has rented: " << rentedVehicle->getModel() << endl;
        else
            cout << name << " has not rented any vehicle." << endl;
    }
};

class VehicleRentalSystem {
private:
    User* users[100];
    int userCount;
    Vehicle* vehicles[100];
    int vehicleCount;

public:
    VehicleRentalSystem() : userCount(0), vehicleCount(0) {}
    ~VehicleRentalSystem() {
        for (int i = 0; i < userCount; ++i) delete users[i];
        for (int i = 0; i < vehicleCount; ++i) delete vehicles[i];
    }

    void registerUser() {
        string name, licenseType, contactInfo, userID;
        int age;

        cout << "Enter User ID: ";
        getline(cin, userID);
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter License Type (Learner/Intermediate/Full): ";
        getline(cin, licenseType);
        cout << "Enter Contact Info: ";
        getline(cin, contactInfo);

        users[userCount++] = new User(name, age, licenseType, contactInfo, userID);
        cout << "User registered successfully!" << endl;
    }

    void updateUser() {
        string userID;
        cout << "Enter User ID to update: ";
        getline(cin, userID);

        for (int i = 0; i < userCount; ++i) {
            if (users[i]->getUserID() == userID) {
                users[i]->updateInfo();
                return;
            }
        }
        cout << "User not found." << endl;
    }

    void addVehicle() {
        string model, requiredLicenseType;
        double rentalPricePerDay;

        cout << "Enter Vehicle Model: ";
        getline(cin, model);
        cout << "Enter Rental Price Per Day: ";
        cin >> rentalPricePerDay;
        cin.ignore();
        cout << "Enter Required License Type (Learner/Intermediate/Full): ";
        getline(cin, requiredLicenseType);

        vehicles[vehicleCount++] = new Vehicle(model, rentalPricePerDay, requiredLicenseType);
        cout << "Vehicle added successfully!" << endl;
    }

    void viewAvailableVehicles() const {
        cout << "Available Vehicles:" << endl;
        for (int i = 0; i < vehicleCount; ++i) {
            if (!vehicles[i]->getIsRented())
                cout << vehicles[i]->getModel() << " - $" << vehicles[i]->getRentalPricePerDay() << " per day" << endl;
        }
    }

    void rentVehicle() {
        string userID, model;
        cout << "Enter User ID: ";
        getline(cin, userID);
        cout << "Enter Vehicle Model: ";
        getline(cin, model);

        for (int i = 0; i < userCount; ++i) {
            if (users[i]->getUserID() == userID) {
                for (int j = 0; j < vehicleCount; ++j) {
                    if (vehicles[j]->getModel() == model) {
                        users[i]->rentVehicle(vehicles[j]);
                        return;
                    }
                }
            }
        }
        cout << "Invalid User ID or Vehicle Model." << endl;
    }
};

int main() {
    VehicleRentalSystem system;
    int choice;

    while (true) {
        cout << "\n1. Register User\n2. Update User\n3. Add Vehicle\n4. View Available Vehicles\n5. Rent Vehicle\n6. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: system.registerUser(); break;
            case 2: system.updateUser(); break;
            case 3: system.addVehicle(); break;
            case 4: system.viewAvailableVehicles(); break;
            case 5: system.rentVehicle(); break;
            case 6: cout << "Exiting..."; return 0;
            default: cout << "Invalid choice!";
        }
    }
}
