#include<iostream>

using namespace std;

int remove_by_shifting (int element, int* list, int len_list){
	int count = 0;
	
	for (int i = (len_list - 1); i >= 0; i--){
		if (list[i] == element){
			count ++;
			int holder = list[i];
			
			for (int j = i; j < (len_list - 1); j++){
				list[j] = list[j + 1];
			}
			
			list[len_list - 1] = holder;
		}
	}
	
	return (count);
}

int main(){
	int nums[] = {0,1,2,2,3,0,4,2};
	int len_nums = sizeof(nums)/ sizeof(nums[0]);
	int vals = 2;

	int rem = remove_by_shifting(vals, nums, len_nums);

	cout << "This is the handy work of C++\n\n";
	cout << rem << "\n\n\n";

	cout << "[";
	for (int i = 0; i < len_nums; i++){
		cout << nums[i];
		
		if (i == (len_nums - 1)){
			cout << "]\n";
		} else {
			cout << ", ";
		}
	}
	
	cout << endl << endl << "[";
	for (int i = 0; i < (len_nums - rem); i++){
		cout << nums[i];
		
		if (i == ((len_nums - rem) - 1)){
			cout << "]\n";
		} else {
			cout << ", ";
		}
	}
	return (0);
}
