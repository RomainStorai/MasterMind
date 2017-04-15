#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*void saisie(int monde[11][4])
{
	int ut1, ut2, ut3, ut4, nbUt, rt, i, j, v, w, x, y;

	printf("Donnez un nombre compris entre 1111 et 6666 ne contenant que des chiffres compris entre 1 et 6 : \n");
	scanf("%d",&rt);
	nbUt = rt;
	ut1 = rt/1000;
	rt = rt%1000;
	ut2 = rt/100;
	rt = rt%100;
	ut3 = rt/10;
	rt = rt%10;
	ut4 = rt;
	while((ut1>6)||(ut1<1)||(ut2>6)||(ut2<1)||(ut3>6)||(ut3<1)||(ut4>6)||(ut4<1)||(nbUt<1111)||(nbUt>6666))
	{
		printf("Mauvaise saisie\n Veuillez reecrire votre serie de chiffre compris entre 1 et 6 :\n");
		scanf("%d",&rt);
		nbUt = rt;
		ut1 = rt/1000;
		rt = rt%1000;
		ut2 = rt/100;
		rt = rt%100;
		ut3 = rt/10;
		rt = rt%10;
		ut4 = rt;
	}
	/* Test de valeur du nombre entré par l'utilisateur :
	printf("ut1 = %d\n", ut1);
	printf("ut2 = %d\n", ut2);
	printf("ut3 = %d\n", ut3);
	printf("ut4 = %d\n", ut4);*/
	/*for(i=0;i<11;i++)
	{
		for(j=0;j<4;j++)
		{
			monde[i][j] = 0;
		}
	}
	srand(time(NULL));
	v = rand()%6+1;
	w = rand()%6+1;
	x = rand()%6+1;
	y = rand()%6+1;
	// Autre manière d'entrer un nombre aléatoire mais deffectueux :
	/*for(i=0;i<4;i++)
	{
		monde[i][0] = rand()%6+1;
	}*/
	/*monde[0][0] = v;
	monde[0][1] = w;
	monde[0][2] = x;
	monde[0][3] = y;
	printf("v = %d\n", v);
	printf("w = %d\n", w);
	printf("x = %d\n", x);
	printf("y = %d\n", y);	
	monde[1][0] = ut1;
	monde[1][1] = ut2;
	monde[1][2] = ut3;
	monde[1][3] = ut4;	
	for(i=0;i<11;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("| %d ", monde[i][j]);
		}
		printf("|\n");
	}
}

void partie(int monde[11][4])
{
	int n, nbTour, v, w, x, y, ut1, ut2, ut3, ut4, i, j, nbUt, rt, bn;
	n = 0;
	nbTour = 0;
	i = 0;
	j = 0;
	bn = 0;
	while((n<4)||(nbTour<10))
	{
		system("cls");
		printf("                 || Bonjour ||\n__xX Bienvenue sur le Projet Minster Mind version 1.1.2 Xx__\n  || Code Par Alexis STORAI (081) et Emerik ROYER (081) ||\n");
		nbTour = nbTour + 1;
		printf("Donnez votre combinaison suivante");
		scanf("%d",&rt);
		nbUt = rt;
		ut1 = rt/1000;
		rt = rt%1000;
		ut2 = rt/100;
		rt = rt%100;
		ut3 = rt/10;
		rt = rt%10;
		ut4 = rt;
		while((ut1>6)||(ut1<1)||(ut2>6)||(ut2<1)||(ut3>6)||(ut3<1)||(ut4>6)||(ut4<1)||(nbUt<1111)||(nbUt>6666))
		{
			printf("Mauvaise saisie\n Veuillez reecrire votre serie de chiffre compris entre 1 et 6 :\n");
			scanf("%d",&rt);
			nbUt = rt;
			ut1 = rt/1000;
			rt = rt%1000;
			ut2 = rt/100;
			rt = rt%100;
			ut3 = rt/10;
			rt = rt%10;
			ut4 = rt;
		}
		printf("%d", nbTour);
		for(i=0;i<4;i++)
		{
			for(j=j;j<j+1;j++)
			{
				printf("| %d ", monde[i][j]);
			}
			printf("| ");
		}

		if(monde[0][0]==monde[0][1])
		{
			monde[1][4] = monde[1][4] + 1; // monde[1][4]++;
			monde[0][1] = bn;
			monde[0][0] = bn;
			bn = bn - 1;
		}


		if(ut1==v)
		{
			printf("o");
			n = n + 1;
		}
		if(ut2 == w)
		{
			printf("o");
			n = n + 1;
		}
		if(ut3 == x)
		{
			n = n + 1;
			printf("o");
		}
		if(ut4 == y)
		{
			printf("o");
			n = n + 1;
		}
		if((ut1!=v)&&((w==ut1)||(x==ut1)||(y==ut1)))
		{
			printf("x");
		}
		if((ut2!=w)&&((v==ut2)||(x==ut2)||(y==ut2)))
		{
			printf("x");
		}
		if((ut3!=x)&&((v==ut3)||(w==ut3)||(y==ut3)))
		{
			printf("x");
		}
		if((ut4!=y)&&((v==ut4)||(w==ut4)||(x==ut4)))
		{
			printf("x");
		}
		printf("\n");
	}
	if((nbTour==10)&&(n==4))
	{
		printf("Felicitations, c'est gagne ! Vous avez reussi a trouver le code au bout de %d", nbTour);
	}
	if(n==4)
	{
		printf("Felicitations, c'est gagne ! Vous avez reussi a trouver le code au bout de %d", nbTour);
	}
	if(n<4)
	{
		printf("Dommage! n'abandonnes pas si vite, reesaye a nouveau ! =)");
	}
}
*/

int nbTour,win,v,w,x,y; 
int tour[10][3];
int saisie_table[3];

static void partie() {
	nbTour = 1;
	win = 0;
	randomize(); // Générer les 4 chiffres aléatoirement
	while (nbTour < 10 || win < 4) { // Boucle de partie
		system("cls");
		printf("                 || Bonjour ||\n__xX Bienvenue sur le Projet Minster Mind version 1.1.0 Xx__\n  || Code Par Alexis STORAI (081) et Emerik ROYER (081) ||\n");
		demander_saisie();

	}
}



static void demander_saisie() {
	int saisie;
	printf("Saisissez votre serie de chiffres compris entre 1 et 6:\n");
	scanf("%d",&saisie);
	decompose_saisie(saisie);
	while (saisie_table[0] < 1 || saisie_table[0] > 6 || saisie_table[1] < 1 || saisie_table[1] > 6 || saisie_table[2] < 1 || saisie_table[2] > 6 || saisie_table[3] < 1 || saisie_table[3] > 6) {
		printf("Mauvaise saisie\n Veuillez reecrire votre serie de chiffre compris entre 1 et 6 :\n");
		scanf("%d",&saisie);
		decompose_saisie(saisie);
	}
	tour[nbTour - 1][0] = saisie_table[0];
	tour[nbTour - 1][1] = saisie_table[1];
	tour[nbTour - 1][2] = saisie_table[2];
	tour[nbTour - 1][3] = saisie_table[3];
}

static void decompose_saisie(int saisie) {
	saisie_table[0] = saisie/1000;
	saisie = saisie%1000;
	saisie_table[1] = saisie/100;
	saisie = saisie%100;
	saisie_table[2] = saisie/10;
	saisie = saisie%10;
	saisie_table[3] = saisie;
}

static int randomize() {
	srand(time(NULL));
	v = rand()%6+1;
	w = rand()%6+1;
	x = rand()%6+1;
	y = rand()%6+1;
	return 0;
}


int main()
{
	//saisie(monde);
	//partie(monde);
	partie();
	return 0;
}