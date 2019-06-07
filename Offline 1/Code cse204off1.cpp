#include<bits/stdc++.h>
using namespace std;

int BinSearch(int arr[], int n, int x)
{
    int first = 0;
    int last = n-1;
    int mid;
    int flag = 0;

    while(first<=last)
    {
        mid = (first+last)/2;
        if(x==arr[mid])
        {
            flag = 1;
            return mid+1;
        }
        else
        {
            if(x>arr[mid])
                first = mid + 1;
            else
                last = mid - 1;
        }
    }
    if (flag==0)
        return -1;
}

int LinearSearch(int arr[], int n, int x)
{
    int flag = 0;
    for(int i=0; i<n; i++)
    {
        if(x==arr[i])
        {
            flag = 1;
            return i+1;
        }
    }
    if(flag==0)
        return -1;
}

void BubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              {
                  int temp;
                  temp = arr[j];
                  arr[j] = arr[j+1];
                  arr[j+1] = temp;
              }
}

int main()
{
    int n=10, x, mid;
    srand (time(NULL));

    cout<<"Input the range of Array : "<<endl;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++)
    {
        arr[i] = rand()%10000;
    }


    BubbleSort(arr, n);
    cout<<"After sorting :"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    double total_lin_Time = 0;
    int key = rand()%10000;
    for(int i=0; i<10; i++)
    {
        clock_t LStime1 = clock();
        LinearSearch(arr, n, key);
        clock_t LStime2 = clock();
        double LStime = double(LStime2 - LStime1)*1000000000/double(CLOCKS_PER_SEC);
        total_lin_Time += LStime;
    }
    cout<<setprecision(10)<<fixed<<"Linear Search result : "<<total_lin_Time/10<<endl;


    double total_Bin_Time = 0;
    for(int i=0; i<10; i++)
    {
        clock_t BStime1 = clock();
        BinSearch(arr, n, key);
        clock_t BStime2 = clock();
        double BStime = double(BStime2 - BStime1)*1000000000/double(CLOCKS_PER_SEC);
        total_Bin_Time += BStime;
    }
    cout<<setprecision(10)<<fixed<<"Binary Search time : "<<total_Bin_Time/10<<endl;

}
