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


int main() {

    srand(time(0));

    //create a blade deck with 30 cards
    int topCardNum = 11;
    int p1Score = 0;
    int p2Score = 0;
    std::string p1Input, p2Input;
    bool gameIsOver = false;

    std::string bladeDeck[30] = { "[1]","[1]","[2]","[2]","[2]",
                                      "[1]","[3]","[3]","[3]","[4]",
                                      "[1]","[4]","[4]","[5]","[5]",
                                      "[1]","[5]","[6]","[6]","[6]",
                                      "[1]","[7]","[4]","[4]","[B]",
                                      "[B]","[B]","[B]","[M]","[M]", };

    //set the deck for both players and set the players hands
    std::vector<std::string> p1Deck = { "","","","","","","","","","","","","","","" };
    std::vector<std::string> p1Hand = { "","","","","","","","","","" };
    std::vector<std::string> p2Deck = { "","","","","","","","","","","","","","","" };
    std::vector<std::string> p2Hand = { "","","","","","","","","","" };
    //Record all cards played and keep track of the value 
    //of cards that may be removed by a bolt card
    std::list<std::string> p1Stack = {""};
    std::list<std::string> p2Stack = {""};
    bool LastCardBolt = false;
    std::string LastBoltValue;

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
        std::string p1LCard = p1Stack.back();
        std::string p2LCard = p2Stack.back();

        //In case of tied Scores, flip the top card of both players decks to get uneven scores
        if (p1Score == p2Score){
            p1Score, p2Score = 0;
            FlipTopCard(topCardNum, p1Deck, p1Score, p2Deck, p2Score);
            DisplayScore(p1Score, p2Score);
        }
        std::cout << LastCardBolt;

        if (p1Score < p2Score){
            //ask p1 for a card and check if it is in the players hand
            VerifyCard(p1Input,1);
            SearchPlayerHand(p1Hand, p1Input, 1);
            //UseP1Card(p1Input, p1Score, p2Score, p1LastCard,p2LastCard, p1Hand, p2LastCard2,p1LastCard2);
            //look for the placement of the first instance of the card the player choose
            int counter = 0;
            for (size_t i = 0; i < p1Hand.size(); i++) {
                if (p1Hand[i] == "[" + p1Input + "]") {
                    break;
                }
                counter += 1;
            }
            if (p1Input == "M") {
                p1Hand.erase(p1Hand.begin() + counter);
                std::swap(p1Score, p2Score);
                std::swap(p1Stack , p2Stack );
                LastCardBolt = false;
            }
            else if (p1Input == "B" && p2LCard == "") {
                p1Hand.erase(p1Hand.begin() + counter);
                LastBoltValue = std::to_string(p2Score);
                LastCardBolt = true;
                p2Score = 0;
            }
            else if (p1Input == "B" ) {
                p1Hand.erase(p1Hand.begin() + counter);
                LastBoltValue = p2LCard;
                p2Score -= std::stoi(p2LCard);
                p2Stack.pop_back();
                LastCardBolt = true;
            }
            else if (p1Input == "1" && LastCardBolt == true){
                p1Hand.erase(p1Hand.begin() + counter);
                p1Stack.push_back(LastBoltValue);
                p1Score += std::stoi(LastBoltValue);
                LastCardBolt = false;
            }
            else {
                p1Hand.erase(p1Hand.begin() + counter);
                p1Score += std::stoi(p1Input);
                p1Stack.push_back(p1Input);
                LastCardBolt = false;
            }
            if (p1Score < p2Score) {
                std::cout << "Player 1 still has a lower score. Player 1 loses." << std::endl;
                std::cout << "Player 2 wins." << std::endl;
                break;
            }

        }
        
        else if (p1Score > p2Score){
            //ask p2 for a card and check if it is in the players hand
            VerifyCard(p2Input,2);
            SearchPlayerHand(p2Hand, p2Input,2);
            int counter = 0;
            for (size_t i = 0; i < p2Hand.size(); i++) {
                if (p2Hand[i] == "[" + p2Input + "]") {
                    break;
                }
                counter += 1;
            }
            if (p2Input == "M") {
                p2Hand.erase(p2Hand.begin() + counter);
                std::swap(p2Score, p1Score);
                std::swap(p2Stack, p1Stack);
                LastCardBolt = false;
            }
            else if (p2Input == "B" && p1LCard == "") {
                p2Hand.erase(p2Hand.begin() + counter);
                LastBoltValue = std::to_string(p1Score);
                p1Score = 0;
                LastCardBolt = true;
            }
            else if (p2Input == "B") {
                p2Hand.erase(p2Hand.begin() + counter);
                LastBoltValue = p1LCard;
                p1Score -= std::stoi(p1LCard);
                p1Stack.pop_back();
                LastCardBolt = true;
            }
            else if (p2Input == "1" && LastCardBolt == true) {
                p2Hand.erase(p2Hand.begin() + counter);
                p2Stack.push_back(LastBoltValue);
                p2Score += std::stoi(LastBoltValue);
                LastCardBolt = false;
            }
            else {
                p2Hand.erase(p2Hand.begin() + counter);
                p2Score += std::stoi(p2Input);
                p2Stack.push_back(p2Input);
                LastCardBolt = false;
            }
            if (p1Score > p2Score) {
                std::cout << "Player 2 still has a lower score. Player 2 loses." << std::endl;
                std::cout << "Player 1 wins." << std::endl;
                break;
            }
        }
        DisplayHands(p1Hand, p2Hand);
        DisplayScore(p1Score, p2Score);
    }
    std::cout << "The game has ended thanks for playing!" << std::endl;
    std::cin.get();
}


