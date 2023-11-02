#include "book.h"
#include <iostream>
#include <list>
#include <fstream>

#ifndef LIBRARY_H
#define LIBRARY_H

class library
{
private:

  std::list<book> myLibrary;  

public:
  library();
  void readFromFile(const std::string& filename);
  void inputToFile(const std::string& filename);

  void insertSorted(const book& newBook);
  void findAuthor(const std::string& authorName);
  
  void findBook(const std::string& bookName);
  void print();
  void deleteInfo(const std::string& authorName, const std::string& bookName); 
};

#endif // LIBRARY_H
