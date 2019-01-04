#include<stdlib.h>
#include<graph.h>
#include<time.h>
#define CYCLE 1L
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
	int tailles;
	int manger;
};

struct Map
{
	Case* map;
	int sizem;
	int sx;
	int sy;
	Snake snake;
	int pastille;
	int niveau;
	int taillec;
	int cyc;
	int next;
};

void AfficherMap(Map jeu){
	couleur c;
	ChoisirEcran(1);
	char* cou[7] = {"purple","blue","red","yellow","pink","black","grey"};
	srand(time(NULL));
	for (int i = 0; i < jeu.sizem; i=i+1)
	{
		if (jeu.map[i].contenue == 0)
			{
				
				c = CouleurParNom("white");
				ChoisirCouleurDessin(c);
				RemplirRectangle(jeu.map[i].cy,jeu.map[i].cx,jeu.taillec,jeu.taillec);
				c = CouleurParNom("black");
				ChoisirCouleurDessin(c);
				DessinerRectangle(jeu.map[i].cy,jeu.map[i].cx,jeu.taillec,jeu.taillec);
			
			}
		else if (jeu.map[i].contenue == 1)
			{
				c = CouleurParNom("purple");
				ChoisirCouleurDessin(c);
				RemplirRectangle(jeu.map[i].cy,jeu.map[i].cx,jeu.taillec,jeu.taillec);
				c = CouleurParNom("black");
				ChoisirCouleurDessin(c);
				DessinerRectangle(jeu.map[i].cy,jeu.map[i].cx,jeu.taillec,jeu.taillec);
				
			}
		else if (jeu.map[i].contenue == 2)
			{
				c = CouleurParNom("green");
				ChoisirCouleurDessin(c);
				RemplirRectangle(jeu.map[i].cy,jeu.map[i].cx,jeu.taillec,jeu.taillec);
				c = CouleurParNom("black");
				ChoisirCouleurDessin(c);
				DessinerRectangle(jeu.map[i].cy,jeu.map[i].cx,jeu.taillec,jeu.taillec);
			}
		else if (jeu.map[i].contenue == 3)
		{
			c = CouleurParNom("black");
			ChoisirCouleurDessin(c);
			RemplirRectangle(jeu.map[i].cy,jeu.map[i].cx,jeu.taillec,jeu.taillec);
			c = CouleurParNom("black");
			ChoisirCouleurDessin(c);
			DessinerRectangle(jeu.map[i].cy,jeu.map[i].cx,jeu.taillec,jeu.taillec);
		}
	}
	CopierZone(1,0,0,0,1200,850,0,0);
	ChoisirEcran(0);
	

}

void InitMap(Map* jeu){
	jeu->map = (Case*)malloc(sizeof(Case)*jeu->sizem);
	int c;
	for (int i = 0,c = 0; i < (*jeu).sy; i=i+1)
	{
		for (int y = 0; y < (*jeu).sx ;y=y+1,c=c+1)
		{
			(*jeu).map[c].cy=jeu->taillec*y;
			(*jeu).map[c].cx=jeu->taillec*i;
			(*jeu).map[c].contenue=0;
		}
	}
}

void poserFruit(Map* jeu){

	int cs = rand()%jeu->sizem+0;
	while((*jeu).map[cs].contenue==1 || (*jeu).map[cs].contenue==2|| (*jeu).map[cs-1].contenue==2|| (*jeu).map[cs+1].contenue==2|| (*jeu).map[cs-60].contenue==2|| (*jeu).map[cs+60].contenue==2 || (*jeu).map[cs].contenue==3){
		cs = rand()%jeu->sizem+0;
	}
	(*jeu).map[cs].contenue=2;



}

