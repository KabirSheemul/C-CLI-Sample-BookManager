#pragma once
#include "cliext/list"
#include "Books.h"
#include "string"


ref class BookManager {
public:
	BookManager();
	~BookManager();
	!BookManager();
	void addBook();
	void updateBookDetail();
	void updateBookName();
	void viewBookList();
	void viewBookDetails();
	void viewBookDetail(std::string name);
	

private:
	cliext::list<Book^> bookList;

	Book^ findByName(std::string name);
	
};