#include <iostream>  
#include <algorithm> 
#include <array>     
#include <string>
#include <random>    
#include <chrono>
#include <vector>

#pragma once

void AllTopCardsTied(bool& retflag);

void CheckForSameScore(bool& sameScore);

void DealHands(std::vector<std::string>& p1Hand, std::vector<std::string>& p1Deck, std::vector<std::string>& p2Hand, std::vector<std::string>& p2Deck);

void FlipTopCard(std::vector<std::string>& p1Deck, std::vector<std::string>& p2Deck);

void SearchPlayerHand(std::vector<std::string>& playerHand, std::string& p1Input,int curPlayer);

void VerifyCard(std::string& p1Input,int curPlayer);
