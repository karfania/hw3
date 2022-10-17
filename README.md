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

(4) Enter `valgrind --tool=memcheck --leak-check=yes ./stack-test1 to check for memory loss/leaks


### Checkpoint 2 Notes

#### Compiling the Code:
- Enter docker container (`ch start csci104` -> `ch shell csci104`) or use Codio and navigate to `hw3/`

##### heap_test

- Navigate to `hw3/heap_test` by entering `cd heap_test`

(1) Run `make` to compile and link all files for the heap header and tests

(2) Run `make test` to test code against suite of examples

(3) Run `make valgrind` to check for memory loss/leaks

###### Design Choices/Notes:
- used a vector as the container for the heap due to its dynamic sizing capabilities and push_back efficiency
- used 0-based indexing to simplify initialization
    - found the pattern of children's indexes: n * index + 1 ... n * index + n
    - found whether or not a node is a leaf-node by checking if the index of what would be THEIR left-most node was within the bounds of the arary


##### logicsim
- Navigate to `hw3/logicsim` by entering `cd logicsim`

(1) Run `make` to compile and link all files for the logicsim visualizations

(2) Enter `./logicsim <input>.txt > my_<input>.uml` in the terminal to generate a UML file based on input file's events

(3) Enter `java -jar plantuml.jar my_<input>.uml` to generate a PNG image of the command gates under the name `my_<input>.png`
- <inputs>: single_and, single_or, single_not, exclusive_or
- so, to execute logicsim on exclusive or, you would do the following:

	(1) `make`

	(2) `./logicsim exclusive_or.txt > my_exclusive_or.uml`

	(3) `java -jar plantuml.jar my_exclusive_or.uml`

	(4) Open `my_exclusive_or.png` and check against `exclusive_or.png`