/****************************************************************
File: menu.h
Description: Resources for menus (start menu, game over menu, 
stage cleared menu, and loading screen). Also loads file images 
and audio resources for rest of the program.

Author: Michael Martinez, Johnny Gonzales, Michael Strade
Class: CSCI 120
Date: 5/13/2015

I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef MENU_H
#define MENU_H

#include "AGK.h"
#include "main.h"
#include "level.h"

class Menu {
public:
	Menu::Menu(){
		fire = 1;
	}
	void MainMenuBegin(){
		agk::PlayMusic(1, 1);
		agk::CreateSprite(48,225);
		agk::SetSpritePosition(48, 150, 150);
		agk::SetSpriteDepth(48,1);
		agk::AddVirtualButton(1, 512, 480, 200); // start button
		agk::SetVirtualButtonImageUp(1, 101); // Start Button
		agk::AddVirtualButton(2, 512, 674, 200); // quit button
		agk::SetVirtualButtonImageUp(2, 102); // Quit Button
	}
	void Continue(){
		agk::CreateSprite(31, 220);//IceBack Graphic
		agk::SetSpriteSize(31, 700, 300);
		agk::SetSpriteDepth(31, 1);
		agk::SetSpritePosition(31, 180, 100);
		agk::FixSpriteToScreen(31, 1);
		agk::CreateText(222, "Stage cleared!");
		agk::FixTextToScreen(222, 1);
		agk::SetTextFontImage(222, 221);
		agk::SetTextSize(222, 70);
		agk::SetTextPosition(222, 230, 130);
		agk::SetTextColor(222, 0, 0, 0, 255);
		agk::SetTextDepth(222, 1);
		agk::AddVirtualButton(5, 390, 680, 130); 
		agk::SetVirtualButtonImageUp(5, 222); 
		agk::AddVirtualButton(2, 570, 680, 130); // quit button
		agk::SetVirtualButtonImageUp(2, 102); // Quit Button
	}
	void GameOverBegin() {
		agk::CreateParticles(16, 0, 0);
		agk::PlayMusic(3, 1);
		agk::SetParticlesImage(16, 16);
		agk::SetSpriteVisible(4, 0); // Sets current player invisible for death animation
		// Creates death sprite animation
		agk::CreateSprite(5, 5);
		agk::SetSpriteDepth(5, 1);
		float xOff = agk::GetSpriteX(4);
		float yOff = agk::GetSpriteY(4);
		agk::SetSpritePosition(5, xOff, yOff);
		agk::SetSpriteAnimation(5, 32, 32, 5);
		agk::PlaySprite(5, 10, 1, 1, 5);
		if (fire == 1){//Generates Warmth particle effect upon death
			agk::SetParticlesPosition(16, agk::GetSpriteX(4), agk::GetSpriteY(4));
			agk::ResetParticleCount(16);
			agk::SetParticlesFrequency(16, 255);
			agk::SetParticlesLife(16, 1.0);
			agk::SetParticlesSize(16, 40);
			agk::SetParticlesStartZone(16, -0, 0, 10, 0);
			agk::SetParticlesImage(16, 16);
			agk::SetParticlesDirection(16, 10, 10);
			agk::SetParticlesAngle(16, 360);
			agk::SetParticlesVelocityRange(16, 1, 30);
			agk::SetParticlesMax(16, 500);
			agk::AddParticlesColorKeyFrame(16, 0, 255, 222, 11, 255);
			agk::AddParticlesColorKeyFrame(16, 1, 222, 0, 0, 255);
			agk::AddParticlesColorKeyFrame(16, 2, 200, 80, 33, 255);
			agk::AddParticlesColorKeyFrame(16, 3, 255, 0, 0, 255);
			agk::AddParticlesForce(2, 2.0, 2.8, 25, -25);
			agk::SetParticlesDepth(16, 2);
			fire = 0;
		}
		if (agk::GetParticlesMaxReached(16))		{
			fire = 1;
		}
		agk::CreateSprite(108, 107); //GameOver graphic
		agk::SetSpriteDepth(108, 1);
		agk::SetSpritePositionByOffset(108, 512, 310);
		agk::FixSpriteToScreen(108, 1);
		agk::AddSpriteAnimationFrame(108, agk::LoadImage("GameOver01.png"));
		agk::AddSpriteAnimationFrame(108, agk::LoadImage("GameOver02.png"));
		agk::AddSpriteAnimationFrame(108, agk::LoadImage("GameOver03.png"));
		agk::AddSpriteAnimationFrame(108, agk::LoadImage("GameOver04.png"));
		agk::AddSpriteAnimationFrame(108, agk::LoadImage("GameOver05.png"));
		agk::PlaySprite(108, 10, 1, 1, 5);
		agk::AddVirtualButton(3, 400, 680, 150); // restart button
		agk::SetVirtualButtonImageUp(3, 103); // Restart Button
		agk::AddVirtualButton(2, 560, 678, 140); // quit button
		agk::SetVirtualButtonImageUp(2, 102); // Quit Button
	}
	void LoadSounds(){//Loads all sound and music used
		agk::SetFolder("/media");//Sets folder to the media folder that's in the same folder as the executable file
		//Music
		agk::LoadMusic(1, "Start2.mp3");
		agk::LoadMusic(2, "BGM2.mp3");
		agk::LoadMusic(3, "DeathTheme.mp3");
		agk::LoadMusic(4, "LevelWonTheme2.mp3");
		//Sounds
		agk::LoadSound(1, "Jump2.wav");
		agk::LoadSound(2, "Game_Over.wav");
		agk::LoadSound(3, "Jingle1.wav");
		agk::LoadSound(4, "Jingle2.wav");
		agk::LoadSound(5, "Jingle3.wav");
		agk::LoadSound(6,"Damage1.wav");
		agk::LoadSound(7,"Damage2.wav");
		agk::LoadSound(8,"IceDrop1.wav");
		agk::LoadSound(9, "IceDrop2.wav");
	}
	void LoadImages(){//Loads all images used
		agk::SetFolder("/media");//Sets folder to the media folder that's in the same folder as the executable file
		agk::LoadImage(1, "background.png");
		agk::LoadImage(3, "snowball.png");
		agk::LoadImage(4, "player.png");
		agk::LoadImage(5, "Player_freeze.png");
		agk::LoadImage(16, "shrapnel3.png");
		agk::LoadImage(20, "icicle01.png");
		agk::LoadImage(101, "start.png"); // Start Button Image
		agk::LoadImage(102, "quit.png"); // Quit Button Image
		agk::LoadImage(103, "restart.png"); // Restart Button Image
		agk::LoadImage(104, "quit.png"); // Quit Button Image
		agk::LoadImage(107, "GameOver01.png"); // Game Over Image
		agk::LoadImage(201, "iceblock.png");
		agk::LoadImage(202, "brick01.png");
		agk::LoadImage(203, "brick02.png");
		agk::LoadImage(204, "brick04.png");
		agk::LoadImage(205, "tree01.png");
		agk::LoadImage(206, "ceiling01.png");
		agk::LoadImage(207, "ceiling02.png");
		agk::LoadImage(208, "ceiling03.png");
		agk::LoadImage(209, "ceiling04.png");
		agk::LoadImage(210, "Mountain Ledges.png");
		agk::LoadImage(211, "1 side hill.png");
		agk::LoadImage(212, "plateau ledges.png");
		agk::LoadImage(213, "flat ledges.png");
		agk::LoadImage(214, "start ledge.png");
		agk::LoadImage(215, "snowman_small.png");
		agk::LoadImage(216, "snowman.png");
		agk::LoadImage(217, "bush.png");
		agk::LoadImage(218, "end ledge.png");
		agk::LoadImage(219, "igloo.png");
		agk::LoadImage(220, "TextBack.png");
		agk::LoadImage(221, "custom.png");
		agk::LoadImage(222, "continue.png");
		agk::LoadImage(223, "LoadingCircle1.png");
		agk::LoadImage(224, "LoadScreen.png");
		agk::LoadImage(225, "title.png");
		agk::LoadImage(226, "load2.png");
		agk::LoadImage(227, "instructions.png");
		agk::LoadImage(300, "warmth_source.png");
	}
	void ShowInstructions(){
		agk::CreateSprite(48, 227);
		agk::SetSpritePosition(48, 150, 140);
		agk::SetSpriteDepth(48, 0);

		agk::AddVirtualButton(6, 520, 600, 300);
		agk::SetVirtualButtonImageUp(6, 222);
	}
	void LoadingScreen(){
		agk::DeleteVirtualButton(1);
		agk::DeleteVirtualButton(2);//Deletes quit button
		agk::DeleteVirtualButton(3);
		agk::DeleteVirtualButton(5);
		agk::DeleteSprite(30);
		agk::DeleteSprite(31);
		agk::DeleteText(220);
		agk::DeleteText(221);
		agk::DeleteText(222);
		agk::DeleteSprite(48);//Deletes title

		agk::CreateSprite(5, 5); //Sprite animation for Loading Screen
		agk::SetSpriteDepth(5, 0);
		agk::SetSpritePosition(5, 40, 560);
		agk::SetSpriteSize(5, 150, -1);
		agk::FixSpriteToScreen(5, 1);
		agk::SetSpriteAnimation(5, 32, 32, 5);
		agk::PlaySprite(5, 10, 1, 1, 5);

		int loadingNum = agk::Random(0, 1);
		if (loadingNum == 0){
			agk::CreateSprite(47, 224);//Load Screen Sprite
			agk::FixSpriteToScreen(47, 1);
			agk::SetSpritePosition(47, 0, 0);
			agk::SetSpriteDepth(47, 1);
		}
		
		else if (loadingNum == 1){
			agk::CreateSprite(47, 226);//Load1 Screen Sprite
			agk::FixSpriteToScreen(47, 1);
			agk::SetSpritePosition(47, 0, 0);
			agk::SetSpriteDepth(47, 1);
		}
		agk::CreateSprite(46, 223); //LoadCircle Display
		agk::SetSpriteDepth(46, 1);
		agk::SetSpriteSize(46, 100, -1);
		agk::SetSpritePosition(46, 900, 650);
		agk::FixSpriteToScreen(46, 1);
		agk::AddSpriteAnimationFrame(46, agk::LoadImage("LoadingCircle1.png"));
		agk::AddSpriteAnimationFrame(46, agk::LoadImage("LoadingCircle2.png"));
		agk::AddSpriteAnimationFrame(46, agk::LoadImage("LoadingCircle3.png"));
		agk::AddSpriteAnimationFrame(46, agk::LoadImage("LoadingCircle4.png"));
		agk::AddSpriteAnimationFrame(46, agk::LoadImage("LoadingCircle5.png"));
		agk::AddSpriteAnimationFrame(46, agk::LoadImage("LoadingCircle6.png"));
		agk::AddSpriteAnimationFrame(46, agk::LoadImage("LoadingCircle7.png"));
		agk::AddSpriteAnimationFrame(46, agk::LoadImage("LoadingCircle8.png"));
		agk::PlaySprite(46, 40, 1, 0, 8);
	}
	void EndGame(){
		exit(1);
	}
	

private:
	int fire;
};

#endif