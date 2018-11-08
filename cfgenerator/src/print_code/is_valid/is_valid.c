/*
 * is_valid.c
 *
 *  Created on: 19 set 2017
 *      Author: gabriele
 */

#include "is_valid.h"

#define ZERO           	0
#define ONE        		1
#define TWO        		2
#define THREE      		3
#define FOUR       		4
#define FIVE       		5
#define SIX        		6
#define SEVEN      		7
#define EIGHT      		8
#define NINE       		9
#define TEN        		10
#define TWELVE     		12
#define THIRTEEN        13
#define FOURTEEN        14
#define SIXTEEN         16
#define THIRTYONE  		31
#define ASCII      		48
#define HUNDRED  	  	100
#define THOUSAND   		1000
#define MIN_YEAR   		1900
#define MAX_YEAR   		2018
#define SLASH      		'/'
#define F 	            'F'
#define M 	            'M'
#define SPACE           ' '
#define APOSTROPHE      '\''
#define EMPTY_STRING    ""

static bool are_valid_chars_name_surname_code(char* code){
	bool flag = true;
	for (int i = ZERO; i < strlen(code) && flag;)
		flag = 	isupper(code[i++]);
	return flag;
}

bool is_valid_coded_surname_name(char* code){
	return strlen(code) == THREE && are_valid_chars_name_surname_code(code);
}

static bool is_valid_char_name_surname(char* string){
	bool flag = true;
	for (int i=ZERO;i < strlen(string) && flag; i++)
		flag = (isupper(string[i])) || (string[i]) == APOSTROPHE || (string[i] == SPACE);
	return flag;
}

bool is_valid_name_surname(char* surname){
	return surname != NULL && strlen(surname) != ZERO && is_valid_char_name_surname(surname);
}

static int number_A(char a, char b){
	return TEN * (a - ASCII) + (b - ASCII);
}

static int number_B(char a, char b, char c, char d){
	return THOUSAND * (a - ASCII) + HUNDRED * (b - ASCII) + TEN * (c - ASCII) + (d - ASCII);
}

static bool is_valid_day(char* date){
	return number_A(date[ZERO], date[ONE]) > ZERO && number_A(date[ZERO], date[ONE]) <= THIRTYONE;
}

static bool is_valid_month(char* date){
	return number_A(date[THREE], date[FOUR]) > ZERO && number_A(date[THREE], date[FOUR]) <= TWELVE;
}

static bool is_valid_year(char* date){
	return number_B(date[SIX], date[SEVEN], date[EIGHT], date[NINE]) >= MIN_YEAR
	       && number_B(date[SIX], date[SEVEN], date[EIGHT], date[NINE]) <= MAX_YEAR;
}

static bool is_valid_char_date(char* date){
	bool flag = true;
	for (int i = ZERO; i<strlen(date)&&flag; i++)
		flag = ((i==TWO || i==FIVE) && (date[i] == SLASH)) || isdigit(date[i]);
	return flag;
}

static bool are_valid_numbers(char* date){
	return is_valid_day(date) && is_valid_month(date) && is_valid_year(date);
}

bool is_valid_date(char* date){
	return strlen(date) == TEN && is_valid_char_date(date) && are_valid_numbers(date);
}

bool is_valid_ctrl_code(char code){
	return isupper(code);
}

static bool is_valid_char_town_code(char* code){
	bool flag = true;
	for (int i = ZERO; i< strlen(code) && flag;)
		flag = (i == ZERO) ? isupper(code[i++]) : isdigit(code[i++]);
	return flag;
}

bool is_valid_town_code(char* code){
	return code!=NULL && strlen(code) == FOUR && is_valid_char_town_code(code);
}

bool is_not_empty_string(char* string){
	return (strcmp(string,EMPTY_STRING) != ZERO);
}

bool is_valid_sex(char sex){
	return sex == M || sex == F;
}

bool is_valid_town(char* town){
	return strcmp(town, EMPTY_STRING) != ZERO || town != NULL;
}

bool are_valid_data(char* name, char* surname, char* date, char* coded_town, char sex){
	return is_valid_name_surname(name) && is_valid_name_surname(surname) &&
		   is_valid_date(date) && is_valid_town_code(coded_town) && is_valid_sex(sex);
}

static bool is_valid_index(int i){
	return i==SIX || i==SEVEN || i==NINE || i==TEN || i==TWELVE ||
		   i==TWELVE||i== THIRTEEN || i==FOURTEEN;
}

static bool is_valid_cf_char(char* code, int i){
	return (is_valid_index(i)) ? isdigit(code[i]) : isupper(code[i]);
}

static bool are_valid_cf_chars(char* code){
	bool flag = true;
	for (int i = ZERO; i < strlen(code) && flag; i++)
		flag = is_valid_cf_char(code, i);
	return flag;
}

bool is_valid_cf_code(char* code){
	return (strlen(code) != SIXTEEN) ? false : are_valid_cf_chars(code);
}

static bool is_valid_char_date_code(char* code, int i){
	return (i==TWO) ? isupper(code[i]) : isdigit(code[i]);
}

static bool are_valid_chars_date_code(char* code){
	bool flag = true;
	for (int i = ZERO; i < strlen(code) && flag; i++)
		flag = is_valid_char_date_code(code, i);
	return flag;
}

bool is_valid_date_code(char* code){
	return strlen(code) == FIVE && are_valid_chars_date_code(code);
}
