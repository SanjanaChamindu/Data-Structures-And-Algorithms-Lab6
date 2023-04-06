class Node
{
public:
    int data;
    Node* next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

class LinkedListStack
{
private:
    Node* head;

public:
    LinkedListStack()
    {
        head = nullptr;
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }

    void push(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    int pop()
    {
        if (isEmpty()){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int data = head->data;
        head = head->next;
        return data;
    }

    void display()
    {
        Node* current = head;

        while (current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << "" << endl;
    }
};


int main()
{

    LinkedListStack stack2;
    cout << "Stack using LinkedList" << endl;
    auto start2 = chrono::high_resolution_clock::now();
    stack2.push(8);
    stack2.push(10);
    stack2.push(5);
    stack2.push(11);
    stack2.push(15);
    stack2.push(23);
    stack2.push(6);
    stack2.push(18);
    stack2.push(20);
    stack2.push(17);
    stack2.display();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.display();
    stack2.push(4);
    stack2.push(30);
    stack2.push(3);
    stack2.push(1);
    stack2.display();

    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();
    cout << "Time taken for LinkedList Stack = " << duration2 << "ns" << endl;
    cout << "" << endl;
    
    return 0;
}
