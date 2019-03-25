// EXAMPLE         top
// The program below creates a thread and then cancels it.  The main
// thread joins with the canceled thread to check that its exit status
// was PTHREAD_CANCELED.  The following shell session shows what happens
// when we run the program:

// $ ./a.out
// thread_func(): started; cancellation disabled
// main(): sending cancellation request
// thread_func(): about to enable cancellation
// main(): thread was canceled

// Program source

#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
using namespace std;
#define handle_error_en(en, msg) \
do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

static void *thread_func( void *ignored_argument ){
	struct timespec timing;
	int s;

	/* Disable cancellation for a while, so that we don't
	immediately react to a cancellation request */
	s = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL );
	if (s != 0 )	handle_error_en( s, "pthread_setcancelstate" );

	cout << "thread_func(): started; cancellation disabled\n";
	timing.tv_sec = 5;
	timing.tv_nsec = 0;
	nanosleep( &timing, NULL );
	cout << "thread_func(): about to enable cancellation\n";

	s = pthread_setcancelstate( PTHREAD_CANCEL_ENABLE, NULL );
	if (s != 0 )	handle_error_en(s, "pthread_setcancelstate");

	/* nanosleep() is a cancellation point */
	// cout << "zzzZZZzz\n";
	timing.tv_sec = 1000;
	nanosleep( &timing, NULL );

	/* Should never get here */
	cout << "thread_func(): not canceled!\n";
	return NULL;
}

int main(void){
	pthread_t tid;
	struct timespec timing;
	void *res;
	int s;

	/* Start a thread and then send it a cancellation request */

	s = pthread_create( &tid, NULL, &thread_func, NULL );
	if ( s != 0 )	handle_error_en( s, "pthread_create" );

	/* Give thread 2 seconds to get started */
	timing.tv_sec = 2;
	timing.tv_nsec = 0;
	nanosleep( &timing, NULL );

	cout << "main(): sending cancellation request\n";
	s = pthread_cancel( tid );
	if ( s != 0 )	handle_error_en( s, "pthread_cancel" );

	/* Join with thread to see what its exit status was */
	timing.tv_sec = 2;
	nanosleep( &timing, NULL );
	s = pthread_join( tid, &res );
	if ( s != 0 )	handle_error_en( s, "pthread_join" );

	if ( res == PTHREAD_CANCELED )	cout << "main(): thread was canceled\n";
	else	cout << "main(): thread wasn't canceled (shouldn't happen!)\n";
	cout << "Bye!\n\n";
	exit( EXIT_SUCCESS );
}