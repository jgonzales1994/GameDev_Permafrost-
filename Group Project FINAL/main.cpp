/****************************************************************
File: main.cpp
Description: Main program loop execution that stitches other classes
together.

Author: Michael Martinez, Johnny Gonzales, Michael Strade
Class: CSCI 120
Date: 5/13/2015

I hereby certify that this program is entirely my own work.
*****************************************************************/

//Includes
#include "main.h"
#include "level.h"
#include "player.h"
#include "menu.h"
#include "mechanics.h"

// Namespace
using namespace AGK;

app App;
level Level1;
Player character;
Mechanics enemy;
Menu menu;
bool startGame = false;
bool zeroTimeLeft = false;
bool startTimer = false;
float totalTime = 0;
bool continue1 = false;
bool restart1 = false;
bool start1 = false; 
float loadSec = 0;
bool gameoverCheck = false;
bool instructionsShown = false;

void SetUpLevel(){
	Level1.GenerateStructures();
	enemy.LoadSnowmen();
	Level1.GenerateEnd();
	Level1.GenerateWarmth();
	character.LoadPlayer();
	enemy.SetFire();//Resets Particle trigger
	enemy.ResetTime();//Resets time
	agk::DeleteParticles(1);
	agk::DeleteParticles(16);
	agk::DeleteSprite(108);
}
void app::Begin(void){
	agk::SetVirtualResolution (1024, 768); 
	agk::SetWindowTitle("Permafrost"); // Sets Window Title
	agk::SetClearColor( 151,170,204 ); // light blue
	agk::SetSyncRate(60,0);
	agk::SetScissor(0,0,0,0);
	menu.LoadImages();
	menu.LoadSounds();
	//Loads Game aspects
	enemy.LoadIcicleEnemy();
	Level1.LoadBG();
	Level1.GenerateStart();
	Level1.GenerateDecorativeBlocks();
	Level1.BeginSnow();
	menu.MainMenuBegin(); // Main Menu Execution
}
void app::Loop (void){	
	loadSec = agk::GetFrameTime() + loadSec;
	Level1.LoopSnow();
	zeroTimeLeft = enemy.TimeUp();//Returns true to zeroTimeLeft once timer hits zero
	if (agk::GetVirtualButtonPressed(2)) {// Quit Button
		menu.EndGame();
	}
	if (character.CheckLife() == true){
		totalTime = agk::GetFrameTime() + totalTime;//Runs Total time counter
		enemy.CollectWarmth();
		enemy.IcicleDrop();
		enemy.RunTimer(true);
		enemy.MoveSnowmen();
		character.SetTotalTime(totalTime);//Passes total time into the player object to allow it to print
	}
	if (agk::GetVirtualButtonPressed(1)) { //Start Button
		agk::PlaySound(5);
		menu.LoadingScreen();
		start1 = true;
		loadSec = 0;
	}
	if (start1 == true &&  loadSec > 6){//Once load screen is finished
			if (instructionsShown == false){//Displays Instructions
				agk::DeleteSprite(46);//Deletes LoadScreen
				agk::DeleteSprite(47);
				agk::DeleteSprite(5);
				menu.ShowInstructions();
				if (agk::GetVirtualButtonPressed(6)){//Makes sure intro screen is shown only once
					agk::DeleteVirtualButton(6);
					agk::DeleteSprite(48);
					instructionsShown = true;
				}
			}
			else if (instructionsShown == true){
				SetUpLevel();
				agk::DeleteSprite(46);//Deletes LoadScreen
				agk::DeleteSprite(47);
				agk::DeleteSprite(5);
				agk::StopMusic();
				agk::PlayMusic(2, 1);
				enemy.AnimateWarmthBar(true);//Allows warmth to begin decreasing
				startGame = true;//Allows movement after Start button is pressed
				start1 = false;
			}
	}
	else if (startGame){//Begins movement after button sets bool startGame to true
			character.PlayerMove();
			if (character.PlayerDeath(zeroTimeLeft) == true && gameoverCheck == false){
				menu.GameOverBegin();
				gameoverCheck = true;
			}
	}
	//Game Over Menu
	if (agk::GetVirtualButtonPressed(3)) { // Restart Button
		agk::PlaySound(4);
		menu.LoadingScreen();
		restart1 = true;
		loadSec = 0;
	}
	if (restart1 == true && loadSec > 6){
		SetUpLevel();
		agk::DeleteSprite(46);//Deletes LoadScreen
		agk::DeleteSprite(47);
		agk::DeleteSprite(5);
		agk::DeleteSprite(5); // Deletes death sprite animation
		agk::SetSpriteVisible(4, 1); // Makes player visible again
		enemy.ResetVictoryCount();
		//Reset Music and Particles
		agk::StopMusic();
		agk::PlayMusic(2, 1);
		//Reset Enemies
		enemy.EnemyPhysicsOff();//Resets enemy physics
		enemy.LoadIcicleEnemy();
		//Reset timer/warmth functions
		totalTime = 0;//Resets total time
		enemy.RunTimer(true);//Runs timer
		enemy.AnimateWarmthBar(true);//Runs warmth bar
		//Etc. Functions
		character.playCount = 0;
		character.isAlive = true;//Allows movement after Start button is pressed
		//Reset Player		
		agk::SetSpritePhysicsOn(4, 2);
		restart1 = false;
		gameoverCheck = false;
	}
	if (agk::GetSpriteX(4) >= Level1.GetFinishLine() && startGame == true){//Ends Level
			enemy.VictoryCountUp();//Increments difficulty with each clear
			enemy.AnimateWarmthBar(false);
			character.DisplayTimeSurvived();
			Level1.PlayFireWorks(Level1.GetFinishLine());
			startGame = false;
			enemy.RunTimer(false);
			character.isAlive = false;
			agk::PlayMusic(4);
			menu.Continue();//Loads Continue Button
	}
	if (agk::GetVirtualButtonPressed(5)) { // Continue Button
		agk::PlaySound(5);
			menu.LoadingScreen();
			continue1 = true;
			loadSec = 0;
	}	
	if (continue1 == true && loadSec > 6){
				SetUpLevel();
				agk::DeleteSprite(46);//Deletes LoadScreen
				agk::DeleteSprite(47);
				agk::DeleteSprite(5);
				//Reset Music and Particles
				agk::StopMusic();
				agk::PlayMusic(2, 1);
				//Reset Enemies
				enemy.EnemyPhysicsOff();//Resets enemy physics
				enemy.LoadIcicleEnemy();
				//Reset timer/warmth functions
				enemy.RunTimer(true);//Runs timer
				enemy.AnimateWarmthBar(true);//Runs warmth bar
				character.isAlive = true;//Allows movement after Start button is pressed
				//Reset Player	
				agk::SetSpritePhysicsOn(4, 2);
				continue1 = false;
				startGame = true;
			}
	agk::Sync();//Keeps the loop running
}

void app::End (void)
{

}