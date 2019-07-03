# include <iostream>
using namespace std;


class Stack{
    int *stck;
    int tos;
    int maxSize;
public:
    Stack();
    Stack(int size);
    void push(int num);
    int pop();
    bool isEmpty();
    int Top();
    int getSize();
    ~Stack();
};


Stack::Stack(){
    stck = new int[10];
    tos = 0;
    maxSize = 10;
}

Stack::Stack(int size){
    stck = new int[size];
    tos = 0;
    maxSize = size;
}

bool Stack::isEmpty(){
    return (!tos);
}

int Stack::getSize()
{
    return tos;
}

int Stack::Top(){
    int val = -1;

    if (tos == 0){
        cout << "Stack is empty" << endl;
    }
    else{

        val = stck[tos-1];
    }
    return val;
}

void Stack::push(int num){
    if (tos == maxSize)
    {
        cout << "Stack is increased" << endl;
        stck = (int*)realloc(stck, (maxSize+10)*sizeof(int));
    }
    stck[tos++] = num;
}


int Stack::pop(){
    int value = -1;
    if (tos == 0){
        cout << "Stack is empty" << endl;
    }
    else{
        value = stck[--tos];
		stck = (int*) realloc(stck, (maxSize-1)*sizeof(int));
    }
    return value;
}



Stack::~Stack(){
    delete[] stck;
}


int main(){
    Stack mainStack;
    int c;
    while(1)
    {
        cout<<"1:	Push an element"<<endl;
        cout<<"2:	Pop"<<endl;
        cout<<"3:	Top"<<endl;
        cout<<"4:	Size"<<endl;
        cout<<"5:	Empty check"<<endl;
        cout<<"6:	Exit"<<endl;
        cin>>c;

        if(c==1)
        {
            int a;
            cout<<"Input a number: ";
            cin>>a;
            mainStack.push(a);
            cout<<endl;
        }

        if(c==2)
        {
            cout<<"Popped: "<<mainStack.pop()<<endl;
        }
        if(c==3)
        {
            cout<<"Top of mainStack is: "<<mainStack.Top()<<endl;
        }
        if(c==4)
        {
            cout<<"Size of mainStack is: "<<mainStack.getSize()<<endl;
        }
        if(c==5)
        {
            if(mainStack.isEmpty())
                cout<<"Empty"<<endl;
            else
                cout<<"Not empty"<<endl;
        }

        if(c==6)
        {
            cout<<"Overall popping mainStack: "<<endl;
            while(!mainStack.isEmpty())
                cout<<mainStack.pop()<<" ";
            cout<<endl;
            cout<<"Program ended..."<<endl;
            break;
        }
    }
    return 0;
}
