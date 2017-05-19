/*
 * main.c
 *
 *  Created on: 18 мая 2017 г.
 *      Author: shaveinikovds
 */

/*

5. Вы должны написать следующую программу на языке C: Вашей программе в качестве
аргумента будет передано имя файла, в котором будет находиться множество строк
(ASCII символы с кодами от 32 до 127). Далее Ваша программа должна считывать строки
из stdin, пока не придет строка "exit". После каждой считанной строки Ваша
программа должна выводить в stdout строку "YES" или "NO" в зависимости от
того, встречается данная строка в переданном файле или нет. Размер файла со
словарем не превосходит 128мб. Напишите как можно более эффективное решение и будьте
готовы объяснить, почему Вы выбрали именно это решение. В качестве ответа пришлите
ссылку на репозиторий с вашей программой и makefile'ом. Программа должна
компилироваться GCC 4.7.2.

 */

#include "stdlib.h"
#include "stdio.h"
#include "math.h"



//#define BASE 97 //base for hash
const int ALPH_SZ = 96;
const int BASE = 97;
int MOD;        //specify after realize number of strings

typedef enum { false, true } bool;

int gcd(int a, int b)
{
    return b?gcd(b, a%b):a;
}

bool CheckCoprime(int a, int b)
{
    if(gcd(a,b) == 1)
        return true;
    else
        return false;
}

typedef struct _Node
{
    struct _Node* next;
    char* data;
} Node;

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

long long getHash(char* p, int sz)
{

}

int ReadDictionary(Node* Head, FILE* fp) //return number of read words in list
{
    size_t read;
    size_t len = 0;
    Node* cur = Head;
    cur->data = NULL;
    Node* prev;
    int cnt = 0;
    while((read = getline(&cur->data, &len, fp)) != -1)
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

int main(int argc, char* argv[])
{
    /*


    char * p = NULL;
    size_t len = 0;
    size_t sz = getline(&p, &len, stdin);

    free(p);
    return 0;
    */

    FILE* fp;
    fp = fopen("dictionary","r");
    if(fp == NULL)
    {
        printf("Can't open file %s", argv[1]);
        exit(EXIT_FAILURE);
    }
    Node DictionaryHead;
    int DictionarySz = ReadDictionary(&DictionaryHead, fp);
    MOD = DictionarySz/0.75;    //load factor is about 0.75
    if(CheckCoprime(MOD, BASE) == false)        //BASE is prime, so ++ is ok, getting coprime
    {
        MOD++;
    }
    Node **HashTable;
    HashTable = (Node*)malloc(MOD*sizeof(Node*));




    Node* cur = &DictionaryHead;
    while(cur!= NULL)
    {
        printf("%s", cur->data);
        cur = cur->next;
    }
    printf("%d\n", DictionarySz);

    free(HashTable);
    FreeList(DictionaryHead, true);


    return 0;
}
