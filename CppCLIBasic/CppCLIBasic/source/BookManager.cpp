#pragma once
#include "stdafx.h"
#include "iostream"
#include "BookManager.h"
#include "string"
#include "cliext/list"
#include "algorithm"
using namespace std;
using namespace System;

static void ClrStringToStdString(string &outStr, String ^str) {
	IntPtr ansiStr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
	outStr = (const char*)ansiStr.ToPointer();
	System::Runtime::InteropServices::Marshal::FreeHGlobal(ansiStr);
}


BookManager::BookManager() {

}

BookManager::~BookManager() {

}

BookManager::!BookManager() {

}

void BookManager::addBook() {

	string name, author, gener;
	int price;
	cout << "Book Name: ";
	getline(cin, name);
	//cin >> name;
	cout << "Author Name: ";
	getline(cin, author);
	//cin >> name;
	cout << "Gener: " ;
	getline(cin, gener);
	//cin >> gener;
	cout << "Price: ";
	cin >> price;

	Book ^book = gcnew Book(name, author, gener, price);
	bookList.push_back(book);
}


void BookManager::updateBookName() {

}

Book^ BookManager::findByName(string name) {
	String ^bookName = gcnew String(name.c_str());

	for each(Book^ book in bookList) {
		if (book->getBookName() == bookName) {
			return book;
		}
	}

	/*auto it = find_if(bookList.begin(), bookList.end(),
		[name](Book^ book) {return book->getBookName() == gcnew String(name.c_str()); });*/
	return nullptr;
}

void BookManager::viewBookList() {
	if (bookList.size() < 0) {
		cout << "No book to show!!";
	}
	int count = 1;
	for each(Book^ book in bookList) {
		Console::WriteLine(count++ + L". " + book->getBookName());
	}

}

void BookManager::viewBookDetails() {
	if (bookList.size() < 0) {
		cout << "No book to show!!";
		return;
	}
	cout << "####################################" << endl;
	for each(Book^ book in bookList) {
		book->showDetail();
	}
}

void BookManager::viewBookDetail(string name) {
	if (bookList.size() < 0) {
		cout << "No book to show!!";
		return;
	}

	Book^ book = findByName(name);
	if (book) {
		cout << "####################################" << endl;
		book->showDetail();
	}
	
}


void BookManager::updateBookDetail() {
	if (bookList.size() < 0) {
		cout << "No book to show!!";
		return;
	}

	viewBookList();
	string name, author, gener, dummy;
	int price;
	cout << "Enter book name: " << endl;
	getline(cin, name);
	Book^ book = findByName(name);
	if (book) {
		cout << "##### Book Details ###" << endl;
		book->showDetail();
		cout << endl;

		cout << "Book Name: ";
		getline(cin, name);
		if (name == "") {
			ClrStringToStdString(name, book->getBookName());
		}
		cout << "Author Name: ";
		getline(cin, author);
		if (author == "") {
			ClrStringToStdString(author, book->getBookDetails().author);
		}
		//cin >> name;
		cout << "Gener: ";
		getline(cin, gener);
		if (gener == "") {
			ClrStringToStdString(author, book->getBookDetails().gener);
		}
		//cin >> gener;
		cout << "Price: ";
		cin >> price;


		book->setName(name);
		book->setDetails(author, gener, price);
		cout << "##### Updated Book Details ###" << endl;
		book->showDetail();
		return;
	}

	cout << "Book didn't find!!!" << endl;
}

