#include <iostream>  
#include <algorithm> 
#include <array>     
#include <string>
#include <random>    
#include <chrono>
#include <vector>
#include "Main.h"

#pragma once
void PrepareGame();

void ShowBladeRules();

void ShowCardTypes();

void ShowTitle();

void DisplayScore();

void ShuffleDeck(std::string* bladeDeck);

void DisplayHands(std::vector<std::string>& p1Hand, std::vector<std::string>& p2Hand);

void SplitDeck(std::string bladeDeck[30],std::vector<std::string>& p1Deck, std::vector<std::string>& p2Deck);