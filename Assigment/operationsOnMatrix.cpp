#include <iostream>
using namespace std;

int main()
{
    int a[2][2], b[2][2], c[2][2];
    int i, j, k, choice;

    cout << "Enter the element of first matrix: ";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter the element of second matrix: ";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cin >> b[i][j];
        }
    }

    cout << "First Matrix:\n";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Second matrix:\n";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n...Operations on Matrix..." << endl;
    cout << "1.Addition" << endl;
    cout << "2.Subtraction" << endl;
    cout << "3.Multiplication" << endl;
    cout << "4.Transpose" << endl;
    cout << "5.Search Element" << endl;
    cout << "6.Traverse Matrix" << endl;
    cout << "7.Update Matrix Element" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Addition of two matrix is:\n";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
        break;

    case 2:
        cout << "Subtraction of two Matrix is:\n";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                c[i][j] = a[i][j] - b[i][j];
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
        break;

    case 3:
        cout << "Multiplication of two matrix is:\n";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                c[i][j] = 0;
                for (k = 0; k < 2; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
        break;

    case 4:
        cout << "Transpose of first matrix is:\n";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                cout << a[j][i] << " ";
            }
            cout << endl;
        }

        cout << "Transpose of second matrix is:\n";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                cout << b[j][i] << " ";
            }
            cout << endl;
        }
        break;

    case 5:     
    {
        int key, found = 0;
        cout << "Enter element to search in Matrix A: ";
        cin >> key;

        for(i = 0; i < 2; i++) {
            for(j = 0; j < 2; j++) {
                if(a[i][j] == key) {
                    cout << "Element found at position: ("
                         << i+1 << "," << j+1 << ")\n";
                    found = 1;
                }
            }
        }

        if(!found)
            cout << "Element not found.";
    }
        break;

    case 6:    
        cout << "Traversing First Matrix:\n";
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 2; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Traversing Second Matrix:\n";
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 2; j++) {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
        break;

    case 7:   
    {
        int mat, row, col, value;

        cout << "Which matrix to update? (1 for A, 2 for B): ";
        cin >> mat;

        cout << "Enter row (0-1) and column (0-1): ";
        cin >> row >> col;

        cout << "Enter new value: ";
        cin >> value;

        if(mat == 1) {
            a[row][col] = value;
            cout << "Matrix A updated.\n";
        }
        else if(mat == 2) {
            b[row][col] = value;
            cout << "Matrix B updated.\n";
        }
        else {
            cout << "Invalid matrix choice.";
        }
    }
        break;

    default:
        cout << "Invalid choice!";
    }

    return 0;
}
