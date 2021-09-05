#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include "cg2d.h"
#include "util.h"


//estrutura da lista ligada de pontos capturados
typedef struct pointlist
{
    point *point;//o ponto em si
    int isCaptured;//se o ponto vai ser desenhado
    struct pointlist *nextpoint;//proximo ponto
} pointlist;




//adiciona a cauda da lista
void push(point *pointToAdd, int captureState);

//Limpa a lista de pontos
void clear();


//pega proximo elemento na lista
pointlist *getNext();


//recebe a cabeça da lista
pointlist *getHead();

//recebe a cauda da lista
pointlist *getTail();

//recebe o ultimo ponto analisado
pointlist *getCur();

//imprime na tela as informações de todos os elementos
void printAll();
#endif