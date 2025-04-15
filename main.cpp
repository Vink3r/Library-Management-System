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
          for (int i = 0; i < counter; i++)
            {
              cout << "Name: " << books[i].name << "\nAuthor: " << books[i].author << "\nID: " << books[i].id << endl;
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
    void display(Book book)
    {
        book.author = "";
        book.name = "";
        book.id = 0;
    }
};

//Main
int main()
{
    /*
    Menu:
    1)  Add book
    2)  Remove book
    3)  Sort book -> (By name, author, id)
    4)  Find book
    5)  Display book
    6) Exit
    */
    return 0;
}