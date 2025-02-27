#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
       string title;
        string author;
       string isbn;

    Book(string t, string a, string i) : title(t), author(a), isbn(i) {
              cout << "Book Created: " << title << " (ISBN: " << isbn << ")" << endl;
    }

    ~Book() {
             cout << "Book Destroyed: " << title << " (ISBN: " << isbn << ")" << endl;
    }
};

class Catalog {
private:
    vector<string> bookList;

public:
    Catalog() {
              cout << "Catalog Created" << endl;
    }

    ~Catalog() {
        cout << "Catalog Destroyed" << endl;
    }

    void addToCatalog(const string& bookTitle) {
             bookList.push_back(bookTitle);
    }

    void findBook(const string& bookTitle) {
            for (const auto& title : bookList) {
            if (title == bookTitle) {
                   cout << "Book Found in Catalog: " << bookTitle << endl;
                  return;
            }
        }
            cout << "Book Not Found in Catalog!" << endl;
    }
};

class Library {
private:
    Catalog catalog; 
    vector<Book*> books; 

public:
    Library() {
        cout << "Library Created" << endl;
    }

    ~Library() {
        cout << "Library Destroyed" << endl;
    }

    void addBook(Book* book) {
        books.push_back(book);
        catalog.addToCatalog(book->title);
    }

    void findBookByTitle(const string& title) {
        catalog.findBook(title);
    }
};

int main() {
    Library myLibrary;

    Book book1("ABC", "John Doe", "11111");
    Book book2("XYZ", "Jane Doe", "22222");
    Book book3("HJHS", "Alice Smith", "33333");
    Book book4("LMNO", "Bob Brown", "44444");
    Book book5("PQRS", "Charlie White", "55555");

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);
    myLibrary.addBook(&book3);
    myLibrary.addBook(&book4);
    myLibrary.addBook(&book5);

    myLibrary.findBookByTitle("ABC");
    myLibrary.findBookByTitle("XYZ");
    myLibrary.findBookByTitle("HJHS");
    myLibrary.findBookByTitle("LMNO");
    myLibrary.findBookByTitle("ZZZZ"); 

    return 0;
}
