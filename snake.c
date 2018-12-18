#include<stdlib.h>
#include<graph.h>
#include<time.h>
#define CYCLE 10000L
typedef struct Map Map;
typedef struct Case Case;
typedef struct Snake Snake;
typedef struct corp corp;

struct Case
{
	int cy;
	int cx;
	int contenue;
};

struct corp
{
	int ca;
	int dir; 
};

struct Snake
{
	corp* cas;
	int dir;
	int taille;
	int manger;
};

struct Map
{
	Case* map;
	int sizem;
	Snake snake;
	int pastille;
	int niveau;
};

void AfficherMap(Map jeu){
	couleur c;
	ChoisirEcran(1);
	for (int i = 0; i < jeu.sizem; i=i+1)
	{
		if (jeu.map[i].contenue == 0)
			{
				
				c = CouleurParNom("white");
				ChoisirCouleurDessin(c);
				RemplirRectangle(jeu.map[i].cy,jeu.map[i].cx,20,20);
				c = CouleurParNom("black");
				ChoisirCouleurDessin(c);
				DessinerRectangle(jeu.map[i].cy,jeu.map[i].cx,20,20);
			
			}
		else if (jeu.map[i].contenue == 1)
			{
				c = CouleurParNom("purple");
				ChoisirCouleurDessin(c);
				RemplirRectangle(jeu.map[i].cy,jeu.map[i].cx,20,20);
				c = CouleurParNom("black");
				ChoisirCouleurDessin(c);
				DessinerRectangle(jeu.map[i].cy,jeu.map[i].cx,20,20);
				
			}
		else if (jeu.map[i].contenue == 2)
			{
				c = CouleurParNom("green");
				ChoisirCouleurDessin(c);
				RemplirRectangle(jeu.map[i].cy,jeu.map[i].cx,20,20);
				c = CouleurParNom("black");
				ChoisirCouleurDessin(c);
				DessinerRectangle(jeu.map[i].cy,jeu.map[i].cx,20,20);
			}
	}
	CopierZone(1,0,0,0,1200,800,0,0);
	ChoisirEcran(0);
	

}

void InitMap(Map* jeu){
	jeu->map = (Case*)malloc(sizeof(Case)*jeu->sizem);
	int c;
	for (int i = 0,c = 0; i < 40; i=i+1)
	{
		for (int y = 0; y < 60 ;y=y+1,c=c+1)
		{
			(*jeu).map[c].cy=20*y;
			(*jeu).map[c].cx=20*i;
			(*jeu).map[c].contenue=0;
		}
	}
}

void poserFruit(Map* jeu){
	srand(time(NULL));
	int cs = rand()%jeu->sizem+0;
	while((*jeu).map[cs].contenue==1 || (*jeu).map[cs].contenue==2|| (*jeu).map[cs-1].contenue==2|| (*jeu).map[cs+1].contenue==2|| (*jeu).map[cs-60].contenue==2|| (*jeu).map[cs+60].contenue==2){
		cs = rand()%jeu->sizem+0;
	}
	(*jeu).map[cs].contenue=2;



}

void chunk(Map* jeu){
	(*jeu).snake.taille=10;
	int t = (*jeu).snake.taille+1;
	(*jeu).snake.cas=(corp*)malloc(sizeof(corp)*t);
	(*jeu).pastille=5;
	for (int i = 0; i < (*jeu).snake.taille; i=i+1)
	{
		(*jeu).map[1170-60*i].contenue=1;
		(*jeu).snake.cas[i].ca=1170-60*i;
	}
	/*(*jeu).map[990].contenue=1;
	(*jeu).map[1050].contenue=1;
	(*jeu).map[1110].contenue=1;
	(*jeu).map[1170].contenue=1;
	(*jeu).snake.cas[3].ca=990;
	(*jeu).snake.cas[2].ca=1050;
	(*jeu).snake.cas[1].ca=1110;
	(*jeu).snake.cas[0].ca=1170;*/
	(*jeu).snake.dir=60;
	(*jeu).snake.cas[0].dir = 60;
	(*jeu).snake.manger=0;
	
	for (int i = 0; i < jeu->pastille; i=i+1)
	{
		poserFruit(jeu);
	}
	
}

