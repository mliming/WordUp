//
//  Chapter.h
//  WordUpH
//
//  Created by Matthew Liming on 8/21/16.
//  Copyright (c) 2016 Matthew Liming. All rights reserved.
//

#ifndef __WordUpH__Chapter__
#define __WordUpH__Chapter__

#include <stdio.h>
#include "c_wordUpW.h"
class Chapter {

private:
    char m_excludedChars[5];
    char m_fileTitle[100];
    c_wordUp wordList;

public:
    Chapter();
    void readFile(char a_filNam[]);
    void printChapt();
    void clearWord(char myWord[]);
    bool checkValidChar(char a_ch);
    bool chEndCh(char a_ch);
    
};
//void Chapter::readFile(char [] fileN)
#endif /* defined(__WordUpH__Chapter__) */
