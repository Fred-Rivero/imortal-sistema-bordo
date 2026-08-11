#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

// Displays the program header
void cabecalho() {
    printf("---------------------------------\n");
    printf("\033[31m  IMORTAL 1 - Sistema de Bordo   \033[0m\n");
    printf("---------------------------------\n\n");
}

// Displays the main menu and available options
void menu() {
    printf("\033[31m         ---- MENU ----          \033[0m\n\n");
    printf("1 - Média\n");
    printf("2 - Máx/Mín\n");
    printf("3 - Desvios\n");
    printf("4 - Verificação de faixa\n");
    printf("5 - Barra gráfica\n");
    printf("6 - Relatório\n");
    printf("0 - Sair\n\n");
}

// Calculates the average of the three input values
double calcular_media(double a, double b, double c) {
    return (a + b + c) / 3;
}

// Returns the smallest value among the three readings
double encontrar_minimo(double a, double b, double c) {
    double min = a;

    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}

// Returns the largest value among the three readings
double encontrar_maximo(double a, double b, double c) {
    double max = a;

    if (b > max) max = b;
    if (c > max) max = c;

    return max;
}

// Checks whether a reading is within the acceptable range
void verificar_faixa(double x, double max_aceito, double min_aceito) {

    printf("%.2lf: ", x);

    if (x < min_aceito)
        printf("\033[31mABAIXO DO LIMITE\033[0m\n");
    else if (x > max_aceito)
        printf("\033[31mACIMA DO LIMITE\033[0m\n");
    else
        printf("\033[32mOK\033[0m\n");
}

// Displays a graphical bar using asterisks to represent the average value
void faixa_grafica(double media) {

    int i;

    printf("Intensidade média: \033[34m%.2lf\033[0m\n{", media);
    fflush(stdout);

    for (i = 0; i < media; i++) {
        printf("\033[32m*\033[0m");
        fflush(stdout);
        usleep(300000);
    }

    printf("}\n\n");
}

