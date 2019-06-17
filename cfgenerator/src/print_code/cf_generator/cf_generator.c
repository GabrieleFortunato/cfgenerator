/*
 * cf_generator.c
 *
 *  Created on: 21 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "cf_generator.h"

static const int ZERO = 0;
static const int ONE = 1;
static const int TWO = 2;
static const int THREE = 3;
static const int FOUR = 4;
static const int FIVE = 5;
static const int SIX = 6;
static const int SEVEN = 7;
static const int EIGHT = 8;
static const int NINE = 9;
static const int TEN = 10;
static const int ELEVEN = 11;
static const int TWELVE = 12;
static const int THIRTEEN = 13;
static const int FOURTEEN = 14;
static const int FIFTEEN = 15;
static const int SIXTEEN = 16;
static const int SEVENTEEN = 17;
static const int EIGHTEEN = 18;
static const int NINETEEN = 19;
static const int TWENTY = 20;
static const int TWENTYONE = 21;
static const int TWENTYTWO = 22;
static const int TWENTYTHREE = 23;
static const int TWENTYFOUR = 24;
static const int TWENTYFIVE = 25;
static const int TWENTYSIX = 26;
static const char EOS = '\0';
static const char A ='A';
static const char B = 'B';
static const char C = 'C';
static const char D = 'D';
static const char E = 'E';
static const char F = 'F';
static const char G = 'G';
static const char H = 'H';
static const char I = 'I';
static const char J = 'J';
static const char K = 'K';
static const char L = 'L';
static const char M = 'M';
static const char N = 'N';
static const char O = 'O';
static const char P = 'P';
static const char Q = 'Q';
static const char R = 'R';
static const char S = 'S';
static const char T = 'T';
static const char U = 'U';
static const char V = 'V';
static const char W = 'W';
static const char X = 'X';
static const char Y = 'Y';
static const char Z = 'Z';
static const char CHAR_0 = '0';
static const char CHAR_1 = '1';
static const char CHAR_2 = '2';
static const char CHAR_3 = '3';
static const char CHAR_4 = '4';
static const char CHAR_5 = '5';
static const char CHAR_6 = '6';
static const char CHAR_7 = '7';
static const char CHAR_8 = '8';
static const char CHAR_9 = '9';

static bool is_vowel(char a){
	return a==A || a==E || a==I || a==O || a==U;
}

static bool is_consonant(char a){
	return isalpha(a) && !is_vowel(a);
}

static int get_consonant(int k, char string, char* consonants) {
	if (is_consonant(string))
		consonants[k++] = string;
	return k;
}

static void get_consonants(const char* string, char* consonants) {
	int k = ZERO;
	for (int i = ZERO; i < strlen(string); i++)
		k = get_consonant(k, string[i], consonants);
	consonants[k] = EOS;
}

static int insert_consonant(char text, char* code, int ind) {
	if (is_consonant(text))
		code[ind++] = text;
	return ind;
}

static int insert_consonants(const char* text, int ind, char* code) {
	for (int i = ZERO; i < strlen(text) && ind < THREE; i++)
		ind = insert_consonant(text[i], code, ind);
	return ind;
}

static int insert_vowel(char text, char code[], int ind) {
	if (is_vowel(text))
		code[ind++] = text;
	return ind;
}

static int insert_vowels(const char text[], int ind, char code[]) {
	for (int i = ZERO; i < strlen(text) && ind < THREE; i++)
		ind = insert_vowel(text[i], code, ind);
	return ind;
}

static int fill_X(int ind, char code[]) {
	while (ind < THREE)
		code[ind++] = X;
	return ind;
}

static void fill_code(const char text[], char code[]) {
	int ind = ZERO;
	ind = insert_consonants(text, ind, code);
	ind = insert_vowels(text, ind, code);
	ind = fill_X(ind, code);
	code[ind] = EOS;
}

static void fill_coded_name_four_consonants(char code[], char* consonants) {
	int ind = ZERO;
	code[ind++] = consonants[ZERO];
	code[ind++] = consonants[TWO];
	code[ind++] = consonants[THREE];
	code[ind] = EOS;
}

static char month_0(char a){
	return (a == CHAR_1) ? A : (a == CHAR_2) ? B : (a == CHAR_3) ? C :
		   (a == CHAR_4) ? D : (a == CHAR_5) ? E : (a == CHAR_6) ? H :
		   (a == CHAR_7) ? L : (a == CHAR_8) ?  M : P;
}

static char month_1(char b){
	return (b == CHAR_0) ? R : (b == CHAR_1) ? S : T;
}

static char month(char a, char b){
	return (a == CHAR_0) ? month_0 (b) : month_1(b);
}

static void birth_date_code_M(const char* date, char code[]){
	code[ZERO] = date[EIGHT];
	code[ONE] = date[NINE];
	code[TWO] = month(date[THREE], date[FOUR]);
	code[THREE] = date[ZERO];
	code[FOUR] = date[ONE];
}

static void birth_date_code_F(const char* date, char code[]){
	code[ZERO] = date[EIGHT];
	code[ONE] = date[NINE];
	code[TWO] = month(date[THREE],date[FOUR]);
	code[THREE] = date[ZERO] + FOUR;
	code[FOUR] = date[ONE];
}

static int even_character(char a){
	return (a == CHAR_0 || a == A) ? ONE: (a == CHAR_1 || a == B) ? ZERO :
		   (a == CHAR_2 || a == C) ? FIVE : (a == CHAR_3 || a == D) ? SEVEN :
	       (a == CHAR_4 || a == E) ? NINE : (a == CHAR_5 || a == F) ? THIRTEEN :
	       (a == CHAR_6 || a==G) ? FIFTEEN : (a==CHAR_7 || a==H) ? SEVENTEEN :
	       (a==CHAR_8 || a == I) ? NINETEEN : (a==CHAR_9 || a == J) ? TWENTYONE :
	       (a == K) ? TWO : (a == L) ? FOUR : (a == M) ? EIGHTEEN : (a == N) ? TWENTY :
	       (a == O) ? ELEVEN : (a == P) ? THREE : (a == Q) ? SIX : (a == R) ? EIGHT :
	       (a == S) ? TWELVE : (a == T) ? FOURTEEN: (a == U) ? SIXTEEN : (a == V) ? TEN :
	       (a == W) ? TWENTYTWO  : (a == X) ? TWENTYFIVE : (a == Y) ? TWENTYFOUR : TWENTYTHREE;
}

static int odd_character(char a){
	return (a == CHAR_0 || a == A) ? ZERO: (a == CHAR_1 || a == B) ? ONE :
		   (a == CHAR_2 || a == C) ? TWO : (a == CHAR_3 || a == D) ? THREE :
		   (a == CHAR_4 || a == E) ? FOUR : (a == CHAR_5 || a==F) ? FIVE :
		   (a == CHAR_6 || a==G) ? SIX : (a==CHAR_7 || a==H) ? SEVEN :
		   (a==CHAR_8 || a == I) ? EIGHT : (a==CHAR_9 || a == J) ? NINE :
		   (a == K) ? TEN : (a == L) ? ELEVEN : (a == M) ? TWELVE :
		   (a == N) ? THIRTEEN : (a == O) ? FOURTEEN : (a == P) ? FIFTEEN :
		   (a == Q) ? SIXTEEN : (a == R) ? SEVENTEEN : (a == S) ? EIGHTEEN :
		   (a == T) ? NINETEEN : (a == U) ? TWENTY : (a == V) ? TWENTYONE :
		   (a == W) ? TWENTYTWO  : (a == X) ? TWENTYTHREE : (a == Y) ? TWENTYFOUR : TWENTYFIVE;
}

static char get_result(int number){
	return (number == ZERO) ? A : (number == ONE) ? B : (number == TWO) ? C :
		   (number == THREE) ? D : (number == FOUR) ? E : (number == FIVE) ? F :
		   (number == SIX) ? G : (number == SEVEN) ? H : (number == EIGHT) ? I :
		   (number == NINE) ? J : (number == TEN) ? K : (number == ELEVEN) ? L :
		   (number == TWELVE) ? M : (number == THIRTEEN) ? N : (number == FOURTEEN) ? O :
		   (number == FIFTEEN) ? P : (number == SIXTEEN) ? Q : (number == SEVENTEEN) ? R :
		   (number == EIGHTEEN) ? S : (number == NINETEEN) ? T : (number == TWENTY) ? U :
		   (number == TWENTYONE) ? V : (number == TWENTYTWO) ? W : (number == TWENTYTHREE) ? X :
		   (number == TWENTYFOUR) ? Y : Z ;
}

static void code_strcat(const char* coded_name, const char* coded_surname,
		const char* coded_birth_date, const char* coded_town, char* code){
	strcat(code,coded_surname);
	strcat(code,coded_name);
	strcat(code,coded_birth_date);
	strcat(code,coded_town);
	code[strlen(code)]=EOS;
}

static int get_sum(char* code) {
	int sum = ZERO;
	for (int i = ZERO; i < strlen(code); i++)
		sum += (i % TWO == ZERO) ?
				even_character(code[i]) : odd_character(code[i]);
	return sum;
}

void name_code(const char*  name, char code[]){
	assert(is_valid_name_surname(name));
	char consonants[strlen(name)];
	get_consonants(name,consonants);
	(strlen(consonants) >= FOUR) ?
			fill_coded_name_four_consonants(code, consonants) :
			fill_code(name, code);
	assert(is_valid_coded_surname_name(code));
}

void surname_code(const char*  surname, char code[]){
	assert(is_valid_name_surname(surname));
	fill_code(surname, code);
	assert(is_valid_coded_surname_name(code));
}

void birth_date_code(const char* date, char sex, char code[]){
	assert(is_valid_date(date));
	assert(is_valid_sex(sex));
	(sex == M) ? birth_date_code_M(date, code) : birth_date_code_F(date, code);
	code[FIVE] = EOS;
	assert(is_valid_date_code(code));
}

char ctrl_code(const char coded_name[], const char coded_surname[],
		const char coded_birth_date[], const char coded_birth_place[]){
	assert(is_valid_coded_surname_name(coded_name));
	assert(is_valid_coded_surname_name(coded_surname));
	char code[FIFTEEN];
	code[ZERO]=EOS;
	code_strcat(coded_name, coded_surname, coded_birth_date, coded_birth_place, code);
	int sum = get_sum(code);
	char result = get_result(sum % TWENTYSIX);
	assert(is_valid_ctrl_code(result));
	return result;
}


void cf_generator(const char* name, const char* surname, const char* birth_date,
		const char* coded_town, char sex, char* code){
	assert(is_valid_name_surname(name));
	assert(is_valid_name_surname(surname));
	assert(is_valid_date(birth_date));
	assert(is_valid_sex(sex));
	char coded_birth_date[SIX];
	char coded_surname[FOUR];
	char coded_name[FOUR];
	code[ZERO]=EOS;
	name_code(name, coded_name);
	surname_code(surname, coded_surname);
	birth_date_code(birth_date, sex, coded_birth_date);
	code_strcat(coded_name, coded_surname, coded_birth_date, coded_town, code);
	code[FIFTEEN] = ctrl_code(coded_name, coded_surname, coded_birth_date, coded_town);
	code[SIXTEEN] = EOS;
	assert(is_valid_cf_code(code));
}
