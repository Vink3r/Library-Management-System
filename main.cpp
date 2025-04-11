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

    //Remove function
    void remove(Book book)
    {
        book.author = "";
        book.name = "";
        book.id = 0;
    }

    //Sort function
    void sort(Book book)
    {
        book.author = "";
        book.name = "";
        book.id = 0;
    }

    //Find function
    void find(Book book)
    {
        book.author = "";
        book.name = "";
        book.id = 0;
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