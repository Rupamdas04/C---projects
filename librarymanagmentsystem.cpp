#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    bool isAvailable;

    Book(string t, string a) : title(t), author(a), isAvailable(true) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const string& title, const string& author) {
        books.emplace_back(title, author);
        cout << "Book added: " << title << " by " << author << endl;
    }

    void viewBooks() {
        cout << "\nAvailable Books:\n";
        for (const auto& book : books) {
            cout << (book.isAvailable ? "[Available] " : "[Borrowed] ") 
                 << book.title << " by " << book.author << endl;
        }
    }

    void borrowBook(const string& title) {
        for (auto& book : books) {
            if (book.title == title && book.isAvailable) {
                book.isAvailable = false;
                cout << "You borrowed: " << title << endl;
                return;
            }
        }
        cout << "Book not available for borrowing.\n";
    }

    void returnBook(const string& title) {
        for (auto& book : books) {
            if (book.title == title && !book.isAvailable) {
                book.isAvailable = true;
                cout << "You returned: " << title << endl;
                return;
            }
        }
        cout << "This book was not borrowed.\n";
    }
};

int main() {
    Library library;
    int choice;
    string title, author;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore(); // to ignore the newline character left by previous input
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                library.addBook(title, author);
                break;
            case 2:
                library.viewBooks();
                break;
            case 3:
                cout << "Enter book title to borrow: ";
                cin.ignore();
                getline(cin, title);
                library.borrowBook(title);
                break;
            case 4:
                cout << "Enter book title to return: ";
                cin.ignore();
                getline(cin, title);
                library.returnBook(title);
                break;
            case 5:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
