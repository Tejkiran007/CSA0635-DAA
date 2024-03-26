#include <stdio.h>

void minMaxSequence(int arr[], int n, int *min, int *max, int *minStart, int *maxStart)
{
  
    if (n == 1) {
        *min = arr[0];
        *max = arr[0];
        *minStart = 0;
        *maxStart = 0;
        return;
    }

   
    int min1 = arr[0], min2 = arr[1], max1 = arr[0], max2 = arr[1];
    int minStart1 = 0, minStart2 = 1, maxStart1 = 0, maxStart2 = 1;

    minMaxSequence(arr, n - 1, &min1, &max1, &minStart1, &maxStart1);

  
    if (min1 > arr[n - 1]) {
        min2 = min1;
        minStart2 = minStart1;
        min1 = arr[n - 1];
        minStart1 = n - 1;
    } else if (min2 > arr[n - 1]) {
        min2 = arr[n - 1];
        minStart2 = n - 1;
    }
    if (max1 < arr[n - 1]) {
        max2 = max1;
        maxStart2 = maxStart1;
        max1 = arr[n - 1];
        maxStart1 = n - 1;
    } else if (max2 < arr[n - 1]) {
        max2 = arr[n - 1];
        maxStart2 = n - 1;
    }

    if (min2 > max1) {
        *min = max1;
        *minStart = maxStart1;
    } else {
        *min = min2;
        *minStart = minStart2;
    }
    if (max2 > max1) {
        *max = max2;
        *maxStart = maxStart2;
    } else {
        *max = max1;
        *maxStart = maxStart1;
    }

    return;
}

int main()
{
    int n, arr[100],i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

   
    int min = arr[0], max = arr[0];
    int minStart = 0, maxStart = 0;

    minMaxSequence(arr, n, &min, &max, &minStart, &maxStart);

    printf("Minimum sequence: %d at index %d\n", min, minStart);
    printf("Maximum sequence: %d at index %d\n", max, maxStart);

    return 0;
}
