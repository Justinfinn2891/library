/**
 * @file library.h
 * @author Justin Finn and Gabriel Speer
 * @date 2023-11-01
 * @brief .h file that holds the class library
 * 
 * holds class library and method prototypes
 */

#include "book.h"
#include <iostream>
#include <list>
#include <fstream>

#ifndef LIBRARY_H
#define LIBRARY_H


/**
 * library class that holds method prototypes used in .cpp that builds/prints/modifies library data
 *
 * @class library library.h "library/library.h"
 * @brief library class
 *
 */
class library
{
private:
  //creates the library or list of book structures
  std::list<book> myLibrary;  

public:

/**
 * constructor
 *
 * @pre 
 * @post initiliazes variables 
 * 
 */
  library();
  

/**
 * reads data from file
 *
 * @param const std::string& filename name of file
 * @pre nothing
 * @return void 
 * @post data
 * 
 */
  void readFromFile(const std::string& filename);

/**
 * inputs data to a file
 *
 * @param const std::string& filename name of file
 * @pre name of file
 * @return void 
 * @post outputed file 
 * 
 */
  void inputToFile(const std::string& filename);


/**
 * sorts alphebetically data
 *
 * @param const book& newBook struct variable
 * @pre info
 * @return void 
 * @post sorted info
 * 
 */
  void insertSorted(const book& newBook);

/**
 * finds author from book title
 *
 * @param const std::string& authorName name of author
 * @pre book title
 * @return void 
 * @post author name
 * 
 */
  void findAuthor(const std::string& authorName);
  

/**
 * finds book from author
 *
 * @param const std::string& bookName name of book
 * @pre author name 
 * @return void 
 * @post book name 
 * 
 */
  void findBook(const std::string& bookName);

/**
 * prints library
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void print();

/**
 * deletes information 
 *
 * @param const std::string& authorName name of auhtor
 * @param const std::string& bookName name of book
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void deleteInfo(const std::string& authorName, const std::string& bookName); 
};

#endif // LIBRARY_H
