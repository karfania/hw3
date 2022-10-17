#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int n; //data member storing ary-ness of tree
  PComparator comparator;
  std::vector<T> nHeap;
  void heapify(size_t index, PComparator c);

};

// Add implementation of member functions here

// Constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
  n = m; // grabbing ary-ness of heap
  comparator = c; // grabbing comparator
}

// Destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}

// Return the size of the container
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return nHeap.size();
}

// Checking if empty, which leverages the already-implemented size() method
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  if (size() == 0)
  {
    return true;
  }
  return false;
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Tried to top() an empty heap!");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else
  {
    return nHeap[0];
  }

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(size_t index, PComparator c)
{
  int aryNess = this -> n;
  size_t idx = index;


  // while not a leaf node (aka while a left-most leaf node for node at idx exists)
  while (((aryNess * idx) + 1) < nHeap.size()) 
  {
    // The left-most child of a parent at loc index will always
    // be at the following index:
    size_t bestChild = (aryNess * idx) + 1;

    for (int i = 2; i <= aryNess; ++i)
    {
      // checking if other children exist
      // if they do exist and it is less than minChild, then update it

      // if the child's index is within the bounds of the array, it exists
      size_t currChild = (aryNess * idx) + i;
      if (currChild < nHeap.size())
      {
        // if this child is better than current best child, as dictated by
        // PComparator, then update bestChild
        if (c(nHeap[currChild], nHeap[bestChild]))
        {
          bestChild = currChild;
        }
      }
    }

    // Once the best child is found, check and see if it is better than the parent
    // If better than the parent, swap them and make the new parent what was the bestChild
    if (c(nHeap[bestChild], nHeap[idx]))
    {
      T temp = nHeap[idx];
      nHeap[idx] = nHeap[bestChild];
      nHeap[bestChild] = temp;
      idx = bestChild;
    }

    // If the child is worse than the parent, and it is the parent's best child, then the
    // parent and child are in the correct place
    else
    {
      break;
    }

  }
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("Tried to pop() an empty heap!");

  } 
  
  // Steps in popping on a heap
  // (1) swap top and bottom nodes
  // (2) pop_back()
  // (3) trickleUp/heapify
  else 
  {
    // Swapping top and bottom
    nHeap[0] = nHeap.back();

    // Removing the old top
    nHeap.pop_back();

    // Calling trickleDown/heapify helper function
    PComparator comp = this -> comparator;
    heapify(0, comp);
    

  }
}
// Implementing TrickleUp
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  int aryNess = this -> n; // getting ary-ness
  PComparator c = this -> comparator; // getting the comparator
  T temp = item;
  nHeap.push_back(temp); // adding the item to the back of the array

  size_t idx = nHeap.size() - 1; //push_back, so start at the end
  size_t parent;

  // If the node is the only node in the vector, there's no real child
  if (idx == 0)
  {
    parent = 0;
  } else
  {
    parent = (idx-1) / aryNess; // formula to find any parent
  }

  // while the index of parent is within the bounds of the container
  // and the parent is worse than their child, continue swapping and 
  // pushing it up

  while (parent > 0 && c(nHeap[idx], nHeap[parent]))
  {
    // Swapping values
    T temp = nHeap[idx];
    nHeap[idx] = nHeap[parent];
    nHeap[parent] = temp;

    // New parent index is one level above
    // New index is where parent used to be
    idx = parent;
    parent = (idx - 1) / aryNess;
  }
  

  // when we are at the root, make one final comparison
  if (parent == 0 && idx != 0)
  {
    // if the child is better than the parent, swap
    if (c(nHeap[idx], nHeap[parent]))
    {
      // Swapping values
      T temp = nHeap[idx];
      nHeap[idx] = nHeap[parent];
      nHeap[parent] = temp;

    }

  }
  
}





#endif

