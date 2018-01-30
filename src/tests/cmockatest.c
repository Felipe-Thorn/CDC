#include "tests.h"

/* A test case that does nothing and succeeds. */
void null_test_success(void **state) {

    (void) state; /* unused */
    
}

//Function that makes a plus b
int inverse_numbers(int a, int b){

     return a + b;

}

/* A test case that verifies if a is the inverse of b. */
void inverse_test_success(void **state) {

     int answer = inverse_numbers(10, -10);
         
     assert_int_equal(answer, 0);
   
}
