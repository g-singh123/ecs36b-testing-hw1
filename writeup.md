# Google Test And Debugging Writeup

## Things I Thought To Test
1. The copy_array function
2. The parse_args function
3. The swap function
...

## Bugs

### Bug 1

### Location

Lines 66-68 in sorting.cpp

```c++
int* temp = a;
a = b;
b = temp;
```

### How the bug was located

When looking through the given functions and seeing how the program computes the sorted array, I went straight to the swap function, which is common, to see if it's written as intended, in which it was not. 

### Description

The swap function is supposed to swap the value that the pointers are pointing to, but since there are no dereferences, the actual values don't get swapped.

### Fix 



```c++
int temp = *a;
*a = *b;
*b = temp;
```

### Bug 2

### Location

Line 56 in sorting.cpp

```c++
return ar[min_index];
```

### How the bug was located

The function was returning wrong values.

### Description

The return statement was part of the min_index_of_array function, which is supposed to return the index at which the minimum value exists, however the return statement listed instead returned the minium value of the array, not the index of it.

### Fix

I simply returned min_index instead of ar[min_index].

```c++
return min_index;
```

### Bug 3

### Location

Lines 29-38 in sorting.cpp

```c++
int* copy_array(int* ar, int len) {
  /**
  * Return a copy of the array
  * @param ar: The array to copy
  * @param len: The length of the array to copy
  * @return: A copy of ar
  */
  int* copy = ar;
  return copy;
}
```

### How the bug was located

The debugger detected an unused parameter len.

### Description

The function does not utilize one of its parameters. Also, the function implementation of copying an array in incorrect, as it does not actually make a copy.

### Fix

The integer pointer copy now allocates memory, accounting for the length of the array, while utilizing the len parameter. The functiona actually coppies the array through the for-loop where the value at each index is copied one by one until the end of the array. Since memory is allocated for the copy of the array, a null check is needed.

```c++
int* copy_array(int* ar, int len) {
  /**
  * Return a copy of the array
  * @param ar: The array to copy
  * @param len: The length of the array to copy
  * @return: A copy of ar
  */
  int* copy = int*(malloc(len * sizeof(int)));
  if (copy == NULL) {
    return NULL;
  }
  for (int i = 0; i < len; ++i) {
    copy[i] = ar[i];
  }
  return copy;
}
```