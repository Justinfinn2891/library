

#include <string>
#include <iostream>

#ifndef BOOK_H
#define BOOK_H

struct book {
  std::string book_title, author_name, isbn_code;
  int page_num, year_num;
  float cover_price; 
};

#endif
