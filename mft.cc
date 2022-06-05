#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, p,pos,max=INT_MIN;

    cout << "Enter the memory size: ";
    cin >> m;
    
    cout << "Enter the number of processes : ";
    cin >> n;

    int a[n],ifrag=0,f1=0,f2=0,s1;
    
    cout<<"Enter the size of each process : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        max = a[i] > max? a[i] : max;
    }

    p =m/max;
    int s=max;
    cout<<"No of partitions : "<<p<<endl;
    cout<<"Size of each partition : "<<s<<endl;
    
    for (int i = 0; i < n; i++)
    {
        if(m<s)
        {
            cout<<"\nNo memory left for process "<<i+1;
            a[i]=0;
            break;
        }
        else
        {
            if(a[i]<=s)
            {
                cout<<"Process got allocated in the partition "<<i+1<<endl;
                ifrag=s-a[i];
                cout<<"Internal fragmentation of process "<<i+1<<" is "<<ifrag<<endl;
                f1+=ifrag;
            }
            else
            {
                cout<<"Process did not get allocated in the partition "<<i+1;
            }
        }
    }
    
    cout<<"\nTotal internal fragmentation = "<<f1;
}