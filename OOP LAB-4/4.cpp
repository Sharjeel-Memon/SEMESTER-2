#include <iostream>
#include <string>
using namespace std;

// ./4 "Harry Potter" "J.K. Rowling" "Bloomsbury" 20.5 10 "Harry Potter" "J.K. Rowling" 3


class Book {
private:
    string title;
    string author;
    string publisher;
    double price;
    int stock;

public:
    // Constructor
    Book(string t, string a, string p, double pr, int s) {
        title = t;
        author = a;
        publisher = p;
        price = (pr > 0) ? pr : 0.0;
        stock = (s > 0) ? s : 0;
    }
    
    // Check availability and process sale
    void searchBook(string t, string a, int copies) {
        if (title == t && author == a) {
            cout << "Book Found!" << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Price: " << price << endl;
            cout << "Stock Available: " << stock << endl;
            
            if (copies <= stock) {
                cout << "Total Cost: " << price * copies << endl;
                stock -= copies;
            } else {
                cout << "Required copies not in stock." << endl;
            }
        } else {
            cout << "Book not found." << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 7) {
        cout << "Invalid Amount of Arguments!" << endl;
        return 1;
    }
    
    // Book Store
    string title = argv[1];
    string author = argv[2];
    string publisher = argv[3];
    double price = stod(argv[4]);
    int stock = stoi(argv[5]);
    
    Book book(title, author, publisher, price, stock);
    
    // Searching for a book
    string searchTitle = argv[6];
    string searchAuthor = argv[7];
    int copies = stoi(argv[8]);
    
    cout << "\nSearching for book..." << endl;
    book.searchBook(searchTitle, searchAuthor, copies);
    
    return 0;
}
