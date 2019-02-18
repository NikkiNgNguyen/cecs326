//
//  main.cpp
//  Lab
//
//  Created by Nikki Nguyen on 2/18/19.
//  Copyright © 2019 cecs326. All rights reserved.
//

#include <iostream>
using namespace std;

int main( int argc, char ** argv ){
    int summation = 0;
    int length = argc - 1;
    float arrayAverage = 0.0;
    int max = atoi(argv[1]);
    int min = atoi(argv[1]);
    if(argc == 1){
        cout << "no arguments entered, I'm done \n" << endl;
    }
    if((1 < argc) && ( argc < 4)){
        cout << "Please enter more than 3 numerical arguments \n" << endl;
    }
    else{
        for (int i = 0; i < length; i++){
            cout << "numbersArray["<< i << "] = " << atoi(argv[i+1]) << endl;
            summation = summation + atoi(argv[i+1]);
        }
        for (int j = 0; j < length; j++){
            if (atoi(argv[j+1]) > max){
                max = atoi(argv[j+1]);
            }
            else if(atoi(argv[j+1]) < min){
                min = atoi(argv[j+1]);
            }
        }
        arrayAverage = float(summation)/float(length);
        cout << "The sum is " << summation << endl;
        cout << "The average is " << arrayAverage << endl;
        int arrayRange = max - min;
        cout << "The range is " << arrayRange << endl;
    }
    exit( 0 );
    
}
