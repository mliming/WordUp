//
//  main.cpp
//  WordUpH
//
//  Created by Matthew Liming on 8/17/16.
//  Copyright (c) 2016 Matthew Liming. All rights reserved.
//

//Input: a ASCII text file.
//Output: a list of the words in the file and how many times they appear in the file.

#include <iostream>
#include "c_wordUpW.h"
#include "Chapter.h"

int main(int argc, const char * argv[]) {
    
    c_wordUp test;
    Chapter mainFil;
    
    char endpr[100] = {'q', '\0'};
    char filTit[100];
    
    while (strcmp(filTit, endpr) != 0) {
        cout << "Enter in name of text file or q to quit: ";
        cin >> filTit;
        cout << endl;
        if(strcmp(filTit, endpr) != 0) {
            mainFil.readFile(filTit);
            mainFil.printChapt();
        }
    }
    
    return 0;
}
