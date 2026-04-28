#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "rapidcheck/gtest.h"
#include "sorting.h"

TEST(MinIndexOfArrayTests, SimpleMinIndexAtFrontOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the front of the array
     */
    int len = 5;
    int arr[] = {1, 2, 3, 4, 5};

    ASSERT_EQ(min_index_of_array(arr, len), 0);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtEndOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the end of the array
     */
    int len = 5;
    int arr[] = {1, 2, 3, 4, 0};

    ASSERT_EQ(min_index_of_array(arr, len), 4);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtMiddleOfArray) {
    /*
     * See if we can find the index of the minimum value when it is somewhere
     * in the "middle" of the array.
     */
    int len = 5;
    int arr[] = {1, 2, 0, 4, 5};

    ASSERT_EQ(min_index_of_array(arr, len), 2);
}

TEST(MinIndexOfArrayTests, SimpleDuplicateMinimums) {
    /*
     * See if we return the index of the first minimum in the array
     * When there are multiple values that are the minimum.
     */
    int len = 5;
    int arr[] = {2, 2, 1, 4, 1};

    ASSERT_EQ(min_index_of_array(arr, len), 2);
}

TEST(MinIndexOfArrayTests, SimpleArrayDoesNotChange) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    int len = 5;
    int arr[] = {1, 2, 3, 4, 5};

    int min = min_index_of_array(arr, len);
    EXPECT_EQ(min, 1);

    for (int i = 0; i < len; ++i) {
        EXPECT_EQ(arr[i], i+1);
    }
}


RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyFindMinIndex,
              (std::vector<int> values)) {
    /* Check that the value at the location of the minimum index
     * is not larger than any of the other values in the array
     */
    int min = min_index_of_array(values.data(), values.size());
    for (size_t i = 0; i < values.size(); i++) {
        RC_ASSERT(values[min] <= values[i]);
    }
}

RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyArrayDoesNotChange,
              (std::vector<int> values)) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    std::vector<int> before = values;

    min_index_of_array(values.data(), values.size());
    for (size_t i = 0; i < values.size(); i++) {
        RC_ASSERT(values[i] == before[i]);
    }

}
