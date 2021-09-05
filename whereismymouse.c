#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "whereismymouse.h"
//#include "util.h"

// int main()
// {
// 	captureMouse();
// }


//Função responsável por realizar a captura dos movimentos do mouse
int captureMouse(void)
{
	//Declarações necessárias para o uso
	int fd, bytes, esquerdo, direito, centro;
	signed char x, y;
	unsigned char data[3];
	const char *mouse_device = "/dev/input/mice";

	// Abre o mouse
	if ((fd = open(mouse_device, O_RDWR)) == -1)
	{
		printf("Houve um erro abrindo %s... você executou como superusuário?\n", mouse_device);
		return -1;
	}

	// Bandeiras utilizadas para sinalizar
	int esqFlag = 0; //captura do movimento do mouse em relaçao ao ultimo ponto capturado, permitindo varios "periodos de captura"
	int dirFlag = 0; //encerrar a captura no geral e permite o proseguimento do codigo


	//insere na lista de pontos a origem, centro da tela
	push(SetPoint(0.0, 0.0, 1, 1),1);


	printf("Para realizar a captura do mouse, aperte com o botão esquerdo, para cancelar a captura, aperte novamente o botão esquerdo\n");
	printf("Para encerrar a captura e exibir desenho, aperte o botão direito do mouse");
	// Fica lendo o mouse
	//Enquanto o botão direito do mouse não for pressionado
	while (dirFlag == 0)
	{
		//Le o arquivo do mouse
		bytes = read(fd, data, sizeof(data));
		if (bytes > 0)//se houver informações
		{
			// informações sobre os botões do mouse
			esquerdo = data[0] & 0x1;
			direito = data[0] & 0x2;
			centro = data[0] & 0x4;
			// posição relativa do ponteiro
			x = data[1];
			y = data[2];
			
			
			//printf("x = %d, y = %d, esquerdo = %d, direito = %d, centro = %d\n", x, y, esquerdo, direito, centro);
			point *lastPoin = getTail()->point;//recebe a ultima posição capturada do mouse
			push(SetPoint(lastPoin->x + x, lastPoin->y + y, lastPoin->w, lastPoin->color),esqFlag);//adiciona a ela o vetor atual do mouse e se ele foi capturado para o desenho
			

			//altera o estado da captura
			if (esquerdo > 0)
			{
				if (esqFlag == 0)//inicia a captura
				{
					esqFlag = 1;
				}
				else//finaliza a captura
				{
					esqFlag = 0;
				}
			}

			//finaliza o loop
			if (direito > 0){
				if(dirFlag == 0){
					dirFlag = 1;
				}else{
					dirFlag = 0;
				}
			}
		}
	}

	//Por algum motivo apos encerrar a leitura, os valores podem ficar diferente de 0, ou seja pensa que os botões estão sendo segurados
	//por isso esse loop pede ao usuário que aperte novamente os botões necessários para corrigir isso
	while (direito != 0 || esquerdo != 0 || centro != 0)
	{
		
		bytes = read(fd, data, sizeof(data));
		if (bytes > 0)
		{
			// informações sobre os botões do mouse
			esquerdo = data[0] & 0x1;
			direito = data[0] & 0x2;
			centro = data[0] & 0x4;
			// posição relativa do ponteiro
			x = data[1];
			y = data[2];
			// exibe as informações
			printf("Encerrando captura....");
			
			if(direito != 0){
				printf("por favor aperte o botão direito do mouse..");
			}
			if(esquerdo != 0){
				printf("por favor aperte o botão esquerdo do mouse..");
			}if(centro != 0){
				printf("por favor aperte o botão central do mouse..");
			}
			printf("\n");
			printf("x = %d, y = %d, esquerdo = %d, direito = %d, centro = %d\n", x, y, esquerdo, direito, centro);
			
				
			
		}
	}


	

	
	// printAll();

	// clear();

	return 0;
}
