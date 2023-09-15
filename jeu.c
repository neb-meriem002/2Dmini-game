#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <time.h>
#include "fonctionsupp.h"
#include "combi.h"
#include "jeu.h"
#include "saisie.h"
#include "affichage.h"

Uint32 incrementationCallback(Uint32 intervalle,void *parametre){
   int *t1 = parametre;
   *t1+=1;

  return intervalle;}

void jouersolo (SDL_Surface* ecran,SDL_Renderer* rendu,SDL_Window *fenetre )
{
    int i=0,j=0; int N , n ,cpt ;
    int c,q=0,conti=1;
    int z,v;
    int *ta;
    int r;
    int t1=0,t2=0;
    int **ligne=malloc (30 * sizeof(int*));
    FILE *f=NULL;
    liste tete= NULL;
    liste L,PAR,P;
    SDL_Rect position,position1,position2,**pos =malloc (30 * sizeof(SDL_Rect*));
    SDL_Surface *image,*texte;
    SDL_Surface* img1=NULL;
    SDL_Event even;
    SDL_Surface *choixmode;
    SDL_Texture *texture=NULL;
    SDL_Rect *fin;
    SDL_TimerID timer;
    char entree[3]="";
    char* nom=malloc (20 * sizeof(char));

TTF_Init();
    TTF_Font *police = NULL;
    SDL_Color couleurBlanche = {255, 255, 255};

    position.x = 950;
    position.y = 4;
    position1.x = 895;
    position1.y = 60;
    position2.x = 895;
    position2.y = 107;

    police = TTF_OpenFont("timesbi.ttf", 40);
  do
  {
    srand(time(NULL));
    N = rand()%9;
  }
while(N<4);

tete=creer_noeud();
tete->val=malloc(N * sizeof(int));

if ( tete->val == NULL)
    {exit(0);}

for (i=0;i<N;i++)
    {

    cpt = 0 ; z = 0;
    do{
            do {
       cpt = 1+rand()%18;
       tete->val[i] = cpt ;
       v=verif(cpt,i,tete);
               }while (v!=0);
       z = z + 1 ;
       cpt = 0 ;
       } while(z < N );
    }
tete->suiv=NULL;

n=2;
z=N/2;
nom= Saisie_nom(rendu,ecran,fenetre );
if(N > 5)
{
do  {
n = 2 + rand()%3;
    }
while(n>z );
}

c=1;
PAR=tete;
P=tete;
do
{

for (i=0;i<=N-n;i++)
{
ta=permuter(PAR,i,n,N);
if (trouv(tete,ta,N)==0)
{
c=c+1;
L=creer_noeud();
L->val=malloc(N* sizeof(int));
for (z=0;z<N;z++)
{
L->val[z]=ta[z];
}
L->suiv=NULL;
P->suiv=L;
P=L;

}
}
PAR=PAR->suiv;
}
while (PAR!=NULL && c<200 );

do
{
  r=3 + rand()%c;
}while (r>c);
for(i=0;i<30;i++)
 {
     pos[i]= malloc ( N * sizeof (SDL_Rect));
     ligne[i]= malloc ( N * sizeof (int));
 }

fin = malloc(N *sizeof(SDL_Rect));
 for(i=0;i<N;i++)
 {
   fin[i].x=450+i*37;
   fin[i].y=6;
   pos[0][i].x=176+i*37;
   pos[0][i].y=50;
   ligne[0][i]=tete->val[i];
 }
PAR = finale(tete,r,N);

v=0;
j=0;

timer=SDL_AddTimer(1016,incrementationCallback,&t1);
while(conti==1)
{

    SDL_PollEvent (&even);
    switch(even.type)
    {

    case SDL_QUIT:
        conti=0;
        exit(0);
        break;
    case SDL_MOUSEBUTTONUP:
        if (even.button.button ==SDL_BUTTON_LEFT)
        {
            if (even.button.x > pos[j][0].x && even.button.x < pos[j][0].x +35 && even.button.y> pos[j][0].y && even.button.y <pos[j][0].y+35 )
            {

                j=j+1;

                ligne[j]=permute(ligne[j-1],0,N,n);
                if( j == 16  ) {q=0;}
                else {q=q+1;}
                pos[j]=positionnement(pos[j-1], N , q );
                v=compar2(PAR->val,ligne[j],N);


            }
              if (even.button.x > pos[j][1].x && even.button.x < pos[j][1].x +35 && even.button.y> pos[j][1].y && even.button.y <pos[j][1].y+35 )
            {

                j=j+1;

                ligne[j]=permute(ligne[j-1],1,N,n);
                if( j == 16 ) {q=0;}
                else {q=q+1;}
                pos[j]=positionnement(pos[j-1], N , q );
                v=compar2(PAR->val,ligne[j],N);

            }
              if (even.button.x > pos[j][2].x && even.button.x < pos[j][2].x +35 && even.button.y> pos[j][2].y && even.button.y <pos[j][2].y+35 )
            {

                j=j+1;

                ligne[j]=permute(ligne[j-1],2,N,n);
                if( j == 16 ) {q=0;}
                else {q=q+1;}
                pos[j]=positionnement(pos[j-1], N , q );
                v=compar2(PAR->val,ligne[j],N);

            }
if(N-n>=3)      if (even.button.x > pos[j][3].x && even.button.x < pos[j][3].x +35 && even.button.y> pos[j][3].y && even.button.y <pos[j][3].y+35 )
            {

                j=j+1;

                ligne[j]=permute(ligne[j-1],3,N,n);
                if( j == 16 ) {q=0;}
                else {q=q+1;}
                pos[j]=positionnement(pos[j-1], N , q );
                v=compar2(PAR->val,ligne[j],N);

            }
if(N-n>=4)       if (even.button.x > pos[j][4].x && even.button.x < pos[j][4].x +35 && even.button.y> pos[j][4].y && even.button.y <pos[j][4].y+35 )
            {

                j=j+1;

                ligne[j]=permute(ligne[j-1],4,N,n);
                if( j == 16 ) {q=0;}
                else {q=q+1;}
                pos[j]=positionnement(pos[j-1], N , q );
                v=compar2(PAR->val,ligne[j],N);

            }
if(N-n>=5)      if (even.button.x > pos[j][5].x && even.button.x < pos[j][5].x +35 && even.button.y> pos[j][5].y && even.button.y <pos[j][5].y+35 )
            {

                j=j+1;

                ligne[j]=permute(ligne[j-1],5,N,n);
                if( j == 16 ) {q=0;}
                else {q=q+1;}
                pos[j]=positionnement(pos[j-1], N , q );
                v=compar2(PAR->val,ligne[j],N);


            }
if(N-n>=6)      if (even.button.x > pos[j][6].x && even.button.x < pos[j][6].x +35 && even.button.y> pos[j][6].y && even.button.y <pos[j][6].y+35 )
            {

                j=j+1;

                ligne[j]=permute(ligne[j-1],6,N,n);
                if( j == 16 ) {q=0;}
                else {q=q+1;}
                pos[j]=positionnement(pos[j-1], N , q );
                v=compar2(PAR->val,ligne[j],N);

            }
            if (even.button.x > 839 && even.button.x < 930 && even.button.y> 477 && even.button.y <505 )  //appuie sur bouton pause
            {    c=1;
                t2=t1;  //recuperer temps ecoule depuis le commencement
    while(c)            //boucle infinie du menu pause
{
img1=IMG_Load("pause.png");
SDL_BlitSurface(img1, NULL, ecran, NULL);
SDL_FreeSurface(img1);
SDL_RenderPresent(rendu);

   SDL_PollEvent (&even);  //attente d'un evenement de la part de l'utilisateur
   switch(even.type)
{
       case SDL_QUIT:
        c=0;
            break;
       case SDL_MOUSEBUTTONUP:
        if (even.button.button ==SDL_BUTTON_LEFT)
        {
        if (even.button.x > 317 && even.button.x < 712 && even.button.y> 408 && even.button.y <450) //appuis sur bouton retour au jeu
             { conti=1; c=0; }
        if (even.button.x > 319 && even.button.x < 675 && even.button.y> 464 && even.button.y <503) //appuis sur bouton retour menu
             { c=0; conti=0; t1=0; t2=0;}
        };
            break;
}
}
t1=t2;    //recuperer le temps ecoule avant d'avoir appuiller sur le bouton pause
        }
        if (even.button.x > 759 && even.button.x < 1009  && even.button.y> 519 && even.button.y <557 )
            {

            conti=0; ;

            }
        if (even.button.x >771 && even.button.x <996 && even.button.y>563 && even.button.y <600 )
        {
f=fopen("sauvegarde.txt","w");
fprintf(f,"%d/%d/%d/%d\n%s\n",N,n,j,t1,nom);

for(z=0;z<=j;z++)
{
for(i=0;i<N-1;i++)
{
fprintf(f,"%d/",ligne[z][i]);
}
fprintf(f,"%d\n",ligne[z][N-1]);
}
for(i=0;i<N-1;i++)
{
fprintf(f,"%d/",PAR->val[i]);
}
fprintf(f,"%d\n",PAR->val[N-1]);
fclose(f);
conti=0;
        }
    break;
    }
    break;
    }
for (i=0;i<N;i++)
                            {
                            image = chargemment(PAR->val[i]);
                            CreateLettre( rendu,  image ,texture,fin[i]);
                            SDL_DestroyTexture(texture);
                            }
for(z=0;z<=j;z++)
{
                            for (i=0;i<N;i++)
                            {
                            image = chargemment(ligne[z][i]);
                            CreateLettre( rendu,  image ,texture,pos[z][i]);
                            SDL_DestroyTexture(texture);
                            }
}

choixmode =IMG_Load("menujeu.png");
SDL_BlitSurface(choixmode, NULL, ecran, NULL);

sprintf(entree,"%d",t1);
texte = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_FreeSurface(texte);

sprintf(entree,"%d",N);
texte = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte, NULL, ecran, &position1);
SDL_FreeSurface(texte);

sprintf(entree,"%d",n);
texte = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte, NULL, ecran, &position2);
SDL_FreeSurface(texte);

