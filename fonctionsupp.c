#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_image.h>
#include <string.h>
#include <SDL_ttf.h>
#include "fonctionsupp.h"
#include "combi.h"
#include "time.h"

void nettoyage_resources (SDL_Window *w, SDL_Renderer *r)
{

if(r != NULL)
{SDL_DestroyRenderer (r);}
if(w != NULL)
{SDL_DestroyWindow (w) ;}

SDL_Quit() ;
}

SDL_Surface * chargemment( int x )
 {

int length;   char* str; SDL_Surface * m ;
length = snprintf( NULL, 0, "%d",  x);
str = malloc( length + 5 );
snprintf( str, length + 1, "%d", x );

  str[length]='.';
  str[length+1]='b' ;
  str[length+2]='m' ;
  str[length+3]='p' ;
  str[length+4]='\0' ;

m =IMG_Load(str);

return m;
 }


void CreateLettre(SDL_Renderer *r,SDL_Surface *img,SDL_Texture *t_lettre,SDL_Rect rectangle)
{

    t_lettre = SDL_CreateTextureFromSurface(r, img);
    SDL_FreeSurface(img);

    SDL_QueryTexture(t_lettre, NULL, NULL, &rectangle.w, &rectangle.h);
    SDL_RenderCopy(r, t_lettre, NULL, &rectangle);

}

SDL_Rect* positionnement( SDL_Rect p[], int N , int q )
{ int i ;  int qq =0;
SDL_Rect *pp;
pp=malloc(N * sizeof(SDL_Rect));
 for(i=0;i<N;i++)

       {pp[i].y =p[i].y;
        pp[i].x =p[i].x;
        pp[i].w =p[i].w;
        pp[i].h =p[i].h;}

     if(pp[0].y == 605 )
            {
                for(i=0;i<N;i++)
                {   pp[i].x = 450+37*qq;
                    qq= qq+1;
                }
            }
            for(i=0;i<N;i++)
        { pp[i].y =50+37*q; }

        return pp ;
}

SDL_Rect* positionnement1( SDL_Rect p[], int N , int q )
{ int i ;
SDL_Rect *pp;
pp=malloc(N * sizeof(SDL_Rect));
 for(i=0;i<N;i++)

       {pp[i].y =p[i].y;
        pp[i].x =p[i].x;
        pp[i].h =p[i].h;
        pp[i].w =p[i].w;
       }
            for(i=0;i<N;i++)
        { pp[i].y =105+37*q; }

        return pp ;
}



