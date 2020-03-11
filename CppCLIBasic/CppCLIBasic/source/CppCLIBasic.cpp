// ConsoleApplication1.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include "string"
#include <cliext/list>
#include "BookManager.h"
//using namespace std;

using namespace System;

int main(array<System::String ^> ^args)
{
	Console::WriteLine(L"Hello World");
	std::cout << "Native Hello World" << std::endl;
	BookManager ^bookManager = gcnew BookManager();

	std::string res, dummy;

	do {
		if (!res.empty()) {
			if (res == "1") {
				bookManager->addBook();
			}
			else if (res == "2") {
				bookManager->viewBookList();
			}
			else if (res == "3") {
				bookManager->viewBookDetails();
			}
			else if (res == "4") {

			}
			else if (res == "5") {
				bookManager->updateBookDetail();
			}
			else {
				std::cout << "Invalied choice!!!" << std::endl;
			}
		}

		std::cout << "1 add a book" << std::endl;
		std::cout << "2 show book list" << std::endl;
		std::cout << "3 show book detail" << std::endl;
		std::cout << "4 alter book name" << std::endl;
		std::cout << "5 alter book detail" << std::endl;
		std::cout << std::endl << "0 exit" << std::endl;
		std::cout << "Enter choice: ";
		std::cin >> res;
		std::getline(std::cin, dummy);
	} while (res != "0");
	return 0;
}
