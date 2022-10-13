#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

private:
    std::vector<T> currStack;
};

template <typename T>
Stack<T>::Stack()
{

}

template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
bool Stack<T>::empty() const
{
    if (currStack.size() == 0)
    {
        return true;
    }

    return false;
}

template <typename T>
size_t Stack<T>::size() const
{
    return currStack.size();
}

template <typename T>
void Stack<T>::push(const T& item)
{
    currStack.push_back(item);
}

template <typename T>
void Stack<T>::pop()
{
    if (empty())
    {
        throw std::underflow_error("Tried to pop an empty stack!");
    } else 
    {
        currStack.pop_back();
    }
    
}

template <typename T>
T const& Stack<T>::top() const
{
    if (empty())
    {
        throw std::underflow_error("Tried to top an empty stack!");
    }

    else 
    {
        return currStack.back();
    }
    
}



#endif