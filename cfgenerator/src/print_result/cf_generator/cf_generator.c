/*
 * cf_generator.c
 *
 *  Created on: 21 ago 2017
 *      Author: Gabriele Fortunato
 */

#include <print_result/cf_generator/cf_generator.h>

static bool is_vowel(char a){
	return a==A||a==E||a==I||a==O||a==U;
}

static bool is_consonant(char a){
	return !is_vowel(a)&&isalpha(a);
}

static void get_vowel(char* string, char* vowels, int i, int* k){
	if (is_vowel(string[i]))
			vowels[(*k)++] = string[i];
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

static void name_code_BA(char code[],char consonants[],
		char vowels[]){
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

static void name_code_CA(char code[],char consonants[],
		char vowels[]){
	code[ZERO] = consonants[ZERO];
	code[ONE] = vowels[ZERO];
	code[TWO] = vowels[ONE];
}

static void name_code_CB(char code[],char consonants[],
		char vowels[]){
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
	strlen(consonants) >= THREE?name_code_A(code,consonants):
			strlen(consonants) == TWO?name_code_B(code,consonants,vowels):
					strlen(consonants) == ONE?name_code_C(code,consonants,vowels):name_code_D(code,vowels);
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
	strlen(vowels)>=ONE?surname_code_BA(code,consonants,vowels):surname_code_BB(code,consonants);
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
	switch(a){
	case CHAR_1: return A; break;
	case CHAR_2: return B; break;
	case CHAR_3: return C; break;
	case CHAR_4: return D; break;
	case CHAR_5: return E; break;
	case CHAR_6: return H; break;
	case CHAR_7: return L; break;
	case CHAR_8: return M; break;
	default: return CHAR_9;
	}
}

static char month_1(char b){
	switch(b){
	case CHAR_0: return R; break;
	case CHAR_1: return S; break;
	default: return CHAR_2;
	}
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
	sex==M?birth_date_code_M(date,code):birth_date_code_F(date,code);;
	code[FIVE] = EOS;
	assert(is_valid_date_code(code));
}

static int even_character(char a){
	switch(a){
	case CHAR_0: return ONE; break;
	case CHAR_1: return ZERO; break;
	case CHAR_2: return FIVE; break;
	case CHAR_3: return SEVEN; break;
	case CHAR_4: return NINE; break;
	case CHAR_5: return THIRTEEN; break;
	case CHAR_6: return FIFTEEN; break;
	case CHAR_7: return SEVENTEEN; break;
	case CHAR_8: return NINETEEN; break;
	case CHAR_9: return TWENTYONE; break;
	case A: return ONE; break;
	case B: return ZERO; break;
	case C: return FIVE; break;
	case D: return SEVEN; break;
	case E: return NINE; break;
	case F: return THIRTEEN; break;
	case G: return FIFTEEN; break;
	case H: return SEVENTEEN; break;
	case I: return NINETEEN; break;
	case J: return TWENTYONE; break;
	case K: return TWO; break;
	case L: return FOUR; break;
	case M: return EIGHTEEN; break;
	case N: return TWENTY; break;
	case O: return ELEVEN; break;
	case P: return THREE; break;
	case Q: return SIX; break;
	case R: return EIGHT; break;
	case S: return TWELVE; break;
	case T: return FOURTEEN; break;
	case U: return SIXTEEN; break;
	case V: return TEN; break;
	case W: return TWENTYTWO; break;
	case X: return TWENTYFIVE; break;
	case Y: return TWENTYFOUR; break;
	default: return TWENTYTHREE;
	}
}

static int odd_character(char a){
	switch(a){
	case CHAR_0: return ZERO; break;
	case CHAR_1: return ONE; break;
	case CHAR_2: return TWO; break;
	case CHAR_3: return THREE; break;
	case CHAR_4: return FOUR; break;
	case CHAR_5: return FIVE; break;
	case CHAR_6: return SIX; break;
	case CHAR_7: return SEVEN; break;
	case CHAR_8: return EIGHT; break;
	case CHAR_9: return NINE; break;
	case A: return ZERO; break;
	case B: return ONE; break;
	case C: return TWO; break;
	case D: return THREE; break;
	case E: return FOUR; break;
	case F: return FIVE; break;
	case G: return SIX; break;
	case H: return SEVEN; break;
	case I: return EIGHT; break;
	case J: return NINE; break;
	case K: return TEN; break;
	case L: return ELEVEN; break;
	case M: return TWELVE; break;
	case N: return THIRTEEN; break;
	case O: return FOURTEEN; break;
	case P: return FIFTEEN; break;
	case Q: return SIXTEEN; break;
	case R: return SEVENTEEN; break;
	case S: return EIGHTEEN; break;
	case T: return NINETEEN; break;
	case U: return TWENTY; break;
	case V: return TWENTYONE; break;
	case W: return TWENTYTWO; break;
	case X: return TWENTYTHREE; break;
	case Y: return TWENTYFOUR; break;
	default: return TWENTYFIVE;
	}
}

static char result(int number){
	switch(number){
	case ZERO: return A; break;
	case ONE: return B; break;
	case TWO: return C; break;
	case THREE: return D; break;
	case FOUR: return E; break;
	case FIVE: return F; break;
	case SIX: return G; break;
	case SEVEN: return H; break;
	case EIGHT: return I; break;
	case NINE: return J; break;
	case TEN:return K; break;
	case ELEVEN: return L; break;
	case TWELVE: return M; break;
	case THIRTEEN: return N; break;
	case FOURTEEN: return O; break;
	case FIFTEEN: return P; break;
	case SIXTEEN: return Q; break;
	case SEVENTEEN: return R; break;
	case EIGHTEEN: return S; break;
	case NINETEEN: return T; break;
	case TWENTY: return U; break;
	case TWENTYONE: return V; break;
	case TWENTYTWO: return W; break;
	case TWENTYTHREE: return X; break;
	case TWENTYFOUR: return Y; break;
	default: return Z;
	}
}

static void string_for_ctrl_code(char coded_name[], char coded_surname[],char coded_birth_date[], char coded_birth_place[], char code[]){
	strcat(code,coded_surname);
	strcat(code,coded_name);
	strcat(code,coded_birth_date);
	strcat(code,coded_birth_place);
	code[strlen(code)]=EOS;
}

static void incr_number(char* code, int* number, int i){
	i%TWO==ZERO?((*number)+= even_character(code[i])):((*number) += odd_character(code[i]));
}

static void get_number(char* code, int *number){
	for (int i=ZERO;i<strlen(code)-ONE;i++)
		incr_number(code,number,i);
}

char ctrl_code(char coded_name[], char coded_surname[],char coded_birth_date[], char coded_birth_place[]){
	assert(is_valid_coded_surname_name(coded_name)&&is_valid_coded_surname_name(coded_surname));
	int number = ZERO;
	char code[FIFTEEN];
	code[ZERO]=EOS;
	string_for_ctrl_code(coded_name, coded_surname,coded_birth_date, coded_birth_place,code);
	get_number(code,&number);
	assert(is_valid_ctrl_code(result(number%TWENTYSIX)));
	return result(number%TWENTYSIX);
}

static void code_strcat(char coded_name[],char coded_surname[],char coded_birth_date[],char coded_town[],char code[]){
	strcat(code,coded_surname);
	strcat(code,coded_name);
	strcat(code,coded_birth_date);
	strcat(code,coded_town);
}

void cf_generator(char name[], char surname[], char birth_date[], char coded_town[],char sex, char code[]){
	assert(is_valid_name(name)&&is_valid_surname(surname)&&is_valid_date(birth_date)&&is_valid_sex(sex));
	code[ZERO]=EOS;
	char coded_birth_date[SIX];
	char coded_surname[FOUR];
	char coded_name[FOUR];
	name_code(name,coded_name);
	surname_code(surname,coded_surname);
	birth_date_code(birth_date,sex,coded_birth_date);
	code_strcat(coded_name,coded_surname,coded_birth_date,coded_town,code);
	code[FIFTEEN] = ctrl_code (coded_name,coded_surname,coded_birth_date,coded_town);
	code[SIXTEEN]=EOS;
	assert(is_valid_cf_code(code));
}
