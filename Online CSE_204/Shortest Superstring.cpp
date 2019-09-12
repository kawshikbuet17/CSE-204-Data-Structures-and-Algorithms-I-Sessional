#include <bits/stdc++.h>
#include <string>
using namespace std;

#define MAX 1000

int str[MAX][MAX];

int maximum(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

string LCS(string X, string Y, int m, int n)
{
	if (m == 0 || n == 0)
		return string("");

	if (X[m - 1] == Y[n - 1])
		return LCS(X, Y, m - 1, n - 1) + X[m - 1];


	if (str[m - 1][n] > str[m][n - 1])
		return LCS(X, Y, m - 1, n);

	else
		return LCS(X, Y, m, n - 1);
}

void LCSLength(string X, string Y, int m, int n)
{
	for (int i = 1; i < m+1; i++)
	{
		for (int j = 1; j < n+1; j++)
		{
			if (X[i - 1] == Y[j - 1])
				str[i][j] = str[i - 1][j - 1] + 1;
			else
				str[i][j] = maximum(str[i - 1][j], str[i][j - 1]);
		}
	}
}

int main()
{
	string X, Y;
    cout<<"Enter two string (Using ENTER) : "<<endl;
	getline(cin, X);
	getline(cin, Y);
	cout<<"\nLCS is : "<<endl;

	int m = X.length(), n = Y.length();
	LCSLength(X, Y, m, n);

	cout << LCS(X, Y, m, n)<<endl;

	string lcs = LCS(X, Y, m, n);
	int len = lcs.length();

	cout<<"\nShortest Superstring is : "<<endl;

	int j, k;
    j=0;
    k=0;
	for(int i=0; i<len; )
    {
        while(j<m && k<n)
        {
            if(X[j]==Y[k] && X[j]==lcs[i])
            {
                cout<<lcs[i];
                i++; j++; k++;
            }
            else if(X[j] != Y[k] && X[j]==lcs[i])
            {
                cout<<Y[k];
                k++;
            }
            else if(X[j] != Y[k] && Y[k]==lcs[i])
            {
                cout<<X[j];
                j++;
            }
            else
            {
                cout<<X[j]<<Y[k];
                j++; k++;
            }
        }
    }

    while(j<m)
    {
        cout<<X[j];
        j++;
    }
    while(k<n)
    {
        cout<<Y[k];
        k++;
    }

	return 0;
}
