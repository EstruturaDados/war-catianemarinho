#include <stdio.h>
#include <string.h>

#define LIM_TERRITORIOS 5
#define TAM_NOME 30
#define TAM_COR 10

/* Estrutura que representa um território no jogo */
typedef struct {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
} Territorio;

/* Função auxiliar: remove newline ao final da string lida */
static void limparFimLinha(char *texto) {
    size_t t = strlen(texto);
    if (t > 0 && texto[t - 1] == '\n') {
        texto[t - 1] = '\0';
    }
}

/* Responsável por coletar os dados dos territórios */
void preencherMapa(Territorio vetor[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\n--- Registro do território %d ---\n", i + 1);

        printf("Nome: ");
        fgets(vetor[i].nome, TAM_NOME, stdin);
        limparFimLinha(vetor[i].nome);

        if (strlen(vetor[i].nome) == 0) {
            printf("Nome não informado. Definindo padrão...\n");
            snprintf(vetor[i].nome, TAM_NOME, "Area_%d", i + 1);
        }

        printf("Cor do exército: ");
        fgets(vetor[i].cor, TAM_COR, stdin);
        limparFimLinha(vetor[i].cor);

        if (strlen(vetor[i].cor) == 0) {
            strcpy(vetor[i].cor, "neutro");
        }

        printf("Tropas: ");
        while (scanf("%d", &vetor[i].tropas) != 1) {
            printf("Valor inválido. Digite um número: ");
            int lixo;
            while ((lixo = getchar()) != '\n' && lixo != EOF);
        }

        int lixo;
        while ((lixo = getchar()) != '\n' && lixo != EOF);
    }
}

/* Apenas apresenta os territórios preenchidos */
void mostrarMapa(const Territorio vetor[], int qtd) {
    printf("\n===== MAPA FINAL =====\n");

    for (int i = 0; i < qtd; i++) {
        printf("[%d] %s | Cor: %s | Tropas: %d\n",
               i + 1,
               vetor[i].nome,
               vetor[i].cor,
               vetor[i].tropas);
    }
}

int main(void) {
    Territorio mundo[LIM_TERRITORIOS];

    printf("Sistema Inicial - Cadastro do Mapa de Jogo\n");
    printf("Quantidade de áreas a cadastrar: %d\n", LIM_TERRITORIOS);

    preencherMapa(mundo, LIM_TERRITORIOS);
    mostrarMapa(mundo, LIM_TERRITORIOS);

    return 0;
}
