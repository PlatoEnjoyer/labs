#include <iostream>
#include <cmath>


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

    void print()
    {
        Node* node = head;
        while (node)
        {
            std::cout << node->data << ' ';
            node = node->next;
        }
    }

    int len()
    {
        Node* node = head;
        int count = 0;
        while (node)
        {
            count += 1;
            node = node->next;
        }
        
        return count;
    }
};

void get_numbers(int n, OneLinkedList& lst)
{
    int k = 0;
    while (k < n)
    {
        int data;
        std::cin >> data;
        lst.push_back(data);
        k++;
    }
}

bool is_sorted_by_first_digit(OneLinkedList& lst)
{
    Node* prev_node = lst.head;
    Node* node = prev_node->next;
    while (node)
    {
        int first_digit = node->data;
        while(first_digit / 10 != 0)
        {
            first_digit /= 10;
        }

        int prev_first_digit = prev_node->data;
        while (prev_first_digit / 10 != 0)
        {
            prev_first_digit /= 10;
        }
        
        if (first_digit > prev_first_digit)
        {
            return false;
        }

        prev_node = node;
        node = node->next;
    }
    
    return true;
}

bool is_sorted_by_last_digit(OneLinkedList& lst)
{
    Node* prev_node = lst.head;
    Node* node = prev_node->next;

    while (node)
    {
        int prev_last_digit = prev_node->data % 10;
        int last_digit = node->data % 10;

        if (last_digit > prev_last_digit)
        {
            return false;
        }

        prev_node = node;
        node = node->next;
    }

    return true;
}

void erase_single_digit_numbers(OneLinkedList& lst)
{
    Node* node = lst.head;
    int k = 0;

    while (node)
    {
        if (node->data < 10)
        {
            lst.erase(k);
            k--;
        }
        k++;
        node = node->next;
    }
}

bool is_palindrome_number(int n)
{
    if (n / 10 == 0)
    {
        return false;
    }

    while (n > 9)
    {
        int last_digit = n % 10;
        n /= 10;

        int k = 0;
        int first_digit = n;
        while (first_digit / 10 != 0)
        {
            k++;
            first_digit /= 10;
        }
    
        if (first_digit != last_digit)
        {
            return false;
        }

        n -= std::pow(10, k) * first_digit;
    }
    
    return true;
}

void double_palindroms(OneLinkedList& lst)
{
    Node* node = lst.head;
    int k = 0;

    while (node)
    {
        if (is_palindrome_number(node->data))
        {
            lst.insert(k, node->data);
            node = node->next;
            k++;
        }
        node = node->next;
        k++;
    }
}

void sort_lst_by_last_digit(OneLinkedList& lst)
{
    int n = lst.len();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            Node* left = lst.getNode(j);
            Node* right = lst.getNode(j + 1);
            if (left->data % 10 > right->data % 10)
            {
                int tmp = left->data;
                left->data = right->data;
                right->data = tmp;
            }
        }
    }
}


/*
Ввести последовательность натуральных чисел. Если последовательность упорядочена по невозрастанию первой или последней цифры, 
удалить из последовательности однозначные числа и продублировать числа - палиндромы длиной более одной цифры. 
В противном случае упорядочить последовательность по неубыванию первой цифры. 
Последовательность хранить в односвязном списке.
*/

int main()
{
    OneLinkedList lst;
    get_numbers(3, lst);

    if (is_sorted_by_first_digit(lst) or is_sorted_by_last_digit(lst))
    {
        erase_single_digit_numbers(lst);
        double_palindroms(lst);
    }
    else
    {
        sort_lst_by_last_digit(lst);
    }

    lst.print();
    return 0;
}