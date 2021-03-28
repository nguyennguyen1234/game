
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <SDL_ttf.h>

//Screen dimension constants
int SCREEN_WIDTH = 1000;
int SCREEN_HEIGHT = 700;
//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();
