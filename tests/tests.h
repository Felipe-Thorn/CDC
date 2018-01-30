#ifndef TESTES_H_
#define TESTES_H_

//system libs
#include <stdio.h>
#include <stdlib.h>

//cmocka libs
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

//Declares the functions
int inverser_numbers(int a, int b);

//Declares the void tests
void null_test_success(void **state);
void inverse_test_success(void **state);

#endif