void pausemenu(Map* jeu){
	couleur c;
	c = CouleurParNom("white");
	ChoisirCouleurDessin(c);
	RemplirRectangle(10,78,100,20);
	c = CouleurParNom("black");
	ChoisirCouleurDessin(c);
	EcrireTexte(10,100,"PAUSE",2);

}

void overmenu(Map* jeu){
	couleur c;
	c = CouleurParNom("white");
	ChoisirCouleurDessin(c);
	RemplirRectangle(0,0,1200,800);
	c = CouleurParNom("black");
	ChoisirCouleurDessin(c);
	EcrireTexte(10,100,"GAME OVER",2);

}

void Agrandir(Map* jeu){
	corp* memoire = (corp*)malloc(sizeof(corp)*((*jeu).snake.taille+1));
	int t = (*jeu).snake.taille;
	int i;
	for (i = 0; i < t; i=i+1)
	{
		memoire[i].ca=(*jeu).snake.cas[i].ca;
		memoire[i].dir=(*jeu).snake.cas[i].dir;
	}
	(*jeu).snake.taille=(*jeu).snake.taille+2;
	(*jeu).snake.cas =realloc((*jeu).snake.cas ,sizeof(corp)*((*jeu).snake.taille+1));
	for (i = 0; i < t; i=i+1)
	{
		(*jeu).snake.cas[i].ca=memoire[i].ca;
		(*jeu).snake.cas[i].dir=memoire[i].dir;
	}
	(*jeu).snake.cas[t+1].ca=(*jeu).snake.cas[t].ca-(*jeu).snake.cas[t].dir;
	(*jeu).snake.cas[t+1].dir=memoire[t].dir;
	(*jeu).snake.cas[t+2].ca=(*jeu).snake.cas[t+1].ca-(*jeu).snake.cas[t+1].dir;
	(*jeu).snake.cas[t+2].dir=memoire[t+1].dir;
	(*jeu).map[(*jeu).snake.cas[t+1].ca].contenue=1;
	(*jeu).map[(*jeu).snake.cas[t+2].ca].contenue=1;
	free(memoire);


	

}



