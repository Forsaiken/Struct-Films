#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include "main.h"

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define NO_WARN_MBCS_MFC_DEPRECATION

void flush() {

	char flush[3];
	gets(flush);

}

struct filme {

	char	title[100];
	int		genre[5];
	char	producer[100];
	int		year;
	float	imdb;
	bool	active;

} cadastros[200];

int last_id() {

	int last_id = 0;

	for (int i = 0; i < 200; i++) {
		if (cadastros[i].active == true)
			last_id = i;
	}

	return last_id;
}

void sleep() {

	printf("\n+-----------------------------------------------------------+\n");
	printf("+                         AGUARDE...                        +\n");
	printf("+-----------------------------------------------------------+\n");
	system("timeout 3 > NUL");
}

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

	for (int g = genre_array; g < 5; g++) {
		cadastros[id].genre[g] = 0;
	}
}

void show_gender(int id) {

	if (id >= 0) {

		for (int i = 0; i <= 5; i++) {

			switch (cadastros[id].genre[i]) {

			case 0: { printf("\n");				return; }
			case 1: { printf("[Ação]");			break;	}
			case 2: { printf("[Adulto]");			break;	}
			case 3: { printf("[Aventura]");		break;	}
			case 4: { printf("[Comédia]");			break;	}
			case 5: { printf("[Criminal]");		break;	}
			case 6: { printf("[Documentario]");	break;	}
			case 7: { printf("[Drama]");			break;	}
			case 8: { printf("[Horror]");			break;	}
			case 9: { printf("[Mistério]");		break;	}
			case 10: { printf("[Musical]");			break;	}
			case 11: { printf("[Policial]");		break;	}
			case 12: { printf("[Romance]");			break;	}
			case 13: { printf("[Ficção]");			break;	}
			case 14: { printf("[Suspense]");		break;	}
			case 15: { printf("[Terror]"); 			break;	}
			}

			if (cadastros[id].genre[i + 1] != 0)
				printf(" ");
		}

	}
	else {

		switch (id) {
		case -1: { printf("[Ação]");			break;	}
		case -2: { printf("[Adulto]");			break;	}
		case -3: { printf("[Aventura]");		break;	}
		case -4: { printf("[Comédia]");			break;	}
		case -5: { printf("[Criminal]");		break;	}
		case -6: { printf("[Documentario]");	break;	}
		case -7: { printf("[Drama]");			break;	}
		case -8: { printf("[Horror]");			break;	}
		case -9: { printf("[Mistério]");		break;	}
		case -10: { printf("[Musical]");			break;	}
		case -11: { printf("[Policial]");		break;	}
		case -12: { printf("[Romance]");			break;	}
		case -13: { printf("[Ficção]");			break;	}
		case -14: { printf("[Suspense]");		break;	}
		case -15: { printf("[Terror]"); 			break;	}
		}
	}
}

void edit_film(int id) {

	int escolha;
	char *string = "Qual opção deseja: ";
	system("CLS");
	printf("+-----------------------------------------------------------+\n");
	printf("+                         STRUCT FILMS                      +\n");
	printf("+                            EDITAR                         +\n");
	printf("+-----------------------------------------------------------+\n");

	printf("\nFilme: [%03d] %s\n\nO que deseja editar no filme:\n\n", id + 1, cadastros[id].title);
	printf("1 - Titulo \n");
	printf("2 - Gênero \n");
	printf("3 - Diretor \n");
	printf("4 - Ano \n");
	printf("5 - Nota IMDB \n\n");
	printf("0 - Voltar \n\n");
	escolha = get_valid_int(string, 0, 5);

	system("CLS");
	printf("+-----------------------------------------------------------+\n");
	printf("+                         STRUCT FILMS                      +\n");
	printf("+                            EDITAR                         +\n");
	printf("+-----------------------------------------------------------+\n\n");

	switch (escolha) {

	case 0: {

		return;
		break;

	}
	case 1: {

		flush();
		printf("Titulo atual: %s\n", cadastros[id].title);
		printf("Insira o novo titulo: ");
		gets(cadastros[id].title);
		printf("\nTitulo alterado com sucesso!\n");
		sleep();
		edit_film(id);
		break;

	}
	case 2: {

		flush();
		printf("Filme: [%03d] %s\n\n", id + 1, cadastros[id].title);
		printf("Gênero atual: "); show_gender(id);
		get_gender(id);
		printf("\nGênero alterado com sucesso!\n");
		sleep();
		edit_film(id);
		break;

	}
	case 3: {

		flush();
		printf("Filme: [%03d] %s\n\n", id + 1, cadastros[id].title);
		printf("Diretor atual: %s\n", cadastros[id].producer);
		printf("Insira o novo diretor: ");
		gets(cadastros[id].producer);
		printf("\nDiretor alterado com sucesso!\n");
		sleep();
		edit_film(id);
		break;

	}
	case 4: {

		flush();
		printf("Filme: [%03d] %s\n\n", id + 1, cadastros[id].title);
		printf("Ano do filme atual: %d\n", cadastros[id].year);
		char *ano = "Insira o novo Ano do filme: ";
		cadastros[id].year = get_valid_int(ano, 1900, 2050);
		printf("\nAno do filme alterado com sucesso!\n");
		sleep();
		edit_film(id);
		break;

	}
	case 5: {

		flush();
		printf("Filme: [%03d] %s\n\n", id + 1, cadastros[id].title);
		printf("Nota IMDB atual: %.1f\n", cadastros[id].imdb);
		char *nota = "Nova nota IMDB: ";
		cadastros[id].imdb = get_valid_float(nota, 0, 10);
		printf("\nNota IMDB alterada com sucesso!\n");
		sleep();
		flush();
		edit_film(id);
		break;
	}
	}
}

