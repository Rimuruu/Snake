#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include"MenuP.h"
#include"Options.h"
#include"MiseEnPlace.h"
#include"Jeu.h"
#include"Score.h"

#define CYCLE 1L

int main()
{
  InitialiserGraphique();
  CreerFenetre(400,100,1200,850);
  menu1();
  Map jeu;
  int c=0;
  int t;
  int n = 1;
  int i=0;
  int d=222;
  int np =0;
  int sco = 0;
  srand(time(NULL));
  jeu.niveau=0;
    //Nombre de pastilles
  jeu.pastille=5;
    //Taille du terrain
  jeu.sizem = 60*40;
    //nombre de case horizontale
  jeu.sx = 60;
    //nombre de case verticale
  jeu.sy= 40;
  jeu.next = 1;
  jeu.taillec = 20;
  jeu.cyc = 0;
  jeu.snake.taille = 10;
  jeu.snake.tailles = 10;


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

	if(np==0) menu1();
	else menu2(sco);
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
      	sco=Partie(&jeu);
	np=np+1;
      	menu2(sco);
      	pos1();
      }

    }
    }
	
}
