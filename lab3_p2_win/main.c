/* SYSC 2006 Lab 3, Part 2 Test Harness.
 *
 * DO NOT MODIFY THIS FILE!
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sput.h"
#include "composition.h"
#include "recursion.h"

#define PI 3.14159265358979323846

#pragma warn(disable: 2130 2154)

static void test_factorial(void)
{
    sput_fail_unless(factorial(0) == 1, "factorial(0)");
    printf("Expected result: 1, actual result: %d\n", factorial(0));
    sput_fail_unless(factorial(1) == 1, "factorial(1)");
    printf("Expected result: 1, actual result: %d\n", factorial(1));
    sput_fail_unless(factorial(2) == 2, "factorial(2)");
    printf("Expected result: 2, actual result: %d\n", factorial(2));
    sput_fail_unless(factorial(3) == 6, "factorial(3)");
    printf("Expected result: 6, actual result: %d\n", factorial(3));
    sput_fail_unless(factorial(4) == 24, "factorial(4)");
    printf("Expected result: 24, actual result: %d\n", factorial(4));
}

static void test_ordered_subsets(void)
{
    sput_fail_unless(ordered_subsets(5, 1) == 5, "ordered_subsets(5, 1)");
    printf("Expected result: 5, actual result: %d\n", ordered_subsets(5, 1));
    sput_fail_unless(ordered_subsets(5, 2) == 20, "ordered_subsets(5, 2)");
    printf("Expected result: 20, actual result: %d\n", ordered_subsets(5, 2));
    sput_fail_unless(ordered_subsets(5, 3) == 60, "ordered_subsets(5, 3)");
    printf("Expected result: 60, actual result: %d\n", ordered_subsets(5, 3));
    sput_fail_unless(ordered_subsets(5, 4) == 120, "ordered_subsets(5, 4)");
    printf("Expected result: 120, actual result: %d\n", ordered_subsets(5, 4));
    sput_fail_unless(ordered_subsets(5, 5) == 120, "ordered_subsets(5, 5)");
    printf("Expected result: 120, actual result: %d\n", ordered_subsets(5, 5));
}

static void test_binomial(void)
{
    sput_fail_unless(binomial(5, 1) == 5, "binomial(5, 1)");
    printf("Expected result: 5, actual result: %d\n", binomial(5, 1));
    sput_fail_unless(binomial(5, 2) == 10, "binomial(5, 2)");
    printf("Expected result: 10, actual result: %d\n", binomial(5, 2));
    sput_fail_unless(binomial(5, 3) == 10, "binomial(5, 3)");
    printf("Expected result: 10, actual result: %d\n", binomial(5, 3));
    sput_fail_unless(binomial(5, 4) == 5, "binomial(5, 4)");
    printf("Expected result: 5, actual result: %d\n", binomial(5, 4));
    sput_fail_unless(binomial(5, 5) == 1, "binomial(5, 5)");
    printf("Expected result: 1, actual result: %d\n", binomial(5, 5));
}

static void test_num_digits(void){
    sput_fail_unless(num_digits(5) == 1, "num_digits(5)");
    printf("Expected result: 1, actual result: %d\n", num_digits(5));
    sput_fail_unless(num_digits(9) == 1, "num_digits(9)");
    printf("Expected result: 1, actual result: %d\n", num_digits(9));
    sput_fail_unless(num_digits(10) == 2, "num_digits(10)");
    printf("Expected result: 2, actual result: %d\n", num_digits(10));
    sput_fail_unless(num_digits(99) == 2, "num_digits(99)");
    printf("Expected result: 2, actual result: %d\n", num_digits(99));
    sput_fail_unless(num_digits(100) == 3, "num_digits(100)");
    printf("Expected result: 3, actual result: %d\n", num_digits(100));
    sput_fail_unless(num_digits(1000) == 4, "num_digits(1000)");
    printf("Expected result: 4, actual result: %d\n", num_digits(1000));
}

static void test_power2(void){
  	sput_fail_unless(power2(2, 0) == 1, "power2(2, 0)");
	printf("Expected result: 1, actual result: %.0f\n", power2(2, 0));
	sput_fail_unless(power2(2, 1) == 2, "power2(2, 1)");
	printf("Expected result: 2, actual result: %.0f\n", power2(2, 1));
	sput_fail_unless(power2(2, 2) == 4, "power2(2, 2)");
	printf("Expected result: 4, actual result: %.0f\n", power2(2, 2));
	sput_fail_unless(power2(2, 3) == 8, "power2(2, 3)");
	printf("Expected result: 8, actual result: %.0f\n", power2(2, 3));
}

int main(void)
{
    printf("Running test harness for SYSC 2006 Lab 3, Part 2\n\n");
    sput_start_testing();

    sput_enter_suite("Exercise 1: factorial()");
    sput_run_test(test_factorial);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Tests for the remaining exercises won't be run until factorial "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 2: ordered_subsets()");
    sput_run_test(test_ordered_subsets);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Tests for the remaining exercises won't be run until ordered_subsets "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }


    sput_enter_suite("Exercise 3: binomial()");
    sput_run_test(test_binomial);
    sput_leave_suite();

    sput_enter_suite("Exercise 4: num_digits()");
    sput_run_test(test_num_digits);
    sput_leave_suite();

    sput_enter_suite("Exercise 5: power2()");
    sput_run_test(test_power2);
    sput_leave_suite();

    sput_finish_testing();
    return sput_get_return_value();
}
