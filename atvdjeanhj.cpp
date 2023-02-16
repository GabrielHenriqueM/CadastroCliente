#include <stdio.h>
#include <string.h>
#include <windows.h>

// ESTRUTURA DE DADOS
// NOME DA DUPLA:
// GABRIEL MOREIRA
// GABRIEL ROCHA

struct Data {
    int dia, mes, ano;

    Data() {
        dia = 0;
        mes = 0;
        ano = 0;
    }

    void ler() {
        printf("Digite a data de nascimento do cliente:\n");
        printf("Dia: ");
        scanf("%d", &dia);
        printf("Mês: ");
        scanf("%d", &mes);
        printf("Ano: ");
        scanf("%d", &ano);
    }

    void imprimir() {
        printf("%02d / %02d / %04d", dia, mes, ano);
    }
};

struct Cliente {
    char nome[100];
    char sexo[1];
    Data dataNascimento;

    Cliente() {
        strcpy(nome, "");
        strcpy(sexo, "");
        dataNascimento = Data();
    }

    void ler() {
        printf("Digite o nome do cliente: ");
        scanf("%s", nome);
        printf("Digite o sexo do cliente (M/F): ");
        scanf("%s", sexo);
        dataNascimento.ler();
    }

    void imprimir() {
        printf("Nome do cliente: %s\n", nome);
        printf("Sexo do cliente: %s\n", sexo);
        printf("Data de nascimento do cliente: ");
        dataNascimento.imprimir();
        printf("\n");
    }

    int idade() {
        SYSTEMTIME st;
        GetLocalTime(&st);

        int idade = st.wYear - dataNascimento.ano;

        if (dataNascimento.mes > st.wMonth) {
            idade--;
        } else if (dataNascimento.mes == st.wMonth) {
            if (dataNascimento.dia > st.wDay) {
                idade--;
            }
        }

        return idade;
    }
};

int main() {

    Cliente clientes[50];
    int opcao = 0, totalClientes = 0;

    do {
        printf("\nSelecione uma opção:\n");
        printf("1 - Cadastrar novo cliente\n");
        printf("2 - Listar clientes cadastrados\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                if (totalClientes >= 50) {
                    printf("\nNúmero máximo de clientes cadastrados atingido.\n");
                    break;
                }

                clientes[totalClientes].ler();
                totalClientes++;

                printf("\nCliente cadastrado com sucesso.\n");
                break;

            case 2:
                if (totalClientes == 0) {
                    printf("\nNão há clientes cadastrados.\n");
                    break;
                }

                printf("\nClientes cadastrados:\n");
                for (int i = 0; i < totalClientes; i++) {
                    printf("\nCliente %d:\n", i+1);
                    clientes[i].imprimir();
                    printf("Idade do cliente: %d anos\n", clientes[i].idade());
                }

                break;

            case 0:
                printf("\nFim do programa!\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
