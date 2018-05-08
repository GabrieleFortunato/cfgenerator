/*
 * get_data.c
 *
 *  Created on: 20 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "../../src/get_data/get_data.h"

char* get_name(){
	fflush(stdin);
	char* name = malloc(MAX_LENGTH_NAME*sizeof(char));
	do{
		printf(INSERT_NAME);
		gets(name);
	} while(!is_not_empty_string(name));
	assert((is_not_empty_string(name)));
	to_upper(name);
	return name;
}

char* get_surname(){
	fflush(stdin);
	char* surname = malloc(MAX_LENGTH_SURNAME*sizeof(char));
	do{
		printf(INSERT_SURNAME);
		gets(surname);
	} while(!is_not_empty_string(surname));
	assert(is_not_empty_string(surname));
	to_upper(surname);
	return surname;
}

char* get_birth_date(){
	fflush(stdin);
	char* date = malloc(LENGTH_DATE*sizeof(char));
	do{
		printf(INSERT_DATE);
		gets(date);
	} while(!is_not_empty_string(date));
	assert(is_not_empty_string(date));
	return date;
}

char* get_birth_town(){
	fflush(stdin);
	char* town = malloc(MAX_LENGTH_TOWN*sizeof(char));
	do{
		printf(INSERT_TOWN);
		gets(town);
	} while(!is_not_empty_string(town));
	assert(is_not_empty_string(town));
	to_upper(town);
	return town;
}

char get_sex(){
	fflush(stdin);
	char sex;
	printf(INSERT_SEX);
	scanf(SPEC_CHAR,&sex);
	sex = toupper(sex);
	return sex;
}
