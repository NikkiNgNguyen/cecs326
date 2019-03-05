#include <sys/types.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;

int main(){
  string write_msg, msg_read, write_operand;
  const short MSG_SIZE = 25;
  char msg_write[ MSG_SIZE ];
  char read_msg[ MSG_SIZE ];
  int fd[2];
  pid_t pid;
  string operation[3];
  pipe( fd ); //create pipe
  pid = fork(); //fork, req #1
  if (pid > 0){ //in parent
    close ( fd[0] ); //close unused Read End
    for ( int i = 0; i < 3; i++ ){
      cout << "PARENT: Enter a message to send: \n";
      cin >> write_msg;
      cout << "PARENT, sending: " << write_msg << "\n" << endl;
      unsigned int size = write_msg.length();
      write_msg.copy( msg_write, write_msg.length(), 0 );
      write( fd[1], msg_write, MSG_SIZE );
			for( int i = 0; i < MSG_SIZE; i++ )
				msg_write[ i ] = '\0';	// overwrite the message local array
			//write( fd[1], msg_write, MSG_SIZE );	// overwrite the shared memory area
    }
    close( fd[1] ); //all done, close the pipe
    cout << "PARENT: exiting!\n" << endl;
  }
  else{
    close( fd[1] ); //close unused write end
    for ( int j = 0; j < 3; j++ ){
      read( fd[0], read_msg, MSG_SIZE );
      msg_read = read_msg;
      operation[j] = msg_read;
      if ( j == 0 ){
        cout << "CHILD: value A: " << stoi(msg_read) << "\n" << endl;
        if ( (stoi(msg_read) <= 0) || (stoi(msg_read) >= 100)){
        cout << "Operator out of bounds \n" << endl;
        close ( fd[0] );
        exit( 0 );
      }
    }

      else if (j == 1){
        if ((msg_read != "+") && (msg_read != "-")){
          cout << "CHILD: operation invalid!\n" << endl;
          close ( fd[0] );
          exit( 0 );
        }
        else{
          if (msg_read == "+"){
            cout << "CHILD: operation addition\n" << endl;
          }
          else if (msg_read == "-"){
            cout << "CHILD: operation subtraction\n" << endl;
          }
      }
    }

    else if ( j == 2 ){
      cout << "CHILD: value B: " << stoi(msg_read) << "\n" << endl;
      if ((stoi(msg_read) <= 0) || (stoi(msg_read) >= 100)){
      cout << "Operator out of bounds \n" << endl;
      close ( fd[0] );
      exit( 0 );
    }
  }
}

  if(operation[1] == "+"){
    int adding = stoi(operation[0]) + stoi(operation[2]);
    cout << operation[0] << " " << operation[1] << " " << operation[2] << " = " << adding << endl;
  }
  else if (operation[1] == "-"){
    int subtracting = stoi(operation[0]) - stoi(operation[2]);
    cout << operation[0] << " " << operation[1] << " " << operation[2] << " = " << subtracting << endl;
  }
    cout << "CHILD: exiting!\n" << endl;
    close( fd[0] ); //all done, close the pipe!
  }
  exit( 0 );
}
