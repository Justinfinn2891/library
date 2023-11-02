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
    myLibrary.push_back(book);
  } else {
    for (auto it = myLibrary.begin(); it != myLibrary.end(); ++it) {
      if(newBook.author_name < it->author) {
	myLibrary.insert(it, book);
      }
    }
    // If we reach here, it means the book belongs at the end of the list
    myLibrary.push_back(book);
  }

  void library::print(){
      for (const auto& book : newBook) {
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
    string filename;
    book temp; 
    ifstream file; 
    cout << "Insert file name: ";
    cin >> filename;
    file.open(filename + ".txt"); 
    while(getline(file, temp.book_title, ',') && getline(file, temp.author_name, ',') && (file >> temp.isbn_code >> temp.page_num >> temp.year_num >> temp.cover_price))
      {
	insertSorted(temp);
      }
    file.close();
    cout << "===================================" << endl;
    cout << "====FILE  ENTERED  SUCCESSFULLY====" << endl;
    cout << "===================================" << endl; 
  }



  void library::inputToFile(const std::string& filename){
    string filename;
    cout << "Enter the file name to save the library: ";
    cin >> filename;
    ofstream file(filename + ".txt");
    
    for (const auto& book : myLibrary) {
      file << book.book_title << " , " << book.author_name << " , " << book.isbn_code << " , "
	   << book.page_num << " , " << book.year_num << " , " << book.cover_price << endl;
    }
    
    file.close();
  }

  void Library::findAuthor(const string& authorName) {
    cout << "Books by " << authorName << ":\n";
    for (const Book& book : bookList) {
      if (book.author == authorName) {
	cout << "Title: " << book.title << "\n"
	cout<< "ISBN: " << book.isbn << "\n";
	cout<<"Pages: "<< book.pages<<"\n";
	cout<<"Cover Price: "<< book.coverPrice<<"\n";
	cout<<"Year: "book.year<<"\n";
      }
    }
  }
  
  void Library::findBook(const string& bookName) {
    for (const Book& book : bookList) {
      if (book.title == bookName) {
	cout << "Book Found:\n";
	cout << "Title: " << book.title << "\n";
        cout << "Author: " << book.author << "\n";
        cout << "ISBN: " << book.isbn << "\n";
	cout << "Pages: " << book.pages << "\n";
        cout << "Cover Price: " << book.coverPrice << "\n";
        cout << "Year: " << book.year << "\n";
	return; // Stop after finding the first match
      }
    }
    std::cout << "Book not found.\n";
  }
  
  void library::deleteInfo(const string& authorName, const string& bookName){
    auto it = myLibrary.begin();
    while (it != myLibrary.end()) {
      if (it->author == authorName && it->title == bookName) {
	it = myLibrary.erase(it);
      } else {
	++it;
      }
    }
  }
