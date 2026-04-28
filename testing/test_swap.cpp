#include <cstdlib>
#include <vector>
#include <algorithm>
#include "test_helpers.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"


TEST(SwapTests, SimpleSwapTwoValues) {
    /*
     * Swap two values and see if the swap was successful.
     */
    int a = 3;
    int b = 4;

    swap(&a, &b);
    EXPECT_EQ(4, a);
    EXPECT_EQ(3, b);
}

TEST(SwapTests, SimpleSwapValuesInArray) {
    /*
     * Swap a few values in an array.
     * Check that the ones that swapped did swap and the ones that didn't swap
     * are still at the same locations
     */

    int arr[5] = {3, 2, 1, 5, 4};

    swap(&arr[0], &arr[2]);
    swap(&arr[3], &arr[4]);
    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(3, arr[2]);
    EXPECT_EQ(4, arr[3]);
    EXPECT_EQ(5, arr[4]);
    EXPECT_EQ(2, arr[1]);

}

RC_GTEST_PROP(SwapTests,
              PropertySwapTwoValues,
              (int a_start, int b_start)
) {
    /*
     * Swap two values and see if the swap was successful.
     */
    int a = a_start;
    int b = b_start;

    swap(&a, &b);
    RC_ASSERT(a == b_start);
    RC_ASSERT(b == a_start);
}


RC_GTEST_PROP(SwapTests,
              PropertySwapValuesInArray,
              (const std::vector<int>& values)
) {
    /*
     * Swap two values in an array. See that they swapped and the others did not
     */
    std::vector<int> arr = values;

    swap(&arr[0], &arr[1]);

    RC_ASSERT(values[0] == arr[1]);
    RC_ASSERT(values[1] == arr[0]);
    for (size_t i = 2; i < values.size(); i++) {
        RC_ASSERT(arr[i] == values[i]);
    }

}
