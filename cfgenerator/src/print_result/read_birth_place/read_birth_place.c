/*
 * read_birth_place.c
 *
 *  Created on: 21 ago 2017
 *      Author: gabriele
 */

#include "../../../src/print_result/read_birth_place/read_birth_place.h"

static const int FIFTEEN = 50;
static const char* PAUSE = "pause";
static const char* FILE_NOT_FOUND = "File dei codici catastali non trovato\n";
static const int fourtysix = 46;
static const int zero = 0;
static const int one = 1;
static const int five = 5;
static const char eos = '\0';
static const char* virgo = ",";

static void result_code(char* code, char* result){
	code = strtok(NULL, virgo);
	code[strlen(code) - one] = eos;
	strcpy(result, code);
}

static char* get_result(char* birth_place,char *part,char *result){
	char *town = strtok(part, virgo);
	char *code = (char*) malloc((five) * sizeof(char*));
	if (strcmp(birth_place, town) == zero)
		result_code(code,result);
	return result;
}

char* read_birth_place_code(FILE* places_file,char* birth_place){
	assert(places_file!= NULL);
	assert(birth_place!= NULL);
	assert(is_not_empty_string(birth_place));
	char *part = (char*) malloc((FIFTEEN) * sizeof(char*));
	char *result = (char*) malloc((five) * sizeof(char*));
    rewind(places_file);
	while (fgets(part, fourtysix, places_file))
    	result = get_result(birth_place,part,result);
    assert(is_valid_town_code(result));
    return result;
}

void file_not_found(){
	puts(FILE_NOT_FOUND);
	system(PAUSE);
	close();
}
