#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "saisie.h"
#include "fonctionsupp.h"
#include "combi.h"

int saisie_N(SDL_Renderer* r,  SDL_Surface* ecran,SDL_Window *fenetre )
{
    SDL_Surface * t_lettre = NULL ;
    int cont = 1 ;
    SDL_Event  event ;
    SDL_Surface* menu=NULL;
    SDL_Rect  position;

    int m =0;
    char vs[3]= "";

    TTF_Init();
    TTF_Font *police = NULL;
    SDL_Color couleurBlanche = {255, 255, 255};
    position.x = 502;
    position.y = 477;
    police = TTF_OpenFont("timesbi.ttf", 40);


while (cont==1)
{

    SDL_PollEvent (&event);

 switch(event.type)

 {
     case SDL_QUIT:
        exit(0);
        cont=0;
     break;

    case SDL_KEYDOWN:
           switch (event.key.keysym.sym)
           {
           case SDLK_1:
            m= 1;

            break;

            case SDLK_2:
            m= 2;

            break;

           case SDLK_3:
            m= 3;

            break;

           case SDLK_4:
            m= 4;

            break;

            case SDLK_5:
            m= 5;


            break;
            case SDLK_6:
            m= 6;

            break;
            case SDLK_7:
            m= 7;

            break;

            case SDLK_8:
            m= 8;

            break;
            case SDLK_9:
            m= 9;

            break;

            case SDLK_RETURN:

                if(m>=4 && m<=8) {  cont=0; }
                else m=0;

                        break;

            case SDLK_RETURN2:

                if(m>=4 && m<=8) {  cont=0; }
                else m=0;

                        break;
            case SDLK_DELETE:
                      m=0;

                        break;
            case SDLK_BACKSPACE:
                      m=0;

                        break;
           }
 case SDL_MOUSEBUTTONUP:

        if (event.button.button == SDL_BUTTON_LEFT)
        {
            if (event.button.x > 479 && event.button.x < 542 && event.button.y> 526 && event.button.y <565)
            {
                if(m>=4 && m<=8) {  cont=0; }
                else m=0;
            }
        }
break;
    break;
}

menu =IMG_Load("saisieN.png");
if (m!=0)
    {
 sprintf(vs,"%d",m);
 t_lettre= TTF_RenderText_Blended(police, vs, couleurBlanche);
 SDL_BlitSurface(t_lettre, NULL,menu, &position);
 SDL_FreeSurface(t_lettre);
    }
 SDL_BlitSurface(menu, NULL, ecran, NULL);
 SDL_RenderPresent(r);
 SDL_UpdateWindowSurface(fenetre);
 SDL_FreeSurface(menu);

 }
return m;
 }


int saisie_n(SDL_Renderer* r,  SDL_Surface* ecran,SDL_Window *fenetre,int N )
{
    SDL_Surface * t_lettre = NULL ;
    int cont = 1 ;
    int z=N/2;
    SDL_Event  event ;
    SDL_Surface* menu=NULL;
    SDL_Rect  position;
    SDL_Rect  position1;

    int m =0;
    char vs[3]= "";
    char vs1[3]= "";

    TTF_Init();
    TTF_Font *police = TTF_OpenFont("timesbi.ttf", 44);
    SDL_Color couleurBlanche = {255, 255, 255};
    position.x = 502;
    position.y = 477;
    position1.x = 728;
    position1.y = 418;


while (cont==1)
{

    SDL_PollEvent (&event);

 switch(event.type)

 {
     case SDL_QUIT:
        exit(0);
        cont=0;
     break;

    case SDL_KEYDOWN:
           switch (event.key.keysym.sym)
           {
           case SDLK_1:
            m= 1;

            break;

            case SDLK_2:
            m= 2;

            break;

           case SDLK_3:
            m= 3;

            break;

           case SDLK_4:
            m= 4;

            break;

            case SDLK_5:
            m= 5;


            break;
            case SDLK_6:
            m= 6;

            break;
            case SDLK_7:
            m= 7;

            break;

            case SDLK_8:
            m= 8;

            break;
            case SDLK_9:
            m= 9;

            break;

            case SDLK_RETURN:

                if(m>=2 && m<=z) {  cont=0; }
                else m=0;

                        break;

            case SDLK_RETURN2:

                if(m>=2 && m<=z) {  cont=0; }
                else m=0;

                        break;
            case SDLK_DELETE:
                      m=0;

                        break;
            case SDLK_BACKSPACE:
                      m=0;

                        break;
           }
     case SDL_MOUSEBUTTONUP:

        if (event.button.button == SDL_BUTTON_LEFT)
        {
            if (event.button.x > 479 && event.button.x < 544 && event.button.y> 538 && event.button.y <582)
            {
                if(m>=2 && m<=z) {  cont=0; }
                else m=0;
            }
        }
break;

    break;
}



menu =IMG_Load("saisieptn.png");
if (m!=0)
    {
 sprintf(vs,"%d",m);
 t_lettre= TTF_RenderText_Blended(police, vs, couleurBlanche);
 SDL_BlitSurface(t_lettre, NULL,menu, &position);
 SDL_FreeSurface(t_lettre);
    }
 sprintf(vs1,"%d",z);
 t_lettre= TTF_RenderText_Blended(police, vs1, couleurBlanche);
 SDL_BlitSurface(t_lettre, NULL,menu, &position1);
 SDL_FreeSurface(t_lettre);
 SDL_BlitSurface(menu, NULL, ecran, NULL);
 SDL_RenderPresent(r);
 SDL_UpdateWindowSurface(fenetre);
 SDL_FreeSurface(menu);

 }
return m;
 }


