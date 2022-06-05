#include <bits/stdc++.h>
using namespace std;

int s, disk_size;
void SCAN(int arr[], int head, string direction)
{
	int seek_count = 0;
	int distance, cur_track;
	vector<int> left, right;
	vector<int> seek_sequence;

	if (direction == "left")
		left.push_back(0);
	else if (direction == "right")
		right.push_back(disk_size - 1);

	for (int i = 0; i < s; i++) {
		if (arr[i] < head)
			left.push_back(arr[i]);
		if (arr[i] > head)
			right.push_back(arr[i]);
	}

	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());
	int run = 2;
	while (run--) {
		if (direction == "left") {
			for (int i = left.size() - 1; i >= 0; i--) {
				cur_track = left[i];

				seek_sequence.push_back(cur_track);

				distance = abs(cur_track - head);

				seek_count += distance;

				head = cur_track;
			}
    
		}
		else if (direction == "right") {
			for (int i = 0; i < right.size(); i++) {
				cur_track = right[i];
				seek_sequence.push_back(cur_track);

				distance = abs(cur_track - head);

				seek_count += distance;

				head = cur_track;
			}
			direction = "left";
		}
	}

	cout << "Total number of seek operations with direction -> " << direction << " = "
		<< seek_count << endl;

	cout << "Seek Sequence is" << endl;

	for (int i = 0; i < seek_sequence.size(); i++) {
		cout << seek_sequence[i] << endl;
	}
}
int main()
{

	int head; 
    cin >> s >> head >> disk_size;
    int *arr = new int[s];
    for (int i = 0; i < s; i++) cin >> arr[i];

	string direction = "left";
	SCAN(arr, head, direction);
    direction = "right";
	SCAN(arr, head, direction);
}