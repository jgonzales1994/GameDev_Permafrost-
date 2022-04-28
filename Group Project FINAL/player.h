/****************************************************************
File: player.h
Description: Resources for player creation, movement, and life 
checking to determine if the player is alive or not.

Author: Michael Martinez, Johnny Gonzales, Michael Strade
Class: CSCI 120
Date: 5/13/2015

I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "AGK.h"
#include "menu.h"

class Player {
public:
	void LoadPlayer(){
		agk::CreateSprite(4, 4);
		agk::SetSpriteDepth(4, 1);
		agk::SetSpritePosition(4, 600, 575);
		agk::AddSpriteAnimationFrame(4, agk::LoadImage("player.png"));
		agk::AddSpriteAnimationFrame(4, agk::LoadImage("player_walk.png"));
		agk::AddSpriteAnimationFrame(4, agk::LoadImage("player_jump.png"));
		agk::SetSpritePhysicsOn(4, 2);
		agk::SetSpritePhysicsCanRotate(4, 0); 
		agk::SetSpriteShape(4, 3);
	}
	void DisplayTimeSurvived(){
		agk::CreateSprite(30,220);//IceBack Graphic
		agk::SetSpriteDepth(30, 1);
		agk::SetSpritePosition(30, 15, 425);
		agk::FixSpriteToScreen(30, 1);
			//TextObject 1
			agk::SetFolder("/media");
			agk::CreateText(221, "Time survived: ");
			agk::FixTextToScreen(221, 1);
			agk::SetTextFontImage(221, 221);
			agk::SetTextSize(221, 70);
			agk::SetTextPosition(221, 50, 450);
			agk::SetTextColor(221, 0, 0, 0, 255);
			agk::SetTextDepth(221, 1);
			//TextObject 2
			agk::CreateText(220, agk::Str(totalTime));
			agk::FixTextToScreen(220, 1);
			agk::SetTextFontImage(220, 221);
			agk::SetTextSize(220, 70);
			agk::SetTextPosition(220, 620, 450);
			agk::SetTextColor(220, 0, 222, 255, 255);
			agk::SetTextDepth(220, 1);
	}
	bool PlayerDeath(bool zeroTime){
		if (zeroTime == true) {
			isAlive = false;
			agk::StopMusic();
			if (playCount == 0){ //Makes sure gameover sound only plays once
				agk::ClearScreen(); agk::Swap();
				agk::PlaySound(2);
				playCount += 1;
				DisplayTimeSurvived();
			}
			agk::SetSpritePhysicsOff(4); // Stops players motion
			return true;
		}
		else if (agk::GetSpriteY(4) > 768){
			isAlive = false;
			Menu Game;
			agk::StopMusic();
			agk::SetSpriteFrame(302, 51);//Sets warmth bar to empty
			if (playCount == 0){
				DisplayTimeSurvived();
				agk::PlaySound(2);
				agk::ClearScreen(); agk::Swap();
				playCount += 1;
			}
			agk::SetSpritePhysicsOff(4); 
			return true;
		}
		else if (agk::GetSpriteY(4) < 768) {
			isAlive = true;
		}
	}
	void PlayerMove(){
		if (isAlive) {
			agk::SetViewOffset(agk::GetSpriteX(4) - 350, 0); // Scrolling screen
			if (agk::GetRawKeyState(37) ) {// Moves Sprite left or right (left/right arrow keys) (37, 39)
				agk::SetSpriteFlip(4, 1, 0);
				if (agk::GetRawKeyPressed(37)){agk::PlaySprite(4, 10, 1, 1, 2);}//(SPRITE ID, FRAMERATE,LOOP,STARTPOINT,ENDPOINT)
				agk::SetSpritePhysicsVelocity(4, (agk::GetRawKeyState(39) - agk::GetRawKeyState(37)) * 250, agk::GetSpritePhysicsVelocityY(4));
			}
			else if (agk::GetRawKeyState(39) ) {
				agk::SetSpriteFlip(4, 0, 0);
				if (agk::GetRawKeyPressed(39)){agk::PlaySprite(4, 10, 1, 1, 2);}
				agk::SetSpritePhysicsVelocity(4, (agk::GetRawKeyState(39) - agk::GetRawKeyState(37)) * 250, agk::GetSpritePhysicsVelocityY(4));
			}
			if (agk::GetRawKeyPressed(32) && CheckGroundCollision()) {// Makes Sprite jump with spacebar (32)
					agk::PlaySprite(4, 10, 1, 3, 3);
					agk::PlaySound(1); // Jump sound
					agk::SetSpritePhysicsVelocity(4, agk::GetSpritePhysicsVelocityX(4), -agk::GetRawKeyState(32) * 340.0);
			}
			if (agk::GetRawKeyReleased(32) && agk::GetSpritePhysicsVelocityX(4) > 0){//Returns sprite to running sprite if velocity of sprite was moving right
				agk::PlaySprite(4, 10, 1, 1, 2); 
			}
			else if (agk::GetRawKeyReleased(32) && agk::GetSpritePhysicsVelocityX(4) < 0){ //Returns sprite to running sprite if velocity of sprite was moving left
				agk::PlaySprite(4, 10, 1, 1, 2);
			}
			else if (agk::GetSpritePlaying(4) && (agk::GetRawKeyReleased(37) || agk::GetRawKeyReleased(39))) { // Sets sprite back to still frame
				agk::StopSprite(4); // Stops sprite animation
				agk::SetSpriteFrame(4, 1); // Sets sprite back to normal (not moving)
			}
		}
	}
	bool CheckGroundCollision(){
		for (int i = 3000; i < 3250; ++i){//Loop checks if the sprite is touching the ground, if true, allows a jump
			if (i >= 3020 && i <= 3025){}
			else{
				if (agk::GetSpriteCollision(4, i)){
					return true;
				}
			}
		}
		return false;
	}
	bool CheckLife(){
		return isAlive;
	}
	void SetTotalTime(float num){
		this->totalTime = num;
	}
	bool isAlive; // while true, it allows the player to move
	int playCount = 0;//Makes sure gameover sound plays once

private:
	float totalTime;
};


#endif