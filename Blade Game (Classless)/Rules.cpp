#include <iostream>     // std::cout
#include "Header.h"

void ShowTitle(){
	std::cout << "\n==================================================================================\n";
	std::cout << "||                                                                              ||" << std::endl;
	std::cout << "||                    ======   ==         =====     ======    ======            ||" << std::endl;
	std::cout << "||                   ||     |  ||       ||     ||  ||     |  ||                 ||" << std::endl;
	std::cout << "||                   ||=====|  ||       ||_____||  ||     |  ||=====            ||" << std::endl;
	std::cout << "||                   ||     |  ||       ||     ||  ||     |  ||                 ||" << std::endl;
	std::cout << "||                   ||=====|  ||=====  ||     ||  ||=====|  ||=====            ||" << std::endl;
	std::cout << "||                                                                              ||" << std::endl;
	std::cout << "==================================================================================" << std::endl;
	std::cout << "||                                                                              ||"<<std::endl;
	std::cout << "||                       =====  ==      =====  ===  ===                         ||" << std::endl;
	std::cout << "||                      ||    | ||     ||   ||   \\\\//                           ||" << std::endl;
	std::cout << "||                      ||____| ||     ||___||    ||                            ||" << std::endl;
	std::cout << "||                      ||      ||==== ||   ||    ||                            ||" << std::endl;
	std::cout << "||                                                                              ||" << std::endl;
	std::cout << "||                       =====  ==    ==  ==      =====    =====                ||" << std::endl;
	std::cout << "||                      ||____| ||    ||  ||     ||____   ||____                ||" << std::endl;
	std::cout << "||                      ||   \\  ||    ||  ||     ||           ||                ||" << std::endl;
	std::cout << "||                      ||    \\ ||====||  ||==== ||====   ====||                ||" << std::endl;
	std::cout << "==================================================================================" << std::endl;
	std::cout << "\n\n\n";
}

void ShowBladeRules() { 
	std::cout << "                      Blade Game Rules:" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "||  Blade is a card game where two players takes turns        ||" << std::endl;
	std::cout << "||  placing numbered cards on the field in order to have      ||" << std::endl;
	std::cout << "||  have the highest sum total then your opponent does.       ||" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cin.get();

	std::cout << "================================================================" << std::endl;
	std::cout << "||  Once both players hands have been dealt, both players     ||" << std::endl;
	std::cout << "||  draw a card from their decks and place it on the field.   ||" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cin.get();

	std::cout << "================================================================" << std::endl;
	std::cout << "||  The player who draws the lower number must then proceed   ||"<< std::endl;
	std::cout << "||  to place a card from their hand onto the field.           ||" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cin.get();
	std::cout << "================================================================" << std::endl;
	std::cout << "||  The player who goes second must then play card with       ||" << std::endl;
	std::cout << "||  a value higher then their opponent's current total.       ||" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cin.get();

	std::cout << "================================================================" << std::endl;
	std::cout << "||  Should both players have equal totals,the scores are      ||" << std::endl;
	std::cout << "||  reset by drawing the card from both players decks.        ||" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cin.get();

	std::cout << "================================================================" << std::endl;
	std::cout << "||  If the final of the game is used to clear the field,      ||" << std::endl;
	std::cout << "||  the match will result in a draw.                          ||" << std::endl;
	std::cout << "================================================================\n" << std::endl;
	std::cin.get();

	//std::cout << "\n----------------------------------------------------------------------------\n"<<std::endl;
}

void ShowCardTypes(){
	//Show the blade card types
	std::cout << "                           Blade Cards Types:" << std::endl;
	std::cout << "===========================================================================" << std::endl;
	std::cout << "||  There are 3 types of cards in Blade:                                 ||" << std::endl;
	std::cout << "||  Blade cards -[1]-[7] Cards with values from 1-7 that boost your score||" << std::endl;
	std::cout << "||  Bolt cards  -[B]     Remove the last card your opponent played       ||" << std::endl;
	std::cout << "||  Mirror cards-[M]     Swaps both players scores and cards played      ||" << std::endl;
	std::cout << "===========================================================================" << std::endl;
	std::cin.get();

	std::cout << "================================================================" << std::endl;
	std::cout << "||  As a special rule, a card with a value of 1 can be used   ||" << std::endl;
	std::cout << "||  to bring back a card removed by the use of a Bolt card.   ||" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cin.get();

	std::cout << "================================================================" << std::endl;
	std::cout << "||  Bolt Cards and Mirror Cards have card values of 1 if      ||" << std::endl;
	std::cout << "||  they are the top card flipped from the player's deck      ||" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cin.get();

	std::cout << "================================================================" << std::endl;
	std::cout << "||  But be careful--using a Bolt or Mirror card as your last  ||" << std::endl;
	std::cout << "||  move is considered a foul, and will cost you the match.   ||" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cin.get();

}
