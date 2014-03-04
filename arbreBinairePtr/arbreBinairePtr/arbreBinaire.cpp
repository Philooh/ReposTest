// arbreBinaire.cpp

#include "stdafx.h"
#include "stdlib.h"
#include "arbreBinaire.h"
#include <string>
#include <iostream>

using namespace System;
using namespace std;


/* creation d'un arbre */
void arbreCreate(unNoeud **arbre) {

 try {
   *arbre = nullptr;
 }
 catch (Exception ^ex) {
   throw ex;
 }
}

/* initialisation d'un arbre */
void arbreClear(unNoeud **arbre) {
 unNoeud *courant;

 try {
   courant = *arbre;
   while (courant != nullptr) {
     arbreDelete(arbre, courant->info);
     courant = *arbre;
   }
 }
 catch (Exception ^ex) {
   throw ex;
 }
}

/* test si un arbre est vide */
bool arbreVide (unNoeud *arbre) {

 try {
   if (arbre == NULL)
     return true;
   else
     return false;
 }
 catch (Exception ^ex) {
   throw ex;
 }
}

/* insertion d'un noeud dans l'arbre */
void arbreInsert (unNoeud **arbre, int n) {
 unNoeud *courant, *precedent, *nouveau;

 try {
   nouveau = new unNoeud;
   nouveau->info = n;
   nouveau->gauche = nullptr;
   nouveau->droite = nullptr;

   precedent = nullptr;
   courant = *arbre;
   while (courant != nullptr){
     precedent = courant;
     if (nouveau->info > courant->info)
       courant = courant->droite;
     else
       courant=courant->gauche;
   }
   if (precedent == nullptr)
     *arbre = nouveau;
   else {
     if (nouveau->info > precedent->info)
       precedent->droite = nouveau;
     else
       precedent->gauche = nouveau;
   }
 }
 catch (Exception ^ex) {
   throw ex;
 }
}

/* retrait d'un noeud dans l'arbre */
bool arbreDelete(unNoeud **arbre, int n) {
 unNoeud *courant, *precedent, *temp;

 try {
   precedent=nullptr;
   courant = *arbre;
   while (courant != nullptr && n != courant->info) {
     precedent = courant;
     if (n > courant->info)
       courant = courant->droite;
     else
       courant=courant->gauche;
   }
/* pas dans l'arbre */
   if (courant == nullptr) 
     return false; 

/* si feuille */
   if (courant->gauche == nullptr && courant->droite == nullptr) {
  /* si racine */
     if (precedent == nullptr)
       *arbre = nullptr;
     else
  /* si pas racine */
       if (precedent->gauche == courant)
         precedent->gauche = nullptr;
       else
         precedent->droite = nullptr;
   }
/* si deux enfants */
   else if (courant->gauche != nullptr && courant->droite != nullptr) {
     precedent = courant;
     temp = courant->gauche;
     while (temp->droite != nullptr) {
       precedent = temp;
       temp = temp->droite;
     }
     courant->info = temp->info;
     /* (1) enfant sinon (0) enfant car temp=>droite est à nullptr */
     if (temp->gauche != nullptr)
       if (precedent->gauche == temp)
         precedent->gauche = temp->gauche;
       else
         precedent->droite = temp->gauche;
     else
       if (precedent->gauche == temp)
         precedent->gauche = nullptr;
       else
         precedent->droite = nullptr;
     courant = temp;
   }

/* si un enfant */
   else {
     if (courant->gauche != nullptr)
  /* si racine */
       if (precedent == nullptr)
         *arbre = courant->gauche;
       else
  /* si pas racine */
         if (precedent->gauche == courant)
           precedent->gauche = courant->gauche;
         else
           precedent->droite = courant->gauche;
     else
  /* si racine */
       if (precedent == nullptr)
         *arbre = courant->droite;
       else
   /* si pas racine */
         if (precedent->gauche == courant)
           precedent->gauche = courant->droite;
         else
           precedent->droite = courant->droite;
   }
   delete courant;
   return true;
 }
 catch (Exception ^ex) {
   throw ex;
 }
}

void arbreInOrder(unNoeud *arbre, char *s) {

 try {
   if (arbre != nullptr) {
     arbreInOrder(arbre->gauche, s);
     sprintf_s(s, 100, "%s %d", s, arbre->info);
     arbreInOrder(arbre->droite, s);
   }
 }
 catch (Exception ^ex) {
   throw ex;
 }
}

/* plus petit nombre, racine et plus grand nombre */
void arbrePPRacinePG(unNoeud *arbre, int *pp, int *r, int *pg) {
 unNoeud *courant, *precedent, *temp;
 try {
   if (arbreVide(arbre))
     return;
  
   *pp = 0;
   *pg = 0;

   courant = arbre;
   while(courant->gauche != nullptr)
	   courant = courant->gauche;
	*pp = courant->info;
   *r = arbre->info;
   courant = arbre;
   while(courant->droite != nullptr)
	   courant = courant->droite;
   *pg = courant->info;
 }
 catch (Exception ^ex) {
   throw ex;
 }
}

