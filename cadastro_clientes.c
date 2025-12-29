#include <stdlib.h>
#include <stdio.h>
#include <string.h>

 struct Cliente{
        char nome[30];
        char email[30]
    };

int main(){

    struct Cliente clientes[30];
    int opcao, numClientes = 0;

    do{
        printf("Selecione uma opcao:\n");
        printf("1 - Adicionar Cliente\n");
        printf("2 - Visualizar Cliente\n");
        printf("3 - Editar Cliente\n");
        printf("4 - Excluir Cliente\n");
        printf("5 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:{
                printf("Digite o nome do Cliente: ");
                scanf("%s", &clientes[numClientes].nome);

                printf("Digite o email do Cliente: ");
                scanf("%s", &clientes[numClientes].email);

                numClientes++;

                printf("Cliente adicionado com sucesso.\n");
                break;
            }
            case 2:{
                printf("Clientes cadastrados:\n");

                for (int i=0; i < numClientes; i++){
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Email:%s\n", clientes[i].email);
                    printf("---------------------\n");
                }
                break;
            }
            case 3:{
                char nome[30];
                printf("Digite o nome do cliete que deseja editar: ");
                scanf("%s", nome);

                for (int i = 0; i < numClientes; i++){
                    if (strcmp(clientes[i].nome, nome) == 0){
                        printf("Digite o novo nome do cliente: ");
                        scanf("%s", clientes[i].nome);

                        printf("Digite o novo email do cliente: ");
                        scanf("%s", clientes[i].email);

                        printf("Cliente editado com sucesso.\n");
                    }
                }
                break;
            }
            case 4:{
                char nome[30];

                printf("Digite o nome do cliente que deseja excluir: ");
                scanf("%s", nome);

                for(int i = 0; i < numClientes; i++){
                    if (strcmp(clientes[i].nome, nome) == 0){
                        for (int j = i; j < numClientes - 1; j++){
                            clientes[j] = clientes[j + 1];
                        }
                        numClientes--;

                        printf("Cliente excluido com sucesso.\n");
                        break;
                    }
                }
                break;
            }
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }   while(opcao != 5);


    return 0;

}