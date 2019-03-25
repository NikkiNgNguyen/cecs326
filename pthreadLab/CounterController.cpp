#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <time.h>
using namespace std;
int value = 10;
char input;
bool counter = true; //counter enabled
bool direction = true; // direction up
int speed_status = 0;
float speed = 0.125;
void *inputReader( void *param );
void *countDownThread( void *param );
bool flag = true;

int main( int argc, char ** argv){

  pthread_t tid_reader, tid_evenChecker, tid_countDownThread;
	pthread_attr_t attr;
	pthread_attr_init( &attr );

	pthread_create( &tid_reader, &attr, inputReader, NULL );	// create the thread
	pthread_create( &tid_countDownThread, &attr, countDownThread, NULL );	// create the thread
	cout << "Main thread blocking until worker threads finish\n";
	pthread_join( tid_reader, NULL );
	pthread_join( tid_countDownThread, NULL );
	cout << "Main thread unblocked and outta here\n";
}
void *inputReader( void *param ){
  cout << "!!! Reader Thread Running!\n";
	value = 10;	// change value to make countDownThread unblock and begin counting

  cout << "Enter a command:\n+: increase speed count\n-: decrease speed count\ns: switch setting\nd: direction setting\na: quit\n";

  cout << "count value: " << value << endl;
  cout << "current count speed: " << speed << endl;
  cout << "current counter: ENABLED" << endl;
  cout << "current direction: UP" << endl;
  while(input != 'a'){
    cin >> input;
    if(!((input=='+') ||(input =='-') || (input == 's') || (input == 'd') || (input == 'a'))){
      cin.clear();
      cin.ignore();
    }
    if(input == '-'){
      if(speed == 1){ //if in setting 0, stay at 0
        speed = 1;
      }
      else {
        speed = speed * 2;
      }

      cout << "current count speed: " << speed << endl;
    }
    else if(input == '+'){
      if(speed == 0.125){
        speed = 0.125;
      }
      else{
        speed = speed/2;
      }

      cout << "current count speed: " << speed << endl;
    }
    if(input == 's'){ //switch counter
      counter = !counter;
      if(!counter){
        cout << "current counter: DISABLED" << endl;
      }else{
        cout << "current counter: ENABLED" << endl;
      }

    }
    if (input == 'd'){
      direction = !direction;
      if(!direction){
        cout << "current direction: DOWN" << endl;
      }
      else{
        cout << "current direction: UP" << endl;
      }
    }
    if(input == 'a'){
      flag = false;
      cout << "inputReader thread exited\n";
    	pthread_exit( 0 );
    }
  }
  return 0;

}

void *countDownThread( void *param ){
	cout << "!!! Count Down Thread Running!\n";
	struct timespec timing;
  timing.tv_sec = 0;
	while( flag != false){
		// sleep( 1 );							// wait 1 second
    if(speed == .125){
    	timing.tv_nsec = 125000000L;
      nanosleep( &timing, NULL );
    }
    else if(speed == .25){
    	timing.tv_nsec = 250000000L;
      nanosleep( &timing, NULL );
    }
    else if(speed == .5){
    	timing.tv_nsec = 500000000L;
      nanosleep( &timing, NULL );
    }
    else if(speed == 1){
      sleep (1);
      nanosleep( &timing, NULL );
    }
    if (!counter){
      cin.get();
    }
    else{
      if(!direction){
        cout << --value << flush;
        while(value == 0){
          value = 99;
        }
      }
      else{
        cout << ++value << flush;
        while(value == 99){
          value = 0;
        }
      }
      /*while(input != 'a'){
        if(!direction){

          cout << --value << flush;
        }else{

        cout << ++value << flush;	// flush to make the value display
        }


    }*/
  }
    if(input == 'a'){
      cout << "countDownThread thread exited\n";
    	pthread_exit( 0 );
    }

		cout << "\r                       \r";	// overwrite previous number with spaces
		cout << "\b\b\b\b\b\b       \b\b\b\b\b\b";	// overwrite previous number with spaces
		cout << "\b\b\b\b\b\b";	// backspace over previously  displayed characters
	}
	//cout << "countDownThread thread exited\n";
	//pthread_exit( 0 );
  return 0;
}
