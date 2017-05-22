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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "list.h"
#include "hashtable.h"

#define EXIT "exit\n"


void ProcessInputStrings(const HashTable* hashTable)
{
    char * curStr;
    while(1)
    {
        size_t len = 0;
        getline(&curStr, &len, stdin);
        if(strcmp(curStr, EXIT) == 0)
            return;
        bool ans = CheckStringInHashTable(hashTable, curStr);
        if(ans == true)
            puts("YES");
        else
            puts("NO");
    }
    free(curStr);
}

int main(int argc, char* argv[])
{

    Node* DictionaryHead = NULL;
    int DictionarySz;
    if(argc > 1)
        DictionarySz = CreateDictionary(argv[1], &DictionaryHead);
    else
        DictionarySz = CreateDictionary("dictionary", &DictionaryHead);

    HashTable hashTable;
    CreateHashTable(DictionaryHead, DictionarySz, &hashTable);

    ProcessInputStrings(&hashTable);

    FreeHashTable(&hashTable);
    FreeList(DictionaryHead, true);


    return 0;
}
