#include <iostream>     
#include <algorithm>    
#include <array>
#include <string>
#include <random>       
#include <chrono>
#include <vector>
#include <list>
#include "Header.h"
#include "Main.h"

int topCardNum;
int p1Score;
int p2Score;

void PrepareGame()
{
    std::string userInput;
    std::cout << " Type 'play' to play the game or 'rules' to see the rules first." << std::endl;
    std::cout << " What would you like to do: ";
    std::cin >> userInput;
    std::cout << "\n";

    while (userInput != "play" && userInput != "rules")
    {
        std::cout << " Please enter a valid input:" << std::endl;
        std::cin >> userInput;
        std::cout << "\n";
    }

    if (userInput == "play"){
        std::cout << " Starting Game......." << std::endl;
    }
    else{
        while (userInput != "play"){
            std::cout << " Which do you want to see first 'rules' or 'cards'." << std::endl;
            std::cout << " Type 'play' when you are ready to play ." << std::endl;
            std::cout << " What would you like to do: ";
            std::cin >> userInput;
            std::cout << "\n";
            if (userInput == "rules"){
                ShowBladeRules();
            }
            else if (userInput == "cards"){
                ShowCardTypes();
            }
            else{
                std::cout << " Please enter a valid input." << std::endl;
            }
        }
        std::cout << " Starting Game......." << std::endl;
    }
}

void CheckForSameScore( bool& sameScore)
{
    //check to see if both scores are equal
    if (p1Score == p2Score) {
        std::cout << " Player 1 top card: " << p1Score << std::endl;
        std::cout << " Player 2 top card: " << p2Score <<"\n" <<std::endl;
        std::cout << " Oh we the same score. We better draw again." << std::endl;
        std::cout << "----------------------------------------------------------------\n" << std::endl;
        topCardNum += 1;
    }
    else {
        sameScore = false;
    }
}

void AllTopCardsTied( bool& retflag){
    retflag = true;
    //if all 5 cards are tied then end the game with a tie
    if (topCardNum == 15) {
        std::cout << "The game ends in a tie." << std::endl;
        return;
    }
    //std::cout << "The game can now start." << std::endl;
    retflag = false;
}

void FlipTopCard(std::vector<std::string>& p1Deck, std::vector<std::string>& p2Deck){
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

        CheckForSameScore(sameScore);
    }
    CheckForSameScore(sameScore);
    AllTopCardsTied(retflag);
    if (retflag) return;
}

void VerifyCard(std::string& playerInput, int curPlayer)
{
    std::cout << " Player " << curPlayer << " has a lower score." << std::endl;
    std::cout << " Please enter a card Player " << curPlayer << ":";
    std::cin >> playerInput;
    std::cout << "--------------------------------------------------------\n" << std::endl;
}

void SearchPlayerHand(std::vector<std::string>& playerHand, std::string& playerInput, int curPlayer) {
    //check player input to see if the card in their hand
    while (std::find(playerHand.begin(), playerHand.begin() + playerHand.size(), "[" + playerInput + "]") == playerHand.begin() + playerHand.size()) {
        std::cout << " That card is not in your hand." << std::endl;
        std::cout << "\n";
        std::cout << " Please enter a new card Player " << curPlayer << ": ";
        std::cin >> playerInput;
        std::cout << "\n----------------------------------------------------------------" << std::endl;
    }
}
