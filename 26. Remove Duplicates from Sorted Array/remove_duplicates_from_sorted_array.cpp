#include<iostream>
#include<algorithm>

using namespace std;

int duplicates_shifting_remove (int * list, int len_list){
	int counter = 0;
	
	sort (list, list + len_list);
	
	for (int i = (len_list - 1); i >= 0; i--){
		int element = list[i];
		bool unique = true;
		
		for (int j = 0; j < i; j++){
			if (element == list[j]){
				unique = false;
				break;
			}
		}
		
		if (unique == false){
			counter ++;
			int holder = list[i];
			
			for (int j = i; j < (len_list - 1); j++){
				list[j] = list[j + 1];
			}
			
			list[len_list - 1] = holder;
		}
	}
	
	return (counter);
}

int main () {
	int nums [] = {0,0,1,1,1,2,2,3,3,4};
	int len_nums = sizeof(nums)/ sizeof(nums[0]);
	
	int rem = duplicates_shifting_remove(nums, len_nums);
	
	cout << "This is the handy work of C++\n\n";
	cout << "The number of the duplicates in the array are:\t" << rem << "\n\n\n";

	printf("[");
	for (int i = 0; i < len_nums; i++){
		cout << nums[i];
		
		if (i == (len_nums - 1)){
			cout << "]" << endl;
		} else {
			cout << ", ";
		}
	}
	
	printf("\n\n\n[");
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
