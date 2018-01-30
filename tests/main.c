#include "tests.h"

//Creates a set of unit tests.
const struct CMUnitTest tests[] = {
    cmocka_unit_test(null_test_success),
    cmocka_unit_test(inverse_test_success),
};
    
int main(void) {
	
        int res;
	
	//calls the inverse_numbers
	inverse_numbers( 10, -10);
	
	//returns the result of the tests
	res = cmocka_run_group_tests(tests, NULL, NULL);
    
        free (answer);
        free (state);
	
        return res;
}
