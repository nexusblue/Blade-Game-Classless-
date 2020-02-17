#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include "Header.h"

void ShuffleDeck(const unsigned int arraySize, std::string* bladeDeck) {
    //shuffle the blade deck to randomize the order
    unsigned seed = rand() % 100;
    std::shuffle(bladeDeck, bladeDeck + arraySize, std::default_random_engine(seed));
}

void SplitDeck(const unsigned int& arraySize, std::vector<std::string>& p1Deck, std::string  bladeDeck[30], std::vector<std::string>& p2Deck){

    //sort and show playerdeck
    for (size_t i = 0; i < arraySize; i++) {
        //create player's 1 pile with the first 15 cards
        if (i < 15) {
            p1Deck[i] = bladeDeck[i];
        }
        //create player's 2 pile with the last 15 cards
        else {
            p2Deck[i - 15] = bladeDeck[i];
        }
    }
    std::cout << "\n";
}

void ShowHand(std::vector<std::string>& p1Hand, std::vector<std::string>& p1Deck, const unsigned int& handSize, std::vector<std::string>& p2Hand, std::vector<std::string>& p2Deck)
{
    //get the starting cards from player 1's deck pile
    for (size_t i = 0; i < (10); i++)
    {
        p1Hand[i] = p1Deck[i];
    }

    //get the starting cards from player 2's deck pile
    for (size_t i = 0; i < (handSize); i++)
    {
        p2Hand[i] = p2Deck[i];
    }

    //sort the cards in order from lowest to highest
    std::sort(p1Hand.begin(), p1Hand.begin() + handSize);
    std::sort(p2Hand.begin(), p2Hand.begin() + handSize);

    //display the hand for player 1
    std::cout << "Player 1's hand:" << std::endl;
    for (unsigned i = 0; i < 10; i++)
    {
        std::cout << p1Hand[i] << " ";
    }
    std::cout << "\n";
    std::cout << "\n";


    //display the hand for player 2
    std::cout << "Player 2's hand:" << std::endl;
    for (size_t i = 0; i < (10); i++)
    {
        std::cout << p2Hand[i] << " ";
    }
    std::cout << "\n";
}
