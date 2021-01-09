#include<stdio.h>
#include<math.h>
#include<stddef.h>
#include "miguel.h"
//funçao para atualizar o sudoku
//Regras do jogo
//1° a linha nao pode ter numero repetido !=0
//2° a coluna nao pode ter numero repetido !=0
//3° o quadrante nao pode ter numero repetido !=0

//funçao para atualizar o sudoku
void AtualizaMatriz(int *vetor,int i){

	if(i>=1){
		AtualizaMatriz(vetor,i-1);

		if(i%2==0){
		printf("[%d] ",vetor[i-1]);
		}
		else{
		printf("[%d]",vetor[i-1]);
		}
		if(i%6==0){
			printf("\n");
		}
		if(i%18==0){
			printf("\n");
		}
	}
}
//funçao para ver se algum numero se repete na linha
int funcaolinha(int *vetor){
	int verif=0;
	int x=0;
	for(int i=0;i<36;i++){
		if(i>0 && i%6==0){
			x= x+6;
		}
		if(vetor[0+x]==vetor[1+x] && vetor[0+x]!=0 || vetor[2+x]==vetor[3+x] && vetor[2+x]!=0 || vetor[4+x]==vetor[5+x] && vetor[4+x]!=0){
		verif=1;
		}
		if(vetor[0+x]==vetor[2+x] && vetor[0+x]!=0 || vetor[1+x]==vetor[3+x] && vetor[1+x]!=0 || vetor[2+x]==vetor[4+x] && vetor[2+x]!=0){
		verif=1;
		}
		if(vetor[0+x]==vetor[3+x] && vetor[3+x]!=0 || vetor[1+x]==vetor[4+x] && vetor[4+x]!=0 || vetor[2+x]==vetor[5+x] && vetor[5+x]!=0){
		verif=1;
		}
		if(vetor[0+x]==vetor[4+x] && vetor[4+x]!=0 || vetor[1+x]==vetor[2+x] && vetor[2+x]!=0 || vetor[3+x]==vetor[5+x] && vetor[5+x]!=0 ){
		verif=1;
		}
		if(vetor[0+x]==vetor[5+x] && vetor[5+x]!=0 || vetor[1+x]==vetor[5+x] && vetor[5+x]!=0 || vetor[3+x]==vetor[4+x] && vetor[4+x]!=0 ){
		verif=1;
		}
	}
	if(verif==1){
	printf("\nValor Repetido em alguma Linha!");
	return 0;
	}else{
		return 1;
	}
}
//funçao para ver se algum numero se repete na coluna
int funcaocoluna(int *vetor){
	int verif=0;
	int x=0;
	for(int i=0;i<36;i++){
		vetor[i];
		if(i>0 && i%6==0){
			x++;
		}
		if(vetor[0+x]==vetor[6+x] && vetor[6+x]!=0 || vetor[12+x]==vetor[18+x] && vetor[12+x]!=0 || vetor[24+x]==vetor[30+x] && vetor[24+x]!=0){
		verif=1;
		}
		if(vetor[0+x]==vetor[12+x] && vetor[12+x]!=0 || vetor[6+x]==vetor[18+x] && vetor[6+x]!=0 || vetor[12+x]==vetor[24+x] && vetor[12+x]!=0){
		verif=1;
		}
		if(vetor[0+x]==vetor[18+x] && vetor[18+x]!=0 || vetor[6+x]==vetor[24+x] && vetor[24+x]!=0 || vetor[12+x]==vetor[30+x] && vetor[30+x]!=0){
		verif=1;
		}
		if(vetor[0+x]==vetor[24+x] && vetor[24+x]!=0 || vetor[6+x]==vetor[12+x] && vetor[12+x]!=0 || vetor[18+x]==vetor[30+x] && vetor[30+x]!=0 ){
		verif=1;
		}
		if(vetor[0+x]==vetor[30+x] && vetor[30+x]!=0 || vetor[6+x]==vetor[30+x] && vetor[30+x]!=0 || vetor[18+x]==vetor[24+x] && vetor[24+x]!=0 ){
		verif=1;
		}
	}
	if(verif==1){
	printf("\nValor Repetido em alguma Coluna!");
		return 0;
	}else{
		return 1;
	}
}
//funçao para ver se algum numero se repete no quadrante
int funcaoquadrante(int *vetor){
    int verif=0;
    int x=0;
    int y=0;
    for(int i=0;i<36;i++){
        vetor[i];
        if(i>0 && i%15==0){
            x+=2;
        }
            if(i>0 && i%18==0){
            y+=18;
        }
        if(vetor[0+x+y]==vetor[7+x+y] && vetor[0+x+y]!=0  ||vetor[0+x+y]==vetor[13+x+y] && vetor[0+x+y]!=0||
         vetor[0+x+y]==vetor[1+x+y] && vetor[0+x+y]!=0 ||vetor[0+x+y]==vetor[6+x+y] && vetor[0+x+y]!=0 ||vetor[0+x+y]==vetor[12+x+y] && vetor[0+x+y]!=0){
        verif=1;
        }
        if(vetor[6+x+y]==vetor[1+x+y] && vetor[6+x+y]!=0 || vetor[6+x+y]==vetor[13+x+y] && vetor[6+x+y]!=0||
         vetor[6+x+y]==vetor[7+x+y] && vetor[6+x+y]!=0||vetor[6+x+y]==vetor[0+x+y] && vetor[6+x+y]!=0||vetor[6+x+y]==vetor[12+x+y] && vetor[6+x+y]!=0){
        verif=1;
        }
        if(vetor[12+x+y]==vetor[1+x+y] && vetor[12+x+y]!=0 || vetor[12+x+y]==vetor[7+x+y] && vetor[12+x+y]!=0||
         vetor[12+x+y]==vetor[13+x+y] && vetor[12+x+y]!=0||vetor[12+x+y]==vetor[0+x+y] && vetor[12+x+y]!=0||vetor[12+x+y]==vetor[6+x+y] && vetor[12+x+y]!=0){
        verif=1;
        }
    }
    if(verif==1){
    printf("\nValor Repetido em algum Quadrante!");
    	return 0;
	}else{
		return 1;
	}
}
//armazena o nome do jogador, na proxima etapa ,utilizarei essa funcao
//para armazenar no arquivo.
/*agora minha funçao alem de executar como antes ela armazena os dados
por nome do jogador, e armazena o sudoku do jogador,
se ele ganhou ou perdeu e a qtd de movimentos */
void nomedojogador(char nome[],int ganharouperder,int status,int *vetor){
	char prefixo[10] ="./";
	FILE *arq;
	strncat(prefixo,nome,20);
	arq = fopen(strncat(prefixo,".txt",20),"w");
        if(arq ==NULL){
            printf("Erro ao Criar Arquivo");
            }
	if(ganharouperder==0){
		printf("VOCE GANHOUUU!!\n");
		printf(" O jogador %s realizou %d movimentos",nome,status);
		fputs("VOCE GANHOUUU!!\n",arq);
		fprintf(arq,"O jogador %s realizou %d movimentos\n",&nome, &status);
		fputs("\tSUDOKU!!",arq);
		for (int i=1;i<=36;i++){
                if(i%6==0){
                 fprintf(arq," \n[%d]", vetor[i]);
                }else{
                    fprintf(arq," [%d]", vetor[i]);
                }
        }
		fclose(arq);
	}else{
		printf("VOCE PERDEU!!\n");
		printf(" O jogador %s realizou %d movimentos",nome,status);
		fputs("VOCE PERDEU!!\n",arq);
		fprintf(arq,"O jogador %s realizou %d movimentos\n",nome, status);
		fputs("\tSUDOKU!!",arq);
		for (int i=0;i<36;i++){
               // vetor2[i]=vetor[i-1];
                if(i%6==0){
                 fprintf(arq," \n[%d]", vetor[i]);
                }else{
                    fprintf(arq," [%d]", vetor[i]);
                }
        }
		fclose(arq);
	}
}

