/**
 * @file book.h
 * @author Justin Finn and Gabriel Speer 
 * @date 2023-11-01
 * @brief book header file 
 * 
 * book header file that holds struct 
 */



#include <string>
#include <iostream>

#ifndef BOOK_H
#define BOOK_H

//this defines the template for book structures
struct book {
  std::string book_title, author_name, isbn_code;
  int page_num, year_num;
  float cover_price; 
};

#endif
