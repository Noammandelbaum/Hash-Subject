/*
Hash Table Program

This program implements a hash table to store subjects and titles.
It allows the user to add, delete, and lookup subjects and associated titles.

Functions:
- addSubjectAndTitle() - Adds a subject and title to the table
- remove() - Removes a subject and its titles from the table
- printS() - Prints all titles for a given subject
- printN() - Prints the last N appearances of a subject
- printAll() - Prints all non-empty entries in the table

The main() function presents a menu and allows the user to
perform operations on the hash table by entering single letter
commands.

The HSubject class (defined in HSubject.h) implements the actual
hash table data structure.

*/

#include "HSubject.h" 


int main() {

	// Variables  
	char ch;
	int n = 0;
	string subject = "";
	string title = "";
	HSubject hs(1000); // Create hash table with 1000 buckets 
	

	// Print menu options
	cout << "Hash Table\n";
	cout << "\nChoose one of the following" << endl;
	cout << "a: Add a subject and a title" << endl;
	cout << "d: Del a subject " << endl;
	cout << "t: Print all titles of the subject " << endl;
	cout << "s: Print N first appearances of a subect " << endl;
	cout << "p: Print all non-empty entries " << endl;
	cout << "e: Exit" << endl;

	// Process user input choice 
	do {
		cin >> ch;
		switch (ch)
		{
		case 'a':cout << "Enter a subject and a title\n";
			cin >> subject >> title;
			hs.addSubjectAndTitle(subject, title);
			break;
		case 'd':cout << "Enter a subject to remove\n";
			cin >> subject;
			hs.remove(subject); break;
		case 't':cout << "Enter subject to print\n";
			cin >> subject;
			hs.printS(subject); break;
		case 's':cout << "Enter a subject and N\n"; cin >> subject >> n;
			hs.printN(subject, n); break;
		case 'e':cout << "bye\n"; break;
		case 'p':hs.printAll(); break;
		default: cout << "ERROR\n";  break;
		}
	} while (ch != 'e');

	return 0;
}