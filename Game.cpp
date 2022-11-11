#include "Game.hpp"

Game::Game(int x, int y) : 
	_window(sf::VideoMode(x,y),"Action Map and Resource management"),_x(x),_y(y)
{
	_player.setPosition(100, 100);
}

void Game::run(int frame_per_seconds)
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	sf::Time TimerPerFrame = sf::seconds(1.f / frame_per_seconds);
	
	while (_window.isOpen())
	{
		processEvents();
		bool repaint = false;

		//fix time delta between frames
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimerPerFrame)
		{

			timeSinceLastUpdate -= TimerPerFrame;
			repaint = true;
			update(TimerPerFrame);
		}

		if (repaint)
			render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window.close();
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				_window.close();
			}
		}
	}
	_player.processEvents();
}

void Game::update(sf::Time deltaTime)
{
	_player.update(deltaTime);
	sf::Vector2f player_pos = _player.getPosition();
	if (player_pos.x < -30)
	{
		player_pos.x = _x;
		player_pos.y = _y - player_pos.y;
	}
	else if (player_pos.x > (_x + 30))
	{
		player_pos.x = 0;
		player_pos.y = _y - player_pos.y;
	}

	if (player_pos.y < -30)
	{
		player_pos.y = _y;
	}
	else if (player_pos.y > _y+30)
	{
		player_pos.y = 0;
	}
	_player.setPosition(player_pos);
}

void Game::render()
{
	_window.clear();
	_window.draw(_player);
	_window.display();
}
