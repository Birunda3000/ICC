//Universidade Estadual do Ceara
//Ciencia da Computação
//Prof.: Leonardo S. Rocha
//Aluno: Erick Santos do Nascimento
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcoes.h"
    struct vetor{//struct dos vetores
    int tamanhovetor;
    float *vetor;
}vetor;
    struct matriz{//struct das matrizes
    int coluna;
    int linha;
    float **matriz;
}matriz;
int main(){//função principal
    int sairprograma = 10;
    int escolhamenuprincipal = 10;
    int voltarmenuprincipal = 10;
    while (sairprograma != 3){//ciclo principal do programa
        char escolhamenuprincipalstr[256];/*Recebe a opção de menu do usuario (foi utilizado uma string para que o programa não entre em loop caso seja digitada uma letra)*/
        escolhamenuprincipal = 10;
        voltarmenuprincipal = 10;
        escolhamenuprincipal = 10;
        printf("\n\t\t\t------CALCULADORA DA VETORES E MATRIZES------\n\n Digite:\n\n 1) Para operacoes com vetores\n 2) Para operacoes com matrizes\n 3) Para sair do programa\n___________________________________");/*Menu Principal*/
        scanf ("%s", &escolhamenuprincipalstr);
        escolhamenuprincipal = atoi(escolhamenuprincipalstr);//transforma a string em inteiro
        switch (escolhamenuprincipal){ //case 1 vetores e case 2 matrizes e case 3 sair do programa
            case 1:{// Vetores
                struct vetor vetor1;//declaração do vetor 1
                struct vetor vetor2;//declaração do vetor 2
                int escolhamenuvetores = 10;
                int sairmenuvetores = 10;
                voltarmenuprincipal = 10;
                int ler2;//caso o usuario não entre com um vetor
                ler2 = 0;//caso o usuario não entre com nenhum vetor
                while (voltarmenuprincipal != 0){//menu vetores
                    char escolhamenuvetoresstr[256];
                    printf("\n\n\n\t--------------------VETORES--------------------\n\n\tDigite:\n\n 1) Para ler vetores\n 2) Para somar 2 vetores\n 3) Multiplicar um dos vetores por um escalar\n 4) Realizar o produto escalar entre 2 vetores\n 5) Para voltar a o menu principal\n______________________________________________");/*menu dos vetores*/
                    scanf("%s", &escolhamenuvetoresstr);
                    escolhamenuvetores = atoi(escolhamenuvetoresstr);
                    switch (escolhamenuvetores){//opções vetores
                        case 1:{//opção de ler vetores
                            float k = 0;//variavel de controle casp seja digitado um valor negativo
                            printf("\ndigite o tamanho dos vetores a serem utilizados nas operacoes(caso seja digitado um valor nao inteiro os valores depis da vigula serao desconsiderados\n");
                            scanf("%f", &k);
                            vetor1.tamanhovetor = (int) k;
                            printf("\ntamanho de vetor recebido %d\n", vetor1.tamanhovetor);
                            while (vetor1.tamanhovetor <= 0){//caso digite um valor negativo para o tamanho
                                printf("\n apenas valores maiores que 0 ou nao fracionario\n");
                                scanf("%f", &k);//entrada de dados
                                vetor1.tamanhovetor = (int) k;
                            }
                            vetor1.vetor = (float*) malloc(sizeof(float)*vetor1.tamanhovetor);//alocação de memoria do primeiro vetor
                            vetor2.vetor = (float*) malloc(sizeof(float)*vetor1.tamanhovetor);//alocação de memoria do segundo vetor
                            lervetores(vetor1.vetor, vetor1.tamanhovetor, 1);//função ler vetores
                            printf("\n\n\n");
                            lervetores(vetor2.vetor, vetor1.tamanhovetor, 2);//função ler vetores
                            printf("\n\n\n");
                            ler2 = 10;
                            break;
                            }//fim da opção ler vetores
                        case 2:{//opção de somar vetores
                            if(ler2 == 10){//caso o usuario não entre com um vetor
                                printf("\nvetor resultante\n");
                                float *m = somarvetores(vetor1.tamanhovetor, vetor1.vetor, vetor2.vetor);//função de somar 2 vetores
                                printf("\n\n\n");
                                free(m);
                            }
                                else{
                                    printf("\n-----------\nprimeiro entre com um vetor\n----------\n");
                                }
                                break;
                            }//fim da opção de somar vetores
                        case 3:{//opção de multiplicar um dos vetores por um escalar
                            if(ler2 == 10){//caso o usuario não entre com um vetor
                                float escalar;
                                float* k;
                                k = (float*) malloc(sizeof(float)*vetor1.tamanhovetor);
                                int e;//controle do switch
                                e = 0;
                                printf("\n\tdigite o escalar\n");
                                scanf("%f", &escalar);
                                printf("\n qual vetor deseja utilizar 1 para o vetor 1 e 2 para o vetor 2 \n");
                                scanf("%d", &e);
                                switch(e){
                                    case 1:{//usar vetor 1
                                        k = multiplicarvetorporescalar(escalar, vetor1.tamanhovetor, vetor1.vetor);/*função de multiplicar um vetor por um escalar*/
                                        free(k);
                                        break;
                                    }
                                    case 2:{//usar vetor 2
                                        k = multiplicarvetorporescalar(escalar, vetor1.tamanhovetor, vetor2.vetor);/*função de multiplicar um vetor por um escalar*/
                                        free(k);
                                        break;
                                    }
                                    default:{
                                        printf("\n----------\n digite uma opcao valida\n----------\n");
                                        break;
                                    }
                                }
                                printf("\n\n\n");
                            }
                                else{
                                    printf("\n----------digite um vetor primeiro\n----------\n");
                                }
                                break;
                            }//fim da opção de multiplicar um dos vetores por um escalar
                        case 4:{//opção realizar o produto escalar entre 2 vetores
                            if (ler2 == 10){//caso o usuario não entre com um vetor
                                multiplicaoescalar(vetor1.tamanhovetor, vetor1.vetor, vetor2.vetor);/*função da multiplicação escalar*/
                                printf("\n\n");
                            }
                                else{
                                    printf("\n----------\nentre com um vetor primeiro\n----------\n");
                                }
                            break;
                            }//fim da opção realizar o produto escalar entre 2 vetores
                        case 5:{//para voltar no menu principal
                            if(ler2 == 10){
                                free(vetor1.vetor);
                                free(vetor2.vetor);
                            }
                            voltarmenuprincipal = 0;
                            break;
                            }//fim do case voltar menu pricipal
                        default:{//caso digite uma opção invalida
                            printf("\n----------\ndigite uma opcao valida\n----------\n");
                            break;
                            }//caso digite uma opção que não esteja no menu
                            }//fim do switch do menu de vetores
                            }//fim do while
                            }//fim do case de vetores
            case 2:{//Matrizes
                int escolhamenumatrizes = 10;
                int sairmenumatrizes = 10;
                int ler;
                ler = 0;//caso o usuario não entre com matrizes
                struct matriz matriz1;
                struct matriz matriz2;
                while (voltarmenuprincipal != 0){//menu de matrizes
                    char escolhamenumatrizesstr[256];
                    printf("\n\n\n\t--------------------MATRIZES--------------------\n\n\tDigite:\n\n 1) Para ler matrizes\n 2) Para somar 2 matrizes\n 3) Multiplicar 2 matrizes\n 4) Calcular a transposta de uma matriz\n 5) Calcular o determinante de uma matriz, 1x1,2x2,3x3\n 6) Verificar se uma matriz e simetrica\n 7) Voltar ao menu anterior\n_______________________________________________");/*menu das matrizes*/
                    scanf("%s", &escolhamenumatrizesstr);
                    escolhamenumatrizes = atoi(escolhamenumatrizesstr);
                    float k1 = 0;/*variaveis de controle caso seja digitado um valor negativo ou fracionado no numero de linhas ou colunas*/
                    float k2 = 0;
                    float k3 = 0;
                    float k4 = 0;
                    switch (escolhamenumatrizes){//opções do menu de matrizes
                        case 1:{//opção ler matrizes
                            printf("\n(caso seja digitado um valor nao inteiro os valores depis da vigula serao desconsiderados)\ndigite o numero de linhas da matriz 1\n");
                            scanf("%f", &k1);
                            matriz1.linha = (int) k1;
                            while(matriz1.linha <= 0){//caso digite um valor negativo
                                printf("\n apenas valores maiores que 0 e nao fracionario\n");
                                scanf("%f", &k1);
                                matriz1.linha = (int) k1;
                            }
                            printf("\ndigite o numero de colunas da matriz 1\n");
                            scanf("%f", &k2);
                            matriz1.coluna = (int) k2;
                            while(matriz1.coluna <= 0){//caso digite um valor negativo
                                printf("\n apenas valores maiores que 0 e nao fracionario\n");
                                scanf("%f", &k2);
                                matriz1.coluna = (int) k2;
                                }
                            matriz1.matriz = alocarmatriz(matriz1.linha, matriz1.coluna);
                            lermatrizes(matriz1.matriz, matriz1.linha, matriz1.coluna, 1);
                            exibirmatriz(matriz1.matriz, matriz1.linha, matriz1.coluna);
                            printf("\ndigite o numero de linhas da matriz 2\n");
                            scanf("%f", &k3);
                            matriz2.linha = (int) k3;
                            while(matriz2.linha <= 0){//caso digite um valor negativo
                                printf("\n apenas valores maiores que 0 e não fracionario\n");
                                scanf("%d", &matriz2.linha);
                                matriz2.linha = (int) k3;
                            }
                            printf("digite o numero de colunas da matriz 2 e nao fracionario\n");
                            scanf("%f", &k4);
                            matriz2.coluna = (int) k4;
                            while(matriz2.coluna <= 0){//caso digite um valor negativo
                                printf("\n apenas valores maiores que 0 e nao fracionario\n");
                                scanf("%d", &matriz2.coluna);
                                matriz2.coluna = (int) k4;
                            }
                            matriz2.matriz = alocarmatriz(matriz2.linha, matriz2.coluna);
                            lermatrizes(matriz2.matriz, matriz2.linha, matriz2.coluna, 2);
                            exibirmatriz(matriz2.matriz, matriz2.linha, matriz2.coluna);
                            ler = 10;
                            break;
                            }//fim da opção ler matrizes
                        case 2:{//opção somar 2 matrizes //Aluno:Erick Santos do Nascimento
                            if(ler == 10){//caso o usuario não entre com uma matriz
                                float **soma  = somarmatrizes(matriz1.linha, matriz1.coluna, matriz2.linha, matriz2.coluna, matriz1.matriz, matriz2.matriz);/*recebe 2 matrizes o numero de linhas e colunas das 2 matrizes e retorna uma matriz soma*/
                                if (soma != 0){
                                    exibirmatriz(soma, matriz1.linha, matriz1.coluna);
                                    limaparmatriz(soma, matriz1.linha, matriz1.coluna);
                                }
                            }
                                else{
                                    printf("\n----------\nprimeiro entre com uma matriz\n----------\n");
                                }
                            break;
                            }//fim da opção de somar 2 matrizes
                        case 3:{//opção multiplicar 2 matrizes
                            if(ler == 10){//caso o usuario não entre com uma matriz
                                int m1 = 0;
                                printf("\n\npara multiplicar a matriz 1 pela matriz 2 digite 1 ou a matriz 2 pela matriz 1 digite 2\n");
                                scanf("%d", &m1);
                                switch(m1){
                                    case 1:{
                                        float **multi = multiplicacaodematrizes(matriz1.matriz, matriz1.linha, matriz1.coluna, matriz2.matriz, matriz2.linha, matriz2.coluna);/*recebe 2 matrizes o numero de linhas e colunas da primeira e segunda matriz e retorna uma matriz multiplicação*/
                                        if (multi != 0){
                                            exibirmatriz(multi, matriz1.linha, matriz2.coluna);
                                            limaparmatriz(multi, matriz.linha, matriz2.coluna);
                                        }
                                        break;
                                    }
                                    case 2:{
                                        float **multi2 = multiplicacaodematrizes(matriz2.matriz, matriz2.linha, matriz2.coluna, matriz1.matriz, matriz1.linha, matriz1.coluna);/*recebe 2 matrizes o numero de linhas e colunas da primeira e segunda matriz e retorna uma matriz multiplicação*/
                                        if (multi2 != 0){
                                            exibirmatriz(multi2, matriz2.linha, matriz1.coluna);
                                            limaparmatriz(multi2, matriz2.linha, matriz1.coluna);
                                        }
                                        break;
                                    }
                                    default:{
                                        printf("\n----------\ndigite uma opcao valida 1 ou 2\n----------\n");
                                        break;
                                    }
                                }
                            }
                                else{
                                    printf("\nprimeiro entre com uma matriz");
                                }
                                break;
                            }//fim da opção de multiplicar 2 matrizes
                        case 4:{//opção calcular a transposta de uma matriz
                            if(ler == 10){//caso o usuario não entre com uma matriz
                                int m2 = 0;
                                printf("\npara transposta da matriz 1, 2 para a matriz 2\n");
                                scanf("%d", &m2);
                                switch(m2){
                                    case 1:{
                                        float **trans = transposta(matriz1.matriz, matriz1.linha, matriz1.coluna);/*recebe a matriz o numero de linhas colunas e retorna um float da determinante*/
                                        if (trans != 0){
                                            exibirmatriz(trans, matriz1.coluna, matriz1.linha);
                                            limaparmatriz(trans, matriz1.coluna, matriz1.linha);
                                        }
                                        break;
                                    }
                                    case 2:{
                                        float **trans2 = transposta(matriz2.matriz, matriz2.linha, matriz2.coluna);/*recebe a matriz o numero de linhas colunas e retorna um float da determinante*/
                                        if (trans2 != 0){
                                            exibirmatriz(trans2, matriz2.coluna, matriz2.linha);
                                            limaparmatriz(trans2, matriz2.coluna, matriz2.linha);
                                        }
                                        break;
                                    }
                                    default:{
                                        printf("\n----------\ndigite uma opção valida\n----------\n");
                                        break;
                                    }
                                }
                                }
                                else{
                                    printf("\n----------\nprimeiro entre com uma matriz\n----------\n");
                                }
                            break;
                            }//fim da opção calcular uma transposta de uma matriz
                        case 5:{//opção calcular uma determinante
                            if(ler == 10){//caso o usuario não entre com uma matriz
                                int m12 = 0;
                                printf("\nqual matriz deseja o determinante 1 para primeira 2 para segunda\n");
                                scanf("%d", &m12);
                                switch(m12){
                                    case 1:{
                                        float d = determinante(matriz1.matriz, matriz1.linha, matriz1.coluna);
                                        if (d != 0){
                                            printf("\n O determinante é = %f\n", d);/*recebe a matriz o numero de linhas colunas e retorna um float da determinante*/
                                        }
                                        break;
                                    }
                                    case 2:{
                                        float d2 = determinante(matriz2.matriz, matriz2.linha, matriz2.coluna);
                                        if (d2 != 0){
                                            printf("\n O determinante é = %.2f\n", d2);/*recebe a matriz o numero de linhas colunas e retorna um float da determinante*/
                                        }
                                        break;
                                    }
                                    default:{
                                        printf("\n----------\n digite 1 ou 2\n----------\n");
                                        break;
                                    }
                                }
                            }
                                else{
                                    printf("\n----------\nprimeiro entre com uma matriz\n-----------\n");
                                }
                            break;
                            }//fim da opção calcular uma determinante
                        case 6:{//opção verificar se uma matriz e simetrica
                            if(ler == 10){//caso o usuario não entre com uma matriz
                                int m4 = 0;
                                printf("\nqual matriz deseja a simetrica 1 para primeira 2 para segunda\n");
                                scanf("%d", &m4);
                                switch(m4){
                                    case 1:{
                                        verificarmatrizsimetrica(matriz1.matriz, matriz1.linha, matriz1.coluna);/*recebe a matriz o numero de linhas colunas e retorna um float da determinante*/
                                        break;
                                    }
                                    case 2:{
                                        verificarmatrizsimetrica(matriz2.matriz, matriz2.linha, matriz2.coluna);/*recebe a matriz o numero de linhas colunas e retorna um float da determinante*/
                                        break;
                                    }
                                    default:{
                                        printf("\n digite 1 ou 2\n");
                                        break;
                                    }
                                }
                            }
                                else{
                                    printf("\n----------\nprimeiro entre com uma matriz\n----------\n");
                                }
                            break;
                            }//fim verificar se uma matriz é simetrica
                        case 7:{//opção voltar para o menu principal
                            if(ler == 10){//caso o usuario não entre com uma matriz
                                limaparmatriz(matriz1.matriz, matriz1.linha, matriz1.coluna);
                                limaparmatriz(matriz2.matriz, matriz2.linha, matriz2.coluna);
                            }
                            voltarmenuprincipal = 0;
                            break;
                            }//fim do case voltar menu pricipal
                        default:{//caso digite algo que não esteja no menu de matrizes
                            printf ("\n----------\nse limite as opcoes dadas 1, 2 , 3, 4, 5, 6, ou 7\n----------\n");
                            break;
                            }//fim do default
                        }//fim do switch do menu de matrizes
                   }//fim do while
                break;
            }// fim do case de matrizes
            case 3:{//Opção sair do programa
                sairprograma = 3;
                break;
            }//sair do programa
            default:{//caso se digite algo que não tenha no menu
            printf("\n\n----------\nDIGITE UMA OPCAO VALIDA 1,2 OU 3\n----------\n\n");
            break;
            }
       }//fim do switch do menu principal
       }//fim do while principal
       return 0;
       }// fim de tudo
       //Aluno:Erick Santos do Nascimento
       //UECE Ciencia da Computação
