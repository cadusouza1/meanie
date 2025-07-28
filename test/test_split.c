#include <criterion/criterion.h>
#include <string.h>

#include "../src/line.h"

Test(split, empty_buffer) {
    char buff[] = "";
    Splits *splits = split_buffer_by_tokens(buff, "", 1);

    cr_assert_not_null(splits);
    cr_assert_eq(splits->len, 0);
}

Test(split, basic_newline_split) {
    char buff[] = "1 2 3\n4 5 6";
    Splits *splits = split_buffer_by_tokens(buff, "\n", 2);
    char *expected_splits[] = {"1 2 3", "4 5 6"};

    cr_assert_not_null(splits);
    cr_assert_eq(splits->len, sizeof(expected_splits) / sizeof(char *));

    for (int i = 0; i < splits->len; i++) {
        cr_assert_str_eq(splits->splits[i], expected_splits[i]);
    }
}

Test(split, simple_separator_small_split_count_no_realloc) {
    char buff[] = "1+2+3+4+5+6+7+8+9+10+11+12+13+14+15+16";
    Splits *splits = split_buffer_by_tokens(buff, "+", strlen(buff));
    char *expected_splits[] = {"1", "2",  "3",  "4",  "5",  "6",  "7",  "8",
                               "9", "10", "11", "12", "13", "14", "15", "16"};

    cr_assert_not_null(splits);
    cr_assert_eq(splits->len, sizeof(expected_splits) / sizeof(char *));
    for (int i = 0; i < splits->len; i++) {
        cr_assert_str_eq(splits->splits[i], expected_splits[i]);
    }
}

Test(split, simple_separator_small_split_count_with_realloc) {
    char buff[] = "1+2+3+4+5+6+7+8+9+10+11+12+13+14+15+16";
    Splits *splits = split_buffer_by_tokens(buff, "+", 1);
    char *expected_splits[] = {"1", "2",  "3",  "4",  "5",  "6",  "7",  "8",
                               "9", "10", "11", "12", "13", "14", "15", "16"};

    cr_assert_not_null(splits);
    cr_assert_eq(splits->len, sizeof(expected_splits) / sizeof(char *));
    for (int i = 0; i < splits->len; i++) {
        cr_assert_str_eq(splits->splits[i], expected_splits[i]);
    }
}

Test(split, simple_separator_big_split_count_no_realloc) {
    char buff[] =
        "1+2+3+4+5+6+7+8+9+10+11+12+13+14+15+16+17+18+19+20+21+22+23+24+25+26+"
        "27+28+29+30+31+32+33+34+35+36+37+38+39+40+41+42+43+44+45+46+47+48+49+"
        "50+51+52+53+54+55+56+57+58+59+60+61+62+63+64+65+66+67+68+69+70+71+72+"
        "73+74+75+76+77+78+79+80+81+82+83+84+85+86+87+88+89+90+91+92+93+94+95+"
        "96+97+98+99+100+101+102+103+104+105+106+107+108+109+110+111+112+113+"
        "114+115+116+117+118+119+120+121+122+123+124+125+126+127+128";
    Splits *splits = split_buffer_by_tokens(buff, "+", strlen(buff));
    char *expected_splits[] = {
        "1",   "2",   "3",   "4",   "5",   "6",   "7",   "8",   "9",   "10",
        "11",  "12",  "13",  "14",  "15",  "16",  "17",  "18",  "19",  "20",
        "21",  "22",  "23",  "24",  "25",  "26",  "27",  "28",  "29",  "30",
        "31",  "32",  "33",  "34",  "35",  "36",  "37",  "38",  "39",  "40",
        "41",  "42",  "43",  "44",  "45",  "46",  "47",  "48",  "49",  "50",
        "51",  "52",  "53",  "54",  "55",  "56",  "57",  "58",  "59",  "60",
        "61",  "62",  "63",  "64",  "65",  "66",  "67",  "68",  "69",  "70",
        "71",  "72",  "73",  "74",  "75",  "76",  "77",  "78",  "79",  "80",
        "81",  "82",  "83",  "84",  "85",  "86",  "87",  "88",  "89",  "90",
        "91",  "92",  "93",  "94",  "95",  "96",  "97",  "98",  "99",  "100",
        "101", "102", "103", "104", "105", "106", "107", "108", "109", "110",
        "111", "112", "113", "114", "115", "116", "117", "118", "119", "120",
        "121", "122", "123", "124", "125", "126", "127", "128"};

    cr_assert_not_null(splits);
    cr_assert_eq(splits->len, sizeof(expected_splits) / sizeof(char *));
    for (int i = 0; i < splits->len; i++) {
        cr_assert_str_eq(splits->splits[i], expected_splits[i]);
    }
}