SDL_RenderPresent(rendu);
SDL_UpdateWindowSurface(fenetre);
SDL_FreeSurface(choixmode);


if(v==2 )  {joueur x; x.score=t1; strcpy(x.nom1,nom); meilleur_scores (x); SDL_Delay (3000); gagne(rendu,ecran,fenetre,x.score); conti=0;  }
if(j==31 ) {SDL_Delay(3000); perte(rendu,ecran,fenetre); conti=0;  }
}
SDL_RemoveTimer(timer);
for (i=0;i<30;i++)
{
  free(ligne[i]);
  free(pos[i]);
}
}

void machine (SDL_Surface* ecran,SDL_Renderer* rendu,SDL_Window *fenetre )
{
    SDL_Surface* choixmode=NULL;
    SDL_Event event;
    SDL_Rect *posfin,position,position1,position2;
    SDL_Surface *image=NULL,*texte = NULL,*img1=NULL;
    SDL_Texture *texture=NULL;
    SDL_TimerID timer,timer1;
    int conti=1;
    int N,n;
    int c,i,z,q=0;
    int *ta,*t;
    int condi=3;
    int indx;
    int r=1,j=0;
    int t1=0,t2=0,t3=0,t4=0;
    liste PAR=NULL,L=NULL,P=NULL;
    liste fin=creer_noeud();
    liste tete=creer_noeud();
    liste tempo=NULL;
    liste chemin=NULL;

TTF_Init();

    TTF_Font *police = NULL;
    SDL_Color couleurBlanche = {255, 255, 255};
    char entree[3]="";

    position.x = 945;
    position.y = 8;
    position1.x = 877;
    position1.y = 52;
    position2.x = 877;
    position2.y = 97;

     police = TTF_OpenFont("timesbi.ttf", 40);

N=saisie_N(rendu,ecran,fenetre);
ta=malloc (N * sizeof(int));
fin->val=malloc (N * sizeof(int));
n=saisie_n(rendu,ecran,fenetre,N);
tete=saisie_deb(rendu,ecran,fenetre,N );
c=1;
PAR=tete;
P=tete;
posfin=malloc (N * sizeof(SDL_Rect));
for(i=0;i<N;i++)
 {

   posfin[i].x=495+i*37;
   posfin[i].y=15;

 }
do {
    for (i=0;i<=N-n;i++)
    {

ta = permuter(PAR,i,n,N);

 if (trouv(tete,ta,N)==0)
{
 L=creer_noeud();
 L->ind=i;
 L->val=malloc(N* sizeof(int));

for (z=0;z<N;z++)
{
L->val[z]=ta[z];
}
L->suiv=NULL;
P->suiv=L;
P=L;
c=c+1;
}
}

PAR=PAR->suiv;

}while(PAR!=NULL && c<400) ;
L=NULL;
PAR=NULL;

do
{
fin=saisie_fin(rendu,ecran,fenetre,N,tete );
c=trouv(tete,fin->val,N);
i=compar2(tete->val,fin->val,N);
}

while (c == 0 || i==2);

t=malloc( N * sizeof(int));
for (z=0;z<N;z++)
{
 t[z]=fin->val[z];
}
while (condi != 2)
{
 tempo = trouv2(tete,t,N);
 indx=tempo->ind;
 creerch(&chemin,tempo,N);
 t=permute(t,indx,N,n);
 condi=compar2(t,tete->val,N);
 r=r+1;
}
tempo=NULL;
free(t);

int **ligne=malloc (r * sizeof(int*));
SDL_Rect **post =malloc (r * sizeof(SDL_Rect*));

for(i=0;i<r;i++)
 {
     post[i]= malloc ( N * sizeof (SDL_Rect));
     ligne[i]= malloc ( N * sizeof (int));
 }

for(i=0;i<N;i++)
 {
     ligne[0][i]=tete->val[i];
     post[0][i].x=176+i*37;
     post[0][i].y=50;
 }
timer1=SDL_AddTimer(1060,incrementationCallback,&t2);
timer=SDL_AddTimer(1060,incrementationCallback,&t1);
while(conti){

SDL_PollEvent (&event);
   switch(event.type)
   {
    case SDL_QUIT:

        exit(0);
        conti=0;
    break;
    case SDL_MOUSEBUTTONUP:
        if (event.button.button ==SDL_BUTTON_LEFT)
        {
                if (event.button.x > 804 && event.button.x < 920 && event.button.y> 513 && event.button.y <551 )
            {    c=1;
                t3=t2;
                t4=t1;
    while(c)
{
img1=IMG_Load("pause.png");
SDL_BlitSurface(img1, NULL, ecran, NULL);
SDL_FreeSurface(img1);
SDL_RenderPresent(rendu);

   SDL_PollEvent (&event);
   switch(event.type)
{
       case SDL_QUIT:
        c=0;
            break;
       case SDL_MOUSEBUTTONUP:
        if (event.button.button ==SDL_BUTTON_LEFT)
        {
        if (event.button.x > 317 && event.button.x < 712 && event.button.y> 408 && event.button.y <450)
             { conti=1; c=0; }
        if (event.button.x > 319 && event.button.x < 675 && event.button.y> 464 && event.button.y <503)
             { c=0; conti=0; t1=0; t2=0; t3=0; SDL_RemoveTimer(timer);SDL_RemoveTimer(timer1);}
        }
            break;
}
}
t2=t3;
t1=t4;
        }
        if (event.button.x > 728 && event.button.x < 1004  && event.button.y> 562 && event.button.y <597 )
            {
            conti=0; SDL_RemoveTimer(timer); SDL_RemoveTimer(timer1);
            }
        }
        break;
   }
if(t1==2 && chemin != NULL)
{
 j=j+1;
 for(z=0;z<N;z++)
 {
     ligne[j][z]=chemin->val[z];
 }
 if( j == 16 ) {q=0;}
 else {q=q+1;}
 post[j]=positionnement(post[j-1],N,q);
 PAR=chemin;
 chemin=chemin->suiv;
 free(PAR);
 t1=0;
}

for (i=0;i<N;i++)
                            {
                            image = chargemment(fin->val[i]);
                            CreateLettre( rendu,  image ,texture,posfin[i]);
                            SDL_DestroyTexture(texture);
                            }
for(z=0;z<=j;z++)
{
                            for (i=0;i<N;i++)
                            {
                            image = chargemment(ligne[z][i]);
                            CreateLettre( rendu,  image ,texture,post[z][i]);
                            SDL_DestroyTexture(texture);
                            }
}

choixmode =IMG_Load("menumachine.png");
SDL_BlitSurface(choixmode, NULL, ecran, NULL);

sprintf(entree,"%d",t2);
texte = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_FreeSurface(texte);

sprintf(entree,"%d",N);
texte = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte, NULL, ecran, &position1);
SDL_FreeSurface(texte);

sprintf(entree,"%d",n);
texte = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte, NULL, ecran, &position2);
SDL_FreeSurface(texte);

