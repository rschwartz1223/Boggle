//
//  Token.h
//  Boggle
//
//  Created by Robert Schwartz on 3/7/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#ifndef TOKEN_H
#define TOKEN_H

// a class that represents a letter on the board - used only in the Boggle letterMap member (not the grid)
// remember that no game board will utilize the same letter more than once on the grid
class Token
{
    friend class Boggle; // boggle needs to be a friend so it can access the row and column directly
private:
    char letter; // the letter that represents this token
    
public:
    Token(char _letter='a', int row = 0, int col = 0); // default constructor
    int row;
    int col;
    
    // int getRow();
    // int getCol();
    
};
#endif
