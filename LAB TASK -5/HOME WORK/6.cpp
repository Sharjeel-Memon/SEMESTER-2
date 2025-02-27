#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct MenuItem {
    string name;
    string type;
    double price;
};

class CoffeeShop {
public:
    const string name;
    vector<MenuItem> menu;

private:
    vector<string> orders;

public:
    CoffeeShop(string n) : name(n) {}

    void addMenuItem(string itemName, string type, double price) {
        menu.push_back({itemName, type, price});
    }

    string addOrder(string itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string order = orders.front();
            orders.erase(orders.begin());
            return "The " + order + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0.0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items in menu";
        MenuItem cheapest = menu[0];
        for (const auto& item : menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (const auto& item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Invalid Amount of Arguments!" << endl;
        return 1;
    }
    
    string shopName = argv[1];
    int menuItemCount = stoi(argv[2]);
    int index = 3;
    
    CoffeeShop shop(shopName);
    
    for (int i = 0; i < menuItemCount; i++) {
        string name = argv[index];
        string type = argv[index + 1];
        double price = stod(argv[index + 2]);
        shop.addMenuItem(name, type, price);
        index += 3;
    }
    
    int orderCount = stoi(argv[index]);
    index++;
    for (int i = 0; i < orderCount; i++) {
        cout << shop.addOrder(argv[index]) << endl;
        index++;
    }
    
    cout << "Due Amount: " << shop.dueAmount() << endl;

    vector<string> orders = shop.listOrders();
    cout << "Orders: ";
    for (const auto& order : orders) cout << order << " ";
    cout << endl;
    
    while (!orders.empty()) {
        cout << shop.fulfillOrder() << endl;
        orders = shop.listOrders();
    }
    
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;

    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks Only: ";
    for (const auto& drink : drinks) cout << drink << " ";
    cout << endl;

    vector<string> foods = shop.foodOnly();
    cout << "Food Only: ";
    for (const auto& food : foods) cout << food << " ";
    cout << endl;
    
    return 0;
}