void show_film_detail(int id) {

	char *string = "Qual opção deseja: ";

	system("CLS");
	printf("+-----------------------------------------------------------+\n");
	printf("+                         STRUCT FILMS                      +\n");
	printf("+                          VISUALIZAR                       +\n");
	printf("+-----------------------------------------------------------+\n\n");
	printf("Código: %03d\n", id + 1);
	printf("Titulo: %s\n", cadastros[id].title);
	printf("Gênero: ");	show_gender(id);
	printf("Diretor: %s\n", cadastros[id].producer);
	printf("Ano: %d\n", cadastros[id].year);
	printf("Nota IMDB: %.1f\n\n", cadastros[id].imdb);
	printf("Escolha uma das opções abaixo: \n\n");
	printf("1 - Editar cadastro\n");
	printf("2 - Remover cadastro\n\n");
	printf("0 - Retornar\n\n");
	int escolha = get_valid_int(string, 0, 2);

	if (escolha == 0) {

		sleep();
		return;

	}
	else if (escolha == 1) {

		sleep();
		edit_film(id);
		show_film_detail(id);


	}
	else if (escolha == 2) {

		cadastros[id].active = false;
		printf("\nO cadastro foi excluido com sucesso.");
		sleep();
		return;

	}
}

int show_films_list(int type) {

	int contador = 0;

	system("CLS");
	printf("+-----------------------------------------------------------+\n");
	printf("+                         STRUCT FILMS                      +\n");
	printf("+                          VISUALIZAR                       +\n");
	printf("+-----------------------------------------------------------+\n\n");

	if (type == 0) {

		printf("Lista de filmes com código:\n\n");

		for (int i = 0; i < 200; i++) {

			if (cadastros[i].active == true) {
				contador += 1;
				printf("[%03d] %s \n", i + 1, cadastros[i].title);
			}

		}

		return contador;

		// Por Genero

	} else if (type == 1) {

		char *string = "Insira o código do gênero (0 - Retornar): ";
		int escolha, contador_genre = 0;

		printf("Lista de Gêneros: \n\n");
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
		printf("15 - Terror \n\n");
		escolha = get_valid_int(string, 0, 15);

		if (escolha != 0) {

			system("CLS");
			printf("+-----------------------------------------------------------+\n");
			printf("+                         STRUCT FILMS                      +\n");
			printf("+                          VISUALIZAR                       +\n");
			printf("+-----------------------------------------------------------+\n\n");

			for (int id = 0; id <= last_id(); id++) {
				for (int id_genre = 0; id_genre <= 5; id_genre++) {
					if (cadastros[id].genre[id_genre] == 0) {
						break;
					}
					else if (cadastros[id].genre[id_genre] == escolha) {
						if (contador_genre == 0) {
							printf("Lista de filmes com gênero "); show_gender(escolha - (escolha * 2)); printf(" :\n\n");
						}

						printf(" [%03d] %s\n", id + 1, cadastros[id].title);
						contador_genre += 1;
					}
				}
			}

			if (contador_genre == 0) {
				printf("Não há itens nesse gênero\n");
				sleep();
				show_films_list(1);
			}
		} else { 
			return 0;
		}
	}

	int select;

	try_select_film:

	printf("\nInsira o código do filme (0 - retornar): ");
	scanf_s("%d", &select);

	if (select < 0 || cadastros[select - 1].active != true) {
		printf("\nCódigo inválido!\n");
		sleep();
		goto try_select_film;
	} else if (select == 0) { show_films_list(1);
	} else {

		sleep();
		show_film_detail(select - 1);
		show_films_list(1);

	}

}

