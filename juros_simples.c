#include <stdio.h> //importando a biblioteca stdio.h

float convert_taxa(float taxa_entrada, char medida_entrada, char medida_saida){
//função para fazer a conversão de taxa em uma medida para outras medidas, da maior para menor como de ano para mês ou da menor para maior como de dia para ano  
//taxa_entrada: taxa a ser convertida
//medida_entrada: medida da taxa de entrada como a (ano), m (mês) e d (dia)
//medida_saida: medida da taxa de saída como a (ano), m (mês) e d (dia)
     
      float taxa_diaria, taxa_saida;
//taxa_diaria: toda taxa de entrada é convertida para a taxa em dia para depois ser convertida para taxa na medida de saída
//taxa_saida: variável que guarda a taxa convertida a ser retornada pela função
      
      switch(medida_entrada){
            
            case 'a':
                  taxa_diaria = taxa_entrada/360;//convertendo de ano para dia
            break;
            case 'm':
                  taxa_diaria = taxa_entrada/30;//convertendo de mês para dia
            break;
            case 'd':
                  taxa_diaria = taxa_entrada/1;//convertendo de dia para dia
            break;
      }
      
      switch(medida_saida){
            
            case 'a':
                  taxa_saida = taxa_diaria * 360;//convertendo de dia para ano
            break;
            case 'm':
                  taxa_saida = taxa_diaria * 30;//convertendo de dia para mês
            break;
            case 'd':
                  taxa_saida = taxa_diaria * 1;//convertendo de dia para dia
            break;
      }
      
      return taxa_saida;//retornando a taxa convertida
}

int main(){ //função principal
    float c, i, t, m, j, convert; //declarando as variáveis c para capital, i para taxa, t para período, m para montante, j para juros e convert para a taxa convertida
    int op; //variável op para opção que decide a opção a ser escolhida
    char medida_entrada, medida_saida;//declarando variáveis medida_entrada para a medida da taxa de entrada e medida_saida para a medida da taxa de saída

    //Menu de opções
    printf("Juro Simples Menu");
    printf("\n1 - Juros e Montante");
    printf("\n2 - Capital e Montante");
    printf("\n3 - Taxa e Montante");
    printf("\n4 - Período e Montante");
    printf("\n5 - Converter taxa");
    printf("\nOpcao: ");
    scanf("%i", &op); //ler o número da opção

    switch(op){ //executa a opção escolhida

        case 1: //Montante e Juros
            printf("Insira o capital: ");
            scanf("%f", &c); //lendo o capital
            printf("Insira a taxa: ");
            scanf("%f", &i); //lendo a taxa
            getchar();//limpa buffer do teclado
            printf("\na - ao ano\nm - ao mes\nd - ao dia\nOpcao: ");
            scanf("%c", &medida_entrada);//lendo medida da taxa d entrada
            printf("Insira o período: ");
            scanf("%f", &t); //lendo o período
            getchar();//limpa buffer do teclado
            printf("\na - ao ano\nm - ao mes\nd - ao dia\nOpcao: ");
            scanf("%c", &medida_saida);//lendo medida da taxa de saída
            
            i = convert_taxa(i, medida_entrada, medida_saida);//convertendo a taxa

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
            getchar();//limpa buffer do teclado
            printf("\na - ao ano\nm - ao mes\nd - ao dia\nOpcao: ");
            scanf("%c", &medida_entrada);//lendo medida da taxa de entrada
            printf("Insira o período: ");
            scanf("%f", &t); //lendo o período
            getchar();//limpa buffer do teclado
            printf("\na - ao ano\nm - ao mes\nd - ao dia\nOpcao: ");
            scanf("%c", &medida_saida);//lendo medida da taxa de saída
            
            i = convert_taxa(i, medida_entrada, medida_saida);//convertendo a taxa

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

            printf("Taxa = %.2f %%", i); //exibindo a taxa
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
        case 5: //converter taxa
        
            printf("Insira a taxa: ");
            scanf("%f", &i); //lendo a taxa
            getchar();//limpa buffer do teclado
            printf("\na - ao ano\nm - ao mes\nd - ao dia\nOpcao: ");
            scanf("%c", &medida_entrada);//lendo medida de entrada da taxa
            printf("Insira o período: ");
            scanf("%f", &t); //lendo o período
            getchar();//limpa buffer do teclado
            printf("\na - ao ano\nm - ao mes\nd - ao dia\nOpcao: ");
            scanf("%c", &medida_saida);//lendo medida da taxa de saída
            
            convert = t * convert_taxa(i, medida_entrada, medida_saida);//convertendo taxa
            
            printf("\n%.2f %% a.%c = %.2f %% em %.2f %c", i, medida_entrada, convert, t, medida_saida);//exibindo resultado 
        
        break;


    }
    return 0;
}
