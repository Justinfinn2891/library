#include "book.h"
#include <iostream>
#include <list>
#include <string>
#include <fstream>

#ifndef LIBRARY_H
#define LIBRARY_H

class library
{
private:

  std::list<book> myLibrary;  

public:
  library();
  void readFromFile();
  void inputToFile();

  void insertSorted(std::string book_title, std::string author_name, std::string isbn_code, int page_num, int year_num, float cover_price);
  void lookup();
  
  void reverse_lookup();
  void print();
  void deleteInformation(); 
};

#endif // LIBRARY_H
