/*
 * get_data.c
 *
 *  Created on: 20 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "../../src/get_data/get_data.h"

static const int MAX_LENGTH_STRING = 100;
static const int LENGTH_DATE = 11;
static const char* SPEC_CHAR = "%c";
static const char* INSERT_NAME = "Inserisci il nome>";
static const char* INSERT_SURNAME = "Inserisci il cognome>";
static const char* INSERT_DATE = "Inserisci la data di nascita (formato GG/MM/AAAA)>";
static const char* INSERT_TOWN = "Inserisci il comune di nascita>";
static const char* INSERT_SEX = "Inserisci il sesso (M-F)>";

static void insert_name(char* name) {
	printf(INSERT_NAME);
	gets(name);
}

const char* get_name() {
	fflush(stdin);
	char* name = malloc(MAX_LENGTH_STRING * sizeof(char));
	do
		insert_name(name);
	while(!is_not_empty_string(name));
	assert((is_not_empty_string(name)));
	to_upper_string(name);
	return name;
}

static void insert_surname(char* surname) {
	printf(INSERT_SURNAME);
	gets(surname);
}

const char* get_surname() {
	fflush(stdin);
	char* surname = malloc(MAX_LENGTH_STRING * sizeof(char));
	do
		insert_surname(surname);
	while(!is_not_empty_string(surname));
	assert(is_not_empty_string(surname));
	to_upper_string(surname);
	return surname;
}

static void insert_date(char* date) {
	printf(INSERT_DATE);
	gets(date);
}

const char* get_birth_date() {
	fflush(stdin);
	char* date = malloc(LENGTH_DATE*sizeof(char));
	do
		insert_date(date);
	while(!is_not_empty_string(date));
	assert(is_not_empty_string(date));
	return date;
}

static void insert_birth_town(char* town) {
	printf(INSERT_TOWN);
	gets(town);
}

const char* get_birth_town() {
	fflush(stdin);
	char* town = malloc(MAX_LENGTH_STRING * sizeof(char));
	do
		insert_birth_town(town);
	while(!is_not_empty_string(town));
	assert(is_not_empty_string(town));
	to_upper_string(town);
	return town;
}

char get_sex() {
	fflush(stdin);
	char sex;
	printf(INSERT_SEX);
	scanf(SPEC_CHAR,&sex);
	return toupper(sex);
}
