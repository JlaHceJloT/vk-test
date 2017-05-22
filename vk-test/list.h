/*
 * list.h
 *
 *  Created on: 22 мая 2017 г.
 *      Author: shaveinikovds
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum { false, true } bool;

typedef struct _Node
{
    struct _Node* next;
    char* data;
} Node;


void FreeList(Node* head, bool bFreeData);
bool CheckStringInList(Node* head, const char* str);
void InsertNode(Node** head, Node* toInsert);

int CreateDictionary(const char* fileName, Node** DictionaryHead);


#endif /* LIST_H_ */
