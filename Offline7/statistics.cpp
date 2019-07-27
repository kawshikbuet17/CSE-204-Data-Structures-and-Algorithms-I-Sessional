#include <bits/stdc++.h>
#include<time.h>
using namespace std;

void reverseArr(int arr[], int n)
{
    for(int i=0; i<n/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

void merge(int arr[], int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int *L = new int[n1+1];
    int *R = new int[n2+1];

    for(int i=0; i<n1; i++)
    {
        L[i] = arr[p+i];
    }
    for(int i=0; i<n2; i++)
    {
        R[i] = arr[q+i+1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    for(int k=p; k<=r; k++)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int arr[], int p, int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p-1;
    for(int j=p; j<r; j++)
    {
        if(arr[j]<=x)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    return i+1;
}

void quickSort(int arr[], int p, int r)
{
    if(p<r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}


int main()
{
    srand (time(NULL));
    int choice, n, count;
    int size[] = {10, 50, 100, 200, 500, 1000, 5000, 10000};
    int loop = sizeof(size)/sizeof(size[0]);

    int *arr, *copyArr;
    auto t1=chrono::high_resolution_clock::now();
    auto t2=chrono::high_resolution_clock::now();
    double t, total;

    for(int i=0; i<loop; i++)
    {
        n = size[i];
        arr = new int[n];
        for(int i=0; i<n; i++)
            arr[i] = rand()%1000000;
        copyArr = new int[n];
        for(int i=0; i<n; i++)
            copyArr[i]=arr[i];


        total = 0;
        count = 100000/n;
        if(count==0)
            count=1;
        for(int i=0; i<count; i++)
        {
            for(int i=0; i<n; i++)
                arr[i]=copyArr[i];
            t1 = chrono::high_resolution_clock::now();
            mergeSort(arr, 0, n-1);
            t2 = chrono::high_resolution_clock::now();
            t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            total += t;
        }
        t = total/count;
        cout<<fixed<<"Avg case MergeSort, n = "<<n<<"\ttime = "<<t<<"\tnanosec"<<endl;
    }
    cout<<endl;
    for(int i=0; i<loop; i++)
    {
        n = size[i];
        arr = new int[n];
        for(int i=0; i<n; i++)
            arr[i] = rand()%1000000;
        sort(arr, arr+n);
        copyArr = new int[n];
        for(int i=0; i<n; i++)
            copyArr[i]=arr[i];


        total = 0;
        count = 100000/n;
        if(count==0)
            count=1;
        for(int i=0; i<count; i++)
        {
            for(int i=0; i<n; i++)
                arr[i]=copyArr[i];
            t1 = chrono::high_resolution_clock::now();
            mergeSort(arr, 0, n-1);
            t2 = chrono::high_resolution_clock::now();
            t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            total += t;
        }
        t = total/count;
        cout<<fixed<<"Best case MergeSort, n = "<<n<<"\ttime = "<<t<<"\tnanosec"<<endl;
    }
    cout<<endl;

    for(int i=0; i<loop; i++)
    {
        n = size[i];
        arr = new int[n];
        for(int i=0; i<n; i++)
            arr[i] = rand()%1000000;
        sort(arr, arr+n);
        reverseArr(arr,n);
        copyArr = new int[n];
        for(int i=0; i<n; i++)
            copyArr[i]=arr[i];


        total = 0;
        count = 100000/n;
        if(count==0)
            count=1;
        for(int i=0; i<count; i++)
        {
            for(int i=0; i<n; i++)
                arr[i]=copyArr[i];
            t1 = chrono::high_resolution_clock::now();
            mergeSort(arr, 0, n-1);
            t2 = chrono::high_resolution_clock::now();
            t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            total += t;
        }
        t = total/count;
        cout<<fixed<<"Worst case MergeSort, n = "<<n<<"\ttime = "<<t<<"\tnanosec"<<endl;
    }

    cout<<endl;

    //Quick
    for(int i=0; i<loop; i++)
    {
        n = size[i];
        arr = new int[n];
        for(int i=0; i<n; i++)
            arr[i] = rand()%1000000;
        copyArr = new int[n];
        for(int i=0; i<n; i++)
            copyArr[i]=arr[i];


        total = 0;
        count = 100000/n;
        if(count==0)
            count=1;
        for(int i=0; i<count; i++)
        {
            for(int i=0; i<n; i++)
                arr[i]=copyArr[i];
            t1 = chrono::high_resolution_clock::now();
            quickSort(arr, 0, n-1);
            t2 = chrono::high_resolution_clock::now();
            t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            total += t;
        }
        t = total/count;
        cout<<fixed<<"Avg case QuickSort, n = "<<n<<"\ttime = "<<t<<"\tnanosec"<<endl;
    }
    cout<<endl;

    for(int i=0; i<loop; i++)
    {
        n = size[i];
        arr = new int[n];
        for(int i=0; i<n; i++)
            arr[i] = rand()%1000000;
        sort(arr, arr+n);
        copyArr = new int[n];
        for(int i=0; i<n; i++)
            copyArr[i]=arr[i];


        total = 0;
        count = 100000/n;
        if(count==0)
            count=1;
        for(int i=0; i<count; i++)
        {
            for(int i=0; i<n; i++)
                arr[i]=copyArr[i];
            t1 = chrono::high_resolution_clock::now();
            quickSort(arr, 0, n-1);
            t2 = chrono::high_resolution_clock::now();
            t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            total += t;
        }
        t = total/count;
        cout<<fixed<<"Best case QuickSort, n = "<<n<<"\ttime = "<<t<<"\tnanosec"<<endl;
    }
    cout<<endl;


    for(int i=0; i<loop; i++)
    {
        n = size[i];
        arr = new int[n];
        for(int i=0; i<n; i++)
            arr[i] = rand()%1000000;
        sort(arr, arr+n);
        reverseArr(arr,n);
        copyArr = new int[n];
        for(int i=0; i<n; i++)
            copyArr[i]=arr[i];


        total = 0;
        count = 100000/n;
        if(count==0)
            count=1;
        for(int i=0; i<count; i++)
        {
            for(int i=0; i<n; i++)
                arr[i]=copyArr[i];
            t1 = chrono::high_resolution_clock::now();
            quickSort(arr, 0, n-1);
            t2 = chrono::high_resolution_clock::now();
            t = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count();
            total += t;
        }
        t = total/count;
        cout<<fixed<<"Worst case QuickSort, n = "<<n<<"\ttime = "<<t<<"\tnanosec"<<endl;
    }

    return 0;

}
