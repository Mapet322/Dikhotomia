//Using SDL, SDL_image, standard math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cstring>

#include "funciones.h"
#include "clases.h"
#include "varglob.h"



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
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;
            int frame = 0;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

	while(quit == false) {
        while(SDL_PollEvent(&e) && quit == false) {

                                    //Clear screen
                                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                                    //Render current frame
                                    SDL_Rect* currentClip = &gSpriteClips[ frame / 4 ];



            if(e.type == SDL_QUIT) {
                    quit = true;
                }

            if(e.type == SDL_KEYDOWN) {

                switch(e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                                    quit = true;
                                    break;
                    case SDLK_DOWN:
                                    ///Ejemplo de manejo de animación

                                    SDL_RenderClear( gRenderer );

                                    gSpriteSheetTexture.render( ( SCREEN_WIDTH - currentClip->w ) / 2, ( SCREEN_HEIGHT - currentClip->h ) / 2, currentClip );

                                    //Update screen
                                    SDL_RenderPresent( gRenderer );

                                    //Go to next frame
                                    ++frame;

                                    //Cycle animation no funciona del todo por ahora porque estamos dentro del while que espera un input, si queres que la animacion fluya tenes que mantener flecha abajo en el programa .
                                    if( frame / 4 >= WALKING_ANIMATION_FRAMES )
                                    {
                                        frame = 0;
                                    }


                                    break;
                    default:
                                    break;
                }
            }


        }
    }

			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
