#include <iostream>



class Node 
{
public:
    int data;
    Node* prev;
    Node* next;

public:
    Node(int data)
    {
        this->data = data;
        this->prev = this->next = NULL;
    }   
};

class LinkedList
{
public:
    Node* head;
    Node* tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    ~LinkedList()
    {
        while (head != NULL)
        {
            pop_front();
        }
    }

    Node* push_front(int data)
    {
        Node *ptr = new Node(data);
        ptr->next = head;
        if (head != NULL)
        {
            head->prev = ptr;
        }
        if (tail == NULL)
        {
            tail = ptr;
        }
        head = ptr;

        return ptr;
    }

    Node* push_back(int data)
    {
        Node *ptr = new Node(data);
        ptr->prev = tail;
        if (tail != NULL)
        {
            tail->next = ptr;
        }
        if (head == NULL)
        {
            head = ptr;
        }
        tail = ptr;

        return ptr;
    }

    void pop_front()
    {
        if (head == NULL)
        {
            return;
        }

        Node* ptr = head->next; 
        if (ptr != NULL)
        {
            ptr->prev == NULL;
        }
        else
        {
            tail = NULL;
        }

        delete head;
        head = ptr;
    }

    void pop_back()
    {
        if (tail == NULL)
        {
            return;
        }

        Node* ptr = tail->prev; 
        if (ptr != NULL)
        {
            ptr->next == NULL;
        }
        else
        {
            head = NULL;
        }

        delete tail;
        tail = ptr;
    }

    Node* getAt(int index)
    {
        Node* ptr = head;
        int n = 0;

        while (n != index && ptr)
        {
            ptr = ptr->next;
            n++;
        }

        return ptr;
    }

    Node* operator [] (int index)
    {
        return getAt(index);
    }

    Node* insert(int idnex, int data)
    {
        Node* right = getAt(idnex);
        if (right == NULL)
        {
            return push_back(data);
        }

        Node* left = right->prev;
        if (left == NULL)
        {
            return push_front(data);
        }

        Node* ptr = new Node(data);
        ptr->prev = left;
        left->next = ptr;
        ptr->next = right;
        right->prev = ptr;

        return ptr;
    }

    void erase(int index)
    {
        Node* ptr = getAt(index);
        if (ptr == NULL)
        {
            return;
        }

        if (ptr->prev == NULL)
        {
            pop_front();
            return;
        }

        if (ptr->next == NULL)
        {
            pop_back();
            return;
        }

        Node* left = ptr->prev;
        Node* right = ptr->next;
        left->next = right;
        right->prev = left;

        delete ptr;
    }

};

int main()
{
    LinkedList lst;
    lst.push_back(1);
    lst.push_back(3);
    lst.push_back(8);
    lst.push_back(4);
    lst.push_back(1);
    lst.insert(2, 177);
    lst.insert(20, -10);
    lst.erase(3);
    lst.erase(30);

    for(Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)
    {
        std::cout << ptr->data << std::endl;
    }

    std::cout << lst[1] << std::endl;
    return 0;
}