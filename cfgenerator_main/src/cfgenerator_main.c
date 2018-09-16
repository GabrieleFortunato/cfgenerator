/*
 ============================================================================
 Name        : cf_generator_main.c
 Author      : Gabriele Fortunato
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "print_code/print_code.h"
#include "access/access.h"
#include "print_code/read_birth_place/read_birth_place.h"
#include "close/close.h"
#include "get_data/get_data.h"
#include "intro/intro.h"
#include "repeat/repeat.h"

static const char* ITALIAN_TOWNS_FILE = "comuni.csv";
static const char* READ_FROM_FILE = "r";
static const char* WRITE_ON_FILE = "w";
static const char* ACCESS_FILE_NAME = "accessi.txt";

void access(){
	FILE* file = fopen(ACCESS_FILE_NAME, WRITE_ON_FILE);
	print_access(file);
	fclose(file);
}

void print_cfgenerator(FILE* file){
	intro();
	char* name = get_name();
	char* surname = get_surname();
	char* birth_date = get_birth_date();
	char* town = get_birth_town();
	char sex = get_sex();
	(file==NULL) ? file_not_found() :
			print_code(name,surname, birth_date, read_birth_place_code(file, town), sex, file);
}

void cfgenerator(FILE* file){
	do{
		print_cfgenerator(file);
	} while (repeat());
}

int main(void) {
	access();
	FILE* file = fopen(ITALIAN_TOWNS_FILE, READ_FROM_FILE);
	(file==NULL) ? file_not_found() : cfgenerator(file);
	fclose(file);
	close();
	return EXIT_SUCCESS;
}
