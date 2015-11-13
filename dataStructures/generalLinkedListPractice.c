#include <stdio.h>
#include <stdlib.h>

/* Define Node structure */
struct nodeStruct {
    int item;
    struct nodeStruct *next;
};

/* Create a node */
struct nodeStruct* linkedList_createNode(int item)
{
    struct nodeStruct *newNode;
    newNode = (struct nodeStruct *)malloc(sizeof(struct nodeStruct));
    newNode->item = item;
    newNode->next = NULL;
    return newNode; 
}

/* Insrt Head */
void linkedList_insert(struct nodeStruct **headRef, struct nodeStruct *node)
{
    if ( headRef == NULL ) {
        *headRef = node;
    }
    else {
        node->next = *headRef;
        *headRef = node;
    }
}

/* Print Node recursively */ 
void linkedList_printBackwards(struct nodeStruct *head)
{
    if ( head->next != NULL ) {
        linkedList_printBackwards(head->next);
        printf("%d\n", head->item);
    }
    // NULL

}

/*** MAIN ***/
int main()
{
    struct nodeStruct *headP = (struct nodeStruct *)malloc(sizeof(*headP));

    struct nodeStruct *newNode = linkedList_createNode(2);
    linkedList_insert(&headP, newNode);

    newNode = linkedList_createNode(1);
    linkedList_insert(&headP, newNode);
   

    linkedList_printBackwards(headP);
    return 0;
}
