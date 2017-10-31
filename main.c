#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

#define _CRT_SECURE_NO_WARNINGS

struct filme {

	char	title[100];
	int		genre[5];
	char	producer[100];
	int		year;
	float	imdb;
	bool	active;

} cadastros[200];

void show_title() {

	setlocale(LC_ALL, "Portuguese");
	system("mode con:cols=60 lines=11");
	printf("+----------------------------------------------------------+\n");
	printf("+                       STRUCT FILMES                      +\n");
	printf("+----------------------------------------------------------+\n");
	printf("+                                                          +\n");
	printf("+    NOME: Vitor Mendes   RA: 8799001598  TURMA: SI - 2    +\n");
	printf("+    NOME: Yang Leite     RA: 2670923557  TURMA: SI - 1    +\n");
	printf("+                                                          +\n");
	printf("+----------------------------------------------------------+\n");
	printf("+                        CARREGANDO...                     +\n");
	printf("+----------------------------------------------------------+\n");
	system("timeout 5 > NUL");


}

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

void verify_database() {
	
	FILE * file;
	file = fopen_s(&file, "filmes.dat", "w");
	if (file == NULL) {

		file = fopen_s(&file, "filmes.dat", "w");
		verify_database();

	}

}

void save(int pos) {

	//verify_database();

}

void get_gender(int id) {

	int genre_array;
	int escolha;
	bool valid = false;

	printf("\nLista de Gêneros: \n\n");
	printf("1 - Ação \n");
	printf("2 - Adulto \n");
	printf("3 - Aventura \n");
	printf("4 - Comédia \n");
	printf("5 - Criminal \n");
	printf("6 - Documentario \n");
	printf("7 - Drama \n");
	printf("8 - Horror \n");
	printf("9 - Mistério \n");
	printf("10 - Musical \n");
	printf("11 - Policial \n");
	printf("12 - Romance \n");
	printf("13 - Ficção \n");
	printf("14 - Suspense \n");
	printf("15 - Terror \n");
	genre_array = get_valid_int("\nEm quantos gêneros esse filme se enquadra: ", 1, 5);
	printf("\n");
	for (int i = 0; i < genre_array; i++) {

		valid = false;

		while (valid != true) {

			printf("Qual o código do gênero %d de %d: ", i + 1, genre_array);
			scanf_s("%d", &escolha);

			if (escolha < 1 || escolha > 15)
				printf("Opção Inválida. Escolha um valor entre 1 e 15\n");
			else {

				cadastros[id].genre[i] = escolha;
				valid = true;

			}
		}
	}
}

int show_films_list() {

	int contador = 0;

	printf("Lista de filmes com código:\n\n");

	for (int i = 0; i < 200; i++) {

		if (cadastros[i].active == true) {
			contador += 1;
			printf("%0d - %s \n", i + 1, cadastros[i].title);
		}

	}

	return contador;

}

void sleep() {

	printf("\n+-----------------------------------------------------------+\n");
	printf("+                         AGUARDE...                        +\n");
	printf("+-----------------------------------------------------------+\n");
	system("timeout 3 > NUL");
}

