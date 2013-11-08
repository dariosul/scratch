#include "CUnit/Basic.h"
#include "program.h"

void testAdd(void) {
	CU_ASSERT_EQUAL(add(1, 2), 3);
}

int main() {
	CU_pSuite pSuite = NULL;

	/* Initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) {
		return CU_get_error();
	}

	/* Add a suite to the registry */
	pSuite = CU_add_suite("Suite_1", NULL, NULL);
	if (pSuite == NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Add the tests to the suite */
	if (CU_add_test(pSuite, "Test add", testAdd) == NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit basic interface. */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
