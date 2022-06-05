#include <bits/stdc++.h>
using namespace std;
void FCFS(int arr[], int head, int s)
{
	int seek_count = 0;
	int distance, cur_track;

	for (int i = 0; i < s; i++) {
		cur_track = arr[i];

		distance = abs(cur_track - head);


		seek_count += distance;


		head = cur_track;
	}

	cout << "Total number of seek operations = "
		<< seek_count << endl;
	cout << "Seek Sequence is" << endl;

	for (int i = 0; i < s; i++) {
		cout << arr[i] << endl;
	}
}

int main()
{
    int s, head; 
    cin >> s >> head;
    int *arr = new int[s];
    for (int i = 0; i < s; i++) cin >> arr[i];

	FCFS(arr, head, s);

	return 0;
}
