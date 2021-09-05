#include "linklist.h"

pointlist *head = NULL;
pointlist *tail = NULL;
pointlist *cur = NULL;
//adiciona a cauda da lista
void push(point *pointToAdd, int captureState)
{
    //Aloca a memoria para o novo ponto
     pointlist *new_point = ( pointlist *)malloc(sizeof( pointlist));

    //Insere as informações
    new_point->point = parsePoint(pointToAdd);
    new_point->isCaptured = captureState;
    new_point->nextpoint = NULL;

    //Caso seja o primeiro ponto prepara tudo
    if (head == NULL)
    {
        head = new_point;
        tail = head;
        cur = head;
    }
    else//caso haja já outros pontos, adiciona ele a cauda e o coloca como a cauda nova
    {
        tail->nextpoint = new_point;
        tail = new_point;
    }
}

//pega proximo elemento na lista
 pointlist *getNext()
{
     pointlist *tmp = cur;
    if(tmp->nextpoint == NULL){
        cur = head;
        return head;
    }else{
        cur = tmp->nextpoint;
    }
    return tmp->nextpoint;
}

//recebe a cabeça da lista
 pointlist *getHead()
{
    return head;
}

//recebe a cauda da lista
 pointlist *getTail()
{
    return tail;
}

//recebe o ultimo ponto analisado
 pointlist *getCur()
{
    return cur;
}

//limpa a lista
void clear(){
    while(head != NULL){
         pointlist* tmp = head;
        head = head->nextpoint;

        free(tmp);
    }

    return;
}
//imprime todos os elementos da lista
void printAll(){
    pointlist* tmp = head;
    while (tmp != NULL)
    {
        printPoint(tmp->point);
        tmp = tmp->nextpoint;
    }
    return;
}
