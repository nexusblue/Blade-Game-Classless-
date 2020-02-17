#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include "Header.h"

void createDeck() {

}

void shuffleDeck(const unsigned int arraySize, std::string* bladeDeck) {
    //shuffle the blade deck to randomize the order
    unsigned seed = rand() % 100;
    std::shuffle(bladeDeck, bladeDeck + arraySize, std::default_random_engine(seed));
}

void splitDeck(const unsigned int& arraySize, std::string bladeDeck[30], std::string p1Deck[15], std::string p2Deck[15]) {
    //split deck in half with each pile going to a player
    for (size_t i = 0; i < arraySize; i++){
        //create player's 1 pile with the first 15 cards
        if (i < 15){
            p1Deck[i]= bladeDeck[i];
        }
        //create player's 2 pile with the last 15 cards
        else{
            p2Deck[i - 15] = bladeDeck[i];
        }
    }
    std::cout << "\n";
}

void showHand(const unsigned int& handSize, std::string  p1Hand[10], std::string p1Deck[15], std::string  p2Hand[10], std::string  p2Deck[15])
{
    //sort and show playerdeck
    //SHOWS ALL OF BOTH PLAYERS CARDS
    //COME BACK TO DELETE THIS TEST CODE
    //std::sort(player1Deck, player1Deck + handSize);
    //std::sort(player2Deck, player2Deck + handSize);

    //get the starting cards from player 1's deck pile
    for (size_t i = 0; i < (handSize); i++)
    {
        p1Hand[i] = p1Deck[i];
        //std::cout << player1Deck[i] << " ";
    }

    //get the starting cards from player 2's deck pile
    for (size_t i = 0; i < (handSize); i++)
    {
        p2Hand[i] = p2Deck[i];
    }

    //sort the cards in order from lowest to highest
    std::sort(p1Hand, p1Hand + handSize);
    std::sort(p2Hand, p2Hand + handSize);

    //display the hand for player 1
    std::cout <<"Player 1's hand:" <<std::endl;
    for (size_t i = 0; i < (handSize); i++)
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

