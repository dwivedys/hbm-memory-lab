#include <stdio.h>

// merging two sorted arrays

void merge(int *arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int sz = right - left + 1;
    int temp[sz];
    int k = 0;
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];
    
    for(i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

}

void split(int *arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left)/2;
    split(arr, left, mid);
    split(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main() {
    int input_arr[] = {3,5,1,2,7};
    int sz = sizeof(input_arr)/sizeof(int);
    split(input_arr, 0, sz-1);
    for(int i = 0; i < sz; i++) {
        printf("%d ", input_arr[i]);
    }
    printf("\n");
    //printf("%lu\n", sizeof(input_arr[0]));
    return 0;

}