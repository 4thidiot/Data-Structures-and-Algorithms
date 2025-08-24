//Used this video: https://www.youtube.com/watch?v=ZOS1fKa_WUY&list=PLQEaRBV9gAFtzpMBLVYMh0bPC4Qk_EKbs

#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int size;
    int top;
    
    public:
    
    //constructor to create the Stack
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int[s];
    }
    
    //will implement: 1. Push 2. Pop 3. Peek 4. IsEmpty 5. IsSize
    
    void push(int value)
    {
        if(top==size-1)
            cout<<"Stack overflow\n";

        else
        {
            top++;
            arr[top]=value;
        }
    }
    
    void pop()
    {
        if(top==-1)
            cout<<"Stack Underflow\n";
        else
            top--;
    }
    
    int peek()
    {
        if(top==-1)
        {
            cout<<"Stack is empty\n";
            return -1;
        }
        else
            return arr[top];
    }
    
    bool IsEmpty()
    {
        return top == -1;
    }
    
    int IsSize()
    {
        return top+1;
    }
};



int main() 
{
	Stack S(5);
	S.push(5);
	S.push(6);
	S.push(8);
	S.pop();
// 	S.pop();
// 	S.pop();
	cout<<S.peek()<<endl;
	cout<<S.IsSize()<<endl;
	cout<<S.IsEmpty()<<endl;
	

}
