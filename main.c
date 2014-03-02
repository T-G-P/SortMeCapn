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
    char * str1 = "two";
    char * str2 = "three";
    char * str3 = "four";
    char * str6 = "four";
    char * str4 = "one";
    char * str5 = "seven";
    int x = 5;
    int y = 7;
    int z = 12;

    //inserting some ints into int list
    SLInsert(intList, &x);
    SLInsert(intList, &y);
    SLInsert(intList, &z);

    //inserting and removing some strings into string list
    SLInsert(newList, str1);
    SLInsert(newList, str1);
    SLInsert(newList, str1);
    SLInsert(newList, str2);
    SLInsert(newList, str3);
    SLInsert(newList, str4);
    SLRemove(newList, str4);
    SLInsert(newList, str5);
    SLInsert(newList, str6);
    SLRemove(newList, str2);

    //Creating Iterators
    SortedListIteratorPtr SLI = SLCreateIterator(newList);
    SortedListIteratorPtr SlInt = SLCreateIterator(intList);

    //Go through string list and print
    printf("%s\n",SLNextItem(SLI));
    printf("%s\n",SLNextItem(SLI));
    printf("%s\n",SLNextItem(SLI));
    printf("%s\n",SLNextItem(SLI));

    //go through int list and print
    printf("%d\n",SLNextItem(SlInt));
    printf("%d\n",SLNextItem(SlInt));
    printf("%d\n",SLNextItem(SlInt));


    /*Node *ptr;
    for(ptr = newList->head; ptr!=NULL; ptr=ptr->next){
        printf("%s\n",ptr->data);
    }*/

}
