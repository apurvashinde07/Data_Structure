#include <iostream>
using namespace std;

int main()
{
    int a[2][2], b[2][2], c[2][2];
    int i, j, k, choice;

    // create Matrix
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

    cout << "First Matrix: ";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << a[i][j];
        }
    }

    cout << "Second matrix: ";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << b[i][j];
        }
    }

    cout << "...Operations on Matrix..." << endl;
    cout << "1.Addition" << endl;
    cout << "2.Subtraction" << endl;
    cout << "3.Multiplication" << endl;
    cout << "4.transpose" << endl;
    cout << "5. Search Element"<<endl;
    cout << "Enter your choice";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Addition of two matrix is: ";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
                cout << c[i][j];
            }
            cout << endl;
        }
        break;

    case 2:
        cout << "Sub of two Matrix is: ";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                c[i][j] = a[i][j] - b[i][j];
                cout << c[i][j];
            }
            cout << endl;
        }
        break;

    case 3:
        cout << "multipliaction of two matrix is: ";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                c[i][j] = 0; // initialize
                for (k = 0; k < 2; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                    cout<<c[i][j];
                }
                cout<<endl;
            }
        }
        break;

    case 4:
        cout << "Transpose of first matrix is: ";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                cout << a[j][i];
            }
            cout << endl;
        }
        cout << "Transpose of second matrix is: ";
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                cout << b[j][i];
            }
            cout << endl;
        }
        break;
    case 5:     // SEARCH ELEMENT
        int key, found = 0;
        cout << "Enter element to search in Matrix A: ";
        cin >> key;

        for(i = 0; i < 2; i++) {
            for(j = 0; j < 2; j++) {
                if(A[i][j] == key) {
                    cout << "Element found at position: (" 
                        << i+1 << "," << j+1 << ")\n";
                        
                    found = 1;
                }
            }
        }

        if(!found)
            cout << "Element not found.";
        
     break;

    default:
        cout << "invalid choice: ";
    }
    return 0;

}