int main() {

	show_title();

	system("mode con:cols=61 lines=30");

	verify_database();

	char *string = "Qual opção deseja: ";

	main_menu:

	system("CLS");
	printf("+-----------------------------------------------------------+\n");
	printf("+                         STRUCT FILMS                      +\n");
	printf("+                        MENU PRINCIPAL                     +\n");
	printf("+-----------------------------------------------------------+\n");
	printf("Escolha uma das opções abaixo: \n\n");
	printf("1 - Cadastro de filme \n");
	printf("2 - Visualizar filme \n");
	printf("3 - Modificar filme \n");
	printf("4 - Remover filme \n");
	printf("5 - Sair \n\n");
	int escolha = get_valid_int(string, 1, 6);

	switch (escolha) {  

		case 1: {

		char *string = "Genero: ";
		int id;

		for (int i = 0; i < 200; i++) {

			printf("%d", i);

			if (cadastros[i].active != true) {
				id = i;
				break;
			}
		}

		system("CLS");
		printf("+-----------------------------------------------------------+\n");
		printf("+                         STRUCT FILMS                      +\n");
		printf("+                           CADASTRO                        +\n");
		printf("+-----------------------------------------------------------+\n");
		flush();

		printf("\nTitulo: ");
		gets(cadastros[id].title);
		get_gender(id);
		flush();
		printf("\nDiretor: ");
		gets(cadastros[id].producer);
		char *ano = "Ano: ";
		cadastros[id].year = get_valid_int(ano, 1900,2050);
		char *nota = "Nota IMDB: ";
		cadastros[id].imdb = get_valid_float(nota, 0, 10);
		cadastros[id].active = true;
		flush();

		printf("\nCadastro realizado com sucesso!");
		sleep();
		goto main_menu;
	
		}

		case 2: {

			char *string = "Qual opção deseja: ";

			search_choice:

			system("CLS");
			printf("+-----------------------------------------------------------+\n");
			printf("+                         STRUCT FILMS                      +\n");
			printf("+                          VISUALIZAR                       +\n");
			printf("+-----------------------------------------------------------+\n\n");
			printf("Escolha uma das opções abaixo: \n\n");
			printf("1 - Buscar filme por lista \n");
			printf("2 - Buscar filme por nome \n\n");
			printf("0 - Voltar \n\n");
			int escolha = get_valid_int(string, 0, 2);
			flush();

			switch (escolha) {

				case 0: { goto main_menu; }
				case 1: {
				list_choice:

					system("CLS");
					printf("+-----------------------------------------------------------+\n");
					printf("+                         STRUCT FILMS                      +\n");
					printf("+                          VISUALIZAR                       +\n");
					printf("+-----------------------------------------------------------+\n\n");
					printf("Escolha uma das opções abaixo: \n\n");
					printf("1 - Visualizar lista de filmes por ordem de código \n");
					printf("2 - Visualizar lista de filmes por gênero \n");
					printf("3 - Visualizar lista de filmes por ordem de ano \n");
					printf("4 - Visualizar lista de filmes por ordem de nota \n\n");
					printf("0 - Voltar \n\n");
					escolha = get_valid_int(string, 0, 4);
					flush();

					switch (escolha) {

					case 0: { goto search_choice; break; }
						case 1: { 

							code_order:

							if (show_films_list(1) < 1) {

								printf("Não há filmes na lista.\n\n");
								sleep();
								goto list_choice;
								break;

							} else {

								int id;

								printf("Insira o código do filme para visualizar (0 - Retornar):");
								scanf_s("%d", &id);
								id -= 1;

								if (id < 0 || cadastros[id].active != true) {
									printf("Código inválido ou inexistente");
									sleep();
									goto code_order;
								}
								else {

									sleep();
									show_film_detail(id);

								}
						}
							break;
						}
						case 2: {
							int result;
							result = show_films_list(1);
							if (result == 0)
								goto list_choice;
						}
						case 3: {
							break;
						}
						case 4: {
							break;
						}

					}

				}

				case 2: {

					char title[100];
					int id = -1;

					// char *title;

					system("CLS");
					printf("+-----------------------------------------------------------+\n");
					printf("+                         STRUCT FILMS                      +\n");
					printf("+                          VISUALIZAR                       +\n");
					printf("+-----------------------------------------------------------+\n\n");
					printf("Insira o nome do filme: ");
					gets(title);

					for (int i = 0; i < 200; i++) {

						if (_stricmp(title, cadastros[i].title) == 0) {
							id = i;
							i = 200;

						}

					}

					if (id > -1 && cadastros[id].active == true) {

						printf("\nEncontrado!\n");
						sleep();

						show_film_detail(id);

					}
					else {
						printf("\nTitulo não encontrado.\n");
						sleep();
					}

					
					goto search_choice;

				}

			}

		}

		case 3: {

			int id, escolha;

			try_editar:

			system("CLS");
			printf("+-----------------------------------------------------------+\n");
			printf("+                         STRUCT FILMS                      +\n");
			printf("+                            EDITAR                         +\n");
			printf("+-----------------------------------------------------------+\n");
			
			if (show_films_list(0) < 1) {

				printf("Não há filmes na lista.\n\n");
				sleep();
				goto main_menu;
				break;

			}

			printf("\nQual o código do filme que deseja editar (0 - Voltar): ");
			scanf_s("%d", &id);
			id -= 1;

			system("CLS");
			printf("+-----------------------------------------------------------+\n");
			printf("+                         STRUCT FILMS                      +\n");
			printf("+                            EDITAR                         +\n");
			printf("+-----------------------------------------------------------+\n");

			if (id < 0) {

				goto main_menu;
				break;

			} else if (cadastros[id].active == true) {
				
				edit_film(id);
				sleep();
				goto try_editar;

					
			} else {

				printf("\nEsse item não consta na lista.");
				sleep();
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

			if (show_films_list(0) < 1) {

				printf("Não há filmes na lista.\n\n");
				sleep();
				goto main_menu;
				break;

			}
			
			printf("\nQual o código do filme que deseja deletar (0 - Voltar): ");
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
				sleep();
				goto try_excluir;
			}

		}

		case 5: {

			return 0;

		}

		case 6: {

			int id;
			
			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "A menina que roubava livros");
			cadastros[id].genre[0] = 7;
			strcpy_s(cadastros[id].producer,sizeof(cadastros[id].producer), "-");
			cadastros[id].imdb = 7.9;
			cadastros[id].year = 2013;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Blade Runner 2049");
			cadastros[id].genre[0] = 1;
			cadastros[id].genre[1] = 3;
			cadastros[id].genre[2] = 13;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "-");
			cadastros[id].imdb = 8.1;
			cadastros[id].year = 2017;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e a Pedra Filosofal");
			cadastros[id].genre[0] = 3;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "Chris Columbus");
			cadastros[id].imdb = 7.5;
			cadastros[id].year = 2001;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e a Câmara Secreta");
			cadastros[id].genre[0] = 3;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "Chris Columbus");
			cadastros[id].imdb = 7.4;
			cadastros[id].year = 2002;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e o Prisioneiro de Azkaban");
			cadastros[id].genre[0] = 3;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "Alfonso Cuarón");
			cadastros[id].imdb = 7.8;
			cadastros[id].year = 2004;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e o Calice de Fogo");
			cadastros[id].genre[0] = 3;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "Mike Newell");
			cadastros[id].imdb = 7.7;
			cadastros[id].year = 2005;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e a Ordem da Fênix");
			cadastros[id].genre[0] = 3;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "David Yates");
			cadastros[id].imdb = 7.5;
			cadastros[id].year = 2007;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e o Enigma do Principe");
			cadastros[id].genre[0] = 3;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "David Yates");
			cadastros[id].imdb = 7.5;
			cadastros[id].year = 2009;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e as Reliquias da Morte (Parte I)");
			cadastros[id].genre[0] = 3;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "David Yates");
			cadastros[id].imdb = 7.7;
			cadastros[id].year = 2010;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e as Reliquias da Morte (Parte II)");
			cadastros[id].genre[0] = 3;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "David Yates");
			cadastros[id].imdb = 8,1;
			cadastros[id].year = 2011;
			cadastros[id].active = true;

			goto main_menu;

		}

	}

}