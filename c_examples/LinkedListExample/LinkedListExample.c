/*
 * File:      LinkedListExample.c
 * Copyright: James Hurst 2022
 * Purpose:   An example in C showing the creation and usage of a
 *            simple linked list, parse and maintain an ordered link list.
 *            Add new elements dynamically to maintain sequence order.
 *            Keep a count within each node regarding how many times it has
 *            been found.
 *            Return -1 to the system if a node can not be found or created.
 *
 * gcc -Wall LinkedListExample.c -o LinkedListExample

 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct Node{
    int         value;    // Example contents of the node, just a simple int
    int         count;
    struct Node *next;
} tNode;

static tNode *linkedList = NULL;

static tNode* searchLinkedList(int valueToFind);
static tNode* addNodeAfter(tNode *currentNode, int value);
static tNode* addNodeBefore(tNode *currentNode, int value);
static bool addNodeBeforeExample(tNode *currentNode, int value, tNode** newNode);
static void parseLinkedList();

int main(void) {
    printf("Linked list example\n");

    /* As an example attempt to find the following values in the linked list
     * if it is a new value add a entry to the linked list in the correctly
     * ordered location, if it already exists inc its count
     */
    /* Return -1 to the system if a node can not be found or created */
    if(searchLinkedList(5) == NULL) {
        return FAILURE;
    }

    if(searchLinkedList(7) == NULL) {
        return FAILURE;
    }

    if(searchLinkedList(6) == NULL) {
        return FAILURE;
    }

    if(searchLinkedList(5) == NULL) {
        return FAILURE;
    }

    if(searchLinkedList(4) == NULL) {
        return FAILURE;
    }

    if(searchLinkedList(4) == NULL) {
        return FAILURE;
    }

    if(searchLinkedList(-1) == NULL) {
        return FAILURE;
    }


    /* Print out the entire linked list */
    parseLinkedList();

    return SUCCESS;
}

/*
 * Name:    searchLinkedList
 * Purpose: Search the linked list, insert a node in the correct order
 *          if a matching one can not be found
 *          If this function returns NULL there has been an error finding
 *          or inserting a newe node
 */
static tNode* searchLinkedList(int valueToFind) {

    tNode* currentNode = NULL;

    if(linkedList == NULL) {
        /* Special case on first usage, linked list is empty */
        /* addNodeBefore or addNodeAfter can be used */
        linkedList = addNodeAfter(NULL, valueToFind);

        /* Allow function to return address of new node, NULL if not set */
        currentNode = linkedList;
    } else if(linkedList->value > valueToFind) {
        /* Special case, insert new node at start of linked list */

        linkedList = addNodeBefore(linkedList, valueToFind);

        /* Alternative example */
        /* Take note of the linkedList address being passed in here */
        //bool success = addNodeBeforeExample(linkedList, valueToFind, &linkedList);

        /* Allow function to return address of new node, NULL if not set */
        currentNode = linkedList;
    } else {
        /* Parse through the linked list looking for a match */
        currentNode = linkedList;

        /* The only time this will not insert a node is when the node needs
         * adding to the start of the linked list, see special case above
         */
        while(currentNode != NULL) {
            if(currentNode->value == valueToFind) {
                /* Matching value found, inc count */
                currentNode->count++;
                break;
            } else if(currentNode->value < valueToFind) {
                /* Check if a new node should be inserted after the current node.
                 * Do this by checking the contents of the next linked object
                 */
                if(currentNode->next == NULL) {
                    /* End of list, add new node */

                    /* Allow function to return address of new node, NULL if not set */
                    currentNode = addNodeAfter(currentNode, valueToFind);

                    break;
                } else {
                    /* Next node in the linked list contains a higher value
                     * than we are looking for, so insert new node
                     */
                    if(currentNode->next->value > valueToFind) {
                        /* Allow function to return address of new node, NULL if not set */
                        currentNode = addNodeAfter(currentNode, valueToFind);
                        break;
                    }
                }
            }

            currentNode = currentNode->next;
        }
    }

    return currentNode;
}

/*
 * Name:    addNodeAfter
 * Purpose: Add a node to the linked list after the current node.
 * Returns the address of the new node
 */
static tNode* addNodeAfter(tNode *currentNode, int value) {

    tNode *node = NULL;

    node = (tNode*) malloc(sizeof(tNode));

    if(node == NULL) {
        printf("Unabled to create node\n");
    } else {
        /* The node has been successfully created, insert in linked list */
        node->value = value;
        node->count = 1;

        if(currentNode != NULL) {
            /* Insert new node after current node */
            node->next = currentNode->next;
            currentNode->next = node;
        } else {
            /* Creating the first node */
            node->next = NULL;
        }

    }

    return node;
}

/*
 * Name:    addNodeBefore
 * Purpose: Add a node to the linked list before the current node,
 *          this is only applicable when adding a node to the start
 *          of the linked list.
 *          Returns the address of the new node
 */
static tNode* addNodeBefore(tNode *currentNode, int value) {

    tNode *node = NULL;

    node = (tNode*) malloc(sizeof(tNode));

    if(node == NULL) {
        printf("Unabled to create node\n");
    } else {
        /* The node has been successfully created, insert in linked list */
        node->value = value;
        node->count = 1;

        if(currentNode != NULL) {
            /* Insert new node before current node */
            node->next = currentNode;
        } else {
            /* Creating the first node */
            node->next = NULL;
        }

    }

    return node;
}

/*
 * Name:    addNodeBeforeExample
 * Purpose: Add a node to the linked list before the current node,
 *          this is only applicable when adding a node to the start
 *          of the linked list.
 *          This is an example of the above function using a function argument
 *          to get the newly malloc'ed node via a double pointer. The return value
 *          is used to report status and not the address of the node
 */
 static bool addNodeBeforeExample(tNode *currentNode, int value, tNode** newNode) {

    bool success = false;

    *newNode = (tNode*) malloc(sizeof(tNode));

    if(*newNode != NULL) {
        success = true;

        /* The node has been successfully created, insert in linked list */
        (*newNode)->value = value;
        (*newNode)->count = 1;

        if(currentNode != NULL) {
            /* Insert new node before current node */
            (*newNode)->next = currentNode;
        } else {
            /* Creating the first node */
            (*newNode)->next = NULL;
        }
    }

    return success;
}

/*
 * Name:    parseLinkedList
 * Purpose: Parse the linked list and print out each nodes cvalue and count
 */
 static void parseLinkedList() {
     tNode* node = NULL;

     node = linkedList;

     while(node != NULL) {
         printf("value %d, count %d\n", node->value, node->count);
         node = node->next;
     }
 }