/*
 * main.c
 *
 *  Created on: 18 мая 2017 г.
 *      Author: shaveinikovds
 */

/*
 Написать функцию bsearch, которая принимает на вход отсортированный по неубыванию массив
 целых чисел и целое число x. В качестве результата функция должна возвращать индекс первого
 элемента массива, строго большего x. В Вашей реализации функция может принимать любое
 количество любых параметров, только 2 этих параметра обязательны. При использовании Вашей
 функции должна быть возможность определить, существует ответ или нет. В качестве решения
 пришлите ссылку на репозиторий с программой на языке C с примером использования функции.
 */
#include "stdlib.h"
#include "stdio.h"
#define SZ 10

typedef enum { false, true } bool;

int bsearch1(int* arr, int x, int sz) //return -1 if all elements are less or eq to x
{
    int l = -1, r = sz;
    while(r - l > 1)
    {
        int mid = (r+l)/2;
        if(arr[mid] > x)
            r = mid;
        else
            l = mid;
    }
    if(r == sz)
        r = -1;
    return r;
}

//here's another way with returning not through return value (depends on style)
 bool bsearch2(int *arr , int x, int sz, int* outRes)    //return true if element is found, false otherwise
 {
     int l = -1, r = sz;
     while(r - l > 1)
     {
         int mid = (r+l)/2;
         if(arr[mid] > x)
             r = mid;
         else
             l = mid;
     }
     *outRes = r;
     if(r == sz)
         return false;
     else
         return true;
 }

 void test(int *arr)
 {
     for(int i = -1; i<= SZ; ++i)
     {
         int ans1, ans2;
         ans1 = bsearch1(arr,i,SZ);
         if(ans1 != -1)
         {
             printf("Answer1 to query %d: %d\n", i, ans1);
         }
         else
         {
             printf("Answer1 to query %d: Element not found\n", i);
         }
         if(bsearch2(arr, i, SZ, &ans2))
         {
             printf("Answer2 to query %d: %d\n", i, ans2);
         }
         else
         {
             printf("Answer2 to query %d: Element not found\n", i);
         }
     }
     printf("\n");
 }


int main()
{
    int arr1[SZ] = {0,1,2,3,4,5,6,7,8,9};
    int arr2[SZ] = {0,1,2,3,3,3,3,7,8,9};
    int arr3[SZ] = {0,0,0,3,3,3,3,7,8,9};
    int arr4[SZ] = {0,0,0,3,3,3,3,7,7,7};
    test(arr1);
    test(arr2);
    test(arr3);
    test(arr4);


    return 0;
}
