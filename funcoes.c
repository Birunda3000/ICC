//Universidade Estadual do Ceara
//Ciencia da Computação
//Prof.: Leonardo S. Rocha
//Aluno: Erick Santos do Nascimento
/*ATENÇÃO TODAS AS FUNÇÕES QUE RETORNAM UM PONTEIRO DE MATRIZ (**) DEPENDEM DA FUNÇÃO ALOCAR MATRIZ*/
#include <stdio.h>
#include <stdlib.h>
float multiplicaoescalar (int tamanhodosvetores, float *vetor1, float *vetor2){/*entra com o ponteiro de 2 vetores, tamanho dos vetores e retorna o resultado da operação*/
    int controle = 0;
    float resultado = 0;
    float *vetorresultante;
    vetorresultante = (float*) malloc(sizeof(float)*tamanhodosvetores);
    while(controle < tamanhodosvetores){
        vetorresultante[controle] = vetor1[controle] * vetor2[controle];
        controle++;
        }
    controle = 0;
    while(controle < tamanhodosvetores){
        resultado += vetorresultante[controle];
        controle++;
    }
    printf("multipicacao escalar e = %f", resultado);
    return resultado;
}
void lervetores(float *vetor, int tamanhovetor, int numerodovetor){/*entra com o ponteiro e o tamanho do vetor (numero so serve para indicar qual vetor recebido)e recebe os valores do vetor*/

    int i = 0;
    int controle = 0;
    printf("digite o vetor %d\n", numerodovetor);
    while(tamanhovetor > i){
        printf("na posicao %d\n", i);
        scanf("%f", &vetor[i]);
        i++;
        }
    while(controle < tamanhovetor){
        printf("valor digitado na  posicao %d o valor e %f\n\n", controle, vetor[controle]);
        controle++;
        }
        }
float* multiplicarvetorporescalar(float escalar, int tamanhovetor, float *vetor){/*entra com o escalar e com o ponteiro do vetor e retorna um ponteiro para o vetor resultante*/
    int controle = 0;
    float *vetorresultante;
    vetorresultante = (float*) malloc(sizeof(float) * tamanhovetor);
    for(controle = 0; controle < tamanhovetor; controle++){
        vetorresultante[controle] = vetor[controle]*escalar;
        printf("\n\nRESULTADO:\n\nNa posicao %d e %f\n", controle, vetorresultante[controle]);
    }
    return vetorresultante;
    }
float* somarvetores(int tamanhodosvetores, float *vetor1, float *vetor2){/*recebe 2 ponteiros para os vetores envolvidos e retorna um ponteiro para o vetor resultante*/

    int controle = 0;
    float *vetorsoma;
    vetorsoma = (float*) malloc(sizeof(float) * tamanhodosvetores);
    while(controle < tamanhodosvetores){
        vetorsoma[controle] = vetor1[controle] + vetor2[controle];
        printf("\n\n\nRESULTADO:\n\nna posicao %d o valor e %f\n", controle, vetorsoma[controle]);
        controle++;
        }
    return vetorsoma;
}
float **alocarmatriz(int linhas, int colunas){ /*Recebe a quantidade de Linhas e Colunas e retorna uma ponteiro para matriz alocada*/
  int i,j;
  float **p = (float**)malloc(linhas * sizeof(float*));
  for (i = 0; i < linhas; i++){
       p[i] = (float*) malloc(colunas * sizeof(float));
       for (j = 0; j < colunas; j++){
            p[i][j] = 0;
       }
  }
return p;
}
void lermatrizes (float **matriz, int linha, int coluna, int numero){/*recebe um ponteiro de matriz o numero e linhas e colunas e recebe os valores de cada posição*/
    int l = 0;
    int c = 0;
    printf("\ndigite a matriz %d\n", numero);
    for(l=0;l<linha;l++){
        for(c=0;c<coluna;c++){
            printf("\n digite o elemento na posicao[%d][%d] ", l, c);
            scanf("%f", &matriz[l][c]);
        }
    }
}
float **somarmatrizes(int numerodelinhas, int numerodecolunas, int linha2, int coluna2, float **matriz1, float **matriz2){/*recebe 2 matrizes o numero de linhas e colunas das 2 matrizes e retorna uma matriz soma*/
    if (numerodecolunas == coluna2 && numerodelinhas == linha2){
        int controlelinhas = 0;
        int controlecolunas = 0;
        float **matrizr = alocarmatriz(numerodelinhas, numerodecolunas);
        while(numerodelinhas > controlelinhas){
            controlecolunas = 0;
            while(numerodecolunas > controlecolunas){
                matrizr[controlelinhas] [controlecolunas] = matriz1[controlelinhas] [controlecolunas] + matriz2[controlelinhas] [controlecolunas];
                controlecolunas++;
                }
            controlelinhas++;
            }
        return matrizr;
        }
        else{
            printf("\nimpossivel somar as matrizes pois as dimensoes sao diferentes entre com uma nova\n");
            return 0;
        }
    }
