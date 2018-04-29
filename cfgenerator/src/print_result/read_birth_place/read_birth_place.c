/*
 * read_birth_place.c
 *
 *  Created on: 21 ago 2017
 *      Author: gabriele
 */

#include <print_result/read_birth_place/read_birth_place.h>


static char* get_result(char* birth_place, char* town, char* code, char* result){
	if (strcmp(birth_place, town) == ZERO) {
		code = strtok(NULL, VIRGO);
		code[strlen(code) - ONE] = EOS;
		strcpy(result, code);
	}
	return result;
}

char* read_birth_place_code(FILE* places_file,char* birth_place){
	assert(places_file!= NULL&&birth_place!= NULL&&is_not_empty_string(birth_place));
    char *part = (char*) malloc((STRLEN) * sizeof(char*));
    char *town = (char*) malloc((STRLEN) * sizeof(char*));
    char *code = (char*) malloc((FIVE) * sizeof(char*));
    char *result = (char*) malloc((FIVE) * sizeof(char*));
    rewind(places_file);
    while (fgets(part, FOURTYSIX, places_file)) {
    	town = strtok(part, VIRGO);
    	result = get_result(birth_place,town,code,result);
    }
    assert(is_valid_birth_place_code(result));
    return result;
}

void file_not_found(){
	puts(FILE_NOT_FOUND);
	system(PAUSE);
	close();
}