int main() {

    // Main control variables
    char test2 = 'y';           // Controls whether a new simulation should be executed
    int opcao = 0;              // Stores the selected menu option

    // Sensor readings and range limits
    double valor1, valor2, valor3, min, max;

    // Main loop: allows multiple simulations with different readings
    while (test2 == 'y' || test2 == 'Y') {

        char test1 = 'y';       // Controls repeated operations within the same simulation

        cabecalho();

        // Collect the three satellite readings
        printf("Digite o valor da primeira leitura: ");
        scanf("%lf", &valor1);

        printf("Digite o valor da segunda leitura: ");
        scanf("%lf", &valor2);

        printf("Digite o valor da terceira leitura: ");
        scanf("%lf", &valor3);

        printf("\n");

        // Secondary loop: allows multiple analyses using the same readings
        while (test1 == 'y' || test1 == 'Y') {

            cabecalho();
            menu();

            // Request a menu option from the user
            printf("Escolha uma opção: ");
            scanf("%d", &opcao);
            printf("\n");

            // Validate the selected option
            while (opcao < 0 || opcao > 6) {
                printf("Opcao invalida.\n\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);
                printf("\n");
            }

            // Calculate the average once and reuse it when needed
            double media = calcular_media(valor1, valor2, valor3);

            // Exit the operations menu
            if (opcao == 0)
                break;

            // Option 1: display the average value
            if (opcao == 1)
                printf("Media dos valores: \033[34m%.2lf\033[0m\n\n", media);

            // Option 2: display maximum and minimum readings
            if (opcao == 2)
                printf("Valor maximo: \033[34m%.2lf\033[0m\nValor minimo: \033[34m%.2lf\033[0m\n\n",
                       encontrar_maximo(valor1, valor2, valor3),
                       encontrar_minimo(valor1, valor2, valor3));

            // Option 3: display the deviation of each reading from the average
            if (opcao == 3)
                printf("Desvio da primeira leitura: \033[34[34m%.2lf\ valor,m%.2lf\033[0m\nDesvio da segunda leitura33[0m\nDesvio da terceira leitura: \033[34m%.2lf\033[0m\n\n",
                       fabs(valor1 - media),
                       fabs(valor2 - media),
                       fabs(valor3 - media));

            // Option 4: validate readings against a user-defined range
            if (opcao == 4) {

                printf("Digite o minimo aceitavel: ");
                scanf("%lf", &min);

                printf("Digite o maximo aceitavel: ");
                scanf("%lf", &max);

                printf("\n");

                // Ensure the maximum limit is greater than the minimum limit
                while (max <= min) {

                    printf("O valor máximo deve ser maior que o mínimo\n\n");

                    printf("Digite o minimo aceitavel: ");
                    scanf("%lf", &min);

                    printf("Digite o maximo aceitavel: ");
                    scanf("%lf", &max);

                    printf("\n");
                }

                // Evaluate each reading individually
                verificar_faixa(valor1, max, min);
                verificar_faixa(valor2, max, min);
                verificar_faixa(valor3, max, min);

                printf("\n");
            }

            // Option 5: display a graphical representation of the average
            if (opcao == 5)
                faixa_grafica(media);

            // Option 6: generate a complete analysis report
            if (opcao == 6) {

                printf("== \033[31mRELATORIO COMLETO\033[0m ==\n\n");

                printf("Media dos valores: \033[34m%.2lf\033[0m\n\n", media);
                printf("--------------------------------------------------\n\n");

                printf("Valor maximo: \033[34m%.2lf\033[0m\nValor minimo: \033[34m%.2lf\033[0m\n\n",
                       encontrar_maximo(valor1, valor2, valor3),
                       encontrar_minimo(valor1, valor2, valor3));

                printf("--------------------------------------------------\n\n");

                printf("Desvio da primeira leitura: \033[34m%.2lf\033[0m\nDesvio da segunda leitura: \033[34m%.2lf\033[0m\nDesvio da terceira leitura: \033[34m%.2lf\033[0m\n\n",
                       (valor1 - media),
                       (valor2 - media),
                       (valor3 - media));

                printf("--------------------------------------------------\n\n");

                // Request range limits if they have not been defined yet
                if (min == 0 || max == 0) {

                    printf("Digite o minimo aceitavel: ");
                    scanf("%lf", &min);

                    printf("Digite o maximo aceitavel: ");
                    scanf("%lf", &max);

                    printf("\n");

                    while (max <= min) {

                        printf("O valor máximo deve ser maior que o mínimo\n\n");

                        printf("Digite o minimo aceitavel: ");
                        scanf("%lf", &min);

                        printf("Digite o maximo aceitavel: ");
                        scanf("%lf", &max);

                        printf("\n");
                    }

                } else {

                    printf("Minimo aceitavel: %.2lf\nMaximo aceitavel: %.2lf\n\n",
                           min, max);
                }

                verificar_faixa(valor1, max, min);
                verificar_faixa(valor2, max, min);
                verificar_faixa(valor3, max, min);

                printf("\n");
                printf("--------------------------------------------------\n\n");

                faixa_grafica(media);

                printf("--------------------------------------------------\n\n");
            }

            // Ask whether another operation should be performed
            printf("Voce deseja realizar outra operacao? [y/n]");
            scanf(" %c", &test1);
            printf("\n");

            // Keep asking until a valid answer is provided
            while (test1 != 'y' && test1 != 'Y' &&
                   test1 != 'n' && test1 != 'N') {

                printf("Opcao invalida.\n\n");

                printf("Voce deseja realizar outra operacao? [y/n]");
                scanf(" %c", &test1);

                printf("\n");
            }
        }

        // Ask whether a new simulation should be started
        printf("Voce deseja realizar outra simulacao? [y/n]");
        scanf(" %c", &test2);
        printf("\n");

        // Keep asking until a valid answer is provided
        while (test2 != 'y' && test2 != 'Y' &&
               test2 != 'n' && test2 != 'N') {

            printf("Opcao invalida.\n\n");

            printf("Voce deseja realizar outra simulacao? [y/n]");
            scanf(" %c", &test2);

            printf("\n");
        }
    }

    printf("Programa encerrado.\n");

    return 0;
}
