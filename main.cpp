#include <iostream>
#include <list>
#include <string>

using namespace std;


/*

Group Members: Vesper Nyugen, Tiffany Rodriguez, Silver, Andrea Safadi

Our main focus is implementation of Hash Map class
We will need functions to sort based on Name, Author, and ID

Linked List (<list>) is used since it's more efficient to add, remove at front
or end for managing. Additionally, it's also a part of the concept for this
semester.

*/

// Main structure of a book
struct Book {
    string name;
    string author;
    int id;
};

// Hash Map implementation as a class with functions
class HashMap {

private:

    int size;
    list<Book> *map;

    //Main hash function
    int hashFunction(int key) {
        return key % size;
    }

public:

    // Constructor
    HashMap(int a) {
        size = a;
        map = new list<Book>[size]; // dynamic memory allocation of linked list array
    }

    // Add a book
    void add(Book book) {
        int index = hashFunction(book.id); // maps the corresponding book id to the hash table index
        map[index].push_back(book); // adds book to hashtable at the index
        cout << "Book was added successfully" << endl;
    }

    // Remove book by ID only
    void removeId(int id) {
        int index = hashFunction(id); // searches for book at index
        for (list<Book>::iterator i = map[index].begin(); i != map[index].end(); i++) {
            if (i->id == id) // if the id within the index matches the given book id
            {
                map[index].erase(i); // removes it from the list

                cout << "Book removed with ID " << id << " ." << endl;
                return;
            }
        }
        cout << "Book doesn't exist within the library." << endl; // else the book wasn't found
    }

    // Removes a book by name or by author
    void removeString(string name, string type) {
        for (int i = 0; i < size; i++) {
            // traverses hashtable

            for (auto it = map[i].begin(); it != map[i].end();) {
                // iterates through linked list at current index

                // if name or author given matches any found in linked list at that index, gets removed
                if ((name == "name" && it->name == type) || (name == "author" && it->author == type)) {
                    cout << it->name << " by " << it->author << " was removed";
                    it = map[i].erase(it); // removes book
                } else {
                    ++it; // moves iterator to next book
                }
            }
        }
    }

