#include <iostream>
#include <chrono>

using namespace std;


class ArrayStack
{
private:
    int top;
    int* arr;
    int capasity;

public:
    ArrayStack(int size)
    {
        top = -1;
        capasity = size-1;
        arr = new int[size];
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top >= capasity);
    }

    void push(int x)
    {
        top ++;
        if (isFull()){
            cout << "Stack overflow" << endl;
        }
        else{
            arr[top] = x;
        }
    }

    int pop()
    {
        if (isEmpty()){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else{
            top--;
            return arr[top+1];
        }
    }

    void display()
    {
        for (int i=top; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << "" << endl;
    }

};

int main()
{
    ArrayStack stack1(20);
    cout << "Stack using Array" << endl;
    auto start1 = chrono::high_resolution_clock::now();
    stack1.push(8);
    stack1.push(10);
    stack1.push(5);
    stack1.push(11);
    stack1.push(15);
    stack1.push(23);
    stack1.push(6);
    stack1.push(18);
    stack1.push(20);
    stack1.push(17);
    stack1.display();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.display();
    stack1.push(4);
    stack1.push(30);
    stack1.push(3);
    stack1.push(1);
    stack1.display();
    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();
    cout << "Time taken for Array Stack = " << duration1 << "ns" << endl;
    cout << "" << endl;
    
    return 0;
}
