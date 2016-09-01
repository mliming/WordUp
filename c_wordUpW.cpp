//
//  c_wordUpW.cpp
//  WordUpH
//
//  Created by Matthew Liming on 8/17/16.
//  Copyright (c) 2016 Matthew Liming. All rights reserved.
//Done sp/Gra

#include "c_wordUpW.h"

c_wordUp::c_wordUp() {
    
    m_frequ = 1;
    m_head = NULL;
    m_nextW = NULL;
    m_tail = NULL;
}

c_wordUp::~c_wordUp() {
    
    c_wordUp * m_del;
    
    m_tail = m_head;
    while (m_tail != NULL) {
        m_del = m_tail;
        m_tail = m_del->m_nextW;
        delete m_del;
    }
    m_del = NULL;
    m_head = NULL;
}

//Set frequency of word in list
void c_wordUp::setFreq(int a_Freq) {
    
    m_frequ = a_Freq;
}

//Increase frequency of word in list by one
void c_wordUp::increFreq() {
    
    m_frequ = m_frequ + 1;
}

//Return frequency of word in list
int c_wordUp::getFreq() {
    
    return m_frequ;
}

//Adds word to list or increases frequency by one if already in list
void c_wordUp::setWordW(char a_word[]) {
    
    c_wordUp * nxtW = new c_wordUp();
    c_wordUp * curpt;
    c_wordUp * prevpt;
    long wrdle;
    int pos = 0;
    int curpos = 0;
    
    wrdle = strlen(a_word);
    nxtW->setWord(a_word);
    
    
    if (m_head == NULL) {
        m_head = nxtW;
        m_tail = nxtW;
        nxtW->m_nextW = NULL;
    }
    else {
        prevpt = m_head;
        curpt = m_head->m_nextW;
        pos = getPosToIns(a_word);
        while (curpos < pos && curpt != NULL) {
            prevpt = prevpt->m_nextW;
            curpt = curpt->m_nextW;
            curpos += 1;
        }
        if (pos == -1) {
            nxtW->m_nextW = m_head;
            m_head = nxtW;
        }
        if (curpt == NULL && pos >= 0) {
            m_tail->m_nextW = nxtW;
            m_tail = nxtW;
        }
        if (curpt != NULL && pos >= 0) {
            prevpt->m_nextW = nxtW;
            nxtW->m_nextW = curpt;
        }
    }
}

//Copies the word to the m_word variable for a particular node
void c_wordUp::setWord(char a_word[]) {
    
    strcpy(m_word, a_word);
}

//Returns the position of where the word goes in the list
int c_wordUp::getPosToIns(char a_word[]){
    
    c_wordUp * curpt;
    int decval;
    int retpos = 0;
    bool done = false;
    char * curW;
    
    curpt = m_head;
    
    while (curpt != NULL && !done) {
        curW = curpt->getWord();
        decval = strcmp(a_word, curW);
        if (decval > 0 && strlen(curW) == strlen(a_word)) {
            retpos += 1;
        }
        if (decval < 0 && strlen(curW) == strlen(a_word)) {
            retpos -= 1;
            done = true;
        }
        if (strlen(curW) < strlen(a_word)) {
            retpos += 1;
        }
        if (strlen(curW) > strlen(a_word)) {
            retpos -= 1;
            done = true;
        }
        if (decval == 0) {
            curpt->increFreq();
            done = true;
            retpos = -2;
        }
        curpt = curpt->m_nextW;
    }
    return retpos;
}

//Returns word for a particular node
char * c_wordUp::getWord() {
    
    return m_word;
}

//Prints contents of list
void c_wordUp::printL() {
    
    c_wordUp * curpt;
    char * curWrd;
    long strLenOfW;
    long curStrLen = 0;
    int freq;
    
    curpt = m_head;
    if (curpt != NULL) {
        curWrd = curpt->getWord();
        curStrLen = strlen(curWrd);
        strLenOfW = curStrLen;
        freq = curpt->getFreq();
        cout << "Word of Lenght: " << curStrLen << endl << endl;
        cout << curWrd << ": " << freq << endl;
    }
    curpt = curpt->m_nextW;
    while (curpt != NULL) {
        curWrd = curpt->getWord();
        strLenOfW = strlen(curWrd);
        if (strLenOfW != curStrLen) {
            cout << endl << "Word of Lenght: " << strLenOfW << endl << endl;
            curStrLen = strLenOfW;
        }
        cout << curWrd << ": " << curpt->getFreq() << endl;
        curpt = curpt->m_nextW;
    }
}