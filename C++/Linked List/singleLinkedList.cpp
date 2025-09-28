#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        newNode->next = head;
        head = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void deleteNode(int val)
    {
        Node *temp = head;
        Node *Prevtemp = head;
        while (temp->data != val)
        {
            Prevtemp = temp;
            temp = temp->next;
        }
        cout << temp->data << " deleted" << endl;
        Prevtemp->next = temp->next;
        display();
    }
};

int main()
{
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtBeginning(0);
    list.insertAtBeginning(-1);
    list.insertAtBeginning(-2);
    list.display();

    list.deleteNode(3);

    return 0;
}