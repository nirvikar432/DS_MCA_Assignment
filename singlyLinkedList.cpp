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

class LinkedList
{
public:
    Node *head;

    // public:
    LinkedList()
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

    void insertAtMiddle(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            return;
        }

        Node *slowPtr = head;
        Node *fastPtr = head;
        while (fastPtr->next && fastPtr->next->next)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        new_node->next = slowPtr->next;
        slowPtr->next = new_node;

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
        cout << counter << endl;
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
        return;
    }

    // END OF INSERT

    // DELETE

    void deleteAtHead()
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    void deleteAtMiddle()
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
        Node *slowPtr = head;
        Node *fastPtr = head;
        Node *prevSlowPtr = NULL;
        ;
        while (fastPtr && fastPtr->next) // 1 2 3 4 5           1 2 3 4
        {
            prevSlowPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        prevSlowPtr->next = slowPtr->next;
        free(slowPtr);
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
        int counter = 0;
        while (counter != pos - 1)
        {
            counter++;
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = temp->next->next;
        free(delNode);
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
        while (temp->next->next)
        {
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = NULL;
        free(delNode);
        return;
    }

    // END OF DELETE

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main()
{
    LinkedList ll1;
    ll1.insertAtHead(6);
    ll1.insertAtHead(5);
    ll1.insertAtHead(4);
    ll1.insertAtHead(3);
    ll1.insertAtHead(2);
    ll1.insertAtHead(1);
    ll1.display();
    cout << endl;
    // ll1.insertAtMiddle(10);
    // ll1.insertAtEnd(100);
    // ll1.insertAtPos(100, 3);
    // ll1.deleteAtMiddle();
    // ll1.deleteAtPos(3);
    ll1.deleteAtEnd();
    ll1.display();
    // cout << (ll1.head->val);

    return 0;
}