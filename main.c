#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

struct filme {

	char	title[100];
	int		genre[5];
	char	produtora;
	int		year;
	int		imdb;

} cadastro;

int gets_valid_int(char *string, int min, int max) {

	bool valid = false;
	int escolha;

	while (valid != true) {

		printf("%s", string);
		scanf_s("%d", &escolha);

		if (escolha < min || escolha > max)
			printf("Opção Inválida. Escolha um valor entre %d e %d\n", min, max);
		else
			return escolha;

	}

}

int main() {

	setlocale(LC_ALL, "Portuguese");

	char *string = "Qual opção deseja: ";

	printf("+----------------------------------------------+ \n");
	printf("+                 STRUCT FILMS                 + \n");
	printf("+                MENU PRINCIPAL                + \n");
	printf("+----------------------------------------------+ \n");
	printf("Escolha uma das opções abaixo: \n\n");
	printf("1 - Cadastro de filme \n");
	printf("2 - Visualizar filme \n");
	printf("3 - Modificar filme \n");
	printf("4 - Remover filme \n");
	printf("4 - Sair \n\n");
	int escolha = gets_valid_int(string, 1, 4);
	system("PAUSE");
}