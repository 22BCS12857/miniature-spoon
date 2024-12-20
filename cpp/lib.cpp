#include <iostream>
#include <string>
using namespace std;

// Base class: Book
class Book {
protected:
    string title;
    string author;
    int ISBN;

public:
    Book(string t, string a, int isbn) : title(t), author(a), ISBN(isbn) {}

    void displayBookDetails() {
        cout << "\"" << title << "\" by " << author << " (ISBN: " << ISBN << ")" << endl;
    }
};

// Base class: Borrower
class Borrower {
protected:
    string name;
    int ID;

public:
    Borrower(string n, int id) : name(n), ID(id) {}

    void displayBorrowerDetails() {
        cout << "Borrower " << name << " (ID: " << ID << ")";
    }
};

// Derived class: Library
class Library : public Book, public Borrower {
private:
    bool bookBorrowed;

public:
    Library(string t, string a, int isbn, string n, int id)
        : Book(t, a, isbn), Borrower(n, id), bookBorrowed(false) {}

    void borrowBook() {
        if (!bookBorrowed) {
            bookBorrowed = true;
            displayBorrowerDetails();
            cout << " has borrowed ";
            displayBookDetails();
        } else {
            cout << "Book is already borrowed." << endl;
        }
    }

    void returnBook() {
        if (bookBorrowed) {
            bookBorrowed = false;
            displayBorrowerDetails();
            cout << " has returned ";
            displayBookDetails();
        } else {
            cout << "No book to return." << endl;
        }
    }

    void performAction(int action) {
        if (action == 1) {
            borrowBook();
        } else if (action == 2) {
            returnBook();
        } else {
            cout << "Invalid action type." << endl;
        }
    }
};

int main() {
    // Input book details
    string title, author, name;
    int ISBN, ID, action;

    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Book Author: ";
    getline(cin, author);
    cout << "Enter Book ISBN: ";
    cin >> ISBN;

    // Input borrower details
    cout << "Enter Borrower Name: ";
    cin.ignore(); // To consume newline left by previous input
    getline(cin, name);
    cout << "Enter Borrower ID: ";
    cin >> ID;

    // Create Library object
    Library library(title, author, ISBN, name, ID);

    // Input action
    cout << "Enter Action (1 to Borrow, 2 to Return): ";
    cin >> action;

    // Perform action
    library.performAction(action);

    return 0;
}
