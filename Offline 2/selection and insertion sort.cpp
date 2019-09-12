#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i, j, temp, min, location;
    for(i=0;i<n-1;i++)
    {
        min=arr[i];
        location=i;
        for(j=i+1;j<n;j++)
        {
            if(min>arr[j])
            {
                min=arr[j];
                location=j;
            }
        }

        temp=arr[i];
        arr[i]=arr[location];
        arr[location]=temp;
    }
}

void insertionSort(int arr[], int n)
{
    int marker, j;

    for(int i=1; i<n; i++)
    {
        marker = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>marker)
        {
            int temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void reverseArr(int arr[], int n)
{
    for(int i=0; i<n/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

int main()
{
    srand (time(NULL));
    int n;
    cout<<"Input the range of Array : "<<endl;
    cin>>n;
    int *arr = new int[n];
    int *copyArr = new int[n];

    double total_selection_time = 0;
    double total_insertion_time = 0;
    double total_selection_time_best = 0;
    double total_selection_time_worst = 0;
    double total_insertion_time_best = 0;
    double total_insertion_time_worst = 0;


    for(int i=0; i<10; i++)
    {
        for(int i=0; i<n; i++)
        {
                arr[i] = rand()%10000;
                copyArr[i] = arr[i];
        }


        //Avg//
        auto selectionTime1 = chrono::high_resolution_clock::now();
        selectionSort(copyArr, n);
        auto selectionTime2 = chrono::high_resolution_clock::now();
        double selectionTime = chrono::duration_cast<chrono::nanoseconds>(selectionTime2 - selectionTime1).count();
        total_selection_time += selectionTime;

        for(int i=0; i<n; i++)
        {
            copyArr[i] = arr[i];
        }
        auto insertionTime1 = chrono::high_resolution_clock::now();
        insertionSort(copyArr, n);
        auto insertionTime2 = chrono::high_resolution_clock::now();
        double insertionTime = chrono::duration_cast<chrono::nanoseconds>(insertionTime2 - insertionTime1).count();
        total_insertion_time += insertionTime;




        // Best//
        for(int i=0; i<n; i++)
        {
                arr[i] = rand()%10000;
                copyArr[i] = arr[i];
        }
        selectionSort(copyArr,n);
        auto selectionTime1_best = chrono::high_resolution_clock::now();
        selectionSort(copyArr, n);
        auto selectionTime2_best = chrono::high_resolution_clock::now();
        double selectionTime_best = chrono::duration_cast<chrono::nanoseconds>(selectionTime2_best - selectionTime1_best).count();
        total_selection_time_best += selectionTime_best;

        for(int i=0; i<n; i++)
        {
            copyArr[i] = arr[i];
        }
        insertionSort(copyArr, n);
        auto insertionTime1_best = chrono::high_resolution_clock::now();
        insertionSort(copyArr, n);
        auto insertionTime2_best = chrono::high_resolution_clock::now();
        double insertionTime_best = chrono::duration_cast<chrono::nanoseconds>(insertionTime2_best - insertionTime1_best).count();
        total_insertion_time_best += insertionTime_best;


        // Worst //
        for(int i=0; i<n; i++)
        {
                arr[i] = rand()%10000;
                copyArr[i] = arr[i];
        }
        selectionSort(copyArr,n);
        reverseArr(copyArr, n);
        auto selectionTime1_worst = chrono::high_resolution_clock::now();
        selectionSort(copyArr, n);
        auto selectionTime2_worst = chrono::high_resolution_clock::now();
        double selectionTime_worst = chrono::duration_cast<chrono::nanoseconds>(selectionTime2_worst - selectionTime1_worst).count();
        total_selection_time_worst += selectionTime_worst;

        for(int i=0; i<n; i++)
        {
            copyArr[i] = arr[i];
        }
        insertionSort(copyArr, n);
        reverseArr(copyArr, n);
        auto insertionTime1_worst = chrono::high_resolution_clock::now();
        insertionSort(copyArr, n);
        auto insertionTime2_worst = chrono::high_resolution_clock::now();
        double insertionTime_worst = chrono::duration_cast<chrono::nanoseconds>(insertionTime2_worst - insertionTime1_worst).count();
        total_insertion_time_worst += insertionTime_worst;



    }

    double selectionResult = total_selection_time/10;
    double insertionResult = total_insertion_time/10;

    double selectionResult_best = total_selection_time_best/10;
    double insertionResult_best = total_insertion_time_best/10;

    double selectionResult_worst = total_selection_time_worst/10;
    double insertionResult_worst = total_insertion_time_worst/10;

    cout<<fixed<<"selection result avg : "<<selectionResult<<" nanosec"<<endl;
    cout<<fixed<<"insertion result avg : "<<insertionResult<<" nanosec"<<endl;
    cout<<fixed<<"selection result best : "<<selectionResult_best<<" nanosec"<<endl;
    cout<<fixed<<"insertion result best : "<<insertionResult_best<<" nanosec"<<endl;
    cout<<fixed<<"selection result worst : "<<selectionResult_worst<<" nanosec"<<endl;
    cout<<fixed<<"insertion result worst : "<<insertionResult_worst<<" nanosec"<<endl;

    return 0;
}