Test(split, simple_separator_big_split_count_with_realloc) {
    char buff[] =
        "1+2+3+4+5+6+7+8+9+10+11+12+13+14+15+16+17+18+19+20+21+22+23+24+25+26+"
        "27+28+29+30+31+32+33+34+35+36+37+38+39+40+41+42+43+44+45+46+47+48+49+"
        "50+51+52+53+54+55+56+57+58+59+60+61+62+63+64+65+66+67+68+69+70+71+72+"
        "73+74+75+76+77+78+79+80+81+82+83+84+85+86+87+88+89+90+91+92+93+94+95+"
        "96+97+98+99+100+101+102+103+104+105+106+107+108+109+110+111+112+113+"
        "114+115+116+117+118+119+120+121+122+123+124+125+126+127+128";
    Splits *splits = split_buffer_by_tokens(buff, "+", 1);
    char *expected_splits[] = {
        "1",   "2",   "3",   "4",   "5",   "6",   "7",   "8",   "9",   "10",
        "11",  "12",  "13",  "14",  "15",  "16",  "17",  "18",  "19",  "20",
        "21",  "22",  "23",  "24",  "25",  "26",  "27",  "28",  "29",  "30",
        "31",  "32",  "33",  "34",  "35",  "36",  "37",  "38",  "39",  "40",
        "41",  "42",  "43",  "44",  "45",  "46",  "47",  "48",  "49",  "50",
        "51",  "52",  "53",  "54",  "55",  "56",  "57",  "58",  "59",  "60",
        "61",  "62",  "63",  "64",  "65",  "66",  "67",  "68",  "69",  "70",
        "71",  "72",  "73",  "74",  "75",  "76",  "77",  "78",  "79",  "80",
        "81",  "82",  "83",  "84",  "85",  "86",  "87",  "88",  "89",  "90",
        "91",  "92",  "93",  "94",  "95",  "96",  "97",  "98",  "99",  "100",
        "101", "102", "103", "104", "105", "106", "107", "108", "109", "110",
        "111", "112", "113", "114", "115", "116", "117", "118", "119", "120",
        "121", "122", "123", "124", "125", "126", "127", "128"};

    cr_assert_not_null(splits);
    cr_assert_eq(splits->len, sizeof(expected_splits) / sizeof(char *));
    for (int i = 0; i < splits->len; i++) {
        cr_assert_str_eq(splits->splits[i], expected_splits[i]);
    }
}

Test(split, composite_separator_small_split_count_no_realloc) {
    char buff[] =
        "1sep2sep3sep4sep5sep6sep7sep8sep9sep10sep11sep12sep13sep14sep15sep16";
    Splits *splits = split_buffer_by_tokens(buff, "sep", strlen(buff));
    char *expected_splits[] = {"1", "2",  "3",  "4",  "5",  "6",  "7",  "8",
                               "9", "10", "11", "12", "13", "14", "15", "16"};

    cr_assert_not_null(splits);
    cr_assert_eq(splits->len, sizeof(expected_splits) / sizeof(char *));
    for (int i = 0; i < splits->len; i++) {
        cr_assert_str_eq(splits->splits[i], expected_splits[i]);
    }
}

Test(split, composite_separator_small_split_count_with_realloc) {
    char buff[] =
        "1sep2sep3sep4sep5sep6sep7sep8sep9sep10sep11sep12sep13sep14sep15sep16";
    Splits *splits = split_buffer_by_tokens(buff, "sep", 1);
    char *expected_splits[] = {"1", "2",  "3",  "4",  "5",  "6",  "7",  "8",
                               "9", "10", "11", "12", "13", "14", "15", "16"};

    cr_assert_not_null(splits);
    cr_assert_eq(splits->len, sizeof(expected_splits) / sizeof(char *));
    for (int i = 0; i < splits->len; i++) {
        cr_assert_str_eq(splits->splits[i], expected_splits[i]);
    }
}