SDL_RenderPresent(rendu);
SDL_UpdateWindowSurface(fenetre);
SDL_FreeSurface(choixmode);

if(chemin==NULL ) {SDL_Delay(3000);  conti=0; }
}
SDL_RemoveTimer(timer); SDL_RemoveTimer(timer1);
for (i=0;i<r;i++)
{
  free(ligne[i]);
  free(post[i]);
}
free(posfin);
}

void vs(SDL_Surface * ecran , SDL_Renderer * rendu ,SDL_Window *fenetre)
{
    int i=0,j=0;
    int N, n,cpt ;
    int c,q=0,conti=1,z,v;
    int *ta;
    int t1=0,t2=0,t3=0,t4=0;
    liste tete= NULL;
    liste L,PAR,P;
    SDL_Surface *image;
    SDL_Event even;
    SDL_Surface *choixmode=NULL,*texte=NULL,*texte1=NULL,*img1=NULL;
    SDL_Texture *texture=NULL;
    SDL_Rect *fin,position,position1,position2;
    int condi=18,r1,r=1;
    int *k;
    int indx ;
    liste chemin=NULL;
    int j1=0,q1=0;
    char entree[5]="";
    SDL_TimerID timer,timer1;

int **ligne=malloc (16 * sizeof(int*));
SDL_Rect **pos=malloc (16 * sizeof(SDL_Rect*));
int **lignemachine=malloc (16 * sizeof(int*));
SDL_Rect **post1 =malloc (16 * sizeof(SDL_Rect*));

TTF_Init();

    TTF_Font *police = NULL;
    SDL_Color couleurBlanche = {255, 255, 255};

    position.x = 945;
    position.y = 8;
    position1.x = 877;
    position1.y = 52;
    position2.x = 877;
    position2.y = 97;

    police = TTF_OpenFont("timesbi.ttf", 40);

    do
    {
        srand(time(NULL));
        N = 1 + rand()%8;
    }
    while(N<4);


    tete=creer_noeud();
    tete->val=malloc(N * sizeof(int));

    if ( tete->val == NULL)
    {
        exit(0);
    }

    for (i=0; i<N; i++)
    {

        cpt = 0 ;
        z = 0;
        do
        {
            do
            {
                cpt = 1+rand()%18;
                tete->val[i] = cpt ;
                v=verif(cpt,i,tete);
            }
            while (v!=0);
                 z = z + 1 ;
            cpt = 0 ;
        }
        while(z < N );
k=malloc( N * sizeof(int)) ;
    }
    tete->suiv=NULL;
    n=2;
    z=N/2;
    if(N > 5)
    {
        do
        {
            srand(time(NULL));
            n = 2 + rand()%3;
        }
        while(n>z);
    }


    c=1;
    PAR=tete;
    P=tete;
    do
    {

        for (i=0; i<=N-n; i++)
        {
            ta=permuter(PAR,i,n,N);
            if (trouv(tete,ta,N)==0)
            {
                L=creer_noeud();
                L->ind=i;
                L->val=malloc(N* sizeof(int));
                for (z=0; z<N; z++)
                {
                    L->val[z]=ta[z];
                }
                L->suiv=NULL;
                P->suiv=L;
                P=L;
                c=c+1;

            }

        }
        PAR=PAR->suiv;
    }
    while (PAR!=NULL && c<90);


 do {
    do
    {

        r1 =3+rand()%c;
    }
    while(r1>c);
    PAR = finale(tete,r1,N);


for (z=0;z<N;z++)
{
 k[z]=PAR->val[z];

}

 r=1;


   while (condi != 2)

{
 L = trouv2(tete,k,N);
 indx=L->ind;
 creerch(&chemin,L,N);
 k=permute(k,indx,N,n);
 condi=compar2(k,tete->val,N);
 r=r+1;

}

}while(r>14);

fin = malloc(N *sizeof(SDL_Rect));

    for(i=0; i<N; i++)
    {
        fin[i].x=495+i*37;
        fin[i].y=15;
    }


    for(i=0; i<16; i++)
    {
        pos[i]= malloc ( N * sizeof (SDL_Rect));
        ligne[i]= malloc ( N * sizeof (int));
        post1[i]= malloc ( N * sizeof (SDL_Rect));
        lignemachine[i]= malloc ( N * sizeof (int));

    }

    for(i=0; i<N; i++)
    {
        ligne[0][i]=tete->val[i];
        lignemachine[0][i]=tete->val[i];
    }

    for(i=0; i<N; i++)
    {

        pos[0][i].x=50+i*37;
        pos[0][i].y=105;

        post1[0][i].x=409+i*37;
        post1[0][i].y=105;
    }

j=0;
t1=0;
t2=0;
timer=SDL_AddTimer(1016,incrementationCallback,&t1);
timer1=SDL_AddTimer(1016,incrementationCallback,&t2);
 while(conti==1)
    {
        while(SDL_PollEvent(&even))
        {
        switch(even.type)
    {

        case SDL_QUIT:
            conti=0;
            exit(0);
            break;

        case SDL_MOUSEBUTTONUP:

            if (even.button.button ==SDL_BUTTON_LEFT)
            {

                if (even.button.x > 804 && even.button.x < 920 && even.button.y> 513 && even.button.y <551 )
            {    c=1;
                t3=t2;
                t4=t1;
    while(c)
{
img1=IMG_Load("pause.png");
SDL_BlitSurface(img1, NULL, ecran, NULL);
SDL_FreeSurface(img1);
SDL_RenderPresent(rendu);

   SDL_PollEvent (&even);
   switch(even.type)
{
       case SDL_QUIT:
        c=0;
            break;
       case SDL_MOUSEBUTTONUP:
        if (even.button.button ==SDL_BUTTON_LEFT)
        {
        if (even.button.x > 317 && even.button.x < 712 && even.button.y> 408 && even.button.y <450)
             { conti=1; c=0; }
        if (even.button.x > 319 && even.button.x < 675 && even.button.y> 464 && even.button.y <503)
             { c=0; conti=0; t1=0; t2=0; t3=0; SDL_RemoveTimer(timer);SDL_RemoveTimer(timer1);}
        }
            break;
}
}
t2=t3;
t1=t4;
           }

        if (even.button.x > 728 && even.button.x < 1004  && even.button.y> 562 && even.button.y <597 )
            {
            conti=0; SDL_RemoveTimer(timer); SDL_RemoveTimer(timer1);
            }

                if (even.button.x > pos[j][0].x && even.button.x < pos[j][0].x +35 && even.button.y> pos[j][0].y && even.button.y <pos[j][0].y+35 )
                {

                    j=j+1;

                    ligne[j]=permute(ligne[j-1],0,N,n);

                        q=q+1;

                    pos[j]=positionnement1(pos[j-1], N, q );
                    v =compar2(ligne[j],PAR->val,N);

                }
                if (even.button.x > pos[j][1].x && even.button.x < pos[j][1].x +35 && even.button.y> pos[j][1].y && even.button.y <pos[j][1].y+35 )
                {

                    j=j+1;

                    ligne[j]=permute(ligne[j-1],1,N,n);


                        q=q+1;

                    pos[j]=positionnement1(pos[j-1], N, q );
                    v =compar2(ligne[j],PAR->val,N);
                }
                if (even.button.x > pos[j][2].x && even.button.x < pos[j][2].x +35 && even.button.y> pos[j][2].y && even.button.y <pos[j][2].y+35 )
                {

                    j=j+1;

                    ligne[j]=permute(ligne[j-1],2,N,n);

                        q=q+1;

                    pos[j]=positionnement1(pos[j-1], N, q );
                    v =compar2(ligne[j],PAR->val,N);
                }
                if(N-n>=3)      if (even.button.x > pos[j][3].x && even.button.x < pos[j][3].x +35 && even.button.y> pos[j][3].y && even.button.y <pos[j][3].y+35 )
                    {

                        j=j+1;

                        ligne[j]=permute(ligne[j-1],3,N,n);

                            q=q+1;

                        pos[j]=positionnement1(pos[j-1], N, q );
                        v =compar2(ligne[j],PAR->val,N);
                    }
                if(N-n>=4)       if (even.button.x > pos[j][4].x && even.button.x < pos[j][4].x +35 && even.button.y> pos[j][4].y && even.button.y <pos[j][4].y+35 )
                    {

                        j=j+1;

                        ligne[j]=permute(ligne[j-1],4,N,n);
                           q=q+1;

                        pos[j]=positionnement1(pos[j-1], N, q );
                        v =compar2(ligne[j],PAR->val,N);
                    }
                if(N-n>=5)      if (even.button.x > pos[j][5].x && even.button.x < pos[j][5].x +35 && even.button.y> pos[j][5].y && even.button.y <pos[j][5].y+35 )
                    {

                        j=j+1;

                        ligne[j]=permute(ligne[j-1],5,N,n);

                            q=q+1;

                        pos[j]=positionnement1(pos[j-1], N, q );
                        v =compar2(ligne[j],PAR->val,N);
                    }
                if(N-n>=6)      if (even.button.x > pos[j][6].x && even.button.x < pos[j][6].x +35 && even.button.y> pos[j][6].y && even.button.y <pos[j][6].y+35 )
                    {

                        j=j+1;

                        ligne[j]=permute(ligne[j-1],6,N,n);

                            q=q+1;

                        pos[j]=positionnement1(pos[j-1], N, q );
                        v =compar2(ligne[j],PAR->val,N);
                    }

             break;
            }
            }
 }

if(t1==2 && chemin != NULL)
{
 j1=j1+1;
 for(z=0;z<N;z++)
 {
     lignemachine[j1][z]=chemin->val[z];
 }
 q1=q1+1;
 post1[j1]=positionnement1(post1[j1-1],N,q1);
 P=chemin;
 chemin=chemin->suiv;
 free(P);
 t1=0;

}
        for (i=0; i<N; i++)
        {
            image = chargemment(PAR->val[i]);
            CreateLettre( rendu,  image,texture,fin[i]);
            SDL_DestroyTexture(texture);
        }
        for(z=0; z<=j; z++)
        {
            for (i=0; i<N; i++)
            {
                image = chargemment(ligne[z][i]);
                CreateLettre( rendu,  image,texture,pos[z][i]);
                SDL_DestroyTexture(texture);
            }
        }
        for(z=0;z<=j1;z++)
{
                            for (i=0;i<N;i++)
                            {
                            image = chargemment(lignemachine[z][i]);
                            CreateLettre( rendu,  image ,texture,post1[z][i]);
                            SDL_DestroyTexture(texture);
                            }
}


choixmode =IMG_Load("vs.png");
SDL_BlitSurface(choixmode, NULL, ecran, NULL);

sprintf(entree,"%d",t2);
texte1 = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte1, NULL, ecran, &position);
SDL_FreeSurface(texte1);

sprintf(entree,"%d",N);
texte = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte, NULL, ecran, &position1);
SDL_FreeSurface(texte);

