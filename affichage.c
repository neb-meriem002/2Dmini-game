#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_image.h>
#include <string.h>
#include <SDL_ttf.h>
#include "fonctionsupp.h"
#include "combi.h"
#include "time.h"
#include "affichage.h"
#include "jeu.h"

void choixpartie(SDL_Renderer *r,SDL_Surface*ecran,SDL_Window *fenetre)
{
SDL_Event even;
SDL_Surface *choixmode=NULL;
FILE * f=NULL;
int cont=1;
int N;


while (cont)
{
SDL_PollEvent(&even);
switch(even.type)
{
case SDL_QUIT:
cont=0;
exit(0);
break;

case SDL_MOUSEBUTTONUP:
     if (even.button.button ==SDL_BUTTON_LEFT)
        {
if(even.button.x > 406 && even.button.x < 615 && even.button.y> 378 && even.button.y <423)
{
f=fopen("sauvegarde.txt","r");
fscanf(f,"%d/",&N);
fclose(f);
if (N==0)
{
vide(r,ecran,fenetre);
cont=0;
jouersolo(ecran,r,fenetre);
}
else
{
chargerjouersolo(r,ecran,fenetre);
cont=0;
}
}

if(even.button.x > 426 && even.button.x < 603 && even.button.y> 438 && even.button.y <466)
{

jouersolo(ecran,r,fenetre);

cont=0;
}
if (even.button.x > 719 && even.button.x < 990 && even.button.y> 580 && even.button.y <617 )
{ cont =0; }
        }

break;
}
choixmode =IMG_Load("modepartie.png");
SDL_BlitSurface(choixmode, NULL, ecran, NULL);
SDL_RenderPresent(r);
SDL_UpdateWindowSurface(fenetre);
SDL_FreeSurface(choixmode);
}
}

void gagne(SDL_Renderer *r,SDL_Surface*ecran,SDL_Window *fenetre,int t)
{
SDL_Event even;
SDL_Surface *choixmode=NULL,*texte = NULL;
int cont=1;
int compt=0;
char entree[3]="";
SDL_Rect position;


TTF_Init();
    TTF_Font *police = NULL;
    SDL_Color couleurBlanche = {255, 255, 255};

    position.x = 684;
    position.y = 505;

    police = TTF_OpenFont("timesbi.ttf", 40);

while (cont)
{
SDL_PollEvent(&even);
switch(even.type)
{
case SDL_QUIT:
cont=0;
exit(0);
break;

case SDL_MOUSEBUTTONUP:
                if (even.button.button ==SDL_BUTTON_LEFT)
            {
                if (even.button.x > 719 && even.button.x < 990 && even.button.y> 580 && even.button.y <617 )
                { cont =0; }

            }
break;
}
if(compt==20)
{
cont=0;
}

SDL_Delay(150);
compt++;
choixmode =IMG_Load("gagne.png");
sprintf(entree,"%d",t);
texte = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(choixmode, NULL, ecran, NULL);
SDL_BlitSurface(texte, NULL, ecran, &position);

SDL_RenderPresent(r);
SDL_UpdateWindowSurface(fenetre);
SDL_FreeSurface(choixmode);
SDL_FreeSurface(texte);
}
}

void perte(SDL_Renderer *r,SDL_Surface*ecran,SDL_Window *fenetre)
{
SDL_Event even;
SDL_Surface *choixmode=NULL;
int cont=1;
int compt=0;


while (cont)
{
SDL_PollEvent(&even);
switch(even.type)
{
case SDL_QUIT:
cont=0;
exit(0);
break;


 case SDL_MOUSEBUTTONUP:

            if (even.button.button ==SDL_BUTTON_LEFT)
            {
                if (even.button.x > 719 && even.button.x < 990 && even.button.y> 580 && even.button.y <617 )
                { cont =0; }

            }
break;
}
if(compt==20)
{
cont=0;
}

SDL_Delay(150);
compt++;

choixmode =IMG_Load("perte.png");

SDL_BlitSurface(choixmode, NULL, ecran, NULL);
SDL_RenderPresent(r);
SDL_UpdateWindowSurface(fenetre);
SDL_FreeSurface(choixmode);

}
}

void vide(SDL_Renderer *r,SDL_Surface*ecran,SDL_Window *fenetre)
{
SDL_Event even;
SDL_Surface *choixmode=NULL;
int cont=1;
int compt=0;


while (cont)
{
SDL_PollEvent(&even);
switch(even.type)
{
case SDL_QUIT:
cont=0;
exit(0);
break;

}
if(compt==20)
{
cont=0;
}
SDL_Delay(150);
compt++;

choixmode =IMG_Load("partie.png");

SDL_BlitSurface(choixmode, NULL, ecran, NULL);
SDL_RenderPresent(r);
SDL_UpdateWindowSurface(fenetre);
SDL_FreeSurface(choixmode);

}
SDL_Delay(500);
}
