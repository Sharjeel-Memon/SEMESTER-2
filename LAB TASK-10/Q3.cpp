#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
    string filename;

public:
    User(const string& file) : filename(file) {}

    string getIDByFirstName(const string& firstName) const {
        ifstream fin(filename);
        string line;
        while (getline(fin, line)) {
            size_t p1 = line.find(',');
            size_t p2 = line.find(',', p1 + 1);
            string uid = line.substr(0, p1);
            string fname = line.substr(p1 + 1, p2 - p1 - 1);
            if (fname == firstName) {
                fin.close();
                return uid;
            }
        }
        fin.close();
        return "";
    }
};

class Order {
    string filename;

public:
    Order(const string& file) : filename(file) {}

    int getProductIDsForUser(const string& userUUID, string pids[], int maxSize) const {
        ifstream fin(filename);
        string line;
        int count = 0;
        while (getline(fin, line) && count < maxSize) {
            size_t p1 = line.find(',');
            size_t p2 = line.find(',', p1 + 1);
            string uid = line.substr(p1 + 1, p2 - p1 - 1);
            if (uid == userUUID) {
                size_t p3 = line.find(',', p2 + 1);
                string pid = line.substr(p2 + 1, p3 - p2 - 1);
                pids[count++] = pid;
            }
        }
        fin.close();
        return count;
    }
};

class Product {
    string filename;

public:
    Product(const string& file) : filename(file) {}

    void printNamesForIDs(const string pids[], int count) const {
        ifstream fin(filename);
        string line;
        while (getline(fin, line)) {
            size_t p1 = line.find(',');
            size_t p2 = line.find(',', p1 + 1);
            string pid = line.substr(0, p1);
            string name = line.substr(p1 + 1, p2 - p1 - 1);
            for (int i = 0; i < count; ++i) {
                if (pids[i] == pid) {
                    cout << "Product: " << name << endl;
                }
            }
        }
        fin.close();
    }
};

int main() {
    User users("users.txt");
    Order orders("orders.txt");
    Product products("products.txt");

    const string targetFirstName = "Linus";
    string uid = users.getIDByFirstName(targetFirstName);
    if (uid.empty()) {
        cout << "User \"" << targetFirstName << "\" not found.\n";
        return 0;
    }

    const int MAX_ORDERS = 100;
    string pids[MAX_ORDERS];
    int count = orders.getProductIDsForUser(uid, pids, MAX_ORDERS);
    if (count == 0) {
        cout << "No orders found for user \"" << targetFirstName << "\".\n";
        return 0;
    }

    products.printNamesForIDs(pids, count);

    return 0;
}
