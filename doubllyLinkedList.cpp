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
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        new_node->next = slowPtr->next;
        slowPtr->next = new_node;
        if (new_node->next)
            new_node->next->prev = new_node;
        new_node->prev = slowPtr;

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
    // END OF INSERT

    // DELETE

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
        while (fastPtr && fastPtr->next)
        {
            prevSlowPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        prevSlowPtr->next = slowPtr->next;
        prevSlowPtr->next->prev = prevSlowPtr;
        free(slowPtr);
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
            cout << "Wrong Pos<<endl";
            return;
        }
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

    // END OF DELETE

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
    DLinkedList dll1;
    dll1.insertAtHead(6);
    dll1.insertAtHead(5);
    dll1.insertAtHead(4);
    dll1.insertAtHead(3);
    dll1.insertAtHead(2);
    dll1.insertAtHead(1);
    dll1.display();
    cout << endl;
    // dll1.insertAtMiddle(100);
    // dll1.insertAtPos(100, 1);
    // dll1.insertAtEnd(7);
    // dll1.deleteAtHead();
    // dll1.deleteAtMiddle();
    // dll1.deleteAtPos(0);
    dll1.deleteAtEnd();
    dll1.display();

    return 0;
}