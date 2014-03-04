// arbreBinaire.h

struct unNoeud {
  int info;
  unNoeud *gauche;
  unNoeud *droite;
};

/* creation d'un arbre */
void arbreCreate(unNoeud **arbre);

/* initialisation d'un arbre */
void arbreClear(unNoeud **arbre);

/* test si un arbre est vide */
bool arbreVide (unNoeud *arbre);

/* insertion d'un noeud dans l'arbre */
void arbreInsert(unNoeud **arbre, int n);

/* retrait d'un noeud dans l'arbre */
bool arbreDelete(unNoeud **arbre, int n);

/* parcours dans l'ordre */
void arbreInOrder(unNoeud *arbre, char *s);

/* plus petit nombre, racine et plus grand nombre */
void arbrePPRacinePG(unNoeud *arbre, int *pp, int *r, int *pg);

