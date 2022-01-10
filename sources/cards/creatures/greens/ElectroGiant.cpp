#include "cards/creatures/greens/ElectroGiant.hpp"

ElectroGiant::ElectroGiant(): Creature(get_full_power(), get_full_toughness()) {}

std::string ElectroGiant::get_full_type() const
{
	return Creature::get_full_type() + " - Giant";
}

Card::Color ElectroGiant::get_color() const
{
	return Color::Green;
}

std::string ElectroGiant::get_name() const
{
	return "Electro Giant";
}

std::string ElectroGiant::get_description() const
{
	return "";
}

Card::Cost ElectroGiant::get_cost() const
{
	return
	{
		{ Color::Colorless, 5 },
		{ Color::Green, 3 }
	};
}

int ElectroGiant::get_full_power() const
{
	return 3;
}

int ElectroGiant::get_full_toughness() const
{
	return 7;
}
