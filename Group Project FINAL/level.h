/****************************************************************
File: level.h
Description: Handles generation of all level related items such as
enemy, enviroment block, warmth sprite generation and placement, 
all of which are randomly generated.

Author: Michael Martinez, Johnny Gonzales, Michael Strade
Class: CSCI 120
Date: 5/13/2015

I hereby certify that this program is entirely my own work.
*****************************************************************/
#ifndef LEVEL_H
#define LEVEL_H

#include "AGK.h"

class level{
public:
	level::level(){
		numSprite = 0;
		finishLine = 0;
		difficulty = 1;
		endfire = 1;//Trigger for endgame fireworks
	}
	float GetFinishLine(){
		return finishLine;
	}
	void PlayFireWorks(float dist){
		for (int i = 17; i < 20; ++i){
			agk::CreateParticles(i, 0, 0);
			agk::SetParticlesImage(i, 16);
		}
		if (endfire == 1){//Generates Fireworks upon crossing finish line
			//Play victory fanfare
			int fireworksNum = dist - 200;
			for (int i = 17; i < 20; ++i){
				agk::SetParticlesPosition(i, fireworksNum, agk::Random(100, 300));
				fireworksNum += 300;
				agk::ResetParticleCount(i);
				agk::SetParticlesFrequency(i, 255);
				agk::SetParticlesLife(i, 1.0);
				agk::SetParticlesSize(i, 70);
				agk::SetParticlesStartZone(i, -0, 0, 10, 0);
				agk::SetParticlesImage(i, 16);
				agk::SetParticlesDirection(i, 10, 10);
				agk::SetParticlesAngle(i, 360);
				agk::SetParticlesVelocityRange(i, 1, 120);
				agk::SetParticlesMax(i, 500);
				agk::AddParticlesColorKeyFrame(i, 0, agk::Random(0, 255), agk::Random(0, 255), agk::Random(0, 255), 255);
				agk::AddParticlesColorKeyFrame(i, 1, agk::Random(0, 255), agk::Random(0, 255), agk::Random(0, 255), 255);
				agk::AddParticlesColorKeyFrame(i, 2, agk::Random(0, 255), agk::Random(0, 255), agk::Random(0, 255), 255);
				agk::AddParticlesColorKeyFrame(i, 3, agk::Random(0, 255), agk::Random(0, 255), agk::Random(0, 255), 255);
				agk::AddParticlesForce(2, 2.0, 2.8, 25, -25);
			}
			endfire = 1;
		}
	}
	void BeginSnow(){
		for (int i = 1000; i < 2000 ; i++){
			agk::CreateSprite(i, 3);
			agk::SetSpriteDepth(i, 3);
			agk::FixSpriteToScreen(i, 1);
			agk::SetSpritePosition(i, agk::Random(0.0, 1024.0), agk::Random(0.0, 768.0));
			size = agk::Random(3, 10) / 10.0f;
			agk::SetSpriteScale(i, size, size);
			agk::SetSpriteColor(i, agk::Random(100, 255), agk::Random(100, 255), agk::Random(100, 255), agk::Random(100, 255));
			speed[i] = agk::Random(1, 30) / 10.0f;
		}
	}
	void LoopSnow(){
		for (int i = 1000; i < 2000; i++){
			agk::SetSpriteY(i, agk::GetSpriteY(i) + speed[i]);
			if (agk::GetSpriteY(i) > 1000){
				agk::SetSpritePosition(i, agk::Random(0.0, 1024.0), 0.0);
				speed[i] = agk::Random(1, 30) / 10.0f;
			}
		}
	}
	void LoadBG(){
		agk::CreateSprite(1, 1);//Assigns image from ID 1 to Sprite ID1
		agk::FixSpriteToScreen(1, 1);
		agk::SetSpriteSize(1, 1024, 768);
	}

