#include <stdio.h>
#include <limits.h>

void secondsmallestelement(int arr[], int n) {
    if (n < 1) {
        printf("The array has basically 0 elements, but the array must have atleast 2 or more elements to get the second smallest element.\n");
        return;
    }
    int smallest = INT_MAX; 
    int secondsmallestelement = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            secondsmallestelement = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondsmallestelement && arr[i] != smallest) {
            secondsmallestelement = arr[i];
        }
    }

    if (secondsmallestelement == INT_MAX)
        printf("No second smallest element found.\n");
    else
        printf("The second smallest element is: %d\n", secondsmallestelement);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 12, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    secondsmallestelement(arr, n);
    return 0;
}

