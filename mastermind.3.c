#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

// Initialisation
int nbTour,nbCercle; 
int tour[11][6];
int saisie_table[4];
int combinaison[4];
int tabnbCercle[6][2];

void demander_saisie();
void decompose_saisie();
void randomize();
void menu();
void credits();
void regles();
void stats();
void quitter();
void retourner_menu();
void retourner_menuopt();
void sauvegarder_saisie();
void calculer_points();
void afficher_image(char *p);
void partie();
void sauvegarder_score(int score, int perdu, int gagne);


// Fonction pour gérer la saisie des nombres
void demander_saisie() {
	int saisie;
	printf("-> Entrez votre proposition: ");
	scanf("%d",&saisie);
	decompose_saisie(saisie);
	while (saisie_table[0] < 1 || saisie_table[0] > 6 || saisie_table[1] < 1 || saisie_table[1] > 6 || saisie_table[2] < 1 || saisie_table[2] > 6 || saisie_table[3] < 1 || saisie_table[3] > 6) {
		printf(RED "\nMauvaise saisie !\nVeuillez ecrire une serie de 4 chiffres (compris entre 1 et 6)" RESET "\n-> Entrez votre proposition: ");
		scanf("%d",&saisie);
		decompose_saisie(saisie);
	}
}

void decompose_saisie(int saisie) {
	saisie_table[0] = saisie/1000;
	saisie = saisie%1000;
	saisie_table[1] = saisie/100;
	saisie = saisie%100;
	saisie_table[2] = saisie/10;
	saisie = saisie%10;
	saisie_table[3] = saisie;
}

// Permet de sauvegarder dans le tableau la saisie du tour
void sauvegarder_saisie() {
	int atour = nbTour;
	tour[atour - 1][0] = saisie_table[0];
	tour[atour - 1][1] = saisie_table[1];
	tour[atour - 1][2] = saisie_table[2];
	tour[atour - 1][3] = saisie_table[3];
}

// Permet d'afficher le tableau
void afficher_tableau() {
	for (int i = 0; i < 10; ++i) {
		printf(GRN "%d." RESET "\t|  ", i + 1);
		if (i <= nbTour - 2) {
			printf("%d  |  %d  |  %d  |  %d  |    ", tour[i][0], tour[i][1], tour[i][2], tour[i][3]);
			for (int y = 0; y < tour[i][4]; y++) printf(GRN "o" RESET);
			for (int z = 0; z < tour[i][5]; z++) printf(CYN "x" RESET);
		}
		printf("\n");
	}
	printf("\n\n\n");
}

// Permet de calculer les points de la ligne
void calculer_points() {
	int n = 7;
	nbCercle = 0;

	// Initialiser les tableaux
	for(int i=0;i<4;i++) {
		tabnbCercle[i][0] = combinaison[i];
		tabnbCercle[i][1] = tour[nbTour - 1][i];
	}

	tour[nbTour - 1][4] = 0;
	tour[nbTour - 1][5] = 0;

	// Compter les ronds
	for (int i=0; i<4;i++) {
		if (tabnbCercle[i][1] == tabnbCercle[i][0]) {
			nbCercle++;
			tour[nbTour - 1][4] = nbCercle;
			tabnbCercle[i][0] = n;
			n++;
			tabnbCercle[i][1] = n;
			n++;
		}
	}

	// Compter les croix
	for (int i=0; i<4;i++) {
		if (tabnbCercle[i][1] == tabnbCercle[0][0]) {
			tour[nbTour - 1][5] = tour[nbTour - 1][5] + 1;
			tabnbCercle[0][0] = n;
			n++;
			tabnbCercle[i][1] = n;
			n++;
		} else if (tabnbCercle[i][1] == tabnbCercle[1][0]) {
			tour[nbTour - 1][5] = tour[nbTour - 1][5] + 1;
			tabnbCercle[1][0] = n;
			n++;
			tabnbCercle[i][1] = n;
			n++;
		} else if (tabnbCercle[i][1] == tabnbCercle[2][0]) {
			tour[nbTour - 1][5] = tour[nbTour - 1][5] + 1;
			tabnbCercle[2][0] = n;
			n++;
			tabnbCercle[i][1] = n;
			n++;
		} else if (tabnbCercle[i][1] == tabnbCercle[3][0]) {
			tour[nbTour - 1][5] = tour[nbTour - 1][5] + 1;
			tabnbCercle[3][0] = n;
			n++;
			tabnbCercle[i][1] = n;
			n++;
		}
	}
}

