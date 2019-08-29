#include<bits/stdc++.h>
using namespace std;

#define MAXSIZE 500000

class Disjoint_Set
{
    int *parent = new int[MAXSIZE];
    int *rank = new int[MAXSIZE];
public:
    void make_set(int x)
    {
        parent[x] = x;
        rank[x] = 0;
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
        int temp = parent[x];
        for(int i=0; i<MAXSIZE; i++)
        {
            if(parent[i]==temp)
                cout<<parent[i]<<" "<<endl;
        }
    }
};

int main()
{

}