    // Sorts books through bubble sort
    void sort(string criteria) {
        Book books[9999]; // book array
        int counter = 0; // tracks number of books

        for (int i = 0; i < size; i++) {
            // traverses hash table

            for (list<Book>::iterator it = map[i].begin(); it != map[i].end(); it++) {
                // iterates through current linked list at i
                if (counter < 9999) {
                    // if book number is less than size of array
                    books[counter++] = *it; // copy book from hash table into fixed array books[]
                } // increment counter ^
            }
        }

        // Bubble sort implementation
        for (int i = 0; i < counter - 1; i++) {
            // loops while 'i' is less than the amount of books copied - 1 (last book is sorted)

            for (int j = 0; j < counter - i - 1; j++) {
                // compares current index with the next index

                bool swapCondition = false; // checks if books should swap position within array

                if (criteria == "name" && books[j].name > books[j + 1].name) {
                    // compares name [j] with [j+1]
                    swapCondition = true; // swaps to alphabetical order of book name
                } else if (criteria == "author" && books[j].author > books[j + 1].author) {
                    // compares author [j] with [j+1]
                    swapCondition = true; // swaps to alphabetical order of book author
                } else if (criteria == "id" && books[j].id > books[j + 1].id) {
                    // compares id of [j] with [j+1]
                    swapCondition = true; // swaps based on numerical order of id number
                }

                if (swapCondition == true) {
                    // swaps books
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }

        // Displays sorted books after sort function resolution
        for (int i = 0; i < counter; i++) {
            cout << "Name: " << books[i].name << "\nAuthor: " << books[i].author << "\nID: " << books[i].id << "\n" <<
                    endl;
        }
    }

    // Find book by ID only
    void findId(int id) {
        int index = hashFunction(id); // maps given id to index on the hash table
        for (list<Book>::iterator i = map[index].begin(); i != map[index].end(); ++i) {
            // traverses linked list at given index

            if (i->id == id) {
                // if the id in the linked list matches given id
                cout << "Book found within library:\n"; // indicate book was found
                cout << "Name: " << i->name << "\nAuthor: " << i->author << "\nID: " << i->id << endl;
                return;
            }
        }
        cout << "Book not found within library.\n"; // else book was not found
    }

    // search for a book by name or author
    void findString(string name, string type) {
        for (int i = 0; i < size; i++) {
            // traverses hash table

            for (list<Book>::iterator it = map[i].begin(); it != map[i].end(); it++) {
                // traverse linked list within current index
                // if search type + given name or author matches data found in hash table index
                if ((name == "name" && it->name == type) || (name == "author" && it->author == type)) {
                    cout << "Book found within library:\n"; // indicate book was found
                    cout << "Name: " << it->name << "\nAuthor: " << it->author << "\nID: " << it->id << endl;
                    return;
                }
            }
        }
        cout << "Book not found within library.\n"; // else book was not found
    }

    // Displays all books within the library
    void display() {
        cout << "\nAll books in the library system:\n" << endl;
        for (int i = 0; i < size; ++i) {
            // traverse hash table
            for (list<Book>::iterator it = map[i].begin(); it != map[i].end(); ++it) {
                // traverse linked list at [i]
                cout << "Name: " << it->name << "\nAuthor: " << it->author << "\nID: " << it->id << "\n" << endl;
            } // displays books at each index ^
        }
    }

    // Starts program with 3 books in the library
    void fill() {
        Book book1 = {"The Great Gatsby", "F. Scott Fitzgerald", 45565};
        Book book2 = {"1984", "George Orwell", 31834};
        Book book3 = {"To Kill a Mockingbird", "Harper Lee", 91045};
        add(book1);
        add(book2);
        add(book3);
    }
};


// main
int main() {

//-------------------------------------------------------------------------------------------------

    HashMap HashMap(20);
    HashMap.fill(); // Fills library with 3 books to demonstrate, can be disabled
    int choice;

    // Main menu input loop
    while (true) {
        cout << "\nMenu:\n";
        cout << "1) Add book\n";
        cout << "2) Remove book\n";
        cout << "3) Sort books (by name, author, id)\n";
        cout << "4) Find book\n";
        cout << "5) Display all books\n";
        cout << "6) Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

//-------------------------------------------------------------------------------------------------

        switch (choice) {
            // Add a book
            case 1:
            {
                Book book;
                cout << "Enter book name: ";
                cin.ignore();
                getline(cin, book.name);
                cout << "Enter author name: ";
                getline(cin, book.author);
                cout << "Enter book ID: ";
                cin >> book.id;
                HashMap.add(book);
                break;
            }
            // Remove a book
            case 2:
            {
                // initialize variables
                Book book;
                int option;
                int bookId;
                string bookName;
                string bookAuthor;

                cout << "Remove book by (Please choose corresponding number option): " << std::endl;
                cout << "[1] Book Name " << endl;
                cout << "[2] Book Author " << endl;
                cout << "[3] Book ID " << endl;
                cout << "[4] Back to Main Menu " << endl;
                cin >> option;
                cin.ignore();

                switch (option) {
                    // Remove by name
                    case 1:
                    {
                        cout << "Enter the name of the book you wish to remove: " << endl;
                        cin >> bookName;
                        HashMap.removeString("name", bookName);
                        break;
                    }
                    // Remove by author
                    case 2:
                    {
                        cout << "Enter the author of the book you wish to remove: " << endl;
                        getline(cin, bookAuthor);
                        HashMap.removeString("author", bookAuthor);
                        break;
                    }
                    // Remove by ID
                    case 3:
                    {
                        cout << "Enter the ID of the book you wish to remove: " << endl;
                        cin >> bookId;
                        HashMap.removeId(bookId);
                        break;
                    }
                    // Go back
                    case 4:
                    {
                        continue;
                    }
                    default:
                    {
                        cout << "\nInvalid input, try again!" << endl;
                    }
                }
                break;
            }
            // Sort books (bubble sort)
            case 3:
            {
                string criteria;
                cout << "Enter sort criteria (name, author, id): ";
                cin >> criteria;
                HashMap.sort(criteria);
                break;
            }
            // Search for a book
            case 4:
            {
                // initialize variables
                Book book;
                int option2;
                int bookId;
                string bookName;
                string bookAuthor;

                cout << "Choose search method by typing in the corresponding number choice: " << std::endl;
                cout << "[1] Book Name " << endl;
                cout << "[2] Book Author " << endl;
                cout << "[3] Book ID " << endl;
                cout << "[4] Back to Main Menu " << endl;
                cin >> option2;
                cin.ignore();

                switch (option2) {
                    // Search by name
                    case 1:
                    {
                        cout << "Enter book name: " << endl;
                        cin >> bookName;
                        HashMap.findString("name", bookName);
                        break;
                    }
                    // Search by author
                    case 2:
                    {
                        cout << "Enter book author: " << endl;
                        getline(cin, bookAuthor);
                        HashMap.findString("author", bookAuthor);
                        break;
                    }
                    // Search by ID
                    case 3:
                    {
                        cout << "Enter book ID: " << endl;
                        cin >> bookId;
                        HashMap.findId(bookId);                        
                        break;
                    }
                    // Go back
                    case 4:
                    {
                        continue;
                    }
                    default:
                    {
                        cout << "\nInvalid input, try again!" << endl;
                    }
                }
                break;
            }
            // Display library
            case 5:
            {
                HashMap.display();
                break;
            }
            // Exit program
            case 6:
            {
                return 0;
            }
            default:
            {
                cout << "\nInvalid input, try again!" << endl;
            }
        }
    }
}
