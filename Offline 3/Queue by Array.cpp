#include<iostream>
using namespace std;

class Queue
{
    int *queue;
    int maxsize;
    int front_num;
    int rear_num;
    int toq;
public:
    Queue()
    {
        queue = new int[10];
        maxsize = 10;
        //toq=0;
        front_num = 0;
        rear_num = -1;
    }

    bool empty()
    {
        if(front_num > rear_num)
            return true;
        else
            return false;
    }

    int size()
    {
        return rear_num - front_num + 1 ;
    }

    void enqueue(int x)
    {
        if(rear_num==maxsize-1)
        {
            queue = (int*)realloc(queue,sizeof(int)*(maxsize+10));
            maxsize +=10;
        }
        queue[++rear_num] = x;

    }

    int dequeue()
    {
        int value=-1;
        if(empty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            value = queue[front_num++];
            //queue = (int*) realloc(queue,sizeof(int)*(maxsize-1));
        }

        return value;
    }

    int front()
    {
        if(!empty())
            return queue[front_num];
        else
            return -1;
    }
    int rear()
    {
        if(!empty())
            return queue[rear_num];
        else
            return -1;

    }


};

int main()
{
Queue qu;
while(1)
{
    cout<<"\n1.empty()"<<endl;
    cout<<"2.size()"<<endl;
    cout<<"3.front()"<<endl;
    cout<<"4.rear()"<<endl;
    cout<<"5.enqueue()"<<endl;
    cout<<"6.dequeue()"<<endl;
    //cout<<"7.Exit"<<endl;
    int input;
    cin>>input;
    if(input==1)
    {
        cout<<qu.empty()<<endl;
    }
    else if(input==2)
    {
        cout<<qu.size()<<endl;
    }
    else if(input==3)
    {
       cout<<"Front is = "<<qu.front()<<endl;
    }
    else if(input==4)
    {
    cout<<"Rear is = "<<qu.rear()<<endl;;
    }
    else if(input==5)
    {
        int x;
        cout<<"Enter the number to be added"<<endl;
        cin>>x;
        qu.enqueue(x);
    }
    else if(input==6)
    {
        cout<<qu.dequeue()<<endl;
    }

}

}
