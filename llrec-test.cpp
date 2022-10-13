#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

// If the node is a single digit, return true
// (and remove it from the list)
struct isSingleDigit
{ 
    bool operator()(const int& val)
    {
        if (val < 10)
        {
            return true;
        }
        
        return false;
    }
};

// If the node is even, return true
// (and remove it from the list)
struct isEven
{
    bool operator()(const int& val)
    {
        if (val % 2 == 0)
        {
            return true;
        }

        return false;
    }
};

// If the node is odd, return true
// (and remove it from the list)
struct isOdd
{
    bool operator()(const int& val)
    {
        if (val % 2 == 1)
        {
            return true;
        }

        return false;
    }
};

// If the node is positive, return true
// (and remove it from the list)
struct isPositive
{
    bool operator()(const int& val)
    {
        if (val >= 0)
        {
            return true;
        }

        return false;
    }
};

// If the node is negative, return true
// (and remove it from the list)
struct isNegative
{
    bool operator()(const int& val)
    {
        if (val < 0)
        {
            return true;
        }

        return false;
    }
};



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* headllpivot = readList(argv[1]);
    Node* headllfilter = readList(argv[1]);
    cout << "Original list: ";
    print(headllpivot);

    // Test out your linked list code

    // Testing when nothing is added to smaller
    cout << "\nITERATING THROUGH LIST WITH PIVOT 5" << endl;

    // Uninitialized, as they can contain garbage
    Node* smaller;
    Node* larger;

    llpivot(headllpivot, smaller, larger, 5);

    cout << "Smaller than or equal to 5: ";
    print(smaller);

    cout << "Larger than 5: ";
    print(larger);

    cout << "Original list: ";
    print(headllpivot);

    dealloc(headllpivot);
    dealloc(smaller);
    dealloc(larger);


    // Testing when there is a blend
    cout << "\nITERATING THROUGH LIST WITH PIVOT 7" << endl;
    headllpivot = readList(argv[1]); // resetting headllpivot

    llpivot(headllpivot, smaller, larger, 7);

    cout << "Smaller than or equal to 7: ";
    print(smaller);

    cout << "Larger than 7: ";
    print(larger);

    cout << "Original list: ";
    print(headllpivot);

    dealloc(headllpivot);
    dealloc(smaller);
    dealloc(larger);

    // Testing when there is nothing added to larger
    cout << "\nITERATING THROUGH LIST WITH PIVOT 20" << endl;
    //delete headllpivot;
    headllpivot = readList(argv[1]); // resetting headllpivot

    llpivot(headllpivot, smaller, larger, 20);

    cout << "Smaller than or equal to 20: ";
    print(smaller);

    cout << "Larger than 20: ";
    print(larger);

    cout << "Original list: ";
    print(headllpivot);

    dealloc(headllpivot);
    dealloc(smaller);
    dealloc(larger);

    /*-------------------------------------------------
    ------------LLFILTER TESTING BELOW ----------------
    --------------------------------------------------*/

    cout << "\nFILTERING LIST" << endl;
    cout << "Original list: ";
    print(headllfilter);
    isSingleDigit comp1;
    isEven comp2;
    isOdd comp3;
    isPositive comp4;
    isNegative comp5;

    // Removing single digits
    headllfilter = llfilter(headllfilter, DoValCompare(comp1));
    cout << "Updated list with removed single-digit nodes: ";
    print(headllfilter);
    dealloc(headllfilter);


    // Removing evens
    headllfilter = readList(argv[1]); //resetting headllfilter
    headllfilter = llfilter(headllfilter, DoValCompare(comp2));
    cout << "Updated list with removed even nodes: ";
    print(headllfilter);
    dealloc(headllfilter);

    // Remvoing odds
    headllfilter = readList(argv[1]); //resetting headllfilter
    headllfilter = llfilter(headllfilter, DoValCompare(comp3));
    cout << "Updated list with removed odd nodes: ";
    print(headllfilter);
    dealloc(headllfilter);

    // Removing positive nodes
    headllfilter = readList(argv[1]); //resetting headllfilter
    headllfilter = llfilter(headllfilter, DoValCompare(comp4));
    cout << "Updated list with removed positive nodes: ";
    print(headllfilter);
    dealloc(headllfilter);

    // Removing negative nodes
    headllfilter = readList(argv[1]); //resetting headllfilter
    headllfilter = llfilter(headllfilter, DoValCompare(comp5));
    cout << "Updated list with removed negative nodes: ";
    print(headllfilter);
    dealloc(headllfilter);



    
    return 0;

}
