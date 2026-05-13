#include <iostream>
using namespace std;

int findLargestIndex(int arr[], int n, int index, int maxIndex) {
    if (index == n)
        return maxIndex;

    if (arr[index] > arr[maxIndex])
        maxIndex = index;

    return findLargestIndex(arr, n, index + 1, maxIndex);
}

bool subsetSum(int arr[], int n, int index, int target, bool used) {
    if (target == 0 && used)
        return true;

    if (index == n || target < 0)
        return false;

    return subsetSum(arr, n, index + 1, target - arr[index], true) ||
        subsetSum(arr, n, index + 1, target, used);
}

int magicNumber(int arr[], int n) {
    if (n == 0)
        return -1;

    int largestIndex = findLargestIndex(arr, n, 0, 0);
    int largest = arr[largestIndex];

    int temp[100];

    int copyArray(int i, int j) {
        if (i == n)
            return j;

        if (i != largestIndex) {
            temp[j] = arr[i];
            return copyArray(i + 1, j + 1);
        }

        return copyArray(i + 1, j);
    }

    int newSize = copyArray(0, 0);

    if (subsetSum(temp, newSize, 0, largest, false))
        return largest;

    arr[largestIndex] = -1;

    return magicNumber(arr, n);
}

int main() {
    int arr[] = { 2, 3, 5, 8, 13 };
    int n = 5;

    cout << "Magic Number: " << magicNumber(arr, n);

    return 0;
}