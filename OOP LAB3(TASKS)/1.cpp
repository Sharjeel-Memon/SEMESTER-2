#include <iostream>
#include <string>

// ./1 

using namespace std;

class User {
public:
    int Age;
    string Name;
};

int main(int argc, char* argv[]) {
    // Creating Object
	User u;
    // Setting values According to the Question...
    u.Age = 24;
    u.Name = "Teo";
    
    // Output
    cout << "My name is " << u.Name << " and I'm " << u.Age << " years old." << endl;
    
    return 0;
}
