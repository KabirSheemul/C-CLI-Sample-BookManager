#pragma once
#include "string"
using System::String;

value struct BookDetail {
	String ^author;
	String ^gener;
	int price;
};

ref class Book {
public:
	Book(std::string name);
	Book(std::string name, std::string author, std::string gener, int price);
	Book();
	~Book();
	!Book();
	void setDetails(std::string auth, std::string gen, int price);
	void setName(std::string name);
	void showName();
	void showDetail();
	String^ getBookName();
	BookDetail getBookDetails();

private:
	String ^name;
	BookDetail detail;

};


