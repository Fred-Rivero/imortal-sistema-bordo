#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// procedimento para printar o cabeçalho do programa
void cabecalho() {
    printf("---------------------------------\n");
    printf("  IMORTAL 1 - Sistema de Bordo   \n");
    printf("---------------------------------\n\n");
}

// procedimento para printar o menu com as opções que o usuário pode escolher
void menu() {
    printf("         ---- MENU ----          \n\n");
    printf("1 - Média\n");
    printf("2 - Máx/Mín\n");
    printf("3 - Desvios\n");
    printf("4 - Verificação de faixa\n");
    printf("5 - Barra gráfica\n");
    printf("6 - Relatório\n");
    printf("0 - Sair\n\n");
}

// função para calcular a média dos três valores
double calcular_media(double a, double b, double c) {
    return (a+b+c)/3;
}

// função para achar qual é o menor valor dos três
double encontrar_minimo(double a, double b, double c) {
    double min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

// função para achar qual é o maior valor dos três
double encontrar_maximo(double a, double b, double c) {
    double max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

// função para verificar se um valor tá dentro da faixa que o user especificou
void verificar_faixa(double x, double max_aceito, double min_aceito) {
    printf("%.2lf: ", x);
    if (x<min_aceito) printf("ABAIXO DO LIMITE\n");
    else if (x>max_aceito) printf("ACIMA DO LIMITE\n");
    else printf("OK\n");
}

// função para printar uma barra gráfica de asteriscos pra mostrar a média
void faixa_grafica(double media) {
    int i;
    printf("Intensidade média: %.2lf\n{", media);
    for (i=0;i<media;i++) printf("*");
    printf("}\n\n");

}

int main() {
    // declaro as variáveis necessárias
    char test2='y';   // controla o loop grande (se quer fazer outra simulação)
    int opcao=0;      // armazena qual opção o user escolheu
    double valor1, valor2, valor3, min, max;  // os três valores que o user vai digitar

    // loop principal: permite fazer várias simulações
    while (test2=='y'||test2=='Y') { 

    char test1='y';   // pra controlar o loop pequeno (se quer outra operação)
    cabecalho();      // imprime o título do programa

    // pede os três valores pro user
    printf("Digite o valor da primeira leitura: ");
    scanf("%lf", &valor1);
    printf("Digite o valor da segunda leitura: ");
    scanf("%lf", &valor2);  
    printf("Digite o valor da terceira leitura: ");
    scanf("%lf", &valor3);
    printf("\n");

    // loop menor: deixa o user fazer várias operações com os mesmos valores
    while (test1=='y' || test1=='Y') { 

        cabecalho();
        menu();

        // pede pro user escolher uma opção
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n");
        
        // se o user digitou algo fora de 0-6, pede pra digitar de novo
        while (opcao < 0 || opcao > 6) {
            printf("Opcao invalida.\n\n");
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);
            printf("\n");
        }
        
        // calcula a média que vai usar em vários lugares
        double media = calcular_media(valor1, valor2, valor3);

        // agora processa qual opção o user escolheu
    
        // se escolheu 0, sai do loop
        if (opcao == 0) break;
        
        // opção 1: mostra a média
        if (opcao == 1) printf("Media dos valores: %.2lf\n\n", media);
        
        // opção 2: mostra o maior e menor valor
        if (opcao == 2) printf("Valor maximo: %.2lf\nValor minimo: %.2lf\n\n", encontrar_maximo(valor1, valor2, valor3), encontrar_minimo(valor1, valor2, valor3));
        
        // opção 3: mostra quanto cada valor desvia da média
        if (opcao == 3) printf("Desvio da primeira leitura: %.2lf\nDesvio da segunda leitura: %.2lf\nDesvio da terceira leitura: %.2lf\n\n", fabs(valor1-media), fabs(valor2-media), fabs(valor3-media));
        
        // opção 4: pede a faixa aceitável e diz se os valores tão ok
        if (opcao == 4) {
            printf("Digite o minimo aceitavel: ");
            scanf("%lf", &min);
            printf("Digite o maximo aceitavel: ");
            scanf("%lf", &max);
            printf("\n");
            while(max<=min) {
                printf("O valor máximo deve ser maior que o mínimo\n\n");
                printf("Digite o minimo aceitavel: ");
                scanf("%lf", &min);
                printf("Digite o maximo aceitavel: ");
                scanf("%lf", &max);
                printf("\n");
            }
            // verifica cada um dos três valores
            verificar_faixa(valor1, max, min);
            verificar_faixa(valor2, max, min);
            verificar_faixa(valor3, max, min);
            printf("\n");
        } 
        
        // opção 5: mostra uma barra gráfica da média
        if (opcao == 5) faixa_grafica(media);
        
        // opção 6: mostra tudo junto num relatório completo
        if (opcao == 6) {
            printf("== RELATORIO COMLETO ==\n\n");
            
            printf("Media dos valores: %.2lf\n\n", media);
            printf("--------------------------------------------------\n\n");
            
            printf("Valor maximo: %.2lf\nValor minimo: %.2lf\n\n", encontrar_maximo(valor1, valor2, valor3), encontrar_minimo(valor1, valor2, valor3));
            printf("--------------------------------------------------\n\n");

            printf("Desvio da primeira leitura: %.2lf\nDesvio da segunda leitura: %.2lf\nDesvio da terceira leitura: %.2lf\n\n", (valor1-media), (valor2-media), (valor3-media));
            printf("--------------------------------------------------\n\n");

            if (min==0 || max==0) {
                printf("Digite o minimo aceitavel: ");
                scanf("%lf", &min);
                printf("Digite o maximo aceitavel: ");
                scanf("%lf", &max);
                printf("\n");
                while(max<=min) {
                    printf("O valor máximo deve ser maior que o mínimo\n\n");
                    printf("Digite o minimo aceitavel: ");
                    scanf("%lf", &min);
                    printf("Digite o maximo aceitavel: ");
                    scanf("%lf", &max);
                    printf("\n");
                }
            } else {
                printf("Minimo aceitavel: %.2lf\nMaximo aceitavel: %.2lf\n\n", min, max);
            }
            verificar_faixa(valor1, max, min);
            verificar_faixa(valor2, max, min);
            verificar_faixa(valor3, max, min);
            printf("\n");
            printf("--------------------------------------------------\n\n");
            
            faixa_grafica(media); 
            printf("--------------------------------------------------\n\n");
        }

        // pergunta se quer fazer outra operação
        printf("Voce deseja realizar outra operacao? [y/n]");
        scanf(" %c", &test1);
        printf("\n");
        
        // se não for y ou n, repete a pergunta
        while (test1!='y' && test1!='Y' && test1!='N' && test1!='n') {
            printf("Opcao invalida.\n\n");
            printf("Voce deseja realizar outra operacao? [y/n]");
            scanf(" %c", &test1);
            printf("\n");
        }
    }
    
    // pergunta se quer fazer outra simulação com novos valores
    printf("Voce deseja realizar outra simulacao? [y/n]");
    scanf(" %c", &test2);
    printf("\n");
    
    // se não for y ou n, repete a pergunta
    while (test2!='y' && test2!='Y' && test2!='N' && test2!='n') {
        printf("Opcao invalida.\n\n");
        printf("Voce deseja realizar outra simulacao? [y/n]");
        scanf(" %c", &test2);
        printf("\n");
    }
    }

    printf("Programa encerrado.\n");

    return 0;
}
