#pragma once
#include "stdafx.h"
#include "iostream"
#include "Books.h"
#include "string"
using System::String;
using namespace System;
using namespace std;


Book::Book() {

}

Book::Book(string name) {
	setName(name);
}

Book::Book(string name, string author, string gener, int price) {
	setName(name);
	setDetails(author, gener, price);
}

Book::~Book() {

}

Book::!Book() {

}


void Book::setDetails(string author, string gener, int price) {
	detail.author = gcnew String(author.c_str());
	detail.gener = gcnew String(gener.c_str());
	detail.price = price;
}

void Book::setName(string name) {
	this->name = gcnew String(name.c_str());
}

void Book::showDetail() {
	Console::WriteLine(L"Book Name: " + name);
	Console::WriteLine(L"Author: " + detail.author);
	Console::WriteLine(L"Gener: " + detail.gener);
	cout << "Price: " << detail.price << endl << endl;
}

void Book::showName() {
	Console::WriteLine(L"Book Name: " + name);
}


String^ Book::getBookName() {
	return name;
}

BookDetail Book::getBookDetails() {
	return detail;
}