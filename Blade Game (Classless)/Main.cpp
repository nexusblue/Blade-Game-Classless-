#include <iostream>  
#include <algorithm> 
#include <array>     
#include <string>
#include <random>    
#include <chrono>
#include <vector>
#include "Header.h"
#include "Main.h"


int main() {

    srand(time(0));

    //create a blade deck with 30 cards
    int topCardNum = 11;
    int p1Score = 0;
    int p2Score = 0;
    std::string p1Input, p2Input;
    std::string p1LastCard = "0";
    std::string p2LastCard = "0";
    std::string p1LCard2 = "0";
    std::string p2LCard2 = "0";

    int p1CardValue, p2CardValue;
    int retflag;
    bool gameIsOver = false;

    std::string bladeDeck[30] = { "[1]","[1]","[2]","[2]","[2]",
                                      "[3]","[3]","[3]","[3]","[4]",
                                      "[4]","[4]","[4]","[5]","[5]",
                                      "[5]","[5]","[6]","[6]","[6]",
                                      "[7]","[7]","[4]","[4]","[B]",
                                      "[B]","[B]","[B]","[M]","[M]", };

    //set the deck for both players and set the players hands
    std::vector<std::string> p1Deck = { "","","","","","","","","","","","","","","" };
    std::vector<std::string> p1Hand = { "","","","","","","","","","" };
    std::vector<std::string> p2Deck = { "","","","","","","","","","","","","","","" };
    std::vector<std::string> p2Hand = { "","","","","","","","","","" };

    //ShowTitle();
    //StartGame(arraySize, bladeDeck, p1Deck, p2Deck, p1Hand, p2Hand);
    //shuffle deck, cut in half and show players hands
    ShuffleDeck(bladeDeck);
    SplitDeck(p1Deck, bladeDeck, p2Deck);
    DealHands(p1Hand, p1Deck, p2Hand, p2Deck);
    DisplayHands(p1Hand, p2Hand);

    //flip the top card  of both players deck and set it to a score
    FlipTopCard(topCardNum, p1Deck, p1Score, p2Deck, p2Score);
    DisplayScore(p1Score, p2Score);

    //while the game is not over ask users for inputs
    while (gameIsOver == false)
    {
        //in case of tie score occuring
        if (p1Score == p2Score){
            p1Score, p2Score = 0;
            FlipTopCard(topCardNum, p1Deck, p1Score, p2Deck, p2Score);
            DisplayScore(p1Score, p2Score);
        }

        if (p1Score < p2Score){
            //ask p1 for a card and check if it is in the players hand
            VerifyCard(p1Input,1);
            SearchPlayerHand(p1Hand, p1Input, 1);
            UseP1Card(p1Input, p1Score, p2Score, p1LastCard,p2LastCard, p1Hand, p2LCard2,p1LCard2);
            if (p1Score < p2Score) {
                std::cout << "Player 1 still has a lower score. Player 1 loses." << std::endl;
                std::cout << "Player 2 wins." << std::endl;
                break;
            }
            if (p1LastCard != "0"){
                p1LCard2 = p1LastCard;
            }
            p1LastCard = p1Input;

        }
        
        else if (p1Score > p2Score){
            //ask p2 for a card and check if it is in the players hand
            VerifyCard(p2Input,2);
            SearchPlayerHand(p2Hand, p2Input,2);
            UseP2Card(p2Input, p2Score, p1Score, p2LastCard,p1LastCard, p2Hand, p1LCard2,p2LCard2);
            if (p1Score > p2Score) {
                std::cout << "Player 2 still has a lower score. Player 2 loses." << std::endl;
                std::cout << "Player 1 wins." << std::endl;
                break;
            }
            if (p2LastCard != "0"){
                p2LCard2 = p1LastCard;
            }

            p2LastCard = p2Input;
        }
        DisplayHands(p1Hand, p2Hand);
        DisplayScore(p1Score, p2Score);
    }
    std::cout << "The game has ended thanks for playing!" << std::endl;
    std::cin.get();
}
