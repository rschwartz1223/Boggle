//
//  Boggle.cpp
//  Boggle
//
//  Created by Robert Schwartz on 3/5/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#include "Boggle.h"
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include "Dictionary.h"

using namespace std;

Boggle::Boggle(std::string board)
{
    // implementation goes here
    this->score = 0;
    this->dim = sqrt(board.length());
    int counter = 0;
    for(int i = 0; i < dim; i++)
    {
        this->grid.push_back({});
        for(int j = 0; j < dim; j++)
        {
            this->grid[i].push_back(board[counter]);
            this->letterMap.insert({board[counter], Token(board[counter], i, j)});
            counter++;
        }
    }
    // use the board string to initialize the grid member of the Boggle class.
}

int Boggle::getDim(){return this->dim;}

bool Boggle::isNeighbor(Token t1, Token t2)
{
    // implementation goes here
    
    //t1 and t2 have same col and row
    if(t1.row == t2.row && t1.col == t2.col)
        return false;
    
    // t1 is top left corner
    if(t1.row == 0 && t1.col == 0)
    {
        //t2 is to the right
        if(t2.row == 0 && t2.col == 1)
            return true;
        //t2 is below or down to the right
        else if(t2.row == 1 && (t2.col == 0 || t2.col == 1) )
            return true;
        else
            return false;
    }
    
    //t1 is top right corner
    else if(t1.row == 0 && t1.col == this->dim - 1)
    {
        //t2 is to the left
        if(t2.row == 0 && t2.col == t1.col - 1)
            return true;
        //t2 is below or down to the left
        else if(t2.row == 1 && (t2.col == t1.col || t2.col == t1.col - 1) )
            return true;
        else
            return false;
    }
    
    //t1 is in bottom left corner
    else if(t1.row == this->dim - 1 && t1.col == 0)
    {
        //t2 is to the right
        if(t2.row == t1.row && t2.col == 1)
            return true;
        //t2 is above or up to the right
        else if(t2.row == this->dim - 2 && (t2.col == t1.col || t2.col == 1) )
            return true;
        else
            return false;
    }
    
    //t1 is in bottom right corner
    else if(t1.row == this->dim - 1 && t1.col == this->dim - 1)
    {
        //t2 is to the left
        if(t2.row == t1.row && t2.col == t1.col - 1)
            return true;
        //t2 is above or up to the left
        else if(t2.row == this->dim - 2 && (t2.col == t1.col || t2.col == t1.col - 1) )
            return true;
        else
            return false;
    }
    
    //t1 is on top edge
    else if(t1.row == 0 && (t1.col > 0 || t1.col < this->dim - 1) )
    {
        //t2 is also on top edge
        if(t2.row == 0 && (t2.col == t1.col - 1 || t2.col == t1.col + 1) )
            return true;
        //t2 is below
        else if(t2.row == 1 && (t2.col == t1.col - 1 || t2.col == t1.col || t2.col == t1.col + 1) )
            return true;
        else
            return false;
    }
    
    //t1 is on bottom edge
    else if(t1.row == this->dim - 1 && (t1.col > 0 || t1.col < this->dim - 1) )
    {
        //t2 is also on bottom edge
        if(t2.row == this->dim - 1 && (t2.col == t1.col - 1 || t2.col == t1.col + 1) )
            return true;
        //t2 is above
        else if(t2.row == this->dim - 2 && (t2.col == t1.col - 1 || t2.col == t1.col || t2.col == t1.col + 1) )
            return true;
        else
            return false;
    }
    
    //t1 is on left edge
    else if(t1.col == 0 && (t1.row > 0 || t1.row < this->dim - 1) )
    {
        //t2 is also on left edge
        if(t2.col == 0 && (t2.row == t1.row - 1 || t2.row == t1.row + 1) )
            return true;
        //t2 is to the right
        else if(t2.col == 1 && (t2.row == t1.row - 1 || t2.row == t1.row || t2.row == t1.row + 1) )
            return true;
        else
            return false;
    }
    
    //t1 is on right edge
    else if(t1.col == this->dim - 1 && (t1.row > 0 || t1.row < this->dim - 1) )
    {
        //t2 is also on right edge
        if(t2.col == this->dim - 1 && (t2.row == t1.row - 1 || t2.row == t1.row + 1) )
            return true;
        //t2 is to the right
        else if(t2.col == this->dim - 2 && (t2.row == t1.row - 1 || t2.row == t1.row || t2.row == t1.row + 1) )
            return true;
        else
            return false;
    }
    
    //t1 is a non-edge piece
    else if( (t1.row > 0) && (t1.row < this->dim - 1) && (t1.col > 0) && (t1.col < this->dim - 1) )
    {
        //if t2 is above t1
        if( (t2.row == t1.row - 1) && (t2.col == t1.col - 1 || t2.col == t1.col || t2.col == t1.col + 1) )
            return true;
        //if t2 is below t1
        else if( (t2.row == t1.row + 1) && (t2.col == t1.col - 1 || t2.col == t1.col || t2.col == t1.col + 1) )
            return true;
        //if t2 is same row as t1
        else if( (t2.row == t1.row) && (t2.col == t1.col - 1 || t2.col == t1.col + 1) )
            return true;
        else
            return false;
    }
    
    return false;
}

void Boggle::printMe()
{
    // implementation goes here
    for(int i = 0; i < this->dim; i++)
    {
        std::cout << "\t\t\t";
        for(int j = 0; j < this->dim; j++)
        {
            std::cout << this->grid[i][j] << "\t";
        }
        std::cout << std::endl << std::endl;
    }
    std::cout << std::endl;
}

void Boggle::printInstructions(){
    cout << "\nA valid move consists of 3-7 letter words.\n";
    cout << "Words must be constructed from adjacent letters (left, right, up down, diagonal).\n";
    cout << "You MAY NOT use the same grid-position more than once." << endl;
    cout << "Type EXIT to end the game" << endl;
}

bool Boggle::isValidGuess(string wordGuess)
{
    // implementation goes here
    if(wordGuess.length() < 3 || wordGuess.length() > 7)
        return false;
    
    int c1 = 0;
    try
    {
        while(c1 < 7)
        {
            if(!isNeighbor(this->letterMap.at(wordGuess[c1]), this->letterMap.at(wordGuess[c1 + 1]) ) )
            {
                return false;
            }
            c1++;
            if(c1 >= wordGuess.length() - 1)
            {
                break;
            }
        }
    }
    catch(std::out_of_range)
    {
        std::cout << "out_of_range exception, key not found.\n";
    }
    return true;
}

bool Boggle::takeTurn(string word, Dictionary *d)
{
    // implementation goes here
    if(word == "EXIT")
    {
        std::cout << "Thank you for playing Boggle!\n";
        return false;
    }
    if(!isValidGuess(word))
    {
        std::cout << "Please enter a valid guess.\n";
        return false;
    }
    
    
    if(d->hasWord(word))
    {
        if(wordsFoundSoFar.find(word) == wordsFoundSoFar.end())
        {
            wordsFoundSoFar.insert(word);
            std::cout << "'" << word << "' is a valid guess AND is a word in the dictionary. Scores +1 point.\n";
            std::cout << "Your current score is " << ++score << ".\n";
            return false;
        }
        else
        {
            std::cout << "'" << word << "' has already been guessed. Scores 0 points.\n";
            return false;
        }
    }
    else
    {
        std::cout << "'" << word << "' is a valid guess but NOT a word in the dictionary. Scores 0 points.\n";
        return false;
    }
    
    return false; // game is not over
}
