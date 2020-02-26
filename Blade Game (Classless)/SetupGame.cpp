#include <iostream>     
#include <algorithm>    
#include <array>        
#include <random>       
#include <chrono>       
#include <vector>
#include <string>
#include "Header.h"
#include "Main.h"

extern int topCardNum;
extern int p1Score;
extern int p2Score;

void ShuffleDeck( std::string* bladeDeck) {
    //shuffle the blade deck to randomize the order
    unsigned seed = rand() % 100;
    std::shuffle(bladeDeck, bladeDeck + 30, std::default_random_engine(seed));
    std::cout << " Shuffling Blade Deck......." << std::endl;
}

void SplitDeck(std::string  bladeDeck[30],std::vector<std::string>& p1Deck, std::vector<std::string>& p2Deck){

    //sort and show playerdeck
    for (size_t i = 0; i < 30; i++) {
        //create player's 1 pile with the first 15 cards
        if (i < 15) {
            p1Deck[i] = bladeDeck[i];
        }
        //create player's 2 pile with the last 15 cards
        else {
            p2Deck[i - 15] = bladeDeck[i];
        }
    }
    std::cout << " Spliting Blade Deck in half......." << std::endl;
}

void DealHands(std::vector<std::string>& p1Hand, std::vector<std::string>& p1Deck, std::vector<std::string>& p2Hand, std::vector<std::string>& p2Deck) {
    //Deal cards from the deck btw the 2 players
    for (size_t i = 0; i < p1Hand.size(); i++){
        p1Hand[i] = p1Deck[i];
    }
    for (size_t i = 0; i < p2Hand.size(); i++){
        p2Hand[i] = p2Deck[i];
    }
    std::cout << " Dealing 10 cards to players......." << std::endl;
    std::cout << "===========================================================================\n" << std::endl;
}

void DisplayHands(std::vector<std::string>& p1Hand, std::vector<std::string>& p2Hand)
{
    //sort the cards in order from lowest to highest
    std::sort(p1Hand.begin(), p1Hand.begin() + p1Hand.size());
    std::sort(p2Hand.begin(), p2Hand.begin() + p2Hand.size());

    //display the hand for player 1
    std::cout << " Player 1's hand:";
    for (size_t i = 0; i < p1Hand.size(); i++){
        std::cout << p1Hand[i] << " ";
    }
    std::cout << "\n\n";
    //display the hand for player 2
    std::cout << " Player 2's hand:";
    for (size_t i = 0; i < p2Hand.size(); i++){
        std::cout << p2Hand[i] << " ";
    }
    std::cout << "\n";
}

void DisplayScore() {
    std::cout << "\n Player 1's current score is: " << p1Score << std::endl;
    std::cout << " Player 2's current score is: " << p2Score << "\n" << std::endl;
}