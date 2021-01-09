#ifndef MIG_H_INCLUDED
#define MIGUEL_H_INCLUDED

void AtualizaMatriz(int *vetor,int i);

int funcaolinha(int *vetor);

int funcaocoluna(int *vetor);

int funcaoquadrante(int *vetor);

void nomedojogador(char nome[],int ganharouperder,int status,int *vetor);

int jogada(char jogadas[]);

int ganharouperder(int funcon,int funlin,int funqua, int *vetor);

int *retornaposdosvlrnulos(int tamanho, int *vetor);

void impvalornulos(int *vetornulos, int tamanho);

#endif /* STR_H_INCLUDED */



