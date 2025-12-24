#include<stdio.h>
#include<stdlib.h>

int compare (const void* a, const void* b){
	return (*(int*) a - *(int*) b);
}

void first_and_last (int element, int* list, int len_list, int* out){
	int find_first = 1;
	
	qsort(list, len_list, sizeof(list[0]), compare);
	
	for (int i = 0; i < len_list; i++){
		if (list[i] == element){
			if (find_first){
				out[0] = i;
				out[1] = i;
				find_first = 0;
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
	
	printf("This is the handy work of C.\n\n[%d, %d]\n\n\n", first_last[0], first_last[1]);
	
	return (0);
}
