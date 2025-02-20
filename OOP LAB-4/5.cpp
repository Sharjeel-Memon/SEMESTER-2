#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct MenuItem {
    string name;
    string type;
    double price;
};

class CoffeeShop {
private:
    string name;
    MenuItem* menu;
    int menuSize;
    string* orders;
    int orderCount;
    int maxOrders;

public:
    CoffeeShop(string n, int size) : name(n), menuSize(size), orderCount(0) {
        menu = new MenuItem[menuSize];
        maxOrders = 50;
        orders = new string[maxOrders];
    }

    ~CoffeeShop() {
        delete[] menu;
        delete[] orders;
    }

    void addMenuItem(int index, string itemName, string type, double price) {
        if (index >= 0 && index < menuSize) {
            menu[index] = {itemName, type, price};
        }
    }

    string addOrder(string itemName) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == itemName) {
                if (orderCount < maxOrders) {
                    orders[orderCount++] = itemName;
                    return "Order added: " + itemName;
                } else {
                    return "Order list is full";
                }
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (orderCount > 0) {
            string order = orders[0];
            for (int i = 0; i < orderCount - 1; i++) {
                orders[i] = orders[i + 1];
            }
            orderCount--;
            return "The " + order + " is ready";
        }
        return "All orders have been fulfilled";
    }

    string* listOrders(int& count) {
        count = orderCount;
        return orders;
    }

    double dueAmount() {
        double total = 0.0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (menu[j].name == orders[i]) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menuSize == 0) return "No items in menu";
        MenuItem cheapest = menu[0];
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < cheapest.price) {
                cheapest = menu[i];
            }
        }
        return cheapest.name;
    }

    string* drinksOnly(int& count) {
        string* drinks = new string[menuSize];
        count = 0;
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                drinks[count++] = menu[i].name;
            }
        }
        return drinks;
    }

    string* foodOnly(int& count) {
        string* foods = new string[menuSize];
        count = 0;
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                foods[count++] = menu[i].name;
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
    
    CoffeeShop shop(shopName, menuItemCount);
    
    for (int i = 0; i < menuItemCount; i++) {
        string name = argv[index];
        string type = argv[index + 1];
        double price = stod(argv[index + 2]);
        shop.addMenuItem(i, name, type, price);
        index += 3;
    }
    
    int orderCount = stoi(argv[index]);
    index++;
    for (int i = 0; i < orderCount; i++) {
        cout << shop.addOrder(argv[index]) << endl;
        index++;
    }
    
    cout << "Due Amount: " << shop.dueAmount() << endl;

    int orderListSize;
    string* orders = shop.listOrders(orderListSize);
    cout << "Orders: ";
    for (int i = 0; i < orderListSize; i++) cout << orders[i] << " ";
    cout << endl;
    
    while (orderListSize-- > 0) {
        cout << shop.fulfillOrder() << endl;
    }
    
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;

    int drinksCount;
    string* drinks = shop.drinksOnly(drinksCount);
    cout << "Drinks Only: ";
    for (int i = 0; i < drinksCount; i++) cout << drinks[i] << " ";
    cout << endl;
    delete[] drinks;

    int foodsCount;
    string* foods = shop.foodOnly(foodsCount);
    cout << "Food Only: ";
    for (int i = 0; i < foodsCount; i++) cout << foods[i] << " ";
    cout << endl;
    delete[] foods;

    return 0;
}
