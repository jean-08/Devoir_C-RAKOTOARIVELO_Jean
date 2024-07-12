void ouvrir(FILE **fic, char *fichier);
char *alloc();
int compteur(FILE *fic, int n);
int cast(char *arg);
void tail(FILE *fic, int nbr_ligne);
void afficher_tail(FILE *fic, int nbr_ligne, int n, char *file_name);
void traiter_options(int argc, char *argv[]);
