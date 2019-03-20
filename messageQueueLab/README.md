# Message Queue Hailstone Sequence Lab

* NOTE: This lab using Message Queue and MUST be done in a native Linux environment!
    * Windows subsystem for Linux, Cygwin, MinGW, and Mac will NOT work!
    * Native Linux install, Linux Virtual Machine, and codeanywhere.com WORK!
---
* Write a C++ Challenger program which will exchange messages with the "Server" program.  The Server program will be run SECOND (after the Challenger), your Challenger program which will run FIRST must begin by doing the following:
    * Creating the message queue with:
        * key value determined by `ftok(".",'u')`
        * read and write permissions set for user/owner (setting read and write permissions for all users is acceptable as well)
    * declare a message buffer structure with the following data members
        * long integer for message type
        * 5 element character array to hold the message contents
    * enter a loop where messages will be exchanged with the "Server"
        * First: read a message using `msgrcv(...`
            * on the first time in the loop, read message of type 0 so that the 1st randomly generated message type can be received
            * on subsequent loop passes, read message of type appropriate to the next value in the hailstone sequence
            * if message of type 1 is received then break the loop and remove the queue
        * Second: Once a message is received then:
            * use the received message's message type to calculate the next hailstone sequence value
            * send a message with a message type which corresponds to the calculated next hailstone sequence value
                * *after sending the message, if the message had type 1 then break the loop and/or close the queue*
            * calculate the subsequent hailstone sequence value to know the message type value that should be received next
        * Once a message of type 1 has been sent or received by your Challenger program then it should close the queue
        
### The Hailstone Sequence begins with some positive whole number value and will eventually converge to 1!

* Algorithm for the Hailstone Sequence is given as follows:
    * if N is odd: ( N + 1 ) = 3 * N + 1
    * if N is even: ( N + 1 ) = N / 2
        * where N is the current number in the sequence and ( N + 1 ) is the next number in the sequence
* To test the attached executable files:
    1. download the appropriate 32-bit or 64-bit version of the executables to some directory on your system
    2. open two terminal windows side by side
    3. in one window run the Challenger program
    4. in the other window run the Server program 
    5. In rapid succession, data is exchanged between the Challenger and Server.
    Example output is shown below:
    ![output example](HailstoneSequenceQOutput.png)

### **You are to create the Challenger program.**
Ubuntu Linux compatible executable files are attached to this message so you can see exactly how the Challenger program you create should work.  (Add execute permissions to the attached executable files using the command `chmod u+x filename.out`)

**_32-bit and 64-bit UBUNTU LINUX COMPATIBLE executable files are attached to this message.  Your program should work identically to the Challenger executable file!_**

* NOTES:
    * If needed, the Challenger program or Server program can be forcibly terminated by using CTRL+C
    * forcibly terminating the Challenger and/or Server programs can cause the message queue to remain, compile Q_CLEANER.cpp into an executable and use it to remove the left over message queue.

_Read these instructions carefully and understand all information contained in this description._

* Also, to get started see:
    * [1 interacticeMsgQ_A](interactiveMsgQ_A.cpp)
    * [2 interactiveMsgQ_B](interactiveMsgQ_B.cpp)
