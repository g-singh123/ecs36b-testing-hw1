#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"
#include "test_helpers.h"

TEST(MakeSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = 5;
    int arr[] = {1, 2, 3, 4, 5};

    make_sorted(arr, len);
    for (int i = 0; i < len; i++) {
        EXPECT_EQ(arr[i], i+1);
    }
}

TEST(MakeSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = 5;
    int arr[] = {5, 4, 3, 2, 1};

    make_sorted(arr, len);
    for (int i = 0; i < len; i++) {
        EXPECT_EQ(arr[i], i+1);
    }
}


TEST(MakeSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = 10;
    int arr[] = {2, 9, 4, 3, 1, 6, 5, 7, 8, 10};
    make_sorted(arr, len);
    for (int i = 0; i < len; i++) {
        EXPECT_EQ(arr[i], i+1);
    }
}

TEST(MakeSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = 10;
    int arr[] = {2, 9, 2, 3, 2, 1, 5, 7, 8, 1};
    make_sorted(arr, len);
    for (int i = 0; i < len; i++) {
        EXPECT_EQ(arr[i], i+1);
    }
}

RC_GTEST_PROP(MakeSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Test that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    make_sorted(values.data(), values.size());
    for (size_t i = 1; i < values.size(); i++) {
        RC_ASSERT(values[i-1] <= values[i]);
    }
}
