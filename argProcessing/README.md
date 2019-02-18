# Lab: Command Line Argument Processing
## Instructions
* Create a C++ program which will receive numerical values through the command line and perform some computations.  Your program will operate with the following restrictions:
    1. program will accept between 3 and 10 numerical command line arguments
        * NOTE:  checking if an argument is actually a decimal quantity isn't needed
    2. the argument values must be between -100 and +100
        * restriction 1 or 2 is violated then output an error message and terminate the program
* The program you create will
    * Output a list of numbers received as a command line arguments
    * Calculate the following:
        * Arithmetic **sum** of the command line argument number values
        * Arithmetic **average** of the command line argument number values
        * Value **range** of the command line argument number values

Example program run and outputs are shown below:

_Example 1, when no arguments are entered:_
```
./a.out
no arguments entered, I'm done
```
_Example 2, when less than 3 arguments are entered:_
```
./a.out 1
Please enter more than 3 numerical arguments
```
_Example 3, proper program run with output_
```
./a.out 1 2 3 4 5 6 7
The numbers received are being buffered up as follows:
numbersArray[ 0 ] = 1
numbersArray[ 1 ] = 2
numbersArray[ 2 ] = 3
numbersArray[ 3 ] = 4
numbersArray[ 4 ] = 5
numbersArray[ 5 ] = 6
numbersArray[ 6 ] = 7
The sum is 28
The average is 4.0
The range is 6
```
_Examples of the remaining program features are not shown._
* Examples code to get you started can be found:
    * here: [commandLineArgs_Example_mul2add3](commandLineArgs_Example_mul2add3.cpp)
    * here: [00_BasicCmdLineArgsTs](00_BasicCmdLineArgsTst.cpp)
* Also to check each condition that your program must satisfy in terms of evaluating command line arguments, you may find it useful to use a script to compile and run your program multiple times.  An example script to test the *commandLineArgs_Example_mul2add3* source code listed above can be found here: [runMul2Add3](runMul2Add3.sh)
    * NOTE: in regards to using the test script
        * The script file will have executable permissions when used on the Linux Subsystem for WIndows (Ubuntu on Windows)
        * The script file will not have executable permissions when used on a native Linux system or Linux virtual machine.  To add executable permissions:
            * navigate to the folder where runMul2Add3.sh is located and type:
            ```
            $ chmod u+x runMul2Add3.sh 
        ```
