# Create a NASM program which will output a list of Celsius Temperatures to a text file:

* The program will receive 2 command line arguments:
* The first argument is a Fahrenheit temperature provided in HEX
* The second argument is the number of Celsius temperature values to write to the text file the text file will be named after your student ID, the text file will have read and write priveleges for the owner
* The conversion formula is: **Celsius = 5 * ( Fahrenheit - 32 ) / 9**

See the examples covered in class for reference:

* Creating a text file from a NASM program: WritingToFile
* Looping example covered in class
* Usage of multiplication and division to convert from Celsius to Fahrenheit
* No information needs to be written to standard output.  The print char macro can be modified so data is written into the text file instead of standard output
---
For example:

Student with ID 11223344 launching the program with command ./a.out 0x40 0x3 would the following data would be written to the output file:
```
0x40 to Celsius is 0x11

0x45 to Celsius is 0x14 

0x4A to Celsius is 0x17
```
* Explanation:
    * 0x40 is the first Fahrenheit temperature which will be converted to Celsius the first Fahrenheit temperature is incremented by 5 for each subsequent conversion to Celsius
    * 0x03 specifies that three conversions will take place (i.e. the text file that is created will have 3 Celsius Temperatures)
    * the text file will be named 11223344.txt, set the file permissions as:
        * owner/user can read and write
        * group owner can only read
        * others can only read
