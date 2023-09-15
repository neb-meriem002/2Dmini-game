#ifndef COMBI_H_INCLUDED
#define COMBI_H_INCLUDED

 typedef struct cellule* liste;
 typedef struct cellule
    {
        int* val;
        liste *suiv;
        int ind;
    }noeud;


liste creer_noeud();
void ajout_tete(liste *tete, int e);
void affichage_liste(liste t,int N);


int* permuter(liste p,int j,int n,int N);
int trouv(liste t,int tableau[], int N);
void combi(liste t,int* c,int N,int n);
int verif(int e,int j,liste t);
int* permute(int ta[], int j, int N , int n);
liste trouv2(liste t,int tableau[], int N);
int compar2(int t[], int g[] ,int N );
liste finale(liste tete,int r,int N);
void creerch(liste* t,liste to,int N);

#endif // COMBI_H_INCLUDED
