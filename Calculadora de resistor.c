#include <stdio.h>
#include <math.h>

int main() {
    //variavel
    int n, i;
    int entrada;
    int tipo;
    int c1, c2, mult;
    int ns, np;

    double R[20];
    double Req = 0;
    double serie = 0;
    double paralelo = 0;

    printf("CALCULADORA DE RESISTORES \n");

    printf("Quantidade de resistores: ");
    scanf("%d", &n);
    
    //validacao para o numeros de resistores
    if (n <= 0 || n > 20) {
        printf("Quantidade invalida\n");
        return 1;
    }
    //usuario escolhe qual a forma de entrada
    printf("\n1 - Digitar valores\n");
    printf("2 - Informar pelas cores\n");
    printf("Escolha: ");
    scanf("%d", &entrada);

    for (i = 0; i < n; i++) {
        printf("\nResistor %d\n", i + 1);

        if (entrada == 1) {
            printf("Valor (ohms): ");
            scanf("%lf", &R[i]);
        }
        //tem uma tabela das cores para o usario saber qual e cor e qual numero
        if (entrada == 2) {
    printf("\nTabela de cores:\n");
    printf("0-Preto  1-Marrom  2-Vermelho  3-Laranja  4-Amarelo\n");
    printf("5-Verde  6-Azul    7-Violeta   8-Cinza    9-Branco\n\n");

    printf("Primeira cor (0-9): ");
    scanf("%d", &c1);
    printf("Segunda cor (0-9): ");
    scanf("%d", &c2);
    printf("Multiplicador (0-9): ");
    scanf("%d", &mult);
    R[i] = (c1 * 10 + c2) * pow(10, mult);
    printf("Valor encontrado: %.2lf ohms\n", R[i]);
}
    }
    //caso o usario digite qualquer numero alem de 1 a 2 o programa fecha
    
    if (entrada != 1 && entrada != 2) {
        printf("Opcao invalida!\n");
        return 1;
    }
   // pergunta como os resistores estão associados no circuito
    printf("\n1 - Serie\n");
    printf("2 - Paralelo\n");
    printf("3 - Misto\n");
    printf("Escolha: ");
    scanf("%d", &tipo);
    //caso  seja esse serie passara por esse if
    if (tipo == 1) {
        for (i = 0; i < n; i++) {
            Req = Req + R[i];
        }
    }
    //caso seja paralelo passara por esse if
    
    if (tipo == 2) {
        for (i = 0; i < n; i++) {
            Req = Req + 1.0 / R[i];
        }

        Req = 1.0 / Req;
    }
// caso seja associacao mista
    if (tipo == 3) {
        //pergunta quantos resistores serao em serie
        printf("Quantos resistores em serie? ");
        scanf("%d", &ns);
        //quantos em paralelo
        printf("Quantos resistores em paralelo? ");
        scanf("%d", &np);
        //se os resistores foram maiores do que o usuario escolheu no inicio o programa fecha
        if (ns + np > n) {
            printf("Quantidade invalida\n");
            return 1;
        }
         // soma os primeiros "ns" resistores do vetor (bloco serie)
        for (i = 0; i < ns; i++) {
            serie = serie + R[i];
        }

        for (i = ns; i < ns + np; i++) {
            paralelo = paralelo + 1.0 / R[i];
        }

        paralelo = 1.0 / paralelo;
        Req = serie + paralelo;
    }
    // checa se tipo foi valido de novo, so detectado tarde,
    if (tipo != 1 && tipo != 2 && tipo != 3) {
        printf("Opcao invalida\n");
        return 1;
    }

    printf("\n  RELATORIO FINAL \n");
// lista o valor de cada resistor que foi lido/calculado no inicio
    for (i = 0; i < n; i++) {
        printf("R%d = %.2lf ohms\n", i + 1, R[i]);
    }
// mostra a resistencia equivalente total  calculada conforme o tipo escolhido
    printf("Resistencia equivalente = %.2lf ohms\n", Req);

    return 0;
}
