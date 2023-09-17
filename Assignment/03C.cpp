// Programs for Stack, Queues and Circular Queues using Arrays

// Programs for Circular Queues using Arrays

#include <iostream>
using namespace std;

int size, choice, elem, front, rear, qSize;
int arr[100];

void insert()
{
    if (qSize == size)
    {
        cout << "Full";
    }
    else
    {
        cout << "Enter the element to be inserted : ";
        cin >> elem;
        rear = (rear + 1) % size;
        arr[rear] = elem;
        qSize++;
    }
}

void del()
{
    if (qSize == 0)
    {
        cout << "Empty";
    }
    else
    {
        front = (front + 1) % size;
        qSize--;
    }
}

void display()
{
    cout << "Queue elements are : ";
    int i = front;
    do
    {
        cout << arr[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
}

int main()
{

    cout << "Enter the size of the queue :";
    cin >> size;
    front = 0;
    rear = size - 1;
    qSize = 0;
    cout << "\nCIRCULAR QUEUE OPERATIONS USING ARRAY";
    cout << "\n-------------";

    do
    {
        cout << "\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT";
        cout << "\nEnter the Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            insert();
            break;
        }
        case 2:
        {
            del();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            cout << "\nEXIT POINT ";
            break;
        }
        default:
        {
            cout << "\nPlease Enter a Valid Choice(1/2/3/4)";
        }
        }
    } while (choice != 4);

    return 0;
}

/*

Enter the size of the queue :3

QUEUE OPERATIONS USING ARRAY
-------------
1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice : 1
Enter the element to be inserted : 1

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice : 1
Enter the element to be inserted : 2

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice : 1
Enter the element to be inserted : 3

1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice : 3
Queue elements are : 1 2 3
1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice : 2
Deleted element is : 1
1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice : 3
Queue elements are : 2 3
1.INSERT
2.DELETE
3.DISPLAY
4.EXIT
Enter the Choice : 4

EXIT POINT

*/