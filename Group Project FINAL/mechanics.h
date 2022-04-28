/****************************************************************
File: mechanics.h
Description: Resources for program gameplay to execute correctly.
Handles processes having to do with enemy behavior as well as 
handling time related operations.

Author: Michael Martinez, Johnny Gonzales, Michael Strade
Class: CSCI 120
Date: 5/13/2015

I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef MECHANICS_H
#define MECHANICS_H

#include "AGK.h"

class Mechanics{
public:
	Mechanics::Mechanics(){
		timeNum = 25;
		snowmanSpeed1 = 100;
		snowmanSpeed2 = 100;
		victory = 0;
	}
	void RunTimer(bool on){
		if (on == true){
			timeNum = timeNum - agk::GetFrameTime();
		}
		else{}
	}
	void ResetTime(){
		timeNum = 25;
	}
	bool TimeUp(){
		if (timeNum < 0){
			return true;
		}
		else{
			return false;
		}
	}
	void AddTime(){
		timeNum += 5;
	}
	void DecreaseTime(){
		timeNum -= 5;
	}
	void CollectWarmth(){
		for (int i = 9000; i < 9100; ++i) {
			if (agk::GetSpriteCollision(4, i)) { // Deletes warmth source when player comes in contact
				agk::PlaySound(3);
				if ((agk::GetSpriteCurrentFrame(302) - 9) < 1){
					agk::SetSpriteFrame(302, 1);
					timeNum = 25;
				}
				else{
					agk::SetSpriteFrame(302, agk::GetSpriteCurrentFrame(302) - 9);
					AddTime();					
				}
				agk::DeleteSprite(i);
			}
		}
	}
	void AnimateWarmthBar(bool on){
		if (on == true){
			agk::SetFolder("/media/warmth bar v2");//Sets folder to the media folder that's in the same folder as the executable file
			agk::LoadImage(301, "warmth_bar100.png");
			agk::CreateSprite(302, 301); // Warmth Bar Display
			agk::SetSpriteDepth(302, 1);
			agk::SetSpritePositionByOffset(302, 870, 100);
			agk::FixSpriteToScreen(302, 1);
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar100.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar98.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar96.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar94.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar92.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar90.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar88.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar86.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar84.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar82.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar80.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar78.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar76.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar74.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar72.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar70.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar68.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar66.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar64.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar62.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar60.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar58.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar56.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar54.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar52.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar50.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar48.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar46.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar44.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar42.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar40.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar38.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar36.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar34.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar32.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar30.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar28.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar26.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar24.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar22.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar20.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar18.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar16.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar14.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar12.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar10.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar8.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar6.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar4.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar2.png"));
			agk::AddSpriteAnimationFrame(302, agk::LoadImage("warmth_bar0.png"));
			agk::PlaySprite(302, 2, 0, 0, 51);
		}
		else{
			agk::StopSprite(302);
		}
	}
	void LoadIcicleEnemy(){
		//agk::SetPhysicsDebugOn();
		agk::SetFolder("/media");//Sets folder to the media folder that's in the same folder as the executable file
		float icicleX = 780;
		for (int i = 10000; i < 10027; i++){//Generates  icicle enemy sprites
			agk::CreateSprite(i, 20);
			agk::SetSpriteDepth(i, 1);
			agk::SetSpriteSize(i, 40, 300);
			agk::SetSpriteShape(i, 3);
			agk::SetSpritePosition(i, icicleX, 80);
			icicleX += agk::Random(300.0, 350.0);
		}
		for (int i = 10000; i <10027; ++i){
			soundPlayed[i] = false;
		}
	}
	void LoadSnowmen(){
		//Loop Spawns snowmen based on where blocks are placed
		if (victory >= 2){
			for (int i = 5050; i < 5071; ++i){
				int tempSpriteNum = agk::Random(3049, 3164);
				agk::CreateSprite(i, 215);
				agk::SetSpriteSize(i, 40, -1);
				agk::SetSpritePhysicsOn(i);
				agk::SetSpritePosition(i, agk::GetSpriteX(tempSpriteNum), agk::GetSpriteY(tempSpriteNum) - 300);//Places snowmen randomly at x coordinate of ice blocks from sprites 3049 to 3164
				agk::SetSpritePhysicsCanRotate(i, 0);
				agk::SetSpriteShape(i, 3);
			}
		}
		//Loads Giant Snowman
		if (victory >= 1){
			agk::CreateSprite(5049, 216);
			agk::SetSpriteSize(5049, 340, -1);
			agk::SetSpritePhysicsOn(5049);
			agk::SetSpritePosition(5049, 40, 200);
			agk::SetSpritePhysicsCanRotate(5049, 0);
			agk::SetSpriteShape(5049, 3);
			agk::SetSpriteDepth(5049, 1);
		}
	}
	void MoveSnowmen(){
		SpeedUp();//Modifies speed according to level clears
		//Giant Snowman Movement
		if (victory >= 1){
			if (agk::GetSpriteX(4) > agk::GetSpriteX(5049)){
				agk::SetSpritePhysicsVelocity(5049, snowmanSpeed1, agk::GetSpritePhysicsVelocityY(5049));
			}
			if (agk::GetSpriteX(4) < agk::GetSpriteX(5049)){
				agk::SetSpritePhysicsVelocity(5049, -snowmanSpeed1, agk::GetSpritePhysicsVelocityY(5049));
			}

			if (agk::GetSpriteY(4) > agk::GetSpriteY(5049)){
				agk::SetSpritePhysicsVelocity(5049, agk::GetSpritePhysicsVelocityX(5049), snowmanSpeed1);
			}
			if (agk::GetSpriteY(4) < agk::GetSpriteY(5049)){
				agk::SetSpritePhysicsVelocity(5049, agk::GetSpritePhysicsVelocityX(5049), -snowmanSpeed1);
			}
		}
		//Giant Snowman Damage
		if (agk::GetSpriteCollision(4, 5049)){
			DamageParticles();
			timeNum = timeNum - 1;
			if (agk::GetSpriteCurrentFrame(302) != 50){
				agk::SetSpriteFrame(302, agk::GetSpriteCurrentFrame(302) + 2);
			}
		}
		// Movement loop for normal snowmen
		if (victory >= 2){
			for (int i = 5050; i < 5071; ++i){
				if (agk::GetSpriteX(4) > agk::GetSpriteX(i) - 100){//Should prevent movement of snowmen until player gets close
					if (agk::GetSpriteX(4) > agk::GetSpriteX(i)){
						agk::SetSpritePhysicsVelocity(i, snowmanSpeed2, agk::GetSpritePhysicsVelocityY(i));
					}
					if (agk::GetSpriteX(4) < agk::GetSpriteX(i)){
						agk::SetSpritePhysicsVelocity(i, -snowmanSpeed2, agk::GetSpritePhysicsVelocityY(i));
					}
					if (agk::GetSpriteY(4) > agk::GetSpriteY(i)){
						agk::SetSpritePhysicsVelocity(i, agk::GetSpritePhysicsVelocityX(i), +snowmanSpeed2);
					}
					if (agk::GetSpriteY(4) < agk::GetSpriteY(i)){
						agk::SetSpritePhysicsVelocity(i, agk::GetSpritePhysicsVelocityX(i), -snowmanSpeed2);
					}
				}
			}
		}
		//Small Snowmen damage
		for (int i = 5050; i < 5071; ++i){
			if (agk::GetSpriteCollision(4, i)){
				DamageParticles();
				timeNum = timeNum - 1;
				if (agk::GetSpriteCurrentFrame(302) != 50){
					agk::SetSpriteFrame(302, agk::GetSpriteCurrentFrame(302) + 2);
				}
			}
		}
	}
	void EnemyPhysicsOff(){
		for (int i = 10000; i < 10027; i++){//Turns enemy icicle physics off
			agk::SetSpriteAngle(i, 0);
			agk::SetSpritePhysicsOff(i);
		}
	}
	void IcicleDrop(){
		agk::SetFolder("/media");
		agk::LoadImage(15, "shrapnel3.png");
		agk::CreateParticles(1, 150, 10);
		agk::SetParticlesImage(1, 15);
		for (int i = 10000; i < 10027; i++){
			if (agk::GetSpriteX(4) >= agk::GetSpriteX(i)){
				agk::SetSpritePhysicsOn(i, 2);
				if ((agk::GetSpriteX(4) >= agk::GetSpriteX(i)) && soundPlayed[i] == false) {
					agk::PlaySound(9);
					soundPlayed[i] = true;
				}
				agk::SetSpritePhysicsVelocity(i,0,1000);
				if (agk::GetSpriteCollision(4, i)){ 
					DamageParticles();
					timeNum = timeNum - 1;
					if (agk::GetSpriteCurrentFrame(302) !=50){ //Decreases warmth bar
						agk::SetSpriteFrame(302, agk::GetSpriteCurrentFrame(302) + 2); 
					}
				}
			}
		}
	}
	void DamageParticles(){
		if (fire == 1){
			agk::SetParticlesPosition(1, agk::GetSpriteX(4), agk::GetSpriteY(4));
			agk::ResetParticleCount(1);
			agk::SetParticlesFrequency(1, 255);
			agk::SetParticlesLife(1, 1.0);
			agk::SetParticlesSize(1, 22);
			agk::SetParticlesStartZone(1, -10, 0, 10, 0);
			agk::SetParticlesImage(1, 1);
			agk::SetParticlesDirection(1, 10, 10);
			agk::SetParticlesAngle(1, 360);
			agk::SetParticlesVelocityRange(1, 1, 15);
			agk::SetParticlesMax(1, 200);
			agk::AddParticlesColorKeyFrame(1, 0.0, 255, 0, 0, 0);
			agk::AddParticlesColorKeyFrame(1, 0.5, 222, 222, 0, 255);
			agk::AddParticlesColorKeyFrame(1, 2.8, 255, 0, 255, 0);
			agk::AddParticlesForce(1, 2.0, 2.8, 25, -25);
			agk::PlaySound(6);
			agk::PlaySound(7);
			agk::PlaySound(6);
			fire = 0;
		}
		if (agk::GetParticlesMaxReached(1)){
			fire = 1;
		}
	}
	void SetFire(){
		fire = 1;
	}
	void SpeedUp(){
		if (victory == 3){
			snowmanSpeed1 = 200;
			snowmanSpeed2 = 150;
		}
		if (victory >= 4){
			snowmanSpeed1 = 300;
		}
	}
	void VictoryCountUp(){
		victory += 1;
	}
	void ResetVictoryCount(){
		victory = 0;
	}


private:
	bool soundPlayed[27];//Keeps track of sounds played or not
	int victory;//Keeps track of wins
	float snowmanSpeed1;
	float snowmanSpeed2;
	float timeNum;
	int fire = 1;
};

#endif

