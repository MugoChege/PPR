#include <stdio.h>

void get_target (int* nums, int target, int* out ){
	int len_nums = sizeof(nums);
	//len_nums++;
	
	for (int i = 0; i <= len_nums; i++){
		int exit_loop = 0;
		for (int j = 0; j < len_nums; j++){
			if (i == j){
				continue;
			} else {
				if ((nums[i] + nums[j]) == target){
					out[0] = nums[i];
					out[1] = nums[j];
					exit_loop = 1;
				}
			}
		}
		if (exit_loop){
			break;
		}
	}
}

void main (){
	int number_list[] = {1,2,3,4,5,6,7,8,9};
	int target = 16;
	int indices[2];
	
	get_target(number_list, target, indices);
	
	printf("[%d,%d]\n\n", indices[0], indices[1]); 
}
