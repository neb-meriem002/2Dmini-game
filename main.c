#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_image.h>
#include <string.h>
#include <SDL_ttf.h>
#include <time.h>
#include "fonctionsupp.h"
#include "jeu.h"
#include "saisie.h"
#include "affichage.h"



int main (int argc, char *argv[])
{

SDL_Window *fenetre = NULL;
SDL_Renderer *rendu = NULL;
SDL_Surface* menu=NULL;
SDL_Surface *ecran = NULL;
SDL_Event even;
SDL_Surface *icone = NULL;

int tick,fps=0,tick_deb=0,tick_fin=0,diff;


    if(SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) != 0)
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        exit (-1);
    }
fenetre = SDL_CreateWindow ("Jeux de lettres", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 650, 0);
    if (fenetre == NULL)
    {
    SDL_Log("ERREUR lors de la creation de la fenetre > %s \n", SDL_GetError() ) ;
    nettoyage_resources (NULL, NULL) ;
    exit(EXIT_FAILURE);
    }

rendu = SDL_CreateRenderer (fenetre, -1, SDL_RENDERER_SOFTWARE);
    if(rendu == NULL)
    {
    SDL_Log("ERREUR lors de la creation du rendu > %s \n", SDL_GetError());
    nettoyage_resources (fenetre, NULL);
    exit(EXIT_FAILURE);
    }

ecran=SDL_GetWindowSurface(fenetre);
icone=IMG_Load("icone64.png");
SDL_SetWindowIcon(fenetre,icone);

tick=SDL_GetTicks();
    //programme_principal_du jeu
int marche=1;
while(marche) {

tick_deb=SDL_GetTicks ();

while (SDL_PollEvent (&even))
       {


 switch(even.type)
 {
    case SDL_QUIT:
        marche=0;
        exit (0);
            break;
    case SDL_MOUSEBUTTONUP:

        if (even.button.button ==SDL_BUTTON_LEFT)
        {
            if (even.button.x > 341 && even.button.x < 682 && even.button.y> 359 && even.button.y <401)
            {
                choixpartie(rendu,ecran,fenetre);
            }
            if (even.button.x > 353 && even.button.x < 672 && even.button.y> 415 && even.button.y <458)
            {
                machine(ecran,rendu,fenetre );
            }
             if (even.button.x > 256 && even.button.x < 765 && even.button.y> 467 && even.button.y <517)
            {
                vs(ecran,rendu,fenetre);
            }
            if (even.button.x > 408 && even.button.x < 624 && even.button.y> 526 && even.button.y <571)
            {
                best_scores(ecran,rendu,fenetre);
            }
            if (even.button.x > 472 && even.button.x < 555 && even.button.y> 583 && even.button.y <634)
            {
                marche=0;
            }
        }

    break;
 }

       }
if (SDL_GetTicks () < tick + 1000){
            fps++;}
        else{
            //printf("fps: %d\n", fps);
            tick=SDL_GetTicks ();
            fps=0;}
            tick_fin=SDL_GetTicks ();

            diff= tick_fin - tick_deb;
                if (diff > 16 )
                    {diff=16;}
            SDL_Delay(16-diff);

menu=IMG_Load("wallpapers.png");
SDL_BlitSurface(menu, NULL, ecran, NULL);
SDL_RenderPresent(rendu);
SDL_FreeSurface(menu);
SDL_UpdateWindowSurface(fenetre);
}
nettoyage_resources(fenetre,rendu);
    return 0;
}