void link(Map* jeu){
	int q=0;
	int p=1;
	int t;
	int memoire;
	unsigned long suivant= Microsecondes()+CYCLE;
	while(q==0){
		if (Microsecondes()>suivant)
		{
		if (ToucheEnAttente())
		{
			
			t = Touche();
			if (t==XK_Left)
			{

				(*jeu).map[(*jeu).snake.cas[(*jeu).snake.taille].ca].contenue=0;
				for (int i = (*jeu).snake.taille; i > 0; i=i-1)
				{	
					(*jeu).snake.cas[i].ca= (*jeu).snake.cas[i-1].ca;
					(*jeu).snake.cas[i].dir= (*jeu).snake.cas[i-1].dir;
				}
				if((*jeu).snake.dir!=1)
				{
					(*jeu).snake.dir=-1;
					(*jeu).snake.cas[0].dir=-1;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 2)
				{
				Agrandir(jeu);
				}
				(*jeu).map[(*jeu).snake.cas[0].ca].contenue=1;
				(*jeu).snake.cas[0].ca=(*jeu).snake.cas[0].ca+(*jeu).snake.dir;
				(*jeu).map[(*jeu).snake.cas[0].ca].contenue=1;
				AfficherMap(*jeu);
				
			}
			else if (t==XK_Right)
			{
				(*jeu).map[(*jeu).snake.cas[(*jeu).snake.taille].ca].contenue=0;
				for (int i = (*jeu).snake.taille; i > 0; i=i-1)
				{	
					(*jeu).snake.cas[i].ca= (*jeu).snake.cas[i-1].ca;
					(*jeu).snake.cas[i].dir= (*jeu).snake.cas[i-1].dir;
				}
				if((*jeu).snake.dir!=-1)
				{
					(*jeu).snake.dir=1;
					(*jeu).snake.cas[0].dir=1;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 2)
				{
				Agrandir(jeu);
				}
				(*jeu).snake.cas[0].ca=(*jeu).snake.cas[0].ca+(*jeu).snake.dir;
				(*jeu).map[(*jeu).snake.cas[0].ca].contenue=1;
				AfficherMap(*jeu);
				
			}
			else if (t==XK_Up)
			{
				(*jeu).map[(*jeu).snake.cas[(*jeu).snake.taille].ca].contenue=0;
				for (int i = (*jeu).snake.taille; i > 0; i=i-1)
				{	
					(*jeu).snake.cas[i].ca= (*jeu).snake.cas[i-1].ca;
					(*jeu).snake.cas[i].dir= (*jeu).snake.cas[i-1].dir;
				}
				if((*jeu).snake.dir!=60)
				{
					(*jeu).snake.dir=-60;
					(*jeu).snake.cas[0].dir=-60;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 2)
				{
					Agrandir(jeu);
				}
				(*jeu).snake.cas[0].ca=(*jeu).snake.cas[0].ca+(*jeu).snake.dir;
				(*jeu).map[(*jeu).snake.cas[0].ca].contenue=1;
				AfficherMap(*jeu);
				
			}
			else if (t==XK_Down)
			{

				(*jeu).map[(*jeu).snake.cas[(*jeu).snake.taille].ca].contenue=0;
				for (int i = (*jeu).snake.taille; i > 0; i=i-1)
				{	
					(*jeu).snake.cas[i].ca= (*jeu).snake.cas[i-1].ca;
					(*jeu).snake.cas[i].dir= (*jeu).snake.cas[i-1].dir;
				}
				if((*jeu).snake.dir!=-60)
				{
					(*jeu).snake.dir=60;
					(*jeu).snake.cas[0].dir=60;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 2)
				{
					Agrandir(jeu);
				}
				(*jeu).snake.cas[0].ca=(*jeu).snake.cas[0].ca+(*jeu).snake.dir;
				(*jeu).map[(*jeu).snake.cas[0].ca].contenue=1;
				AfficherMap(*jeu);
				

			}
			else if (t == XK_space)
			{
				p=0;
				pausemenu(jeu);
				while(p==0){
					
					if (ToucheEnAttente())
					{
						t=Touche();
						if (t==XK_space)
						{
							p=1;
						}
					}
				}
				 
			}
		}
		else 
		{
			if ((*jeu).snake.cas[0].ca+(*jeu).snake.dir>2399 || (*jeu).snake.cas[0].ca+(*jeu).snake.dir<0)
			{
				AfficherMap(*jeu);
				overmenu(jeu);
				q=1;
				break;
			}
			else if (((*jeu).snake.cas[0].ca % 60 == 59 && (*jeu).snake.dir == 1) || ((*jeu).snake.cas[0].ca % 60 == 0 && (*jeu).snake.dir == -1))
			{
				AfficherMap(*jeu);
				overmenu(jeu);
				q=1;
				break;
			}
			if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 2)
			{
				Agrandir(jeu);
			}
			(*jeu).map[(*jeu).snake.cas[(*jeu).snake.taille].ca].contenue=0;
			for (int i = (*jeu).snake.taille; i > 0; i=i-1)
			{
				(*jeu).snake.cas[i].ca= (*jeu).snake.cas[i-1].ca;
				(*jeu).snake.cas[i].dir= (*jeu).snake.cas[i-1].dir;
			}
			(*jeu).snake.cas[0].ca=(*jeu).snake.cas[0].ca+(*jeu).snake.dir;
		
			(*jeu).map[(*jeu).snake.cas[0].ca].contenue=1;
			
			AfficherMap(*jeu);
		}
		suivant= Microsecondes()+CYCLE;
	}

		


	}
}

void Partie(Map* jeu){
	InitMap(jeu);
	chunk(jeu);
	//AfficherMap(*jeu);
	link(jeu);
}

int main()
{
	Map jeu;
    InitialiserGraphique();
    CreerFenetre(10,10,1200,800);
    int c=0;
    int t;
    
    

    //DessinerRectangle(0,0,20,20);
    //DessinerRectangle(0,20,20,20);
    
   
  	while(c==0){
  		if (ToucheEnAttente())
  		{
  			t = Touche();
  			if (t==XK_Escape)
  			{
  				FermerGraphique();
  			}
  			else if (t==XK_space)
  			{
  				jeu.sizem = 2400;
  				Partie(&jeu);
  			}
  		}

  	}
    return EXIT_SUCCESS;
}