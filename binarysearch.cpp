// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;


int binarySearch(int a[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return binarySearch(a, l, mid - 1, x);
		return binarySearch(a, mid + 1, r, x);
    }
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
	int result = binarySearch(a, 0, n - 1, x);
	if(result == -1)
		cout << "-1";
    else    
		cout <<result+1;
	return 0;
}
