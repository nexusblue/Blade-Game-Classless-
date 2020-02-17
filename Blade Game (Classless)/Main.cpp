#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <string>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include "Header.h"
#include "Main.h"
#include <vector> 


int main() {

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
    std::vector<std::string> p1Deck = { "","","","","","","","","","","","","","","" };
    std::vector<std::string> p1Hand = { "","","","","","","","","","" };
    std::vector<std::string> p2Deck = { "","","","","","","","","","","","","","","" };
    std::vector<std::string> p2Hand = { "","","","","","","","","","" };

    //ShowTitle();
    //StartGame(arraySize, bladeDeck, p1Deck, p2Deck, p1Hand, handSize, p2Hand);
    //shuffle deck, cut in half and show players hands
    //DELETE THIS WHEN GAME IS DONE 
    ShuffleDeck(arraySize, bladeDeck);
    SplitDeck(arraySize, p1Deck, bladeDeck, p2Deck);
    ShowHand(p1Hand, p1Deck, handSize, p2Hand, p2Deck);

    //flip the top card  of both players deck and set it to a score
    FlipTopCard(topCardNum, p1Deck, p1Score, p2Deck, p2Score);

    bool gameIsOver = false;
    std::string p1Input, p2Input, p1LastCard;
    int p1CardValue, p2CardValue;
    std::cout << "\n";
    std::cout << "Player 1's current score is: " << p1Score << std::endl;
    std::cout << "Player 2's current score is: " << p2Score << std::endl;
    std::cout << "\n";
    
    //while the game is not over ask users for inputs
   
    while (gameIsOver == false)
    {
        if (p1Score == p2Score){
            p1Score, p2Score = 0;
            FlipTopCard(topCardNum, p1Deck, p1Score, p2Deck, p2Score);
        }

        if (p1Score < p2Score){

            //ask p1 for a card and check if it is in the players hand
            std::cout << "Player 1 has a lower score please go first." << std::endl;
            std::cout << "\n";
            std::cout << "Please enter a card Player 1:";
            std::cin >> p1Input;
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------" << std::endl;

            while (std::find(p1Hand.begin(), p1Hand.begin() + handSize, "["+p1Input+"]") == p1Hand.begin() + handSize) {
                std::cout << "That card is not in your hand." << std::endl;
                std::cout << "\n";
                std::cout << "Please enter a new card Player 1:";
                std::cin >> p1Input;
                p1Input = p1Input ;
                std::cout << "\n";
                std::cout << "----------------------------------------------------------------" << std::endl;
            }

            if (p1Input == "M"){
                std::swap(p1Score, p2Score);
            }

            else if (p1Input == "B"){
                p2Score =  p2Score-std::stoi(p1LastCard);
            }

            else{
                p1Score = p1Score + std::stoi(p1Input);
                std::cout << "\n";
            }
            p1LastCard = p1Input;

        }
        
        else if (p1Score > p2Score)
        {
            //ask p2 for a card and check if it is in the players hand
            std::cout << "Player 2 has a lower score please go first." << std::endl;
            std::cout << "\n";
            std::cout << "Please enter a card Player 2:";
            std::cin >> p2Input;
            p2Input = p2Input;
            std::cout << "\n";
            std::cout << "----------------------------------------------------------------" << std::endl;

            while (std::find(p2Hand.begin(), p2Hand.begin() + handSize, "["+p2Input+"]") == p2Hand.begin() + handSize) {
                std::cout << "That card is not in your hand." << std::endl;
                std::cout << "\n";
                std::cout << "Please enter a new card Player 2:";
                std::cin >> p2Input;
                p2Input = p2Input;
                std::cout << "\n";
                std::cout << "----------------------------------------------------------------" << std::endl;
            }

            if (p2Input == "M"){
                std::swap(p2Score, p1Score);
            }

            else if (p2Input == "B"){
                p1Score = p1Score - std::stoi(p1LastCard);
                std::cout << "\n";
            }

            else{
                p2Score = p2Score + std::stoi(p2Input);
            }
        }
        
        ShowHand(p1Hand, p1Deck, handSize, p2Hand, p2Deck);
        std::cout << "\n";
        std::cout << "Player 1's current score is: " << p1Score << std::endl;
        std::cout << "Player 2's current score is: " << p2Score << std::endl;

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
        */
    std::cin.get();
}