liste saisie_deb(SDL_Renderer* r,  SDL_Surface* ecran,SDL_Window *fenetre,int N )
{
    SDL_Surface * img = NULL,* t_lettre = NULL ;
    SDL_Texture *tex=NULL;
    int cont = 1 ;
    int z,i=0;
    SDL_Rect  position;
    TTF_Font *police = NULL;
    SDL_Color couleurBlanche = {255, 255, 255};
    char vs[3]= "";
    liste comb=creer_noeud();
    SDL_Event  evt ;
    SDL_Surface* menu=NULL;
    SDL_Rect  pos[19];
    SDL_Rect  *pos1=malloc( N * sizeof(SDL_Rect));


TTF_Init();
police = TTF_OpenFont("timesbi.ttf", 44);
    position.x = 822;
    position.y = 340;
for(z=0;z<19;z++)
{
    pos[z].x=161+37*z;
    pos[z].y=78;
}

for(z=0;z<N;z++)
{
    pos1[z].x=376+37*z;
    pos1[z].y=446;
}

comb->val=malloc(N * sizeof(int));
comb->suiv=NULL;
comb->ind=0;

 while(cont)
 {
    SDL_PollEvent(&evt);
 switch(evt.type)
 {
     case SDL_QUIT:
        exit(0);
        cont=0;
     break;

     case SDL_MOUSEBUTTONUP:

         if (evt.button.button ==SDL_BUTTON_LEFT)
         {
if (evt.button.x > 479 && evt.button.x < 544 && evt.button.y> 538 && evt.button.y <582)
            {
                if(i==N) {  cont=0; }
            }
if (evt.button.x > 161 && evt.button.x < 196 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=1;
                if (verif(1,i,comb)==0 && i<N) {i++;}
            }
            else {
if (evt.button.x > 198 && evt.button.x < 233 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=2;
                if (verif(2,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 235 && evt.button.x < 270 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=3;
                if (verif(3,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 272 && evt.button.x < 307 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=4;
                if (verif(4,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 309 && evt.button.x < 344 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=5;
                if (verif(5,i,comb)==0 && i<N ) {i++;}
            }
            else {
 if (evt.button.x > 346 && evt.button.x < 381 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=6;
                if (verif(6,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 383 && evt.button.x < 418 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=7;
                if (verif(7,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 420 && evt.button.x < 455 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=8;
                if (verif(8,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 457 && evt.button.x < 492 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=9;
                if (verif(9,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 494 && evt.button.x < 529 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=10;
                if (verif(10,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 531 && evt.button.x < 566 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=11;
                if (verif(11,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 568 && evt.button.x < 603 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=12;
                if (verif(12,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 605 && evt.button.x < 640 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=13;
                if (verif(13,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 642 && evt.button.x < 677 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=14;
                if (verif(14,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 679 && evt.button.x < 714 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=15;
                if (verif(15,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 716 && evt.button.x < 751 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=16;
                if (verif(16,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 753 && evt.button.x < 788 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=17;
                if (verif(17,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 790 && evt.button.x < 825 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=18;
                if (verif(18,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 827 && evt.button.x < 862 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=19;
                if (verif(19,i,comb)==0 && i<N) {i++;}
            }
         }

}}}}}}}}}}}}}}}}}}

     break;

     case SDL_KEYDOWN:
           switch (evt.key.keysym.sym)
           {
              case SDLK_RETURN:

                if(i==N) {  cont=0; }

                        break;

            case SDLK_RETURN2:

                if(i==N) {  cont=0; }
                        break;
            case SDLK_DELETE:
                      i=i-1;

                        break;
            case SDLK_BACKSPACE:
                      i=i-1;

                        break;
           }
break;

 }

 for (z=0;z<19;z++)
                            {
                            img = chargemment(z+1);
                            CreateLettre( r,  img ,tex,pos[z]);
                            SDL_DestroyTexture(tex);
                            }
  for (z=0;z<i;z++)
                            {
                            img = chargemment(comb->val[z]);
                            CreateLettre( r,  img ,tex,pos1[z]);
                            SDL_DestroyTexture(tex);

                            }

 menu =IMG_Load("saisiedp.png");
 sprintf(vs,"%d",N);
 t_lettre= TTF_RenderText_Blended(police, vs, couleurBlanche);
 SDL_BlitSurface(t_lettre, NULL,menu, &position);
 SDL_BlitSurface(menu, NULL, ecran, NULL);
 SDL_RenderPresent(r);
 SDL_UpdateWindowSurface(fenetre);
 SDL_FreeSurface(menu);
 SDL_FreeSurface(t_lettre);
 }
free(pos);
free(pos1);
return(comb);
}


liste saisie_fin(SDL_Renderer* r,  SDL_Surface* ecran,SDL_Window *fenetre,int N,liste tete)
{
    SDL_Surface * img = NULL,* t_lettre = NULL ;
    SDL_Texture *tex=NULL;
    int cont = 1 ;
    int z,i=0;
    SDL_Rect  position;
    TTF_Font *police = NULL;
    SDL_Color couleurBlanche = {255, 255, 255};
    char vs[3]= "";
    int x;
    liste comb=creer_noeud();
    SDL_Event  evt ;
    SDL_Surface* menu=NULL;
    SDL_Rect  pos[19],poss[19];
    SDL_Rect  *pos1=malloc( N * sizeof(SDL_Rect)),*pos2=malloc( N * sizeof(SDL_Rect));

 TTF_Init();
police = TTF_OpenFont("timesbi.ttf", 44);
    position.x = 827;
    position.y = 342;
for(z=0;z<19;z++)
{
    pos[z].x=161+37*z;
    pos[z].y=78;
    poss[z].x=161+37*z;
    poss[z].y=120;
}
for(z=0;z<N;z++)
{
    pos1[z].x=401+37*z;
    pos1[z].y=491;
    pos2[z].x=542+37*z;
    pos2[z].y=251;
}
comb->val=malloc( N * sizeof(int));
comb->ind=0;
while (cont)
{

SDL_PollEvent(&evt);
 switch(evt.type)
 {
     case SDL_QUIT:
        exit(0);
        cont=0;
     break;

     case SDL_MOUSEBUTTONUP:

         if (evt.button.button ==SDL_BUTTON_LEFT)
         {
if (evt.button.x > 479 && evt.button.x < 544 && evt.button.y> 538 && evt.button.y <582)
            {
                if(i==N) {  cont=0; }
            }
if (evt.button.x > 161 && evt.button.x < 196 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=1;
                if (verif(1,i,comb)==0 && i<N) {i++;}
            }
            else {
if (evt.button.x > 198 && evt.button.x < 233 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=2;
                if (verif(2,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 235 && evt.button.x < 270 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=3;
                if (verif(3,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 272 && evt.button.x < 307 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=4;
                if (verif(4,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 309 && evt.button.x < 344 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=5;
                if (verif(5,i,comb)==0 && i<N ) {i++;}
            }
            else {
 if (evt.button.x > 346 && evt.button.x < 381 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=6;
                if (verif(6,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 383 && evt.button.x < 418 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=7;
                if (verif(7,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 420 && evt.button.x < 455 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=8;
                if (verif(8,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 457 && evt.button.x < 492 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=9;
                if (verif(9,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 494 && evt.button.x < 529 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=10;
                if (verif(10,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 531 && evt.button.x < 566 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=11;
                if (verif(11,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 568 && evt.button.x < 603 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=12;
                if (verif(12,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 605 && evt.button.x < 640 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=13;
                if (verif(13,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 642 && evt.button.x < 677 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=14;
                if (verif(14,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 679 && evt.button.x < 714 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=15;
                if (verif(15,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 716 && evt.button.x < 751 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=16;
                if (verif(16,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 753 && evt.button.x < 788 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=17;
                if (verif(17,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 790 && evt.button.x < 825 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=18;
                if (verif(18,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 827 && evt.button.x < 862 && evt.button.y> 78 && evt.button.y < 113)
            {
                comb->val[i]=19;
                if (verif(19,i,comb)==0 && i<N) {i++;}
            }
            /////////////////////
            else {
            if (evt.button.x > 161 && evt.button.x < 196 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-1;
                if (verif(-1,i,comb)==0 && i<N) {i++;}
            }
            else {
if (evt.button.x > 198 && evt.button.x < 233 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-2;
                if (verif(-2,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 235 && evt.button.x < 270 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-3;
                if (verif(-3,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 272 && evt.button.x < 307 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-4;
                if (verif(-4,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 309 && evt.button.x < 344 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-5;
                if (verif(-5,i,comb)==0 && i<N ) {i++;}
            }
            else {
 if (evt.button.x > 346 && evt.button.x < 381 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-6;
                if (verif(-6,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 383 && evt.button.x < 418 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-7;
                if (verif(-7,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 420 && evt.button.x < 455 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-8;
                if (verif(-8,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 457 && evt.button.x < 492 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-9;
                if (verif(-9,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 494 && evt.button.x < 529 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-10;
                if (verif(-10,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 531 && evt.button.x < 566 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-11;
                if (verif(-11,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 568 && evt.button.x < 603 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-12;
                if (verif(-12,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 605 && evt.button.x < 640 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-13;
                if (verif(-13,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 642 && evt.button.x < 677 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-14;
                if (verif(-14,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 679 && evt.button.x < 714 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-15;
                if (verif(-15,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 716 && evt.button.x < 751 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-16;
                if (verif(-16,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 753 && evt.button.x < 788 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-17;
                if (verif(-17,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 790 && evt.button.x < 825 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-18;
                if (verif(-18,i,comb)==0 && i<N) {i++;}
            }
            else {
 if (evt.button.x > 827 && evt.button.x < 862 && evt.button.y> 120 && evt.button.y < 157)
            {
                comb->val[i]=-19;
                if (verif(-19,i,comb)==0 && i<N) {i++;}
            }
         }}}}}}}}}}}}}}}}}}
         }}}}}}}}}}}}}}}}}}}
         }

     break;

     case SDL_KEYDOWN:
           switch (evt.key.keysym.sym)
           {
              case SDLK_RETURN:

                if(i==N) {  cont=0; }

                        break;

            case SDLK_RETURN2:

                if(i==N) {  cont=0; }
                        break;
            case SDLK_DELETE:
                      i=i-1;

                        break;
            case SDLK_BACKSPACE:
                      i=i-1;
                        break;
           }
 }
for (z=0;z<19;z++)
                            {
                                x=z+1;
                            img = chargemment(x);
                            CreateLettre( r,  img ,tex,pos[z]);
                            SDL_DestroyTexture(tex);

                            img = chargemment(-x);
                            CreateLettre( r,  img ,tex,poss[z]);
                            SDL_DestroyTexture(tex);
                            if(z<N)
                            {
                             img = chargemment(tete->val[z]);
                            CreateLettre( r,  img ,tex,pos2[z]);
                            SDL_DestroyTexture(tex);
                            }
                            }

for (z=0;z<i;z++)
                            {
                            img = chargemment(comb->val[z]);
                            CreateLettre( r,  img ,tex,pos1[z]);
                            SDL_DestroyTexture(tex);

                            }

 menu =IMG_Load("saisiearr.png");
 sprintf(vs,"%d",N);
 t_lettre= TTF_RenderText_Blended(police, vs, couleurBlanche);
 SDL_BlitSurface(t_lettre, NULL,menu, &position);
 SDL_BlitSurface(menu, NULL, ecran, NULL);
 SDL_RenderPresent(r);
 SDL_UpdateWindowSurface(fenetre);
 SDL_FreeSurface(menu);
 SDL_FreeSurface(t_lettre);
 }

free(pos2);
free(pos1);
return(comb);
}

char* Saisie_nom(SDL_Renderer *r,SDL_Surface*ecran,SDL_Window *fenetre)
{

char* str=malloc(20 * sizeof(char));
int i=0;
int cont=1;
SDL_Event event;
SDL_Rect pos;
SDL_Surface *menu=IMG_Load("saisie.png");
TTF_Font *pol ;
SDL_Surface * texte = NULL ;

TTF_Init();
 SDL_Color couleurBlanche = {255, 255, 255};
 pol = TTF_OpenFont("timesbi.ttf", 44);

pos.x=235;
pos.y=451;

while(cont)
{
SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT:
cont=0;
exit(0);
break;

case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_a:
str[i]='a';
i++;
str[i]='\0';
break;

case SDLK_b:
str[i]='b';
i++;
str[i]='\0';
break;

case SDLK_c:
str[i]='c';
i++;
str[i]='\0';
break;

case SDLK_d:
str[i]='d';
i++;
str[i]='\0';
break;

case SDLK_e:
str[i]='e';
i++;
str[i]='\0';
break;

case SDLK_f:
str[i]='f';
i++;
str[i]='\0';
break;

case SDLK_g:
str[i]='g';
i++;
str[i]='\0';
break;

case SDLK_h:
str[i]='h';
i++;
str[i]='\0';
break;

case SDLK_i:
str[i]='i';
i++;
str[i]='\0';
break;

case SDLK_j:
str[i]='j';
i++;
str[i]='\0';
break;

case SDLK_k:
str[i]='k';
i++;
str[i]='\0';
break;

case SDLK_l:
str[i]='l';
i++;
str[i]='\0';
break;

case SDLK_m:
str[i]='m';
i++;
str[i]='\0';
break;

case SDLK_n:
str[i]='n';
i++;
str[i]='\0';
break;

case SDLK_o:
str[i]='o';
i++;
str[i]='\0';
break;

case SDLK_p:
str[i]='p';
i++;
str[i]='\0';
break;

case SDLK_q:
str[i]='q';
i++;
str[i]='\0';
break;

case SDLK_r:
str[i]='r';
i++;
str[i]='\0';
break;

case SDLK_s:
str[i]='s';
i++;
str[i]='\0';
break;

case SDLK_t:
str[i]='t';
i++;
str[i]='\0';
break;

case SDLK_u:
str[i]='u';
i++;
str[i]='\0';
break;

case SDLK_v:
str[i]='v';
i++;
str[i]='\0';
break;

case SDLK_w:
str[i]='w';
i++;
str[i]='\0';
break;

case SDLK_x:
str[i]='x';
i++;
str[i]='\0';
break;

case SDLK_y:
str[i]='y';
i++;
str[i]='\0';
break;

case SDLK_z:
str[i]='z';
i++;
str[i]='\0';
break;

case SDLK_1:
str[i]='1';
i++;
str[i]='\0';
break;

case SDLK_2:
str[i]='2';
i++;
str[i]='\0';
break;

case SDLK_3:
str[i]='3';
i++;
str[i]='\0';
break;

case SDLK_4:
str[i]='4';
i++;
str[i]='\0';
break;

case SDLK_5:
str[i]='5';
i++;
str[i]='\0';
break;

case SDLK_6:
str[i]='6';
i++;
str[i]='\0';
break;

case SDLK_7:
str[i]='7';
i++;
str[i]='\0';
break;

case SDLK_8:
str[i]='8';
i++;
str[i]='\0';
break;

case SDLK_9:
str[i]='9';
i++;
str[i]='\0';
break;

case SDLK_0:
str[i]='0';
i++;
str[i]='\0';
break;

 case SDLK_RETURN:
if(i!=0) {  cont=0; }
break;

case SDLK_RETURN2:
if(i!=0) {  cont=0; }
break;

case SDLK_DELETE:
    str[i-1]='\0';
i=i-1;
break;

case SDLK_BACKSPACE:
    str[i-1]='\0';
i=i-1;
break;

}
 case SDL_MOUSEBUTTONUP:

        if (event.button.button == SDL_BUTTON_LEFT)
        {
            if (event.button.x > 479 && event.button.x < 542 && event.button.y> 526 && event.button.y <565)
            {
                if(i!=0) {  cont=0; }
            }
        }
break;

}
 menu =IMG_Load("saisienom.png");
 if(i!=0)
 {
texte= TTF_RenderText_Blended(pol, str, couleurBlanche);
SDL_BlitSurface(texte, NULL,menu, &pos);
SDL_FreeSurface(texte);
 }
 SDL_BlitSurface(menu, NULL, ecran, NULL);
 SDL_RenderPresent(r);
 SDL_UpdateWindowSurface(fenetre);
 SDL_FreeSurface(menu);
 }

 return str;
}
