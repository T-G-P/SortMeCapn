/*
 * sorted-list.c
 */

#include	<string.h>
#include <stdio.h>
#include <stdlib.h>
#include	"sorted-list.h"

int compareInts(void *p1, void *p2)
{
	int i1 = *(int*)p1;
	int i2 = *(int*)p2;

	return i1 - i2;
}

int compareDoubles(void *p1, void *p2)
{
	double d1 = *(double*)p1;
	double d2 = *(double*)p2;

	return (d1 < d2) ? -1 : ((d1 > d2) ? 1 : 0);
}

int compareStrings(void *p1, void *p2)
{
	char *s1 = p1;
	char *s2 = p2;

	return strcmp(s1, s2);
}

//Destructor functions
void destroyBasicTypeAlloc(void *p){
	//For pointers to basic data types (int*,char*,double*,...)
	//Use for allocated memory (malloc,calloc,etc.)
	free(p);
}

void destroyBasicTypeNoAlloc(void *p) {
	//For pointers to basic data types (int*,char*,double*,...)
	//Use for memory that has not been allocated (e.g., "int x = 5;SLInsert(mylist,&x);SLRemove(mylist,&x);")
	return;
}

int main()
{
    SortedListPtr newList = SLCreate(compareStrings,destroyBasicTypeNoAlloc);
    SortedListPtr intList = SLCreate(compareInts, destroyBasicTypeNoAlloc);
    SortedListPtr finalList = SLCreate(compareInts, destroyBasicTypeNoAlloc);

    //string list values
    char * str1 = "two";
    char * str2 = "three";
    char * str3 = "four";
    char * str6 = "four";
    char * str4 = "one";
    char * str5 = "seven";

    //int list values
    int x = 5;
    int y = 7;
    int z = 12;
    int a = 1;
    int b = 8;
    int c = 18;

    //final list values
    int d = 1;
    int e = 2;
    int f = 3;
    int g = 4;
    int h = 5;
    int i = 6;
    int j = 7;
    int k = 8;
    int l = 9;
    int m = 10;
    int n = 11;
    int o = 12;
    int p = 13;


    //inserting some ints into int list
    SLInsert(intList, &x);
    SLInsert(intList, &y);
    SLInsert(intList, &z);
    SLInsert(intList, &c);
    SLInsert(intList, &a);
    SLInsert(intList, &b);

    //inserting and removing some strings into string list
    SLInsert(newList, str1);
    SLRemove(newList, str4);
    SLInsert(newList, str1);
    SLInsert(newList, str1);
    SLInsert(newList, str2);
    SLInsert(newList, str3);
    SLRemove(newList, str3);
    SLInsert(newList, str4);
    SLRemove(newList, str4);
    SLInsert(newList, str5);
    SLInsert(newList, str6);
    //SLRemove(newList, str2);
    SLInsert(newList, str4);
    SLRemove(newList, str2);
    SLInsert(newList, str2);
    SLRemove(newList, str1);


    SLInsert(finalList, &d);
    SLInsert(finalList, &e);
    SLInsert(finalList, &f);
    SLInsert(finalList, &g);
    SLInsert(finalList, &h);
    SLInsert(finalList, &i);
    SLInsert(finalList, &j);
    SLInsert(finalList, &k);
    SLInsert(finalList, &l);
    SLInsert(finalList, &m);
    SLInsert(finalList, &n);
    SLInsert(finalList, &o);
    SLInsert(finalList, &p);

    //Creating Iterators
    SortedListIteratorPtr SLI = SLCreateIterator(newList);
    SortedListIteratorPtr SlInt = SLCreateIterator(intList);
    SortedListIteratorPtr SlFinal = SLCreateIterator(finalList);

    //Go through string list and print
    printf("%s\n",SLNextItem(SLI));
    printf("%s\n",SLNextItem(SLI));
    printf("%s\n",SLNextItem(SLI));
    printf("%s\n",SLNextItem(SLI));

    //go through int list and print
    //Returning void star, turning into int * and dereferencing that
    printf("\n%d\n",*(int*)SLNextItem(SlInt));
    printf("%d\n",*(int*)SLNextItem(SlInt));
    printf("%d\n",*(int*)SLNextItem(SlInt));
    printf("%d\n",*(int*)SLNextItem(SlInt));
    printf("%d\n",*(int*)SLNextItem(SlInt));
    printf("%d\n",*(int*)SLNextItem(SlInt));

    //go through final list and print stuff with iterator movement
    printf("\n%d\n",*(int*)SLNextItem(SlFinal));
    SLRemove(finalList, &o);
    SLRemove(finalList, &n);
    printf("%d\n",*(int*)SLNextItem(SlFinal));
    printf("%d\n",*(int*)SLNextItem(SlFinal));
    printf("%d\n",*(int*)SLNextItem(SlFinal));
    printf("%d\n",*(int*)SLNextItem(SlFinal));
    printf("%d\n",*(int*)SLNextItem(SlFinal));
    printf("%d\n",*(int*)SLNextItem(SlFinal));
    printf("%d\n",*(int*)SLNextItem(SlFinal));
    printf("%d\n",*(int*)SLNextItem(SlFinal));
    printf("%d\n",*(int*)SLNextItem(SlFinal));
    printf("%d\n",*(int*)SLNextItem(SlFinal));

    //Destroying the Iterators
    SLDestroyIterator(SlFinal);
    SLDestroyIterator(SlInt);
    SLDestroyIterator(SLI);

    //Destroying the SortedLists
    SLDestroy(newList);
    SLDestroy(intList);
    SLDestroy(finalList);


    /*Node *ptr;
    for(ptr = newList->head; ptr!=NULL; ptr=ptr->next){
        printf("%s\n",ptr->data);
    }*/

}
