#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include "lib.h"
#include<math.h>
#include<string.h>
//Regras do jogo
//1° a linha nao pode ter numero repetido !=0
//2° a coluna nao pode ter numero repetido !=0
//3° o quadrante nao pode ter numero repetido !=0

main(){
	int lin,col,valor,teste;
	char nome[20],jogar[20];
	int *vetornulos;
	int converte=0,jogadas=1, contador=0;
	int Vetor [36] ={1,3,0,6,2,0,
					 0,0,5,2,6,0,
					 0,0,0,1,0,0,
					 0,0,1,0,0,0,
				   	 0,4,2,5,0,0,
					 0,2,6,0,3,0
  					};

  	printf("digite seu nome:");
	gets(nome);
        while(jogadas!=0){
            contador++;
            printf("   ----- SUDOKO -----\n\n");
            AtualizaMatriz(Vetor,36);
            funcaolinha(Vetor);
            funcaocoluna(Vetor);
            funcaoquadrante(Vetor);
            printf("\nDigite a linha:");
            scanf("%d",&lin);
            printf("Digite a coluna:");
            scanf("%d",&col);
            printf("Digite o Valor:");
            scanf("%d",&valor);

  		// para facilitar ao usario, usei o metodo como se fosse matriz
  		// utilizando linha x coluna para se localizar no sudoko
  		// e converti dentro do programa para vetores, como utilizei em todo o programa
  	 	converte=(lin*6)+col;
	  	Vetor[converte]=valor;
	  	AtualizaMatriz(Vetor,36);
	  	funcaolinha(Vetor);
	   	funcaocoluna(Vetor);
	   	funcaoquadrante(Vetor);
	  	printf("\nDeseja Continuar?" );
		scanf("%s",jogar);
		jogadas=jogada(jogar);
		system("cls");
		fflush(stdin);
  		}
  			if(jogadas==0){
		  	teste=ganharouperder(funcaocoluna(Vetor),funcaolinha(Vetor),funcaoquadrante(Vetor),Vetor);
		  		nomedojogador(nome,teste,contador,Vetor);
		  		vetornulos= retornaposdosvlrnulos(36,Vetor);
		  		impvalornulos(vetornulos,36);
		  		free(vetornulos);
			}
}

