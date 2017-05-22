/*
 * hashtable.h
 *
 *  Created on: 22 мая 2017 г.
 *      Author: shaveinikovds
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "list.h"

typedef struct
{
    Node** table;
    int size;
} HashTable;


bool CheckStringInHashTable(const HashTable* hashTable, const char* str);
void CreateHashTable(Node* DictionaryHead, int DictionarySz, HashTable* hashTable);

void FreeHashTable(HashTable * hashTable);


#endif /* HASHTABLE_H_ */
