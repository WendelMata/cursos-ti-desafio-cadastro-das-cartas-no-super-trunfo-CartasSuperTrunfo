#include <stdio.h>

// Definição da estrutura para armazenar os dados da cidade
typedef struct {
    char codigo[4]; // Código da cidade (ex: A01, B02)
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

int main() {
    Cidade cidade1, cidade2;

    // Cadastro da primeira cidade
    printf("Cadastro da primeira cidade:\n");
    printf("Código da cidade: ");
    scanf("%s", cidade1.codigo);
    printf("População: ");
    scanf("%d", &cidade1.populacao);
    printf("Área (km²): ");
    scanf("%f", &cidade1.area);
    printf("PIB (em milhões): ");
    scanf("%f", &cidade1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &cidade1.pontos_turisticos);

    // Cadastro da segunda cidade
    printf("\nCadastro da segunda cidade:\n");
    printf("Código da cidade: ");
    scanf("%s", cidade2.codigo);
    printf("População: ");
    scanf("%d", &cidade2.populacao);
    printf("Área (km²): ");
    scanf("%f", &cidade2.area);
    printf("PIB (em milhões): ");
    scanf("%f", &cidade2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &cidade2.pontos_turisticos);

    // Exibição dos dados cadastrados
    printf("\nDados cadastrados:\n");
    printf("Cidade 1 (%s)\n", cidade1.codigo);
    printf("População: %d\n", cidade1.populacao);
    printf("Área: %.2f km²\n", cidade1.area);
    printf("PIB: %.2f milhões\n", cidade1.pib);
    printf("Pontos turísticos: %d\n", cidade1.pontos_turisticos);

    printf("\nCidade 2 (%s)\n", cidade2.codigo);
    printf("População: %d\n", cidade2.populacao);
    printf("Área: %.2f km²\n", cidade2.area);
    printf("PIB: %.2f milhões\n", cidade2.pib);
    printf("Pontos turísticos: %d\n", cidade2.pontos_turisticos);

    return 0;
}
