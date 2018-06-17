/*
 * cf_generator.c
 *
 *  Created on: 21 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "../../../src/print_result/cf_generator/cf_generator.h"

static bool is_vowel(char a){
	return a==A||a==E||a==I||a==O||a==U;
}

static bool is_consonant(char a){
	return !is_vowel(a)&&isalpha(a);
}

static void get_consonant(char* string, char* consonants, int i, int* k){
	if (is_consonant(string[i]))
		consonants[(*k)++] = string[i];
}

static void get_consonants(char* string, char* consonants){
	int k = ZERO;
	for (int i=ZERO;i<strlen(string);i++)
		get_consonant(string,consonants,i,&k);
	consonants[k] = EOS;
}

static void get_vowel(char* string, char* vowels, int i, int* k){
	if (is_vowel(string[i]))
		vowels[(*k)++] = string[i];
}

static void get_vowels(char* string, char* vowels){
	int k = ZERO;
	for (int i=ZERO;i<strlen(string);i++)
		get_vowel(string,vowels,i,&k);
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
	char result;
	switch(a){
	case CHAR_1: result=A; break;
	case CHAR_2: result=B; break;
	case CHAR_3: result=C; break;
	case CHAR_4: result=D; break;
	case CHAR_5: result=E; break;
	case CHAR_6: result=H; break;
	case CHAR_7: result=L; break;
	case CHAR_8: result=M; break;
	default: result=P;
	} return result;
}

static char month_1(char b){
	char result;
	switch(b){
	case CHAR_0: result=R; break;
	case CHAR_1: result=S; break;
	default: result=CHAR_2;
	} return result;
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
	char result;
	switch(a){
	case CHAR_0: result=ONE; break;
	case CHAR_1: result=ZERO; break;
	case CHAR_2: result=FIVE; break;
	case CHAR_3: result=SEVEN; break;
	case CHAR_4: result=NINE; break;
	case CHAR_5: result=THIRTEEN; break;
	case CHAR_6: result=FIFTEEN; break;
	case CHAR_7: result=SEVENTEEN; break;
	case CHAR_8: result=NINETEEN; break;
	case CHAR_9: result=TWENTYONE; break;
	case A: result=ONE; break;
	case B: result=ZERO; break;
	case C: result=FIVE; break;
	case D: result=SEVEN; break;
	case E: result=NINE; break;
	case F: result=THIRTEEN; break;
	case G: result=FIFTEEN; break;
	case H: result=SEVENTEEN; break;
	case I: result=NINETEEN; break;
	case J: result=TWENTYONE; break;
	case K: result=TWO; break;
	case L: result=FOUR; break;
	case M: result=EIGHTEEN; break;
	case N: result=TWENTY; break;
	case O: result=ELEVEN; break;
	case P: result=THREE; break;
	case Q: result=SIX; break;
	case R: result=EIGHT; break;
	case S: result=TWELVE; break;
	case T: result=FOURTEEN; break;
	case U: result=SIXTEEN; break;
	case V: result=TEN; break;
	case W: result=TWENTYTWO; break;
	case X: result=TWENTYFIVE; break;
	case Y: result=TWENTYFOUR; break;
	default: result=TWENTYTHREE;
	} return result;
}

static int odd_character(char a){
	char result;
	switch(a){
	case CHAR_0: result=ZERO; break;
	case CHAR_1: result=ONE; break;
	case CHAR_2: result=TWO; break;
	case CHAR_3: result=THREE; break;
	case CHAR_4: result=FOUR; break;
	case CHAR_5: result=FIVE; break;
	case CHAR_6: result=SIX; break;
	case CHAR_7: result=SEVEN; break;
	case CHAR_8: result=EIGHT; break;
	case CHAR_9: result=NINE; break;
	case A: result=ZERO; break;
	case B: result=ONE; break;
	case C: result=TWO; break;
	case D: result=THREE; break;
	case E: result=FOUR; break;
	case F: result=FIVE; break;
	case G: result=SIX; break;
	case H: result=SEVEN; break;
	case I: result=EIGHT; break;
	case J: result=NINE; break;
	case K: result=TEN; break;
	case L: result=ELEVEN; break;
	case M: result=TWELVE; break;
	case N: result=THIRTEEN; break;
	case O: result=FOURTEEN; break;
	case P: result=FIFTEEN; break;
	case Q: result=SIXTEEN; break;
	case R: result=SEVENTEEN; break;
	case S: result=EIGHTEEN; break;
	case T: result=NINETEEN; break;
	case U: result=TWENTY; break;
	case V: result=TWENTYONE; break;
	case W: result=TWENTYTWO; break;
	case X: result=TWENTYTHREE; break;
	case Y: result=TWENTYFOUR; break;
	default: result=TWENTYFIVE;
	} return result;
}

static char result(int number){
	char result;
	switch(number){
	case ZERO: result=A; break;
	case ONE: result=B; break;
	case TWO: result=C; break;
	case THREE: result=D; break;
	case FOUR: result=E; break;
	case FIVE: result=F; break;
	case SIX: result=G; break;
	case SEVEN: result=H; break;
	case EIGHT: result=I; break;
	case NINE: result=J; break;
	case TEN: result=K; break;
	case ELEVEN: result=L; break;
	case TWELVE: result=M; break;
	case THIRTEEN: result=N; break;
	case FOURTEEN: result=O; break;
	case FIFTEEN: result=P; break;
	case SIXTEEN: result=Q; break;
	case SEVENTEEN: result=R; break;
	case EIGHTEEN: result=S; break;
	case NINETEEN: result=T; break;
	case TWENTY: result=U; break;
	case TWENTYONE: result=V; break;
	case TWENTYTWO: result=W; break;
	case TWENTYTHREE: result=X; break;
	case TWENTYFOUR: result=Y; break;
	default: result=Z;
	} return result;
}

static void code_strcat(char coded_name[],char coded_surname[],char coded_birth_date[],char coded_town[],char code[]){
	strcat(code,coded_surname);
	strcat(code,coded_name);
	strcat(code,coded_birth_date);
	strcat(code,coded_town);
	code[strlen(code)]=EOS;
}

static void incr_number(char* code, int* number, int i){
	i%TWO==ZERO?((*number)+=even_character(code[i])):((*number)+=odd_character(code[i]));
}

static void get_number(char* code, int *number){
	for (int i=ZERO;i<strlen(code)-ONE;i++)
		incr_number(code,number,i);
}

char ctrl_code(char coded_name[], char coded_surname[],char coded_birth_date[], char coded_birth_place[]){
	assert(is_valid_coded_surname_name(coded_name));
	assert(is_valid_coded_surname_name(coded_surname));
	int number = ZERO;
	char code[FIFTEEN];
	code[ZERO]=EOS;
	code_strcat(coded_name, coded_surname,coded_birth_date, coded_birth_place,code);
	get_number(code,&number);
	assert(is_valid_ctrl_code(result(number%TWENTYSIX)));
	return result(number%TWENTYSIX);
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
