#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int registro;
    char tipo[50];
    char modelo[50];
    char fabricante[50];
    float valorDiario;
    int diasAlugados;
    float valorTotal;
} Maquina;

void preencherVetor(Maquina *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o registro da maquina %d: ", i + 1);
        scanf("%d", &vetor[i].registro);
        printf("Digite o tipo da maquina %d: ", i + 1);
        scanf("%s", vetor[i].tipo);
        printf("Digite o modelo da maquina %d: ", i + 1);
        scanf("%s", vetor[i].modelo);
        printf("Digite o fabricante da maquina %d: ", i + 1);
        scanf("%s", vetor[i].fabricante);
        printf("Digite o valor cobrado por dia de aluguel da maquina %d: ", i + 1);
        scanf("%f", &vetor[i].valorDiario);
        printf("Digite o numero de dias de aluguel da maquina %d: ", i + 1);
        scanf("%d", &vetor[i].diasAlugados);

        vetor[i].valorTotal = vetor[i].valorDiario * vetor[i].diasAlugados;
        printf("Valor total do aluguel: %.2f\n", vetor[i].valorTotal);
    }
}

int exibirMaquinasTipo(Maquina *vetor, int tamanho, char tipo[]) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(vetor[i].tipo, tipo) == 0 || strcmp(tipo, "") == 0) {
            printf("Registro: %d\n", vetor[i].registro);
            printf("Tipo: %s\n", vetor[i].tipo);
            printf("Modelo: %s\n", vetor[i].modelo);
            printf("Fabricante: %s\n", vetor[i].fabricante);
            printf("Valor diario: %.2f\n", vetor[i].valorDiario);
            printf("Dias alugados: %d\n", vetor[i].diasAlugados);
            printf("Valor total do aluguel: %.2f\n", vetor[i].valorTotal);
            contador++;
        }
    }
    return contador;
}

int buscarMaquina(Maquina *vetor, int tamanho, int registro) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i].registro == registro) {
            return i;
        }
    }
    return -1;
}

void submenuOperacoes(Maquina *maquinas, int numMaquinas) {
    int opcaoSubmenu;
    int registro;
    char tipo[50];

    do {
        printf("\n[1] Listar maquinas por tipo\n");
        printf("[2] Buscar maquina pelo registro\n");
        printf("[3] Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoSubmenu);

        switch (opcaoSubmenu) {
            case 1:
                printf("Digite o tipo de maquina (ou deixe em branco para todas): ");
                scanf("%s", tipo);
                int numMaquinasTipo = exibirMaquinasTipo(maquinas, numMaquinas, tipo);
                printf("Numero de maquinas encontradas: %d\n", numMaquinasTipo);
                break;
            case 2:
                printf("Digite o registro da maquina: ");
                scanf("%d", &registro);
                int indice = buscarMaquina(maquinas, numMaquinas, registro);
                if (indice != -1) {
                    printf("Registro: %d\n", maquinas[indice].registro);
                    printf("Tipo: %s\n", maquinas[indice].tipo);
                    printf("Modelo: %s\n", maquinas[indice].modelo);
                    printf("Fabricante: %s\n", maquinas[indice].fabricante);
                    printf("Valor diario: %.2f\n", maquinas[indice].valorDiario);
                    printf("Dias alugados: %d\n", maquinas[indice].diasAlugados);
                    printf("Valor total do aluguel: %.2f\n", maquinas[indice].valorTotal);
                } else {
                    printf("Maquina nao encontrada.\n");
                }
                break;
            case 3:
                printf("Retornando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcaoSubmenu != 3);
}

int main() {
    int opcao = 0, numMaquinas = 0;
    Maquina *maquinas = NULL;

    printf("Informe o numero de maquinas: ");
    scanf("%d", &numMaquinas);
    maquinas = realloc(maquinas, numMaquinas * sizeof(Maquina));
    if (!maquinas) {
        printf("Erro ao alocar memoria.\n");
        exit(EXIT_FAILURE);
    }

    do {
        printf("\n[1] Alterar a quantidade de maquinas.\n");
        printf("[2] Entrar com os dados de cada maquina.\n");
        printf("[3] Realizar operacoes com maquinas.\n");
        printf("[4] Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o novo numero de maquinas: ");
                scanf("%d", &numMaquinas);
                maquinas = realloc(maquinas, numMaquinas * sizeof(Maquina));
                if (!maquinas) {
                    printf("Erro ao alocar memoria.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case 2:
                if (numMaquinas <= 0) {
                    printf("Primeiro insira a quantidade de maquinas.\n");
                } else {
                    preencherVetor(maquinas, numMaquinas);
                }
                break;
            case 3:
                if (numMaquinas <= 0) {
                    printf("Primeiro insira os dados das maquinas.\n");
                } else {
                    submenuOperacoes(maquinas, numMaquinas);
                }
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 4);

    free(maquinas);
    return 0;
}
