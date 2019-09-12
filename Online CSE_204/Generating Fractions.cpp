#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int a, b, c, cnt=0;
    cout<<"input 'a' and 'b' to generate the pattern a/b :"<<endl;
    cin>>a>>b;
    cout<<"fractions are :  ";
    while((float)a/b > 0)
    {
        c= ceil((float)b/a);
        cout<<"1/"<<c<< " ";
        a = a*c - b;
        b = b*c;
        cnt++;
    }
    cout<<"\nnum of fraction = "<<cnt<<endl;
}
