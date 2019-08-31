#include<bits/stdc++.h>
using namespace std;

#define MAXSIZE 500000

class Disjoint_Set
{
    int *parent = new int[MAXSIZE];
    int *rank = new int[MAXSIZE];
    int yes = 0;
public:
    void make_set(int x)
    {
        parent[x] = x;
        rank[x] = 0;
        yes = 1;
    }

    int find_set(int x)
    {
        if (x != parent[x])
            parent[x] = find_set(parent[x]);
        return parent[x];
    }

    void link(int x, int y)
    {
        if (rank[x] > rank[y])
            parent[y] = x;
        else
        {
            parent[x] = y;
            if(rank[x]==rank[y])
                rank[y]++;
        }
    }

    void union_set(int x, int y)
    {
        link(find_set(x), find_set(y));
    }

    void print(int x)
    {
        if(yes==1)
        {
            int temp = find_set(x);
            for(int i=0; i<MAXSIZE; i++)
            {
                if(find_set(i)==temp)
                    cout<<i<<" ";
            }
        }
        else
        {
            cout<<"You didn't input anything..."<<endl;
        }

    }
};

int main()
{
    Disjoint_Set ds;
    int x,y;
    cout<<"----DISJOINT SET DATA STRUCTURE----"<<endl;
    cout<<endl;
    while(1)
    {
        cout<<"1.   Make Set"<<endl;
        cout<<"2.   Find Set"<<endl;
        cout<<"3.   Union Set"<<endl;
        cout<<"4.   Print"<<endl;
        cout<<"5.   Quit"<<endl;
        cout<<">>> "<<endl;
        int ch;
        cin>>ch;
        if(ch==1)
        {
            cout<<"Input value : ";
            cin>>x;
            ds.make_set(x);
            cout<<endl;
        }
        else if(ch==2)
        {
            cout<<"You want to find : ";
            cin>>x;
            cout<<ds.find_set(x);
            cout<<endl;
        }
        else if(ch==3)
        {
            cout<<"Make union between : ";
            cin>>x>>y;
            ds.union_set(x, y);
            cout<<endl;
        }
        else if(ch==4)
        {
            cout<<"Select a set element : ";
            cin>>x;
            ds.print(x);
            cout<<endl;

        }
        else if(ch==5)
        {
            cout<<"Program Ended"<<endl;
            break;
        }
    }
}



