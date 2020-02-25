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

//COME BACK HERE TO BREAK DOWN CODE
void StartGame(std::string bladeDeck[30], std::vector<std::string>& p1Deck, std::vector<std::string>& p2Deck, std::vector<std::string>& p1Hand, std::vector<std::string>& p2Hand, int& p1Score, int& p2Score)
{
    std::string userInput;
    std::cout << "Type 'play' to play the game or 'rules' to see the rules first." << std::endl;
    std::cout << "What would you like to do: ";
    std::cin >> userInput;
    std::cout << "\n";

    while (userInput != "play" && userInput != "rules")
    {
        std::cout << "Please enter a valid input." << std::endl;
        std::cout << "What would you like to do: ";
        std::cin >> userInput;
        std::cout << "\n";
    }

    if (userInput == "play"){
        ShuffleDeck(bladeDeck);
        SplitDeck(p1Deck, bladeDeck, p2Deck);
        DisplayHands(p1Hand, p2Hand);
        DisplayScore(p1Score, p2Score);
    }
    else{
        while (userInput != "play")
        {
            std::cout << "Which do you want to see first 'rules' or 'cards'." << std::endl;
            std::cout << "Type 'play' when you are ready to play ." << std::endl;
            std::cout << "What would you like to do: ";
            std::cin >> userInput;
            std::cout << "\n";
            if (userInput == "rules")
            {
                ShowBladeRules();
            }
            else if (userInput == "cards")
            {
                ShowCardTypes();
            }
            else
            {
                std::cout << "Please enter a valid input." << std::endl;
            }
        }
        ShuffleDeck(bladeDeck);
        SplitDeck(p1Deck, bladeDeck, p2Deck);
        DisplayHands(p1Hand, p2Hand);
        DisplayScore(p1Score, p2Score);

    }
}

void CheckForSameScore(int& p1Score,int& p2Score,int& topCardNum, bool& sameScore)
{
    //check to see if both scores are equal
    if (p1Score == p2Score) {
        std::cout << "\nPlayer 1 top card: " << p1Score << std::endl;
        std::cout << "Player 2 top card: " << p2Score <<"\n" <<std::endl;
        std::cout << "Oh same score. We better must draw again." << std::endl;
        std::cout << "----------------------------------------------------------------\n" << std::endl;
        topCardNum += 1;
    }
    else {
        sameScore = false;
    }
}

void AllTopCardsTied(int& topCardNum, bool& retflag){
    retflag = true;
    //if all 5 cards are tied then end the game with a tie
    if (topCardNum == 15) {
        std::cout << "The game ends in a tie." << std::endl;
        return;
    }
    std::cout << "The game can now start." << std::endl;
    retflag = false;
}

void FlipTopCard(int& topCardNum, std::vector<std::string>& p1Deck, int& p1Score, std::vector<std::string>& p2Deck,int& p2Score){
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

        CheckForSameScore(p1Score, p2Score, topCardNum, sameScore);
    }
    std::cout << "\nPlayer 1 top card: " << p1Deck[topCardNum][1] << std::endl;
    std::cout << "Player 2 top card: " << p2Deck[topCardNum][1] <<"\n"<<std::endl;
    AllTopCardsTied(topCardNum, retflag);
    if (retflag) return;
}

void VerifyCard(std::string& playerInput, int curPlayer)
{
    std::cout << "Player " << curPlayer << " has a lower score please go first." << std::endl;
    std::cout << "Please enter a card Player " << curPlayer << ":";
    std::cin >> playerInput;
    std::cout << "\n----------------------------------------------------------------" << std::endl;
}

void SearchPlayerHand(std::vector<std::string>& playerHand, std::string& playerInput, int curPlayer) {
    //check player input to see if the card in their hand
    while (std::find(playerHand.begin(), playerHand.begin() + playerHand.size(), "[" + playerInput + "]") == playerHand.begin() + playerHand.size()) {
        std::cout << "That card is not in your hand." << std::endl;
        std::cout << "\n";
        std::cout << "Please enter a new card Player " << curPlayer << ": ";
        std::cin >> playerInput;
        std::cout << "\n----------------------------------------------------------------" << std::endl;
    }
}

