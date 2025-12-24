#include<iostream>
#include<algorithm>

using namespace std;

void first_and_last (int element, int* list, int len_list, int* out){
	bool find_first = true;
	sort (list, list + len_list);
	
	for (int i = 0; i < len_list; i++){
		if (list[i] == element){
			if (find_first){
				out[0] = i;
				out[1] = i;
				find_first = false;
			} else {
				out[1] = i;
			}
		}
	}
}

int main () {
	int nums[] = {5,7,7,8,8,10,2};
	int len_nums = sizeof(nums) / sizeof(nums[0]);
	int target = 8;
	int first_last [] = {-1,-1};
	
	first_and_last(target, nums, len_nums, first_last);
	
	cout << "This is the handy work of C++.\n\n[" << first_last[0] << ", " << first_last[1] << "]\n\n\n";
	
	return (0);
}