	void GenerateStart(){
		//Base Y coordinate for blocks is 720.0 pixels
		//Blocks span 80 by 80 pixels
		//9 t0 10 Block distance from top to bottom of screen
		agk::SetPhysicsGravity(0, 500);
		x2 = 1750;//x coordinate of starting generation location after start platform
		leftWallY = 0;//Generate Left Wall Blocks
		for (int i = 2000; i < 2010; i++){
			agk::CreateSprite(i, 204);
			agk::SetSpriteSize(i, 80, -1);
			agk::SetSpritePhysicsOn(i, 1);
			leftWallY += 80;
			agk::SetSpritePosition(i, 0, leftWallY);
		}
		for (int i = 2010; i < 2011; i++){//place background ice block past boundary
			agk::CreateSprite(i, 201);
			agk::SetSpriteSize(i, 1000, -1);
			agk::SetSpritePhysicsOn(i, 1);
			agk::SetSpritePosition(i, -1000, 0);
		}
		topBlockX = 0;
		for (int i = 2011; i < 3000; i++){//Ceiling blocks
			agk::CreateSprite(i, 204);
			agk::SetSpriteSize(i, 80, -1);
			agk::SetSpritePhysicsOn(i, 1);
			topBlockX += 80;
			agk::SetSpritePosition(i, topBlockX - 80, 0);
		}
		x1 = 0;
		for (int i = 3000; i < 3019; i++){//Generates starting ice platform
			agk::CreateSprite(i, 204);
			agk::SetSpriteSize(i, 80, -1);
			agk::SetSpritePhysicsOn(i, 1);
			x1 += 80;
			agk::SetSpritePosition(i, x1, 720.0);
			agk::SetSpriteDepth(i, 1);
		}
		agk::CreateSprite(3019, 214);
		agk::SetSpriteDepth(3019, 1);
		agk::SetSpritePosition(3019,70, 710.0);
		int decorX1 = 100;
		for (int i = 3020; i < 3026; i++){//Sets background items at start area
			int num2 = agk::Random(0, 6);
			switch (num2){
			case 0://small snowman
			case 1:
			case 2:
				agk::CreateSprite(i, 215);
				agk::SetSpriteSize(i, 40, -1);
				agk::SetSpriteDepth(i, 3);
				agk::SetSpritePosition(i, decorX1, 660.0);
				decorX1 += agk::Random(180, 340);
				break;
			case 3://big snowman
				agk::CreateSprite(i, 216);
				agk::SetSpriteDepth(i, 3);
				agk::SetSpritePosition(i, decorX1, 430.0);
				decorX1 += agk::Random(180, 345);
				break;
			case 4://bush
			case 5:
			case 6:
				agk::CreateSprite(i, 217);
				agk::SetSpriteDepth(i, 3);
				agk::SetSpritePosition(i, decorX1, 650.0);
				decorX1 += agk::Random(180, 300);
				break;		
			}
		}
	}
	void GenerateEnd(){
		rightWallY = 0;//Generate Right Wall Blocks
		for (int i = 3026; i < 3036; i++){
			agk::CreateSprite(i, 204);
			agk::SetSpriteSize(i, 80, -1);
			agk::SetSpritePhysicsOn(i, 1);
			rightWallY += 80;
			agk::SetSpritePosition(i, x2 + 800, rightWallY);
		}
		float endx1 = x2 - 80;
		for (int i = 3036; i < 3047; i++){//Generates end ice platform
			agk::CreateSprite(i, 204);
			agk::SetSpriteSize(i, 80, -1);
			agk::SetSpritePhysicsOn(i, 1);
			endx1 += 80;
			agk::SetSpritePosition(i, endx1, 720.0);
			agk::SetSpriteDepth(i, 1);
		}
		//Sets Block snow sprites
		agk::CreateSprite(3047, 218);
		agk::SetSpriteDepth(3047, 1);
		agk::SetSpriteSize(3047, 820, 30);
		agk::SetSpritePosition(3047, x2 - 20, 710.0);
		//Generate Igloo 
		agk::CreateSprite(3048, 219);
		agk::SetSpritePosition(3048, endx1 - 600, 560.0); 
		agk::SetSpriteDepth(3048, 5);
		finishLine = endx1 - 600;// Saves the position of the igloo
	}
	void GenerateStructures(){
		x2 = 1840;
		for (int i = 3049; i < 3250; ++i){//Deletes sprites
			agk::DeleteSprite(i);
		}
		for (int i = 3049; i < 3250; ++i){//Generates basic sprites and sprite properties
			agk::CreateSprite(i, 204);
			agk::SetSpriteSize(i, 80, -1);
			agk::SetSpritePhysicsOn(i, 1);
		}
		for (int i = 3049; i < 3165; i = i + numSprite ){//Loop Generates 5 different ice structures
			int x = 0;
			int num = agk::Random(0, 6);
			switch (num){
			case 0:// 1 block ice hill
				numSprite = 5;
				agk::DeleteSprite(i + 4);
				agk::CreateSprite(i + 4, 210);
				agk::SetSpriteShape(i + 4, 3);
				agk::SetSpritePosition(i, x2, 720.0);
				agk::SetSpritePosition(i + 1, x2 + 80, 720.0);
				agk::SetSpritePosition(i + 2, x2 + 160, 720.0);
				agk::SetSpritePosition(i + 3, x2 + 80, 640.0);
				agk::SetSpritePosition(i + 4, x2 - 95, 635.0);//ledge sprite
				x2 += 320;
				break;
			case 1://Generates 3 Block long ground areas
				numSprite = 4;
				agk::DeleteSprite(i + 3);
				agk::CreateSprite(i + 3, 213);
				agk::SetSpriteShape(i + 3, 3);
				agk::SetSpritePhysicsOff(i + 3);
				agk::SetSpritePosition(i, x2, 720.0);
				agk::SetSpritePosition(i + 1, x2 + 80, 720.0);
				agk::SetSpritePosition(i + 2, x2 + 160, 720.0);
				agk::SetSpritePosition(i + 3, x2 -25, 715.0);//ledgesprite
				x2 += 400;
				break;
			case 2:
			case 3://Ice Mountain Generation
				numSprite = 10;//Creates 10 sprites
				agk::DeleteSprite(i + 9);
				agk::CreateSprite(i + 9, 210);

				//agk::SetSpriteGroup(i + 9, -1);
				agk::SetSpriteShape(i + 9, 3);
				agk::SetSpritePosition(i, x2, 720.0);
				agk::SetSpritePosition(i + 1, x2 + 80.0, 720.0);
				agk::SetSpritePosition(i + 2, x2 + 160.0, 720.0);
				agk::SetSpritePosition(i + 3, x2 + 240.0, 720.0);
				agk::SetSpritePosition(i + 4, x2 + 320.0, 720.0);//Block 5 - first 5 blocks are base level blocks
				agk::SetSpritePosition(i + 5, x2 + 80.0, 640.0);
				agk::SetSpritePosition(i + 6, x2 + 160.0, 640.0);
				agk::SetSpritePosition(i + 7, x2 + 240.0, 640.0);//6 - 8 are 2nd level blocks
				agk::SetSpritePosition(i + 8, x2 + 160.0, 560.0);//Block 9 is the top level block
				agk::SetSpritePosition(i + 9, x2 - 15, 550.0);//Ledge Sprites
				x2 += 560;
				break;
			case 4:
			case 5://Generates one sided mountain
				numSprite = 4;//Creates 4 sprites
				agk::DeleteSprite(i + 3);
				agk::CreateSprite(i + 3, 211);
				agk::SetSpriteShape(i + 3, 3);
				agk::SetSpritePosition(i, x2, 720.0);
				agk::SetSpritePosition(i + 1, x2 + 80.0, 720.0);
				agk::SetSpritePosition(i + 2, x2 + 80.0, 640.0);
				agk::SetSpritePosition(i + 3, x2 - 95, 635.0);//LedgeSprite
				x2 += 400;
				break;
			case 6:
				numSprite = 11;//Creates 11 sprites for a plateau structure
				agk::DeleteSprite(i + 10);
				agk::CreateSprite(i + 10, 212);
				agk::SetSpriteShape(i + 10, 3);
				agk::SetSpritePosition(i, x2, 720.0);
				agk::SetSpritePosition(i + 1, x2 + 80.0, 720.0);
				agk::SetSpritePosition(i + 2, x2 + 160.0, 720.0);
				agk::SetSpritePosition(i + 3, x2 + 240.0, 720.0);
				agk::SetSpritePosition(i + 4, x2 + 320.0, 720.0);
				agk::SetSpritePosition(i + 5, x2 + 400.0, 720.0);//Block 6 - first 6 blocks are base level blocks
				agk::SetSpritePosition(i + 6, x2 + 80.0, 640.0);
				agk::SetSpritePosition(i + 7, x2 + 160.0, 640.0);
				agk::SetSpritePosition(i + 8, x2 + 240.0, 640.0);
				agk::SetSpritePosition(i + 9, x2 + 320.0, 640.0);//Block 10 - Last 4 blocks are the top level blocks
				agk::SetSpritePosition(i + 10, x2 - 20, 635.0);//Block 11 - ledge sprite
				x2 += 560;
			}
		}
		for (int i = 3026; i < 3500; ++i){//Sets all previous ice blocks to correct depthness
			agk::SetSpriteDepth(i, 1);
		}
	}
	void GenerateDecorativeBlocks(){
		x3 = 0;
		for (int i = 7000; i < 7050; i++){//Generates Tree sprites
			agk::CreateSprite(i, 205);
			agk::SetSpriteSize(i, 300, -1);
			agk::FixSpriteToScreen(i, 0); 
			x3 += agk::Random(400, 1000);
			agk::SetSpritePosition(i, x3, 400);
		}
		float cielingX = 80;
		for (int i = 7050; i < 7100; i++){//Generates cieling icicile sprites
			int randCeil = agk::Random(0, 3);
			switch(randCeil){//Randomly places 1 of 4 ceiling sprites
			case 0:
				agk::CreateSprite(i, 206);
				break;
			case 1:
				agk::CreateSprite(i, 207);
				break;
			case 2:
				agk::CreateSprite(i, 208);
				break;
			case 3:
				agk::CreateSprite(i, 209);
				break;
			}
			agk::SetSpriteSize(i, 240, -1);
			agk::FixSpriteToScreen(i, 0); 
			
			agk::SetSpritePosition(i, cielingX, 80);
			cielingX += 240;
		}
	}
	void GenerateWarmth() { // Generates warmth sources
		for (int i = 9000; i < 9100; ++i) { 
			agk::CreateSprite(i, 300);
			agk::SetSpritePhysicsOn(i, 2); 
			agk::SetSpriteShape(i, 1);
			agk::SetSpriteAnimation(i, 40, 50, 8);
			agk::PlaySprite(i, 10, 1, 1, 8);
			agk::SetSpriteDepth(i, 1);
			agk::SetSpritePosition(i, agk::Random(180.0, 10000.0), 300.0);
		}
	}
	void DifficultyUp(){
		difficulty += 1;
	}


private:
	int endfire;
	int difficulty;
	float finishLine;
	int numSprite;//Keeps track of how many sprites are generated for each structure to prevent from overwriting other sprites
	int sprite;
	int image;
	float size;
	float x3;//Saves specific distances needed for random level generation
	float x2;//
	float x1;//
	float topBlockX;
	float leftWallY;
	float rightWallY;
	float speed[2000];
};

#endif