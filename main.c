#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define NO_WARN_MBCS_MFC_DEPRECATION

void flush() {

	char flush[3];
	gets(flush);

}

struct filme {

	char	title[100];
	int		genre[3];
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

int min_year() {

	int min_year = 2500;

	for (int i = 0; i < 200; i++) {

		if (cadastros[i].active == true && cadastros[i].year < min_year)
			min_year = cadastros[i].year;

	}

	if (min_year == 2500)
		return -1;
	else
		return min_year;
}

float min_imdb() {

	float min_imdb = 10;

	for (int i = 0; i < 200; i++) {

		if (cadastros[i].active == true && cadastros[i].imdb < min_imdb)
			min_imdb = cadastros[i].imdb;

	}

	return min_imdb;
}

int max_year() {

	int max_year = 500;

	for (int i = 0; i < 200; i++) {

		if (cadastros[i].active == true && cadastros[i].year > max_year)
			max_year = cadastros[i].year;

	}

	if (max_year == 500)
		return -1;
	else
		return max_year;
}

float max_imdb() {

	float max_imdb = 0;

	for (int i = 0; i < 200; i++) {

		if (cadastros[i].active == true && cadastros[i].imdb > max_imdb)
			max_imdb = cadastros[i].imdb;

	}

	return max_imdb;
}

int total_films() {
	int count = 0;

	for (int i = 0; i < 200; i++) {
		if (cadastros[i].active == true)
			count += 1;
	}

	return count;
}

void sleep() {

	printf("\n+-----------------------------------------------------------+\n");
	printf("+                         AGUARDE...                        +\n");
	printf("+-----------------------------------------------------------+\n");
	system("timeout 3 > NUL");
}

void show_title() {

	setlocale(LC_ALL, "Portuguese");
	system("mode con:cols=61 lines=11");
	system("COLORS 70");
	printf("+----------------------------------------------------------+\n");
	printf("+                        STRUCT FILMS                      +\n");
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
		flush();

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
		flush();

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
	printf("3 - Animação \n");
	printf("4 - Aventura \n");
	printf("5 - Comédia \n");
	printf("6 - Criminal \n");
	printf("7 - Documentario \n");
	printf("8 - Drama \n");
	printf("9 - Fantasia \n");
	printf("10 - Horror \n");
	printf("11 - Mistério \n");
	printf("12 - Musical \n");
	printf("13 - Policial \n");
	printf("14 - Romance \n");
	printf("15 - Sci-fi \n");
	printf("16 - Suspense \n");
	printf("17 - Terror \n");
	genre_array = get_valid_int("\nEm quantos gêneros esse filme se enquadra: ", 1, 3);
	printf("\n");
	for (int i = 0; i < genre_array; i++) {

		valid = false;

		while (valid != true) {

			printf("Qual o código do gênero %d de %d: ", i + 1, genre_array);
			scanf_s("%d", &escolha);
			flush();

			if (escolha < 1 || escolha > 17)
				printf("Opção Inválida. Escolha um valor entre 1 e 17\n");
			else {
				cadastros[id].genre[i] = escolha;
				valid = true;

			}
		}
	}

	for (int g = genre_array; g <= 3; g++) {
		cadastros[id].genre[g] = 0;
	}
}

void show_gender(int id) {

	if (id >= 0) {

		for (int i = 0; i < 3; i++) {

			switch (cadastros[id].genre[i]) {

			case 0: { printf("\n");					return; }
			case 1: { printf("[Ação]");				break;	}
			case 2: { printf("[Adulto]");			break;	}
			case 3: { printf("[Animação]");			break;	}
			case 4: { printf("[Aventura]");			break;	}
			case 5: { printf("[Comédia]");			break;	}
			case 6: { printf("[Criminal]");			break;	}
			case 7: { printf("[Documentario]");		break;	}
			case 8: { printf("[Drama]");			break;	}
			case 9: { printf("[Fantasia]");			break;	}
			case 10: { printf("[Horror]");			break;	}
			case 11: { printf("[Mistério]");		break;	}
			case 12: { printf("[Musical]");			break;	}
			case 13: { printf("[Policial]");		break;	}
			case 14: { printf("[Romance]");			break;	}
			case 15: { printf("[Sci-fi]");			break;	}
			case 16: { printf("[Suspense]");		break;	}
			case 17: { printf("[Terror]"); 			break;	}
			}

			if (cadastros[id].genre[i + 1] != 0)
				printf(" ");
		}

	}
	else {

		switch (id) {
		case -1: { printf("[Ação]");				break;	}
		case -2: { printf("[Adulto]");				break;	}
		case -3: { printf("[Animação]");			break;	}
		case -4: { printf("[Aventura]");			break;	}
		case -5: { printf("[Comédia]");				break;	}
		case -6: { printf("[Criminal]");			break;	}
		case -7: { printf("[Documentario]");		break;	}
		case -8: { printf("[Drama]");				break;	}
		case -9: { printf("[Fantasia]");			break;	}
		case -10: { printf("[Horror]");				break;	}
		case -11: { printf("[Mistério]");			break;	}
		case -12: { printf("[Musical]");			break;	}
		case -13: { printf("[Policial]");			break;	}
		case -14: { printf("[Romance]");			break;	}
		case -15: { printf("[Sci-fi]");				break;	}
		case -16: { printf("[Suspense]");			break;	}
		case -17: { printf("[Terror]"); 			break;	}
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

		printf("Titulo atual: %s\n", cadastros[id].title);
		printf("Insira o novo titulo: ");
		gets(cadastros[id].title);
		printf("\nTitulo alterado com sucesso!\n");
		sleep();
		edit_film(id);
		break;

	}
	case 2: {

		printf("Filme: [%03d] %s\n\n", id + 1, cadastros[id].title);
		printf("Gênero atual: "); show_gender(id);
		get_gender(id);
		printf("\nGênero alterado com sucesso!\n");
		sleep();
		edit_film(id);
		break;

	}
	case 3: {

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

		printf("Filme: [%03d] %s\n\n", id + 1, cadastros[id].title);
		printf("Nota IMDB atual: %.1f\n", cadastros[id].imdb);
		char *nota = "Nova nota IMDB: ";
		cadastros[id].imdb = get_valid_float(nota, 0, 10);
		printf("\nNota IMDB alterada com sucesso!\n");
		sleep();
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

bool have_films() {
	int total = total_films();

	if (total <= 0)
		return false;
	return true;
}

void show_films_list(int type) {

	int contador = 0;

	system("CLS");
	printf("+-----------------------------------------------------------+\n");
	printf("+                         STRUCT FILMS                      +\n");
	printf("+                          VISUALIZAR                       +\n");
	printf("+-----------------------------------------------------------+\n\n");

	if (have_films() == false) { printf("Não há cadastros ativos.\n"); sleep();	return; }

	if		(type == 0) {

		printf("Lista de filmes por código:\n\n");

		for (int i = 0; i < 200; i++) {

			if (cadastros[i].active == true) {
				contador += 1;
				printf("[%03d] %s \n", i + 1, cadastros[i].title);
			}

		}

	}
	else if (type == 1) {

		char *string = "Insira o código do gênero (0 - Retornar): ";
		int escolha, contador_genre = 0;

		printf("Lista de Gêneros: \n\n");
		printf("1 - Ação \n");
		printf("2 - Adulto \n");
		printf("3 - Animação \n");
		printf("4 - Aventura \n");
		printf("5 - Comédia \n");
		printf("6 - Criminal \n");
		printf("7 - Documentario \n");
		printf("8 - Drama \n");
		printf("9 - Fantasia \n");
		printf("10 - Horror \n");
		printf("11 - Mistério \n");
		printf("12 - Musical \n");
		printf("13 - Policial \n");
		printf("14 - Romance \n");
		printf("15 - Sci-fi \n");
		printf("16 - Suspense \n");
		printf("17 - Terror \n\n");
		escolha = get_valid_int(string, 0, 17);

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
					else if (cadastros[id].genre[id_genre] == escolha && cadastros[id].active == true) {
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
				show_films_list(type);
				return;
			}

		} else { 
			return;
		}
	}
	else if (type == 2) {

		int range = last_id();
		int actual_year = min_year();
		int next_year;
		int total = total_films();
		int contador = 0;

		while (contador < total) {

			next_year = 2200;

			for (int id = 0; id <= range; id++) {
				if (cadastros[id].active == true && cadastros[id].year == actual_year) {
					if (contador == 0)
						printf("Lista de filmes por ano em ordem crescente: \n\n");
					printf("[%d] [%03d] %s\n", cadastros[id].year, id + 1, cadastros[id].title);
					contador += 1;
				}
				else if (cadastros[id].year > actual_year && cadastros[id].year < next_year && cadastros[id].active == true)
					next_year = cadastros[id].year;
			}

			actual_year = next_year;
		}
	}
	else if (type == 3) {

		int range = last_id();
		int actual_year = max_year();
		int next_year;
		int total = total_films();
		int contador = 0;		

		while (contador < total) {

			next_year = 500;

			for (int id = 0; id <= range; id++) {
				if (cadastros[id].active == true && cadastros[id].year == actual_year) {
					if (contador == 0)
						printf("Lista de filmes por ano em ordem decrescente: \n\n");
					printf("[%d] [%03d] %s\n", cadastros[id].year, id + 1, cadastros[id].title);
					contador += 1;
				}
				else if (cadastros[id].year < actual_year && cadastros[id].year > next_year && cadastros[id].active == true)
					next_year = cadastros[id].year;
			}

			actual_year = next_year;
		}
	}
	else if (type == 4) {

		int range = last_id();
		float actual_imdb = min_imdb();
		float next_imdb;
		int total = total_films();
		int contador = 0;

		while (contador < total) {

			next_imdb = 11;

			for (int id = 0; id <= range; id++) {
				if (cadastros[id].active == true && cadastros[id].imdb == actual_imdb) {
					if (contador == 0)
						printf("Lista de filmes por ano em ordem crescente: \n\n");
					printf("[%.1f] [%03d] %s\n", cadastros[id].imdb, id + 1, cadastros[id].title);
					contador += 1;
				}
				else if (cadastros[id].imdb > actual_imdb && cadastros[id].imdb < next_imdb && cadastros[id].active == true)
					next_imdb = cadastros[id].imdb;
			}

			actual_imdb = next_imdb;
		}
	}
	else if (type == 5) {

		int range = last_id();
		float actual_imdb = max_imdb();
		float next_imdb;
		int total = total_films();
		int contador = 0;

		while (contador < total) {

			next_imdb = -1;

			for (int id = 0; id <= range; id++) {
				if (cadastros[id].active == true && cadastros[id].imdb == actual_imdb) {
					if (contador == 0)
						printf("Lista de filmes por ano em ordem crescente: \n\n");
					printf("[%.1f] [%03d] %s\n", cadastros[id].imdb, id + 1, cadastros[id].title);
					contador += 1;
				}
				else if (cadastros[id].imdb < actual_imdb && cadastros[id].imdb > next_imdb && cadastros[id].active == true)
					next_imdb = cadastros[id].imdb;
			}

			actual_imdb = next_imdb;
		}
	}
	else if (type == 6) {

		printf("Lista de filmes por código:\n\n");

		for (int i = 199; i >= 0; i--) {

			if (cadastros[i].active == true) {
				contador += 1;
				printf("[%03d] %s \n", i + 1, cadastros[i].title);
			}

		}

	}

	int select;

	try_select_film:

	printf("\nInsira o código do filme (0 - retornar): ");
	scanf_s("%d", &select);
	flush();

	if (select == 0)
		return;
	else if (select < 0 || cadastros[select - 1].active != true) {
		printf("\nCódigo inválido!\n");
		goto try_select_film;
	} else {

		sleep();
		show_film_detail(select - 1);
		show_films_list(type);

	}

}

int main() {

	show_title();

	// system("mode con:cols=61 lines=30");

	HANDLE OUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD BUFFER_SIZE = { 61, 210 };
	SetConsoleScreenBufferSize(OUTPUT, BUFFER_SIZE);
	SMALL_RECT QUADRADO = { 0, 0, 60, 30 };
	SetConsoleWindowInfo(OUTPUT, TRUE, &QUADRADO);

	verify_database();

	char *string = "Qual opção deseja: ";

	main_menu:

	system("CLS");
	printf("+-----------------------------------------------------------+\n");
	printf("+                         STRUCT FILMS                      +\n");
	printf("+                        MENU PRINCIPAL                     +\n");
	printf("+-----------------------------------------------------------+\n\n");
	printf("Escolha uma das opções abaixo: \n\n");
	printf("1 - Incluir filme \n");
	printf("2 - Buscar filme \n\n");
	printf("0 - Sair \n\n");
	int escolha = get_valid_int(string, 0, 3);

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

		printf("\nTitulo: ");
		gets(cadastros[id].title);
		get_gender(id);
		printf("\nDiretor: ");
		gets(cadastros[id].producer);
		char *ano = "Ano: ";
		cadastros[id].year = get_valid_int(ano, 1900,2050);
		char *nota = "Nota IMDB: ";
		cadastros[id].imdb = get_valid_float(nota, 0, 10);
		cadastros[id].active = true;

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
			if (have_films() == false) { printf("Não há cadastros ativos.\n"); sleep();	goto main_menu; }
			printf("Escolha uma das opções abaixo: \n\n");
			printf("1 - Buscar filme por lista \n");
			printf("2 - Buscar filme por titulo \n");
			printf("3 - Buscar filme por diretor \n\n");
			printf("0 - Voltar \n\n");
			int escolha = get_valid_int(string, 0, 3);

			switch (escolha) {

				case 0: { goto main_menu; }
				case 1: {
				list_choice:

					system("CLS");
					printf("+-----------------------------------------------------------+\n");
					printf("+                         STRUCT FILMS                      +\n");
					printf("+                          VISUALIZAR                       +\n");
					printf("+-----------------------------------------------------------+\n\n");
					if (have_films() == false) { printf("Não há cadastros ativos.\n"); sleep();	goto main_menu; }
					printf("Escolha uma das opções abaixo: \n\n");
					printf("1 - Visualizar lista de filmes por ordem de código \n");
					printf("2 - Visualizar lista de filmes por gênero \n");
					printf("3 - Visualizar lista de filmes por ordem de ano \n");
					printf("4 - Visualizar lista de filmes por ordem de nota \n\n");
					printf("0 - Voltar \n\n");
					escolha = get_valid_int(string, 0, 4);

					switch (escolha) {

						case 0: { goto search_choice; break; }
						case 1: { 

							system("CLS");
							printf("+-----------------------------------------------------------+\n");
							printf("+                         STRUCT FILMS                      +\n");
							printf("+                          VISUALIZAR                       +\n");
							printf("+-----------------------------------------------------------+\n\n");
							printf("Escolha uma das opções abaixo: \n\n");
							printf("1 - Ordem crescente \n");
							printf("2 - Ordem decrescente \n\n");
							printf("0 - Voltar \n\n");
							escolha = get_valid_int(string, 0, 2);

							if (escolha == 2) { show_films_list(6); }
							else if (escolha == 1) { show_films_list(0); }
							goto list_choice;
							break;

						}
						case 2: {
							int result;
							show_films_list(1);
							goto list_choice;
							break;
						}
						case 3: {

							system("CLS");
							printf("+-----------------------------------------------------------+\n");
							printf("+                         STRUCT FILMS                      +\n");
							printf("+                          VISUALIZAR                       +\n");
							printf("+-----------------------------------------------------------+\n\n");
							printf("Escolha uma das opções abaixo: \n\n");
							printf("1 - Ordem crescente \n");
							printf("2 - Ordem decrescente \n\n");
							printf("0 - Voltar \n\n");
							escolha = get_valid_int(string, 0, 2);

							int result;

							if (escolha == 2) { show_films_list(3); }
							else if (escolha == 1) { show_films_list(2); }
							goto list_choice;
							break;

						}
						case 4: {

							system("CLS");
							printf("+-----------------------------------------------------------+\n");
							printf("+                         STRUCT FILMS                      +\n");
							printf("+                          VISUALIZAR                       +\n");
							printf("+-----------------------------------------------------------+\n\n");
							printf("Escolha uma das opções abaixo: \n\n");
							printf("1 - Ordem crescente \n");
							printf("2 - Ordem decrescente \n\n");
							printf("0 - Voltar \n\n");
							escolha = get_valid_int(string, 0, 2);

							int result;

							if (escolha == 2) { show_films_list(5); }
							else if (escolha == 1) { show_films_list(4); }
							goto list_choice;
							break;
						}

					}
				}

				case 2: {

					char title[100];
					int id = -1;

					system("CLS");
					printf("+-----------------------------------------------------------+\n");
					printf("+                         STRUCT FILMS                      +\n");
					printf("+                          VISUALIZAR                       +\n");
					printf("+-----------------------------------------------------------+\n\n");
					if (have_films() == false) { printf("Não há cadastros ativos.\n"); sleep();	goto main_menu; }
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
				case 3: {

					char title[100];
					int id = -1;

					try_producer:

					system("CLS");
					printf("+-----------------------------------------------------------+\n");
					printf("+                         STRUCT FILMS                      +\n");
					printf("+                          VISUALIZAR                       +\n");
					printf("+-----------------------------------------------------------+\n\n");
					if (have_films() == false) { printf("Não há cadastros ativos.\n"); sleep();	goto main_menu; }
					printf("Insira o nome do diretor: ");
					gets(title);

					int contador = 0;

					system("CLS");
					printf("+-----------------------------------------------------------+\n");
					printf("+                         STRUCT FILMS                      +\n");
					printf("+                          VISUALIZAR                       +\n");
					printf("+-----------------------------------------------------------+\n\n");

					for (int id = 0; id < 200; id++) {

						if (_stricmp(title, cadastros[id].producer) == 0 && cadastros[id].active == true) {
							if (contador == 0)
								printf("\nLista de filmes com o diretor [%s]:\n\n", cadastros[id].producer);
							printf("[%03d] %s\n", id + 1, cadastros[id].title);
							contador += 1;
						}
					}

					if (contador == 0) { printf("Não existe registros com o nome desse diretor\n");
					sleep();
					goto search_choice;

					}

						try_film:

						printf("\nInsira o código do filme (0 - Voltar): ");
						scanf_s("%d", &escolha);

						if (escolha == 0)
							goto search_choice;
						else if (cadastros[escolha - 1].active == true)  {
							sleep();
							show_film_detail(escolha - 1);	
							goto search_choice;

						} else {
							printf("Código inválido ou inexistente! Tente novamente.\n");
							sleep();
							goto try_film;
						}
				}

			}
		}

		case 0: {

			return 0;

		}

		case 3: {

			int id;
			
			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "A menina que roubava livros");
			cadastros[id].genre[0] = 8;
			strcpy_s(cadastros[id].producer,sizeof(cadastros[id].producer), "-");
			cadastros[id].imdb = 7.9;
			cadastros[id].year = 2013;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Blade Runner 2049");
			cadastros[id].genre[0] = 11;
			cadastros[id].genre[1] = 15;
			cadastros[id].genre[2] = 16;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "-");
			cadastros[id].imdb = 8.1;
			cadastros[id].year = 2017;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e a Pedra Filosofal");
			cadastros[id].genre[0] = 4;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "Chris Columbus");
			cadastros[id].imdb = 7.5;
			cadastros[id].year = 2001;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e a Câmara Secreta");
			cadastros[id].genre[0] = 4;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "Chris Columbus");
			cadastros[id].imdb = 7.4;
			cadastros[id].year = 2002;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e o Prisioneiro de Azkaban");
			cadastros[id].genre[0] = 4;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "Alfonso Cuarón");
			cadastros[id].imdb = 7.8;
			cadastros[id].year = 2004;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e o Calice de Fogo");
			cadastros[id].genre[0] = 4;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "Mike Newell");
			cadastros[id].imdb = 7.7;
			cadastros[id].year = 2005;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e a Ordem da Fênix");
			cadastros[id].genre[0] = 4;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "David Yates");
			cadastros[id].imdb = 7.5;
			cadastros[id].year = 2007;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e o Enigma do Principe");
			cadastros[id].genre[0] = 4;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "David Yates");
			cadastros[id].imdb = 7.5;
			cadastros[id].year = 2009;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e as Reliquias da Morte (Parte I)");
			cadastros[id].genre[0] = 4;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "David Yates");
			cadastros[id].imdb = 7.7;
			cadastros[id].year = 2010;
			cadastros[id].active = true;

			id = last_id() + 1;

			strcpy_s(cadastros[id].title, sizeof(cadastros[id].producer), "Harry Potter e as Reliquias da Morte (Parte II)");
			cadastros[id].genre[0] = 4;
			cadastros[id].genre[1] = 9;
			strcpy_s(cadastros[id].producer, sizeof(cadastros[id].producer), "David Yates");
			cadastros[id].imdb = 8.1;
			cadastros[id].year = 2011;
			cadastros[id].active = true;

			goto main_menu;

		}

	}

}