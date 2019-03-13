//
//  Boggle.h
//  Boggle
//
//  Created by Robert Schwartz on 3/5/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#ifndef BOGGLE_H
#define BOGGLE_H

#include <string>
#include <vector>
#include <set>
#include <map>
#include "Dictionary.h"
#include "Token.h"

using namespace std;

class Boggle
{
    
private:
    int dim; // dimension of game board; computed by the constructor based on the sqrt(boardString.size())
    vector< vector <char > > grid; // grid of characters; same as Maze and Tic Tac Toe
    map<char, Token> letterMap; // map of characters (key) with their Token (value)
    set<string> wordsFoundSoFar; // number of valid words found so far in the dictionary based on player guesses
    int totalWords; // BONUS: number of total words in the dictionary that represent a valid guess on the grid
    
public:
    int score;
    Boggle(std::string boardString); // initialize the game grid with a given string that will fit a square grid;
    int getDim();
    // also init dimension and letterMap
    void printMe(); // print the grid
    bool isValidGuess(string wordGuess);// true if the wordGuess is valid: 3 >= size() <= 7,
    // and all successive letters are neightbors
    void printInstructions(); // print instructions for the game (provided for you)
    bool isNeighbor(Token t1, Token t2); // return true if t1 is a neighbor of t2 (exactly 1 square away on the grid)
    bool takeTurn(string wordGuess, Dictionary *d); // process a player guess by checking its validity
    // and then seeing if it is in the dictionary POINTED to by d
    
    void solve(Dictionary *d); // BONUS
    
};

#endif
