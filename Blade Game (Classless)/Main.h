#include <iostream>  
#include <algorithm> 
#include <array>     
#include <string>
#include <random>    
#include <chrono>
#include <vector>

#pragma once

void AllTopCardsTied(int& topCardNum, bool& retflag);

void CheckForSameScore( int& p1Score,  int& p2Score,int& topCardNum, bool& sameScore);

void SplitDeck(std::vector<std::string>& p1Deck, std::string  bladeDeck[30], std::vector<std::string>& p2Deck);

//void DisplayHands(std::vector<std::string>& p1Hand, std::vector<std::string>& p2Hand, int& p1Score, int& p2Score);

void DealHands(std::vector<std::string>& p1Hand, std::vector<std::string>& p1Deck, std::vector<std::string>& p2Hand, std::vector<std::string>& p2Deck);

void StartGame(std::string  bladeDeck[30], std::vector<std::string>& p1Deck, std::vector<std::string>& p2Deck, std::vector<std::string>& p1Hand, std::vector<std::string>& p2Hand, int& p1Score, int& p2Score);

void FlipTopCard(int& topCardNum, std::vector<std::string>& p1Deck,  int& p1Score, std::vector<std::string>& p2Deck,  int& p2Score);

void UseP1Card(std::string& p1Input, int& p1Score, int& p2Score, std::string& p1LastCard,std::string& p2LastCard, std::vector<std::string>& p1Hand, std::string& p2LCard2, std::string& p1LCard2);

void UseP2Card(std::string& p2Input, int& p2Score, int& p1Score, std::string& p2LastCard,std::string& p1LastCard, std::vector<std::string>& p2Hand, std::string& p1LCard2, std::string& p2LCard2);

void SearchPlayerHand(std::vector<std::string>& playerHand, std::string& p1Input,int curPlayer);

void CheckForWinner(int p1Score, int p2Score, int& retflag);

void VerifyCard(std::string& p1Input,int curPlayer);
