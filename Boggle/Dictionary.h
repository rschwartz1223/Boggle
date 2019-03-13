//
//  Dictionary.h
//  Boggle
//
//  Created by Robert Schwartz on 3/6/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <set>
#include <string>

using namespace std;

class Dictionary{
    set<string> words; // a set of unique words
public:
    Dictionary(string fileName); // constructor that builds the dictionary based on a string filename
    void printMe(); // ability to print the dictionary (only for debug, not advised for large dictionary)
    bool hasWord(string word); // return true if the set has a requested word
};

#endif
