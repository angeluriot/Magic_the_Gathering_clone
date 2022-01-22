#ifndef GAME_HPP
#define GAME_HPP

#include <array>
#include "players/Player.hpp"

class Game
{
public:

	static std::array<Player, 2> players;
	static const int deck_size;

	static void reset_game();
	static void start();
	static void create_decks();
	static void play();
};

#endif