Test(split, composite_separator_big_split_count_no_realloc) {
    char buff[] =
        "1sep2sep3sep4sep5sep6sep7sep8sep9sep10sep11sep12sep13sep14sep15sep16se"
        "p17sep18sep19sep20sep21sep22sep23sep24sep25sep26sep27sep28sep29sep30se"
        "p31sep32sep33sep34sep35sep36sep37sep38sep39sep40sep41sep42sep43sep44se"
        "p45sep46sep47sep48sep49sep50sep51sep52sep53sep54sep55sep56sep57sep58se"
        "p59sep60sep61sep62sep63sep64sep65sep66sep67sep68sep69sep70sep71sep72se"
        "p73sep74sep75sep76sep77sep78sep79sep80sep81sep82sep83sep84sep85sep86se"
        "p87sep88sep89sep90sep91sep92sep93sep94sep95sep96sep97sep98sep99sep100s"
        "ep101sep102sep103sep104sep105sep106sep107sep108sep109sep110sep111sep11"
        "2sep113sep114sep115sep116sep117sep118sep119sep120sep121sep122sep123sep"
        "124sep125sep126sep127sep128";

    Splits *splits = split_buffer_by_tokens(buff, "sep", strlen(buff));
    char *expected_splits[] = {
        "1",   "2",   "3",   "4",   "5",   "6",   "7",   "8",   "9",   "10",
        "11",  "12",  "13",  "14",  "15",  "16",  "17",  "18",  "19",  "20",
        "21",  "22",  "23",  "24",  "25",  "26",  "27",  "28",  "29",  "30",
        "31",  "32",  "33",  "34",  "35",  "36",  "37",  "38",  "39",  "40",
        "41",  "42",  "43",  "44",  "45",  "46",  "47",  "48",  "49",  "50",
        "51",  "52",  "53",  "54",  "55",  "56",  "57",  "58",  "59",  "60",
        "61",  "62",  "63",  "64",  "65",  "66",  "67",  "68",  "69",  "70",
        "71",  "72",  "73",  "74",  "75",  "76",  "77",  "78",  "79",  "80",
        "81",  "82",  "83",  "84",  "85",  "86",  "87",  "88",  "89",  "90",
        "91",  "92",  "93",  "94",  "95",  "96",  "97",  "98",  "99",  "100",
        "101", "102", "103", "104", "105", "106", "107", "108", "109", "110",
        "111", "112", "113", "114", "115", "116", "117", "118", "119", "120",
        "121", "122", "123", "124", "125", "126", "127", "128"};

    cr_assert_not_null(splits);
    cr_assert_eq(splits->len, sizeof(expected_splits) / sizeof(char *));
    for (int i = 0; i < splits->len; i++) {
        cr_assert_str_eq(splits->splits[i], expected_splits[i]);
    }
}
Test(split, composite_separator_big_split_count_with_realloc) {
    char buff[] =
        "1sep2sep3sep4sep5sep6sep7sep8sep9sep10sep11sep12sep13sep14sep15sep16se"
        "p17sep18sep19sep20sep21sep22sep23sep24sep25sep26sep27sep28sep29sep30se"
        "p31sep32sep33sep34sep35sep36sep37sep38sep39sep40sep41sep42sep43sep44se"
        "p45sep46sep47sep48sep49sep50sep51sep52sep53sep54sep55sep56sep57sep58se"
        "p59sep60sep61sep62sep63sep64sep65sep66sep67sep68sep69sep70sep71sep72se"
        "p73sep74sep75sep76sep77sep78sep79sep80sep81sep82sep83sep84sep85sep86se"
        "p87sep88sep89sep90sep91sep92sep93sep94sep95sep96sep97sep98sep99sep100s"
        "ep101sep102sep103sep104sep105sep106sep107sep108sep109sep110sep111sep11"
        "2sep113sep114sep115sep116sep117sep118sep119sep120sep121sep122sep123sep"
        "124sep125sep126sep127sep128";

    Splits *splits = split_buffer_by_tokens(buff, "sep", 1);
    char *expected_splits[] = {
        "1",   "2",   "3",   "4",   "5",   "6",   "7",   "8",   "9",   "10",
        "11",  "12",  "13",  "14",  "15",  "16",  "17",  "18",  "19",  "20",
        "21",  "22",  "23",  "24",  "25",  "26",  "27",  "28",  "29",  "30",
        "31",  "32",  "33",  "34",  "35",  "36",  "37",  "38",  "39",  "40",
        "41",  "42",  "43",  "44",  "45",  "46",  "47",  "48",  "49",  "50",
        "51",  "52",  "53",  "54",  "55",  "56",  "57",  "58",  "59",  "60",
        "61",  "62",  "63",  "64",  "65",  "66",  "67",  "68",  "69",  "70",
        "71",  "72",  "73",  "74",  "75",  "76",  "77",  "78",  "79",  "80",
        "81",  "82",  "83",  "84",  "85",  "86",  "87",  "88",  "89",  "90",
        "91",  "92",  "93",  "94",  "95",  "96",  "97",  "98",  "99",  "100",
        "101", "102", "103", "104", "105", "106", "107", "108", "109", "110",
        "111", "112", "113", "114", "115", "116", "117", "118", "119", "120",
        "121", "122", "123", "124", "125", "126", "127", "128"};

    cr_assert_not_null(splits);
    cr_assert_eq(splits->len, sizeof(expected_splits) / sizeof(char *));
    for (int i = 0; i < splits->len; i++) {
        cr_assert_str_eq(splits->splits[i], expected_splits[i]);
    }
}
