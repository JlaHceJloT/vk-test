/*
 * list.c
 *
 *  Created on: 22 мая 2017 г.
 *      Author: shaveinikovds
 */


#include "list.h"

void InsertNode(Node** head, Node* toInsert)
{
    Node * newNode = (Node*)malloc(sizeof(Node));    //new node with ptr to existing data
    newNode->data = toInsert->data;
    newNode->next = *head;
    *head = newNode;
}


void FreeList(Node* head, bool bFreeData)
{
    while(head != NULL)
    {
        Node* tmp = head->next;
        if(bFreeData == true)
            free(head->data);
        free(head);
        head = tmp;
    }
}


int ReadDictionary(Node** Head, FILE* fp) //return number of read words in list
{
    *Head = (Node*)malloc(sizeof(Node));
    size_t len = 0;
    Node* cur = *Head;
    cur->next = NULL;
    cur->data = NULL;
    Node* prev;
    int cnt = 0;
    while(getline(&cur->data, &len, fp) != -1) //TODO: pb remove read
    {
        cnt++;
        cur->next = (Node*)malloc(sizeof(Node));
        prev = cur;
        cur = cur->next;
        cur->data = NULL;
    }
    free(cur);
    prev->next = NULL;
    return cnt;
}

bool CheckStringInList(Node* head, const char* str)
{
    Node* cur = head;
    while(cur != NULL)
    {
        if(strcmp(cur->data, str) == 0)
        {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

int CreateDictionary(const char* fileName, Node** DictionaryHead)
{
    FILE* fp;
    fp = fopen("dictionary","r");
    if(fp == NULL)
    {
        printf("Can't open file %s", fileName);
        exit(EXIT_FAILURE);
    }
    int DictionarySz = ReadDictionary(DictionaryHead, fp);
    fclose(fp);
    return DictionarySz;
}
