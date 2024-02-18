#include <stdio.h>

void m(int A[], int low, int high, int *min, int *max) {
    if (low == high) {
        *min = *max = A[low];
    } else if (low + 1 == high) {
        if (A[low] < A[high]) {
            *min = A[low];
            *max = A[high];
        } else {
            *min = A[high];
            *max = A[low];
        }
    } else {
        int mid = (low + high) / 2;
        int LMin, LMax, RMin, RMax;

        m(A, low, mid, &LMin, &LMax);
        m(A, mid + 1, high, &RMin, &RMax);

        if (LMin < RMin) {
            *min = LMin;
        } 
        else {
            *min = RMin;
        }
        if (LMax > RMax) {
            *max = LMax;
        } else {
            *max = RMax;
        }

    }
}

int main() {
    int n;
    int A[n];
    printf("Keval 60009220061");
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int min, max;
    m(A, 0, n - 1, &min, &max);
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}