#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

struct filme {

	char	title[100];
	int		genre[5];
	char	producer[100];
	int		year;
	float	imdb;
	bool	active;

} cadastros[200];

float get_valid_float(char *string, float min, float max) {

	bool valid = false;
	float escolha;

	while (valid != true) {

		printf("%s", string);
		scanf_s("%f", &escolha);

		if (escolha < min || escolha > max)
			printf("Opção Inválida. Escolha um valor entre %.1f e %.1f\n", min, max);
		else
			return escolha;

	}

}

int get_valid_int(char *string, int min, int max) {

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

//void save(int pos) {



//}

int main() {

	setlocale(LC_ALL, "Portuguese");

	char *string = "Qual opção deseja: ";

	main_menu:

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
	int escolha = get_valid_int(string, 1, 4);

	switch (escolha) {

		case 1: {

		char title[80];
		char *string = "Genero: ";
		int pos;

		// Método para escolher espaço para colocar novo filme

		for (int i = 0; i < 200; i++) {

			printf("%d", i);

			if (cadastros[i].active != true) {
				pos = i;
				break;
			}
		}

		system("CLS");
		printf("+----------------------------------------------+ \n");
		printf("+                 STRUCT FILMS                 + \n");
		printf("+              CADASTRO DE FILME               + \n");
		printf("+----------------------------------------------+ \n\n");
		gets(title);

		printf("Titulo: ");
		gets(cadastros[pos].title);
		printf("Produtora: ");
		gets(cadastros[pos].producer);
		char *ano = "Ano: ";
		cadastros[pos].year = get_valid_int(ano, 1900,2050);
		char *nota = "Nota IMDB: ";
		cadastros[pos].imdb = get_valid_float(nota, 0, 10);
		cadastros[pos].active = true;

		goto main_menu;
	
		}

	}

	system("PAUSE");

}