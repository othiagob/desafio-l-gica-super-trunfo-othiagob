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

// Função para comparar e exibir os resultados
void compararCartas(Carta c1, Carta c2, int atributoEscolhido) {
    printf("\nComparação de Cartas:\n");
    char *atributoNome;
    float valor1, valor2;
    int vencedor;

    switch (atributoEscolhido) {
        case 1:
            atributoNome = "População";
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            break;
        case 2:
            atributoNome = "Área";
            valor1 = c1.area;
            valor2 = c2.area;
            break;
        case 3:
            atributoNome = "PIB";
            valor1 = c1.pib;
            valor2 = c2.pib;
            break;
        case 4:
            atributoNome = "Densidade Populacional";
            valor1 = c1.densidadePopulacional;
            valor2 = c2.densidadePopulacional;
            break;
        case 5:
            atributoNome = "PIB per Capita";
            valor1 = c1.pibPerCapita;
            valor2 = c2.pibPerCapita;
            break;
        default:
            printf("Erro: Atributo inválido\n");
            return;
    }

    if (valor1 == valor2) {
        printf("Comparação de cartas (Atributo: %s):\n\n", atributoNome);
        printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, valor1);
        printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, valor2);
        printf("\nResultado: Empate!\n");
    } else {
        if (atributoEscolhido == 4) {
            vencedor = (valor1 < valor2) ? 1 : 2;
        } else {
            vencedor = (valor1 > valor2) ? 1 : 2;
        }

        printf("Comparação de cartas (Atributo: %s):\n\n", atributoNome);
        printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, valor1);
        printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, valor2);
        printf("\nResultado: Carta %d (%s) venceu!\n", vencedor, vencedor == 1 ? c1.cidade : c2.cidade);
    }
}

// Função principal
int main() {
    Carta carta1, carta2;
    int atributoEscolhido;

    cadastroCartas(&carta1, 1);
    cadastroCartas(&carta2, 2);

    // Exibir menu interativo para o usuário escolher o atributo de comparação
    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per Capita\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &atributoEscolhido);

    compararCartas(carta1, carta2, atributoEscolhido);
    
    return 0;
}
