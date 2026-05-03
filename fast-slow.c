#include <stdio.h>

int main() {

  int arr[] = {1,1,2,2,3};
  int slow = 0, fast = 1;
  int sz = sizeof(arr)/sizeof(arr[0]);
  for(fast = 1; fast < sz; fast++) {
    if(arr[slow] != arr[fast]) {
      slow++;
      arr[slow] = arr[fast];
    }
  }
  // print the final array
  int newsz = sizeof(arr)/sizeof(arr[0]);
  for(int i = 0; i < newsz; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
