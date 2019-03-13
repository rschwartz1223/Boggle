//
//  Dictionary.cpp
//  Boggle
//
//  Created by Robert Schwartz on 3/6/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary(std::string fileName)
{   // constructor: given the fileName, open the file and build the set of words
    // implementation goes here
    std::string word;
    std::fstream file;
    file.open(fileName.c_str());
    while(file >> word)
    {
        words.insert(word);
    }
    file.flush();
}

void Dictionary::printMe()
{ // print the entire dictionary one word per line
    // implementation goes here
    for(auto const& it: words)
    {
        std::cout << it << std::endl;
    }
}

bool Dictionary::hasWord(std::string word){ // return true if the dictionary contains a specific word
    // implementation goes here
    for(auto const& it: words)
    {
        if(it == word) return true;
    }
    return false; // don't assume this is correct!
}
