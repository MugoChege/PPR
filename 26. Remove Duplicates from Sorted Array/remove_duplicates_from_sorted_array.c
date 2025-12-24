#include<stdio.h>
#include<stdlib.h>

int compare (const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

int duplicates_shifting_remove (int * list, int len_list){
	int counter = 0;
	
	qsort (list, len_list, sizeof(list[0]), compare); 
	
	for (int i = (len_list - 1); i >= 0; i--){
		int element = list[i];
		int unique = 1;
		
		for (int j = 0; j < i; j++){
			if (element == list[j]){
				unique = 0;
				break;
			}
		}
		
		if (unique == 0){
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
	
	printf("This is the handy work of C\n\n");
	printf("The number of the duplicates in the array are:\t%d\n\n\n", rem);

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
