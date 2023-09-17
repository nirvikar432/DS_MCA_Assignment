// 15. Program to count number of nodes in linear linked list

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

    void display()
    {
        Node *temp = head;
        int count = 0;
        while (temp)
        {
            cout << temp->val << "->";
            temp = temp->next;
            count++;
        }
        cout << "NULL";
        cout << endl;
        cout << "Number of Nodes : " << count;
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
    return 0;
}

/*
1->2->3->4->5->6->NULL
Number of Nodes : 6

*/