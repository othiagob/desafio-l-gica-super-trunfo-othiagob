#include <stdio.h>
#include <string.h>

// Definição da struct Carta
typedef struct {
    char estado[3]; 
    char codigo[3];
    char cidade[30];
    unsigned long int populacao;
    float area;
    float pib;
    int pontoTuristico;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para registrar os dados das cartas
void cadastroCartas(Carta *c, int num) {
    printf("\nDigite os dados da carta %d:\n", num);
    printf("____________________________________\n");

    printf("Digite a sigla do estado (ex: SP, RJ): ");
    scanf("%s", c->estado);

    printf("Digite o código da carta: ");
    scanf("%s", c->codigo);

    getchar(); // Limpa buffer
    printf("Digite o nome da cidade: ");
    fgets(c->cidade, sizeof(c->cidade), stdin);
    c->cidade[strcspn(c->cidade, "\n")] = '\0';

    printf("Digite a quantidade da população: ");
    scanf("%lu", &c->populacao);

    printf("Digite a área em Km²: ");
    scanf("%f", &c->area);

    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &c->pib);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &c->pontoTuristico);

    // Cálculos adicionais
    c->densidadePopulacional = (float)c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1e9) / c->populacao;
}

// Função para exibir o menu de atributos
typedef struct {
    int opcao;
    char nome[30];
} Atributo;

Atributo atributos[] = {
    {1, "População"},
    {2, "Área"},
    {3, "PIB"},
    {4, "Densidade Populacional"},
    {5, "PIB per Capita"}
};

// Função para comparar as cartas com dois atributos
void compararCartas(Carta c1, Carta c2, int atributo1, int atributo2) {
    float valor1_a1, valor2_a1, valor1_a2, valor2_a2;
    int vencedor;
    
    float valores1[] = {(float)c1.populacao, c1.area, c1.pib, c1.densidadePopulacional, c1.pibPerCapita};
    float valores2[] = {(float)c2.populacao, c2.area, c2.pib, c2.densidadePopulacional, c2.pibPerCapita};
    
    valor1_a1 = valores1[atributo1 - 1];
    valor2_a1 = valores2[atributo1 - 1];
    valor1_a2 = valores1[atributo2 - 1];
    valor2_a2 = valores2[atributo2 - 1];
    
    float soma1 = valor1_a1 + valor1_a2;
    float soma2 = valor2_a1 + valor2_a2;
    
    printf("\nComparação de Cartas:\n");
    printf("Atributos escolhidos: %s e %s\n", atributos[atributo1 - 1].nome, atributos[atributo2 - 1].nome);
    printf("\nCarta 1 - %s (%s): %.2f + %.2f = %.2f\n", c1.cidade, c1.estado, valor1_a1, valor1_a2, soma1);
    printf("Carta 2 - %s (%s): %.2f + %.2f = %.2f\n", c2.cidade, c2.estado, valor2_a1, valor2_a2, soma2);
    
    if (soma1 == soma2) {
        printf("\nResultado: Empate!\n");
    } else {
        vencedor = (soma1 > soma2) ? 1 : 2;
        printf("\nResultado: Carta %d (%s) venceu!\n", vencedor, vencedor == 1 ? c1.cidade : c2.cidade);
    }
}

// Função principal
int main() {
    Carta carta1, carta2;
    int atributo1, atributo2;

    cadastroCartas(&carta1, 1);
    cadastroCartas(&carta2, 2);

    // Escolher primeiro atributo
    printf("\nEscolha o primeiro atributo para comparação:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d - %s\n", atributos[i].opcao, atributos[i].nome);
    }
    printf("Digite a opção desejada: ");
    scanf("%d", &atributo1);

    // Escolher segundo atributo, garantindo que seja diferente do primeiro
    do {
        printf("\nEscolha o segundo atributo para comparação:\n");
        for (int i = 0; i < 5; i++) {
            if (atributos[i].opcao != atributo1) {
                printf("%d - %s\n", atributos[i].opcao, atributos[i].nome);
            }
        }
        printf("Digite a opção desejada: ");
        scanf("%d", &atributo2);
    } while (atributo1 == atributo2);

    compararCartas(carta1, carta2, atributo1, atributo2);
    
    return 0;
}
