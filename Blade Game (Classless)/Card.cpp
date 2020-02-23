#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <vector>
#include <string>
#include "Header.h"
#include "Main.h"


void ShuffleDeck( std::string* bladeDeck) {
    //shuffle the blade deck to randomize the order
    unsigned seed = rand() % 100;
    std::shuffle(bladeDeck, bladeDeck + 30, std::default_random_engine(seed));
}

void SplitDeck(std::vector<std::string>& p1Deck, std::string  bladeDeck[30], std::vector<std::string>& p2Deck){

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
    std::cout << "\n";
}

void DealHands(std::vector<std::string>& p1Hand, std::vector<std::string>& p1Deck, std::vector<std::string>& p2Hand, std::vector<std::string>& p2Deck) {
    //get the starting cards from player 1's deck pile
    for (size_t i = 0; i < p1Hand.size(); i++){
        p1Hand[i] = p1Deck[i];
    }

    //get the starting cards from player 2's deck pile
    for (size_t i = 0; i < p2Hand.size(); i++){
        p2Hand[i] = p2Deck[i];
    }
}

void DisplayHands(std::vector<std::string>& p1Hand, std::vector<std::string>& p2Hand)
{
    //sort the cards in order from lowest to highest
    std::sort(p1Hand.begin(), p1Hand.begin() + p1Hand.size());
    std::sort(p2Hand.begin(), p2Hand.begin() + p2Hand.size());

    //display the hand for player 1
    std::cout << "Player 1's hand:" << std::endl;
    for (size_t i = 0; i < p1Hand.size(); i++){
        std::cout << p1Hand[i] << " ";
    }
    std::cout << "\n\n";
    //display the hand for player 2
    std::cout << "Player 2's hand:" << std::endl;
    for (size_t i = 0; i < p2Hand.size(); i++){
        std::cout << p2Hand[i] << " ";
    }
    std::cout << "\n";
}

void DisplayScore(int& p1Score, int& p2Score) {
    std::cout << "\nPlayer 1's current score is: " << p1Score << std::endl;
    std::cout << "Player 2's current score is: " << p2Score << "\n" << std::endl;
}
