#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Player.hpp"

class Game
{
public:
	Game(int x=800,int y=600);

	//Run with fixed Time Steps 30FPS
	void run(int frame_per_seconds);
private:

	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	const int _x, const _y;

	sf::RenderWindow _window;
	Player  _player;
};

