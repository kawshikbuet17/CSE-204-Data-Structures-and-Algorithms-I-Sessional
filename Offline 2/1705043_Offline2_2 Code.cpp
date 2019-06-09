#include<bits/stdc++.h>
#include<chrono>
using namespace std;



void PowerSet(char *arr, int SetSize)
{
    long long int PowSetSize = pow(2, SetSize);
    long long int i, j;

    for(i = 0; i < PowSetSize; i++)
    {
        cout<<"No "<<i+1<<" Subset : ";
        for(j = 0; j < SetSize; j++)
        {
            if((1<<j) & i)
                cout << arr[j];
        }
        cout << endl;
    }
}


int main()
{
    srand(time(NULL));
    int n;
    cout<<"Input the value of n : "<<endl;
    cin>>n;
    char listt[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *arr = new char[n];

    cout<<"Randomly generated set : { ";
    for(int i = 0; i<n; i++)
    {
        arr[i] = listt[rand()%60];
        cout<<arr[i]<<" ";
    }
    cout<<"}"<<endl;
    cout<<"POWERSET of given set: "<<endl;

    //clock_t time1 = clock();

    auto time1 = chrono::high_resolution_clock::now();

    PowerSet(arr, n);
    //clock_t time2 = clock();

    auto time2 = chrono::high_resolution_clock::now();

    double time = chrono::duration_cast<chrono::nanoseconds>(time2-time1).count();

    cout<<fixed<<"Time is : "<<time<<" nanosec"<<endl;
}
