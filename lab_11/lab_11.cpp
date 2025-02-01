#include <iostream>
#include <cmath>


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
        head = new Node(0);
        tail = new Node(1);
        tail->next = head;
        tail->prev = head;
        head->prev = tail;
        head->next = tail;
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
        ptr->prev = head;
        ptr->next = head->next;
        head->next->prev = ptr;
        head->next = ptr;
        return ptr;
    }

    Node* push_back(int data)
    {
        Node *ptr = new Node(data);
        ptr->next = tail;
        ptr->prev = tail->prev;
        tail->prev->next = ptr;
        tail->prev = ptr;
        return ptr;
    }

    void pop_front()
    {
        if (head->next == tail)
        {
            return;
        }

        Node *ptr = head->next;
        ptr->next->prev = head;
        head->next = ptr->next;
        delete ptr;
    }

    void pop_back()
    {
        if (head->next == tail)
        {
            return;
        }

        Node* ptr = tail->prev; 
        tail->prev = ptr->prev;
        ptr->prev->next = tail;
        delete ptr;
    }

    Node* getAt(int index)
    {
        if (head->next == tail)
        {
            return head;
        }

        Node* ptr = head->next;
        int n = 0;

        while (n != index && ptr != tail)
        {
            ptr = ptr->next;
            n++;
        }
        
        if (ptr == tail)
        {
            return ptr;
        }

        return ptr;
    }

    Node* operator [] (int index)
    {
        return getAt(index);
    }

    Node* insert(int index, int data)
    {
        Node* right = getAt(index);
        if (!right)
        {
            return push_back(data);
        }

        Node* left = right->prev;
        if (left == head)
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
        if (!ptr)
        {
            return;
        }

        if (ptr->prev == head)
        {
            pop_front();
            return;
        }

        if (ptr->next == tail)
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

    void print()
    {
        Node* ptr = head->next;
        while (ptr != tail)
        {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }

};

bool chek_palindrome_number(int n)
{
    if (n < 100)
    {
        return false;
    }

    int digits[3];
    for (int i = 0; i < 3; i++)
    {
        int curr = n % 10;
        n /= 10;
        digits[i] = curr;
    }
    if (digits[0] == digits[2])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void sort_linked_list(LinkedList& lst, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (lst[j]->data > lst[j+1]->data)
            {
                int tmp = lst[j]->data;
                lst[j]->data = lst[j+1]->data;
                lst[j+1]->data = tmp;
            }
        }
    }
}

bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }

    for (int i = 2; i < std::sqrt(n) + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;

}

bool is_ends_with_zero(int num)
{
    if (num % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    LinkedList lst;
    int n;
    std::cin >> n;
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        int el;
        std::cin >> el;
        lst.push_back(el);

        if (chek_palindrome_number(el))
        {
            flag = true;
        }
    }

    if (flag)
    {
        sort_linked_list(lst, n);
    }
    else
    {
        Node* ptr = lst.head->next;
        int i = 0;
        while (ptr != lst.tail)
        {
            if (is_prime(ptr->data) || is_ends_with_zero(ptr->data))
            {
                lst.insert(i, ptr->data);
                i++;
            }
            ptr = ptr->next;
            i++;
        }
    }
    
    lst.print();
    return 0;
}