#include<iostream>
#define NOE 4
using namespace std;

int result_number = 0;
int number_of_elements = 4;

class Result{
	int values[NOE];
	int number_of_values;
	bool not_null;
	
	public:
		void print_result(){
			for (int i = 0; i < number_of_values; i++){
				cout << values[i];
				
				if (i < (number_of_values - 1)){
					cout << "\t";
				}
			}
			cout << "\n";
		}
		
		Result (){
			not_null = false;
			number_of_values = 0;
		}
		
		Result (int* list, int len_list){
			not_null = true;
			number_of_values = len_list;
			
			for (int i = 0; i < len_list; i++){
				values[i] = list[i];
			}
		}
};

bool not_equal_list (int* list, int len_list){
	bool out = true;
	
	for (int i = 0; i < len_list; i++){
		for (int j = i; j < len_list; j++){
			if (i != j){
				if (list[i] == list[j]){
					out = false;
				}
			}
		}
	}
	
	return (out);
}

int factorial(int number){
	int out = 1;
	
	for (int i = number; i > 0; i--){
		out *= i;
	}
	
	return (out);
}

void sum_of_four (int* list, int len_list, int target, Result* out){
	int result_cursor = 0;
	
	for (int a = 0; a < len_list; a++){
		for (int b = 0; b < len_list; b++){
			if (b > a){
				for (int c = 0; c < len_list; c++){
					if (c > b){
						for (int d = 0; d < len_list; d++){
							if (d > c){
								int place_equal_list[] = {a, b, c, d};
								int place_equal_list_len = sizeof(place_equal_list)/sizeof(place_equal_list[0]);
								
								if (not_equal_list(place_equal_list, place_equal_list_len)){
									int aa = list[a];
									int bb = list[b];
									int cc = list[c];
									int dd = list[d];
									
									int value_equal_list[] = {aa, bb, cc, dd};
									int value_equal_list_len = sizeof(value_equal_list)/sizeof(value_equal_list[0]);
									
									//if (not_equal_list(value_equal_list, value_equal_list_len)){
									if (true){
										if ((aa + bb + cc + dd) == target){
											int z[] = {list[a], list[b], list[c], list[d]};
											int z_len = sizeof(z)/sizeof(z[0]);
											
											out[result_cursor] = Result(z, NOE);
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
	
	int sample_space = (factorial(len_nums) / (factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
	
	Result h[sample_space];
	
	sum_of_four(nums, len_nums, target, h);
	
	printf("This is the handy work of C++\n\n");
	
	for (int i = 0; i < result_number; i++){
		h[i].print_result();
	}
	
	printf("\n\n");
	
	return (0);
}
