

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
