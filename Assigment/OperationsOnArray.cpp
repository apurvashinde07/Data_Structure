#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0;
    int choice;

    do {
        cout << "\n\n---- ARRAY OPERATIONS MENU ----";
        cout << "\n1. Create";
        cout << "\n2. Destroy";
        cout << "\n3. Traverse";
        cout << "\n4. Selection";
        cout << "\n5. Update";
        cout << "\n6. Split";
        cout << "\n7. Insert";
        cout << "\n8. Delete";
        cout << "\n9. Search";
        cout << "\n10. Sort";
        cout << "\n11. Merge";
        cout << "\n12. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1:     
            cout << "Enter number of elements: ";
            cin >> n;

            cout << "Enter elements:\n";
            for(int i = 0; i < n; i++)
                cin >> arr[i];
            break;

        case 2:    
            n = 0;
            cout << "Array destroyed successfully.\n";
            break;

        case 3:    
            if(n == 0)
                cout << "Array is empty.\n";
            else {
                cout << "Array elements: ";
                for(int i = 0; i < n; i++)
                    cout << arr[i] << " ";
            }
            break;

        case 4:     
        {
            int pos;
            cout << "Enter position to access: ";
            cin >> pos;

            if(pos <= n && pos > 0)
                cout << "Element at position " << pos << " is " << arr[pos-1];
            else
                cout << "Invalid position.";
        }
            break;

        case 5:     
        {
            int pos, val;
            cout << "Enter position to update: ";
            cin >> pos;
            cout << "Enter new value: ";
            cin >> val;

            if(pos <= n && pos > 0) {
                arr[pos-1] = val;
                cout << "Element updated.";
            } else {
                cout << "Invalid position.";
            }
        }
            break;

        case 6:     
        {
            int mid = n / 2;

            cout << "First part: ";
            for(int i = 0; i < mid; i++)
                cout << arr[i] << " ";

            cout << "\nSecond part: ";
            for(int i = mid; i < n; i++)
                cout << arr[i] << " ";
        }
            break;

        case 7:     
        {
            int pos, val;
            cout << "Enter position to insert: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;

            if(pos > n+1 || pos <= 0) {
                cout << "Invalid position.";
            } else {
                for(int i = n; i >= pos; i--)
                    arr[i] = arr[i-1];

                arr[pos-1] = val;
                n++;

                cout << "Element inserted.";
            }
        }
            break;

        case 8:    
        {
            int pos;
            cout << "Enter position to delete: ";
            cin >> pos;

            if(pos > n || pos <= 0) {
                cout << "Invalid position.";
            } else {
                for(int i = pos-1; i < n-1; i++)
                    arr[i] = arr[i+1];

                n--;
                cout << "Element deleted.";
            }
        }
            break;

        case 9:    
        {
            int key, i;
            cout << "Enter element to search: ";
            cin >> key;

            for(i = 0; i < n; i++) {
                if(arr[i] == key) {
                    cout << "Element found at position " << i+1;
                    break;
                }
            }
            if(i == n)
                cout << "Element not found.";
        }
            break;

        case 10:   
            for(int i = 0; i < n-1; i++) {
                for(int j = 0; j < n-i-1; j++) {
                    if(arr[j] > arr[j+1]) {
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
            cout << "Array sorted.";
            break;

        case 11:   
        {
            int b[50], m;

            cout << "Enter size of second array: ";
            cin >> m;

            cout << "Enter elements of second array:\n";
            for(int i = 0; i < m; i++)
                cin >> b[i];

            for(int i = 0; i < m; i++)
                arr[n++] = b[i];

            cout << "Arrays merged successfully.";
        }
            break;

        case 12:
            cout << "Exiting program...";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while(choice != 12);

    return 0;
}
