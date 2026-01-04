#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

//Quantidade de filmes
#define qtd_filmes 5

//Cores
#define ANSI_COLOR_RED_BG     "\x1b[41m"
#define ANSI_COLOR_GREEN_BG   "\x1b[42m"
#define ANSI_COLOR_YELLOW_BG  "\x1b[43m"
#define ANSI_COLOR_BLUE_BG    "\x1b[44m"
#define ANSI_COLOR_WHITE_BG   "\x1b[47m"
#define ANSI_COLOR_RESET      "\x1b[0m"


int main(){

    SetConsoleOutputCP(65001);
    int ingressos[qtd_filmes], i, total=0, mais_vendido = 0, menos_vendido = 0;

    //filmes
    char filmes[qtd_filmes][30] = {
        "Deadpool e Wolverine",
        "Furiosa - Uma saga Mad Max",
        "Duna - Parte 2",
        "Gladiador 2",
        "Coringa - Loucura a Dois"
    };

    //cores
    const char *cores_bg[qtd_filmes] = {
        ANSI_COLOR_BLUE_BG,
        ANSI_COLOR_GREEN_BG,
        ANSI_COLOR_RED_BG,
        ANSI_COLOR_YELLOW_BG,
        ANSI_COLOR_WHITE_BG

    };

    //Escopo
    printf("\n\n\t\t\t\tCINE HOLLYWOOD\n\n");
    printf("\t\t\t------------------------------");
    printf("\n\t\t\t  Venda de Ingressos em 2024\n");
    printf("\t\t\t------------------------------\n\n");


    //Definiçao da quantidade de ingressos e soma do total
    printf("\nInforme a quantidade de ingressos vendidos para cada filme.\n");
    for(i = 0; i < qtd_filmes; i++){
        printf("\n* %-30s: ", filmes[i]);
        scanf("%d", &ingressos[i]);
        total += ingressos[i];
    }

    //calculo de quais foram os ingressos mais vendidos e menos vendidos
    for(i = 1; i < qtd_filmes; i++){
        if (ingressos[i] > ingressos[mais_vendido]){
            mais_vendido = i;
        }
        if (ingressos[i] < ingressos[menos_vendido]){
            menos_vendido = i;
        }
    }


    //Relatorio de vendas mensais
    printf("\n\n*******************************************************************************\n");
    printf("\n\t\t\t\tRelatorio Mensal\n\n");
    printf("\n* Total de ingressos vendidos no mes:    %d unidades\n", total);
    printf("\n* Filmes mais assistidos no mes:         %s (%d ingressos)\n", filmes[mais_vendido], ingressos[mais_vendido]);
    printf("\n* Filmes menos assistidos no mes:        %s (%d ingressos)\n", filmes[menos_vendido], ingressos[menos_vendido]);
    printf("\n********************************************************************************\n");


    //Definicao do grafico de vendas
    printf("\n\t\t\t   Grafico de Vendas Mensais\n\n");
    for(i = 0; i < qtd_filmes; i++){
        //Definicao do formato do filmes
        printf("* %-35s |", filmes[i]);

        //definicao das cores no grafico
        printf("%s", cores_bg[i]);
        for(int j = 0; j < ingressos[i] / 15; j++){
            printf(" ");
        }

        //definicao da cor em negrito
        printf("%s", ANSI_COLOR_RESET);
        printf("(%d)\n", ingressos[i]);
    }
    printf("\n********************************************************************************\n");
    printf("\n\nFinalizando o programa...\n\n");
    getchar();

    return 0;
}
