#include <iostream>
#include <string>

using namespace std;

// Base class
class Books {
protected:
    string genre;
public:
    Books(string g) : genre(g) {}
    string getGenre() {
        return genre;
    }
};

// Derived class for Novels
class Novel : public Books {
    string title;
    string author;
public:
    Novel(string t, string a) : Books("Novel"), title(t), author(a) {}
    
    void displayDetails() {
    	cout << "Novel Details:\n";
        cout << "Genre: " << genre << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

// Derived class for Mystery books
class Mystery : public Books {
    string title;
    string author;
public:
    Mystery(string t, string a) : Books("Mystery"), title(t), author(a) {}
    
    void displayDetails() {
    	cout << "Mystery Book Details:\n";
        cout << "Genre: " << genre << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

int main() {
    // Creating objects for Novel and Mystery
    Novel n1("Paddington in Peru", "Unknown Author");
    Mystery m1("Eggcelent", "Eggman");
    
    // Displaying book details
    n1.displayDetails();
    cout << "\n";
    m1.displayDetails();
    
    return 0;
}
