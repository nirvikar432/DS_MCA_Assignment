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

    void insertAtMiddle(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *slowPtr = head;
        Node *fastPtr = head;
        while (fastPtr->next != head && fastPtr->next->next != head)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        newNode->next = slowPtr->next;
        slowPtr->next = newNode;
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

    // END OF INSERT

    // DELETE

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

    void deleteAtMiddle()
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
        Node *slowPtr = head;
        Node *fastPtr = head;
        Node *prevSlowPtr = NULL;
        do
        {
            prevSlowPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        } while (fastPtr != head && fastPtr->next != head);

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
        while (temp->next != head)
        {
            temp = temp->next;
            counter++;
        }
        // cout << counter << endl;
        temp = head;
        if (pos > 0 && pos <= counter)
        {
            int icounter = 0;
            while (icounter != pos - 1)
            {
                icounter++;
                temp = temp->next;
            }
            // cout << temp->val << endl;
            // cout << icounter << endl;
            Node *delNode = temp->next;
            temp->next = temp->next->next;
            free(delNode);
        }
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
    CLinkedList cll1;
    cll1.insertAtHead(6);
    cll1.insertAtHead(5);
    cll1.insertAtHead(4);
    cll1.insertAtHead(3);
    cll1.insertAtHead(2);
    cll1.insertAtHead(1);
    cll1.display();
    // cll1.insertAtMiddle(100);
    // cll1.insertAtPos(100, 6);
    // cll1.insertAtEnd(100);
    // cll1.deleteAtEnd();
    // cll1.deleteAtHead();
    // cll1.deleteAtMiddle();
    cll1.deleteAtPos(1);
    cll1.display();

    return 0;
}