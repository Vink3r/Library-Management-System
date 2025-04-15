#include <iostream>
#include <list>
#include <string>

using namespace std;


/*
Our main focus is implementation of Hash Map class
We will need functions to sort based on Name, Author, and ID

Linked List (<list>) is used since it's more efficient to add, remove at front
or end for managing. Additionally, it's also a part of the concept for this
semester.
*/

//Main structure of a book
struct Book
{
    string name;
    string author;
    int id;
};

//Hash Map owns implementation
class HashMap
{
private:
    int size;
    list<Book>* map;

    //Main hash function
    int hashFunction(int key)
    {
        return key % size;
    }
    
public:
    //Constructor
    HashMap(int a)
    {
        size = a;
        map = new list<Book>[size];
    }

    //Add function
    void add(Book book)
    {
      int index = hashFunction(book.id);
      map[index].push_back(book);
    }

    //Remove function
    void remove(int id)
    {
        int index = hashFunction(id);
        for (list<Book>::iterator i = map[index].begin(); i != map[index].end(); i++)
        {
         if (i->id == id)
           {
           map[index].erase(i);
           cout << "Book removed with ID " << id << " ." << endl;
           return;
           }
        }
        cout << "Book doesn't exist within the library." << endl;
    }

    //Sort function
    void sort(string criteria)
    {
        Book books[9999];
        int counter = 0;;

        for (int i = 0; i < size; i++)
          {
          for (list<Book>::iterator it = map[i].begin(); it != map[i].end(); it++)
            {
            if (counter < 9999)
              {
              books[counter++] = *it;
              }
            }
          }
          //Bubble sort
          for (int i = 0; i < counter - 1; i++)
            {
            for (int j = 0; j < counter - i - 1; j++)
              {
              bool swapCondition = false;
              if (criteria == "name" && books[j].name > books[j + 1].name)
              {
                    swapCondition = true;
              }
              else if (criteria == "author" && books[j].author > books[j + 1].author)
              {
                    swapCondition = true;
              }
              else if (criteria == "id" && books[j].id > books[j + 1].id)
              {
                    swapCondition = true;
              }
              if (swapCondition == true)
                {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
                }
            }
          }
          //Display after sort
          for (int i = 0; i < counter; i++)
            {
              cout << "Name: " << books[i].name << "\nAuthor: " << books[i].author << "\nID: " << books[i].id << "\n" << endl;
            }
    }

    //Find function
    void find(int id)
    {
        int index = hashFunction(id);
        for (list<Book>::iterator i = map[index].begin(); i != map[index].end(); ++i)
        {
            if (i->id == id)
          {
                cout << "Book found within library:\n";
                cout << "Name: " << i->name << "\nAuthor: " << i->author << "\nID: " << i->id << endl;
                return;
          }
        }
        cout << "Book not found within library.\n";
    }

    //Display function
    void display()
    {
      cout << "\nAll books in the library system:\n";
        for (int i = 0; i < size; ++i)
      {
            for (list<Book>::iterator it = map[i].begin(); it != map[i].end(); ++it)
              {
                cout << "Name: " << it->name << "\nAuthor: " << it->author << "\nID: " << it->id << "\n" << endl;
              }
      }
    }

    //Fill 3 books in library
    void fill()
    {
      Book book1 = {"The Great Gatsby", "F. Scott Fitzgerald", 45565};
      Book book2 = {"1984", "George Orwell", 31834};
      Book book3 = {"To Kill a Mockingbird", "Harper Lee", 91045};
      add(book1);
      add(book2);
      add(book3);
    }
};

//Main
int main()
{
  HashMap HashMap(20);
  HashMap.fill();     //Fill 3 books to demonstrate, can be disable
  int choice;
  //Main menu
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1) Add book\n";
        cout << "2) Remove book\n";
        cout << "3) Sort books (by name, author, id)\n";
        cout << "4) Find book\n";
        cout << "5) Display all books\n";
        cout << "6) Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
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
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter book ID to remove: ";
            cin >> id;
            HashMap.remove(id);
        }
        else if (choice == 3)
        {
            string criteria;
            cout << "Enter sort criteria (name, author, id): ";
            cin >> criteria;
            HashMap.sort(criteria);
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter book ID to find: ";
            cin >> id;
            HashMap.find(id);
        }
        else if (choice == 5)
        {
            HashMap.display();
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Choose a valid option.\n";
        }
    }

    return 0;
}