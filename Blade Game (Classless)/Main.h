#pragma once

void flipTopCard(std::string  player1Deck[15], std::string  player2Deck[15], unsigned int& p1Score, unsigned int& p2Score);

void allTopCardsTied(unsigned int& topCardNum, bool& retflag);

void FlipTopCard(std::string  player1Deck[15], unsigned int& topCardNum, std::string  player2Deck[15], unsigned int& p1Score, unsigned int& p2Score);

void setStartScore(std::string* player1Deck, unsigned int& topCardNum, unsigned int& p1Score);

void checkForSameScore(unsigned int& p1Score, unsigned int& p2Score, unsigned int& topCardNum, bool& sameScore);

void startGame(const unsigned int& arraySize, std::string  bladeDeck[30], std::string  player1Deck[15], std::string  player2Deck[15], const unsigned int& handSize, std::string  player1Hand[10], std::string  player2Hand[10]);
