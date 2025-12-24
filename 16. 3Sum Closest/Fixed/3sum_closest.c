#include <stdio.h>
#define NOE 3

int result_number = 0;
int number_of_elements = NOE;

struct Result;

typedef struct Result{
	int values[NOE];
	int number_of_values;
	int not_null;
	
	void (*set_values) (struct Result*, int*, int);
	void (*print_values)(struct Result*);
	void (*empty_result)(struct Result*);
} Result;

void fun_set_values (Result* self, int* list, int len_list){
	self->not_null = 1;
	self->number_of_values = len_list;
	
	for (int i = 0; i < len_list; i++){
		self->values[i] = list[i];
	}
}

void fun_print_values(Result* self){
	printf("This is the handy work of C\n");
	
	int out = 0;
	
	for (int i = 0; i < self->number_of_values; i++){
		printf("%d", self->values[i]);
		out += self->values[i];
		
		if (i < (self->number_of_values - 1)){
			printf("\t");
		}
	}
	printf("\nThe sum of the values is %d\n\n", out);
}

void fun_empty_values(Result* self){
	self->not_null = 0;
	
	for (int i = 0; i < self->number_of_values; i++){
		self->values[i] = 0;
	}
	
	self->number_of_values = 0;
}

void function_placer (Result* self){
	self->set_values = fun_set_values;
	self->print_values = fun_print_values;
	self->empty_result = fun_empty_values;
}

Result create_Result (int* list, int len_list){
	Result r;
	function_placer(&r);
	
	r.set_values(&r, list, len_list);
	
	return (r);
}

///XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

int factorial (int number){
	int out = 1;
	
	for (int i = number; i > 0; i--){
		out *= 1;
	}
	
	return (out);
}

int absolute (int number){
	return (number < 0) ? (number * -1) : (number * 1);
}

void sum_of_three_closest (int* list, int len_list, int target, Result* out){
//This allows for an array of the combinations that have a sum closest in value
//Result sum_of three_closest (int* list, int len_list, int target){
//This gives the first found combination that has the sum that is closest in value.
	int result_cursor = 0;
	int closest_difference = 0;
	int first_execution = 1;
	//Result out;
	
	for (int a = 0; a < len_list; a++){
		for (int b = 0; b < len_list; b++){
			if (b > a){
				for (int c = 0; c < len_list; c++){
					if (c > b){
						if ((a != b) && (a != c) && (b != c)){
							int aa = list[a];
							int bb = list[b];
							int cc = list[c];
							
							//if ((aa != bb) && (aa != cc) && (bb != cc)){
							if (1){
								int difference = absolute(target - (aa + bb + cc));
								
								int update_array = 0;
								
								if (first_execution){
									closest_difference = difference;
									first_execution = 0;
									
									update_array = 1;
								} else {
									if (difference < closest_difference){
										
										closest_difference = difference;
										/*
										//This is the one that returns the first combination
										out = create_Result(y, number_of_elements
										*/
										
									//BEGIN if commenting out for the first occurrence outcome
										if (result_cursor > 0){
											for (int i = 0; i < result_cursor; i++){
												out[result_cursor].empty_result(&out[result_cursor]);
											}
											result_cursor = 0;
										}
										
										update_array = 1;
										
									} else if (difference == closest_difference){
										update_array = 1;
									//END if commenting out for the first occurrence outcome
									}
								}
								
								if (update_array){
									int y[] = {aa, bb, cc};
									out[result_cursor] = create_Result(y, number_of_elements);
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
	
	//return (out); //This is for the first occurence
}

int main () {
	int nums[] = {-1,2,1,-4};
	int len_nums = sizeof(nums)/sizeof(nums[0]);
	
	int sample_space = (factorial(len_nums) / (factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
	
	Result h[sample_space];
	
	sum_of_three_closest(nums, len_nums, 1, h);
	
	for (int i = 0; i < result_number; i++){
		h[i].print_values(&h[i]);
	}
	
	return (0);
}
