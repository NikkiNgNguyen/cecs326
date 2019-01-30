####NOTE: NASM based labs cannot be done using Windows Linux Subsystem (UOW) or Cygwin

1. Enter your Linux environment and open the Terminal application

2. Install NASM with command

sudo apt-get install nasm

3. Change Directory into some directory where you would like to do work for this lab development

4. Download the hello world program, use the following command:


wget http://web.csulb.edu/~000059460/326Asm/hello.asm

5. Compile the NASM hello world with the following command:


nasm -f elf hello.asm


(If compilation is successful then object file hello.o will be created)

6. Use the linker to create an executable via the following command:


ld -m elf_i386 -s -o hello.out hello.o

(If linking is successful then an executable named hello.out will be created)

7. Run the executable by using the following command:

./hello.out

8. Observe the results, also take a little time to familiarize yourself with the commands that were used to create/run the executable in stesp 5, 6, and 7.

9. Modify the program to output your name and student ID in the following fashion:


First: Homer
Last: Simpson
ID: 11223344

The sample output shown above is for a student named Homer Simpson with a student ID 11223344. Use your information instead.
