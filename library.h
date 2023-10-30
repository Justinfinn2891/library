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

  void insertSorted(std::string author_name);
  void lookup();
  
  void reverse_lookup();
  void print();
  void deleteInformation(); 
};

#endif // LIBRARY_H
