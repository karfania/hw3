## HW 3

 - Name: Kourosh Arfania
 - Email: arfania@usc.edu

### Checkpoint 1 Notes

#### Compiling the Code:

- Enter docker container (`ch start csci104` -> `ch shell csci104`) or use Codio and navigate to `hw3/`

##### llrec-test
(1) Run `make` to compile and link all files for the recurisve linked list problems
(2) Enter `./llrec-test llrec-test<n>.in` in your terminal to pass in inputs and test the function calls
- llrec-test1.in contains only positive numbers
- llrec-test2.in contains both positive, negative, and 0 (considered positive)
(3) Run `make valgrind` to check for memory loss/leaks

##### stack.h
(1) Enter `g++ -g -Wall -std=c++11 -c stack.h stack-test.cpp` in your terminal to create a `stack-test.o` object
(2) Enter `g++ -g -Wall -std=c++11 -o stack-test stack-test.o` to create the executable `stack-test`
(3) Run the test by entering `./stack-test` in your terminal

