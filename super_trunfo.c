#include <stdio.h>

// Defina quais níveis ativar (descomente para ativar um nível)
//#define NIVEL_NOVATO
//#define NIVEL_AVENTUREIRO
#define NIVEL_MESTRE // <- Ativar todos os níveis

typedef struct {
    char codigo[4]; // Ex: "A01"
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional; // Calculado no nível aventureiro
    float pib_per_capita; // Calculado no nível aventureiro
    float super_poder; // Calculado no nível mestre
} Carta;

void cadastrarCarta(Carta *carta) {
    printf("Digite o código da cidade (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

void exibirCarta(const Carta *carta) {
    printf("\n----------------------------\n");
    printf("Código: %s\n", carta->codigo);
    printf("População: %lu\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões\n", carta->pib);
    printf("Pontos turísticos: %d\n", carta->pontos_turisticos);
    
#ifdef NIVEL_AVENTUREIRO
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidade_populacional);
    printf("PIB per capita: %.2f\n", carta->pib_per_capita);
#endif

#ifdef NIVEL_MESTRE
    printf("Super Poder: %.5f\n", carta->super_poder);
#endif

    printf("----------------------------\n");
}

#ifdef NIVEL_AVENTUREIRO
void calcularAtributos(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade_populacional = carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }

    if (carta->populacao > 0) {
        carta->pib_per_capita = carta->pib / carta->populacao;
    } else {
        carta->pib_per_capita = 0;
    }
}
#endif

#ifdef NIVEL_MESTRE
void calcularSuperPoder(Carta *carta) {
    float inverso_densidade = carta->densidade_populacional > 0 ? 1.0 / carta->densidade_populacional : 0;
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pontos_turisticos + inverso_densidade;
}

void compararCartas(Carta *carta1, Carta *carta2) {
    printf("\n=== Comparação de Cartas ===\n");

    printf("População: %d\n", (carta1->populacao > carta2->populacao));
    printf("Área: %d\n", (carta1->area > carta2->area));
    printf("PIB: %d\n", (carta1->pib > carta2->pib));
    printf("Pontos turísticos: %d\n", (carta1->pontos_turisticos > carta2->pontos_turisticos));
    printf("Densidade Populacional: %d (vence a menor)\n", (carta1->densidade_populacional < carta2->densidade_populacional));
    printf("PIB per capita: %d\n", (carta1->pib_per_capita > carta2->pib_per_capita));
    printf("Super Poder: %d\n", (carta1->super_poder > carta2->super_poder));

    printf("============================\n");
}
#endif

int main() {
    Carta carta1, carta2;

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&carta2);

#ifdef NIVEL_AVENTUREIRO
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);
#endif

#ifdef NIVEL_MESTRE
    calcularSuperPoder(&carta1);
    calcularSuperPoder(&carta2);
#endif

    printf("\n=== Cartas Cadastradas ===\n");
    exibirCarta(&carta1);
    exibirCarta(&carta2);

#ifdef NIVEL_MESTRE
    compararCartas(&carta1, &carta2);
#endif

    return 0;
}
