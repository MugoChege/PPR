#include <stdio.h>
#define NOE 3

int result_number = 0;
int number_of_elements = NOE;

struct Result;

typedef struct Result{
	int values [NOE];
	int is_null;
	int number_of_values;
	
	void (*set_result)(struct Result*, int*, int);
	void (*print)(struct Result*);
	
} Result;

void set_result (Result* self, int * list, int count){
	for (int i = 0; i < count; i++){
		self->values[i] = list[i];
	}
	self->number_of_values = count;
}

void print_result (Result* self){
	for (int i = 0; i < self->number_of_values; i++){
		printf("%d", self->values[i]);
		if (i < (self->number_of_values - 1)){
			printf("\t");
		}
	}
	printf("\n");
}

void function_placer (Result* self){
	self->set_result = set_result;
	self->print = print_result;
}

Result createResult (int * list, int count){
	Result r;
	r.is_null = 0;
	r.number_of_values = count;
	
	for (int i = 0; i < count; i++){
		r.values[i] = list[i];
	}
	
	function_placer (&r);
	
	return (r);
}

int factorial (int number){
	int out = 1;
	
	for (int i = number; i > 0; i--){
		out *= i;
	}
	
	return (out);
}

void sum_of_three (int* list, int len_list , int target, Result* out){
	int result_pointer = 0;
	
	for (int a = 0; a < len_list; a++){
		for (int b = a; b < len_list; b++){
			if (b > a){
				for (int c = b; c < len_list; c++){
					if (c > b){
						if ((a != b) && (a != c) && (b != c)){
							int aa = list[a];
							int bb = list[b];
							int cc = list[c];
							
							if ((aa != bb) && (aa != cc) && (bb != cc)){
								if ((aa + bb + cc) == target){
									int y[] = {aa, bb, cc};
									
									out[result_pointer] = createResult(y, number_of_elements);
									result_pointer++;
									result_number = result_pointer;
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
	int nums [] = {-1,0,1,2,-1,-4};
	
	int len_nums = sizeof(nums)/sizeof(nums[0]);
	
	int sample_space = (factorial(len_nums) / (factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
	
	Result h[sample_space];
	
	sum_of_three (nums, len_nums, 0, h);
	
	for (int i = 0; i < result_number; i++){
		h[i].print(&h[i]);
	}
	return (0);
}
