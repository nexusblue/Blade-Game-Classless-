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

extern int topCardNum;
extern int p1Score;
extern int p2Score;

int main() {

    srand(time(0));
    //int topCardNum = 11;
    //int p1Score = 0;
    //int p2Score = 0;
    std::string p1Input, p2Input;
    bool gameIsOver = false;

    //create a blade deck with 30 cards
    std::string bladeDeck[30] = {"[1]","[1]","[2]","[2]","[2]","[2]","[3]","[3]","[3]","[4]",
                                 "[4]","[4]","[4]","[5]","[5]","[5]","[5]","[6]","[6]","[6]",
                                 "[7]","[7]","[4]","[4]","[B]","[B]","[B]","[B]","[M]","[M]"};

    //ready players decks and hands to be filled with blade cards
    std::vector<std::string> p1Deck = { "","","","","","","","","","","","","","","" };
    std::vector<std::string> p1Hand = { "","","","","","","","","","" };
    std::vector<std::string> p2Deck = { "","","","","","","","","","","","","","","" };
    std::vector<std::string> p2Hand = { "","","","","","","","","","" };

    //Record all cards played by both players
    std::list<std::string> p1Stack = {""};
    std::list<std::string> p2Stack = {""};

    //Keep track of when bolt cards are used and what values were deleted 
    bool LastCardBolt = false;
    std::string LastBoltValue;


    ShowTitle();                                //Show the title screen
    PrepareGame();                              //Make sure the user is able to see the rules
                                                //Setup game functions
    ShuffleDeck(bladeDeck);                     //shuffle deck
    SplitDeck(bladeDeck, p1Deck, p2Deck);       //Cut deck in half
    DealHands(p1Hand, p1Deck, p2Hand, p2Deck);  //Deal out the cards from the players decks
    FlipTopCard(p1Deck, p2Deck);                //Set score to value with the top card of player deck

    //main game loop
    while (gameIsOver == false)
    {
        std::string p1LCard = p1Stack.back();
        std::string p2LCard = p2Stack.back();
        DisplayHands(p1Hand, p2Hand);
        DisplayScore();
        //In case of tied Scores, flip the top card of both players decks to get uneven scores
        if (p1Score == p2Score){
            p1Score, p2Score = 0;
            FlipTopCard(p1Deck,p2Deck);
            DisplayScore();
        }
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
                std::cout << " Player 1 still has a lower score. Player 2 is the winner!" << std::endl;
                gameIsOver = true;
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
                std::cout << " Player 1 still has a lower score. Player 1 is the winner!" << std::endl;
                gameIsOver = true;
            }
        }
    }
    
    std::cout << " The game has ended thanks for playing!" << std::endl;
    std::cin.get();
}
