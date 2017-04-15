#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Initialisation
int nbTour,win; 
int tour[11][6];
int saisie_table[4];
int combinaison[4];

void demander_saisie();
void decompose_saisie();
void randomize();
void menu();
void credits();
void regles();
void retourner_menu();
void sauvegarder_saisie();
void calculer_points();
void partie();

// Test

// Fonction pour gérer la saisie des nombres
void demander_saisie() {
	int saisie;
	printf("-> Saisissez votre serie de 4 chiffres (compris entre 1 et 6):\n");
	scanf("%d",&saisie);
	decompose_saisie(saisie);
	while (saisie_table[0] < 1 || saisie_table[0] > 6 || saisie_table[1] < 1 || saisie_table[1] > 6 || saisie_table[2] < 1 || saisie_table[2] > 6 || saisie_table[3] < 1 || saisie_table[3] > 6) {
		printf("\nMauvaise saisie !\n-> Veuillez reecrire votre serie de 4 chiffres (compris entre 1 et 6): \n");
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

// Permet de calculer les points de la ligne
void calculer_points() {
	int atour = nbTour;
	tour[atour - 1][4] = 0;
	tour[atour - 1][5] = 0;
	for (int i=0; i<4;i++) {
		if (tour[atour - 1][i] == combinaison[0] || tour[atour - 1][i] == combinaison[1] || tour[atour - 1][i] == combinaison[2] || tour[atour - 1][i] == combinaison[3]) {
			if (tour[atour - 1][i] == combinaison[i]) {
				win++;
				tour[atour - 1][4] = win;
			} else {
				tour[atour - 1][5] = tour[atour - 1][5]++;
			}
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
	win = 0;

	randomize(); // Générer les 4 chiffres aléatoirement

	// Boucle de partie
	while (nbTour <= 10 && win < 4) {
		win = 0;
		//system("cls");
		printf("\t \t --- MASTERMIND (Essai %d/10) ---\n", nbTour);

		for (int i = 0; i < 4; ++i) 
			printf("%d", combinaison[i]);
		printf("\n");

		demander_saisie();
		sauvegarder_saisie();
		calculer_points();
		
		for (int i = 0; i < tour[nbTour - 1][4] + 1; ++i) 
			printf("o", combinaison[i], i);
		printf("\n");
		for (int i = 0; i < tour[nbTour - 1][5] + 1; ++i) 
			printf("x", combinaison[i], i);
		printf("\n");

		nbTour++;
	}

	// Fin de la partie
	//system("cls");
	printf("\t \t --- MASTERMIND (Fin de la partie !) ---\n\n");
	
	if (nbTour > 10) printf("Dommage :( ! N'abandonnez pas si vite, reesayez a nouveau ! =)\n\n");
	if (win > 3) printf("Felicitations, c'est gagne ! Vous avez trouve la bonne combinaison en %d essais !\n\n", nbTour);
	retourner_menu();
}

// Menu
void menu() {
	int choix = 0;

	system("cls");
	printf("\t \t --- Bienvenue sur MASTERMIND ---\n\n");
	printf("1. Jouer\n");
	printf("2. Regles du jeu\n");
	printf("3. Credits du jeu\n");
	printf("4. Quitter\n\n");
	printf("-> Entrez votre choix: ");
	scanf("%d", &choix);
	while (choix < 1 || choix > 4) {
		system("cls");
		printf("\t \t --- Bienvenue sur MASTERMIND ---\n\n");
		printf("1. Jouer\n");
		printf("2. Regles du jeu\n");
		printf("3. Credits du jeu\n");
		printf("4. Quitter\n\n");
		printf("-> Entrez votre choix (1-4): ");
        scanf("%d", &choix);
	}
	if (choix == 1) partie();
	if (choix == 2) regles();
	if (choix == 3) credits();
	if (choix == 4) exit(0);
}

void regles() {
	system("cls");
    printf("\t \t --- Regles du MASTERMIND ---\nLe but du Mastermind est de resoudre la combinaison de quatre chiffres, generee aleatoirement, le plus rapidement possible... Vous avez seulement 10 essais pour trouver ce nombre.\nA chaque essai vous proposez une combinaison et si vous n'obtenez pas directement la bonne combinaison, vous pouvez voir au bout de la ligne des indications sur votre proposition:\n - 'x' signifie qu'un chiffre est valide mais mal place\n - 'o' signifie qu'un chiffre est bien place\n");
    retourner_menu();
}

void credits() {
	system("cls");
    printf("\t \t --- Credits du MASTERMIND ---\nVersion: DEBUG\nCode:\n  - Alexis STORAI (081)\n  - Emerik ROYER (081)\n");
    retourner_menu();
}

void retourner_menu() {
	int leave = 0;
	printf("\n-> Appuyer sur '1' pour retourner au menu: ");
    while (leave != 1) {
        scanf("%d", &leave);
    }
    menu();
}


// Main
int main()
{
	system("cls");
	menu();
	return 0;
}