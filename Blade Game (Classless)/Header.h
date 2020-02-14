#pragma once

void createDeck();

void shuffleDeck(const unsigned int arraySize, std::string* bladeDeck);

void splitDeck(const unsigned int& arraySize, std::string  p1Deck[15], std::string  bladeDeck[30], std::string  p2Deck[15]);

void showHand(const unsigned int& handSize, std::string  p1Hand[10], std::string  p1Deck[15], std::string  p2Hand[10], std::string  p2Deck[15]);

void showBladeRules();

void showCardTypes();

void ShowTitle();

void FlipTopCard(std::string  p1Deck[15], unsigned int& topCardNum, std::string  p2Deck[15], unsigned int& p1Score, unsigned int& p2Score);

void startGame(const unsigned int& arraySize, std::string  bladeDeck[30], std::string  p1Deck[15], std::string  p2Deck[15], const unsigned int& handSize, std::string  p1Hand[10], std::string  p2Hand[10]);