

const int WALKING_ANIMATION_FRAMES = 10;
SDL_Rect gSpriteClips[ WALKING_ANIMATION_FRAMES ];
LTexture gSpriteSheetTexture;
const int MONSTER_ANIMATION_FRAMES = 6;
SDL_Rect gSprite[ MONSTER_ANIMATION_FRAMES ];
LTexture gmonstersheet;
LTexture gBGTexture;

const int MONSTER1_ANIMATION_FRAMES = 6;
SDL_Rect gSpritemonster[ MONSTER1_ANIMATION_FRAMES ];
LTexture gmonster1sheet;
LTexture gTextTexture;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "NGUYEN DUC NGUYEN", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !gSpriteSheetTexture.loadFromFile( "888.png" ) )
	{
		printf( "Failed to load walking animation texture!\n" );
		success = false;
	}
	else
	{
		//Set sprite clips
		gSpriteClips[ 0 ].x =   0;
		gSpriteClips[ 0 ].y =   20;
		gSpriteClips[ 0 ].w =  160;
		gSpriteClips[ 0 ].h = 215;

		/*gSpriteClips[ 1 ].x =  192;
		gSpriteClips[ 1 ].y =   0;
		gSpriteClips[ 1 ].w =  192;
		gSpriteClips[ 1 ].h = 192;*/

		gSpriteClips[ 1 ].x = 160;
		gSpriteClips[ 1 ].y =   20;
		gSpriteClips[ 1 ].w = 160;
		gSpriteClips[ 1 ].h = 210;

		/*gSpriteClips[ 3 ].x = 576;
		gSpriteClips[ 3 ].y =   0;
		gSpriteClips[ 3 ].w =  192;
		gSpriteClips[ 3 ].h = 192;*/

		gSpriteClips[ 2 ].x = 320;
		gSpriteClips[ 2 ].y =   20;
		gSpriteClips[ 2 ].w = 160;
		gSpriteClips[ 2 ].h = 210;

		/*gSpriteClips[ 5 ].x = 960;
		gSpriteClips[ 5 ].y =   0;
		gSpriteClips[ 5 ].w = 192;
		gSpriteClips[ 5 ].h = 192;*/

		gSpriteClips[ 3 ].x = 480;
		gSpriteClips[ 3 ].y =   20;
		gSpriteClips[ 3 ].w = 160;
		gSpriteClips[ 3 ].h = 210;

		/*gSpriteClips[ 7 ].x = 1344;
		gSpriteClips[ 7 ].y =   0;
		gSpriteClips[ 7 ].w =  192;
		gSpriteClips[ 7 ].h = 192;*/

		gSpriteClips[ 4 ].x = 640;
		gSpriteClips[ 4 ].y =   20;
		gSpriteClips[ 4 ].w = 160;
		gSpriteClips[ 4 ].h = 210;

		/*gSpriteClips[ 9 ].x = 1728;
		gSpriteClips[ 9 ].y =   0;
		gSpriteClips[ 9 ].w =  192;
		gSpriteClips[ 9 ].h = 192;*/

		gSpriteClips[ 5 ].x =0 ;
		gSpriteClips[ 5 ].y =220;
		gSpriteClips[ 5 ].w =160;
		gSpriteClips[ 5 ].h = 220;

		/*gSpriteClips[ 6 ].x = 192;
		gSpriteClips[ 6 ].y = 192;
		gSpriteClips[ 6 ].w =192;
		gSpriteClips[ 6 ].h = 192;*/

		gSpriteClips[ 6 ].x = 160;
		gSpriteClips[ 6 ].y = 220;
		gSpriteClips[ 6 ].w = 160;
		gSpriteClips[ 6 ].h = 220;

		gSpriteClips[ 7 ].x = 320;
		gSpriteClips[ 7 ].y = 220;
		gSpriteClips[ 7 ].w = 160;
		gSpriteClips[ 7 ].h = 220;


		gSpriteClips[ 8 ].x = 480;
		gSpriteClips[ 8 ].y = 220;
		gSpriteClips[ 8 ].w = 160;
		gSpriteClips[ 8 ].h = 220;

		gSpriteClips[ 9 ].x = 640;
		gSpriteClips[ 9 ].y = 220;
		gSpriteClips[ 9 ].w = 160;
		gSpriteClips[ 9 ].h = 220;

	}

	if( !gmonstersheet.loadFromFile( "monster2.png" ) )
	{
		printf( "Failed to load walking animation texture!\n" );
		success = false;
	}
	else
	{
		//Set sprite clips
		gSprite[ 0 ].x =  0;
		gSprite[ 0 ].y =  0;
		gSprite[ 0 ].w = 150;
		gSprite[ 0 ].h = 158;

		gSprite[ 1 ].x = 150;
		gSprite[ 1 ].y =   0;
		gSprite[ 1 ].w = 150;
		gSprite[ 1 ].h = 158;

		gSprite[ 2 ].x = 300;
		gSprite[ 2 ].y = 0;
		gSprite[ 2 ].w = 150;
		gSprite[ 2 ].h = 158;

		gSprite[ 3 ].x = 0;
		gSprite[ 3 ].y = 160;
		gSprite[ 3 ].w = 150;
		gSprite[ 3 ].h = 158;

		gSprite[ 4 ].x = 150;
		gSprite[ 4 ].y = 160;
		gSprite[ 4 ].w = 150;
		gSprite[ 4 ].h = 158;

		gSprite[ 5 ].x = 300;
		gSprite[ 5 ].y = 160;
		gSprite[ 5 ].w = 150;
		gSprite[ 5 ].h = 158;
	}

	if( !gmonster1sheet.loadFromFile( "monster3.png" ) )
	{
		printf( "Failed to load walking animation texture!\n" );
		success = false;
	}
	else
	{
		//Set sprite clips
		gSpritemonster[ 0 ].x =  0;
		gSpritemonster[ 0 ].y = 117;
		gSpritemonster[ 0 ].w = 150;
		gSpritemonster[ 0 ].h = 116;

		gSpritemonster[ 1 ].x = 150;
		gSpritemonster[ 1 ].y =   117;
		gSpritemonster[ 1 ].w = 150;
		gSpritemonster[ 1 ].h = 116;

		gSpritemonster[ 2 ].x = 300;
		gSpritemonster[ 2 ].y = 117;
		gSpritemonster[ 2 ].w = 150;
		gSpritemonster[ 2 ].h = 116;

		gSpritemonster[ 3 ].x =  0;
		gSpritemonster[ 3 ].y = 117;
		gSpritemonster[ 3 ].w = 150;
		gSpritemonster[ 3 ].h = 116;

		gSpritemonster[ 4 ].x = 150;
		gSpritemonster[ 4 ].y =   117;
		gSpritemonster[ 4 ].w = 150;
		gSpritemonster[ 4 ].h = 116;

		gSpritemonster[ 5 ].x = 300;
		gSpritemonster[ 5 ].y = 117;
		gSpritemonster[ 5 ].w = 150;
		gSpritemonster[ 5 ].h = 116;



	}
	//Load background texture
	if( !gBGTexture.loadFromFile( "gamebackground.png" ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}

	gFont = TTF_OpenFont( "ALGER.ttf", 100 );
	if( gFont == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		//Render text
		SDL_Color textColor = { 250, 0, 0 };
		if( !gTextTexture.loadFromRenderedText( "GAME OVER ", textColor ) )
		{
			printf( "Failed to render text texture!\n" );
			success = false;
		}
	}

	return success;
}

void close()
{
    //Free global font
	TTF_CloseFont( gFont );
	gFont = NULL;

	//Free loaded images
	gSpriteSheetTexture.free();
	gBGTexture.free();
    gmonstersheet.free();
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
