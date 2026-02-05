#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int start = 0, end = n - 1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main() {
    int n, choice, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements of array: \n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nEnter element to search: ";
    cin >> key;

    cout << "\nChoose Search Method:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search (Array must be sorted)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    int result;

    switch(choice) {
        case 1:
            result = linearSearch(arr, n, key);
            if(result != -1)
                cout << "Element found at index " << result;
            else
                cout << "Element not found";
            break;

        case 2:
            result = binarySearch(arr, n, key);
            if(result != -1)
                cout << "Element found at index " << result;
            else
                cout << "Element not found";
            break;

        default:
            cout << "Invalid Choice!";
    }

    return 0;
}
