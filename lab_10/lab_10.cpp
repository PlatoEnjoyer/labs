#include <iostream>


class Node
{
    public:
    int data;
    Node* next;

    public:
    Node (int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class OneLinkedList
{
    public:
    Node* head;
    Node* tail;

    public:
    OneLinkedList ()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    ~OneLinkedList ()
    {
        while(head != NULL)
        {
            pop_front();
        }
    }
    
    void pop_front()
    {
        if (head == NULL)
        {
            return;
        }

        if (head == tail)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            return;
        }

        Node* tmp = head;
        head = tmp -> next;
        delete tmp;
    }

    void push_back (int data)
    {
        Node* node = new Node(data);

        if (head == NULL)
        {
            head = node;
        }

        if (tail != NULL)
        {
            tail->next = node;
        }
        tail = node;
    }

    void push_front(int data)
    {
        Node* node = new Node(data);
        node->next = head;
        head = node;
    }

    void pop_back()
    {
        if (tail == NULL)
        {
            return;
        }

        if (head == tail)
        {
            delete tail;
            head = tail = NULL;
        }

        Node* node = head;
        for (;node->next != tail;)
        {
            node = node->next;
        }
        node->next = NULL;
        delete tail;
        tail = node;
    }

    Node* getNode(int k)
    {
        if (k < 0)
        {
            return NULL;
        }

        Node* node = head;
        int count = 0;
        while (node && count != k && node->next != NULL)
        {
            node = node->next;
            count++;
        }

        if (count == k)
        {
            return node;
        }
        else
        {
            return NULL;
        }
    }

    void insert(int k, int data)
    {
        Node* left = getNode(k);
        if (left == NULL)
        {
            return;
        }

        Node* right = left->next;
        Node* node = new Node(data);
        left->next = node;
        node->next = right;

        if (right == NULL)
        {
            tail = node;
        }
    }

    void erase(int k)
    {
        if (k < 0)
        {
            return;
        }

        if (k == 0)
        {
            pop_front();
            return;
        }

        Node* left = getNode(k-1);
        Node* node = left->next;

        if (node == NULL)
        {
            return;
        }

        Node* right = node->next;
        left->next = right;

        if (node == tail)
        {
            left = tail;
        }

        delete node;
    }
};




int main()
{
    OneLinkedList lst;
    return 0;
}