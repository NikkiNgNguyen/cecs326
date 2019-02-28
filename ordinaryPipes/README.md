# Lab: Ordinary Pipes

## Create a C++ program which works in the following fashion:

1. Process launches, creates an ordinary pipe, then forks
2. The Parent process receives inputs from stdin and sends them to the child using the ordinary pipe
3. The Child process receives the inputs and processes them as follows:
    1. First value that is received is expected to be an positive integer operand smaller than 100
    2. Second value that is received will be a plus sign or a minus sign to indicate what operation to perform
    3. Third value that is received is expected to be an positive integer operand smaller than 100
4. Once the 3 values are sent from the Parent, the parent prints a message and terminates
5. Once the 3 values are received by the Child, the child performs either addition of the values or subtraction of the values

* Run one of the following executable files to understand how the program you create will operate:
    * 32-bit Linux users click here: [32BitLinux_LabPipes](32BitLinux_LabPipes.out)
    * 64-bit Linux users click here: [64BitLinux_LabPipes](64BitLinux_LabPipes.out)
* after downloading an executable file, add executable permissions by using the `chmod u+x <file>` command and replace `<file>` with the name of the executable you have downloaded.

Also, see the following example for getting started in this lab: [InteractiveOrdinaryPipe](InteractiveOrdinaryPipe.cpp)
