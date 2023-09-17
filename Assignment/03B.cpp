// Programs for Stack, Queues and Circular Queues using Arrays

// Programs for Queues using Arrays

#include <iostream>
using namespace std;

int size, choice, elem, front, rear;
int arr[100];

void insert()
{
    if (rear == size - 1)
    {
        cout << "Queue is full";
    }
    else
    {
        cout << "Enter the element to be inserted : ";
        cin >> elem;
        if (front == -1)
        {
            arr[++front] = elem;
            rear++;
        }
        else
        {
            arr[++rear] = elem;
        }
    }
}

void del()
{
    if (front == -1)
    {
        cout << "Queue is empty";
    }
    else if (front == rear)
    {
        front = rear = -1;
        cout << "Queue is empty";
    }
    else
    {
        cout << "Deleted element is : " << arr[front++];
    }
}

void display()
{
    cout << "Queue elements are : ";
    if (front == rear == -1)
    {
        cout << "Queue is empty";
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    front = rear = -1;
    cout << "Enter the size of the queue :";
    cin >> size;
    cout << "\nQUEUE OPERATIONS USING ARRAY";
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
            exit(0);
            break;
        }
        default:
        {
            cout << "\nPlease Enter a Valid Choice(1/2/3/4)";
        }
        }
    } while (choice = 4);

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