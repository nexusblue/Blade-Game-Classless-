#include <iostream>  
#include <algorithm> 
#include <array>     
#include <string>
#include <random>    
#include <chrono>
#include <vector>
#include "Main.h"

#pragma once
void ShowBladeRules();

void ShowCardTypes();

void ShowTitle();

void ShuffleDeck(std::string* bladeDeck);

void SplitDeck(std::vector<std::string>& p1Deck, std::string  bladeDeck[30], std::vector<std::string>& p2Deck);

void DisplayHands(std::vector<std::string>& p1Hand, std::vector<std::string>& p2Hand);

void DisplayScore(int& p1Score, int& p2Score);

void FlipTopCard(int& topCardNum, std::vector<std::string>& p1Deck, int& p1Score, std::vector<std::string>& p2Deck, int& p2Score);

void StartGame(std::string  bladeDeck[30], std::vector<std::string>& p1Deck, std::vector<std::string>& p2Deck, std::vector<std::string>& p1Hand, std::vector<std::string>& p2Hand, int& p1Score, int& p2Score);