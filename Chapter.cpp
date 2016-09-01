//
//  Chapter.cpp
//  WordUpH
//
//  Created by Matthew Liming on 8/21/16.
//  Copyright (c) 2016 Matthew Liming. All rights reserved.
//
//Done sp/Gra

#include "Chapter.h"

Chapter::Chapter() {
    
    //charartecters that represent the end of a word
    m_excludedChars[0] = '.';
    m_excludedChars[1] = '!';
    m_excludedChars[2] = '?';
    m_excludedChars[3] = ':';
    m_excludedChars[4] = ';';
}

//Creates a c_wordUp object from a ASCII txt file input from the user
void Chapter::readFile(char a_filNam[]) {

    FILE * v_FileRd;
    int v_cnt = 0;
    size_t v_size = 1;
    size_t v_sizeT = 1;
    char v_ch[13];
    char v_word[50];

    strcpy(m_fileTitle, a_filNam);
    v_FileRd = fopen(m_fileTitle, "r");
    if (v_FileRd != NULL){
        while (!feof(v_FileRd)) {
            fread(&v_ch, v_size, v_sizeT, v_FileRd);
            if (chEndCh(v_ch[0]) &&  v_cnt > 0) {
                v_word[v_cnt] = '\0';
                wordList.setWordW(v_word);
                v_cnt = 0;
                clearWord(v_word);
            }
            else {
                if (checkValidChar(v_ch[0]) && v_ch[0] != feof(v_FileRd)) {
                    v_word[v_cnt] = tolower(v_ch[0]);
                    v_cnt = v_cnt + 1;
                }
            }
            
        }
        
        v_word[v_cnt - 1] = '\0';
        if (v_cnt > 0) {
            wordList.setWordW(v_word);
        }
        fclose(v_FileRd);
    }
}

//Returns true value if character is a valid value in the English alphabet; otherwise false
bool Chapter::checkValidChar(char a_ch) {
    
    bool val = false;
    
    if ((97 <= int(a_ch) && int(a_ch) <= 122) || (65 <= int(a_ch) && int(a_ch) <= 90)) {
        val = true;
    }
    
    return val;
}

//Checks if character indicates the end of a word
bool Chapter::chEndCh(char a_ch) {
    
    bool val = false;
    
    if (a_ch == ' ' || int(a_ch) == 9) {
        val = true;
    }
    if (a_ch == '\n' || a_ch == '\r') {
        val = true;
    }
    for (int i = 0; i < 5; i++) {
        if (a_ch == m_excludedChars[i]) {
            val = true;
        }
    }
    return val;
}

//Displays the information in the c_wordUp object (words and the number of times they appear in the file)
void Chapter::printChapt() {
    
    cout << "Word Count For: " << m_fileTitle << endl;
    wordList.printL();
}

//Clear word to default value
void Chapter::clearWord(char myWord[]) {
    
    for (int i = 0; i < 50; i++) {
        myWord[i] = 'N';
    }
}