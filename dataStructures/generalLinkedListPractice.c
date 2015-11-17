/***************************************************************************
 *  File Name: generalLinkedListPractice.c
 *  Description: Implementation of various functions related to Linked List
 *               for coding practice
 *  Author: Janet Mardjuki
 *  Year: 2015
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>


/*** GLOBALS VARIABLES AND DEFINITION ***/

/**
 * Node struct
 *  Define Node structure
 */
struct nodeStruct {
    int item;
    struct nodeStruct *next;
};

/*** FUNCTIONS IMPLEMENTATION ***/

/** LinkedList_createNode 
 *  Create a node 
 *  @params:
 *      int item: data to be created the ndoe form
 */
struct nodeStruct* linkedList_createNode(int item)
{
    struct nodeStruct *newNode;
    newNode = (struct nodeStruct *)malloc(sizeof(struct nodeStruct));
    newNode->item = item;
    newNode->next = NULL;
    return newNode; 
}

/**
 *  linkedList_insertHead
 *  Insert Node in the list from the Head
 *  @params:
 *      struct nodeStruct **headRed: the head refernce to the linked list to be inserted
 *      struct nodeStruct *node: the node to be inserted 
 */
void linkedList_insertHead(struct nodeStruct **headRef, struct nodeStruct *node)
{
    if ( headRef == NULL ) {
        *headRef = node;
    }
    else {
        node->next = *headRef;
        *headRef = node;
    }
}

/**
 *  linkedList_insertTail
 *  Insert node from tail
 *  @params:
 *      struct ndoeStruct **headRef: the head reference to the linked list to be inserted
 *      struct nodeStruct *node: the node to be inserted to tail
 */
void linkedList_insertTail(struct nodeStruct **headRef, struct nodeStruct *node)
{
    if ( headRef == NULL ) {
        *headRef = node;
    }       
    else {
        struct nodeStruct *current = *headRef;
        while ( current->next != NULL ) {
            current->next;
        }
        current->next = node;
        free(current);
    }
}

/* Reverse Linked List */
void linkedList_reverseList(struct nodeStruct **head)
{
    struct nodeStruct *prev = NULL;
    struct nodeStruct *current = *head;
    struct nodeStruct *temp = NULL;

    while ( current != NULL ) {
        temp = current->next;
        current->next = prev;
        prev = temp;

    }
    *head = prev;

    free(prev);
    free(current);
    free(temp);

    return;
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
    free(node);

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
