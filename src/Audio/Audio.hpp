#ifndef AUDIO_HPP
#define AUDIO_HPP

using namespace std;
#include <iostream>
#include <vector>

/* Class containing all objects and functions related to Audio */

class Audio
{
	enum SoundList
	{
		SFXClick = 0,
	};
	enum HoverSoundList
	{
		HoverSound0 = 0,
		HoverSound1 = 1,
		HoverSound2 = 2,
		HoverSound3 = 3,
	};
	enum SoundBufferList
	{
		SFXClickBuffer = 0,
		SFXHoverBuffer = 1,
	};
	enum MusicList
	{
		TheGreatBattle = 0,
		Greenlands = 1,
		BattleOfTheCreek = 2,
		HymmToTheGods = 3,
		VeturFrosti = 4
	};

private:
	//Variables
	float MasterMultiplier;
	float SFXMultiplier;
	float MusicMultiplier;
	float EffectsMultiplier;
	bool musicPlaying = false;
	int currSong;
	int initMusic;
	int i;

	//Sound Objects
	vector<sf::SoundBuffer> buffers;
	sf::SoundBuffer buffer;

	vector<sf::Sound> Sounds;
	vector<sf::Sound> hoverSounds;
	sf::Sound Sound;

	//Private Functions
	void initVariables();
	void initSounds();
	void initSongs();

public:
	//Variables
	int HoverSoundIterator;
	vector<int> MusicPlaylist;
	float MusicVolume;
	float SFXVolume;

	//Songs
	vector<string> Songs;
	string songLocation;
	sf::Music Song;

	//Functions
	void playSFXClick();
	void playSFXHover();
	void setVolume(int MasterVol, int SFXVol, int MusicVol, int EffectsVol);
	void MuteAllSounds();
	void UnmuteAllSounds();
	void update(int currScene);
	void init(int MasterVol, int SFXVol, int MusicVol, int EffectsVol);
};

#endif