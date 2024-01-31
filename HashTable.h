/**
 * HashTable
 *
 * Template class for hash table data structure. Allows storing
 * and retrieving key-value pairs.
 *
 * Uses open addressing with double hashing for collision resolution.
 */

#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

template <typename T, typename K>
class HashTable
{
protected:

	/**
	  * Item class to represent a record in the table
	  * Holds actual data, key and occupancy state
	  */
	enum state { empty, full, deleted };
	template <typename U, typename V>
	class Item
	{
	public:
		U data;
		V key;
		state flag = empty;
		Item() {}
		Item(V  k, state f) { key = k; flag = f; }
		Item(U d, V  k, state f) { data = d; key = k; flag = f; }
	};


	int size;
	int containing = 0; // Occupied slots
	Item<T, K>* arr; // Array of items
	bool prime(int n);
	int hash(K key, int i); // Return the index to insert some 'key', or -1 if not found.
	
	// Virtual hash functions 
	virtual int h1(K key) = 0; 
	virtual int h2(K key) = 0;
public:
	HashTable(int capacity) { size = capacity, arr = new Item<T, K>[capacity](); }
	T* getItemData(int i); // Get item data pointer by array index.
	T* addItem(K key, int i); // Add new Item and return pointer to the data field.
	int removeItem(K key); // Remove Item and return his index if found, else return -1;
	virtual void removeData(int i) = 0;
	int search(K key); // Return index of given 'key' if found else -1.
	list<K> keyToArr(); // Return arr with all the 'key's.
};

/**
 * Get item data pointer by array index
 *
 * @param i - Array index to get item at
 * @return Pointer to item data or NULL if not found
 */
template<typename T, typename K>
inline T* HashTable<T, K>::getItemData(int i)
{
	if (!&(arr[i].data))
		return NULL;
	return &(arr[i].data);
}

/**
 * Add new item to hash table
 * Handles collision resolution internally.
 *
 * @param key - Item key value
 * @param index - Array index to insert item at
 * @return Pointer to inserted item data
*/
template<typename T, typename K>
inline T* HashTable<T, K>::addItem(K key, int index)
{
	Item<T, K>* item = &arr[index];
	if (item->key != key)
	{
		item->key = key;
		item->flag = full;
		containing++;
	}
	T* dataField = &(item->data);
	return dataField;
}

/**
 * @brief Remove an item from the HashTable based on the given key.
 *
 * This function attempts to remove an item from the HashTable using the specified key.
 * If the key is not found in the HashTable, the function returns -1.
 * If the key is found, the item is marked as deleted, and the total count of items in the
 * HashTable is reduced by one.
 *
 * @param key The key of the item to be removed.
 * @return int If the key is found, the index of the removed item; otherwise, -1.
 */

template<typename T, typename K>
inline int HashTable<T, K>::removeItem(K key)
{
	int iToRem = search(key);
	if (iToRem == -1)
	{
		return -1;
	}
	else
	{
		removeData(iToRem);
		arr[iToRem].flag = deleted;
		containing--;
	}
	return iToRem;
}

/**
 * @brief Retrieve all keys from the HashTable and return them in a list.
 *
 * This function iterates through the HashTable and retrieves all keys of the
 * items marked as 'full'. The keys are then returned in a list.
 *
 * @return std::list<K> A list containing all keys in the HashTable.
 */
template<typename T, typename K>
inline list<K> HashTable<T, K>::keyToArr()
{
	list<K> listKey;
	int j = 0;
	Item<T, K>* currItem = arr;
	for (int i = 0; j < containing && i < size; i++)
	{
		currItem = &(arr[i]);
		if (currItem->flag == full)
		{
			listKey.push_front(currItem->key);
			j++;
		}
	}
	return listKey;
}

/**
 * @brief Search for a key in the HashTable and return its index.
 *
 * This function searches for a key in the HashTable using double hashing.
 * It calculates the current index based on the primary and secondary hash functions
 * (h1 and h2). It iterates through the HashTable until it finds an empty slot or
 * locates the key marked as 'full'. If the key is found, the index is returned; otherwise, -1
 * is returned to indicate that the key is not present in the HashTable.
 *
 * @param key The key to be searched in the HashTable.
 * @return int The index of the key if found; otherwise, -1.
 */
template<typename T, typename K>
inline int HashTable<T, K>::search(K key)
{
	int i = 0;
	int numH1 = h1(key);
	int numH2 = h2(key);
	Item<T, K>* currItem = arr;

	while (i < size)
	{
		int currInd = (numH1 + i * numH2) % size;
		currItem = &(arr[currInd]);
		if (currItem == NULL || currItem->flag == empty)
			return -1;

		if (currItem->key == key && currItem->flag == full)
			return currInd;
		i++;
	}
	return -1;
}

/**
 * @brief Compute the hashed index for a key with linear probing.
 *
 * This function computes the hashed index for a key using linear probing.
 * It takes the primary and secondary hash functions (h1 and h2), as well as
 * an iteration index 'i'. It calculates the current index based on the double hashing
 * technique and linear probing. If the slot is empty or contains a deleted item,
 * the current index is returned. If the loop completes without finding an empty slot, -1
 * is returned, indicating that the HashTable is full.
 *
 * @param key The key to be hashed.
 * @param i The iteration index for linear probing.
 * @return int The computed index for the key with linear probing, or -1 if the HashTable is full.
 */
template<typename T, typename K>
inline int HashTable<T, K>::hash(K key, int i)
{
	int numH1 = h1(key);
	int numH2 = h2(key);
	Item<T, K>* currItem = arr;

	while (i < size)
	{
		// Calculate the current index using double hashing
		int currInd = (numH1 + i * numH2) % size;
		currItem = &(arr[currInd]);
		if (currItem == NULL)
			return -1;

		if (currItem->flag != full)
			return currInd;
		i++;
	}
	return -1;
}
