#include "HSubject.h"
#include <algorithm>

/**
 * @brief Compute a unique key for a given string.
 *
 * This private function computes a unique key for a given string by summing
 * the ASCII values of its first, second, and last characters.
 *
 * @param s The input string.
 * @return int The computed key.
 */
int HSubject::key(string s)
{
	return (int)s[0] + (int)s[1] + (int)s[s.length() - 1];
}

// Printing 'title's of one 'item'.
void HSubject::printData(list<string>* listData)
{
	for (auto it = listData->begin(); it != listData->end(); it++)
		cout << (*it) << " ";
	cout << endl;
}

// Printing all the 'title's on 'subject'.
void HSubject::printS(string ky)
{
	int index = search(ky);

	// If the subject not found
	if (index == -1)
	{
		cout << "ERROR\n";
		return;
	}

	list<string>* listData = getItemData(index);

	// If there are no titles
	if (listData->size() == 0)
	{
		cout << "ERROR\n";
		return;
	}

	// Printing
	cout << "Subject " << ky << " " << listData->size() << " topics:" << endl;
	printData(listData);

}


void HSubject::printN(string ky, int N)
{
	int index = search(ky);
	if (index == -1) // Not found.
	{
		cout << "ERROR\n";
		return;
	}

	list<string>* listData = getItemData(index);
	int i = 0;
	for (auto it = listData->begin(); it != listData->end() && i != N; it++, i++)
		cout << (*it) << " ";
	cout << endl;
}

// Printing all the 'title's on all the 'subject's.
void HSubject::printAll()
{
	list<string> listKey = keyToArr();
	listKey.sort();
	cout << "All subjects and titles:\n";
	for (auto it = listKey.begin(); it != listKey.end(); it++)
	{
		// The subject
		cout << *it << ": ";
		int index = search(*it);

		// The data of the subject
		printData(getItemData(index));
	}
}

void HSubject::remove(string s) // Removeing Subject from the hash table.
{
	HashTable::removeItem(s);
}

// Remove all tha data from item
void HSubject::removeData(int i)
{
	list<string>* listData = getItemData(i);
	listData->~list();
}

// Adds a subject and title to the table
void HSubject::addSubjectAndTitle(string s, string t)
{
	int index = search(s);
	if (index == -1)
		index = hash(s, 0);
	if (index == -1) //Full table.
		cout << "ERROR: FULL TABLE" << endl;
	else //Insert title to the 'data' list.
	{
		auto listData = addItem(s, index);
		listData->push_front(t);
	}
}