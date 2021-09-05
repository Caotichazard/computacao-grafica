/*
Guilherme Locca Salomão - 758569


Nota: professor, fiz apenas uma alteração pequena no cg2d.h que foi adicionar o ifndef para permitir incluir ele multiplas vezes no codigo em arquivos diferentes
sem essa guarda ele alegava o erro de multiplas definições das funções e estruturas presentes nele, fora isso os arquivos do cg2d foram mantidos.

Tive uma dificuldade em finalizar a captura do mouse, pois há momentos onde ele realiza a captura de apertar um botão mas nunca "atualiza" os valores
de volta a 0, por isso há um loop adicional no whereismymouse para corrigir isso.

Adicionei tambem uma makefile para facilitar o processo de compilação.

*/


#include "linklist.h"
#include "util.h"
#include "whereismymouse.h"


int main(){
    
    //Ajustando valores da janela, mais funções para ajuste de janela, mundo, viewport e etc em util.h
    setWindowH(640);
    setWindowW(480);
    
    //Configurações para o cg2d
    palette * palheta;
    bufferdevice * monitor;
    window * janela;
    viewport * porta;
    object * bordas;

    SetWorld(-getWorldH(), -getWorldW(), getWorldH(), getWorldW()); // Define o tamanho do mundo 

    monitor = CreateBuffer(getMonitorH(),getMonitorW()); // Cria um monitor virtual
    
    palheta = CreatePalette(5);  // Cria um colormap (lookup table) com 5 cores
    SetColor(0,0,0,palheta);
    SetColor(1,0,0,palheta);
    SetColor(0,1,0,palheta);
    SetColor(0,0,1,palheta);
    SetColor(1,1,1,palheta);


 


    janela = CreateWindow(-getWindowH(),-getWindowW(),getWindowH(),getWindowW()); // cria uma janela de visualização (coordenadas no SRU)
    //definindo desse jeito a janela, o centro e ponto de partida do mouse é o centro da janela.


    porta = CreateViewPort(0, 0, getMonitorH()-1, getMonitorW()-1); // Cria uma viewport
  
    
    

    
    
   

    
    //Realiza a captura dos movimentos do mouse em whereismymouse.c
    captureMouse();

    
    //apos a captura for realizada,recebe a cabeça da lista
    pointlist* tmp_list = getHead();
    while (tmp_list->nextpoint != NULL)//enquanto houver um par de elementos na lista
    {
        if(tmp_list->isCaptured == 1 && tmp_list->nextpoint->isCaptured == 1){//se ambos o ponto atual e o proximo ponto foram capturados
            DrawLine(tmp_list->point,tmp_list->nextpoint->point,janela,porta,monitor,1);//desenha uma linha entre eles
            
        }
        tmp_list = tmp_list->nextpoint;//passa para o proximo ponto
    }
    

    clear();//limpa a lista



    Dump2X(monitor,palheta);//desenha e mostra a tela

    return 0;

}