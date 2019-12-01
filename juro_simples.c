#include <stdio.h> //importando a biblioteca stdio.h

int main(){ //função principal
    float c, i, t, m, j; //declarando as variáveis c para capital, i para taxa, t para período, m para montante e j para juros
    int op; //variável op para opção que decide a opção a ser escolhida

    //Menu de opções
    printf("Juro Simples Menu");
    printf("\n1 - Juros e Montante");
    printf("\n2 - Capital e Montante");
    printf("\n3 - Taxa e Montante");
    printf("\n4 - Período e Montante");
    printf("\nOpcao: ");
    scanf("%i", &op); //ler o número da opção

    switch(op){ //executa a opção escolhida

        case 1: //Montante e Juros
            printf("Insira o capital: ");
            scanf("%f", &c); //lendo o capital
            printf("Insira a taxa: ");
            scanf("%f", &i); //lendo a taxa
            printf("Insira o período: ");
            scanf("%f", &t); //lendo o período

            m = c * (1 + (i/100) * t); //calculando o montante
            j = m - c; //calculando os juros

            printf("Juros = R$ %.2f", j); //exibindo os juros
            printf("\nMontante = R$ %.2f", m); //exibindo o montante

        break;

         case 2: //Capital
            printf("Insira os juros: ");
            scanf("%f", &j); //lendo os juros
            printf("Insira a taxa: ");
            scanf("%f", &i); //lendo a taxa
            printf("Insira o período: ");
            scanf("%f", &t); //lendo o período

            c = j/((i * t)/100); //calculando o capital
            m = c + j; //calculando o montante
            

            printf("Capital = R$ %.2f", c); //exibindo o capital
            printf("\nMontante = R$ %.2f", m); //exibindo o montante
            

        break;

        case 3: //taxa
             printf("Insira o capital: ");
            scanf("%f", &c); //lendo o capital
            printf("Insira o período: ");
            scanf("%f", &t); //lendo o período
            printf("Insira os juros: ");
            scanf("%f", &j); //lendo os juros

            m = c + j; //calculando o montante
            i = (j/(c * t)) * 100; //calculando a taxa

            printf("Taxa = %.2f porcento", i); //exibindo a taxa
            printf("\nMontante = R$ %.2f", m); //exibindo o montante

        break;

        case 4: //período
            printf("Insira o capital: ");
            scanf("%f", &c); //lendo o capital
            printf("Insira a taxa: ");
            scanf("%f", &i); //lendo a taxa
            printf("Insira os juros: ");
            scanf("%f", &j); //lendo os juros

            m = c + j; //calculando o montante
            t = j/(c * (i/100)); //calculando o período

            printf("Período = %.2f ", t); //exibindo o período
            printf("\nMontante = R$ %.2f", m); //exibindo o montante

        break;


    }
    return 0;
}
