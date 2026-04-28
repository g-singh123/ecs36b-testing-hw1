#include <cstdlib>
#include "gtest/gtest.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(GetSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = 5;
    int arr[] = {1, 2, 3, 4, 5};
    int* copy = get_sorted(arr, len);

    for (int i = 0; i < len; i++) {
        EXPECT_EQ(copy[i], i+1);
    }
    free(copy);


}

TEST(GetSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = 5;
    int arr[] = {5, 4, 3, 2, 1};
    int* copy = get_sorted(arr, len);

    for (int i = 0; i < len; i++) {
        EXPECT_EQ(copy[i], i+1);
    }
    free(copy);

}

TEST(GetSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = 5;
    int arr[] = {4, 2, 1, 5, 3};
    int* copy = get_sorted(arr, len);

    for (int i = 0; i < len; i++) {
        EXPECT_EQ(copy[i], i+1);
    }
    free(copy);

}

TEST(GetSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = 5;
    int arr[] = {5, 5, 3, 2, 1};
    int* copy = get_sorted(arr, len);

    EXPECT_EQ(copy[0], 1);
    EXPECT_EQ(copy[1], 2);
    EXPECT_EQ(copy[2], 3);
    EXPECT_EQ(copy[3], 5);
    EXPECT_EQ(copy[4], 5);

    free(copy);


}

TEST(GetSortedTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = 5;
    int arr[] = {1, 2, 3, 4, 5};
    int* copy = get_sorted(arr, len);

    for (int i = 0; i < len; i++) {
        EXPECT_EQ(arr[i], i+1);
    }

    free(copy);


}

TEST(GetSortedTests, SimpleCopyWasMade) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = 5;
    int arr[] = {1, 2, 3, 4, 5};
    int* copy = get_sorted(arr, len);

    for (int i = 0; i < len; i++) {
        EXPECT_EQ(copy[i], arr[i]);
    }

    ASSERT_NE(copy, arr);

    free(copy);


}


RC_GTEST_PROP(GetSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Check that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */
    int* sorted = get_sorted(values.data(), values.size());

    for (size_t i = 1; i < values.size(); i++) {
        RC_ASSERT(sorted[i-1] <= sorted[i]);
    }

    free(sorted);

}

RC_GTEST_PROP(GetSortedTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    std::vector<int> original = values;
    int* sorted_arr = get_sorted(original.data(), original.size());

    for (size_t i = 0; i < values.size(); i++) {
        RC_ASSERT(original[i] == sorted_arr[i]);
    }

    free(sorted_arr);
}

RC_GTEST_PROP(GetSortedTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    std::vector<int> original = values;
    int* sorted = get_sorted(original.data(), original.size());

    RC_ASSERT(sorted != values.data());
    for (size_t i = 1; i < values.size(); i++) {
        RC_ASSERT(sorted[i-1] <= sorted[i]);
    }

    for (size_t i = 0; i < values.size(); i++) {
        int origCount = 0;
        int copyCount = 0;
        for (size_t j = 1; j < values.size(); j++) {
            if (values[j] == values[i]) {
                origCount++;
            }
            if (values[i] == sorted[j]) {
                copyCount++;
            }
        }
        RC_ASSERT(origCount == copyCount);
    }

    free(sorted);

}











