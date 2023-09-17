// 16. Program to create add remove &display element from circular linked list

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class CLinkedList
{
public:
    Node *head;
    CLinkedList()
    {
        head = NULL;
    }

    // INSERT
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        return;
    }

    void insertAtPos(int val, int pos)
    {
        Node *newNode = new Node(val);
        if (pos == 0)
        {
            insertAtHead(val);
            return;
        }
        Node *temp = head;
        int counter = 0;
        while (counter != pos - 1)
        {
            temp = temp->next;
            counter++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }

    // Remove

    void deleteAtHead()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == head)
        {
            free(head);
            head = NULL;
            cout << "No element";
            return;
        }

        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        Node *temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
        return;
    }

    void deleteAtEnd()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == head)
        {
            free(head);
            cout << "No element";
            head = NULL;

            return;
        }
        Node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        Node *dNode = temp->next;
        temp->next = head;
        free(dNode);
        return;
    }

    void deleteAtPos(int pos)
    {
        if (head == NULL)
        {
            cout << "list is empty";
        }
        if (pos == 0)
        {
            deleteAtHead();
            return;
        }
        Node *temp = head;
        if (pos > 0)
        {
            int icounter = 0;
            while (icounter != pos - 1 && temp->next != head)
            {
                icounter++;
                temp = temp->next;
            }
            if (temp->next != head)
            {
                Node *delNode = temp->next;
                temp->next = temp->next->next;
                free(delNode);
            }
        }
    }

    // Display

    void display()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->val << "->";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    CLinkedList ll;
    int choice, choice2;
    do
    {
        cout << "\n Circular LINKED LIST";
        cout << "\n-------------";
        cout << "\n1.ADD\n2.REMOVE\n3.DISPLAY\n4.EXIT";
        cout << "\nEnter the Choice : ";

        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\n1.INSERT AT HEAD\n2.INSERT AT END\n3.INSERT AT Kth POS";
            cout << "\nEnter the Choice : ";
            cin >> choice2;
            cout << "Enter the value : ";
            int val;
            cin >> val;
            switch (choice2)
            {
            case 1:
            {
                ll.insertAtHead(val);
                break;
            }
            case 2:
            {
                ll.insertAtEnd(val);
                break;
            }
            case 3:
            {
                cout << "Enter the position";
                int pos;
                cin >> pos;
                ll.insertAtPos(val, pos);
                break;
            }
            default:
            {
                cout << "\nPlease Enter a Valid Choice(1/2/3)";
            }
            }
            break;
        }

        case 2:
        {
            cout << "\n1.DELETE AT HEAD\n2.DELETE AT END\n3.DELETE AT Kth POS";
            cout << "\nEnter the Choice : ";
            cin >> choice2;
            switch (choice2)
            {
            case 1:
            {
                ll.deleteAtHead();
                break;
            }
            case 2:
            {
                ll.deleteAtEnd();
                break;
            }
            case 3:
            {
                cout << "Enter the position : ";
                int pos;
                cin >> pos;
                ll.deleteAtPos(pos);
                break;
            }
            default:
            {
                cout << "\nPlease Enter a Valid Choice(1/2/3)";
            }
            }
            break;
        }

        case 3:
        {
            ll.display();
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
            break;
        }
        }

    } while (choice = 4);

    return 0;
}

/*

 Circular LINKED LIST
-------------
1.ADD
2.REMOVE
3.DISPLAY
4.EXIT
Enter the Choice : 1

1.INSERT AT HEAD
2.INSERT AT END
3.INSERT AT Kth POS
Enter the Choice : 1
Enter the value : 3

 Circular LINKED LIST
-------------
1.ADD
2.REMOVE
3.DISPLAY
4.EXIT
Enter the Choice : 1

1.INSERT AT HEAD
2.INSERT AT END
3.INSERT AT Kth POS
Enter the Choice : 1
Enter the value : 2

 Circular LINKED LIST
-------------
1.ADD
2.REMOVE
3.DISPLAY
4.EXIT
Enter the Choice : 1

1.INSERT AT HEAD
2.INSERT AT END
3.INSERT AT Kth POS
Enter the Choice : 1
Enter the value : 1

 Circular LINKED LIST
-------------
1.ADD
2.REMOVE
3.DISPLAY
4.EXIT
Enter the Choice : 3
1->2->3->

 Circular LINKED LIST
-------------
1.ADD
2.REMOVE
3.DISPLAY
4.EXIT
Enter the Choice : 4

EXIT POINT
*/