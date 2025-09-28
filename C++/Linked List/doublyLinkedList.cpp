#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        prev = NULL;
        data = val;
        next = NULL;
    }
};
class DoublyLinkedList{
    private:
        Node *head;

    public:
        DoublyLinkedList()
        {
            head = NULL;
        }
};

main()
{
    return 0;
}