/**
 * @file library.cpp
 * @author Justin Finn and Gabriel Speer
 * @date 2023-11-01
 * @brief .cpp file that keeps the methods for library class
 * 
 * keeps all the methods required for the library class and book.h 
 */

#include "library.h"
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "book.h"

using namespace std;

library::library()
{
  myLibrary = list<book>();
}

void library::insertSorted(const book& newBook){  
  if (myLibrary.empty()) {
    myLibrary.push_back(newBook);
  } else {
    // Create an iterator to traverse the list
    auto it = myLibrary.begin();

    // Find the position where the new book should be inserted
    while (it != myLibrary.end() && newBook.author_name > it->author_name) {
      ++it;
    }

    // Insert the new book before the found position
    myLibrary.insert(it, newBook);
  }
}
  void library::print(){
    //prints out any and all book structures in the library
      for (const auto& book : myLibrary) {
	cout << "Title: " << book.book_title << endl;
	cout << "Author: " << book.author_name << endl;
	cout << "ISBN: " << book.isbn_code << endl;
	cout << "Pages: " << book.page_num << endl;
	cout << "Year: " << book.year_num << endl;
	cout << "Cover Price: " <<fixed<<setprecision(2)<< book.cover_price << endl;
	cout << "==========================\n";
      }
  }



  void library::readFromFile(const string& filename){
    book temp; 
    ifstream file;
    string line;
    file.open(filename + ".txt");
    if(file.fail())
    {
      cout << endl;
      cout << "+==========================+" << endl;
      cout << "ERROR: FILE DOESN'T EXIST!" << endl;
      cout << "+==========================+";
      
      return;
    }
    while (getline(file, line)) {
      // Use string manipulation to split the line into fields
      size_t pos = 0;
      string delimiter = ",";
      size_t count = 0;

      while ((pos = line.find(delimiter)) != string::npos) {
	string field = line.substr(0, pos);
	line.erase(0, pos + delimiter.length());

	// Parse and assign the fields to the book object
	switch (count) {
	case 0:
	  temp.book_title = field;
	  break;
	case 1:
	  temp.author_name = field;
	  break;
	case 2:
	  temp.isbn_code = field;
	  break;
	case 3:
	  temp.page_num = stoi(field);
	  break;
	case 4:
	  temp.year_num = stoi(field);
	  break;
	case 5:
	  temp.cover_price = stof(field);
	  break;
	}

	count++;
      }
      
      insertSorted(temp);
    }
    file.close();
    cout << "===================================" << endl;
    cout << "====FILE  ENTERED  SUCCESSFULLY====" << endl;
    cout << "===================================" << endl;
  }



  void library::inputToFile(const std::string& filename){
    ofstream file(filename + ".txt");
    //outputs all of stored book structures into a .txt file named by the user    
    for (const auto& book : myLibrary) {
      file << book.book_title << ", " << book.author_name << ", " << book.isbn_code << ", "
	   << book.page_num << ", " << book.year_num << ", " <<fixed<<setprecision(2)<<book.cover_price<<"," << endl;
    }
    
    file.close();
  }

  void library::findAuthor(const string& authorName) {
    cout << "Books by " << authorName << ":\n";

    //search through the library to find any books by the provided author name
    for (const book& book : myLibrary) {
      if (book.author_name == authorName) {
	cout << "Title: " << book.book_title << "\n";
	cout<< "ISBN: " << book.isbn_code << "\n";
	cout<<"Pages: "<< book.page_num<<"\n";
	cout<<"Cover Price: "<<fixed<<setprecision(2)<< book.cover_price<<"\n";
	cout<<"Year: "<<book.year_num<<"\n";
      }
    }
  }
  
  void library::findBook(const string& bookName) {
    //looks for the provided book title within the library
    for (const book& book : myLibrary) {
      if (book.book_title == bookName) {
	cout << "Book Found:\n";
	cout << "Title: " << book.book_title << "\n";
        cout << "Author: " << book.author_name << "\n";
        cout << "ISBN: " << book.isbn_code << "\n";
	cout << "Pages: " << book.page_num << "\n";
        cout << "Cover Price: " << fixed<<setprecision(2)<<book.cover_price << "\n";
        cout << "Year: " << book.year_num << "\n";
	return; // Stop after finding the first match
      }
    }
    //ifnot found it tells the user
    cout << "Book not found.\n";
  }
  
  void library::deleteInfo(const string& authorName, const string& bookName){
    auto it = myLibrary.begin();
    //cycles through the library for a matching author and title before deleting that structure
    while (it != myLibrary.end()) {
      if (it->author_name == authorName && it->book_title == bookName) {
	it = myLibrary.erase(it);
      } else {
	++it;
      }
    }
  }
