#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include "jeu.h"


void choixpartie(SDL_Renderer *r,SDL_Surface*ecran,SDL_Window *fenetre);
void gagne(SDL_Renderer *r,SDL_Surface*ecran,SDL_Window *fenetre,int t);
void perte(SDL_Renderer *r,SDL_Surface*ecran,SDL_Window *fenetre);
void vide(SDL_Renderer *r,SDL_Surface*ecran,SDL_Window *fenetre);


#endif // AFFICHAGE_H_INCLUDED
