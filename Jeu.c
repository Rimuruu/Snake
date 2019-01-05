#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include"Score.h"
#include"MiseEnPlace.h"
#include"Jeu.h"
#define CYCLE 1L

void pausemenu(Map* jeu){
	couleur c;
	c = CouleurParNom("white");
	ChoisirCouleurDessin(c);
	RemplirRectangle(10,78,100,20);
	c = CouleurParNom("black");
	ChoisirCouleurDessin(c);
	EcrireTexte(10,100,"PAUSE",2);

}

void overmenu(Map* jeu,int n1, int n2, int sco){
	couleur c;
	c = CouleurParNom("white");
	ChoisirCouleurDessin(c);
	RemplirRectangle(0,0,1200,800);
	c = CouleurParNom("black");
	ChoisirCouleurDessin(c);
	EcrireTexte(10,100,"GAME OVER",2);
	niv(n1,n2);
	score(sco);
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


int link(Map* jeu,int sco){
	int q=0;
	int p=1;
	int t;
	int n1;
	int n2;
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
					sco=sco+1;
					jeu->snake.manger = jeu->snake.manger+1;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 1 || (*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 3)
				{
					AfficherMap(*jeu);
					overmenu(jeu,n1,n2,sco);
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
					overmenu(jeu,n1,n2,sco);
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
					overmenu(jeu,n1,n2,sco);
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
				sco=sco+1;
				jeu->snake.manger = jeu->snake.manger+1;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 1 || (*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 3)
				{
					AfficherMap(*jeu);
					overmenu(jeu,n1,n2,sco);
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
					overmenu(jeu,n1,n2,sco);
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
					overmenu(jeu,n1,n2,sco);
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
					sco=sco+1;
					jeu->snake.manger = jeu->snake.manger+1;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 1 || (*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 3)
				{
					AfficherMap(*jeu);
					overmenu(jeu,n1,n2,sco);
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
					overmenu(jeu,n1,n2,sco);
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
					overmenu(jeu,n1,n2,sco);
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
					sco=sco+1;
					jeu->snake.manger = jeu->snake.manger+1;
				}
				if ((*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 1 || (*jeu).map[(*jeu).snake.cas[0].ca+(*jeu).snake.dir].contenue == 3)
				{
					AfficherMap(*jeu);
					overmenu(jeu,n1,n2,sco);
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
					overmenu(jeu,n1,n2,sco);
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
					overmenu(jeu,n1,n2,sco);
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
				overmenu(jeu,n1,n2,sco);
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
				overmenu(jeu,n1,n2,sco);
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
					overmenu(jeu,n1,n2,sco);
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
				sco=sco+1;
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

		n1 = ((jeu->niveau)+1)%10;
		n2 = ((jeu->niveau)+1) - n1;

		niv(n1,n2);
		score(sco);
	}

	return sco;
}

int Partie(Map* jeu){
  int sco=0;
  int niv=0;
	while(jeu->next == 1){
		InitMap(jeu);
		chunk(jeu);
		sco=link(jeu,sco);
		jeu->snake.taille = jeu->snake.tailles;
		niv=niv+1;

	}
	return sco+niv*10000;
}
