#include <cstdlib>
#include <string>
#include "gtest/gtest.h"
#include "formatting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

auto word_generator() {
    /* Creates a generator for a string made up of
     * characters from [a - z]
     */
    return rc::gen::container<std::string>(
            rc::gen::inRange<char>('a', 'z' + 1)
        );
}

auto vector_of_ints_to_vector_of_strings(const std::vector<int>& numbers) {
    /* Create a vector of strings from a vector of ints
     */
    std::vector<std::string> result;

    for (int num : numbers) {
        result.push_back(std::to_string(num));
    }

    return result;
}


TEST(ParseArgsTests, SimpleCheckArgumentsParsedSuccessfully) {
    /*
     * Check that you parse the command line arguments correctly.
     * (ar_out and len_out are set to the right values).
     * Don't forget to free any memory that was dynamically allocated as part of your test.'
     */
    int argc = 3;
    char* argv[] = {(char*)"SortInts", (char*)"1", (char*)"2"};

    int* ar_out = nullptr;
    int len_out = 0;

    parse_args(argc, argv, &ar_out, &len_out);

    EXPECT_EQ(len_out, 2);
    EXPECT_EQ(ar_out[0], 1);
    EXPECT_EQ(ar_out[1], 2);

    free(ar_out);
}

TEST(ParseArgsTests, SimpleCheckParseNoArgs) {
    /*
     * Check that you parse you can successfully parse "no" command line arguments.
     */
    int argc = 1;
    char* argv[] = {(char*)"SortInts"};

    int* ar_out = nullptr;
    int len_out = -1;

    parse_args(argc, argv, &ar_out, &len_out);

    EXPECT_EQ(len_out, 0);
    EXPECT_EQ(ar_out, nullptr);
}


RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckArgumentsParsedSuccessfully,
              ()
) {
    /* Check that we can correctly parse the command line
     * arguments when we receive 1 or more arguments.
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */
}

RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckParseNoArgs,
              ()
) {
    /*
     * Check that you parse you can successfully parse "no" command line arguments.
     */
}
