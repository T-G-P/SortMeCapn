#include <string.h>
#include <stdlib.h>
#include "sorted-list.h"

/*Creates a Linked List Node
 *
 */

Node createNode(void *val)
{
    Node llNode = malloc(sizeof(struct Node));
    llNode->data = val;
    llNode->reMoved = 0;
    llNode->refCount = 0;
    llNode->next = NULL;
    return llNode;

}
/*
 * SLCreate creates a new, empty sorted list.  The caller must provide
 * a comparator function that can be used to order objects that will be
 * kept in the list, and a destruct function that gets rid of the objects
 * once they are no longer in the list or referred to in an iterator.
 *
 * If the function succeeds, it returns a (non-NULL) SortedListT object,
 * otherwise, it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df)
{
    SortedListPtr sl = malloc(sizeof(struct SortedListPtr));
    sl->CompareFuncT = cf;
    sl->DestructFunct = df;
}

/*
 * SLDestroy destroys a list, freeing all dynamically allocated memory.
 *
 * You need to fill in this function as part of your implementation.
 */

void SLDestroy(SortedListPtr list)
{
}

int SLInsert(SortedListPtr list, void *newObj)
{
}

int SLRemove(SortedListPtr list, void *newObj)
{
}

SortedListIteratorPtr SLCreateIterator(SortedListPtr list)
{
}

void SLDestroyIterator(SortedListIteratorPtr iter)
{
}


void *SLNextItem(SortedListIteratorPtr iter)
{
}



