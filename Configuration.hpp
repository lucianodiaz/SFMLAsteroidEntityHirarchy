#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "ActionMap.hpp"
#include "Player.hpp"


class Configuration
{
public:
	//this class It would be  static class so we don't need any constructor or copy constructor
	Configuration() = delete;
	Configuration(const Configuration&) = delete;
	Configuration& operator=(const Configuration&) = delete;
	//

	enum Textures : int {
		Player,
		PlayerLife,
		BigSaucer,
		SmallSaucer,
		BigMeteor1,
		BigMeteor2,
		BigMeteor3,
		BigMeteor4,
		MediumMeteor1,
		MediumMeteor2,
		SmallMeteor1,
		SmallMeteor2,
		SmallMeteor3,
		SmallMeteor4,
		ShootPlayer,
		ShootSaucer,
	};
	static ResourceManager<sf::Texture, int> textures;

	enum PlayerInputs : int
	{
		Up,
		Left,
		Right,
		Shoot,
		Hyperspace
	};
	static ActionMap<int> playerInputs;

	enum Sounds: int 
	{
		LaserPlayer,
		LaserEnemy,
		SaucerSpawn1,
		SacuerSpawn2,
		Boom,
		Boom2,
		Explosion1,
		Explosion2,
		Explosion3,
		Jump
	};
	static ResourceManager<sf::SoundBuffer, int>sounds;
	

	enum Musics : int
	{
		MainTheme
	};
	static ResourceManager<sf::Music, int> musics;

	static void initialize();

	static void addScore(int points);
	static int getScore();

	static world::Player* player;
	static int level;
	static int lives;


	static void draw(sf::RenderTarget& target);

private:
	static int _score;
	static sf::Text	_txt_score;
	static sf::Sprite _spr_life;

	static void initTextures();
	static void initFonts();
	static void initSounds();
	static void initMusics();
	

	static void initPlayerInputs();
};

