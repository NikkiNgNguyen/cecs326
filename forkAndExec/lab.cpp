#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

 int main(){
  pid_t pid1, pid2, pid3, pid4;
  pid1 = fork();
  if( pid1 < 0 ){
    cout << "ERROR: Fork failed!\n";
    exit(1);
  }
  else if ( pid1 == 0 ){
    pid2 = fork();
    if( pid2 < 0 ){
      cout << "ERROR: Fork failed!\n";
      exit(1);
    }
    else if ( pid2 == 0 ){
      cout << "CHILD1: about fork and show a long list of directory contents: \n";
      //cout << pid2 << endl;
      if(execlp("ls","ls","-l",NULL) == -1){
        cout << "ERROR: exec failed!\n";
        exit ( 1 );
      }
    }
    else{
      wait( &pid2 );
    }
    pid3 = fork();
    if( pid3 < 0 ){
      cout << "ERROR: Fork failed!\n";
      exit(1);
    }
    else if( pid3 == 0 ){
      cout << "CHILD1: about fork and show hello.cpp contents:\n";
      if(execlp("more","more", "hello.cpp", NULL) == -1){
        cout << "ERROR: exec failed!\n";
        exit ( 1 );
      }
    }
    else{
      wait( &pid3 );
    }
    pid4 = fork();
    if( pid4 < 0 ){
      cout << "ERROR: Fork failed!\n";
      exit(1);
    }
    else if( pid4 == 0 ){
      if(execlp("g++","g++", "hello.cpp", "-o", "hello.out", NULL) == -1){
        cout << "ERROR: exec failed\n";
        exit ( 1 );
      }
    }
    else{
      wait( &pid4 );
    }
    cout << "CHILD1: about fork and compile hello.cpp:\n";
    cout << "CHILD1: doing ./hello.out 2\n";
    if(execlp("./hello.out", "./hello.out", "2", NULL) == -1){
      cout << "ERROR: exec failed\n";
      exit ( 1 );
    }
  }
  else{
    cout << "\nPARENT: Waiting for child to exit...\n";
    wait( &pid1 );
    cout << "\nPARENT: Child finally exited\n";
  }
  exit(0);
}
