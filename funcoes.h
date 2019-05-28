//Universidade Estadual do Ceara
//Ciencia da Computação
//Prof.: Leonardo S. Rocha
//Aluno: Erick Santos do Nascimento
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.c"
float multiplicaoescalar (int tamanhodosvetores, float *vetor1, float *vetor2);/*entra com o ponteiro de 2 vetores, tamanho dos vetores e retorna o resultado da operação*/

void lervetores(float *vetor, int tamanhovetor, int numerodovetor);/*entra com o ponteiro e o tamanho do vetor (numero so serve para indicar qual vetor recebido)e recebe os valores do vetor*/

float* multiplicarvetorporescalar(float escalar, int tamanhovetor, float *vetor);/*entra com o escalar e com o ponteiro do vetor e retorna um ponteiro para o vetor resultante*/

float* somarvetores(int tamanhodosvetores, float *vetor1, float *vetor2);/*recebe 2 ponteiros para os vetores envolvidos e retorna um ponteiro para o vetor resultante*/
/*ATENÇÃO TODAS AS FUNÇÕES QUE RETORNAM UM PONTEIRO DE MATRIZ DEPENDEM DA FUNÇÃO ALOCAR MATRIZ*/
void lermatrizes (float **matriz, int linha, int coluna, int numero);/*recebe um ponteiro de matriz o numero e linhas e colunas e recebe os valores de cada posição*/

float **somarmatrizes(int numerodelinhas, int numerodecolunas, int linha2, int coluna2, float **matriz1, float **matriz2);/*recebe 2 matrizes o numero de linhas e colunas das 2 matrizes e retorna uma matriz soma*/

float **multiplicacaodematrizes(float **matriz1, int linha1, int coluna1, float **matriz2, int linha2, int coluna2);/*recebe 2 matrizes o numero de linhas e colunas da primeira e segunda matriz e retorna uma matriz multiplicação*/

float determinante(float **matriz, int linha, int coluna);/*recebe a matriz o numero de linhas colunas e retorna um float da determinante*/

float **transposta(float **matriz, int linha, int coluna);/*recebe uma matriz o nuumero de linhas e colunas e retorna uma transposta*/

void verificarmatrizsimetrica(float **matriz, int linha, int coluna);/*recebe o numero de linhas o numero de colunas*/

float **alocarmatriz(int linhas, int colunas); /*Recebe a quantidade de Linhas e Colunas e retorna uma ponteiro para matriz alocada*/

void limaparmatriz(float **p,int linhas, int colunas); /*Recebe o ponteiro quantidade de Linhas e Colunas e liberta essas posições de memoria*/
/*ATENÇÃO TODAS AS FUNÇÕES QUE RETORNAM UM PONTEIRO DE MATRIZ (**)DEPENDEM DA FUNÇÃO ALOCAR MATRIZ*/
//Aluno:Erick Santos do Nascimento
//UECE Ciencia da Computação
