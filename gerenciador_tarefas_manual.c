#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>


int main(){

    int opcao;
    char nome_processo[30], comando[70], raiz[50], nome_arquivo[30], simbolo[3];

    system("title Gerenciador de Tarefas Manual versao 1.0");

    printf("\n--------------------------------------------\n");
    printf("\tGerenciador de Tarefas Manual");
    printf("\n--------------------------------------------\n");

    printf("\n\t\tMENU ");
    printf("\n\n*   *   *   *   *   *   *   *   *   *\n");

    printf("\nSelecione sua opcao: \n");
    printf("Digite 1 - Abrir a Lista de Processos:\n");
    printf("Digite 2 - Fechar um Processo em Aberto:\n");
    printf("Digite 3 -Abrir um Novo Processo:\n");
    printf("Digite 4 - Sair:\nTecla:");
    scanf("%d", &opcao);


    switch(opcao){
        case 1:
            //system("cls");
            system("tasklist");
            getchar();
            break;

        case 2:
            strcpy(comando, "taskkill /IM ");
            printf("\nDigite o nome do processo completo a ser fechado - [exemplo: teste.exe]: ");
            scanf("%s", nome_processo);
            strcat(comando, nome_processo);
            system(comando);
            getchar();
            break;

        case 3:
            strcpy(comando, "start ");
            printf("\nDigite a raiz do arquivo ou programa que deseja abrir - [exemplo: C/Users/vi/OneDrive/Documentos/dumps/ ]: ");
            scanf("%s", &raiz);
            strcpy(simbolo, "\\");          //barra para colocar na frente da raiz
            printf("Digite o nome do arquivo ou programa que deseja abrir - [exemplo: teste.txt]: ");
            scanf("%s", nome_arquivo);

            strcat(comando, raiz);
            strcat(comando, simbolo);
            strcat(comando, nome_arquivo);
            system(comando);
            printf("Abrindo arquivo. . . ");
            break;
        case 4:
            printf("\nFechando o programa...\n");
            system("exit");
        default:
            getchar();
            break;
    }while (opcao >= 5);
    getchar();

    return 0;
}