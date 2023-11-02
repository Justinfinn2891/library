#include "library.h"
#include "book.h"
#include <iostream>

using namespace std;


int main()
{
  library myLibrary;
  //creates any needed variables
  int x = 0;
  string name, last, num, trash = "";
  //the trash variable is to stop any getlines from reading in when they aren't supposed to
  
  while(x != 8){
    cout<<"\n";
  string name, last, num = "";
    for(int i =0;i < 40; i++){
      cout<<"+X";
    }
    cout<<endl;
    cout << "\nWelcome to the UTM Library!  You may select one of the following options:\n";
    cout << "1 Read a file to the Library\n";
    cout << "2 Write the Library to file\n";
    cout << "3 Print Library\n";
    cout << "4 Search for Book Name\n";
    cout << "5 Reverse lookup by Author Name\n";
    cout << "6 Add a Book\n";
    cout << "7 Delete a Book\n";
    cout << "8 Exit this program\n";

    cout << "\nPlease enter your choice now:";
    cin >> x;
    cout<<endl;
    
    for(int i =0;i < 40;i++){
      cout<<"+X";
    }
    cout<<endl;
    cout<<"\n";
    switch (x) {

    case 1:{
      //reads information out of a file into nodes
      string filename;
      getline(cin, trash);
      cout << "Enter the filename to read from: ";
      getline(cin, filename);
      myLibrary.readFromFile(filename);
      break;
    }
      
    case 2:{
      //writes all nodes into a file
      string filename;
      getline(cin,trash);
      cout << "Enter the filename to save to: ";
      getline(cin, filename);
      myLibrary.inputToFile(filename);
      break;
    }
      
    case 3:{
      //prints out all nodes to console
      myLibrary.print();
      break;
    }
    case 4:{
      //looks up Book according to Book Title provided
      string bookTitle;
      cout << "Enter Book Title: ";
      getline(cin, bookTitle);
      myLibrary.findBook(bookTitle);
      break;
    }

    case 5:{
      //looks up book according to the author provided
      string authorName;
      getline(cin, trash);
      cout <<"Enter Author Name: ";
      getline(cin, authorName);
      myLibrary.findAuthor(authorName);
      break;
    }
    case 6:{
      //adds a book according to user input
      book newBook;
      getline(cin, trash);
      cout << "Enter Book Title: ";
      getline(cin, newBook.book_title);
      cout << "Enter Author Name: ";
      getline(cin, newBook.author_name);
      cout << "Enter ISBN: ";
      getline(cin, newBook.isbn_code);
      cout << "Enter Pages: ";
      cin >> newBook.page_num;
      cout << "Enter Year: ";
      cin >> newBook.year_num;
      cout << "Enter Cover Price: ";
      cin >> newBook.cover_price;
      myLibrary.insertSorted(newBook);
      break;
    }
    case 7:{
    //deletes the book whose author matches the user input
      string authorName, bookTitle;
      getline(cin,trash);
      cout << "Enter Author Name: ";
      getline(cin, authorName);
      cout << "Enter Book Title: ";
      getline(cin, bookTitle);
      myLibrary.deleteInfo(authorName, bookTitle);
      break;
      break;
    }
    case 8:{
      cout << "Exiting program.\n";
      break;
    }
    default:
      cout << "Invalid choice. Please try again.\n";
      break;

    }
  }
  
  return 0; 
}