// Permet de générer les nombres d'une partie
void randomize() {
	srand(time(NULL));
	combinaison[0] = (rand()%6) + 1;
	combinaison[1] = (rand()%6) + 1;
	combinaison[2] = (rand()%6) + 1;
	combinaison[3] = (rand()%6) + 1;
}

// Fonction pour faire une partie
void partie() {
	nbTour = 1;
	nbCercle = 0;

	randomize(); // Générer les 4 chiffres aléatoirement

	// Boucle de partie
	while (nbTour <= 10 && nbCercle < 4) {
		system("cls");
		char *p = "res/logo.txt";
		afficher_image(p);
		printf("\t\t\t --- Essai %d/10 ---\n\n", nbTour);

		// Permet d'afficher la combinaison
		/*for (int i = 0; i < 4; ++i) 
			printf("%d", combinaison[i]);
		printf("\n");*/

		afficher_tableau();
		demander_saisie();
		sauvegarder_saisie();
		calculer_points();

		nbTour++;
	}

	// Fin de la partie
	system("cls");

	char *pp = "res/logo.txt";
	afficher_image(pp);
	printf("\t\t\t --- Fin de la partie ! ---\n\n");
	
	afficher_tableau();

	if (nbCercle > 3) {
		printf(GRN "\t\tFelicitations, c'est gagne !\n\tVous avez trouve la bonne combinaison en %d essais !\n\n", nbTour - 1);
		sauvegarder_score(nbTour - 1,0,1);
	} else if (nbTour > 10) {
		printf(GRN "La combinaison etait:\t" RESET);
		for (int i = 0; i < 4; ++i) 
			printf("%d", combinaison[i]);
		printf("\n\n");
		printf(YEL "\t\tDommage :( ! N'abandonnez pas si vite, reesayez a nouveau ! =)\n\n");
		sauvegarder_score(nbTour - 1,1,0);
	}
	retourner_menu();
}

// Menu
void menu() {
	int choix = 0;

	system("cls");
	char *p = "res/logo.txt";
	afficher_image(p);
	printf(GRN "\t1." RESET " Jouer\n");
	printf(GRN "\t2." RESET " Regles du jeu\n");
	printf(GRN "\t3." RESET " Credits du jeu\n");
	printf(GRN "\t4." RESET " Statistiques\n");
	printf(GRN "\t5." RESET " Quitter\n\n");
	printf(MAG "-> Entrez votre choix: ");
	scanf("%d", &choix);
	while (choix < 1 || choix > 5) {
		system("cls");
		char *pp = "res/logo.txt";
		afficher_image(pp);
		printf(GRN "\t1." RESET " Jouer\n");
		printf(GRN "\t2." RESET " Regles du jeu\n");
		printf(GRN "\t3." RESET " Credits du jeu\n");
		printf(GRN "\t4." RESET " Statistiques\n");
		printf(GRN "\t5." RESET " Quitter\n\n");
		printf(MAG "-> Entrez votre choix (1-5): ");
        scanf("%d", &choix);
	}
	if (choix == 1) partie();
	if (choix == 2) regles();
	if (choix == 3) credits();
	if (choix == 4) stats();
	if (choix == 5) quitter();
}

void regles() {
	system("cls");
	char *p = "res/regles.txt";
	afficher_image(p);
    printf("Le but du Mastermind est de resoudre la combinaison de quatre chiffres, generee aleatoirement, le plus rapidement possible... Vous avez seulement 10 essais pour trouver ce nombre.\nA chaque essai vous proposez une combinaison et si vous n'obtenez pas directement la bonne combinaison, vous pouvez voir au bout de la ligne des indications sur votre proposition:\n - 'x' signifie qu'un chiffre est valide mais mal place\n - 'o' signifie qu'un chiffre est bien place\n");
    retourner_menu();
}

