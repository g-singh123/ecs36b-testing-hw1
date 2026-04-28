#include <cstdlib>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(CopyArrayTests, SimpleValuesAreSame) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = 5;
    int arr[] = {1, 2, 3, 4, 5};
    int* copy_of_arr = copy_array(arr, len);

    for (int i = 0; i < len; i++) {
        EXPECT_EQ(arr[i], copy_of_arr[i]);
    }
    free(copy_of_arr);


}

TEST(CopyArrayTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = 5;
    int arr[] = {1, 2, 3, 4, 5};
    int* copy_of_arr = copy_array(arr, len);

    copy_of_arr[2] = 20;
    for (int i = 0; i < len; i++) {
        EXPECT_EQ(arr[i], i+1);
    }

    free(copy_of_arr);

}

TEST(CopyArrayTests, SimpleCopyWasMade) {
    /*
     * Check that a copy was actually made
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int len = 5;
    int arr[] = {1, 2, 3, 4, 5};
    int* copy_of_arr = copy_array(arr, len);

    EXPECT_NE(copy_of_arr, arr);
    for (int i = 0; i < len; i++) {
        EXPECT_EQ(arr[i], copy_of_arr[i]);
    }

    free(copy_of_arr);

}


RC_GTEST_PROP(CopyArrayTests,
              PropertyValuesAreSame,
              (const std::vector<int>& values)
) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    std::vector<int> original = values;
    int* copy = copy_array(original.data(), original.size());

    for (size_t i = 0; i < original.size(); i++) {
        RC_ASSERT(original[i] == copy[i]);
    }
    free(copy);

}

RC_GTEST_PROP(CopyArrayTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    std::vector<int> original = values;
    int* copy = copy_array(original.data(), original.size());

    for (size_t i = 0; i < original.size(); i++) {
        RC_ASSERT(original[i] == values[i]);
    }

    free(copy);

}

RC_GTEST_PROP(CopyArrayTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
  * Check that a copy was actually made
  * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
  * Don't forget to free any memory that was dynamically allocated as part of your test.
  */
    std::vector<int> original = values;
    int* copy = copy_array(original.data(), original.size());

    RC_ASSERT(copy != values.data());
    for (size_t i = 0; i < values.size(); i++) {
        RC_ASSERT(values[i] == copy[i]);
    }

    free(copy);

}



