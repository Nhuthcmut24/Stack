#include <iostream>
using namespace std;

template <class T>
class SLinkedList
{
public:
    class Node // use inside of SLinkedList
    {
    private:
        T data;
        Node *next;

    public:
        Node()
        {
            this->next = nullptr;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next)
        {
            this->data = data;
            this->next = next;
        }
    };

protected:
    Node *head;
    Node *tail;
    int count;

public:
    SLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
    }
    ~SLinkedList()
    {
    }
    void add(const T &e);
    void add(int index, const T &e);
    int size();
    bool empty();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    void clear();
    T removeAt(int index);
    bool removeItem(const T &item);
};

template <class T>
void SLinkedList<T>::add(const T &e) // Insert in the end of Singly linked list
{
    Node *new_node = new Node(e, nullptr);
    if (this->head != nullptr)
    {
        Node *temp = this->head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        count++;
        this->tail = new_node;
    }
    else
    {
        this->head = new_node;
        this->count++;
        this->tail = new_node;
    }
}
template <class T>
void SLinkedList<T>::add(int index, const T &e) // Insert element by index
{
    if (index >= 0 && index <= count)
    {
        if (index == 0)
        {
            if (this->head)
            {
                Node *new_node = new Node(e, head);
                this->head = new_node;
                count++;
            }
            else
            {
                Node *new_node = new Node(e, nullptr);
                this->head = new_node;
                count++;
                tail = head;
            }
        }
        else if (index == count)
        {
            add(e);
        }
        else
        {
            Node *temp = this->head;
            Node *pre = temp;
            int idx = 0;
            while (idx < index)
            {
                pre = temp;
                temp = temp->next;
                idx++;
            }
            Node *new_node = new Node(e, temp);
            count++;
            pre->next = new_node;
        }
    }
}

template <class T>
int SLinkedList<T>::size() // Size of list
{
    return this->count;
}

template <class T>
T SLinkedList<T>::get(int index) // Get element by index
{
    if (index < 0 || index >= this->size())
    {
        throw std::out_of_range("index is out of range!");
    }
    Node *temp = this->head;
    int idx = 0;
    while (idx < index)
    {
        temp = temp->next;
        idx++;
    }
    return temp->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T &e)
{
    if (index >= 0 && index < this->size())
    {
        int idx = 0;
        Node *temp = this->head;
        while (idx < index)
        {
            temp = temp->next;
            idx++;
        }
        temp->data = e;
    }
}

template <class T>
bool SLinkedList<T>::empty()
{
    if (this->size())
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class T>
int SLinkedList<T>::indexOf(const T &item)
{
    int idx = 0;
    Node *temp = head;
    while (temp != nullptr && temp->data != item)
    {
        temp = temp->next;
        idx++;
    }
    if (idx < this->size())
    {
        return idx;
    }
    else
    {
        return -1;
    }
}

template <class T>
bool SLinkedList<T>::contains(const T &item)
{
    Node *temp = this->head;
    while (temp && temp->data != item)
    {
        temp = temp->next;
    }
    if (temp)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= this->size())
    {
        throw std::out_of_range("index is out of range!");
    }
    if (index == 0)
    {
        if (head == tail)
        {
            tail = nullptr;
        }
        Node *temp = this->head;
        this->head = this->head->next;
        T res = temp->data;
        temp = nullptr;
        count--;
        return res;
    }
    else if (index == this->size() - 1)
    {
        Node *temp = this->head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        T res = temp->next->data;
        temp->next = nullptr;
        tail = temp;
        count--;
        return res;
    }
    else
    {
        Node *temp = this->head;
        Node *pre = temp;
        int idx = 0;
        while (idx < index)
        {
            pre = temp;
            temp = temp->next;
            idx++;
        }
        T res = temp->data;
        pre->next = temp->next;
        temp = nullptr;
        count--;
        return res;
    }
}

template <class T>
bool SLinkedList<T>::removeItem(const T &item)
{
    Node *temp = this->head;
    int idx = 0;
    while (idx < this->size() && temp->data != item)
    {
        temp = temp->next;
        idx++;
    }
    if (idx == this->size())
    {

        return false;
    }
    else
    {
        removeAt(idx);
        return true;
    }
}

template <class T>
void SLinkedList<T>::clear()
{
}

int main()
{
    return 0;
}