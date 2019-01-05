#include<stdlib.h>
#include<graph.h>
#include "Options.h"

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
