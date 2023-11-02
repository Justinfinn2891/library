#include "library.h"
#include <list>
#include <iostream>
#include <fstream>
#include "book.h"

using namespace std;

library::library()
{
  myLibrary = list<book>();
}

void library::insertSorted(const book& newBook){  
  if(myLibrary.empty()) {
    myLibrary.push_back(newBook);
  } else {
    for (auto it = myLibrary.begin(); it != myLibrary.end(); ++it) {
      if(newBook.author_name < it->author_name) {
	myLibrary.insert(it,newBook);
      }
    }
    // If we reach here, it means the book belongs at the end of the list
    myLibrary.push_back(newBook);
  }
}
  void library::print(){
      for (const auto& book : myLibrary) {
	cout << "Title: " << book.book_title << endl;
	cout << "Author: " << book.author_name << endl;
	cout << "ISBN: " << book.isbn_code << endl;
	cout << "Pages: " << book.page_num << endl;
	cout << "Year: " << book.year_num << endl;
	cout << "Cover Price: " << book.cover_price << endl;
	cout << "==========================\n";
      }
  }



  void library::readFromFile(const string& filename){
    book temp; 
    ifstream file; 
    file.open(filename + ".txt");
    while (getline(file, temp.book_title, ',') &&
	   getline(file, temp.author_name, ',') &&
	   (file >> temp.isbn_code >> temp.page_num >> temp.year_num >> temp.cover_price)){      
      char newline;
      file>>newline;//remove newline character
      insertSorted(temp);
      
	cout<<temp.book_title<<" "<<temp.cover_price; 	
      }
    file.close();
    cout << "===================================" << endl;
    cout << "====FILE  ENTERED  SUCCESSFULLY====" << endl;
    cout << "===================================" << endl;
  }



  void library::inputToFile(const std::string& filename){
    ofstream file(filename + ".txt");
    
    for (const auto& book : myLibrary) {
      file << book.book_title << " , " << book.author_name << " , " << book.isbn_code << " , "
	   << book.page_num << " , " << book.year_num << " , " << book.cover_price << endl;
    }
    
    file.close();
  }

  void library::findAuthor(const string& authorName) {
    cout << "Books by " << authorName << ":\n";
    for (const book& book : myLibrary) {
      if (book.author_name == authorName) {
	cout << "Title: " << book.book_title << "\n";
	cout<< "ISBN: " << book.isbn_code << "\n";
	cout<<"Pages: "<< book.page_num<<"\n";
	cout<<"Cover Price: "<< book.cover_price<<"\n";
	cout<<"Year: "<<book.year_num<<"\n";
      }
    }
  }
  
  void library::findBook(const string& bookName) {
    for (const book& book : myLibrary) {
      if (book.book_title == bookName) {
	cout << "Book Found:\n";
	cout << "Title: " << book.book_title << "\n";
        cout << "Author: " << book.author_name << "\n";
        cout << "ISBN: " << book.isbn_code << "\n";
	cout << "Pages: " << book.page_num << "\n";
        cout << "Cover Price: " << book.cover_price << "\n";
        cout << "Year: " << book.year_num << "\n";
	return; // Stop after finding the first match
      }
    }
    cout << "Book not found.\n";
  }
  
  void library::deleteInfo(const string& authorName, const string& bookName){
    auto it = myLibrary.begin();
    while (it != myLibrary.end()) {
      if (it->author_name == authorName && it->book_title == bookName) {
	it = myLibrary.erase(it);
      } else {
	++it;
      }
    }
  }
