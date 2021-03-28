
//Using SDL, SDL_image, standard IO, vectors, and strings
#include"window.h"
#include"ltexture.h"
#include"runfunction.h"
#include"collision.h"


int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{

            SDL_GetWindowSize(gWindow, &SCREEN_WIDTH, &SCREEN_HEIGHT);
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//The background scrolling offset
			int scrollingOffset = 0;

			//Current animation frame
			int frame = 0;
			int x=SCREEN_WIDTH/6;
			int y=SCREEN_HEIGHT*0.65;
			int framemonster=0;
			int framemonster1=0;
			int z=SCREEN_WIDTH;
			int i=0;
			int t=1;
			int black=1.5*SCREEN_WIDTH;
			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{

                   /* if (e.type == SDL_WINDOWEVENT)
                    {


                        SDL_GetWindowSize(gWindow, &SCREEN_WIDTH, &SCREEN_HEIGHT);

                    }*/
					//User requests quit
					if( e.type == SDL_QUIT || e.key.keysym.sym==SDLK_ESCAPE  )
					{
						quit = true;
					}
					if(y<SCREEN_HEIGHT*0.65)y+=250;
					else if( e.type == SDL_KEYDOWN )
					{
						//Select surfaces based on key press
						switch( e.key.keysym.sym )
						{

							case SDLK_RIGHT:
							{
							x=x+10;
							if(x>=SCREEN_WIDTH-160)
                            {
                                x -= 10;
                            }


							break;}
							case SDLK_LEFT:
							{
							x=x-10;
							if(x==0)
                            {
                                x += 10;
                            }


							break;}
							case SDLK_UP:
							{

                                y=y-250;
                                x=x+250;
                                if(x>=SCREEN_WIDTH-160)
                            {
                                x -= 250;
                            }
							break;

                            }
						}
					}


				}
				 i++;
                 z-=5;
                 black-=5;


                 //Render current frame
				SDL_Rect monsterClip = gSprite[ framemonster / 6 ];
				gmonstersheet.render( z, SCREEN_HEIGHT*0.7 , &monsterClip );
				//Update screen
				//SDL_RenderPresent( gRenderer );
				//Go to next frame
				framemonster++;

				//Cycle animation
				if( framemonster / 6 >= MONSTER_ANIMATION_FRAMES )
				{
					framemonster = 0;
				}
				if(z<-300)z=SCREEN_WIDTH+700;

				//Render current frame
				SDL_Rect monster1Clip = gSpritemonster[ framemonster1 / 6 ];
				gmonster1sheet.render( black, SCREEN_HEIGHT*0.7 , &monster1Clip );
				//Update screen
				//SDL_RenderPresent( gRenderer );
				//Go to next frame
				framemonster1++;

				//Cycle animation
				if( framemonster1 / 6 >= MONSTER1_ANIMATION_FRAMES )
				{
					framemonster1 = 0;
				}
				if(black<-300)black=SCREEN_WIDTH+700;
				if(z<-300)z=SCREEN_WIDTH+700;


				//Render current frame
				SDL_Rect currentClip = gSpriteClips[ frame / 10 ];
				gSpriteSheetTexture.renderelse( x, y , &currentClip );
				//Update screen
				SDL_RenderPresent( gRenderer );
				//Go to next frame
				frame+=2;

				//Cycle animation
				if( frame / 10 >= WALKING_ANIMATION_FRAMES )
				{
					frame = 0;
				}


				//Scroll background
				scrollingOffset=scrollingOffset-t;
				if( scrollingOffset < -(gBGTexture.getWidth()+SCREEN_WIDTH/3) )
				{
					scrollingOffset = 0;
				}
				if (i==1000){
                        t++;
                        i=0;}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render background
				SDL_Rect BGClip = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
				gBGTexture.render( scrollingOffset,0,&BGClip );
				gBGTexture.render( scrollingOffset + gBGTexture.getWidth()+SCREEN_WIDTH/3,0,&BGClip );

				if((z==x+120)||(black==x+120))
                {
                    z+=5;
                    black+=5;
                    gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - gTextTexture.getHeight() ) / 2 );

                }



			}

		}
	}

	printf("%d",SCREEN_WIDTH);
	//Free resources and close SDL
	close();

	return 0;
}
