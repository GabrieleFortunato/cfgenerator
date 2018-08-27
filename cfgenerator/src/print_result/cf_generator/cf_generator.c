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
	return a==A||a==E||a==I||a==O||a==U;
}

static bool is_consonant(char a){
	return !is_vowel(a)&&isalpha(a);
}

int get_consonant(int i, int k, char* string, char* consonants) {
	if (is_consonant(string[i]))
		consonants[k++] = string[i];
	return k;
}

static void get_consonants(char* string, char* consonants){
	int k = ZERO;
	for (int i=ZERO;i<strlen(string);i++)
		k = get_consonant(i, k, string, consonants);
	consonants[k] = EOS;
}

int get_vowel(int i, int k, char* string, char* vowels) {
	if (is_vowel(string[i]))
		vowels[k++] = string[i];
	return k;
}

static void get_vowels(char* string, char* vowels){
	int k = ZERO;
	for (int i=ZERO;i<strlen(string);i++)
		k = get_vowel(i, k, string, vowels);
	vowels[k] = EOS;
}

static void get_consonants_vowels(char* string, char* vowels, char* consonants){
	get_consonants(string,consonants);
	get_vowels(string,vowels);
}

static void name_code_AA(char code[], char consonants[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = consonants[ONE];
	code[TWO] = consonants[TWO];
}

static void name_code_AB(char code[], char consonants[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = consonants[TWO];
	code[TWO] = consonants[THREE];
}

static void name_code_A(char code[], char consonants[]){
	strlen(consonants)==THREE?name_code_AA(code,consonants):name_code_AB(code,consonants);
}

static void name_code_BA(char code[],char consonants[],char vowels[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = consonants[ONE];
	code[TWO] = vowels[ZERO];
}

static void name_code_BB(char code[],char consonants[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = consonants[ONE];
	code[TWO] = X;
}

static void name_code_B(char code[],char consonants[],char vowels[]){
	strlen(vowels)>=ONE?name_code_BA(code,consonants,vowels):name_code_BB(code,consonants);
}

static void name_code_CA(char code[],char consonants[],char vowels[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = vowels[ZERO];
	code[TWO] = vowels[ONE];
}

static void name_code_CB(char code[],char consonants[],char vowels[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = vowels[ZERO];
	code[TWO] = X;
}

static void name_code_CC(char code[],char consonants[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = X;
	code[TWO] = X;
}

static void name_code_C(char code[],char consonants[],char vowels[]){
	strlen(vowels)>ONE?name_code_CA(code,consonants,vowels):
	strlen(vowels)==ONE?name_code_CB(code,consonants,vowels):name_code_CC(code,consonants);
}

static void name_code_DA(char code[], char vowels[]){
	code[ZERO] = vowels[ZERO];
	code[ONE] = vowels[ONE];
	code[TWO] = vowels[TWO];
}

static void name_code_DB(char code[], char vowels[]){
	code[ZERO] = vowels[ZERO];
	code[ONE] = vowels[ONE];
	code[TWO] = X;
}

static void name_code_DC(char code[], char vowels[]){
	code[ZERO] = vowels[ZERO];
	code[ONE] = X;
	code[TWO] = X;
}

static void name_code_DD(char code[]){
	code[ZERO] = X;
	code[ONE] = X;
	code[TWO] = X;
}

static void name_code_D(char code[], char vowels[]){
	strlen(vowels)>=THREE?name_code_DA(code,vowels):
	strlen(vowels)==TWO?name_code_DB(code,vowels):
	strlen(vowels)==ONE?name_code_DC(code,vowels):name_code_DD(code);
}

void name_code(char name[], char code[]){
	assert(is_valid_name(name));
	char consonants[strlen(name)];
	char vowels[strlen(name)];
	get_consonants_vowels(name,vowels,consonants);
	strlen(consonants) >= THREE ? name_code_A(code,consonants) :
	strlen(consonants) == TWO ? name_code_B(code,consonants,vowels) :
	strlen(consonants) == ONE ? name_code_C(code,consonants,vowels) : name_code_D(code,vowels);
	code[THREE] = EOS;
	assert(is_valid_coded_surname_name(code));
}

static void surname_code_A(char code[], char consonants[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = consonants[ONE];
	code[TWO] = consonants[TWO];
}

static void surname_code_BA(char code[],char consonants[], char vowels[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = consonants[ONE];
	code[TWO] = vowels[ZERO];
}

static void surname_code_BB(char code[],char consonants[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = consonants[ONE];
	code[TWO] = X;
}

static void surname_code_B(char code[],char consonants[], char vowels[]){
	strlen(vowels) >= ONE ? surname_code_BA(code,consonants,vowels) :
			surname_code_BB(code,consonants);
}

static void surname_code_CA(char code[], char consonants[], char vowels[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = vowels[ZERO];
	code[TWO] = vowels[ONE];
}

static void surname_code_CB(char code[], char consonants[], char vowels[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = vowels[ZERO];
	code[TWO] = X;
}

static void surname_code_CC(char code[], char consonants[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = X;
	code[TWO] = X;
}

static void surname_code_C(char code[],	char consonants[], char vowels[]){
	strlen(vowels)>ONE?surname_code_CA(code,consonants,vowels):
	strlen(vowels)==ONE?surname_code_CB(code,consonants,vowels):surname_code_CC(code,consonants);
}

static void surname_code_DA(char code[], char vowels[]){
	code[ZERO] = vowels[ZERO];
	code[ONE] = vowels[ONE];
	code[TWO] = vowels[TWO];
}

static void surname_code_DB(char code[], char vowels[]){
	code[ZERO] = vowels[ZERO];
	code[ONE] = vowels[ONE];
	code[TWO] = X;
}

static void surname_code_DC(char code[], char vowels[]){
	code[ZERO] = vowels[ZERO];
	code[ONE] = X;
	code[TWO] = X;
}

static void surname_code_DD(char code[]){
	code[ZERO] = X;
	code[ONE] = X;
	code[TWO] = X;
}

static void surname_code_D(char code[], char vowels[]){
	strlen(vowels)>=THREE?surname_code_DA(code,vowels):
	strlen(vowels)==TWO?surname_code_DB(code,vowels):
	strlen(vowels)==ONE?surname_code_DC(code,vowels):surname_code_DD(code);
}

void surname_code(char surname[], char code[]){
	assert(is_valid_surname(surname));
	int length = strlen(surname);
	char consonants[length];
	char vowels[length];
	get_consonants_vowels(surname,vowels,consonants);
	strlen(consonants) >= THREE?surname_code_A(code,consonants):
	strlen(consonants) == TWO?surname_code_B(code,consonants,vowels):
	strlen(consonants) == ONE?surname_code_C(code,consonants,vowels):surname_code_D(code,vowels);
	code[THREE] = EOS;
	assert(is_valid_coded_surname_name(code));
}

static char month_0(char a){
	return (a == CHAR_1) ? A : (a == CHAR_2) ? B : (a == CHAR_3) ? C :
			(a == CHAR_4) ? D :	(a == CHAR_5) ? E : (a == CHAR_6) ? H :
			(a == CHAR_7) ? L : M;
}

static char month_1(char b){
	return (b == CHAR_0) ? R : (b == CHAR_1) ? S : T;
}

static char month(char a, char b){
	return a==CHAR_0?month_0(b):month_1(b);
}

static void birth_date_code_M(char date[], char code[]){
	code[ZERO] = date[EIGHT];
	code[ONE] = date[NINE];
	code[TWO] = month(date[THREE],date[FOUR]);
	code[THREE] = date[ZERO];
	code[FOUR] = date[ONE];
}

static void birth_date_code_F(char date[], char code[]){
	code[ZERO] = date[EIGHT];
	code[ONE] = date[NINE];
	code[TWO] = month(date[THREE],date[FOUR]);
	code[THREE] = date[ZERO];
	code[THREE] = code[THREE] + FOUR;
	code[FOUR] = date[ONE];
}

void birth_date_code(char date[], char sex, char code[]){
	assert(is_valid_date(date)&&is_valid_sex(sex));
	sex==M?birth_date_code_M(date,code):birth_date_code_F(date,code);
	code[FIVE] = EOS;
	assert(is_valid_date_code(code));
}

static int even_character(char a){
	return	(a == CHAR_0 || a == A) ? ONE: (a == CHAR_1 || a == B) ? ZERO : (a == CHAR_2 || a == C) ? FIVE :
			(a == CHAR_3 || a == D) ? SEVEN : (a == CHAR_4 || a == E) ? NINE :
			(a == CHAR_5 || a == F) ? THIRTEEN : (a == CHAR_6 || a==G) ? FIFTEEN :
		    (a==CHAR_7 || a==H) ? SEVENTEEN : (a==CHAR_8 || a == I) ? NINETEEN :
		    (a==CHAR_9 || a == J) ? TWENTYONE : (a == K) ? TWO : (a == L) ? FOUR : (a == M) ? EIGHTEEN :
			(a == N) ? TWENTY : (a == O) ? ELEVEN : (a == P) ? THREE : (a == Q) ? SIX : (a == R) ? EIGHT :
			(a == S) ? TWELVE : (a == T) ? FOURTEEN: (a == U) ? SIXTEEN : (a == V) ? TEN :
			(a == W) ? TWENTYTWO  : (a == X) ? TWENTYFIVE : (a == Y) ? TWENTYFOUR : TWENTYTHREE;
}

static int odd_character(char a){
	return (a == CHAR_0 || a == A) ? ZERO: (a == CHAR_1 || a == B) ? ONE : (a == CHAR_2 || a == C) ? TWO :
		(a == CHAR_3 || a == D) ? THREE : (a == CHAR_4 || a == E) ? FOUR : (a == CHAR_5 || a==F) ? FIVE :
		(a == CHAR_6 || a==G) ? SIX : (a==CHAR_7 || a==H) ? SEVEN : (a==CHAR_8 || a == I) ? EIGHT :
		(a==CHAR_9 || a == J) ? NINE : (a == K) ? TEN : (a == L) ? ELEVEN : (a == M) ? TWELVE :
		(a == N) ? THIRTEEN : (a == O) ? FOURTEEN : (a == P) ? FIFTEEN : (a == Q) ? SIXTEEN :
		(a == R) ? SEVENTEEN : (a == S) ? EIGHTEEN : (a == T) ? NINETEEN : (a == U) ? TWENTY :
	    (a == V) ? TWENTYONE : (a == W) ? TWENTYTWO  : (a == X) ? TWENTYTHREE : (a == Y) ? TWENTYFOUR :
	    TWENTYFIVE;
}

static char result(int number){
	return (number == ZERO) ? A : (number == ONE) ? B : (number == TWO) ? C : (number == THREE) ? D :
		   (number == FOUR) ? E : (number == FIVE) ? F : (number == SIX) ? G : (number == SEVEN) ? H :
		   (number == EIGHT) ? I : (number == NINE) ? J : (number == TEN) ? K : (number == ELEVEN) ? L :
		   (number == TWELVE) ? M : (number == THIRTEEN) ? N : (number == FOURTEEN) ? O :
		   (number == FIFTEEN) ? P : (number == SIXTEEN) ? Q : (number == SEVENTEEN) ? R :
		   (number == EIGHTEEN) ? S : (number == NINETEEN) ? T : (number == TWENTY) ? U :
		   (number == TWENTYONE) ? V : (number == TWENTYTWO) ? W : (number == TWENTYTHREE) ? X :
		   (number == TWENTYFOUR) ? Y : Z ;
}

static void code_strcat(char coded_name[],char coded_surname[],char coded_birth_date[],char coded_town[],char code[]){
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

char ctrl_code(char coded_name[], char coded_surname[],char coded_birth_date[], char coded_birth_place[]){
	assert(is_valid_coded_surname_name(coded_name));
	assert(is_valid_coded_surname_name(coded_surname));
	char code[FIFTEEN];
	code[ZERO]=EOS;
	code_strcat(coded_name, coded_surname,coded_birth_date, coded_birth_place,code);
	int sum = get_sum(code);
	assert(is_valid_ctrl_code(result(sum%TWENTYSIX)));
	return result(sum % TWENTYSIX);
}

void cf_generator(char name[], char surname[], char birth_date[], char coded_town[],char sex, char code[]){
	assert(is_valid_name(name)&&is_valid_surname(surname)&&is_valid_date(birth_date)&&is_valid_sex(sex));
	char coded_birth_date[SIX];
	char coded_surname[FOUR];
	char coded_name[FOUR];
	code[ZERO]=EOS;
	name_code(name,coded_name);
	surname_code(surname,coded_surname);
	birth_date_code(birth_date,sex,coded_birth_date);
	code_strcat(coded_name,coded_surname,coded_birth_date,coded_town,code);
	code[FIFTEEN] = ctrl_code(coded_name,coded_surname,coded_birth_date,coded_town);
	code[SIXTEEN]=EOS;
	assert(is_valid_cf_code(code));
}
