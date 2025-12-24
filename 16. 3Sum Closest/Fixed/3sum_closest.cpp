#include <iostream>
#define NOE 3

using namespace std;

int result_number = 0;
const int number_of_elements = NOE;

class Result{
	int values[NOE];
	int number_of_values;
	bool not_null;
	
	public:
		void set_values(int* list, int len_list){
			not_null = true;
			number_of_values = len_list;
			
			for (int i = 0; i < len_list; i++){
				values[i] = list[i];
			}
		}
		
		Result (int* list, int len_list){
			not_null = true;
			set_values(list, len_list);
		}
		
		Result (){
			not_null = false;
			
			for (int i = 0; i < number_of_elements; i++){
				values[i] = 0;
			}
			number_of_values = 0;
		}
		
		void print_values(){
			cout << "This is the handy work of C++" << endl;
			int out = 0;
			
			for (int i = 0; i < number_of_elements; i++){
				cout << values[i];
				out += values[i];
				
				if (i < (number_of_values - 1)){
					cout << "\t";
				}
			}
				
			cout << endl << "The sum of the values is:\t" << out << endl;
		}
		
		void empty_result(){
			not_null = false;
			
			for (int i = 0; i < number_of_values; i++){
				values[i] = 0;
			}
			
			number_of_values = 0;
		}
};

int factorial (int number){
	int out = 1;
	
	for (int i = number; i > 0; i--){
		out *= number;
	}
	
	return (out);
}

int absolute (int number){
	return (number < 0) ? (number * -1) : (number * 1);
}

void sum_of_three_closest (int* list, int len_list, int target, Result* out){
	int result_cursor = 0;
	int closest_difference = 0;
	bool first_execution = true;
	
	for (int a = 0; a < len_list; a++){
		for (int b = 0; b < len_list; b++){
			if (b > a){
				for (int c = 0; c < len_list; c++){
					if (c > b){
						if ((a != b) && (a != c) && (b != c)){
							int aa = list[a];
							int bb = list[b];
							int cc = list[c];
							
							//if ((aa != bb) && (aa != cc) && (bb != cc))
							if (true){
								int difference = absolute(target - (aa + bb + cc));
								
								bool update_array = false;
								
								if (first_execution){
									closest_difference = difference;
									first_execution = false;
									
									update_array = true;
								} else {
									if (difference < closest_difference){
										closest_difference = difference;
										
										if (result_cursor > 0){
											for (int i = 0; i < result_cursor; i++){
												out[result_cursor].empty_result();
											}
											result_cursor = 0;
										}
										
										update_array = true;
									} else if (difference == closest_difference){
										update_array = true;
									}
								}
								
								if (update_array){
									int y[] = {aa, bb, cc};
									out[result_cursor] = Result(y, number_of_elements);
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

int main () {
	int nums[] = {-1,2,1,-4};
	int len_nums = sizeof(nums)/ sizeof(nums[0]);
	int target = 1;
	
	int sample_space = (factorial(len_nums) / (factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
	
	Result h[sample_space];
	
	sum_of_three_closest(nums, len_nums, target, h);
	
	for (int i = 0; i < result_number; i++){
		h[i].print_values();
	}
	
	return (0);
}
