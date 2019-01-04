#include<stdlib.h>
#include<graph.h>
#include<time.h>
#define CYCLE 1000L
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
	int sx;
	int sy;
	Snake snake;
	int pastille;
	int niveau;
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
		else if (jeu.map[i].contenue == 3)
		{
			c = CouleurParNom("black");
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
	for (int i = 0,c = 0; i < (*jeu).sy; i=i+1)
	{
		for (int y = 0; y < (*jeu).sx ;y=y+1,c=c+1)
		{
			(*jeu).map[c].cy=20*y;
			(*jeu).map[c].cx=20*i;
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
	(*jeu).snake.taille=9;
	jeu->snake.manger = 0;
	int t = (*jeu).snake.taille+1;
	for (int i = 0; i < (*jeu).snake.taille; i=i+1)
	{
		(*jeu).map[sizem1-(*jeu).sx*i].contenue=1;
		(*jeu).snake.cas[i].ca=sizem1-(*jeu).sx*i;
	}
	if((*jeu).snake.taille==0){
		(*jeu).map[sizem1].contenue=1;
		(*jeu).snake.cas[0].ca=sizem1;
	}
	(*jeu).snake.dir=(*jeu).sx;
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

}
void nextmenu(Map* jeu){
	couleur c;
	c = CouleurParNom("white");
	ChoisirCouleurDessin(c);
	RemplirRectangle(0,0,1200,800);
	c = CouleurParNom("black");
	ChoisirCouleurDessin(c);
	EcrireTexte(10,100,"Niveau suivant",2);

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
		}
		else 
		{
			if ((*jeu).snake.cas[0].ca+(*jeu).snake.dir>(*jeu).sizem-1 || (*jeu).snake.cas[0].ca+(*jeu).snake.dir<0)
			{
				AfficherMap(*jeu);
				overmenu(jeu);
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
		suivant= Microsecondes()+CYCLE-jeu->niveau;
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
    jeu.niveau=0;
    //Nombre de pastille
    jeu.pastille=1;
    //Taille du terrain
    jeu.sizem = 60*40;
    //Taille du serpent pas besoin de modifier il se change selon les cases
    jeu.snake.cas=(corp*)malloc(sizeof(corp)*jeu.sizem);
    //nombre de case horizontale
    jeu.sx = 60;
    //nombre de case verticale
    jeu.sy= 40;

    
    srand(time(NULL));
    
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
  				
  				Partie(&jeu);
  			}
  		}

  	}
    return EXIT_SUCCESS;
}