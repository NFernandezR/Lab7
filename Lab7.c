// Lab7.c
// Computer Science 1 Lab Assignment # 7
// Norman Fernandez

// The goal of this assignment is to:
// 1) Implement two sorting algorithms, bubble sort and selection sort
// 2) Use these algorithms to sort two hardcoded integer arrays
// 3) Display both the # of times an individual element was swapped, and how many total swaps were done on the list as a whole.

// Include stdio.h to include printf() for displaying information to the monitor.
#include <stdio.h>

// Define a struct holding two integer fields, an element of an integer array, and the # of times that element has been swapped.
struct element {
    int val; // The integer value associated with this element.
    int swapped; // The # of times this individual element has been swapped.
};

// Declare functions to avoid redundant code and improve readability.

void swap(int *first, int *second); // Swap two elements in an integer array.
void bubblesort(int arr[], int n, struct element list[]); // Sort an unsorted integer array using the bubble sort algorithm.
void selectionsort(int arr[], int n, struct element list[]); // Sort an unsorted integer array using the selection sort algorithm.
void copyArray(int original[], int copy[]); // Copy over all the data from one integer array onto another.

int main(void) {
    // Hardcode the two unsorted integer arrays
    int arr1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    // Hardcode two pre-sorted struct element arrays, this ensures the output will be displayed in the correct order.
    struct element list1[9] = {
        [0].val = 7, [1].val = 13, [2].val = 16, [3].val = 22, [4].val = 45, [5].val = 58, [6].val = 63, [7].val = 72, [8].val = 97
    };
    for (int q = 0; q < 9; q++) {
        list1[q].swapped = 0;
    }
    struct element list2[9] = {
        [0].val = 10, [1].val = 20, [2].val = 30, [3].val = 40, [4].val = 50, [5].val = 60, [6].val = 70, [7].val = 80, [8].val = 90
    };
    for (int z = 0; z < 9; z++) {
        list2[z].swapped = 0;
    }

    // Sort the Arrays and display both how many times an element was swapped, and the total number of swaps applied on the lists.
    
    // Sort the two arrays using bubble sort, then display the # of swaps of individual elements, and for the overall array.
    for(int g = 0; g <= 1; g++) {
        // First, sort array 1 using the bubble sort algorithm and display the desired output.
        if (g == 0) {
            // Declare an integer array variable to copy array 1's data into.
            int cpy1[9];
            // Copy array 1's data into its copy variable.
            copyArray(arr1, cpy1);
            // Output to the monitor which array and algorithm will be used for the following sorting.
            printf("array1 bubble sort:\n");
            // Pass the copy of array 1 and the array of element structs to the bubble sort function.
            bubblesort(cpy1, 9, list1);
        }

        // Second, repeat the process for the bubble sort algorithm with array 2.
        else {
            int cpy2[9];
            copyArray(arr2, cpy2);
            printf("array2 bubble sort:\n");
            bubblesort(cpy2, 9, list2);
        }
    }

    // Reset the swapped member counter values of the struct element arrays to 0.
    for (int x = 0; x < 9; x++) {
        list1[x].swapped = 0;
        list2[x].swapped = 0;
    }

    // Sort the two arrays using selection sort, the display the # of swaps of individual elements, and for the overall array.
    
    // Repeat the steps taken with the bubble sort above, instead calling the selectionsort function.
    for (int h = 0; h <= 1; h++) {
        if (h == 0) {
            int dup1[9];
            copyArray(arr1, dup1);
            printf("array1 selection sort:\n");
            selectionsort(dup1, 9, list1);
        }

        else {
            int dup2[9];
            copyArray(arr2, dup2);
            printf("array2 selection sort:\n");
            selectionsort(dup2, 9, list2);
        }
    }
    return 0;
}

// Swap - A function that takes two pointers to integers, and swaps the pointed-to integer values.
void swap(int *first, int* second) {
    // Store the integer value at the first index position in a temporary integer variable.
    int temp = *first;
    // Replace the integer value at the first index position with that of the integer value at the second index position. 
    *first = *second;
    // Copy the first integer's old value into the second from temp, completing the swap.
    *second = temp;
}

// Bubble Sort - A function that algorithmically sorts an array in increasing order by comparing adjacent values,
// swapping as necessary until the array is fully sorted.
void bubblesort(int arr[], int n, struct element list[]) {
    // Declare loop variables i and j, a temp variable, and a total int variable to track the total # of swap calls executed.
    int i, j, temp, total;
    // Set total to 0.
    total = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Increment the swapped counters of the individual elements to be swapped.
                for (int e = 0; e < 9; e++) {
                    if (arr[j] == list[e].val) {
                        list[e].swapped++;
                    }

                    if (arr[j+1] == list[e].val) {
                        list[e].swapped++;
                    }
                }
                // swap values
                swap(arr + j, arr + j + 1);
                // Each time the swap function was called, increment the total # of swaps counter variable.
                total++;
            }
        }
    }

    // Display the desired output post-sorting.

    // Iterate over the struct element array.
    for (int t = 0; t < 9; t++) {
        // Print to monitor a column of data, listing how many times a particular value was swapped.
        printf("%d: %d\n", list[t].val, list[t].swapped);
    }
    // Print the total # of swaps.
    printf("%d", total);
    printf("\n");
}

// Selection Sort - A function that algorithmically sorts an array in increasing order by finding the smallest
// element of the array and then swapping that element with the first element in the unsorted section of the array.
void selectionsort(int arr[], int n, struct element list[]) {
    // Declare loop variables i and j, minimum array index variable mindex, temp and counter int variables.
    int i, j, mindex, temp, counter;
    // Set counter to 0.
    counter = 0;
    for (i = 0; i < n - 1; i++) {
        // Find minimum element
        mindex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[mindex]) {
                mindex = j;
            }

        }

        if (mindex != i) {
            // Increment the two elements' swapped counters in the struct element list
            for (int r = 0; r < 9; r++) {
                if (list[r].val == arr[mindex]) {
                    list[r].swapped++;
                }

                if (list[r].val == arr[i]) {
                    list[r].swapped++;
                }
            }
            // Swap the elements
            swap(arr + mindex, arr + i);
            // Each time a swap is done on the list, increment the counter.
            counter++;
        }
    }

    // Display the desired output of the selection sort.

    // Iterating over the corresponding struct element array...
    for (int y = 0; y < 9; y++) {
        // Print a column of the sorted values in increasing order, each value paired with the # of times it was swapped.
        printf("%d: %d\n", list[y].val, list[y].swapped);
    }
    // Output the total # of swaps performed on the array.
    printf("%d", counter);
    printf("\n");
}

// Copy Array - A function to copy the integer values stored in one array to another.
void copyArray(int original[], int copy[]) {
    // Iterate over each element of the temp array...
    for (int w = 0; w < 9; w++) {
        // copying the data from the original array onto the temporary one.
        copy[w] = original[w];
    }
}