sprintf(entree,"%d",n);
texte = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte, NULL, ecran, &position2);
SDL_FreeSurface(texte);

SDL_RenderPresent(rendu);
SDL_UpdateWindowSurface(fenetre);
SDL_FreeSurface(choixmode);
        if (v==2)

        {
              SDL_Delay(3000);

            conti = 0;
            int f=t2;
            gagne(rendu,ecran,fenetre,f);
        }
        if (chemin==NULL || j == 13)

        {

              SDL_Delay(3000);

            perte(rendu,ecran,fenetre);
            conti = 0;

        }
            }

 SDL_RemoveTimer(timer);
 SDL_RemoveTimer(timer1);
for (i=0;i<16;i++)
{
  free(ligne[i]);
  free(pos[i]);
  free(lignemachine[i]);
  free(post1[i]);
}
free(fin);
TTF_CloseFont(police);
}

void chargerjouersolo(SDL_Renderer *rendu,SDL_Surface*ecran,SDL_Window *fenetre )
 {
    int i=0,j=0;
    int N, n ,c,t2;
    int q=0,conti=1;
    int z,v;
    char entree[3]="";
    int **ligne=malloc (30 * sizeof(int*));
    char nom[20];
    liste PAR = creer_noeud();
    SDL_Rect **pos =malloc (30 * sizeof(SDL_Rect*));
    SDL_Surface *image,*texte=NULL;
    SDL_Surface* img1=NULL;
    SDL_Rect position,position1,position2;
    SDL_Event even;
    SDL_Surface *choixmode;
    SDL_Texture *texture=NULL;
    SDL_Rect *fin;
    SDL_TimerID timer;
    int t1 = 0;
    FILE * f =NULL;

TTF_Init();
    TTF_Font *police = NULL;
    SDL_Color couleurBlanche = {255, 255, 255};

    position.x = 945;
    position.y = 8;
    position1.x = 877;
    position1.y = 52;
    position2.x = 877;
    position2.y = 97;

    police = TTF_OpenFont("timesbi.ttf", 40);

f=fopen("sauvegarde.txt","r");
fscanf(f,"%d/%d/%d/%d\n%s\n",&N,&n,&j,&t1,nom);
printf("%s",nom);


    for(i=0;i<30;i++)
 {
   pos[i]= malloc ( N * sizeof (SDL_Rect));
   ligne[i]= malloc ( N * sizeof (int));
 }

PAR->ind =0;
PAR->suiv=NULL;
PAR->val=malloc(N*sizeof(int));
fin = malloc(N *sizeof(SDL_Rect));

    for(i=0; i<N; i++)
    {

        pos[0][i].x=176+i*37;
        pos[0][i].y=50;
        fin[i].x=495+i*37;
        fin[i].y=10;

    }

for(z=0;z<=j;z++)
{

    for(i=0;i<N-1;i++)
{
fscanf(f,"%d/",&ligne[z][i]);
}
fscanf(f,"%d\n",&ligne[z][N-1]);

}

for(i=0;i<N-1;i++)
{
fscanf(f,"%d/",&PAR->val[i]);
}
fscanf(f,"%d\n",&PAR->val[N-1]);

fclose(f);

 v=0;

 for(z=1;z<=j;z++)
 {
     if( j == 16  ) {q=0;}
                else {q=q+1;}
                pos[z]=positionnement(pos[z-1], N , q );

 }

timer=SDL_AddTimer(1016,incrementationCallback,&t1);
while(conti==1)
    {

 SDL_PollEvent(&even);
        switch(even.type)
        {

        case SDL_QUIT:
            conti=0;
            exit(0);
            break;

        case SDL_MOUSEBUTTONUP:

            if (even.button.button ==SDL_BUTTON_LEFT)
            {

                if (even.button.x > pos[j][0].x && even.button.x < pos[j][0].x +35 && even.button.y> pos[j][0].y && even.button.y <pos[j][0].y+35 )
                {

                    j=j+1;

                    ligne[j]=permute(ligne[j-1],0,N,n);
                    if( j == 16  )
                    {
                        q=0;
                    }
                    else
                    {
                        q=q+1;
                    }
                    pos[j]=positionnement(pos[j-1], N, q );
                    v =compar2(ligne[j],PAR->val,N);

                }
                if (even.button.x > pos[j][1].x && even.button.x < pos[j][1].x +35 && even.button.y> pos[j][1].y && even.button.y <pos[j][1].y+35 )
                {

                    j=j+1;

                    ligne[j]=permute(ligne[j-1],1,N,n);
                    if( j == 16 )
                    {
                        q=0;
                    }
                    else
                    {
                        q=q+1;
                    }
                    pos[j]=positionnement(pos[j-1], N, q );
                    v =compar2(ligne[j],PAR->val,N);
                }
                if (even.button.x > pos[j][2].x && even.button.x < pos[j][2].x +35 && even.button.y> pos[j][2].y && even.button.y <pos[j][2].y+35 )
                {

                    j=j+1;

                    ligne[j]=permute(ligne[j-1],2,N,n);
                    if( j == 16 )
                    {
                        q=0;
                    }
                    else
                    {
                        q=q+1;
                    }
                    pos[j]=positionnement(pos[j-1], N, q );
                    v =compar2(ligne[j],PAR->val,N);
                }
                if(N-n>=3)      if (even.button.x > pos[j][3].x && even.button.x < pos[j][3].x +35 && even.button.y> pos[j][3].y && even.button.y <pos[j][3].y+35 )
                    {

                        j=j+1;

                        ligne[j]=permute(ligne[j-1],3,N,n);
                        if( j == 16 )
                        {
                            q=0;
                        }
                        else
                        {
                            q=q+1;
                        }
                        pos[j]=positionnement(pos[j-1], N, q );
                        v =compar2(ligne[j],PAR->val,N);
                    }
                if(N-n>=4)       if (even.button.x > pos[j][4].x && even.button.x < pos[j][4].x +35 && even.button.y> pos[j][4].y && even.button.y <pos[j][4].y+35 )
                    {
                        j=j+1;

                        ligne[j]=permute(ligne[j-1],4,N,n);
                        if( j == 16 )
                        {
                            q=0;
                        }
                        else
                        {
                            q=q+1;
                        }
                        pos[j]=positionnement(pos[j-1], N, q );
                        v =compar2(ligne[j],PAR->val,N);
                    }
                if(N-n>=5)      if (even.button.x > pos[j][5].x && even.button.x < pos[j][5].x +35 && even.button.y> pos[j][5].y && even.button.y <pos[j][5].y+35 )
                    {

                        j=j+1;

                        ligne[j]=permute(ligne[j-1],5,N,n);
                        if( j == 16 )
                        {
                            q=0;
                        }
                        else
                        {
                            q=q+1;
                        }
                        pos[j]=positionnement(pos[j-1], N, q );
                        v =compar2(ligne[j],PAR->val,N);
                    }
                if(N-n>=6)      if (even.button.x > pos[j][6].x && even.button.x < pos[j][6].x +35 && even.button.y> pos[j][6].y && even.button.y <pos[j][6].y+35 )
                    {

                        j=j+1;

                        ligne[j]=permute(ligne[j-1],6,N,n);
                        if( j == 16 )
                        {
                            q=0;
                        }
                        else
                        {
                            q=q+1;
                        }
                        pos[j]=positionnement(pos[j-1], N, q );
                        v =compar2(ligne[j],PAR->val,N);
                    }
                  if (even.button.x > 839 && even.button.x < 930 && even.button.y> 477 && even.button.y <505 )
                    {
                c=1;
                t2=t1;

                    while(c)
                    {
                        img1=IMG_Load("pause.png");
                        SDL_BlitSurface(img1, NULL, ecran, NULL);
                        SDL_FreeSurface(img1);
                        SDL_RenderPresent(rendu);

                        SDL_PollEvent (&even);
                        switch(even.type)
{
       case SDL_QUIT:
        c=0;
            break;
       case SDL_MOUSEBUTTONUP:
        if (even.button.button ==SDL_BUTTON_LEFT)
        {
        if (even.button.x > 317 && even.button.x < 712 && even.button.y> 408 && even.button.y <450)
             { conti=1; c=0; }
        if (even.button.x > 319 && even.button.x < 675 && even.button.y> 464 && even.button.y <503)
             { c=0; conti=0; t1=0; t2=0; SDL_RemoveTimer(timer);}
        }
            break;
}
                    }
                t1=t2;
                    }
        if (even.button.x > 759 && even.button.x < 1009  && even.button.y> 519 && even.button.y <557 )
            {
            conti=0;
            }
        if (even.button.x >771 && even.button.x <996 && even.button.y>563 && even.button.y <600 )
        {
f=fopen("sauvegarde.txt","w");
fprintf(f,"%d/%d/%d/%d\n%s\n",N,n,j,t1,nom);

for(z=0;z<=j;z++)
{
for(i=0;i<N-1;i++)
{
fprintf(f,"%d/",ligne[z][i]);
}
fprintf(f,"%d\n",ligne[z][N-1]);
}
for(i=0;i<N-1;i++)
{
fprintf(f,"%d/",PAR->val[i]);
}
fprintf(f,"%d\n",PAR->val[N-1]);
fclose(f);
conti=0;
        }
            }
            break;
        }


        for (i=0; i<N; i++)
        {
            image = chargemment(PAR->val[i]);
            CreateLettre( rendu,  image,texture,fin[i]);
        }
        for(z=0; z<=j; z++)
        {
            for (i=0; i<N; i++)
            {
                image = chargemment(ligne[z][i]);
                CreateLettre( rendu,  image,texture,pos[z][i]);
            }
        }

choixmode =IMG_Load("menujeu.png");
SDL_BlitSurface(choixmode, NULL, ecran, NULL);

sprintf(entree,"%d",t1);
texte = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte, NULL, ecran, &position);
SDL_FreeSurface(texte);

sprintf(entree,"%d",N);
texte = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte, NULL, ecran, &position1);
SDL_FreeSurface(texte);

sprintf(entree,"%d",n);
texte = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte, NULL, ecran, &position2);
SDL_FreeSurface(texte);

SDL_RenderPresent(rendu);
SDL_UpdateWindowSurface(fenetre);
SDL_FreeSurface(choixmode);

if(v==2 ) {f=fopen("sauvegarde.txt","w");
            fprintf(f,"%d/",0);
            fclose(f);
            joueur x; x.score=t1; strcpy(x.nom1,nom); meilleur_scores (x); SDL_Delay (3000); gagne(rendu,ecran,fenetre,x.score);
            conti=0; }

if(j==31 ) {f=fopen("sauvegarde.txt","w");
            fprintf(f,"%d/",0);
            fclose(f);    perte(rendu,ecran,fenetre); conti=0;  }
}
SDL_RemoveTimer(timer);
for (i=0;i<30;i++)
{
  free(ligne[i]);
  free(pos[i]);
}
}