void meilleur_scores (joueur x)
{
  int point[5];
  char nom[5][20];
  int date[5][3];
  FILE* f=NULL,*f1=NULL;
  int j,k,nb;
  time_t timestamp;
  struct tm * t;
  timestamp = time(NULL);
  t = localtime(&timestamp);

f1=fopen("nbrecores.txt","r");
fscanf(f1,"%d",&nb);
fclose(f1);

if (nb==0)
{
f=fopen("rec.txt","w");
fprintf(f,"%d/%s %d/%d/%d",x.score,x.nom1, t->tm_mday,t->tm_mon + 1,1900 + t->tm_year);
fclose(f);

f1=fopen("nbrecores.txt","w");
fprintf(f1,"%d",1);
fclose(f1);
}

else
{
if (nb==1)
{
f=fopen("rec.txt","r");
if (f!=NULL)
{
    fscanf(f,"%d/%s %d/%d/%d",&point[0],nom[0],&date[0][0],&date[0][1],&date[0][2]);
    fclose(f);
}
if (x.score<point[0])
          {
              for(j=1;j>0;j--)
              {
               point[j]=point[j-1];
               date[j][0]=date[j-1][0];
               date[j][1]=date[j-1][1];
               date[j][2]=date[j-1][2];
               strcpy(nom[j],nom[j-1]);
              }

               point[0]=x.score;
               strcpy(nom[0],x.nom1);
               date[0][0]=t->tm_mday;
               date[0][1]=t->tm_mon + 1;
               date[0][2]=1900 + t->tm_year;
          }
 else {
               point[1]=x.score;
               strcpy(nom[1],x.nom1);
               date[1][0]=t->tm_mday;
               date[1][1]=t->tm_mon + 1;
               date[1][2]=1900 + t->tm_year;
      }

f=fopen("rec.txt","w");
if (f!=NULL)
{
fprintf(f,"%d/%s %d/%d/%d\n%d/%s %d/%d/%d",point[0],nom[0],date[0][0],date[0][1],date[0][2],point[1],nom[1],date[1][0],date[1][1],date[1][2]);
fclose(f);
}
f1=fopen("nbrecores.txt","w");
fprintf(f1,"%d",2);
fclose(f1);
    }

if (nb==2)
{
f=fopen("rec.txt","r");
if (f!=NULL)
{
    fscanf(f,"%d/%s %d/%d/%d\n%d/%s %d/%d/%d",&point[0],nom[0],&date[0][0],&date[0][1],&date[0][2],&point[1],nom[1],&date[1][0],&date[1][1],&date[1][2]);
    fclose(f);
}
if (x.score<=point[0])
          {
              for(j=2;j>0;j--)
              {
               point[j]=point[j-1];
               date[j][0]=date[j-1][0];
               date[j][1]=date[j-1][1];
               date[j][2]=date[j-1][2];
               strcpy(nom[j],nom[j-1]);

              }
               point[0]=x.score;
               strcpy(nom[0],x.nom1);
               date[0][0]=t->tm_mday;
               date[0][1]=t->tm_mon + 1;
               date[0][2]=1900 + t->tm_year;
          }
 else {
    for(j=0;j<1;j++)
    {
 if(x.score<=point[j+1] && x.score >point[j])
    {
            for(k=2;k>j+1;k--)
                {
               point[k]=point[k-1];
               strcpy(nom[k],nom[k-1]);
               date[k][0]=date[k-1][0];
               date[k][1]=date[k-1][1];
               date[k][2]=date[k-1][2];
                }
        point[j+1]=x.score;
        strcpy(nom[j+1],x.nom1);
        date[j+1][0]=t->tm_mday;
        date[j+1][1]=t->tm_mon + 1;
        date[j+1][2]=1900 + t->tm_year;
    }
    }
if (x.score>point[1])
{
 point[2]=x.score;
 strcpy(nom[2],x.nom1);
 date[2][0]=t->tm_mday;
 date[2][1]=t->tm_mon + 1;
 date[2][2]=1900 + t->tm_year;
}
 }

f=fopen("rec.txt","w");
if (f!=NULL)
{
fprintf(f,"%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d",point[0],nom[0],date[0][0],date[0][1],date[0][2],point[1],nom[1],date[1][0],date[1][1],date[1][2],point[2],nom[2],date[2][0],date[2][1],date[2][2]);
fclose(f);
}
f1=fopen("nbrecores.txt","w");
fprintf(f1,"%d",3);
fclose(f1);
}

if (nb==3)
{
f=fopen("rec.txt","r");
if (f!=NULL)
{
    fscanf(f,"%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d",&point[0],nom[0],&date[0][0],&date[0][1],&date[0][2],&point[1],nom[1],&date[1][0],&date[1][1],&date[1][2],&point[2],nom[2],&date[2][0],&date[2][1],&date[2][2]);
    fclose(f);
}
if (x.score<=point[0])
          {
              for(j=3;j>0;j--)
              {

               point[j]=point[j-1];
               date[j][0]=date[j-1][0];
               date[j][1]=date[j-1][1];
               date[j][2]=date[j-1][2];
               strcpy(nom[j],nom[j-1]);

              }
               point[0]=x.score;
               strcpy(nom[0],x.nom1);
               date[0][0]=t->tm_mday;
               date[0][1]=t->tm_mon + 1;
               date[0][2]=1900 + t->tm_year;
          }
 else {
    for(j=0;j<2;j++)
    {
 if(x.score<=point[j+1] && x.score >point[j])
    {
            for(k=3;k>j+1;k--)
                {
                point[k]=point[k-1];
               strcpy(nom[k],nom[k-1]);
               date[k][0]=date[k-1][0];
               date[k][1]=date[k-1][1];
               date[k][2]=date[k-1][2];
                }
        point[j+1]=x.score;
        strcpy(nom[j+1],x.nom1);
        date[j+1][0]=t->tm_mday;
        date[j+1][1]=t->tm_mon + 1;
        date[j+1][2]=1900 + t->tm_year;
    }
    }
if (x.score>point[2])
{
 point[3]=x.score;
 strcpy(nom[3],x.nom1);
 date[3][0]=t->tm_mday;
 date[3][1]=t->tm_mon + 1;
 date[3][2]=1900 + t->tm_year;
}
 }

f=fopen("rec.txt","w");
if (f!=NULL)
{
fprintf(f,"%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d",point[0],nom[0],date[0][0],date[0][1],date[0][2],point[1],nom[1],date[1][0],date[1][1],date[1][2],point[2],nom[2],date[2][0],date[2][1],date[2][2],point[3],nom[3],date[3][0],date[3][1],date[3][2]);
fclose(f);
}
f1=fopen("nbrecores.txt","w");
fprintf(f1,"%d",4);
fclose(f1);
}
//
if (nb==4)
{
f=fopen("rec.txt","r");
if (f!=NULL)
{
    fscanf(f,"%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d",&point[0],nom[0],&date[0][0],&date[0][1],&date[0][2],&point[1],nom[1],&date[1][0],&date[1][1],&date[1][2],&point[2],nom[2],&date[2][0],&date[2][1],&date[2][2],&point[3],nom[3],&date[3][0],&date[3][1],&date[3][2]);
    fclose(f);
}
if (x.score<=point[0])
          {
              for(j=4;j>0;j--)
              {
               point[j]=point[j-1];
               date[j][0]=date[j-1][0];
               date[j][1]=date[j-1][1];
               date[j][2]=date[j-1][2];
               strcpy(nom[j],nom[j-1]);
              }

               point[0]=x.score;
               strcpy(nom[0],x.nom1);
               date[0][0]=t->tm_mday;
               date[0][1]=t->tm_mon + 1;
               date[0][2]=1900 + t->tm_year;

          }
 else {
    for(j=0;j<3;j++)
    {
 if(x.score<=point[j+1] && x.score >point[j])
    {
            for(k=4;k>j+1;k--)
                {
               point[k]=point[k-1];
               strcpy(nom[k],nom[k-1]);
               date[k][0]=date[k-1][0];
               date[k][1]=date[k-1][1];
               date[k][2]=date[k-1][2];
                }
        point[j+1]=x.score;
        strcpy(nom[j+1],x.nom1);
        date[j+1][0]=t->tm_mday;
        date[j+1][1]=t->tm_mon + 1;
        date[j+1][2]=1900 + t->tm_year;
    }
    }
if (x.score>point[3])
{
  point[4]=x.score;
 strcpy(nom[4],x.nom1);
 date[4][0]=t->tm_mday;
 date[4][1]=t->tm_mon + 1;
 date[4][2]=1900 + t->tm_year;
}
 }
f1=fopen("nbrecores.txt","w");
fprintf(f1,"%d",5);
fclose(f1);
f=fopen("rec.txt","w");
if (f!=NULL)
{
fprintf(f,"%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d",point[0],nom[0],date[0][0],date[0][1],date[0][2],point[1],nom[1],date[1][0],date[1][1],date[1][2],point[2],nom[2],date[2][0],date[2][1],date[2][2],point[3],nom[3],date[3][0],date[3][1],date[3][2],point[4],nom[4],date[4][0],date[4][1],date[4][2]);
fclose(f);
}
}
///
if (nb==5)
{
f=fopen("rec.txt","r");
if (f!=NULL)
{
    fscanf(f,"%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d",&point[0],nom[0],&date[0][0],&date[0][1],&date[0][2],&point[1],nom[1],&date[1][0],&date[1][1],&date[1][2],&point[2],nom[2],&date[2][0],&date[2][1],&date[2][2],&point[3],nom[3],&date[3][0],&date[3][1],&date[3][2],&point[4],nom[4],&date[4][0],&date[4][1],&date[4][2]);
    fclose(f);
}
if (x.score<=point[0])
          {
              for(j=4;j>0;j--)
                 {
               point[j]=point[j-1];
               date[j][0]=date[j-1][0];
               date[j][1]=date[j-1][1];
               date[j][2]=date[j-1][2];
               strcpy(nom[j],nom[j-1]);
              }

               point[0]=x.score;
               strcpy(nom[0],x.nom1);
               date[0][0]=t->tm_mday;
               date[0][1]=t->tm_mon + 1;
               date[0][2]=1900 + t->tm_year;

f=fopen("rec.txt","w");

if (f!=NULL)
{
fprintf(f,"%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d",point[0],nom[0],date[0][0],date[0][1],date[0][2],point[1],nom[1],date[1][0],date[1][1],date[1][2],point[2],nom[2],date[2][0],date[2][1],date[2][2],point[3],nom[3],date[3][0],date[3][1],date[3][2],point[4],nom[4],date[4][0],date[4][1],date[4][2]);
fclose(f);
}
          }
 else {
    for(j=0;j<4;j++)
      {
 if(x.score<=point[j+1] && x.score >point[j])
    {
            for(k=4;k>j+1;k--)
                {
               point[k]=point[k-1];
               strcpy(nom[k],nom[k-1]);
               date[k][0]=date[k-1][0];
               date[k][1]=date[k-1][1];
               date[k][2]=date[k-1][2];
                }
        point[j+1]=x.score;
        strcpy(nom[j+1],x.nom1);
        date[j+1][0]=t->tm_mday;
        date[j+1][1]=t->tm_mon + 1;
        date[j+1][2]=1900 + t->tm_year;

f=fopen("rec.txt","w");

if (f!=NULL)
{
fprintf(f,"%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d\n%d/%s %d/%d/%d",point[0],nom[0],date[0][0],date[0][1],date[0][2],point[1],nom[1],date[1][0],date[1][1],date[1][2],point[2],nom[2],date[2][0],date[2][1],date[2][2],point[3],nom[3],date[3][0],date[3][1],date[3][2],point[4],nom[4],date[4][0],date[4][1],date[4][2]);
fclose(f);

}}}}}}
}

