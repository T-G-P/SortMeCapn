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
    char * str1 = "two";
    char * str2 = "three";
    char * str3 = "four";
    char * str6 = "four";
    char * str4 = "one";
    char * str5 = "seven";
    SLInsert(newList, str1);
    SLInsert(newList, str2);
    SLInsert(newList, str3);
    SLInsert(newList, str4);
    SLRemove(newList, str4);
    SLInsert(newList, str5);
    SLInsert(newList, str6);
    SortedListIteratorPtr SLI = SLCreateIterator(newList);
    printf("%s\n",SLNextItem(SLI));
    printf("%s\n",SLNextItem(SLI));
    printf("%s\n",SLNextItem(SLI));
    printf("%s\n",SLNextItem(SLI));
    printf("%s\n",SLNextItem(SLI));
    printf("%s\n",SLNextItem(SLI));


    /*Node *ptr;
    for(ptr = newList->head; ptr!=NULL; ptr=ptr->next){
        printf("%s\n",ptr->data);
    }*/

}
