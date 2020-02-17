#pragma once

//Done
void AllTopCardsTied(unsigned int& topCardNum, bool& retflag);
//Done
void CheckForSameScore(unsigned int& p1Score, unsigned int& p2Score, unsigned int& topCardNum, bool& sameScore);
//Done
void SplitDeck(const unsigned int& arraySize, std::vector<std::string>& p1Deck, std::string  bladeDeck[30], std::vector<std::string>& p2Deck);
//Done
void ShowHand(std::vector<std::string>& p1Hand, std::vector<std::string>& p1Deck, const unsigned int& handSize, std::vector<std::string>& p2Hand, std::vector<std::string>& p2Deck);
//Done
void StartGame(const unsigned int& arraySize, std::string  bladeDeck[30], std::vector<std::string>& p1Deck, std::vector<std::string>& p2Deck, std::vector<std::string>& p1Hand, const unsigned int& handSize, std::vector<std::string>& p2Hand);
//Done
void FlipTopCard(unsigned int& topCardNum, std::vector<std::string>& p1Deck, unsigned int& p1Score, std::vector<std::string>& p2Deck, unsigned int& p2Score);
