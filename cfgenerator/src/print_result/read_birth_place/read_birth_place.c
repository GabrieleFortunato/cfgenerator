/*
 * read_birth_place.c
 *
 *  Created on: 21 ago 2017
 *      Author: gabriele
 */

#include "print_result/read_birth_place/read_birth_place.h"

static void result_code(char* code, char* result){
	code = strtok(NULL, VIRGO);
	code[strlen(code) - ONE] = EOS;
	strcpy(result, code);
}

static char* get_result(char* birth_place,char *part,char *result){
	char *town = strtok(part, VIRGO);
	char *code = (char*) malloc((FIVE) * sizeof(char*));
	if (strcmp(birth_place, town) == ZERO)
		result_code(code,result);
	return result;
}

char* read_birth_place_code(FILE* places_file,char* birth_place){
	assert(places_file!= NULL);
	assert(birth_place!= NULL);
	assert(is_not_empty_string(birth_place));
    char *part = (char*) malloc((STRLEN) * sizeof(char*));
    char *result = (char*) malloc((FIVE) * sizeof(char*));
    rewind(places_file);
    while (fgets(part, FOURTYSIX, places_file))
    	result = get_result(birth_place,part,result);
    assert(is_valid_town_code(result));
    return result;
}

void file_not_found(){
	puts(FILE_NOT_FOUND);
	system(PAUSE);
	close();
}
