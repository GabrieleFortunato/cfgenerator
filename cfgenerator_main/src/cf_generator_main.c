/*
 ============================================================================
 Name        : cf_generator_main.c
 Author      : Gabriele Fortunato
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "print_result/print_code.h"
#include "print_result/read_birth_place/read_birth_place.h"
#include "get_data/get_data.h"
#include "intro/intro.h"
#include "repeat/repeat.h"

void not_found(){
	file_not_found();
}

void cfgenerator(FILE* file){
	do{
		(file==NULL)?not_found():
				print_result(get_sex(),read_birth_place_code(file,get_birth_town()),get_birth_date(),get_surname(),get_name());
	} while (repeat());
}

int main(void) {
	intro();
	FILE* file = fopen(FILE_NAME,FILE_MODE);
	(file==NULL)?file_not_found():cfgenerator(file);
	fclose(file);
	return EXIT_SUCCESS;
}