int main() {

	show_title();

	system("mode con:cols=61 lines=30");

	verify_database();

	char *string = "Qual opção deseja: ";

	main_menu:

	system("CLS");
	printf("+-----------------------------------------------------------+\n");
	printf("+                        STRUCT FILMS                       +\n");
	printf("+                       MENU PRINCIPAL                      +\n");
	printf("+-----------------------------------------------------------+\n");
	printf("Escolha uma das opções abaixo: \n\n");
	printf("1 - Cadastro de filme \n");
	printf("2 - Visualizar filme \n");
	printf("3 - Modificar filme \n");
	printf("4 - Remover filme \n");
	printf("5 - Sair \n\n");
	int escolha = get_valid_int(string, 1, 4);

	switch (escolha) {



		case 1: {

		char title[80];
		char *string = "Genero: ";
		int id;

		// Método para escolher espaço para colocar novo filme

		for (int i = 0; i < 200; i++) {

			printf("%d", i);

			if (cadastros[i].active != true) {
				id = i;
				break;
			}
		}

		system("CLS");
		printf("+-----------------------------------------------------------+\n");
		printf("+                        STRUCT FILMS                       +\n");
		printf("+                          CADASTRO                         +\n");
		printf("+-----------------------------------------------------------+\n");
		gets(title);

		printf("\nTitulo: ");
		gets(cadastros[id].title);
		get_gender(id);
		gets(title);
		printf("\nDiretor: ");
		gets(cadastros[id].producer);
		char *ano = "Ano: ";
		cadastros[id].year = get_valid_int(ano, 1900,2050);
		char *nota = "Nota IMDB: ";
		cadastros[id].imdb = get_valid_float(nota, 0, 10);
		cadastros[id].active = true;
		gets(title);

		printf("\nCadastro realizado com sucesso!");
		sleep();
		goto main_menu;
	
		}

		case 2: {

			system("CLS");
			printf("+----------------------------------------------------------+\n");
			printf("+                        STRUCT FILMS                      +\n");
			printf("+                         VISUALIZAR                       +\n");
			printf("+----------------------------------------------------------+\n");
			break;

		}

		case 3: {

			char title[10];
			int id, escolha;

			try_editar:

			system("CLS");
			printf("+----------------------------------------------------------+\n");
			printf("+                        STRUCT FILMS                      +\n");
			printf("+                           EDITAR                         +\n");
			printf("+----------------------------------------------------------+\n");
			
			if (show_films_list() < 1) {

				printf("Não há filmes na lista.\n\n");
				system("PAUSE");
				goto main_menu;
				break;

			}

			printf("\nQual o código do filme que deseja editar (0 - Cancelar): ");
			scanf_s("%d", &id);

			film_edit:

			system("CLS");
			printf("+----------------------------------------------------------+\n");
			printf("+                        STRUCT FILMS                      +\n");
			printf("+                           EDITAR                         +\n");
			printf("+----------------------------------------------------------+\n");

			if (id == 0) {
				goto main_menu;
				break;
			}
			else if (cadastros[id - 1].active == true) {
				
				id -= 1;
				printf("\nFilme: %s\n\nO que deseja editar no filme:\n\n", cadastros[id].title);
				printf("1 - Titulo \n");
				printf("2 - Gênero \n");
				printf("3 - Diretor \n");
				printf("4 - Ano \n");
				printf("5 - Nota IMDB \n");
				printf("0 - Cancelar \n");
				printf("\nQual opção deseja:");
				scanf_s("%d", &escolha);

				system("CLS");
				printf("+----------------------------------------------------------+\n");
				printf("+                        STRUCT FILMS                      +\n");
				printf("+                           EDITAR                         +\n");
				printf("+----------------------------------------------------------+\n\n");
				
				switch (escolha) {
				case 0: {


					
				}
				case 1: {

					gets(title);
					printf("Titulo atual: %s\n", cadastros[id].title);
					printf("Insira o novo titulo: ");
					gets(cadastros[id].title);
					printf("\nTitulo alterado com sucesso!\n");
					sleep();
					goto film_edit;
				
				}
				case 2: {
					
					gets(title);
					printf("Filme: %s\n", cadastros[id].title);
					get_gender(id);
					printf("\nGênero alterado com sucesso!\n");
					sleep();
					goto film_edit; 
				
				}
				case 3: {

					gets(title);
					printf("Diretor atual: %s\n", cadastros[id].producer);
					printf("Insira o novo diretor: ");
					gets(cadastros[id].title);
					printf("\nDiretor alterado com sucesso!\n");
					sleep();
					goto film_edit;
				
				}
				case 4: {

					int number;

					gets(title);
					printf("Ano do filme atual: %d\n", cadastros[id].year);
					char *ano = "Insira o novo Ano do filme: ";
					cadastros[id].year = get_valid_int(ano, 1900, 2050);
					printf("\Ano do filme alterado com sucesso!\n");
					sleep();
					goto film_edit;
				
				}
				case 5: {
					
					gets(title);
					printf("Nota IMDB atual: %d\n", cadastros[id].year);
					char *nota = "Nova nota IMDB: ";
					cadastros[id].imdb = get_valid_float(nota, 0, 10); 
					printf("\Nota IMDB alterada com sucesso!\n");
					sleep();
					goto film_edit;
				}
				}

				goto try_excluir;

			} else {

				printf("\nEsse item não consta na lista.");
				goto try_editar;
			}

		}

		case 4: {

			int escolha;

			try_excluir:
			
			system("CLS");
			printf("+----------------------------------------------------------+\n");
			printf("+                        STRUCT FILMS                      +\n");
			printf("+                          EXCLUIR                         +\n");
			printf("+----------------------------------------------------------+\n\n");

			if (show_films_list() < 1) {

				printf("Não há filmes na lista.\n");
				system("PAUSE");
				goto main_menu;
				break;

			}
			
			printf("\n\nQual o código do filme que deseja deletar (0 - Cancelar): ");
			scanf_s("%d", &escolha);

			if (escolha == 0) {
				goto main_menu;
				break;
			} else if (cadastros[escolha - 1].active == true) {
				cadastros[escolha - 1].active = false;
				printf("\nO filme foi excluido com sucesso.");
				sleep();
				goto try_excluir;
			} else {
				printf("\nEsse item não consta na lista.");
				goto try_excluir;
			}

		}

		case 5: {

			return 0;

		}

	}

	system("PAUSE");

}