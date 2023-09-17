#include <iostream>
using namespace std;

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Size of an array is " << size << endl;
    return 0;
}

/*

Size of an array is 9
*/