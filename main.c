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

char get_valid_string(char *string) {

	bool valid = false;
	char name[80];

	while (valid != true) {

		printf("%s", string);
		//sscanf("%s", &name);
		fgets(name, sizeof(name), stdin);
		return *name;

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
	int escolha = get_valid_int(string, 1, 4);
	
	switch (escolha) {

	case 1: {
			
		char *title;
		char *string = "Genero: ";
			
		system("CLS");
		printf("+----------------------------------------------+ \n");
		printf("+                 STRUCT FILMS                 + \n");
		printf("+              CADASTRO DE FILME               + \n");
		printf("+----------------------------------------------+ \n");
		//printf("\n\n Titulo: ");
		//fgets(title,80,stdin);
		title = get_valid_string(string);
		printf("%s", title);
		//gets(cadastro.genre);
		printf("\n Produtora: ");
		//gets(cadastro.produtora);
		printf("\n Ano: ");
		//gets(cadastro.year);
		printf("\n Nota IMDB: ");
		//gets(cadastro.imdb);
			

		}
	}
	system("PAUSE");
}