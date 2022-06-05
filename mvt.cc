#include<iostream>
using namespace std;
void Fixed(int process[],int m,int block[],int n)
{
    int allocation[m],internal_fragmentation[n];
    for(int i = 0; i < m; i++) 
    {
        allocation[i] = -1;
        internal_fragmentation[i] = 0;
   }
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            if(allocation[i] == -1 && block[j] >= process[i]) 
            {
                allocation[i] = j;
                internal_fragmentation[j] = block[j] - process [i];
                break;
            }
        }
   }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < m; i++) 
    {
        cout << " " << i+1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
            cout << endl;
    }
}
void FirstFit(int process[],int m,int block[],int n) 
{
    int allocation[m];
    for(int i = 0; i < m; i++) 
    {
        allocation[i] = -1;
    }
    
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (block[j] >= process[i]) 
            {
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < m; i++) 
    {
        cout << " " << i+1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
            cout << endl;
   }
}
void BestFit(int process[],int m,int block[],int n)
{
    int allocation[m];
    for(int i = 0; i < m; i++) 
    {
        allocation[i] = -1;
    }
    for (int i=0; i<n; i++) 
    {
        int bestIdx = -1;
        for (int j=0; j<m; j++) 
        {
            if (block[j] >= process[i]) 
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (block[bestIdx] > block[j])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) 
        {
            allocation[i] = bestIdx;
            block[bestIdx] -= process[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) 
    {
        cout << " " << i+1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
            cout << endl;
    }
}
void WorstFit(int process[],int m,int block[],int n)
{
    int allocation[m];
    for(int i = 0; i < m; i++) 
    {
        allocation[i] = -1;
    }
    for (int i=0; i<n; i++) 
    {
        int worstIdx = -1;
        for (int j=0; j<m; j++) 
        {
            if (block[j] >= process[i]) 
            {
                if (worstIdx == -1)
                    worstIdx = j;
                else if (block[worstIdx] < block[j])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) 
        {
            allocation[i] = worstIdx;
            block[worstIdx] -= process[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) 
    {
        cout << " " << i+1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
            cout << endl;
    }
}
int main()
{
    int m,n,x,choice;
    cout<<"Enter number of processes: ";
    cin>>m;
    int process[m];
    cout<<"Enter the process sizes: ";
    for(int i=0;i<m;i++)
    {
        cin>>process[i];
    }
    cout<<"Enter number of blocks: ";
    cin>>n;
    int block[n];
    cout<<"Enter the block sizes: ";
    for(int i=0;i<n;i++)
    {
        cin>>block[i];
    }
    cout<<"Which partitioning do you want to use?"<<endl;
    cout<<"1.Fixed partitioning \n2.Variable partitioning"<<endl;
    cin>>x;
    if(x==1)
    {
        Fixed(process,m,block,n);
    }
    else if(x==2)
    {
        cout<<"Choose the fit according to the choices below:-";
        cout<<"1.First Fit\n2.Best Fit\n3.Worst Fit";
        cin>>choice;
        switch(choice)
        {
            case 1:
                FirstFit(process,m,block,n);
                break;
            case 2:
                BestFit(process,m,block,n);
                break;
            case 3:
                WorstFit(process,m,block,n);
                break;
            default:
                cout<<"Enter a valid choice";
        }
    }
    else
    {
        cout<<"Enter a valid choice";
    }
    
    return 0;
}