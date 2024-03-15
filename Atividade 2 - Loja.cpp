#include<stdio.h>


struct Loja {

    char nome[100];
    char cargo[100];
    double salarioBase, beneficios, descontos, salario;

    void ler() {
        printf("Nome: ");
        scanf("%[^\n]%*c", nome);
        printf("Cargo: ");
        scanf("%[^\n]%*c", cargo);
        printf("Salario base: ");
        scanf("%lf%*c", &salarioBase);
        printf("Beneficios: ");
        scanf("%lf%*c", &beneficios);
        printf("Descontos: ");
        scanf("%lf%*c", &descontos);
        salario = salarioBase + beneficios - descontos;
    }

    void imprimir() {
        printf(" %s\n", nome);
        printf(" %s\n", cargo);
        printf(" R$ %.2lf\n", salarioBase);
        printf(" R$ %.2lf\n", beneficios);
        printf(" R$ %.2lf\n", descontos);
    }

};

struct Funcionario {

    Loja lojas[10];
    int qtdFuncionarios;
    double totalSalarios, maior;


    Funcionario() {
        qtdFuncionarios = 0;
        totalSalarios = 0;
        maior = 0;
    }

    void ler() {
        lojas[qtdFuncionarios].ler();
        totalSalarios += lojas[qtdFuncionarios].salario;
        if (lojas[qtdFuncionarios].salario > maior) {
            maior = lojas[qtdFuncionarios].salario;

        }

        qtdFuncionarios++;
    }

    void imprimir() {
        for (int i = 0; i < qtdFuncionarios; i++) {
            lojas[i].imprimir();
        }
    }

    double mediaSalarial() {
        if (qtdFuncionarios == 0) {
            return 0;
        }
        return totalSalarios / qtdFuncionarios;
    }

    double maiorSalario() {
        return maior;
    }

};
int main() {

   Funcionario f;

   int opcao;

    do {

        printf("1. Ler\n");
        printf("2. Imprimir\n");
        printf("3. Imprimir Maior\n");
        printf("4. Média Salarial\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d%*c", &opcao);

        switch(opcao ) {
            case 1:
                f.ler();
                break;
            case 2:
                f.imprimir();
                break;
           case 3:
                f.maiorSalario();
                break;
           case 4:
                f.mediaSalarial();
                break;
           case 5:
                printf("Saindo...\n");
                break;
        }

    } while (opcao != 5);

    return 0;
}
