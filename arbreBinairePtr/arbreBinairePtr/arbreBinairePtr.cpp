// arbreBinairePtr.cpp : fichier projet principal.

#include "stdafx.h"
#include "arbreBinaire.h"
#include <string>
#include <iostream>

using namespace System;

int lireChoix (void) {
 int menu;

 try {
   std::cout << "1. arbreInsert" << std::endl;
   std::cout << "2. arbreDelete" << std::endl;
   std::cout << "3. arbreInOrder" << std::endl;
   std::cout << "4. arbrePPRacinePG" << std::endl;
   std::cout << "5. arbreClear" << std::endl;
   std::cout << "0. Sortie" << std::endl;
   std::cout << "Votre choix : ";
   std::cin >> menu;
   return menu;
 }
 catch (Exception ^ex) {
   throw ex;
 }
}

void afficherEnOrdre (unNoeud *racineArbre) {
 char s[101];

 try {
   if (arbreVide(racineArbre)) {
     std::cout << "arbre vide" << std::endl;
     return;
   }
   std::cout << "Contenu de l'arbre : " << std::endl;
   *s = '\0';
   arbreInOrder(racineArbre, s);
   std::cout << s << std::endl;
 }
 catch (Exception ^ex) {
   throw ex;
 }
}

void afficherPPRacinePG (unNoeud *racineArbre) {
 int pp, r, pg;

 try {
   if (arbreVide(racineArbre)) {
     std::cout << "arbre vide" << std::endl;
     return;
   }
   std::cout << "pp, racine, pg : " << std::endl;
   arbrePPRacinePG(racineArbre, &pp, &r, &pg);
   std::cout << pp << ", " << r << ", " << pg << std::endl;
 }
 catch (Exception ^ex) {
   throw ex;
 }
}

void inserer (unNoeud **racineArbre) {
 int n;

 try {
   std::cout << "Nombre a ajouter : ";
   std::cin >> n;
   arbreInsert(racineArbre, n);
 }
 catch (Exception ^ex) {
   throw ex;
 }
}

void retirer (unNoeud **racineArbre) {
 int n;
 bool trouve;

 try {
   if (arbreVide(*racineArbre)) {
     std::cout << "arbre vide" << std::endl;
     return;
   }
   std::cout << "Nombre a retirer : ";
   std::cin >> n;
   trouve = arbreDelete(racineArbre, n);
   if (!trouve)
     std::cout << "Nombre pas dans la arbre" << std::endl;
 }
 catch (Exception ^ex) {
   throw ex;
 }
}


int main(array<System::String ^> ^args) {
 int menu; 
 unNoeud *racineArbre;

 try {
   arbreCreate(&racineArbre);
   do  {
     menu = lireChoix();
     switch (menu) {
       case    0 : break;
       case    1 : inserer(&racineArbre);
                   break;
       case    2 : retirer(&racineArbre);
                   break;
       case    3 : afficherEnOrdre(racineArbre);
                   break;
       case    4 : afficherPPRacinePG(racineArbre);
                   break;
       case    5 : arbreClear(&racineArbre);
                   break;
       default   : std::cout << "Choix inexistant" << std::endl;
                   break;
     }
   } while (menu != 0);
   arbreClear(&racineArbre);
 }
 catch (Exception ^ex) {
   Console::WriteLine(ex->GetType()->ToString());
   Console::WriteLine(ex->Message);
   Console::WriteLine(ex->StackTrace);
 }
 finally {
   std::cout << "Fin de l'execution";
   Console::Read();
 }
 return 0;
}
