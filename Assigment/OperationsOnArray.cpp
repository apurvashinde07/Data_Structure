#include <iostream>
using namespace std;

int main() {
    int arr[50];          // Declaration of array
    int n, i, position, value, key;

    // Input array size
    cout << "Enter number of elements: ";
    cin >> n;

    // Input array elements
    cout << "Enter elements:\n";
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Traversing the array
    cout << "\nTraversing the array:\n";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Insertion operation
    cout << "\n\nEnter position to insert element: ";
    cin >> position;
    cout << "Enter value to insert: ";
    cin >> value;

    for(i = n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = value;
    n++;

    cout << "Array after insertion:\n";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Searching operation 
    cout << "\n\nEnter element to search: ";
    cin >> key;

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << "Element found at position " << i + 1;
            break;
        }
    }
    if(i == n) {
        cout << "Element not found";
    }

    return 0;
}
