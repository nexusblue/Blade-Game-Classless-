#pragma once

//Done
void ShuffleDeck(const unsigned int arraySize, std::string* bladeDeck);
//Done
void SplitDeck(const unsigned int& arraySize, std::vector<std::string>& p1Deck, std::string  bladeDeck[30], std::vector<std::string>& p2Deck);
//Done
void ShowHand(std::vector<std::string>& p1Hand, std::vector<std::string>& p1Deck, const unsigned int& handSize, std::vector<std::string>& p2Hand, std::vector<std::string>& p2Deck);
//Done
void ShowBladeRules();
//Done
void ShowCardTypes();
//Done
void ShowTitle();

void FlipTopCard(std::string  p1Deck[15], unsigned int& topCardNum, std::string  p2Deck[15], unsigned int& p1Score, unsigned int& p2Score);
//Done
void StartGame(const unsigned int& arraySize, std::string  bladeDeck[30], std::vector<std::string>& p1Deck, std::vector<std::string>& p2Deck, std::vector<std::string>& p1Hand, const unsigned int& handSize, std::vector<std::string>& p2Hand);