void best_scores(SDL_Surface* ecran,SDL_Renderer* rendu,SDL_Window *fenetre)
{
  int point[5];
  char nom[5][20];
  char str[52];
  int date[5][3];
  char entree[20]="";
  FILE* f=NULL,*f1=NULL;
  int i,nb;
  int cont=1;
  SDL_Surface *choixmode,*texte1,*texte[5];
  SDL_Event even;
  SDL_Rect posnom[5],posdate[5],posscores[5];
  SDL_Rect position;

TTF_Init();

    SDL_Color couleurBlanche = {255, 255, 255};
    TTF_Font *police = NULL;
    police = TTF_OpenFont("timesbi.ttf", 35);

f1=fopen("nbrecores.txt","r");
fscanf(f1,"%d",&nb);
fclose(f1);

if (nb==0)
{
strcpy(str,"'Pas de scores enrengistées dans le fichier'");

position.x=193;
position.y=205;
}
else
{
f=fopen("rec.txt","r");
if (f!=NULL)
{
    for (i=0;i<nb;i++)
{
    fscanf(f,"%d/%s %d/%d/%d\n",&point[i],nom[i],&date[i][0],&date[i][1],&date[i][2]);
}
}
 fclose(f);
}

for(i=0;i<5;i++)
{
    posnom[i].x=300;
    posscores[i].x=485;
    posdate[i].x=560;
    posnom[i].y=210+42*i;
    posscores[i].y=210+42*i;
    posdate[i].y=210+42*i;
}

while (cont)
{
SDL_PollEvent (&even);


 switch(even.type)
 {
    case SDL_QUIT:
        cont=0;
        exit (0);
            break;
      case SDL_MOUSEBUTTONUP:

            if (even.button.button ==SDL_BUTTON_LEFT)
            {
                if (even.button.x > 719 && even.button.x < 990 && even.button.y> 580 && even.button.y <617 )
                { cont =0; }

            }
            break;
 }


choixmode =IMG_Load("scores.png");
SDL_BlitSurface(choixmode, NULL, ecran, NULL);
if (nb==0)
{
texte1 = TTF_RenderText_Blended(police, str, couleurBlanche);
SDL_BlitSurface(texte1, NULL, ecran, &position);
SDL_FreeSurface(texte1);
}
else
{
for (i=0;i<nb;i++)
{
texte[i] = TTF_RenderText_Blended(police, nom[i], couleurBlanche);
SDL_BlitSurface(texte[i], NULL, ecran, &posnom[i]);
SDL_FreeSurface(texte[i]);

sprintf(entree,"%d s",point[i]);
texte[i] = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte[i], NULL, ecran, &posscores[i]);
SDL_FreeSurface(texte[i]);

sprintf(entree,"%d/%d/%d",date[i][0],date[i][1],date[i][2]);
texte[i] = TTF_RenderText_Blended(police, entree, couleurBlanche);
SDL_BlitSurface(texte[i], NULL, ecran, &posdate[i]);
SDL_FreeSurface(texte[i]);
}

}

SDL_RenderPresent(rendu);
SDL_UpdateWindowSurface(fenetre);
SDL_FreeSurface(choixmode);

}

}

