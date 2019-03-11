Write a C++ program which will engage in a repeated challenge / response scenario through a shared memory region with a "Challenge server" program.  The Challenge server program will be run first, your program must read a short integer value from shared memory and write an appropriate short integer value back to the shared memory region.  The short integer value that will be written back to the shared memory region will be the next value in the Hailstone Sequence.  The Hailstone Sequence begins with some positive whole number value and will eventually converge to 1, the program to receive the value 1 is the loser!

* Algorithm for the Hailstone Sequence is given as follows:
  * if N is odd: ( N + 1 ) = 3 * N + 1
  * if N is even: ( N + 1 ) = N / 2
    * where N is the current number in the sequence and ( N + 1 ) is the next number in the sequence

* To test the attached executable files:
  * download the appropriate 32-bit or 64-bit version of the executables to some directory on your system
  * open two terminal windows side by side
  * in one window run the Server program
    * some messages should be displayed stating that a value is being written to shared memory and another value is being waited upon
  * in the other window run the Challenger program
  * In rapid succession, data is exchanged between the Challenger and Server.  One program will announce victory, the other program will announce defeat.  The program that announces defeat is the program receives the value of 1 (last number in the Hailstone Sequence)

```
Example output is shown below:
Terminal 1
./1_Server.out
1: Value to write into shared memory: 17
1: Awaiting new data in shared memory region
1: Value Received: 52
1: Value to write into shared memory: 26
1: Awaiting new data in shared memory region
1: Value Received: 13
1: Value to write into shared memory: 40
1: Awaiting new data in shared memory region
1: Value Received: 20
1: Value to write into shared memory: 10
1: Awaiting new data in shared memory region
1: Value Received: 5
1: Value to write into shared memory: 16
1: Awaiting new data in shared memory region
1: Value Received: 8
1: Value to write into shared memory: 4
1: Awaiting new data in shared memory region
1: Value Received: 2
VICTORY IS MINE!

I WIN!

1: Attempting to close shared memory region
1: ERROR: Error removing shared memory region: Challenge

Terminal 2
./2_Challenger.out
2: FIRST Value Received: 17
2: Value to write into shared memory: 52
2: Awaiting new data in shared memory region
2: Value Received: 26
2: Value to write into shared memory: 13
2: Awaiting new data in shared memory region
2: Value Received: 40
2: Value to write into shared memory: 20
2: Awaiting new data in shared memory region
2: Value Received: 10
2: Value to write into shared memory: 5
2: Awaiting new data in shared memory region
2: Value Received: 16
2: Value to write into shared memory: 8
2: Awaiting new data in shared memory region
2: Value Received: 4
2: Value to write into shared memory: 2
2: Awaiting new data in shared memory region
2: Value Received: 1
2: I lose!
2: About to close the shared memory region
2: Successfully closed shared memory region
```

* You are to create the Challenger program which will perform the following primary actions:
  1. open the shared memory region named "Challenge"
  2. read a short integer value from the base address of the shared memory region
  3. print the value that was received
  4. apply the Hailstone Sequence algorithm to the value that was received
  5. print the Hailstone Sequence value to the base address of the shared memory region
  6. wait for a new short integer value to appear in the base address of the shared memory region
  7. repeat steps 2 through 6 until:
    * after step 3, if the value 2 is received, your program will
      * claim victory
      * write the value 1 to the base address of the shared memory region
      * attempt to close the shared memory region and exit
    * after step 3, if the value 1 is received, your program will
      * admit defeat
      * attempt to close the shared memory region and exit
Ubuntu Linux compatible executables are attached to this message so you can see exactly how the program you create should work.  (Add executable permissions to the executable files using the command ` chmod u+x filename.out ` )

32-bit and 64-bit executable files are attached to this message.  Your program should work identically to the Challenger executable file!

NOTES:
The Challenge server will validate the data sent to it by the Challenger program and your program will be accused of cheating if the Challenge server receives invalid data.
Running the attached CheatingChallenger executable will cause Challenge server to issue cheating allegations!
If needed, the Challenger program or Challenge server program can be forcibly terminated by using CTRL+C
forcibly terminating the Challenger and Challenge server programs can cause the shared memory region to remain, use the attached CLEANsharedMem.cpp to remove the left over shared memory region.
Read these instructions carefully and understand all information contained in this description.  Also see: Reading and Writing Integers with shared memory
