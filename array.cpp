#include <iostream>
#define SIZE 10

int *createArray(int n) {
  int *arr = (int *)malloc(n * sizeof(int));
  return arr;
}

int *initializeArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
  return arr;
}

void printArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
}

void deleteArray(int *arr) { free(arr); }

int main() {
  int *arr = createArray(SIZE);
  initializeArray(arr, SIZE);
  printArray(arr, SIZE);
  deleteArray(arr);
  std::cout << "\n";
  printArray(arr, SIZE);//garbage values
}