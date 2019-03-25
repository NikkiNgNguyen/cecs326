# Pthread Counter Controller
Counter increments and decrements whole numbers in 2 digits of resolution.  The count value is displayed in standard output by one thread while another thread can read user input.  User input is provided, to change count speed, change count direction, pause/resume counting, and terminate the program.  Details regarding program operation and settings are given as follows:

* default settings (when program is first launched):
  * count value initialized to 10
  * count speed is 0.125 seconds
  * counter is enabled
  * count direction is up
* User can type a single key and press enter to issue a command to the Counter Controller program.
  * commands received by input reader, each command symbol is an ascii character (shown in bold):
    * **+**: count speed increase
    * **-**: count speed decrease
      * 4 different count speed settings
        * 0 -> 1 second
        * 1 -> 0.5 second
        * 2 -> 0.25 seconds
        * 3 -> 0.125 seconds
        * NOTE: if speed is in setting 3 and '+' is received then stay in setting 3, if speed is in setting 0 and '-' is received then stay in setting 0
      * **s**: disable/enable counting (disable means paused, enabled means resumed i.e. counting up at specified speed
      * **d**: change counting direction (up or down)
      * **a**: abort counting and exit
      * ignore invalid commands _(invalid commands should have no effect!)_

Executable file which demonstrates proper functionality is attached to this message.  Run, test, and experiment with the executable to understand how your program should work.

_Advice and Hints:_

* You must use pthreads but you are free to use any type of program logic to complete this lab but the following information may assist you in getting started
* For starter code, you can use: [3_ThreadInteractiveExample_UpdatableCounter](3_ThreadInteractiveExample_UpdatableCounter.cpp)
* Have variables to hold program state information:
  * an int to hold the count value
  * a char to receive user input
  * an integral type to hold the count speed setting
  * a bool to hold the disable/enable status
  * a bool to hold the counting direction status
* In the input reader thread:
  * read the user input and update a state variable depending on what input character was provided by the user
* In the counting thread:
  * in one set of conditional statements, check the speed setting and assign proper values to the timespec structure member variables
  * after the previous set of conditional statements have run to update the speed then if counting is enabled, check the direction to increment or decrement the counting value and do a nanosleep
  * finally output the count value and
* The reader and counter threads should both exit if the user inputs an 'a'
