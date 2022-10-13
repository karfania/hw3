#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivotHelper(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    // Base Case, where head is empty
    if (head == NULL)
    {
        return;
    }

    // Holding the value after head so it isn't lost as
    // the original linked list is destroyed
    Node* temp = head -> next;

    // If the value at the current node is less than or equal
    // to the pivot, update smaller, update next to destroy original
    // list, and increment both smaller and head (using temp) in the recursive call
    if (head -> val <= pivot)
    {
        smaller = head;

        // Setting next to null, "cleaning up" the possible garbage
        smaller -> next = NULL;

        // Removing head from the original linked list
        head = NULL;
        llpivot(temp, smaller -> next, larger, pivot);
    } 
    
    // If the value at the current node is greater than the 
    // pivot, update larger and increment larger and 
    // head (using temp) in the recursive call
    else 
    {
        larger = head;

        // Setting next to null, "cleaning up" the possible garbage
        larger -> next = NULL;

        // Removing head from the original linked list
        head = NULL;
        llpivot(temp, smaller, larger -> next, pivot);
    }
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    // Pre-proccessing: making smaller and larger NULL
    smaller = NULL;
    larger = NULL;

    // Calling recurisve function
    llpivotHelper(head, smaller, larger, pivot);

    
}


