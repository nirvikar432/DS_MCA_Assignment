// Develop and implement a menu driven program in C for the following Array operations
// a. Creating Array of N Integer elements.
// b. Display of Array elements with suitable headings.
// c. Inserting an element (ELEM) at a given valid position(POS).
// d. Deleting an element at a given valid position(POS).
// e. Exit

#include <iostream>
using namespace std;

int n = 0, pos, elem;
int arr[1000];

void createArray()
{

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void showArray()
{
    if (n == 0)
    {
        cout << "No element is found\n";
        return;
    }
    else
    {
        cout << "Array elements are : " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
        cout << endl;
    }
}

void insertElements()
{

    int i;
    if (n == 1000)
    {
        cout << "Array is full";
        return;
    }

    cout << "Enter the position: ";
    cin >> pos;
    cout << "Enter the element: ";
    cin >> elem;

    for (i = n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = elem;
    n = n + 1;
    showArray();
}

void deleteElement()
{
    int i;
    cout << "Enter the position: ";
    cin >> pos;
    if (pos > n)
    {
        cout << "Position is out of array index try again!!" << endl;
        return;
    }
    if (n == 0)
    {
        cout << "No element found" << endl;
        return;
    }
    for (i = pos; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n = n - 1;

    showArray();
}

int main()
{
    bool flag = true;
    while (flag)
    {
        cout << "\n(Press 1) Creating Array";
        cout << "\n(Press 2) Display";
        cout << "\n(Press 3) Insert";
        cout << "\n(Press 4) Delete";
        cout << "\n(Press 5) Exit.";
        cout << "\nEnter your choice : ";

        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
            createArray();
            break;
        case 2:
            showArray();
            break;
        case 3:
            insertElements();
            break;
        case 4:
            deleteElement();
            break;
        case 5:
            flag = false;
            break;

        default:
            cout << "Thank You";
            break;
        }
    }
    return 0;
}

/*
(Press 1) Creating Array
(Press 2) Display
(Press 3) Insert
(Press 4) Delete
(Press 5) Exit.

Enter your choice : 1
Enter the number of elements: 5
Enter the elements: 1 2 3 4 5

(Press 1) Creating Array
(Press 2) Display
(Press 3) Insert
(Press 4) Delete
(Press 5) Exit.

Enter your choice : 2
Array elements are :
1       2       3       4       5

(Press 1) Creating Array
(Press 2) Display
(Press 3) Insert
(Press 4) Delete
(Press 5) Exit.
Enter your choice : 5

*/