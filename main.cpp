#include "library.h"
#include "book.h"
using namespace std;


int main()
{
  //creates any needed variables
  int x = 0;
  string name, last, num = "";

    cout << "\nPlease enter your choice now:";
    cin >> x;
    for(int i =0;i < 20; i++){
      cout<<"+X";
    }
    cout<<endl;
  
  while(x != 8){

    cout << "\nWelcome to the UTM Library!  You may select one of the following options:\n";
    cout << "1 Read a file to the Library\n";
    cout << "2 Write the Library to a file\n";
    cout << "3 Print the File\n";
    cout << "4 Search for Book Name\n";
    cout << "5 Reverse lookup by Author Name\n";
    cout << "6 Add a Book\n";
    cout << "7 Delete a Book\n";
    cout << "8 Exit this program\n";

    cout << "\nPlease enter your choice now:";
    cin >> x;
    for(int i =0;i < 20;i++){
      cout<<"+X";
    }
    cout<<endl;
    
    switch (x) {

    case 1:
      //reads information out of a file into nodes
      cout << "Save File function";
      break;

    case 2:
      //writes all nodes into a file
      cout << "Load file Info to File";
      break;

    case 3:
      //prints out all nodes to console
      cout<<"Print Function";
      break;

    case 4:
      //looks up Book according to Book name provided
      cout << "Enter the user's name: ";
      break;

    case 5:
      //looks up book according to the author provided
      cout << "Author search";
      break;

    case 6:
      //adds a book according to user input
      cout << "Add Book Function";
      break;
      
    case 7:
    //deletes the book whose author matches the user input
      cout << "Delete Function!";
      break;

    case 8:
      cout << "Exiting program.\n";
      return 0;

    default:
      cout << "Invalid choice. Please try again.\n";
      break;

    }
  }
  return 0; 
}
