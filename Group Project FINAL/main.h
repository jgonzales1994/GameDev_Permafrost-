/****************************************************************
File: main.h
Description: Resources for platform use on PC and header for main.cpp
use to execute main functions to run the program

Author: Michael Martinez, Johnny Gonzales, Michael Strade
Class: CSCI 120
Date: 5/13/2015

I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef _H_SMACKIT_
#define _H_SMACKIT_

// Link to GDK libraries
#include "AGK.h"
#include "main.h"
#include "level.h"
#include "player.h"
#include "menu.h"
#include "mechanics.h"
#include <iomanip>  

#define DEVICE_WIDTH 1024
#define DEVICE_HEIGHT 768
#define DEVICE_POS_X 32
#define DEVICE_POS_Y 32
#define FULLSCREEN false

class app{
	public:

		// constructor
		app() { memset ( this, 0, sizeof(app)); }

		// main app functions 
		void Begin( void );
		void Loop( void );
		void End( void );
};

extern app App;

#endif

// Allow us to use the LoadImage function name
#ifdef LoadImage
 #undef LoadImage
#endif