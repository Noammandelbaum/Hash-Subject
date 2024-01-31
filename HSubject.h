/**
 * @brief A specialized HashTable class for storing subjects and their titles.
 *
 * This class inherits from the HashTable class and is specifically designed for
 * storing subjects and their associated titles in a hash table. It overrides the
 * hash functions, print functions, and removal functions to suit the specific
 * requirements of the application.
 */

#pragma once
#include <iostream>
#include <string>
#include <list>
#include "HashTable.h"
using namespace std;


class HSubject :public HashTable<list<string>, string>
{
	int key(string s); // Compute a unique key for a given string.

public:
	//Initializes the HSubject class with a specified size.
	HSubject(int n) :HashTable <list<string>, string>(n) {}

	// Override of the hash functions
	int h1(string s) override { return key(s) % size; }
	int h2(string s) override { return (key(s) % (size - 1) + 1) % size; }

	void printData(list<string>* listData); // Printing all the 'title's of one 'item'.
	void printS(string ky); // Printing all the 'title's on 'subject'.
	void printN(string ky, int N); // Printing the 'n' last 'title's on 'subject'.
	void printAll(); // Printing all the 'title's on all the 'subject's.
	void remove(string s);  // Removeing Subject from the hash table.
	void removeData(int i) override; // Remove all tha data from item
	void addSubjectAndTitle(string s, string t); // Adds a subject and title to the table
};
