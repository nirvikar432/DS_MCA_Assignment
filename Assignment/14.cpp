// 14. Program to create add remove &display element from double linked list

#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int val;
    Node *next;

    Node(int data)
    {
        prev = NULL;
        val = data;
        next = NULL;
    }
};

class DLinkedList
{
public:
    Node *head;

    DLinkedList()
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
        head->prev = new_node;
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

        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
        return;
    }

    void insertAtPos(int val, int pos)
    {
        if (pos == 0)
        {
            insertAtHead(val);
            return;
        }
        Node *temp = head;
        int counter = 0;
        Node *new_node = new Node(val);

        while (counter != pos - 1)
        {
            counter++;
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        if (new_node->next)
            new_node->next->prev = new_node;
        new_node->prev = temp;
    }

    // Remove

    void deleteAtHead()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            free(head);
            head = NULL;
            return;
        }
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return;
    }

    void deleteAtEnd()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            free(head);
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        Node *dNode = temp;
        temp->prev->next = NULL;
        free(dNode);
        return;
    }

    void deleteAtPos(int pos)
    {
        if (pos > 0)
        {
            if (pos == 1)
            {
                deleteAtHead();
                return;
            }
            Node *temp = head;
            int counter = 1;
            while (counter != pos - 1)
            {
                counter++;
                temp = temp->next;
            }
            Node *dNode = temp->next;
            temp->next = temp->next->next;
            if (temp->next)
                temp->next->prev = temp;
            free(dNode);
            return;
        }
        else
        {
            cout << "Wrong Position" << endl;
            return;
        }
    }

    // Display

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << "<->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main()
{
    DLinkedList dll;
    int choice, choice2;
    do
    {
        cout << "\n DOUBLY LINKED LIST";
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
                dll.insertAtHead(val);
                break;
            }
            case 2:
            {
                dll.insertAtEnd(val);
                break;
            }
            case 3:
            {
                cout << "Enter the position";
                int pos;
                cin >> pos;
                dll.insertAtPos(val, pos);
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
                dll.deleteAtHead();
                break;
            }
            case 2:
            {
                dll.deleteAtEnd();
                break;
            }
            case 3:
            {
                cout << "Enter the position : ";
                int pos;
                cin >> pos;
                dll.deleteAtPos(pos);
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
            dll.display();
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
 DOUBLY LINKED LIST
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

 DOUBLY LINKED LIST
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

 DOUBLY LINKED LIST
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

 DOUBLY LINKED LIST
-------------
1.ADD
2.REMOVE
3.DISPLAY
4.EXIT
Enter the Choice : 3
3<->2<->1<->NULL
 DOUBLY LINKED LIST
-------------
1.ADD
2.REMOVE
3.DISPLAY
4.EXIT
Enter the Choice : 4

EXIT POINT
*/