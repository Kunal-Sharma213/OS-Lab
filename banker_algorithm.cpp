#include <bits/stdc++.h>
using namespace std;
const int N =1000;
int alloc[N][N],need[N][N],new_alloc[N][N], new_need[N][N];

bool safe_state(int n, int m, int alloc[N][N], int need[N][N], int avail[])
{
    int finish[n], temp[n], work[m], x = 1, c = 0;

    for (int i = 0; i < m; i++)
    {
        work[i] = avail[i];
    }

    for (int i = 0; i < n; i++)
        finish[i] = false;

    cout << "\nSafe System : ";
    do
    {
        x = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            if (finish[i] == false)
            {
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] <= work[j])
                    {
                        count++;
                    }
                }
                if (count == m)
                {
                    cout << i << " -> ";
                    for (int k = 0; k < m; k++)
                    {
                        work[k] += alloc[i][k];
                    }
                    finish[i] = true;
                    c++;
                    x = 1;
                }
            }
            if (c == n)
                break;
        }
        if (c == n)
            break;

    } while (x != 0);

    if (c == n)
    {
        cout << "\n\nSystem is in safe state!\n";
        return true;
    }

    else
    {
        cout << "\n\nSystem is not in safe state!\n";
        return false;
    }
}

int main()
{
    int n, m;
    cout << "Enter number of processes : ";
    cin >> n;
    cout << "Enter number of resources : ";
    cin >> m;

    int avail[m], max[n][m];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number of allocated resources to process " << i + 1 << " : ";
        for (int j = 0; j < m; j++)
        {
            cin >> alloc[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number of maximum resources requested by process " << i + 1 << " : ";
        for (int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
        cout << endl;
    }
    cout << endl;

    cout << "Need -:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    char ch = 'y';
    do
    {
        cout << "Enter the availiability of each resource : ";
        for (int i = 0; i < m; i++)
        {
            cin >> avail[i];
        }

        safe_state(n, m, alloc, need, avail);
   
        cout << "\nDo you want to change the availbility? (y/n): ";
        cin >> ch;

    } while (ch == 'y');

    char choice = 'n';
    int pid, request[m], new_avail[m];
    do
    {
        int count = 0;
        cout << endl;

        if (choice == 'y')
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    new_alloc[i][j] = alloc[i][j];
                    new_need[i][j] = need[i][j];
                }
            }

            cout << "Enter the id of the process you want to make a request for : ";
            cin >> pid;

            cout << "Enter the request : ";
            for (int i = 0; i < m; i++)
            {
                cin >> request[i];
            }

            for (int i = 0; i < m; i++)
            {
                if (request[i] <= need[pid][i] && request[i] <= avail[i])
                {
                    count++;
                }
            }

            if (count == m)
            {
                for (int i = 0; i < m; i++)
                {
                    new_avail[i] = avail[i] - request[i];
                    new_alloc[pid][i] += request[i];
                    new_need[pid][i] -= request[i];
                }

                if (safe_state(n, m, new_alloc, new_need, new_avail))
                {
                    cout << "Request granted!\n";
                }
                else
                {
                    cout << "Request not granted!\n";
                }
            }
            else
            {
                cout << "Request not granted!\n";
            }
        }

        cout << "\nDo you want to make a request?(y/n) : ";
        cin >> choice;
    } while (choice == 'y');
}