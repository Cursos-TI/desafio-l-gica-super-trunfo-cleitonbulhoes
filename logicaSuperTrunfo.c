#include <stdio.h>

typedef struct {
    char estado;               // Letra de A a H
    char codigo[4];            // Código da carta ex: "A01"
    char nomeCidade[50];       // Nome da cidade
    int populacao;             // População
    float area;                // Área em km²
    float pib;                 // PIB em bilhões de reais
    int pontosTuristicos;      // Pontos turísticos
} Carta;

// Enumeração para os atributos de comparação
typedef enum {
    POPULACAO,
    AREA,
    PIB,
    DENSIDADE_POPULACIONAL,
    PIB_PER_CAPITA
} AtributoComparacao;

// Função para calcular densidade populacional
float calcularDensidadePopulacional(Carta carta) {
    if (carta.area == 0) return 0; // evitar divisão por zero
    return (float)carta.populacao / carta.area;
}

// Função para calcular PIB per capita
float calcularPibPerCapita(Carta carta) {
    if (carta.populacao == 0) return 0; // evitar divisão por zero
    return carta.pib * 1e9 / carta.populacao; // PIB em bilhões convertido para reais
}

// Função para imprimir uma carta
void mostrarCarta(Carta carta, int numeroCarta) {
    printf("=== Carta %d ===\n", numeroCarta);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n\n", carta.pontosTuristicos);
}

int main() {
    // Escolha do atributo para comparação (alterar aqui para mudar o critério)
    const AtributoComparacao ATRIBUTO_COMPARACAO = PIB; 

    // Duas cartas pré-definidas (pode modificar os valores conforme desejar)
    Carta carta1 = {'A', "A01", "São Paulo", 12325000, 1521.11f, 699.28f, 50};
    Carta carta2 = {'B', "B02", "Rio de Janeiro", 6748000, 1200.25f, 300.50f, 30};

    // Mostrar cartas
    mostrarCarta(carta1, 1);
    mostrarCarta(carta2, 2);

    // Variáveis para armazenar os valores usados na comparação
    float valorCarta1 = 0, valorCarta2 = 0;
    char nomeAtributo[30];

    // Definir valores a comparar e nome do atributo conforme escolha
    switch (ATRIBUTO_COMPARACAO) {
        case POPULACAO:
            valorCarta1 = carta1.populacao;
            valorCarta2 = carta2.populacao;
            sprintf(nomeAtributo, "População");
            break;
        case AREA:
            valorCarta1 = carta1.area;
            valorCarta2 = carta2.area;
            sprintf(nomeAtributo, "Área");
            break;
        case PIB:
            valorCarta1 = carta1.pib;
            valorCarta2 = carta2.pib;
            sprintf(nomeAtributo, "PIB");
            break;
        case DENSIDADE_POPULACIONAL:
            valorCarta1 = calcularDensidadePopulacional(carta1);
            valorCarta2 = calcularDensidadePopulacional(carta2);
            sprintf(nomeAtributo, "Densidade Populacional");
            break;
        case PIB_PER_CAPITA:
            valorCarta1 = calcularPibPerCapita(carta1);
            valorCarta2 = calcularPibPerCapita(carta2);
            sprintf(nomeAtributo, "PIB per capita");
            break;
    }

    // Exibir valores usados na comparação
    printf("Comparação de cartas (Atributo: %s):\n\n", nomeAtributo);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.codigo, valorCarta1);
    printf("Carta 2 - %s (%s): %.2f\n\n", carta2.nomeCidade, carta2.codigo, valorCarta2);

    // Comparar e determinar vencedor
    if (ATRIBUTO_COMPARACAO == DENSIDADE_POPULACIONAL) {
        // Menor valor vence
        if (valorCarta1 < valorCarta2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valorCarta2 < valorCarta1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        // Maior valor vence
        if (valorCarta1 > valorCarta2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valorCarta2 > valorCarta1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    return 0;
}
