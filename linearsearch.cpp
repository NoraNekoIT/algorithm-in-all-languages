#include<iostream>
using namespace std;
int search(int a[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return -1;
}
int main()
{
    int n,j,x;
    cin>>n;
    int a[n];
    for (j = 0; j< n; j++)
        cin>>a[j];
    cin>>x;   
    int result = search(a,n, x);
    if(result == -1)
		cout << "-1";
    else    
		cout <<result+1;
    return 0;
}    