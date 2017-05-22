/*
 * hashtable.c
 *
 *  Created on: 22 мая 2017 г.
 *      Author: shaveinikovds
 */

#include "hashtable.h"

const int ALPH_BEGIN = 32;
const int ALPH_SZ = 96;
const int BASE = 97;



void FreeHashTable(HashTable * hashTable)
{
    for(int i = 0; i < hashTable->size; ++i)
    {
        FreeList(hashTable->table[i], false);
    }
    free(hashTable->table);
}

int GetHash(const char* str)
{
    size_t sz = strlen(str);
    int hash = 0;
    int st = 1;
    for(int i = 0; i < sz; ++i)
    {
        hash += ((unsigned char)(str[i]) - ALPH_BEGIN + 1)*st;  //overflowing by 2^32
        st*= BASE;
    }
    return hash;
}

int GetIndex(int h, int size)
{
    return h&(size-1);
}


void FillHashTable(HashTable* hashTable, Node* DictionaryHead)
{
    Node* cur = DictionaryHead;
    while(cur != NULL)
    {
        int index = GetIndex(GetHash(cur->data),hashTable->size);
        InsertNode(&hashTable->table[index], cur);
        cur = cur->next;
    }
}


bool CheckStringInHashTable(const HashTable* hashTable, const char* str)
{
    int index = GetIndex(GetHash(str), hashTable->size);
    return CheckStringInList(hashTable->table[index], str);
}


void CreateHashTable(Node* DictionaryHead, int DictionarySz, HashTable* hashTable)
{

    hashTable->size = DictionarySz/0.75;    //load factor is about 0.75

    hashTable->table = (Node**)malloc(hashTable->size*sizeof(Node*));
    memset(hashTable->table, 0, hashTable->size*sizeof(Node*));
    FillHashTable(hashTable, DictionaryHead);

}
