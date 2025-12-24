#include<stdio.h>
#include<stdlib.h>

int exponented (int base, int exponent){
	int out = 1;
	
	for (int i = 0; i < exponent; i++){
		out *= base;
	}
	
	return (out);

}

int factorial (int number){
	int out = 1;
	
	for (int i = number; i > 0; i--){
		out *= i;
	}
	
	return (out);
}

int number_from_list (int* list, int len_list){
	int out = 0;
	int base = 10;
	
	for (int i = 0; i < len_list; i++){
		out += (list[i] * exponented(base, (len_list - 1 - i)));
	}
	
	return (out);
}

void number_to_list (int number, int* list, int len_list){
	for (int i = 0; i < len_list; i++){
		list[i] = 0;
	}
	
	int base = 10;
	int running_number = number;
	int list_cursor = len_list - 1;
	
	while ((running_number > 0) && (list_cursor >= 0)){
		int modulo = running_number % base;
		running_number -= modulo;
		running_number /= base;
		list[list_cursor] = modulo;
		list_cursor--;
	}
}

int list_comparison (int* list1, int len_list1, int* list2, int len_list2){
	if (len_list1 != len_list2){
		return (0);
	}
	
	int list1_bool_map[len_list1];
	int list2_bool_map[len_list2];
	
	for (int i = 0; i < len_list1; i++){
		list1_bool_map[i] = 0;
		list2_bool_map[i] = 0;
	}
	
	for (int i = 0; i < len_list1; i++){
		for (int j = 0; j < len_list1; j++){
			if ((list1_bool_map[i] == 0) && (list2_bool_map[j] == 0)){
				if (list1[i] == list2[j]){
					list1_bool_map[i] = 1;
					list2_bool_map[j] = 1;
					break;
				}
			}
		}
	}
	
	int bool_counter = 0;
	
	for (int i = 0; i < len_list1; i++){
		if (list1_bool_map[i] && list2_bool_map[i]){
			bool_counter += 1;
		}
	}
	
	return (len_list1 == bool_counter);
}

int appears (int element, int* list, int len_list){
	int out = -1;
	
	for (int i = 0; i < len_list; i++){
		if (element == list[i]){
			out += 1;
		}
	}
	
	return (out);
}

void reverse_list (int* list, int len_list){
	int half_len_list = len_list / 2;
	
	for (int i = 0; i < half_len_list; i++){
		int x = list[i];
		
		list[i] = list[len_list - 1 - i];
		list[len_list - 1 - i] = x;
	}
}
int comparison(const void* a, const void* b){
	int aa = *(int*) a;
	int bb = *(int*) b;
	
	return (aa - bb);
}

int main (){
	int nums[] = {1,2,3,4,3};
	int len_nums = sizeof(nums) / sizeof(nums[0]);
	
	qsort(nums, len_nums, sizeof(nums[0]), comparison);
	
	int lowest_value_nums_number = number_from_list(nums, len_nums);
	reverse_list(nums, len_nums);
	int highest_value_nums_number = number_from_list(nums, len_nums);
	
	printf("The lowest number from the elements is:\t%d\n", lowest_value_nums_number);
	printf("The highest number from the elements is:\t%d\n", highest_value_nums_number);
	
	int sample_size = factorial(len_nums);
	int unique = 0;
	
	for (int i = 0; i < len_nums; i++){
		int occ_code = 0;
		
		if (i == 0){
			occ_code = 1;
		} else {
			if (nums[i - 1] != nums[i]){
				occ_code = 1;
				
			}
		}
		
		if (occ_code){
			int occurences = appears(nums[i], nums, len_nums);
			if (occurences == 0){
				unique++;
			}
			
			if (occurences > 0){
				unique++;
				sample_size /= factorial(occurences + 1);
			}
		}
	}
	
	printf("The number of unique elements are:\t%d\n", unique);
	printf("The sample size of permutations expected is:\t%d\n", sample_size);
	
	//create an array for the permutations
	
	int permutations[sample_size][len_nums];
	int running_number = lowest_value_nums_number;
	int permutations_cursor = 0;
	
	while (running_number <= highest_value_nums_number){
		int temp_array[len_nums];
		
		for (int i = 0; i < len_nums; i++){
			temp_array[i] = 0;
		}
		
		number_to_list(running_number, temp_array, len_nums);
		
		if (list_comparison(temp_array, len_nums, nums, len_nums)){
			//printf("%d\n", running_number);
			for (int i = 0; i < len_nums; i++){
				permutations[permutations_cursor][i] = temp_array[i];
			}
			permutations_cursor++;
		}
		
		running_number ++;
	}
	
	for (int i = 0; i < permutations_cursor; i++){
		for (int j = 0; j < len_nums; j++){
			printf("%d", permutations[i][j]);
			/*
			if (j != (len_nums - 1)){
				printf("\t");
			}
			*/
		}
		printf("\n");
	}
	
	return (0);
}
