#include <stdio.h>
#define NOE 4

int result_number = 0;

struct Result;

typedef struct Result{
	int values[NOE];
	int no_of_values;
	int not_null;
	
	void (*print_result)(struct Result*);
} Result;

void fun_print_result(Result* self){
	int no_of_values = self->no_of_values;
	
	for (int i = 0; i < no_of_values; i++){
		printf("%d", self->values[i]);
		if (i < (no_of_values - 1)){
			printf("\t");
		}
	}
	printf("\n");
}

Result create_Result(int* list, int len_list){
	Result out;
	

	out.no_of_values = len_list;
	out.not_null = 1;
	
	for (int i = 0; i < len_list; i++){
		out.values[i] = list[i];
	}
	
	out.print_result = fun_print_result;
	
	return (out);
}

int not_equal_list (int* list, int len_list){
	int out = 1;
	
	for (int i = 0; i < len_list; i++){
		for (int j = i; j < len_list; j++){
			if (i != j){
				if (list[i] == list[j]){
					out = 0;
				}
			}
		}
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

void sum_of_four(int* list, int len_list, int target, Result* out){
	int result_cursor = 0;
	
	for (int a = 0; a < len_list; a++){
		for (int b = 0; b < len_list; b++){
			if (b > a){
				for (int c = 0; c < len_list; c++){
					if (c > b){
		  				for (int d = 0; d < len_list; d++){
							if (d > c){
								int place_equal_list [] = {a, b, c, d};
								int place_equal_list_len = sizeof(place_equal_list)/sizeof(place_equal_list[0]);
								
								if (not_equal_list(place_equal_list, place_equal_list_len)){
									int aa = list[a];
									int bb = list[b];
									int cc = list[c];
									int dd = list[d];
									
									int value_equal_list [] = {aa, bb, cc, dd};
									int value_equal_list_len = sizeof(value_equal_list)/sizeof(value_equal_list_len);
									//if (not_equal_list(value_equal_list, value_equal_list_len){
									if (1){
										if ((aa + bb + cc + dd) == target){
											int z[] = {list[a], list[b], list[c], list[d]};
											int z_len = sizeof(z)/sizeof(z[0]);
											
											out[result_cursor] = create_Result(z, NOE);
											result_cursor++;
											result_number = result_cursor;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

int main (){
	int nums[] = {1,0,-1,0,-2,2};
	int len_nums = sizeof(nums)/sizeof(nums[0]);
	int target = 0;
	
	int sample_space = (factorial(len_nums) / (factorial(len_nums - NOE) * factorial(NOE)));
	
	Result h[sample_space];
	
	sum_of_four(nums, len_nums, target, h);
	
	printf("The handy work of C is:\n\n");
	for (int i = 0; i < result_number; i++){
		h[i].print_result(&h[i]);
	}
	
	printf("\n\n");
}
