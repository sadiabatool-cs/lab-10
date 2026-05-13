#include <iostream>
using namespace std;
int recursiveSum(int arr[], int size) {
    if (size == 0)
        return 0;
    return arr[size - 1] + recursiveSum(arr, size - 1);
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = recursiveSum(arr, size);
    cout << "Sum of array elements: " << sum << endl;
    return 0;
}