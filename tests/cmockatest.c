#include "tests.h"

/* A test case that does nothing and succeeds. */
void null_test_success(void **state) {

    (void) state; /* unused */
    
}

//Function that makes a plus b
int inverse_numbers(int a, int b, void **state){

	 int *answer = malloc(sizeof(int));
     if (!*answer) {
         return -1;
     }

     *answer = a + b;
     *state = answer;

     return 0;

}

/* A test case that verifies if a is the inverse of b. */
void inverse_test_success(void **state) {

     int *answer = *state;
         
     assert_int_equal(answer, 0);
   
}
