#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void gerarSenha(int comprimento, int incluirMaiusculas, int incluirMinusculas, int incluirNumeros, int incluirEspeciais){
    const char caracteresMaiusculos[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char caracteresMinusculos[] = "abcdefghijklmnopqrstuvwyz";
    const char caracteresNumeros[] = "0123456789";
    const char caracteresEspeciais[] = "!@#$%^&*()";

    char caracteresPermitidos[100] = "";

    if (incluirMaiusculas){
        strcat(caracteresPermitidos, caracteresMaiusculos);
    }
    if (incluirMinusculas){
        strcat(caracteresPermitidos, caracteresMinusculos);
    }
    if (incluirNumeros){
        strcat(caracteresPermitidos, caracteresNumeros);
    }
    if (incluirEspeciais){
        strcat(caracteresPermitidos, caracteresEspeciais);
    }
    srand(time(0));

    for(int i = 0; i < comprimento; i++){
        int index = rand() % strlen(caracteresPermitidos);
        printf("%c", caracteresPermitidos[index]);
    }
    printf("\n");
}

int main(){

        int comprimento, incluirMaiusculas, incluirMinusculas, incluirNumeros, incluirEspeciais;

        printf("Gerador de Senhas Aleatorias\n");

        printf("Digite o comprimento da senha: ");
        scanf("%d", &comprimento);

        printf("Deseja incluir letras maiusculas - [1-Sim/0-Nao]: ");
        scanf("%d", &incluirMaiusculas);

        printf("Deseja incluir letras minusculas - [1-Sim/0-Nao]: ");
        scanf("%d", &incluirMinusculas);

        printf("Deseja Numeros - [1-Sim/0-Nao]");
        scanf("%d", incluirNumeros);

        printf("Deseja incluir Caracteres Especiais - [1-Sim/0-Nao]");
        scanf("%d", &incluirEspeciais);

        gerarSenha(comprimento, incluirMaiusculas, incluirMinusculas, incluirNumeros, incluirEspeciais);


    return 0;
}
