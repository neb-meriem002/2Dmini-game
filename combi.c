#include <stdio.h>
#include <stdlib.h>
#include"combi.h"


liste creer_noeud()
{
    liste nouv=malloc(sizeof(noeud));
if(nouv==NULL)
    {
    printf("erreur memoire saturee");
    exit(-1);
    }
return nouv;
}


void affichage_liste(liste t,int N)
{
    int i;
    if (t==NULL) {printf ("liste vide");}
 do
    {
printf ("\n");
for(i=0;i<N;i++)
{

printf("%d       ",t->val[i]);

}
  t=t->suiv;

    }
while (t!=NULL);
}



int* permuter(liste p,int j,int n,int N)
{
 int *pp=malloc(N * sizeof(int));
 int k,h,tmp;
 int i;


for (k=0;k<N;k++)
{
pp[k]=p->val[k];
}

k=j+n-1;
h=(j+k)/2;

if((n % 2) != 0)
{
    pp[h]=-pp[h];
    for(i=j;i<h;i++)
{
    tmp=-pp[i];
    pp[i]=-pp[k];
    pp[k]=tmp;
    k=k-1;
}

}
else
{
for(i=j;i<=h;i++)
{
    tmp=-pp[i];
    pp[i]=-pp[k];
    pp[k]=tmp;
    k=k-1;
}
}



return pp;
}


int trouv(liste t,int tableau[], int N)
{
int z,cpt;
do
{
cpt=0;
for (z=0;z<N;z++)
{
if (t->val[z]==tableau[z]) {cpt=cpt+1;}
}
if (cpt==N)
{return 1;}
t=t->suiv;
}
while (t!=NULL);
return 0;
}

int verif(int e,int j,liste t)
{
    int z;
  if (j==0) {return 0;}
  else
  {
   for(z=0;z<j;z++)
   {
       if (e==(t->val[z])) {return 1;}
   }
  }

   return 0;

}

int* permute(int ta[], int j, int N , int n)

{
 int *pp;
 int k,h,tmp;
 int i;

pp = malloc(N*sizeof(int));
for (k=0;k<N;k++)
{
pp[k]=ta[k];
}

k=j+n-1;
h=(j+k)/2;

if((n % 2) != 0)
{
    pp[h]=-pp[h];
    for(i=j;i<h;i++)
{
    tmp=-pp[i];
    pp[i]=-pp[k];
    pp[k]=tmp;
    k=k-1;
}

}
else
{
for(i=j;i<=h;i++)
{
    tmp=-pp[i];
    pp[i]=-pp[k];
    pp[k]=tmp;
    k=k-1;
}
}



return pp;
}


liste trouv2(liste t,int tableau[], int N)
{
 liste p=NULL;
 int a=1;
 while(t!=NULL && a==1)
 {
   a=compar2(tableau,t->val,N);
   if (a==1) {t=t->suiv;}
   else {p=t;}
 }

return p;
}

int compar2(int t[], int g[] ,int N )
  {
      int i; int cpt ;
      cpt = 0 ;


      for (i=0;i<N;i++)
      {

         if(g[i]==t[i]) {cpt=cpt+1;}

      }

      if (cpt==N)   {         return 2;}
      else          {         return 1;}

  }

liste finale(liste tete,int r,int N)
{
int c=0;
while (c!=r)
{
    tete=tete->suiv;
    c=c+1;
}
return tete;

}

void creerch(liste* t,liste to,int N)
{
 liste n;
 int i=0;

 n=creer_noeud();
 n->val=malloc(N* sizeof(int));
 do
{
 n->val[i]=to->val[i];
 i=i+1;
}
while (i<N);

  n->ind=to->ind;
  n->suiv=*t;
  *t=n;

}


