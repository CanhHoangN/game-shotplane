
#include "ComonFunction.h"
#include "MovePlaneOb.h"
#include "ThreateObject.h"
#include "START.h"
#include <SDL_mixer.h>
#include <ctime>
#include <cstdlib>

#define  SLD 2


int main( int argc, char* args[] )
{
	        init();
	       // init1();
	        loadMedia();
	        bool quit = false;

			SDL_Color textColor = { 255, 255, 255, 255 };

			std::stringstream timeText;

			SDL_Event e;

			Dot dot;
            LTexture EG;
			start letgogame;

			ThreateObject threateOb;
			ThreateObject threateOb1;

			threateOb.loadIMThreate();
			letgogame.loadImage();

			SDL_Rect camera = { 0, 0, SCREEN_WIDTH ,SCREEN_HEIGHT };
			SDL_Rect camera1 = { 0, 0, SCREEN_WIDTH ,SCREEN_HEIGHT };



			while( !EG.EndGame() )
			{



				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					dot.handleEvent( e );


                }

				dot.move();
				timeText.str( "" );
				timeText << "Milliseconds since start time " << 100;
                 gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(), textColor );


                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				SDL_RenderClear( gRenderer );
				gBGTexture.render( 0, 0, &camera );



				//letgogame.renderst(camera1.x,camera1.y);
                 if(camera.x < SCREEN_WIDTH*4 && endgame != 5 )
                 {
                     camera.x +=2;
                 }
                 else
                 {

                     camera.x = 0;

                 }

                 dot.render( camera1.x, camera1.y );
                 dot.renderM(camera1.x,camera1.y);
                 dot.renderuntil(camera1.x,camera1.y);
				//letgogame.renderst(camera1.x,camera1.y);

                 threateOb.constructor();
                // letgogame.MouseEV(e,rectStart);

                 for(int i=0;i< SLD-1;i++)
                 {

                     dot.renderP(camera.x,camera.y);
                 }
                 threateOb.freeeverything();

				SDL_RenderPresent( gRenderer );

            }


   close();

	return 0;

}
