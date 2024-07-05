/* This file contains simpel unit tests for the pktime library
*
* Author: Josh McIntyre
*/
#include "pktime.h"
#include "calc.h"
#include "test_pktime.h"

// Test iteration calculations
int test_iterations()
{
	double avg_optime = average_optime_from_opssec(10000);
	double etimes[REAL_KEYSIZES_LENGTH];
	double eiterations[REAL_KEYSIZES_LENGTH];
	calc_esttimes(REAL_KEYSIZES, etimes, eiterations, REAL_KEYSIZES_LENGTH, avg_optime);
	
	int result = 0;
	for (int i = 0; i < REAL_KEYSIZES_LENGTH; i++)
	{
		if (eiterations[i] != pow(2, REAL_KEYSIZES[i]))
		{
			result = 1;
		}
	}
	
	printf("test_iterations result: %d\n", result);
	return result;
}

// The main entry point for the unit tests
int main(int argc, char* argv[])
{
	int tests = 1;
	int results[1];

	int res_iterations = test_iterations();
	results[0] = res_iterations;
	
	int tests_passed = 0;
	int tests_failed = 0;
	for (int i = 0; i < tests; i++)
	{
		if (results[i] == 0)
		{
			tests_passed++;
		}
		else
		{
			tests_failed++;
		}
	}
	
	printf("-----\n");
	printf("Tests passed: %d\n", tests_passed);
	printf("Tests failed: %d\n", tests_failed);
	
	return 0;
}