float **multiplicacaodematrizes(float **matriz1, int linha1, int coluna1, float **matriz2, int linha2, int coluna2){/*recebe 2 matrizes o numero de linhas e colunas da primeira e segunda matriz e retorna uma matriz multiplicação*/
    if(coluna1 == linha2){
        float **matrizr = alocarmatriz(linha1, coluna2);
        int k1 = 0;//controle das linhas da matriz 1
        int k2 = 0;//controle das colunas da matriz 2
        int i = 0;
        float auxi = 0;
        for(k1=0;k1<linha1;k1++){
            for(k2=0;k2<coluna2;k2++){
                auxi = 0;
                for(i=0;i<coluna1;i++){
                    auxi = auxi + (matriz1[k1][i] * matriz2[i][k2]);
                    }
                matrizr[k1][k2] = auxi;
                }
        }
        return matrizr;
    }
        else{
            printf("nao e possivel multiplicar essa matrizes");
            return 0;
        }
}
float determinante(float **matriz, int linha, int coluna){/*recebe a matriz o numero de linhas colunas e retorna um float da determinante*/
    float determinante = 0;
    if (linha == coluna){
        int teste;
        teste = linha + coluna;
        switch(teste){
            case 2:{//1x1
                determinante = matriz[0][0];
                break;
                }
            case 4:{//2x2
                float diagonala = matriz[0][0] * matriz[1][1];
                float diagonals = (-1 * matriz[0][1] * matriz[1][0]);
                determinante = diagonala + diagonals;
                break;
                }
            case 6:{//3x3
                float diagonal1 = matriz[0][0] * matriz[1][1] * matriz[2][2];
                float diagonal2 = matriz[0][1] * matriz[1][2] * matriz[2][0];
                float diagonal3 = matriz[0][2] * matriz[1][0] * matriz[2][1];
                float diagonals1 = (-1 * matriz[0][2]) * (-1 * matriz[1][1]) * (-1 * matriz[2][0]);
                float diagonals2 = (-1 * matriz[0][0]) * (-1 * matriz[1][2]) * (-1 * matriz[2][1]);
                float diagonals3 = (-1 * matriz[0][1]) * (-1 * matriz[1][0]) * (-1 * matriz[2][2]);
                determinante = diagonal1 + diagonal2 + diagonal3 + diagonals1 + diagonals2 + diagonals3;
                break;
                }
            default:{
                printf("\n determinante apenas para matrizes 3x3 2x2 ou 1x1 entre com uma nova matriz \n");
                break;
                }
            }//fim do switch
            return determinante;
            }
            else{
                printf("\ndeterminante apenas para matrizes 3x3 2x2 ou 1x1 entre com uma nova matriz\n");
                return 0;
            }
    }
float **transposta(float **matriz, int linha, int coluna){/*recebe uma matriz o numero de linhas e colunas e retorna uma transposta*/
    int c = 0;
    int l = 0;
    float **matrizt = alocarmatriz(coluna, linha);
    for(l=0;l<linha;l++){
        for(c=0;c<coluna;c++){
            matrizt[c][l] = matriz [l][c];
        }
    }
    return matrizt;
}
void verificarmatrizsimetrica(float **matriz, int linha, int coluna){/*recebe o numero de linhas o numero de colunas*/
    int teste = 0;
    int l = 0;
    int c = 0;
    if (coluna == linha){
        for(l=0;l<linha;l++){
            for(c=0;c<coluna;c++)
               if (matriz[l][c] != matriz[c][l]){
                teste = 1;
                }
            }
        if (teste == 0){
            printf("\na matriz e simetrica\n");
        }
        if (teste == 1){
            printf("\nnao e simetrica\n");
        }
    }
        else{
            printf("\nnao e simetrica\n");
        }
}
void limaparmatriz(float **p,int linhas, int colunas){ /*Recebe o ponteiro quantidade de Linhas e Colunas e liberta essas posições de memoria*/
  int i,j;
  for (i = 0; i < linhas; i++){
       free(p[i]);
       }
  free(p);
}
void exibirmatriz(float **matriz, int linhas, int colunas){/*Recebe o ponteiro da Matriz o numero de colunas e o numero de linhas e imprime a a matriz na tela*/
    int l = 0;
    int c = 0;
    printf("\n\n\n\t**RESULTADO**\n\n");
    for(l = 0; l < linhas ; l++){
        for(c=0;c<colunas;c++){
            printf("%.2f\t", matriz [l][c]);
            }
        printf("\n");
        }
    printf("\n\n----------------------------------\n\n\n");
}
/*ATENÇÃO TODAS AS FUNÇÕES QUE RETORNAM UM PONTEIRO DE MATRIZ (**) DEPENDEM DA FUNÇÃO ALOCAR MATRIZ*/
//Aluno:Erick Santos do Nascimento
//UECE Ciencia da Computação
