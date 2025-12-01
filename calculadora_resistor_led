#include <stdio.h>
#include <stdlib.h>

float Vin, Vled, Iled, R = 0.0;

int main(){

    printf(" LED CALCULADORA     v1.0\n");                //Descriçao
    printf(" Autor: Engenheiro Vinicius Lima\n");
    printf(" Empresa: Inizilab\n\n");
    printf("*******************************************\n");
    printf("\n I e a corrente (em amperes, A)\n V e a tensao (em Volts, V)\n R e a resistencia(em Ohms)\n\n");
    printf("*******************************************\n");

    printf("\n\n Digite o valor de Vin (em Volts): ");        //Tensão de Entrada;
    scanf("%f", &Vin);
    printf("\n");

    printf(" Digite o valor de Vled (em Volts): ");         //Tensão do Led
    scanf("%f", &Vled);
    printf("\n");

    printf(" Digite o valor de Iled (em Amperes): ");
    scanf("%f", &Iled);
    printf("\n\n----------------------------------------------\n\n");

    R = (Vin - Vled) / Iled;                                //Calculo da resistencia

    printf(" Vin = %.2f\n\n", Vin);
    printf(" Vled = %.2f\n\n", Vled);
    printf(" Iled = %.2f\n\n", Iled);
    printf(" O resistor para o Led tem o valor (em Ohms) de: %.2f\n", R);
    printf("\n----------------------------------------------\n");

    printf(" Precione qualquer tecla para continuar. . .\n");
    getchar();

    return 0;
}
