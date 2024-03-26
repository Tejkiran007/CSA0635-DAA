#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair minmax, leftMinMax, rightMinMax;
    int mid;

    // If there is only one element
    if (low == high) {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    // If there are more than two elements
    mid = (low + high) / 2;
    leftMinMax = findMinMax(arr, low, mid);
    rightMinMax = findMinMax(arr, mid + 1, high);

    // Compare minimums of two parts
    if (leftMinMax.min < rightMinMax.min)
        minmax.min = leftMinMax.min;
    else
        minmax.min = rightMinMax.min;

    // Compare maximums of two parts
    if (leftMinMax.max > rightMinMax.max)
        minmax.max = leftMinMax.max;
    else
        minmax.max = rightMinMax.max;

    return minmax;
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Pair result = findMinMax(arr, 0, n - 1);

    printf("Minimum element in the list: %d\n", result.min);
    printf("Maximum element in the list: %d\n", result.max);

    return 0;
}
+
