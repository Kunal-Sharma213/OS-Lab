#include <bits/stdc++.h>
using namespace std;

int s, disk_size;

void CSCAN(int arr[], int head, string direction)
{
	int seek_count = 0;
	int distance, cur_track;
	vector<int> left, right;
	vector<int> seek_sequence;

	left.push_back(0);
	right.push_back(disk_size - 1);

	for (int i = 0; i < s; i++) {
		if (arr[i] < head)
			left.push_back(arr[i]);
		if (arr[i] > head)
			right.push_back(arr[i]);
	}
    std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());
        if(direction == "left"){
	for (int i = left.size() - 1; i >= 0; i--) {
				cur_track = left[i];

				seek_sequence.push_back(cur_track);

				distance = abs(cur_track - head);

				seek_count += distance;

				head = cur_track;
			}
	seek_count += head;
        for (int i = right.size() - 1; i >= 0; i--) {
				cur_track = right[i];

				seek_sequence.push_back(cur_track);

				distance = abs(cur_track - head);

				seek_count += distance;

				head = cur_track;
			}
        }
        else if(direction == "right"){

	for (int i = 0; i < right.size(); i++) {
		cur_track = right[i];
		seek_sequence.push_back(cur_track);
		distance = abs(cur_track - head);
		seek_count += distance;
		head = cur_track;
        }
        seek_count += abs(head - disk_size - 1);
        for (int i = 0; i < left.size(); i++) {
		cur_track = left[i];
		seek_sequence.push_back(cur_track);
		distance = abs(cur_track - head);
		seek_count += distance;
		head = cur_track;
        }
    }
	cout << "Total number of seek operations = "
		<< seek_count << endl;

	cout << "Seek Sequence is" << endl;

	for (int i = 0; i < seek_sequence.size(); i++) {
		cout << seek_sequence[i] << endl;
	}
}

// Driver code
int main()
{

	int head; 
    cin >> s >> head >> disk_size;
    int *arr = new int[s];
    for (int i = 0; i < s; i++) cin >> arr[i];
    string direction = "left";
	CSCAN(arr, head, direction);
    direction = "right";
	CSCAN(arr, head, direction);


	return 0;
}
