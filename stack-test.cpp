#include "stack.h"
#include "iostream"


int main ()
{

    // Initializing an empty stack
    Stack<int> stackInt;
    Stack<std::string> stackString;

    // Trying to pop() an empty stack, should throw an error
    // and catch it, outputting the error info
    std::cout << "Stack of Ints\n" << std::endl;
    try
    {
        stackInt.pop();
    }
    catch(const std::exception& e)
    {
        // Prints "Tried to pop an empty stack!" as defined in the 
        // header file
        std::cerr << e.what() << '\n';
    }

    // Trying to top() an empty stack, should throw an error
    // and catch it, outputting the error info
    try
    {
        int top = stackInt.top();
        std::cout << "Top of the stack is: " << top << std::endl;
    }
    catch(const std::exception& e)
    {
        // Prints "Tried to top an empty stack!" as defined in the 
        // header file
        std::cerr << e.what() << '\n';
    }

    // Checking if the stack is empty, should return true as of now
    std::cout << "The stack is empty: " << std::boolalpha << stackInt.empty() << std::endl;

    // Printing the current size of the stack, which should be 0
    std::cout << "Current size of the stack: " << stackInt.size() << std::endl;
    std::cout << std::endl;

    // Pushing 2 items to the stack, checking the functions accordingly
    std::cout << "Pushing 3 5 to the stack" << std::endl;
    stackInt.push(3);
    stackInt.push(5);

    // Trying top, should print 5
    try
    {
        int top = stackInt.top();
        std::cout << "Top of the stack is: " << top << std::endl;
    }
    catch(const std::exception& e)
    {
        // Prints "Tried to top an empty stack!" as defined in the 
        // header file
        std::cerr << e.what() << '\n';
    }

    // Checking if the stack is empty, should return false
    std::cout << "The stack is empty: " << std::boolalpha << stackInt.empty() << std::endl;

    // Printing the current size of the stack, which should be 2
    std::cout << "Current size of the stack: " << stackInt.size() << std::endl;

    // Trying to pop() 5, new size should be 1 and top should be 3
    try
    {
        stackInt.pop();
        std::cout << "Popped 5 out of the stack" << std::endl;
        std::cout << "Current size of the stack: " << stackInt.size() << std::endl;
    }
    catch(const std::exception& e)
    {
        // Prints "Tried to pop an empty stack!" as defined in the 
        // header file
        std::cerr << e.what() << '\n';
    }

    // New top should be 3
    try
    {
        int top = stackInt.top();
        std::cout << "Top of the stack is: " << top << std::endl;
    }
    catch(const std::exception& e)
    {
        // Prints "Tried to pop an empty stack!" as defined in the 
        // header file
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n\n" << std::endl;




    // Attemtping the same function calls for a Stack of strings

    // Trying to pop() an empty stack, should throw an error
    // and catch it, outputting the error info
    std::cout << "Stack of Strings\n" << std::endl;
    try
    {
        stackString.pop();
    }
    catch(const std::exception& e)
    {
        // Prints "Tried to pop an empty stack!" as defined in the 
        // header file
        std::cerr << e.what() << '\n';
    }

    // Trying to top() an empty stack, should throw an error
    // and catch it, outputting the error info
    try
    {
        std::string top = stackString.top();
        std::cout << "Top of the string stack is: " << top << std::endl;
    }
    catch(const std::exception& e)
    {
        // Prints "Tried to top an empty stack!" as defined in the 
        // header file
        std::cerr << e.what() << '\n';
    }

    // Checking if the stack is empty, should return true as of now
    std::cout << "The stack is empty: " << std::boolalpha << stackString.empty() << std::endl;

    // Printing the current size of the stack, which should be 0
    std::cout << "Current size of the stack: " << stackString.size() << std::endl;
    std::cout << std::endl;

    // Pushing 2 items to the stack, checking the functions accordingly
    std::cout << "Pushing first second to the stack" << std::endl;
    stackString.push("first");
    stackString.push("second");

    // Trying top, should print second
    try
    {
        std::string top = stackString.top();
        std::cout << "Top of the stack is: " << top << std::endl;
    }
    catch(const std::exception& e)
    {
        // Prints "Tried to top an empty stack!" as defined in the 
        // header file
        std::cerr << e.what() << '\n';
    }

    // Checking if the stack is empty, should return false
    std::cout << "The stack is empty: " << std::boolalpha << stackString.empty() << std::endl;

    // Printing the current size of the stack, which should be 2
    std::cout << "Current size of the stack: " << stackString.size() << std::endl;

    // Trying to pop() second, new size should be 1 and top should be first
    try
    {
        stackString.pop();
        std::cout << "Popped 'second' out of the stack" << std::endl;
        std::cout << "Current size of the stack: " << stackString.size() << std::endl;
    }
    catch(const std::exception& e)
    {
        // Prints "Tried to pop an empty stack!" as defined in the 
        // header file
        std::cerr << e.what() << '\n';
    }

    // New top should be 3
    try
    {
        std::string top = stackString.top();
        std::cout << "Top of the stack is: " << top << std::endl;
    }
    catch(const std::exception& e)
    {
        // Prints "Tried to pop an empty stack!" as defined in the 
        // header file
        std::cerr << e.what() << '\n';
    }

};