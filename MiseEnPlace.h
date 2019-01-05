#ifndef MISEENPLACE_H
#define MISEENPLACE_H

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


void AfficherMap(Map);
void InitMap(Map*);
void poserFruit(Map*);
void poserObs(Map*);
void chunk(Map*);
void Agrandir(Map*);

#endif
