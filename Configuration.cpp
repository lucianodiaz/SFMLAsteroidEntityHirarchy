#include "Configuration.hpp"
#include "Random.hpp"

ResourceManager<sf::Texture, int> Configuration::textures;
ActionMap<int> Configuration::playerInputs;
void Configuration::initialize()
{
	initTextures();
	initPlayerInputs();
	
	rand_init();
}

void Configuration::addScore(int points)
{
}

int Configuration::getScore()
{
	return 0;
}

void Configuration::initTextures()
{
	textures.load(Textures::Player, "media/Player/Ship.png");
}

void Configuration::initPlayerInputs()
{
	playerInputs.map(PlayerInputs::Up, Action(sf::Keyboard::W));
	playerInputs.map(PlayerInputs::Right, Action(sf::Keyboard::D));
	playerInputs.map(PlayerInputs::Left, Action(sf::Keyboard::A));
	playerInputs.map(PlayerInputs::Shoot, Action(sf::Keyboard::Space));
	playerInputs.map(PlayerInputs::Hyperspace, Action(sf::Keyboard::LShift));

}

void Configuration::draw(sf::RenderTarget& target)
{
}

void Configuration::initFonts()
{
}

void Configuration::initSounds()
{
}

void Configuration::initMusics()
{
}
