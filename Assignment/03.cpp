// Programs for Stack using Arrays
#include <iostream>
using namespace std;

int stack[100], top, capacity, choice, i, x, rem;

void push()
{
    if (top == capacity - 1)
    {
        cout << "\nSTACK overflow\n";
    }
    else
    {
        cout << "\nEnter a value to be pushed : ";
        cin >> x;
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top == -1)
    {
        cout << "\nSTACK  underflow \n";
    }
    else
    {
        cout << "\nThe poped element is " << stack[top--];
    }
}

void display()
{
    if (top >= 0)
    {
        printf("\nThe element in stack\n");
        for (i = top; i >= 0; i--)
        {
            cout << endl;
            cout << stack[i];
        }
    }
    else
    {
        cout << "\nThe stack is empty\n";
    }
}

int main()
{
    top = -1;
    cout << "\nEnter the size of the stack [MAX =100] : ";
    cin >> capacity;
    cout << "\nSTACK OPERATIONS USING ARRAY";
    cout << "\n-------------";

    do
    {
        cout << "\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT";
        cout << "\nEnter the Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
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

Enter the size of the stack [MAX =100] : 3

STACK OPERATIONS USING ARRAY
-------------
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter the Choice : 1

Enter a value to be pushed : 1

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter the Choice : 1

Enter a value to be pushed : 2

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter the Choice : 1

Enter a value to be pushed : 3

1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter the Choice : 3

The element in stack

3
2
1
1.PUSH
2.POP
3.DISPLAY
4.EXIT
Enter the Choice : 4

EXIT POINT
*/