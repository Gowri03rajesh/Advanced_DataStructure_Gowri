#include <stdio.h>
int main() {
    int n, i, key, low, high, mid, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in sorted order:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("Element %d found at position %d\n", key, mid + 1);
            found = 1;
            break;
        }
        else if(arr[mid] < key) {
            low = mid + 1; // Search right half
        }
        else {
            high = mid - 1; // Search left half
        }
    }
    if(found == 0) {
        printf("Element %d not found in the array\n", key);
    }
    return 0;
}
