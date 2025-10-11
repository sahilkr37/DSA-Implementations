#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;
    Node(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};
class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newNode->prev = temp;
            temp->next = newNode;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void deleteNode(Node *delNode)
    {
        if (delNode == NULL)
            return;
        if (delNode->prev != NULL)
            delNode->prev->next = delNode->next;
        else
            head = delNode->next;

        if (delNode->next != NULL)
            delNode->next->prev = delNode->prev;
        free(delNode);
    }

    Node *getHead()
    {
        return head;
    }

    void reverse()
    {
        if (head == NULL || head->next == NULL)
            return;

        Node *back = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            back = curr->prev;
            curr->prev = curr->next;
            curr->next = back;

            curr = curr->prev;
        }
        head = back->prev;
    }
};

int main()
{
    DoublyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    list.display();

    // list.deleteNode(list.getHead());
    // list.display();
    list.reverse();
    list.display();
    return 0;
}