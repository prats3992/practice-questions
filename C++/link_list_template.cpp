#include <iostream>

using namespace std;

template <typename T>class ChainNode
{
    template <typename U>friend class Chain;

public:
    ChainNode(T element, ChainNode<T> *next) // constructor
    {
        data = element;
        link = next;
    }

private:
    T data;
    ChainNode<T> *link;
};

template <typename T>class Chain
{
private:
    ChainNode<T> *first;

public:
    Chain() { first = NULL; } // constructor
    void insertbegin(T);
    void insertend(T);
    void remove(int);
    void printchain();
    int countNodes();
    void insertAfter(T, int); // inserts a node after finding the specified data
    ~Chain()
    { // destructor
        ChainNode<T> *tmp;
        while (first)
        {
            tmp = first->link;
            delete first;
            first = tmp;
        }
    }
};

template <typename T>void Chain<T>::printchain()
{
    cout << "\n"
         << endl;
    ChainNode<T> *node = first;
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->link;
    }
    cout << "\n"
         << endl;
}

template <typename T>void Chain<T>::insertbegin(T x)
{
    if (first) // list already exists
    {
        ChainNode<T> *newNode = new ChainNode(x, first);
        first = newNode;
    }
    // first=new ChainNode(x,first);
    else
        first = new ChainNode<T>(x, 0);
}

template <typename T>void Chain<T>::insertend(T x)
{
    ChainNode<T> *node = new ChainNode<T>(x,NULL);
    if (first) // list already exists
    {
        ChainNode<T> *temp = first;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = node;
    }
    else // empty list; creating the first node of the list
        first = new ChainNode<T>(x, 0);
}

template <typename T>void Chain<T>::remove(int x)
{

    if (first == NULL)
    {
        cout << "UNDERFLOW !" << endl;
    }
    if (x >= countNodes() || x < 0)
    {
        cout << "x out of bounds !" << endl;
    }
    if (x == 1)
    {
        if (first == NULL)
        {
            cout << "Chain is empty !" << endl;
        }
        first = first->link;
        cout << "Head removed" << endl;
    }
    int count = 1;
    ChainNode<T> *temp = first;
    while (temp != NULL)
    {
        if (count == x - 1)
        {
            temp->link = temp->link->link;
            cout << "Item removed at x " << x << endl;
            break;
        }
        count++;
        temp = temp->link;
    }
}

template <typename T>void Chain<T>::insertAfter(T x, int pos)
{
    if (pos > countNodes() || pos < 0)
    {
        cout << "pos out of bounds !" << endl;
        return;
    }
    ChainNode<T> *node = new ChainNode<T>(x,NULL);
    int count = 0;
    ChainNode<T> *temp = first;
    while (temp != NULL && count < pos)
    {
        if (count == pos - 1)
        {
            if (temp->link != NULL)
            {
                node->link = temp->link;
            }
            temp->link = node;
            cout << "New node added at pos " << pos << endl;
            break;
        }
        count++;
        temp = temp->link;
    }
}

template <typename T>int Chain<T>::countNodes()
{
    int count = 1;
    ChainNode<T> *temp = first;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}
int main()
{
    Chain<int> c;
    short int choice;
    int data, item;
    do
    {
        cout << endl
             << "   Insert at: 1. Beginning 2. End  3. After an item 4. Stop " << endl;
        cout << "   Enter your choice (1/2/3/4): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Data to be inserted at beginning: ";
            cin >> data;
            c.insertbegin(data);
            break;
        case 2:
            cout << "Data to be inserted at end: ";
            cin >> data;
            c.insertend(data);
            break;
        case 3:
            cout << "Data to be inserted: ";
            cin >> data;
            cout << "Item after which data is to be inserted: ";
            cin >> item;
            c.insertAfter(data, item);
            break;
        }
    } while (choice != 4);
    c.printchain();
    cout << "Enter node to be removed : ";
    cin >> data;
    c.remove(data);
    c.printchain();
    return 0;
}