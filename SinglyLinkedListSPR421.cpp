#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value, Node* next) : data(value), next(next) {}
};

class List {
    Node* head;
public:
    List()
    {
        head = nullptr;
    }
    void AddToHead(int data)
    {
        Node* newNode = new Node(data, head);
        /*newNode->data = data;
        newNode->next = head;*/
		head = newNode;
    }
    void AddToTail(int value)
    {
        Node* newNode = new Node(value, nullptr);
        if (head == nullptr)
        {
			head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
		    current->next = newNode;
        }
        
    }
    void Show()const
    {
		Node* current = head;
        while (current!=nullptr)
        {
			cout << current->data << " "; 
            current = current->next;
        }
    }
    int GetElement(int pos)const
    {
		int count = 0;
        Node* current = head;
        while (current != nullptr)
        {
            if (pos-1 == count)
            {
				return current->data;
            }
			current = current->next;
            ++count;
        }
        return -1;
    }
    void DeleteFromTail()
    {
        if (head == nullptr)return;
        if (head->next == nullptr)
        {
            delete head;
			head = nullptr;
        }
        else {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        
    }
    ~List()
    {
        while (head != nullptr)
        {
            Node* temp = head;
			head = head->next;
            delete temp;
        }
    }
};

int main()
{
	List list;
	list.AddToHead(1);
	list.AddToHead(2);
	list.AddToHead(3);
	list.Show();
	cout << endl;
	list.AddToTail(4);
	list.AddToTail(5);
	list.Show();
	cout << endl;
    cout << list.GetElement(3);
    list.DeleteFromTail();
    list.DeleteFromTail();
    list.DeleteFromTail();
    list.DeleteFromTail();
    list.DeleteFromTail();
    list.DeleteFromTail();
    list.Show();
    
}