void UseP1Card(std::string& p1Input, int& p1Score, int& p2Score, std::string& p1LastCard,std::string& p2LastCard, std::vector<std::string>& p1Hand, std::string& p2LCard2, std::string& p1LCard2) {
    
    //look for the placement of the first instance of the card the player choose
    int counter = 0;
    for (size_t i = 0; i < p1Hand.size(); i++){
        if (p1Hand[i] == "["+p1Input+"]"){
            break;
        }
        counter += 1;
    }
    //player 1 swaps score with player 2 and takes out 1 mirror card
    if (p1Input == "M") {
        p1Hand.erase(p1Hand.begin()+counter);
        std::swap(p1Score, p2Score);
        std::swap(p2LastCard, p1LastCard);
    }
    //
    else if (p1Input == "1" && p2LastCard == "B")
    {
        p1Hand.erase(p1Hand.begin() + counter);
        p2Score = p2Score + std::stoi(p1LastCard);
    }
    //
    else if (p1Input == "B" && p2LastCard == "B")
    {
        p1Hand.erase(p1Hand.begin() + counter);
        p2Score = p2Score - std::stoi(p2LCard2);
    }

    //
    else if (p1Input == "B" && p2LastCard == "M")
    {
        p1Hand.erase(p1Hand.begin() + counter);
        p2Score = p2Score - std::stoi(p2LCard2);
    }
    //remove last card value player 2 played and take out a bolt card
    else if (p1Input == "B" && p2LastCard == "0")
    {
        p1Hand.erase(p1Hand.begin() + counter);
        p1Score = p1Score - std::stoi(p2LCard2);

    }
    else if (p1Input == "B") {
        // IDEA TO TRY TOMORROW! REMOVE THE LAST CARD PLAYED
        //IF THERE IS NO LAST CARD PLAYED THEN SET PLAYER SCORE TO 0
        p1Hand.erase(p1Hand.begin() + counter);
        p2Score = p2Score - std::stoi(p2LastCard);
    }
    //add a card value to player 1 
    else {
        p1Hand.erase(p1Hand.begin() + counter);
        p1Score = p1Score + std::stoi(p1Input);
        std::cout << "\n";
    }
}

void UseP2Card(std::string& p2Input, int& p2Score, int& p1Score, std::string& p2LastCard,std::string& p1LastCard, std::vector<std::string>& p2Hand, std::string& p1LCard2, std::string& p2LCard2) {

    //look for the placement of the first instance of the card the player choose
    int counter = 0;
    for (size_t i = 0; i < p2Hand.size(); i++){
        if (p2Hand[i] == "[" + p2Input + "]"){
            break;
        }
        counter += 1;
    }

    //player 2 swaps score with player 2 and takes out 1 mirror card
    if (p2Input == "M") {
        p2Hand.erase(p2Hand.begin() + counter);
        std::swap(p2Score, p1Score);
        std::swap(p2LastCard,p1LastCard);
    }
    else if (p2Input == "1" && p1LastCard == "B")
    {
        p2Hand.erase(p2Hand.begin() + counter);
        p1Score = p1Score + std::stoi(p1LCard2);
    }
    else if (p2Input == "B" && p1LastCard == "B")
    {
        p2Hand.erase(p2Hand.begin() + counter);
        p1Score = p1Score - std::stoi(p1LCard2);
    }
    else if (p2Input == "B" && p1LastCard == "M")
    {
        p2Hand.erase(p2Hand.begin() + counter);
        p1Score = p1Score - std::stoi(p1LCard2);
    }

    //remove last card value player 1 played and take out a bolt card
    else if (p2Input == "B" && p1LastCard == "0")
    {
        p2Hand.erase(p2Hand.begin() + counter);
        p1Score = 0;
    }

    else if (p2Input == "B") {
        p2Hand.erase(p2Hand.begin() + counter);
        p1Score = p1Score - std::stoi(p1LastCard);
        std::cout << "\n";
    }
    //add a card value to player 1 
    else {
        p2Hand.erase(p2Hand.begin() + counter);
        p2Score = p2Score + std::stoi(p2Input);
        std::cout << "\n";
    }

}

void CheckForWinner(int p1Score, int p2Score, int& retflag)
{
    retflag = 1;
    if (p1Score < p2Score) {
        std::cout << "Player 1 still has a lower score. Player 1 loses." << std::endl;
        std::cout << "Player 2 wins." << std::endl;
        { retflag = 2; return; };
    }
    if (p1Score > p2Score) {
        std::cout << "Player 2 still has a lower score. Player 2 loses." << std::endl;
        std::cout << "Player 1 wins." << std::endl;
        { retflag = 2; return; };
    }

}

