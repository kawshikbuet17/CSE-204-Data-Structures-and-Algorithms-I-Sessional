#include <bits/stdc++.h>
using namespace std;

int* greedy_activity_selection(int a[], int s[], int f[], int n) {
  int* A = new int[n];
  A[0] = 0;
  A[1] = a[1];

  int k=1;
  int i;
  int it = 1;

  for(i=2; i<=n; i++) {
    if(s[i] >= f[k]) {
      it++;
      A[it] = a[i];
      k=i;
    }
  }

  A[0] = it;
  return A;
}

int main()
{

    srand (time(NULL));
    int N = 20;
    int *a = new int[N];
    int *s = new int[N];
    int *f = new int[N];
    a[0]=0;
    s[0]=0;
    f[0]=0;
    for(int i=1; i<N; i++)
    {
        a[i] = i;
        s[i] = rand()%100;
        f[i] = s[i] + rand()%50;
    }
    cout<<"a : ";
    for(int i=0; i<N; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"s : ";
    for(int i=0; i<N; i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    cout<<"f : ";
    for(int i=0; i<N; i++)
    {
        cout<<f[i]<<" ";
    }
    cout<<endl;
    int *ans = greedy_activity_selection(a, s, f, N-1);


    cout<<"Ans is: ";
    for(int i=1; i<=ans[0]; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
