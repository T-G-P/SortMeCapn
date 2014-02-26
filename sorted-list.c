#include <string.h>
#include <stdlib.h>
#include "sorted-list.h"

/*Creates a Linked List Node
 *
 */

Node *createNode(void *val)
{
    Node *llNode = malloc(sizeof(Node));
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
    SortedListPtr sl = malloc(sizeof(struct SortedList));
    sl->head = NULL;
    sl->cf = cf;
    sl->df = df;
    return sl;
}

/*
 * SLDestroy destroys a list, freeing all dynamically allocated memory.
 *
 * You need to fill in this function as part of your implementation.
 */

void SLDestroy(SortedListPtr list)
{
    /*Destroy all Nodes, data. Free on the nodes, and df(data)*/
    Node *ptr = NULL;
    while(!(list->head == NULL)){
        list->df(head->data);
        ptr = list->head;
        head = head->next;
        free(ptr);
    }
    free(list);

}
int SLInsert(SortedListPtr list, void *newObj)
{
    if(list->head == NULL){
        Node *newNode = createNode(newObj);
        list->head = newNode;
        list->head->refCount++;
        return 1;
    }
    while(list->head != NULL){
        if(list->head->data = newObj){
            return 1;
        }





    }




}

int SLRemove(SortedListPtr list, void *newObj)
{

}

SortedListIteratorPtr SLCreateIterator(SortedListPtr list)
{
    SortedListIteratorPtr slIterator = malloc(sizeof(struct SortedListIterator));
    slIterator->currNode = list->head;
    if(list->head != NULL){
        list->head->refCount++;
    }
    return slIterator;



}

void SLDestroyIterator(SortedListIteratorPtr iter)
{
    //decrement currNode count, then free iterator.
}


void *SLNextItem(SortedListIteratorPtr iter)
{
    //Check if item has been removed. If removed, move iterator to next node.

}



