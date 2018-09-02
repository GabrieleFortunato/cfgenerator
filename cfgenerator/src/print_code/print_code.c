/*
 * print_result.c
 *
 *  Created on: 27 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "print_code.h"

static const char* NOT_VALID_DATA =
		"\nI dati inseriti non sono tutti corretti\n\n";
static const char* PRINT_CODE =
		"\n================================\n"
		"Codice fiscale: %s"
		"\n================================\n";
static const int CODE_LENGTH = 17;

static void print_code(char* name, char* surname, char* birth_date, char* coded_town, char sex){
	char code[CODE_LENGTH];
	cf_generator(name,surname,birth_date,coded_town,sex,code);
	printf(
			PRINT_CODE,
			code);
}

static void not_valid_data(){
	printf(NOT_VALID_DATA);
}

void print_result(char sex, char* coded_town, char* birth_date, char* surname, char* name){
	(is_valid_data(name, surname, birth_date, coded_town, sex)) ?
			print_code(name,surname,birth_date,coded_town,sex) : not_valid_data();
}
