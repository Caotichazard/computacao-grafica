#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include "cg2d.h"






//Função auxiliar para impressão formatada de pontos
void printPoint(point* pointToPrint);

//Função para verificar se um botão é válido
point* parsePoint(point* pointToParse);

//funções get e set para valores utilizados
int getMonitorH ();
int getMonitorW ();

void setMonitorH (int newMonitorH);
void setMonitorW (int newMonitorW);


float getWindowH();
float getWindowW();

void setWindowH(float newWindowH);
void setWindowW(float newWindowW);




float getWorldH();
float getWorldW();

void setWorldH(float newWorldH);
void setWorldW(float newWorldW);

#endif