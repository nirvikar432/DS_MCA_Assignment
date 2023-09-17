// Program to create add, remove & display element from single linked list

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

class linkedList
{
public:
    Node *head;
    linkedList()
    {
        head = NULL;
    }

    // INSERT
    void insertAtHead(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        new_node->next = head;
        head = new_node;
        return;
    }

    void insertAtEnd(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    void insertAtPos(int val, int pos)
    {
        Node *new_node = new Node(val);
        if (pos == 0)
        {
            insertAtHead(val);
            return;
        }

        Node *temp = head;
        int curPos = 0;
        while (curPos != pos - 1)
        {
            temp = temp->next;
            curPos++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        return;
    }

    // Remove

    void deleteAtHead()
    {
        if (head == NULL)
        {
            cout << "List is Empty";
        }
        Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << " List is Empty";
        }
        if (head->next == NULL)
        {
            free(head);
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = NULL;
        free(delNode);
        return;
    }

    void deleteAtPos(int pos)
    {
        if (pos == 0)
        {
            deleteAtHead();
            return;
        }

        Node *temp = head;
        int curPos = 0;
        while (curPos != pos - 1)
        {
            temp = temp->next;
            curPos++;
        }
        Node *delNode = temp->next;
        temp->next = temp->next->next;
        free(delNode);
    }

    // Display

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    linkedList ll;
    int choice, choice2;
    do
    {
        cout << "\n LINKED LIST";
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

 LINKED LIST
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

 LINKED LIST
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

 LINKED LIST
-------------
1.ADD
2.REMOVE
3.DISPLAY
4.EXIT
Enter the Choice : 3
2 1 NULL

 LINKED LIST
-------------
1.ADD
2.REMOVE
3.DISPLAY
4.EXIT
Enter the Choice : 4

EXIT POINT

*/