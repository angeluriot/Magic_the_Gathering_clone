#include "Game.hpp"
#include "renderer/print.hpp"
#include "utils/PtrList.hpp"
#include "cards/creatures/blacks/LavaHound.hpp"
#include "cards/creatures/blacks/Pekka.hpp"
#include "cards/creatures/blues/IceWizard.hpp"
#include "cards/creatures/greens/ElectroGiant.hpp"
#include "cards/creatures/greens/Golem.hpp"
#include "cards/creatures/greens/RoyalGiant.hpp"
#include "cards/creatures/whites/MegaKnight.hpp"
#include "cards/lands/Forest.hpp"
#include "cards/lands/Island.hpp"
#include "cards/lands/Plain.hpp"
#include "cards/lands/Swamp.hpp"
#include "utils/utils.hpp"
#include "utils/files.hpp"
#include <filesystem>

Player player_1;
Player player_2;
std::array<Player, 2> Game::players = { player_1, player_2 };
int Game::turn = 0;
const int Game::deck_size = 30;

void Game::start()
{
	for (int i = 0; i < 2; i++)
	{
		std::string name = input(to_str(bold) + to_str(magenta) + "Player " + to_str(i + 1) + to_str(reset) + " name:");
		name = remove_spaces(name);
		players[i].set_name(name == "" ? "Player " + to_str(i + 1) : name);
	}

	if (players[0].get_name() == players[1].get_name())
		players[1].set_name(players[1].get_name() + " (2)");

	std::cout << End(1);
}

void Game::create_decks()
{
	if (!std::filesystem::exists("decks"))
		print_error("No decks directory.");

	auto files = get_decks_name();

	if (files.size() == 0)
		print_error("No decks found.");

	for (auto& player : players)
	{
		std::cout << magenta << bold << player.get_name() << reset << ", which deck do you want to use?" << End(1);
		int res = choice(files);
		auto cards = Card::get_cards_from_string(get_cards_from_deck(files[res]));
		player.create_deck(cards);
	}
}

void Game::play()
{
	while (true)
	{
		for (auto& player : players)
		{
			if (player.is_alive())
			{
				if (player.get_opponent().is_alive())
					player.begin_turn();
				else
				{
					std::cout << magenta << bold << player.get_opponent().get_name() << reset << " has lost!" << End(1);
					std::cout << magenta << bold << player.get_name() << reset << " wins this game!" << End(1);
					return;
				}
			}

			else
			{
				std::cout << magenta << bold << player.get_name() << reset << " has lost!" << End(1);
				std::cout << magenta << bold << player.get_opponent().get_name() << reset << " wins this game!" << End(1);
				return;
			}
		}
	}
}
