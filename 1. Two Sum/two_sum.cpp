#include <iostream>

using namespace std;

void get_target (int* nums, int target, int* out){
	int len_nums = sizeof(nums);
	len_nums++;
	cout << "The size of the nums is:\t" << sizeof(nums) << "\n";
	
	for (int i = 0; i < len_nums; i++){
		//printf("%d is %d is %d\n", i, nums[i], target);
		bool exit_loop = false;
		
		for (int j = 0; j < len_nums; j++){
			if (i == j){
				continue;
			} else {
				if ((nums[i] + nums[j]) == target){
					out[0] = nums[i];
					out[1] = nums[j];
					exit_loop = true;
				}
			}
		}
		if (exit_loop){
			break;
		}
	}
}

int main () {
	int number_list[] = {1,2,3,4,5,6,7,8,9};
	int target = 16;
	int indices[2];
	
	get_target(number_list, target, indices);
	
	//printf ("[%d,%d]\n\n", indices[0], indices[1]);
	cout << "[" << indices[0] << "," << indices[1] << "]\n";
	
	return 0;
}