void poserObs(Map* jeu){
	int cd = rand()%jeu->sizem+0;
	while((*jeu).map[cd].contenue==1 || (*jeu).map[cd].contenue==2|| (*jeu).map[cd-1].contenue==2|| (*jeu).map[cd+1].contenue==2|| (*jeu).map[cd-60].contenue==2|| (*jeu).map[cd+60].contenue==2 || (*jeu).map[cd].contenue==3){
		cd = rand()%jeu->sizem+0;
	}
	(*jeu).map[cd].contenue=3;


}

void chunk(Map* jeu){
	int sizem1 = ((*jeu).sizem/2)-((*jeu).sx/2);

	jeu->snake.manger = 0;
	int t = (*jeu).snake.taille+1;
	for (int i = 0; i < (*jeu).snake.taille; i=i+1)
	{
		(*jeu).map[sizem1-1*i].contenue=1;
		(*jeu).snake.cas[i].ca=sizem1-1*i;
	}
	if((*jeu).snake.taille==0){
		(*jeu).map[sizem1].contenue=1;
		(*jeu).snake.cas[0].ca=sizem1;
	}
	(*jeu).snake.dir=1;
	(*jeu).snake.cas[0].dir = (*jeu).sx;
	(*jeu).snake.manger=0;
	
	for (int i = 0; i < jeu->pastille; i=i+1)
	{
		poserFruit(jeu);
	}
	for (int i = 0; i < jeu->niveau; i=i+1)
	{
		poserObs(jeu);
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
	int t = 0;
	while(t == 0){
		if (ToucheEnAttente())
		{
			int t = Touche();
			if (t == XK_space)
			{
				t=1;
				break;
			}
		}
	}

}
void nextmenu(Map* jeu){
	couleur c;
	c = CouleurParNom("white");
	ChoisirCouleurDessin(c);
	RemplirRectangle(0,0,1200,800);
	c = CouleurParNom("black");
	ChoisirCouleurDessin(c);
	EcrireTexte(10,100,"Niveau suivant",2);
	int t = 0;
	while(t == 0){
		if (ToucheEnAttente())
		{
			int t = Touche();
			if (t == XK_space)
			{
				t=1;
				break;
			}
		}
	}

}

void Agrandir(Map* jeu){
	(*jeu).snake.taille=(*jeu).snake.taille+2;
}



void link(Map* jeu){
	int q=0;
	int p=1;
	int t;
	int memoire;
	unsigned long suivant= Microsecondes()+CYCLE;
	while(jeu->niveau > 0)
	{
		AfficherMap(*jeu);
		pausemenu(jeu);
		if (ToucheEnAttente)
		{
			t= Touche();
			if (t == XK_space)
			{
				break;
			}
		}
	}
	while(q==0){
		if (Microsecondes()>suivant)
		{
		if (jeu->pastille == jeu->snake.manger)
		{
				q = 0;
				jeu->pastille = jeu->pastille + 1;
				jeu->niveau = jeu->niveau+1;
				nextmenu(jeu);
				break;
		}
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
					jeu->snake.manger = jeu->snake.manger+1;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 1 || (*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 3)
				{
					AfficherMap(*jeu);
					overmenu(jeu);
					jeu->next = 0;
					jeu->pastille = jeu->pastille - jeu->niveau;
					jeu->snake.manger = 0;
					jeu->niveau=0;
					q=1;
					break;
				
				}
				else if (((*jeu).snake.cas[0].ca % (*jeu).sx == (*jeu).sx-1 && (*jeu).snake.dir == 1) || ((*jeu).snake.cas[0].ca % (*jeu).sx == 0 && (*jeu).snake.dir == -1))
				{
					AfficherMap(*jeu);
					overmenu(jeu);
					jeu->next = 0;
					jeu->pastille = jeu->pastille - jeu->niveau;
					jeu->snake.manger = 0;
					jeu->niveau=0;
					q=1;
					break;
				}
				else if((*jeu).snake.cas[0].ca+(*jeu).snake.dir>(*jeu).sizem-1 || (*jeu).snake.cas[0].ca+(*jeu).snake.dir<0)
				{
					AfficherMap(*jeu);
					overmenu(jeu);
					jeu->next = 0;
					jeu->pastille = jeu->pastille - jeu->niveau;
					jeu->snake.manger = 0;
					jeu->niveau=0;
					q=1;
					break;
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
				jeu->snake.manger = jeu->snake.manger+1;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 1 || (*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 3)
				{
					AfficherMap(*jeu);
					overmenu(jeu);
					jeu->next = 0;
					jeu->pastille = jeu->pastille - jeu->niveau;
					jeu->snake.manger = 0;
					jeu->niveau=0;
					q=1;
					break;
				
				}
				else if (((*jeu).snake.cas[0].ca % (*jeu).sx == (*jeu).sx-1 && (*jeu).snake.dir == 1) || ((*jeu).snake.cas[0].ca % (*jeu).sx == 0 && (*jeu).snake.dir == -1))
				{
					AfficherMap(*jeu);
					overmenu(jeu);
					jeu->next = 0;
					jeu->pastille = jeu->pastille - jeu->niveau;
					jeu->snake.manger = 0;
					jeu->niveau=0;
					q=1;
					break;
				}
				else if((*jeu).snake.cas[0].ca+(*jeu).snake.dir>(*jeu).sizem-1 || (*jeu).snake.cas[0].ca+(*jeu).snake.dir<0)
				{
					AfficherMap(*jeu);
					overmenu(jeu);
					jeu->next = 0;
					jeu->pastille = jeu->pastille - jeu->niveau;
					jeu->snake.manger = 0;
					jeu->niveau=0;
					q=1;
					break;
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
				if((*jeu).snake.dir!=(*jeu).sx)
				{
					(*jeu).snake.dir=-(*jeu).sx;
					(*jeu).snake.cas[0].dir=-(*jeu).sx;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 2)
				{
					Agrandir(jeu);
					jeu->snake.manger = jeu->snake.manger+1;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 1 || (*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 3)
				{
					AfficherMap(*jeu);
					overmenu(jeu);
					jeu->next = 0;
					jeu->pastille = jeu->pastille - jeu->niveau;
					jeu->snake.manger = 0;
					jeu->niveau=0;
					q=1;
					break;
				
				}
				else if (((*jeu).snake.cas[0].ca % (*jeu).sx == (*jeu).sx-1 && (*jeu).snake.dir == 1) || ((*jeu).snake.cas[0].ca % (*jeu).sx == 0 && (*jeu).snake.dir == -1))
				{
					AfficherMap(*jeu);
					overmenu(jeu);
					jeu->next = 0;
					jeu->pastille = jeu->pastille - jeu->niveau;
					jeu->snake.manger = 0;
					jeu->niveau=0;
					q=1;
					break;
				}
				else if((*jeu).snake.cas[0].ca+(*jeu).snake.dir>(*jeu).sizem-1 || (*jeu).snake.cas[0].ca+(*jeu).snake.dir<0)
				{
					AfficherMap(*jeu);
					overmenu(jeu);
					jeu->next = 0;
					jeu->pastille = jeu->pastille - jeu->niveau;
					jeu->snake.manger = 0;
					jeu->niveau=0;
					q=1;
					break;
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
				if((*jeu).snake.dir!=-(*jeu).sx)
				{
					(*jeu).snake.dir=(*jeu).sx;
					(*jeu).snake.cas[0].dir=(*jeu).sx;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 2)
				{
					Agrandir(jeu);
					jeu->snake.manger = jeu->snake.manger+1;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 1 || (*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 3)
				{
					AfficherMap(*jeu);
					overmenu(jeu);
					jeu->next = 0;
					jeu->pastille = jeu->pastille - jeu->niveau;
					jeu->snake.manger = 0;
					jeu->niveau=0;
					q=1;
					break;
				
				}
				else if (((*jeu).snake.cas[0].ca % (*jeu).sx == (*jeu).sx-1 && (*jeu).snake.dir == 1) || ((*jeu).snake.cas[0].ca % (*jeu).sx == 0 && (*jeu).snake.dir == -1))
				{
					AfficherMap(*jeu);
					overmenu(jeu);
					jeu->next = 0;
					jeu->pastille = jeu->pastille - jeu->niveau;
					jeu->snake.manger = 0;
					jeu->niveau=0;
					q=1;
					break;
				}
				else if((*jeu).snake.cas[0].ca+(*jeu).snake.dir>(*jeu).sizem-1 || (*jeu).snake.cas[0].ca+(*jeu).snake.dir<0)
				{
					AfficherMap(*jeu);
					overmenu(jeu);
					jeu->next = 0;
					jeu->pastille = jeu->pastille - jeu->niveau;
					jeu->snake.manger = 0;
					jeu->niveau=0;
					q=1;
					break;
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
			else if (t == XK_Escape)
			{
				jeu->next = 0;
				jeu->pastille = jeu->pastille - jeu->niveau;
				jeu->snake.manger = 0;
				jeu->niveau=0;
				q=1;
				break;
				
			}
		}
		else 
		{
			if ((*jeu).snake.cas[0].ca+(*jeu).snake.dir>(*jeu).sizem-1 || (*jeu).snake.cas[0].ca+(*jeu).snake.dir<0)
			{
				AfficherMap(*jeu);
				overmenu(jeu);
				jeu->next = 0;
				jeu->pastille = jeu->pastille - jeu->niveau;
				jeu->snake.manger = 0;
				jeu->niveau=0;
				q=1;
				break;
			}
			else if (((*jeu).snake.cas[0].ca % (*jeu).sx == (*jeu).sx-1 && (*jeu).snake.dir == 1) || ((*jeu).snake.cas[0].ca % (*jeu).sx == 0 && (*jeu).snake.dir == -1))
			{
				AfficherMap(*jeu);
				overmenu(jeu);
				jeu->next = 0;
				jeu->pastille = jeu->pastille - jeu->niveau;
				jeu->snake.manger = 0;
				jeu->niveau=0;
				q=1;
				break;
			}
			if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 1 || (*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 3)
				{
					AfficherMap(*jeu);
					overmenu(jeu);
					jeu->next = 0;
					jeu->pastille = jeu->pastille - jeu->niveau;
					jeu->snake.manger = 0;
					jeu->niveau=0;
					q=1;
					break;
				
				}
			if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 2)
			{
				Agrandir(jeu);
				jeu->snake.manger = jeu->snake.manger+1;
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
		suivant= Microsecondes()+jeu->cyc+CYCLE-jeu->niveau*500;
	}

		


	}
}

void Partie(Map* jeu){
	while(jeu->next == 1){
		InitMap(jeu);
		chunk(jeu);
	//AfficherMap(*jeu);
		link(jeu);
		jeu->snake.taille = jeu->snake.tailles; 

	}
	
}

void pos1(){

  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  
  ChoisirCouleurDessin(green);
  RemplirRectangle(0,0,1600,900);
  ChoisirCouleurDessin(black);
  RemplirRectangle(400,200,400,400);
  ChoisirCouleurDessin(black);
  RemplirRectangle(465,65,275,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(570,100,"SNAKE",2);
  EcrireTexte(480,300,"Commencer une partie",2);
  EcrireTexte(550,400,"Options",2);
  EcrireTexte(550,500,"Quitter",2);
  ChoisirCouleurDessin(black);
  EcrireTexte(415,720,"Appuyer sur ESPACE pour valider",2);

  ChoisirCouleurDessin(green);
  RemplirTriangle(445,265,445,315,465,290);
  ChoisirCouleurDessin(black);
  RemplirTriangle(495,365,495,415,515,390);
  ChoisirCouleurDessin(black);
  RemplirTriangle(495,465,495,515,515,490);

  CopierZone(1,0,0,0,1200,800,0,0);
  ChoisirEcran(0);
}

void pos2(){

  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);

  ChoisirCouleurDessin(green);
  RemplirRectangle(0,0,1600,900);
  ChoisirCouleurDessin(black);
  RemplirRectangle(400,200,400,400);
  ChoisirCouleurDessin(black);
  RemplirRectangle(465,65,275,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(570,100,"SNAKE",2);
  EcrireTexte(480,300,"Commencer une partie",2);
  EcrireTexte(550,400,"Options",2);
  EcrireTexte(550,500,"Quitter",2);
  ChoisirCouleurDessin(black);
  EcrireTexte(415,720,"Appuyer sur ESPACE pour valider",2);

  ChoisirCouleurDessin(black);
  RemplirTriangle(445,265,445,315,465,290);
  ChoisirCouleurDessin(green);
  RemplirTriangle(495,365,495,415,515,390);
  ChoisirCouleurDessin(black);
  RemplirTriangle(495,465,495,515,515,490);

  CopierZone(1,0,0,0,1200,1200,0,0);
  ChoisirEcran(0);
}

void pos3(){

  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);

  ChoisirCouleurDessin(green);
  RemplirRectangle(0,0,1600,900);
  ChoisirCouleurDessin(black);
  RemplirRectangle(400,200,400,400);
  ChoisirCouleurDessin(black);
  RemplirRectangle(465,65,275,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(570,100,"SNAKE",2);
  EcrireTexte(480,300,"Commencer une partie",2);
  EcrireTexte(550,400,"Options",2);
  EcrireTexte(550,500,"Quitter",2);
  ChoisirCouleurDessin(black);
  EcrireTexte(415,720,"Appuyer sur ESPACE pour valider",2);

  ChoisirCouleurDessin(black);
  RemplirTriangle(445,265,445,315,465,290);
  ChoisirCouleurDessin(black);
  RemplirTriangle(495,365,495,415,515,390);
  ChoisirCouleurDessin(green);
  RemplirTriangle(495,465,495,515,515,490);

  CopierZone(1,0,0,0,1200,800,0,0);
  ChoisirEcran(0);

}

void t1c () {

  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,270,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(680,300,"Petit (20x30)", 1.5);

  ChoisirCouleurDessin(green);
  RemplirTriangle(820,282.5,820,302.5,840,292.5);
  RemplirTriangle(650,282.5,650,302.5,630,292.5);
 

  CopierZone(1,0,630,270,250,50,630,270);
  ChoisirEcran(0);
  
}

void t2c () {

  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,270,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(680,300,"Normal (40x60)", 1.5);

  ChoisirCouleurDessin(green);
  RemplirTriangle(820,282.5,820,302.5,840,292.5);
  RemplirTriangle(650,282.5,650,302.5,630,292.5);
 

  CopierZone(1,0,630,270,250,50,630,270);
  ChoisirEcran(0);
  
}

void t3c () {

  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,270,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(680,300,"Grand (50x75)", 1.5);

  ChoisirCouleurDessin(green);
  RemplirTriangle(820,282.5,820,302.5,840,292.5);
  RemplirTriangle(650,282.5,650,302.5,630,292.5);
  

  CopierZone(1,0,630,270,250,50,630,270);
  ChoisirEcran(0);
  
}

void t1 () {

  couleur black=CouleurParNom("black");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,270,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(680,300,"Petit (20x30)", 1.5);
 
  CopierZone(1,0,630,270,250,50,630,270);
  ChoisirEcran(0);
  
}

void t2 () {

  couleur black=CouleurParNom("black");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,270,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(680,300,"Normal (40x60)", 1.5);
  

  CopierZone(1,0,630,270,250,50,630,270);
  ChoisirEcran(0);
  
}

void t3 () {

  couleur black=CouleurParNom("black");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,250,250,70);
  
  ChoisirCouleurDessin(white);
  EcrireTexte(680,300,"Grand (50x75)", 1.5);

  CopierZone(1,0,630,270,250,50,630,270);
  ChoisirEcran(0);
  
}

void s1c () {

  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,370,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(680,400,"Petit (7 cases)", 1.5);

  ChoisirCouleurDessin(green);
  RemplirTriangle(820,382.5,820,402.5,840,392.5);
  RemplirTriangle(650,382.5,650,402.5,630,392.5);

  CopierZone(1,0,630,370,250,50,630,370);
  ChoisirEcran(0);
  
}

void s2c () {

  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,370,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(680,400,"Normal (10 cases)", 1.5);

  ChoisirCouleurDessin(green);
  RemplirTriangle(820,382.5,820,402.5,840,392.5);
  RemplirTriangle(650,382.5,650,402.5,630,392.5);

  CopierZone(1,0,630,370,250,50,630,370);
  ChoisirEcran(0);
}

void s3c () {

  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,370,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(680,400,"Grand (15 cases)", 1.5);

  ChoisirCouleurDessin(green);
  RemplirTriangle(820,382.5,820,402.5,840,392.5);
  RemplirTriangle(650,382.5,650,402.5,630,392.5);

  CopierZone(1,0,630,370,250,50,630,370);
  ChoisirEcran(0);
}

void s1 () {

  couleur black=CouleurParNom("black");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,370,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(680,400,"Petit (7 cases)", 1.5);

  CopierZone(1,0,630,370,250,50,630,370);
  ChoisirEcran(0);
}

void s2 () {

  couleur black=CouleurParNom("black");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,370,250,50);
  
  ChoisirCouleurDessin(white);
  EcrireTexte(680,400,"Normal (10 cases)", 1.5);
  
  CopierZone(1,0,630,370,250,50,630,370);
  ChoisirEcran(0);
  
}

void s3 () {

  couleur black=CouleurParNom("black");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,370,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(680,400,"Grand (15 cases)", 1.5);

  CopierZone(1,0,630,370,250,50,630,370);
  ChoisirEcran(0);
}

void p1c () {

  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,470,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(675,500,"Petit (3 pastilles)", 1.5);

  ChoisirCouleurDessin(green);
  RemplirTriangle(845,482.5,845,502.5,865,492.5);
  RemplirTriangle(650,482.5,650,502.5,630,492.5);
  
  CopierZone(1,0,630,470,250,50,630,470);
  ChoisirEcran(0);
  
}

void p2c () {

  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,470,250,50);
  
  ChoisirCouleurDessin(white);
  EcrireTexte(675,500,"Normal (5 pastilles)", 1.5);

  ChoisirCouleurDessin(green);
  RemplirTriangle(845,482.5,845,502.5,865,492.5);
  RemplirTriangle(650,482.5,650,502.5,630,492.5);
  
  CopierZone(1,0,630,470,250,50,630,470);
  ChoisirEcran(0);
 
}

void p3c () {

  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,470,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(675,500,"Grand (10 pastilles)", 1.5);

  ChoisirCouleurDessin(green);
  RemplirTriangle(845,482.5,845,502.5,865,492.5);
  RemplirTriangle(650,482.5,650,502.5,630,492.5);

  CopierZone(1,0,630,470,250,50,630,470);
  ChoisirEcran(0);
}

void p1 () {

  couleur black=CouleurParNom("black");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,470,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(675,500,"Petit (3 pastilles)", 1.5);

  CopierZone(1,0,630,470,250,50,630,470);
  ChoisirEcran(0);
  
}

void p2 () {

  couleur black=CouleurParNom("black");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,470,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(675,500,"Normal (5 pastilles)", 1.5);

  CopierZone(1,0,630,470,250,50,630,470);
  ChoisirEcran(0);
}

void p3 () {
  
  couleur black=CouleurParNom("black");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(630,470,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(675,500,"Grand (10 pastilles)", 1.5);

  CopierZone(1,0,630,470,250,50,630,470);
  ChoisirEcran(0);
}

void vc () {
  
  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(470,620,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(525,650,"Valider les options",1.5);

  ChoisirCouleurDessin(green);
  RemplirTriangle(490,635,490,655,510,645);

  CopierZone(1,0,470,620,250,50,470,620);
  ChoisirEcran(0);
}

void v () {
  
  couleur black=CouleurParNom("black");
  couleur white=CouleurParNom("white");

  ChoisirEcran(1);
  ChoisirCouleurDessin(black);
  RemplirRectangle(470,620,250,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(525,650,"Valider les options",1.5);

  CopierZone(1,0,470,620,250,50,470,620);
  ChoisirEcran(0);
}

int options(int d){
  
  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirCouleurDessin(green);
  RemplirRectangle(0,0,1600,900);
  ChoisirCouleurDessin(black);
  RemplirRectangle(300,100,600,600);

  ChoisirCouleurDessin(white);
  EcrireTexte(555,150,"OPTIONS",2);
  EcrireTexte(350,300,"Taille du terrain :",1.5);
  EcrireTexte(350,400,"Taille du serpent :", 1.5);
  EcrireTexte(350,500,"Nombre de pastilles initial :", 1.5);
  EcrireTexte(525,650,"Valider les options",1.5);

  
  
  int i = 0;
  int n  = 1;
  int n1 = d/100;
  int n2 = (d - n1*100)/10;
  int n3 = d-n1*100-n2*10;

  if(n1==1) t1c();
  else if(n1==2) t2c();
  else t3c();

  if(n2==1) s1();
  else if(n2==2) s2();
  else s3();

  if(n3==1) p1();
  else if(n3==2) p2();
  else p3();

  v();
	
  while(i==0){

    if(ToucheEnAttente()){
      int t = Touche();

      if(t==XK_Down) n=n+1;
      else if(t==XK_Up) n=n-1;
      if(n==0) n=4;
      else if(n==5) n=1;

      if(n==1 && t==XK_Right) n1=n1+1;
      else if(n==1 && t==XK_Left) n1=n1-1;
      if(n1==0) n1=3;
      else if(n1==4) n1=1;

      if(n==2 && t==XK_Right) n2=n2+1;
      else if(n==2 && t==XK_Left) n2=n2-1;
      if(n2==0) n2=3;
      else if(n2==4) n2=1;

      if(n==3 && t==XK_Right) n3=n3+1;
      else if(n==3 && t==XK_Left) n3=n3-1;
      if(n3==0) n3=3;
      else if(n3==4) n3=1;

      if(n==4 && t==XK_space) i=1;

      if(n==1){
	if(n1==1) t1c();
	else if(n1==2) t2c();
	else t3c();

	if(n2==1) s1();
	else if(n2==2) s2();
	else s3();

	if(n3==1) p1();
	else if(n3==2) p2();
	else p3();

	v();
      }

      else if(n==2){
	if(n1==1) t1();
	else if(n1==2) t2();
	else t3();

	if(n2==1) s1c();
	else if(n2==2) s2c();
	else s3c();

	if(n3==1) p1();
	else if(n3==2) p2();
	else p3();

	v();
      }

      else if(n==3){
	if(n1==1) t1();
	else if(n1==2) t2();
	else t3();

	if(n2==1) s1();
	else if(n2==2) s2();
	else s3();

	if(n3==1) p1c();
	else if(n3==2) p2c();
	else p3c();

	v();
      }

      else {
	if(n1==1) t1();
	else if(n1==2) t2();
	else t3();

	if(n2==1) s1();
	else if(n2==2) s2();
	else s3();

	if(n3==1) p1();
	else if(n3==2) p2();
	else p3();

	vc();
      }
    }
  }

  d=n1*100 + n2*10 +n3;

  return d;
}

void menu(){
  
  couleur black=CouleurParNom("black");
  couleur green=CouleurParNom("green");
  couleur white=CouleurParNom("white");

  ChoisirCouleurDessin(green);
  RemplirRectangle(0,0,1600,900);
  ChoisirCouleurDessin(black);
  RemplirRectangle(400,200,400,400);
  ChoisirCouleurDessin(black);
  RemplirRectangle(465,65,275,50);

  ChoisirCouleurDessin(white);
  EcrireTexte(570,100,"SNAKE",2);
  EcrireTexte(480,300,"Commencer une partie",2);
  EcrireTexte(550,400,"Options",2);
  EcrireTexte(550,500,"Quitter",2);
  ChoisirCouleurDessin(black);
  EcrireTexte(415,720,"Appuyer sur ESPACE pour valider",2);

}



int main()
{
  InitialiserGraphique();
  CreerFenetre(400,100,1200,850);
  menu();
  Map jeu;
  int c=0;
  int t;
  int n = 1;
  int i=0;
  int d=222;
  srand(time(NULL));
  jeu.niveau=0;
    //Nombre de pastille
  jeu.pastille=5;
    //Taille du terrain
  jeu.sizem = 60*40;
    //Taille du serpent pas besoin de modifier il se change selon les cases
  
    //nombre de case horizontale
  jeu.sx = 60;
    //nombre de case verticale
  jeu.sy= 40;
  jeu.next = 1;
  jeu.taillec = 20;
  jeu.cyc = 0;
  jeu.snake.taille = 10;


  if(n==1) {
    pos1();
  }
  else if(n==2) {
    pos2();
  }
  else {
    pos3();

  }
  
  while(i == 0){
    
    if(ToucheEnAttente()){
      int t = Touche();
      if(t==XK_Down) n=n+1;
      else if(t==XK_Up) n=n-1;

      if(n==4) n=1;
      if(n==0) n=3;
    
      if(n==1) {
	pos1();
      }
      else if(n==2) {
	pos2();
      }
      else {
	pos3();

      }
      if(n==2 && t==XK_space){
	d=options(d);
	int n1= ((d%100)-(d%10))/10;
	
	if(d%10 == 1)
	{
		jeu.pastille=3;
	}
	else if(d%10 == 2)
	{
		jeu.pastille=5;
	}
	else if(d%10 == 3)
	{
		jeu.pastille=10;
	}
	if (n1 == 1)
	{
		jeu.snake.taille = 6;
		jeu.snake.tailles = 6;
	}
	else if (n1 == 2)
	{
		jeu.snake.taille = 9;
		jeu.snake.tailles = 9;
	}
	else if (n1 == 3)
	{
		jeu.snake.taille = 14;
		jeu.snake.tailles = 14;
	}
	if (d/100 == 2)
	{
		jeu.sizem = 60*40;
		jeu.sx = 60;
		jeu.sy= 40;
		jeu.taillec = 20;
		jeu.cyc = 0;
		jeu.snake.cas=(corp*)malloc(sizeof(corp)*jeu.sizem);

	}
	else if (d/100 == 1)
	{
		jeu.sizem = 30*20;
		jeu.sx = 30;
		jeu.sy= 20;
		jeu.taillec = 40;
		jeu.cyc = 100000;
		jeu.snake.cas=(corp*)malloc(sizeof(corp)*jeu.sizem);

	}
	else if (d/100 == 3)
	{
		jeu.sizem = 75*50;
		jeu.sx = 75;
		jeu.sy= 50;
		jeu.taillec = 16;
		jeu.cyc = 0;
		jeu.snake.cas=(corp*)malloc(sizeof(corp)*jeu.sizem);

	}
	menu();
	if(n==1) {
	  pos1();
	}
	else if(n==2) {
	  pos2();
	}
	else {
	  pos3();

	}
      }
      
      if(n==3 && t==XK_space) i=1;
      if(n==1 && t==XK_space) {
      	jeu.next = 1;
      	jeu.snake.cas=(corp*)malloc(sizeof(corp)*jeu.sizem);
      	Partie(&jeu);
      	menu();
      	pos1();
      }

    }
    }
	
}