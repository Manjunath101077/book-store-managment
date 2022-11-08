// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<string>
using namespace std;

class bookshope
{
public:
	void control_panel();
	void add_book();
	void show_book();
	void check_book();
	void update_book();
	void delete_book();
	

};
void bookshope::control_panel()
{
	system("cls");
	cout << "\n\n\t\t\t\t Book Management";
	cout << "\n\n 1.Add New Book";
	cout << " \n 2.Display Books";
	cout << "\n 3.Check Specific Book";
	cout << " \n 4.Update Book";
	cout << " \n 5.Delete Book";
	cout << " \n 6.exit";
}

void bookshope::add_book()
{
	
	system("cls");
	fstream file;
	int no_copy;
	string b_name, a_name, b_id;
	cout << "\n\n\n\t\t\t\t ADD New Book";
	cout << "\n\n Book Id :";
	cin >> b_id;
	cout << "\n\n Book Name :";
	cin >> b_name;
	cout << "\n\n Author Name: ";
	cin >> a_name;
	cout << "\n\n Number of Copies :";
	cin >> no_copy;
	file.open("book.txt",ios::out|ios::app);
	file << " "<<b_id<<" "<< b_name << " " << a_name << " " << no_copy << "\n";
	file.close();
}

void bookshope::show_book()
{
	system("cls");
	fstream file;
	int no_copy;
	string b_name, b_id, a_name;
	cout << "\n\n\t\t\t\t Show All the books";
	file.open("book.txt", ios::in);
	if (!file)
	
		cout << "\n\n file opening error...";

	
	else
	{
		cout << "\n\n Book id  Book name  Author   No.of copy\n\n";
		file >> b_id >> b_name >> a_name >> no_copy;
		while (!file.eof())
		{
			cout << " " << b_id << "\t" << b_name << "\t" << a_name << "\t" << no_copy << "\n\n";
			file >> b_id >> b_name >> a_name >> no_copy;
		}
		file.close();
	}
}
void bookshope::check_book()
{
	system("cls");
	fstream file;
	string b_idd;
	int no_copy,count=0;
	string b_id, b_name, a_name;
	cout << "\n\n\t\t\tCheck Specific Book";
	file.open("book.txt", ios::in);
	if (!file)
	{
		cout << "\n\n file opening error";

	}
	else
	{
		cout << "\n\n\t\tBook id: ";
		cin >> b_idd;
		file >> b_id >> b_name >> a_name >> no_copy;
		while (!file.eof())
		{
			if (b_idd == b_id)
			{
				system("cls");
				cout << "\n\n\n\t\t\tCheck Specfic book";
				cout << "\n\n Book id :" << b_id;
				cout << "\n\n Book name :" << b_name;
				cout << "\n\n Autor Name :" << a_name;
				cout << "\n\n Number of copies :" << no_copy;
				count++;
				break;
			}
			file >> b_id >> b_name >> a_name >> no_copy;
		}
		file.close();
		if (count == 0)
		{
			cout<< "\n\n\t Book not found";
		}
	}
}
void bookshope::update_book()
{
	system("cls");
	fstream file;
	fstream file1;
	string b_id,b_iddd,b_name,b_na,a_name,a_na;
	int no_copy, n_no, count = 0;

	cout << "\n\n\t\t\tUpdate Book Record";
	file.open("book.txt", ios::in);
	file1.open("book1.txt", ios::app | ios::out);
	
	if (!file)
	
		cout << "\n\n file opening error";
	
	
	else
	{
		cout << "\n\n Book Id:";
		cin >> b_id;
		file >> b_iddd >> b_name >> a_name >> no_copy;
		while (!file.eof())
		{
			if (b_id == b_iddd)
			{
				system("cls");
				cout << "\n\nUpdate Book record";
				cout << "\n\n\t\tNew Book Name:";
				cin >> b_na;
				cout << "\n\n\t\tNew Author Name:";
				cin >> a_na;
				cout << "\n\n\t\tNumber of copies:";
				cin >> n_no;
				file1 << " " << b_id << " " << b_na << " " << a_na << " " << n_no<<"\n";
				count++;

			}
			else
			
				file1 << " " << b_iddd << " " << b_name << " " << a_name << " " << no_copy << "\n";
			file >> b_iddd >> b_name >> a_name >> no_copy;

		}
		if (count == 0)
		{
			cout << "\n\n Book ID not found";
		}
		file.close();
		file1.close();
		remove("book.txt");
		rename("book1.txt", "book.txt");
	}
}
void bookshope::delete_book()
{
	system("cls");
	int n_copy,count=0;
	string b_iddd, b_id, b_name, a_name;
	fstream file,file1;
	cout << "\n\n\n\t\t\tDelete Book Record";
	file1.open("book1.txt",ios::out|ios::app);
	file.open("book.txt", ios::in);
	if (!file)
	
		cout << "\n\n\ file opening error";
	
	else
	{
		cout << "\n\n Book id :";
		cin >> b_id;
		file >> b_iddd >> b_name >> a_name >> n_copy;
		while (!file.eof())
		{
			if (b_id == b_iddd)
			{
				system("cls");
				cout << "\n\n\t\t Delete Book record";
				cout << "\n\n One Book is deleted successfully";
				count++;
			}
			else

				file1 << " " << b_iddd << " " << b_name << " " << a_name << " " << n_copy << "\n";
			file >> b_iddd >> b_name >> a_name >> n_copy;


		}
		if (count == 0)
		{
			cout << "Book id not found" << "\n";
		}
	
	
	}
	file1.close();
	file.close();
	remove("book.txt");
	rename("book1.txt", "book.txt");
}
int main()
{
	int choice;
	char x;
	bookshope b;
	p:
	b.control_panel();
	cout << "\n\n Your choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		do {
			b.add_book();
			cout << "\n\n Do you want to Add an another Book (y,n) :";
			cin >> x;
		} while (x == 'y');
		break;
	case 2:
		b.show_book();
		break;
	case 3:
		b.check_book();
		break;
	case 4:
		b.update_book();
		break;
	case 5:
		b.delete_book();
		break;
	case 6:
		exit(0);
	default:
		cout << "\n\n Invalid Value ...please try again later";

	}
	_getch();
	goto p;



	system("pause");
    return 0;
}