//funcao para saber se o jogador quer jogar ou nao novamente.
int jogada(char jogar[]){
	int	retorno;
	char resposta[10]="SIM";
		jogar=strupr(jogar);
		retorno=strcmp(jogar,resposta);
			if(retorno==0){
				return 1;
			}else{
				return 0;
			}
}
//funcao para testar se o jogador ganhou ou perdeu ao sair do jogo;
int ganharouperder(int funcon,int funlin,int funqua, int *vetor){
	int retorno=0;
	if(funcon==1 && funlin==1 && funqua==1){
		for(int i=0;i<36;i++){
			if(vetor[i]==0){
				retorno++;
			}
		}
	}else{
		retorno=1;
	}
	return retorno;
}
/*essa funcao retorna a posicao dos numeros igual a zero*/
int *retornaposdosvlrnulos(int tamanho, int *vetor){
    int *armvetor, i;
    int *vetornulos;
   armvetor = (int *)malloc(tamanho *sizeof(int));
    vetornulos = (int *)malloc(tamanho *sizeof(int));
    if(armvetor == NULL){
        printf("Erro 1");
        return NULL;
    }
    if(vetornulos == NULL){
        printf("Erro 2");
        return NULL;
    }
        for(i=0;i<tamanho;i++){
            *(armvetor +i) = vetor[i];
        }
        for(i=0;i<tamanho;i++){
            if(*(armvetor +i)==0){
                *(vetornulos+i)=i;
    }else{
        *(vetornulos+i)=NULL;
        }
    }
    return vetornulos;
}
//imprime na tela a posiçoes dos valores nulos
void impvalornulos(int *vetornulos, int tamanho){
    printf("\nposicao dos valores nulos no sudoku:\n ");
    for (int i = 0; i < tamanho; i++){
        if(*(vetornulos + i)!=0){
        printf("%d,", *(vetornulos + i));
        }
    }
    printf("\n\n");
}
