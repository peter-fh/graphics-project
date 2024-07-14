#include <iostream>


int *createArray(int n) {
  int *arr = new int[n];
  return arr;
}

void initializeArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
}

void printArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

void deleteArray(int *arr) { 
  delete arr;
}

int main() {
  int size;
  std::cout << "Size: ";
  std::cin >> size;
  int *arr = createArray(size);
  initializeArray(arr, size);
  printArray(arr, size);
  deleteArray(arr);
}
