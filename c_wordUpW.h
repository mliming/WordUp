//
//  c_wordUpW.h
//  WordUpH
//
//  Created by Matthew Liming on 8/17/16.
//  Copyright (c) 2016 Matthew Liming. All rights reserved.
//
#pragma once
#include <iostream>
#include <string>

using namespace::std;

class c_wordUp {
    
private:
    c_wordUp * m_nextW;
    c_wordUp * m_head;
    c_wordUp * m_tail;
    int m_frequ;
    int m_WordLen;
    char m_word[50];
    
public:
    ~c_wordUp();
    c_wordUp();
    void setFreq(int a_Freq);
    void increFreq();
    int getFreq();
    void setWordW(char a_word[]);
    void setWord(char a_word[]);
    int getPosToIns(char a_word[]);
    char * getWord();
    void printL();
    
};