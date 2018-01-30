#include "tests.h"

//Creates a set of unit tests.
const struct CMUnitTest tests[] = {
    cmocka_unit_test(null_test_success),
    cmocka_unit_test(inverse_test_success),
};
    
int main(void){
	
	//returns the result of the tests
	return cmocka_run_group_tests(tests, NULL, NULL);
}
