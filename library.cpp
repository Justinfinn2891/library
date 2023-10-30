#include "library.h"
#include <list>

using namespace std; 
library::library()
{
  myLibrary = list<book>();
}

void library::insertSorted(std::string author_name){
  
  if (myLibrary.empty()) {
    myLibrary.push_back(book);
  } else {
    for (auto it = myLibrary.begin(); it != myLibrary.end(); ++it) {
      if (author_name < it->author) {
	myLibrary.insert(it, book);
      }
}

void library::print()
{
  for(auto it = myLibrary.begin(); it != myLibrary.end(); ++it)
    {
      cout << "Title: ";
    }
}

void library::readFromFile()
{
  string filename;
  book temp; 
  ifstream file; 
  cout << "Insert file name: ";
  cin >> filename;
  file.open(filename + ".txt");
  getline(file, temp.book_title, ',');
  getline(file, temp.author_name, ',');
  cin >> temp.isbn_code >> temp.page_num >> temp.year_num >> temp.cover_price;
  
  while(file)
    {
      insertSorted(temp.book_title, temp.author_name, temp.isbn_code, temp.page_num, temp.year_num, temp.cover_price);
      getline(file, temp.book_title, ',');
      getline(file, temp.author_name, ',');
      cin >> temp.isbn_code >> temp.page_num >> temp.year_num >> temp.cover_price; 
    }
  cout << "===================================" << endl;
  cout << "====FILE  ENTERED  SUCCESSFULLY====" << endl;
  cout << "===================================" << endl; 
}

void library::inputToFile()
{
  
}

