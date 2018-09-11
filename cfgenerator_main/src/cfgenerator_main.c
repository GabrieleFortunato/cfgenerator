/*
 ============================================================================
 Name        : cf_generator_main.c
 Author      : Gabriele Fortunato
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <print_code/print_code.h>
#include <print_code/read_birth_place/read_birth_place.h>
#include <stdio.h>
#include <stdlib.h>
#include "access/access.h"
#include "close/close.h"
#include "get_data/get_data.h"
#include "intro/intro.h"
#include "repeat/repeat.h"

static const char* ITALIAN_TOWNS_FILE = "comuni.csv";
static const char* REAF_FROM_FILE = "r";
static const char* WRITE_ON_FILE = "w";
static const char* ACCESS_FILE_NAME = "accessi.txt";

void access(){
	FILE* file = fopen(ACCESS_FILE_NAME, WRITE_ON_FILE);
	print_access(file);
	fclose(file);
}

void print_cfgenerator(FILE* file){
	intro();
	(file==NULL)?file_not_found():
			print_code(get_sex(),read_birth_place_code(file,get_birth_town()),get_birth_date(),get_surname(),get_name());
}

void cfgenerator(FILE* file){
	access();
	do{
		print_cfgenerator(file);
	} while (repeat());
}

int main(void) {
	FILE* file = fopen(ITALIAN_TOWNS_FILE, REAF_FROM_FILE);
	(file==NULL)?file_not_found():cfgenerator(file);
	fclose(file);
	close();
	return EXIT_SUCCESS;
}
