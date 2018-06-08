/*
 ============================================================================
 Name        : cfgenerator_test.c
 Author      : Gabriele Fortunato
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <CUnit/basic.h>

#include "../../cfgenerator/src/print_result/cf_generator/cf_generator.h"
#include "../../cfgenerator/src/print_result/is_valid/is_valid.h"
#include "../../cfgenerator/src/print_result/read_birth_place/read_birth_place.h"
#include "../../cfgenerator/src/get_data/to_upper/to_upper.h"

void test_read_birth_place(){
	FILE* file = fopen(FILE_NAME,FILE_MODE);
	CU_ASSERT_STRING_EQUAL(read_birth_place_code(file,"BARI"),"A662");
	CU_ASSERT_STRING_EQUAL(read_birth_place_code(file,"MOLA DI BARI"),"F280");
	CU_ASSERT_STRING_EQUAL(read_birth_place_code(file,"ROMA"),"H501");
	CU_ASSERT_STRING_EQUAL(read_birth_place_code(file,"MILANO"),"F205");
	CU_ASSERT_STRING_EQUAL(read_birth_place_code(file,"FIRENZE"),"D612");
	CU_ASSERT_STRING_EQUAL(read_birth_place_code(file,"NAPOLI"),"F839");
	CU_ASSERT_STRING_EQUAL(read_birth_place_code(file,"SANGIANO"),"H872");
	fclose(file);
}

void test_to_upper_string(){
	char string[]="Gabriele";
	to_upper_string(string);
	CU_ASSERT_STRING_EQUAL(string,"GABRIELE");
	char string1[]="Fortunato";
	to_upper_string(string1);
	CU_ASSERT_STRING_EQUAL(string1,"FORTUNATO");
}

void test_coded_name(){
	char code[FOUR];
	name_code("GABRIELE",code);
	CU_ASSERT_STRING_EQUAL(code,"GRL");
	name_code("DARIO",code);
	CU_ASSERT_STRING_EQUAL(code,"DRA");
	name_code("PAOLO",code);
	CU_ASSERT_STRING_EQUAL(code,"PLA");
	name_code("LUIGI",code);
	CU_ASSERT_STRING_EQUAL(code,"LGU");
	name_code("FRANCESCO",code);
	CU_ASSERT_STRING_EQUAL(code,"FNC");
	name_code("MARCO",code);
	CU_ASSERT_STRING_EQUAL(code,"MRC");
	name_code("MARIO",code);
	CU_ASSERT_STRING_EQUAL(code,"MRA");
	name_code("ANNA MARIA",code);
	CU_ASSERT_STRING_EQUAL(code,"NMR");
	name_code("VITTORIO EMANUELE",code);
	CU_ASSERT_STRING_EQUAL(code,"VTR");
	name_code("CARLO ALBERTO",code);
	CU_ASSERT_STRING_EQUAL(code,"CLL");
	name_code("ANDREA",code);
	CU_ASSERT_STRING_EQUAL(code,"NDR");
}

void test_is_valid_name(){
	CU_ASSERT_TRUE(is_valid_name("GABRIELE"));
	CU_ASSERT_TRUE(is_valid_name("MARC'AURELIO"));
	CU_ASSERT_TRUE(is_valid_name("ANNA MARIA"));
	CU_ASSERT_FALSE(is_valid_name("Anna Maria"));
	CU_ASSERT_FALSE(is_valid_name("Anna maria"));
	CU_ASSERT_FALSE(is_valid_name("Annamaria"));
	CU_ASSERT_FALSE(is_valid_name(""));
}

void test_is_valid_surname(){
	CU_ASSERT_TRUE(is_valid_surname("FORTUNATO"));
	CU_ASSERT_TRUE(is_valid_surname("DE ROSSI"));
	CU_ASSERT_TRUE(is_valid_surname("D'AMATO"));
	CU_ASSERT_FALSE(is_valid_surname("D'amato"));
	CU_ASSERT_FALSE(is_valid_surname(""));
}

void test_is_valid_date(){
	CU_ASSERT_FALSE(is_valid_date("02/10/2019"));
	CU_ASSERT_FALSE(is_valid_date("02/10/1"));
	CU_ASSERT_FALSE(is_valid_date("02/10/198"));
	CU_ASSERT_TRUE(is_valid_date("02/10/1978"));
	CU_ASSERT_FALSE(is_valid_date("02/13/1978"));
	CU_ASSERT_FALSE(is_valid_date("32/12/1978"));
}

void test_is_valid_code_date(){
	CU_ASSERT_FALSE(is_valid_date_code("78R02A"));
	CU_ASSERT_FALSE(is_valid_date_code("78R0"));
	CU_ASSERT_FALSE(is_valid_date_code("78r02"));
	CU_ASSERT_FALSE(is_valid_date_code("A8R02"));
	CU_ASSERT_FALSE(is_valid_date_code("7AR02"));
	CU_ASSERT_FALSE(is_valid_date_code("78R0A"));
	CU_ASSERT_FALSE(is_valid_date_code("78RA2"));
	CU_ASSERT_TRUE(is_valid_date_code("78R02"));
}

void test_is_valid_town_code(){
	CU_ASSERT_TRUE(is_valid_town_code("A662"));
	CU_ASSERT_TRUE(!is_valid_town_code("A662A"));
	CU_ASSERT_TRUE(!is_valid_town_code("a662"));
	CU_ASSERT_TRUE(!is_valid_town_code("AA62"));
	CU_ASSERT_TRUE(!is_valid_town_code("A6A2"));
	CU_ASSERT_TRUE(!is_valid_town_code("A66A"));
}

void test_is_valid_cf_code(){
	CU_ASSERT_FALSE(is_valid_cf_code("FRTGRL78R02F280W1"));
	CU_ASSERT_FALSE(is_valid_cf_code("FrTGRL78R02F280W"));
	CU_ASSERT_TRUE(is_valid_cf_code("FRTGRL78R02F280W"));
	CU_ASSERT_FALSE(is_valid_cf_code("FRTGR7L8R02F280W"));
}

void test_is_valid_ctrl_code(){
	CU_ASSERT_TRUE(is_valid_ctrl_code('X'));
	CU_ASSERT_TRUE(is_valid_ctrl_code('Y'));
	CU_ASSERT_FALSE(is_valid_ctrl_code('x'));
	CU_ASSERT_FALSE(is_valid_ctrl_code('y'));
	CU_ASSERT_FALSE(is_valid_ctrl_code('1'));
	CU_ASSERT_FALSE(is_valid_ctrl_code('9'));
	CU_ASSERT_FALSE(is_valid_ctrl_code('\''));
}

void test_coded_surname(){
	char code[FOUR];
	surname_code("FORTUNATO",code);
	CU_ASSERT_STRING_EQUAL(code,"FRT");
	surname_code("FO",code);
	CU_ASSERT_STRING_EQUAL(code,"FOX");
	surname_code("FOX",code);
	CU_ASSERT_STRING_EQUAL(code,"FXO");
	surname_code("D'AMBROSIO",code);
	CU_ASSERT_STRING_EQUAL(code,"DMB");
	surname_code("BUONO",code);
	CU_ASSERT_STRING_EQUAL(code,"BNU");
	surname_code("DI CHIO",code);
	CU_ASSERT_STRING_EQUAL(code,"DCH");
	surname_code("RIVA",code);
	CU_ASSERT_STRING_EQUAL(code,"RVI");
	surname_code("DEL DEBBIO",code);
	CU_ASSERT_STRING_EQUAL(code,"DLD");
	surname_code("PIO",code);
	CU_ASSERT_STRING_EQUAL(code,"PIO");
}

void test_coded_date(){
	char code[SIX];
	birth_date_code("02/10/1978",'M',code);
	CU_ASSERT_STRING_EQUAL(code,"78R02");
	birth_date_code("02/10/1978",'F',code);
	CU_ASSERT_STRING_EQUAL(code,"78R42");
	birth_date_code("15/04/1951",'M',code);
	CU_ASSERT_STRING_EQUAL(code,"51D15");
	birth_date_code("17/03/1953",'F',code);
	CU_ASSERT_STRING_EQUAL(code,"53C57");
	birth_date_code("21/11/1920",'F',code);
	CU_ASSERT_STRING_EQUAL(code,"20S61");
	birth_date_code("21/11/1911",'M',code);
	CU_ASSERT_STRING_EQUAL(code,"11S21");
	birth_date_code("21/11/2011",'M',code);
	CU_ASSERT_STRING_EQUAL(code,"11S21");
}

void test_ctrl_code(){
	CU_ASSERT_EQUAL(ctrl_code("GRL","FRT","78R02","F280"),'W');
	CU_ASSERT_EQUAL(ctrl_code("FNC","FRT","51D15","A662"),'C');
	CU_ASSERT_EQUAL(ctrl_code("NNA","DNI","20S61","A662"),'R');
	CU_ASSERT_EQUAL(ctrl_code("NNA","MNN","75E57","A662"),'H');
	CU_ASSERT_EQUAL(ctrl_code("NAA","MNN","75E57","A662"),'O');
}

void test_cf_generator(){
	char code[SEVENTEEN];
	cf_generator("GABRIELE","FORTUNATO","02/10/1978","F280",'M',code);
	CU_ASSERT_STRING_EQUAL(code,"FRTGRL78R02F280W");
	cf_generator("ANNA","MONNO","17/05/1975","A662",'F',code);
	CU_ASSERT_STRING_EQUAL(code,"MNNNNA75E57A662H");
	cf_generator("ANA","MONNO","17/05/1975","A662",'F',code);
	CU_ASSERT_STRING_EQUAL(code,"MNNNAA75E57A662O");
	cf_generator("ANNA","DIANA","21/11/1920","A662",'F',code);
	CU_ASSERT_STRING_EQUAL(code,"DNINNA20S61A662R");
	cf_generator("FRANCESCO","FORTUNATO","15/04/1951","A662",'M',code);
	CU_ASSERT_STRING_EQUAL(code,"FRTFNC51D15A662C");
}

int init_suite_default(){
	return ZERO;
}

int clear_suite_default(){
	return ZERO;
}

int main(void) {
	CU_initialize_registry();
	CU_pSuite pSuite_A = CU_add_suite("IS VALID",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_A,"test of is_valid_name()",test_is_valid_name);
	CU_add_test(pSuite_A,"test of is_valid_surname()",test_is_valid_surname);
	CU_add_test(pSuite_A,"test of is_valid_date()",test_is_valid_date);
	CU_add_test(pSuite_A,"test of is_valid_ctrl_code()",test_is_valid_ctrl_code);
	CU_add_test(pSuite_A,"test of is_valid_cf_code()",test_is_valid_cf_code);
	CU_add_test(pSuite_A,"test of is_valid_date_code()",test_is_valid_code_date);
	CU_add_test(pSuite_A,"test of is_valid_town_code()",test_is_valid_town_code);
	CU_pSuite pSuite_B = CU_add_suite("SUITE TO UPPER STRING",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_B,"test of to_upper_string()",test_to_upper_string);
	CU_pSuite pSuite_C = CU_add_suite("SUITE READ BIRTH PLACE",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_C,"test of read_birth_place()",test_read_birth_place);
	CU_pSuite pSuite_D = CU_add_suite("SUITE PARTIAL CFGENERATOR",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_D,"test of coded_name()",test_coded_name);
	CU_add_test(pSuite_D,"test of coded_surname()",test_coded_surname);
	CU_add_test(pSuite_D,"test of coded_birth_date()",test_coded_date);
	CU_add_test(pSuite_D,"test of ctrl_code()",test_ctrl_code);
	CU_pSuite pSuite_E = CU_add_suite("SUITE TOTAL CFGENERATOR",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_E,"test of cf_generator()",test_cf_generator);
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
