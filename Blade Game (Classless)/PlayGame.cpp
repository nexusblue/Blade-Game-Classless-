#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include "Header.h"
#include "Main.h"


void StartGame(const unsigned int& arraySize, std::string  bladeDeck[30], std::vector<std::string>& p1Deck, std::vector<std::string>& p2Deck, std::vector<std::string>& p1Hand, const unsigned int& handSize, std::vector<std::string>& p2Hand)
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
        ShuffleDeck(arraySize, bladeDeck);
        SplitDeck(arraySize, p1Deck, bladeDeck, p2Deck);
        ShowHand(p1Hand, p1Deck, handSize, p2Hand, p2Deck);
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
                ShowBladeRules();
            }
            else if (userInput == "cards")
            {
                ShowCardTypes();
            }
            else
            {
                std::cout << "Please enter a valid input." << std::endl;
            }
        }
        ShuffleDeck(arraySize, bladeDeck);
        SplitDeck(arraySize, p1Deck, bladeDeck, p2Deck);
        ShowHand(p1Hand, p1Deck, handSize, p2Hand, p2Deck);
    }
}

void CheckForSameScore(unsigned int& p1Score, unsigned int& p2Score, unsigned int& topCardNum, bool& sameScore)
{
    //check to see if both scores are equal
    if (p1Score == p2Score) {
        std::cout << "Player 1 top card: " << p1Score << std::endl;
        std::cout << "Player 2 top card: " << p2Score << std::endl;
        std::cout << "\n";
        std::cout << "Oh same score. We better must draw again." << std::endl;
        std::cout << "----------------------------------------------------------------" << std::endl;

        std::cout << "\n";

        topCardNum += 1;
    }
    else {
        sameScore = false;
    }
}

void AllTopCardsTied(unsigned int& topCardNum, bool& retflag)
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

void FlipTopCard(unsigned int& topCardNum, std::vector<std::string>& p1Deck, unsigned int& p1Score, std::vector<std::string>& p2Deck, unsigned int& p2Score)
{
    bool sameScore = true;
    bool retflag;
    //run loop until no cards can be drawn or until the players scores are different
    while (sameScore && topCardNum < 15)
    {
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

        CheckForSameScore(p1Score, p2Score, topCardNum, sameScore);
    }
    std::cout << "Player 1 top card: " << p1Deck[topCardNum][1] << std::endl;
    std::cout << "Player 2 top card: " << p2Deck[topCardNum][1] << std::endl;
    std::cout << "\n";

    AllTopCardsTied(topCardNum, retflag);
    if (retflag) return;
}

