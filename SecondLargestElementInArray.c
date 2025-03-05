#include <stdio.h>
#include <limits.h>

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Array has basically 0 element, but it should have atleast 2 or more elements.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = INT_MIN;
    int secondlargest = INT_MIN;

    for (i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondlargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondlargest ,arr[i] != largest) {
            secondlargest = arr[i];
        }
    }

    if (secondlargest == INT_MIN) {
        printf("There is no second largest element.\n");
    } else {
        printf("The second largest element is: %d\n", secondlargest);
    }

    return 0;
}
