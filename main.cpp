#include "Game.hpp"
#include "Configuration.hpp"

int main()
{
	Configuration::initialize();
	Game game;
	//Run with fixed minum step
	game.run(30);

	return 0;
}