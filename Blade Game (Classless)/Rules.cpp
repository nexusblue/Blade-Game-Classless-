#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include "Header.h"

void ShowTitle()
{
	std::cout << "\n";
	std::cout << "=======================================================================================";
	std::cout << "                                                                        " << std::endl;
	std::cout << "                     ======   ==         =====     ======    ======     " << std::endl;
	std::cout << "                    ||     |  ||       ||     ||  ||     |  ||          " << std::endl;
	std::cout << "                    ||=====|  ||       ||_____||  ||     |  ||=====     " << std::endl;
	std::cout << "                    ||     |  ||       ||     ||  ||     |  ||          " << std::endl;
	std::cout << "                    ||=====|  ||=====  ||     ||  ||=====|  ||=====     " << std::endl;
	std::cout << "                                                                        " << std::endl;
	std::cout << "=======================================================================================" << std::endl;
	std::cout << "                                                                        " << std::endl;
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "                       =====  ==      =====  ===  ===           " << std::endl;
	std::cout << "                      ||    | ||     ||   ||   \\\\//           " << std::endl;
	std::cout << "                      ||____| ||     ||___||    ||              " << std::endl;
	std::cout << "                      ||      ||==== ||   ||    ||              " << std::endl;
	std::cout << "                                                                " << std::endl;
	std::cout << "                       =====  ==    ==  ==      =====    =====  " << std::endl;
	std::cout << "                      ||____| ||    ||  ||     ||____   ||____  " << std::endl;
	std::cout << "                      ||   \\  ||    ||  ||     ||           || " << std::endl;
	std::cout << "                      ||    \\ ||====||  ||==== ||====   ====|| " << std::endl;
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
}

void showBladeRules() {
	std::cout << "\n";
	std::cout << "----------------------------------------------------------------------------";
	std::cout << "\n";
	//Show blade rules
	std::cout << "Blade Game Rules:" << std::endl;
	std::cout << "\n";
	std::cout << "Blade is a card game where two players takes turns placing" << std::endl;
	std::cout << "numbered cards on the field and to have the highest sum total. " << std::endl;
	std::cout << "\n";
	std::cout << "Once both players hands have been dealt, both players" << std::endl;
	std::cout << "draw a card from their decks and place it on the field " << std::endl;
	std::cout << "\n";
	std::cout << "The player who draws the lower number must then proceed" << std::endl;
	std::cout << "to place a card from their hand onto the field. " << std::endl;
	std::cout << "\n";
	std::cout << "The player who goes second must then play card with " << std::endl;
	std::cout << "a value higher then their opponent's current total. " << std::endl;
	std::cout << "\n";
	std::cout << "Should both players have total at any point, the field is " << std::endl;
	std::cout << "cleared and both players must draw card from their deck to start over." << std::endl;
	std::cout << "\n";
	std::cout << "If the final of the game is used to clear the field," << std::endl;
	std::cout << "the match will result in a draw." << std::endl;
	std::cout << "\n";
	std::cout << "----------------------------------------------------------------------------";
	std::cout << "\n";
	std::cout << "\n";

}

void showCardTypes(){
	//Show the blade card types
	std::cout << "Blade Cards Types:" << std::endl;
	std::cout << "\n";
	std::cout << "There are three types of cards in Blade" << std::endl;
	std::cout << "\n";
	std::cout << "Blade cards are the most common. They're numbered from 1 to 7." << std::endl;
	std::cout << "\n";
	std::cout << "Bolt cards -[B]- remove the last card that your opponent placed on the field" << std::endl;
	std::cout << "\n";
	std::cout << "As a special rule, a Blade card with a value of 1 can be used to bring" << std::endl;
	std::cout << "back a card removed by the use of a Bolt card." << std::endl;
	std::cout << "\n";
	std::cout << "Mirror cards -[M]- are used to switch the positions of the cards currently " << std::endl;
	std::cout << "placed on the field." << std::endl;
	std::cout << "\n";
	std::cout << "Bolt and Mirror cards each have a value of 1 if they are the first card" << std::endl;
	std::cout << "to be placed on the field" << std::endl;
	std::cout << "\n";
	std::cout << "But be careful--using a Bolt or Mirror card as your last move is considered " << std::endl;
	std::cout << "a foul, and will cost you the match." << std::endl;
	std::cout << "\n";
	std::cout << "----------------------------------------------------------------------------";
	std::cout << "\n";
	std::cout << "\n";
	std::cin.get();
}
