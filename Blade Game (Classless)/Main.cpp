#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <string>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include "Header.h"
#include "Main.h"


int main() {

    createDeck();
    srand(time(0));

    //REMINDER: const means object or var is not modefiable and unsigned makes sure its not a negative num
    //create a blade deck with 30 cards
    const unsigned int arraySize = 30;
    const unsigned int handSize = 10;
    unsigned int topCardNum = 11;
    unsigned int p1Score = 0;
    unsigned int p2Score = 0;
    
    std::string bladeDeck[arraySize] = { "[1]","[1]","[2]","[2]","[2]",
                                      "[3]","[3]","[3]","[3]","[4]",
                                      "[4]","[4]","[4]","[5]","[5]",
                                      "[5]","[5]","[6]","[6]","[6]",
                                      "[7]","[7]","[B]","[B]","[B]",
                                      "[B]","[B]","[B]","[M]","[M]", };
    
    //set the deck for both players and set the players hands
    std::string p1Deck[arraySize / 2];
    std::string p2Deck[arraySize / 2];
    std::string p1Hand[handSize];
    std::string p2Hand[handSize];

    //ShowTitle();
    //startGame(arraySize, bladeDeck, player1Deck, player2Deck, handSize, player1Hand, player2Hand);

    //shuffle deck, cut in half and show players hands
    //DELETE THIS WHEN GAME IS DONE 
    shuffleDeck(arraySize, bladeDeck);
    splitDeck(arraySize, bladeDeck, p1Deck, p2Deck);
    showHand(handSize, p1Hand, p1Deck, p2Hand, p2Deck);
   
    //flip the top card  of both players deck and set it to a score
    FlipTopCard(p1Deck, topCardNum, p2Deck, p1Score, p2Score);

    bool gameIsOver = false;
    std::string p1Input, p2Input;
    int p1CardValue, p2CardValue;

    std::cout << "Player 1's current score is: " << p1Score << std::endl;
    std::cout << "Player 2's current score is: " << p2Score << std::endl;

    //while the game is not over ask users for inputs
    while (gameIsOver == false)
    {
        if (p1Score < p2Score)
        {
            //ask p1 for a card and check if it is in the players hand
            std::cout << "Player 1 has a lower score please go first." << std::endl;
            std::cout << "Please enter a card Player 1:";
            std::cin >> p1Input;

            while (std::find(p1Hand, p1Hand + handSize, "["+p1Input+"]") == p1Hand+handSize) {
                std::cout << "That card is not in your hand." << std::endl;
                std::cout << "Please enter a new card Player 1:";
                std::cin >> p1Input;
                p1Input = p1Input ;
            
            }
            if (p1Input == "M")
            {

            }
            else if (p1Input == "B")
            {

            }
            else
            {
                p1Score = p1Score + std::stoi(p1Input);
                std::cout << std::stoi(p1Input) << std::endl;
                std::cout << "\n";
                std::cout << "Player 1's current score is: " << p1Score << std::endl;
                std::cout << "Player 2's current score is: " << p2Score << std::endl;
            }
        }

        if (p1Score > p2Score)
        {
            //ask p2 for a card and check if it is in the players hand
            std::cout << "Player 2 has a lower score please go first." << std::endl;
            std::cout << "Please enter a card Player 2:";
            std::cin >> p2Input;
            p2Input = p2Input;

            while (std::find(p2Hand, p2Hand + handSize, "["+p2Input+"]") == p2Hand + handSize) {
                std::cout << "That card is not in your hand." << std::endl;
                std::cout << "Please enter a new card Player 2:";
                std::cin >> p2Input;
                p2Input = p2Input;

            }
            if (p1Input == "M")
            {

            }
            else if (p1Input == "B")
            {

            }
            else
            {
                p2Score = p2Score + std::stoi(p2Input);
                std::cout << p2Input << std::endl;
                std::cout << "Player 1's current score is: " << p1Score << std::endl;
                std::cout << "Player 2's current score is: " << p2Score << std::endl;
            }
        }
    }

    std::cout << "game is done" << std::endl;
    //playGame();
    /*
    when you start the game you should:
        create a current score for both players
        flip top card of both players decks and check both cards score
        while the score of both cards are not equal
            flip a new card then
            reset score back to 0
            else let the player with the lower score go first and show a 
        check if one score is larger
    
    std::cout<<"Type: "<<typeid(p1Score).name()<<std::endl;
    player2Deck

            else
        {
            std::cout << "Player 2 has a lower score please go first." << std::endl;
            std::cout << "Please enter a card Player 2:" << std::endl;
        }

    */
    std::cin.get();
}