//Audio takes care of any sounds/music used in the game
//
//TODO:
//-> Make the music play based on the scene when new scenes are made
//-> Don't forget to set all sounds to 100.f when game is finished and settings widgets are finished

using namespace std;
#include "Audio.hpp"

///////////////////////////////////////////////////////////////
/* Private Functions */
void Audio::initVariables()
{
	MusicPlaylist = { 1, 2, 3, 4 };
	i = MusicPlaylist.size();

	HoverSoundIterator = 0;
	currSong = 0;
	initMusic = 1;

	MusicVolume = 10.f;
	Song.setVolume(MusicVolume);

	SFXVolume = 10.f;
}

void Audio::initSounds()
{

	/* Initializing Click Sounds */
	this->buffer.loadFromFile("content/audio/SFX/ClickSFX.ogg");
	this->buffers.push_back(this->buffer);
	this->Sound.setVolume(10.f);
	this->Sounds.push_back(this->Sound);

	/* Initializing Hover Sounds */
	this->buffer.loadFromFile("content/audio/SFX/HoverSFX.ogg");
	this->buffers.push_back(this->buffer);
	this->Sound.setVolume(10.f);
	this->hoverSounds.push_back(this->Sound);
	this->hoverSounds.push_back(this->Sound);
	this->hoverSounds.push_back(this->Sound);
	this->hoverSounds.push_back(this->Sound);

	this->Sounds[SFXClick].setBuffer(this->buffers[SFXClickBuffer]);

	this->hoverSounds[HoverSound0].setBuffer(this->buffers[SFXHoverBuffer]);
	this->hoverSounds[HoverSound1].setBuffer(this->buffers[SFXHoverBuffer]);
	this->hoverSounds[HoverSound2].setBuffer(this->buffers[SFXHoverBuffer]);
	this->hoverSounds[HoverSound3].setBuffer(this->buffers[SFXHoverBuffer]);
}

void Audio::initSongs()
{
	songLocation = "content/audio/Music/TheGreatBattle.ogg";
	this->Songs.push_back(songLocation);
	songLocation = "content/audio/Music/Greenlands.ogg";
	this->Songs.push_back(songLocation);
	songLocation = "content/audio/Music/BattleOfTheCreek.ogg";
	this->Songs.push_back(songLocation);
	songLocation = "content/audio/Music/HymmToTheGods.ogg";
	this->Songs.push_back(songLocation);
	songLocation = "content/audio/Music/VeturFrosti.ogg";
	this->Songs.push_back(songLocation);
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
/* Functions */
void Audio::playSFXClick()
{
	this->Sounds[SFXClick].play();
}

void Audio::playSFXHover()
{
	switch (HoverSoundIterator)
	{
		case (0):
			this->hoverSounds[HoverSound0].play();
			HoverSoundIterator += 1;
			break;
		case (1):
			this->hoverSounds[HoverSound1].play();
			HoverSoundIterator += 1;
			break;
		case (2):
			this->hoverSounds[HoverSound2].play();
			HoverSoundIterator += 1;
			break;
		case (3):
			this->hoverSounds[HoverSound3].play();
			HoverSoundIterator = 0;
			break;
		default:
			this->hoverSounds[HoverSound0].play();
			HoverSoundIterator = 1;
			break;
	}
}

void Audio::setVolume(int MasterVol, int SFXVol, int MusicVol, int EffectsVol)
{
	MasterMultiplier = MasterVol / 200.f;

	//Setting SFX sounds
	SFXMultiplier = SFXVol * MasterMultiplier;
	this->Sounds[SFXClick].setVolume(SFXMultiplier);
	this->hoverSounds[HoverSound0].setVolume(SFXMultiplier);
	this->hoverSounds[HoverSound1].setVolume(SFXMultiplier);
	this->hoverSounds[HoverSound2].setVolume(SFXMultiplier);
	this->hoverSounds[HoverSound3].setVolume(SFXMultiplier);

	//Setting Song sounds
	MusicMultiplier = MusicVol * MasterMultiplier;
	Song.setVolume(MusicMultiplier);

	//Setting Effects sounds
	EffectsMultiplier = EffectsVol * MasterMultiplier;

	//For debugging purposes
	//cout << SFXMultiplier << " " << MusicMultiplier << " " << EffectsMultiplier << endl;
}

void Audio::MuteAllSounds()
{
	Song.setVolume(0.f);
	this->Sounds[SFXClick].setVolume(0.f);
	this->hoverSounds[HoverSound0].setVolume(0.f);
	this->hoverSounds[HoverSound1].setVolume(0.f);
	this->hoverSounds[HoverSound2].setVolume(0.f);
	this->hoverSounds[HoverSound3].setVolume(0.f);
}

void Audio::UnmuteAllSounds()
{
	Song.setVolume(MusicVolume);
	this->Sounds[SFXClick].setVolume(SFXVolume);
	this->hoverSounds[HoverSound0].setVolume(SFXVolume);
	this->hoverSounds[HoverSound1].setVolume(SFXVolume);
	this->hoverSounds[HoverSound2].setVolume(SFXVolume);
	this->hoverSounds[HoverSound3].setVolume(SFXVolume);
}

void Audio::update(int currScene)
{
	/* First Song that plays the moment the game opens is always The Great Battle */
	if (initMusic == 1)
	{
		this->Song.openFromFile(Songs[0]);
		this->Song.play();
		initMusic = 0;
	}
	/* Plays Music List if in any of the main menu scenes */
	if (currScene <= 5)
	{
		/* getStatus() returns 0 if stopped, 1 if paused, and 2 if playing */
		if (Song.getStatus() != 2)
		{
			if (i > 0)
			{
				/* Shuffles Soundtrack */
				currSong = rand() % i;
				this->Song.openFromFile(Songs[MusicPlaylist[currSong]]);
				MusicPlaylist.erase(MusicPlaylist.begin() + currSong);
				i--;
				this->Song.play();
			}
			else
			{
				MusicPlaylist = { 0, 1, 2, 3, 4 };
				i = MusicPlaylist.size();
				currSong = rand() % i;
				this->Song.openFromFile(Songs[MusicPlaylist[currSong]]);
				MusicPlaylist.erase(MusicPlaylist.begin() + currSong);
				i--;
				this->Song.play();
			}
		}
	}
}

void Audio::init(int MasterVol, int SFXVol, int MusicVol, int EffectsVol)
{
	this->initVariables();
	this->initSounds();
	this->initSongs();
	this->setVolume(MasterVol, SFXVol, MusicVol, EffectsVol);
}
///////////////////////////////////////////////////////////////