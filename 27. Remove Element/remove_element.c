#include <stdio.h>

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

	printf("This is the handy work of C\n\n");
	printf("%d\n\n\n", rem);

	printf("[");
	for (int i = 0; i < len_nums; i++){
		printf("%d", nums[i]);
		
		if (i == (len_nums - 1)){
			printf("]\n");
		} else {
			printf(", ");
		}
	}
	
	printf("\n\n\n[");
	for (int i = 0; i < (len_nums - rem); i++){
		printf("%d", nums[i]);
		
		if (i == ((len_nums - rem) - 1)){
			printf("]\n");
		} else {
			printf(", ");
		}
	}

	return (0);
}
