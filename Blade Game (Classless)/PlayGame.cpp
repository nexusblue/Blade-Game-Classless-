#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include "Header.h"
#include "Main.h"

void startGame(const unsigned int& arraySize, std::string  bladeDeck[30], std::string  p1Deck[15], std::string  p2Deck[15], const unsigned int& handSize, std::string  p1Hand[10], std::string  p2Hand[10])
{
    std::string userInput;
    std::cout << "Type 'play' to play the game or 'rules' to see the rules first." << std::endl;
    std::cout << "What would you like to do: ";
    std::cin >> userInput;
    std::cout << "\n";

    while (userInput != "play" && userInput != "rules")
    {
        std::cout << "Please enter a valid input." << std::endl;
        std::cout << "What would you like to do: ";
        std::cin >> userInput;
        std::cout << "\n";
    }

    if (userInput == "play")
    {
        shuffleDeck(arraySize, bladeDeck);
        splitDeck(arraySize, bladeDeck, p1Deck, p2Deck);
        showHand(handSize, p1Hand, p1Deck, p2Hand, p2Deck);
    }
    else
    {
        while (userInput != "play")
        {
            std::cout << "Which do you want to see first 'rules' or 'cards'." << std::endl;
            std::cout << "Type 'play' when you are ready to play ." << std::endl;
            std::cout << "\n";
            std::cout << "What would you like to do: ";
            std::cin >> userInput;
            std::cout << "\n";
            if (userInput == "rules")
            {
                showBladeRules();
            }
            else if (userInput == "cards")
            {
                showCardTypes();
            }
            else
            {
                std::cout << "Please enter a valid input." << std::endl;
            }
        }
        shuffleDeck(arraySize, bladeDeck);
        splitDeck(arraySize, bladeDeck, p1Deck, p2Deck);
        showHand(handSize, p1Hand, p1Deck, p2Hand, p2Deck);

    }
}

void checkForSameScore(unsigned int& p1Score, unsigned int& p2Score, unsigned int& topCardNum, bool& sameScore)
{
    //check to see if both scores are equal
    if (p1Score == p2Score) {
        std::cout << "Oh same score. We better must draw again." << std::endl;
        topCardNum += 1;
    }
    else {
        sameScore = false;
    }
}

void allTopCardsTied(unsigned int& topCardNum, bool& retflag)
{
    retflag = true;
    //if all 5 cards are tied then end the game with a tie
    if (topCardNum == 15) {
        std::cout << "The game ends in a tie." << std::endl;
        return;
    }
    std::cout << "The game can now start." << std::endl;
    retflag = false;
}

void FlipTopCard(std::string  p1Deck[15], unsigned int& topCardNum, std::string  p2Deck[15], unsigned int& p1Score, unsigned int& p2Score)
{
    bool sameScore = true;
    bool retflag;
    //run loop until no cards can be drawn or until the players scores are different
    while (sameScore && topCardNum < 15)
    {
        std::cout << "\n";
        std::cout << p1Deck[topCardNum][1] << std::endl;
        std::cout << p2Deck[topCardNum][1] << std::endl;
        std::cout << "\n";
        //set special card values to 1 and set all other numbers that value (player 1/2)
        //then set the score
        if (p1Deck[topCardNum][1] == 'B' || p1Deck[topCardNum][1] == 'M') {
            p1Score = 1;
        }
        else {
            p1Score = (p1Deck[topCardNum][1] - '0');
        }
        if (p2Deck[topCardNum][1] == 'B' || p2Deck[topCardNum][1] == 'M') {
            p2Score = 1;
        }
        else {
            p2Score = (p2Deck[topCardNum][1] - '0');
        }

        checkForSameScore(p1Score, p2Score, topCardNum, sameScore);
    }

    allTopCardsTied(topCardNum, retflag);
    if (retflag) return;
}