void credits() {
	system("cls");
	char *p = "res/credits.txt";
	afficher_image(p);
    printf("Version: 2.1.0\nCode: Romain Storaï\n");
    retourner_menu();
}

void stats() {
	system("cls");
	char *p = "res/stats.txt";
	afficher_image(p);

	FILE *fichier = fopen("res/score.txt","r");
    int score;
    int partie = 1;
    int moyen = 0;
    int gagne = 0;
    int perdu = 0;


    if (fichier != NULL) {
        fscanf(fichier,"%d-%d-%d-%d-%d",&score,&partie,&gagne,&perdu,&moyen);
		fclose(fichier);
		printf("\t\tMeilleur score:\t\t" GRN "%d essai(s).\n" RESET, score);
		printf("\t\tScore moyen:\t\t" GRN "%d.\n" RESET, moyen);
		printf("\t\tNombre de partie:\t" GRN "%d partie(s).\n" RESET, partie);
		printf("\t\tNombre de victoire:\t" GRN "%d victoire(s).\n" RESET, gagne);
		printf("\t\tNombre de defaite:\t" GRN "%d defaite(s).\n" RESET, perdu);
    } else 
    	printf(RED "Impossible de lire le fichier !\n");

    retourner_menuopt();
}

void quitter() {
	exit(0);
}

void retourner_menu() {
	int leave = 0;
	printf(MAG "\n-> Appuyer sur '1' pour retourner au menu: ");
    while (leave != 1) {
        scanf("%d", &leave);
    }
    menu();
}

void retourner_menuopt() {
	int leave = 0;
	printf(MAG "\n-> Appuyer sur '1' pour retourner au menu\n" GRN "ou sur '2' pour remettre zero vos Statistiques: ");
    while (leave != 1 && leave != 2) {
        scanf("%d", &leave);
    }
    if (leave == 1) menu();
    if (leave == 2) {
    	system("cls");

		char *p = "res/stats.txt";
		afficher_image(p);

		FILE *fichier = fopen("res/score.txt","w");
    	fprintf(fichier,"%d-%d-%d-%d-%d",0,0,0,0,0);

    	fclose(fichier);
    	printf(GRN "\t\tVos Statistiques sont comme neuf !\n");
    	retourner_menu();
    }
}

// Afficher le logo
void afficher_image(char *p) {
    char read_string[128];
 	char *fichier = p;
    FILE *fptr = NULL;
 
    if((fptr = fopen(fichier,"r")) == NULL) {
        return;
    }
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf(YEL "%s" RESET,read_string);
    printf("\n\n\n");
    fclose(fptr);
}

// Statistiques
void sauvegarder_score(int score, int perdu, int gagne) {
    FILE *fichier = fopen("res/score.txt","r");
    int scorefichier;
    int partie = 1;
    int moyen = 0;
    int gagneFichier = 0;
    int perduFichier = 0;


    if (fichier != NULL) {
        fscanf(fichier,"%d-%d-%d-%d-%d",&scorefichier,&partie,&gagneFichier,&perduFichier,&moyen);

        fclose(fichier);

        fichier = fopen("res/score.txt","w");
        if (scorefichier < score && scorefichier != 0) score = scorefichier; 
        if (gagne == 1) moyen = (moyen + score)/(gagneFichier + gagne);
        fprintf(fichier,"%d-%d-%d-%d-%d",score,partie + 1,gagneFichier + gagne,perduFichier + perdu,moyen);
    } else {
    	fclose(fichier);
    	fichier = fopen("res/score.txt","w");
    	if (gagne == 1) moyen = score;
    	fprintf(fichier,"%d-%d-%d-%d-%d",score,partie,gagne,perdu,moyen);
    }

    fclose(fichier);
}

// Main
int main()
{
	menu();
	return 0;
}