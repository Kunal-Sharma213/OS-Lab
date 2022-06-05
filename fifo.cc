#include<bits/stdc++.h>
using namespace std;
int h,f;
void fifo(int pages[], int n, int capacity)
{
	unordered_set<int> s;
	queue<int> indexes;
	for (int i=0; i<n; i++)
	{
		if (s.size() < capacity)
		{
			if (s.find(pages[i])==s.end())
			{
				s.insert(pages[i]);
				f++;
				indexes.push(pages[i]);
			}
            else h++;
		}
		else
		{
			if (s.find(pages[i]) == s.end())
			{
				int val = indexes.front();
				indexes.pop();
				s.erase(val);
				s.insert(pages[i]);
				indexes.push(pages[i]);
				f++;
			}
            else h++;
		}
	}
}
int main()
{
	int n, capacity;
    cin >> n >> capacity;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    fifo(arr,n,capacity);
    cout << "Page Faults -  " << f << '\n' << "Hit - " << h << '\n';
}
