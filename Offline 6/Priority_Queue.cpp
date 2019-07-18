#include<bits/stdc++.h>
using namespace std;

class Priority_Queue
{
    int* arr;
    int capacity;

public:
    Priority_Queue()
    {
        capacity = 10;
        arr = new int[10];
        arr[0] = 0;  //array size in arr[0]
    }


    int Parent(int i)
    {
        return i/2;
    }
    int Left(int i)
    {
        return 2*i;
    }
    int Right(int i)
    {
        return 2*i+1;
    }
    void Heapify(int i)
    {
        int left = Left(i);
        int right = Right(i);
        int largest;
        if(left<=arr[0] && arr[left]>arr[i])
            largest = left;
        else
            largest = i;

        if(right<=arr[0] && arr[right]>arr[largest])
            largest = right;
        if (largest != i)
        {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest]=temp;
            Heapify(largest);
        }
    }


    void Heap_Increase_Key(int i, int key)
    {
        if(key<arr[i])
        {
            cout<<"Error! New key is smaller than current key"<<endl;
        }
        arr[i] = key;
        while(i>1 && arr[Parent(i)]<arr[i])
        {
            int temp = arr[i];
            arr[i] = arr[Parent(i)];
            arr[Parent(i)] = temp;
            i = Parent(i);
        }
    }

    void Heap_Decrease_Key(int i, int key)
    {
        if(key>arr[i])
        {
            cout<<"Error! New key is bigger than current key"<<endl;
        }
        arr[i] = key;
        while(i>0 && arr[Parent(i)]>arr[i])
        {
            int temp = arr[i];
            arr[i] = arr[Parent(i)];
            arr[Parent(i)] = temp;
            i = Parent(i);
        }
    }

    void Priority_Queue_Insert(int key)
    {

        arr[0]++;
        if(arr[0]>=capacity)
        {
            capacity+=10;
            arr = (int*) realloc(arr, (capacity+10)*sizeof(int));
        }

        arr[arr[0]] = -INT_MAX;
        Heap_Increase_Key(arr[0], key);
        cout<<"inserted "<<key<<endl;
    }

    int FindMax()
    {
        if(arr[0]>0)
            return arr[1];
        else
        {
            cout<<"No value in heap"<<endl;
            return 0;
        }
    }

    int ExtractMax()
    {
        if(arr[0]<1)
            {
                cout<<"Heap underflow"<<endl;
                return 0;
            }
        int max = arr[1];
        arr[1] = arr[arr[0]];
        arr[0]--;
        Heapify(1);
        return max;
    }
    int size()
    {
        return arr[0];
    }
    void Print()
    {
        for(int i=1; i<=arr[0]; i++)
        {
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }
};

int main()
{
    Priority_Queue pq;

    /*pq.Priority_Queue_Insert(2);
    pq.Priority_Queue_Insert(6);
    pq.Priority_Queue_Insert(4);
    pq.Priority_Queue_Insert(1);
    pq.Priority_Queue_Insert(7);
    pq.Priority_Queue_Insert(10);

    cout<<"size is: "<<pq.size()<<endl;
    cout<<"max is "<<pq.ExtractMax()<<endl;
    cout<<"size is: "<<pq.size()<<endl;
    cout<<"max is "<<pq.ExtractMax()<<endl;
    cout<<"size is: "<<pq.size()<<endl;
    cout<<"max is "<<pq.ExtractMax()<<endl;
    cout<<"size is: "<<pq.size()<<endl;
    cout<<"max is "<<pq.ExtractMax()<<endl;
    cout<<"size is: "<<pq.size()<<endl;
    cout<<"max is "<<pq.ExtractMax()<<endl;
    cout<<"size is: "<<pq.size()<<endl;
    cout<<"max is "<<pq.ExtractMax()<<endl;
    cout<<"size is: "<<pq.size()<<endl;
    cout<<"max is "<<pq.ExtractMax()<<endl;
    cout<<"size is: "<<pq.size()<<endl;*/

    while(1)
    {
        cout<<"1. insert"<<endl;
        cout<<"2. FindMax"<<endl;
        cout<<"3. ExtractMax"<<endl;
        cout<<"4. IncreaseKey"<<endl;
        cout<<"5. DecreaseKey"<<endl;
        cout<<"6. Print"<<endl;
        cout<<"7. quit"<<endl;

        int ch;
        cin>>ch;
        if(ch==1)
        {
            int key;
            cout<<"input insert value : ";
            cin>>key;
            pq.Priority_Queue_Insert(key);
        }
        else if(ch==2)
        {
            cout<<"Max value is : "<<pq.FindMax()<<endl;
        }
        else if(ch==3)
        {
            cout<<"Extracted max. Max is : "<<pq.ExtractMax()<<endl;
        }
        else if(ch==4)
        {
            cout<<"Index = ";
            int index;
            cin>>index;
            cout<<"NewValue = ";
            int newValue;
            cin>>newValue;
            pq.Heap_Increase_Key(index, newValue);
        }
        else if(ch==5)
        {
            cout<<"Index = ";
            int index;
            cin>>index;
            cout<<"NewValue = ";
            int newValue;
            cin>>newValue;
            pq.Heap_Decrease_Key(index, newValue);
        }
        else if(ch==6)
        {
            cout<<"Printing the Queue : ";
            pq.Print();
        }
        else if(ch==7)
            {
                cout<<"Program Ended"<<endl;
                break;
            }
    }

    return 0;
}
