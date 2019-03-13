//
//  main.cpp
//  Boggle
//
//  Created by Robert Schwartz on 3/5/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#include <iostream>
#include "Boggle.h"
#include "Dictionary.h"

using namespace std;

int main()
{
    std::cout << "\n\t-------------------------------";
    std::cout << "\n\t\tLet's\tPlay\tBoggle!";
    std::cout << "\n\t-------------------------------\n\n";
    
    // "winmloraflbdepsi"  // this game string has duplicate letters.. out of scope for our default assignment
    // "winmloraftbdepsj" // this game string has no duplicates (normal)
    
    // implementation goes here
    
    Dictionary dict("Solution.txt");
//    dict.printMe();
    
    Boggle bog("winmloraftbdepsj");
    bog.printMe();

    bog.printInstructions();

    bool turn = false;
    std::string guess;

    while(!turn)
    {
        std::cout << "Enter guess: ";
        std::cin >> guess;
        if(guess == "EXIT")
            turn = true;
        bog.takeTurn(guess, &dict);
    }
    
}
