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
    int sum = 0;
    int length = argc - 1;
    float aAvg = 0.0;
    
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
            sum = sum + atoi(argv[i+1]);
        }
        for (int j = 0; j < length; j++){
            if (atoi(argv[j+1]) > max){
                max = atoi(argv[j+1]);
            }
            else if(atoi(argv[j+1]) < min){
                min = atoi(argv[j+1]);
            }
        }
        aAvg = float(sum)/float(length);
        cout << "The sum is " << sum << endl;
        cout << "The average is " << aAvg << endl;
        int aRange = max - min;
        cout << "The range is " << aRange << endl;
    }
    exit( 0 );
    
}
