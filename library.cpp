#include "library.h"

using namespace std; 
library::library()
{
  // STUFF
}

void library::insertSorted(std::string book_title, std::string author_name, std::string isbn_code, int page_num, int year_num, float cover_price)
{
  
}

void library::print()
{
  
}

void library::readFromFile()
{
  book temp; 
  ifstream file; 
  cout << "Insert file name: ";
  cin >> filename;
  file.open(filename + ".txt");
  getline(file, temp.book_title, ',');
  getline(file, temp.author_name., ',');
  cin >> temp.isbn_code >> temp.page_num >> temp.cover_price;
  
  while(file)
    {
      insert_sorted(temp.book_title, temp.author_name, temp.isbn_code, temp.page_num, temp.cover_price);
      getline(file, temp.book_title, ',');
      getline(file, temp.author_name, ',');
      cin >> temp.isbn_code >> temp.page_num >> temp.cover_price; 
    }
  cout << "===================================" << endl;
  cout << "====FILE ENTERED SUCCESSFULLY======" << endl;
  cout << "===================================" << endl; 
}

