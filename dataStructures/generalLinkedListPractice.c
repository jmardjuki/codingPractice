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


/* Print Node backward recursively */ 
void linkedList_printBackwards(struct nodeStruct *head)
{
    if ( head->next != NULL ) {
        linkedList_printBackwards(head->next);
        printf("%d,", head->item);
    }

}

/* Print the whole linked list in order */
void linkedList_printAll(struct nodeStruct *head)
{
    struct nodeStruct * node = head;
    while (node->next != NULL) {
        printf("%d,", node->item);
        node = node->next;
    }
    printf("\n");

}

/*** MAIN ***/
int main()
{
    struct nodeStruct *headP = (struct nodeStruct *)malloc(sizeof(*headP));

    struct nodeStruct *newNode = linkedList_createNode(3);
    linkedList_insert(&headP, newNode);

    newNode = linkedList_createNode(2);
    linkedList_insert(&headP, newNode);
   
    newNode = linkedList_createNode(1);
    linkedList_insert(&headP, newNode);

    linkedList_printBackwards(headP);

    linkedList_printAll(headP);
    return 0;
}
