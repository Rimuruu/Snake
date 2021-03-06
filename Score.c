#include<stdlib.h>
#include<graph.h>
#include "Score.h"

void niv(int niv1,int niv2){

  couleur white=CouleurParNom("white");
  couleur black=CouleurParNom("black");

  ChoisirEcran(1);
  if(niv1==1) {
    ChoisirCouleurDessin(black);
    RemplirRectangle(148,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(150,840,"1",2);
  }
  else if(niv1==2){
    ChoisirCouleurDessin(black);
    RemplirRectangle(148,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(150,840,"2",2);
  }
  else if(niv1==3){
    ChoisirCouleurDessin(black);
    RemplirRectangle(148,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(150,840,"3",2);
  }
  else if(niv1==4){
    ChoisirCouleurDessin(black);
    RemplirRectangle(148,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(150,840,"4",2);
  }
  else if(niv1==5){
    ChoisirCouleurDessin(black);
    RemplirRectangle(148,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(150,840,"5",2);
  }
  else if(niv1==6){
    ChoisirCouleurDessin(black);
    RemplirRectangle(148,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(150,840,"6",2);
  }
  else if(niv1==7){
    ChoisirCouleurDessin(black);
    RemplirRectangle(148,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(150,840,"7",2);
  }
  else if(niv1==8){
    ChoisirCouleurDessin(black);
    RemplirRectangle(148,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(150,840,"8",2);
  }
  else if(niv1==9){
    ChoisirCouleurDessin(black);
    RemplirRectangle(148,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(150,840,"9",2);
  }
  else if(niv1==0){
    ChoisirCouleurDessin(black);
    RemplirRectangle(148,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(150,840,"0",2);
  }

  ChoisirCouleurDessin(black);
  RemplirRectangle(130,800,20,50);
  if(niv2==1) {
    ChoisirCouleurDessin(white);
    EcrireTexte(135,840,"1",2);
  }
  else if(niv2==2){
    ChoisirCouleurDessin(white);
    EcrireTexte(135,840,"2",2);
  }
  else if(niv2==3){
    ChoisirCouleurDessin(white);
    EcrireTexte(135,840,"3",2);
  }
  else if(niv2==4){
    ChoisirCouleurDessin(white);
    EcrireTexte(135,840,"4",2);
  }
  else if(niv2==5){
    ChoisirCouleurDessin(white);
    EcrireTexte(135,840,"5",2);
  }
  else if(niv2==6){
    ChoisirCouleurDessin(white);
    EcrireTexte(135,840,"6",2);
  }
  else if(niv2==7){
    ChoisirCouleurDessin(white);
    EcrireTexte(135,840,"7",2);
  }
  else if(niv2==8){
    ChoisirCouleurDessin(white);
    EcrireTexte(135,840,"8",2);
  }
  else if(niv2==9){
    ChoisirCouleurDessin(white);
    EcrireTexte(135,840,"9",2);
  }
  CopierZone(1,0,130,810,32,40,130,810);
  ChoisirEcran(0);

}

void score(int sco){

  int score = sco * 5;
  int n1 = score/1000;
  int n2 = (score - n1*1000)/100;
  int n3 = (score - n1*1000 -n2*100)/10;
  int n4 = score - n1*1000 -n2*100 -n3*10;

  couleur white=CouleurParNom("white");
  couleur black=CouleurParNom("black");

  ChoisirEcran(1);

  if(n1==1){
    ChoisirCouleurDessin(black);
    RemplirRectangle(890,800,50,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(915,840,"1",2);
  }
  else if(n1==2){
    ChoisirCouleurDessin(black);
    RemplirRectangle(890,800,50,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(915,840,"2",2);
  }
  else if(n1==3){
    ChoisirCouleurDessin(black);
    RemplirRectangle(890,800,50,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(915,840,"3",2);
  }
  else if(n1==4){
    ChoisirCouleurDessin(black);
    RemplirRectangle(890,800,50,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(915,840,"4",2);
  }
  else if(n1==5){
    ChoisirCouleurDessin(black);
    RemplirRectangle(890,800,50,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(915,840,"5",2);
  }
  else if(n1==6){
    ChoisirCouleurDessin(black);
    RemplirRectangle(890,800,50,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(915,840,"6",2);
  }
  else if(n1==7){
    ChoisirCouleurDessin(black);
    RemplirRectangle(890,800,50,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(915,840,"7",2);
  }
  else if(n1==8){
    ChoisirCouleurDessin(black);
    RemplirRectangle(890,800,50,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(915,840,"8",2);
  }
  else if(n1==9){
    ChoisirCouleurDessin(black);
    RemplirRectangle(890,800,50,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(915,840,"9",2);
  }
  else if(n1==0){
    ChoisirCouleurDessin(black);
    RemplirRectangle(890,800,50,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(915,840,"0",2);
  }

  if(n2==1){
    ChoisirCouleurDessin(black);
    RemplirRectangle(928,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(930,840,"1",2);
  }
  else if(n2==2){
    ChoisirCouleurDessin(black);
    RemplirRectangle(928,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(930,840,"2",2);
  }
  else if(n2==3){
    ChoisirCouleurDessin(black);
    RemplirRectangle(928,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(930,840,"3",2);
  }
  else if(n2==4){
    ChoisirCouleurDessin(black);
    RemplirRectangle(928,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(930,840,"4",2);
  }
  else if(n2==5){
    ChoisirCouleurDessin(black);
    RemplirRectangle(928,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(930,840,"5",2);
  }
  else if(n2==6){
    ChoisirCouleurDessin(black);
    RemplirRectangle(928,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(930,840,"6",2);
  }
  else if(n2==7){
    ChoisirCouleurDessin(black);
    RemplirRectangle(928,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(930,840,"7",2);
  }
  else if(n2==8){
    ChoisirCouleurDessin(black);
    RemplirRectangle(928,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(930,840,"8",2);
  }
  else if(n2==9){
    ChoisirCouleurDessin(black);
    RemplirRectangle(928,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(930,840,"9",2);
  }
  else if(n2==0){
    ChoisirCouleurDessin(black);
    RemplirRectangle(928,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(930,840,"0",2);
  }

  if(n3==1){
    ChoisirCouleurDessin(black);
    RemplirRectangle(943,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(945,840,"1",2);
  }
  else if(n3==2){
    ChoisirCouleurDessin(black);
    RemplirRectangle(943,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(945,840,"2",2);
  }
  else if(n3==3){
    ChoisirCouleurDessin(black);
    RemplirRectangle(943,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(945,840,"3",2);
  }
  else if(n3==4){
    ChoisirCouleurDessin(black);
    RemplirRectangle(943,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(945,840,"4",2);
  }
  else if(n3==5){
    ChoisirCouleurDessin(black);
    RemplirRectangle(943,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(945,840,"5",2);
  }
  else if(n3==6){
    ChoisirCouleurDessin(black);
    RemplirRectangle(943,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(945,840,"6",2);
  }
  else if(n3==7){
    ChoisirCouleurDessin(black);
    RemplirRectangle(943,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(945,840,"7",2);
  }
  else if(n3==8){
    ChoisirCouleurDessin(black);
    RemplirRectangle(943,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(945,840,"8",2);
  }
  else if(n3==9){
    ChoisirCouleurDessin(black);
    RemplirRectangle(943,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(945,840,"9",2);
  }
  else if(n3==0){
    ChoisirCouleurDessin(black);
    RemplirRectangle(943,800,15,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(945,840,"0",2);
  }

  if(n4==1){
    ChoisirCouleurDessin(black);
    RemplirRectangle(958,800,100,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(960,840,"1",2);
  }
  else if(n4==2){
    ChoisirCouleurDessin(black);
    RemplirRectangle(958,800,100,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(960,840,"2",2);
  }
  else if(n4==3){
    ChoisirCouleurDessin(black);
    RemplirRectangle(958,800,100,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(960,840,"3",2);
  }
  else if(n4==4){
    ChoisirCouleurDessin(black);
    RemplirRectangle(958,800,100,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(960,840,"4",2);
  }
  else if(n4==5){
    ChoisirCouleurDessin(black);
    RemplirRectangle(958,800,100,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(960,840,"5",2);
  }
  else if(n4==6){
    ChoisirCouleurDessin(black);
    RemplirRectangle(958,800,100,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(960,840,"6",2);
  }
  else if(n4==7){
    ChoisirCouleurDessin(black);
    RemplirRectangle(958,800,100,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(960,840,"7",2);
  }
  else if(n4==8){
    ChoisirCouleurDessin(black);
    RemplirRectangle(958,800,100,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(960,840,"8",2);
  }
  else if(n4==9){
    ChoisirCouleurDessin(black);
    RemplirRectangle(958,800,100,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(960,840,"9",2);
  }
  else if(n4==0){
    ChoisirCouleurDessin(black);
    RemplirRectangle(958,800,100,50);
    ChoisirCouleurDessin(white);
    EcrireTexte(960,840,"0",2);
  }
  
  CopierZone(1,0,890,810,100,40,890,810);
  ChoisirEcran(0);

  }
