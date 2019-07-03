/*
Ekta input N dewa hobe. 0 theke N porjonto
sobgula songkhar Binary print dite hobe
only QUEUE use kore
*/



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
    Queue q;
    int n;
    cout<<"Input the value of N : "<<endl;
    cin>>n;

    q.enqueue(0);
    cout<<q.front()<<endl;
    q.dequeue();

    q.enqueue(1);
    while(n--)
    {
        int temp = q.front();
        q.dequeue();
        cout<<temp<<endl;

        int temp2 = temp * 10;

        q.enqueue(temp2 + 0);
        q.enqueue(temp2 + 1);
    }
}

