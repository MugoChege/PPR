#include <iostream>
#define NOE 3

using namespace std;

int result_number = 0;
int number_of_elements = NOE;

class Result{
	int values [NOE];
	bool not_null;
	int number_of_values;
	
	public:
		Result(){
		}
		
		Result(int* list, int count){
			set_result (list, count);
			number_of_values = count;
			not_null = true;
		}
		
		void set_result(int* list, int count){
			for (int i = 0; i < count; i++){
				values[i] = list[i];
			}
		}
		
		void print_result (){
			cout << "This is the handy work of C++" << endl;
			for (int i = 0; i < number_of_elements; i++){
				cout << values[i];
				if (i < (number_of_values - 1)){
					cout << "\t";
				}
			}
			cout << endl;
		}
};

int factorial (int number){
	int out = 1;
	for (int i = number; i > 0; i--){
		out *= i;
	}
	
	return (out);
}

void sum_of_three (int* list, int len_list, int target, Result* out){
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
									
									out[result_pointer] = Result(y, NOE);
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
	int nums[] = {-1,0,1,2,-1,-4};
	
	int len_nums = sizeof(nums)/sizeof(nums[0]);
	
	int sample_space = (factorial(len_nums) / (factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
	
	Result h[sample_space];
	
	sum_of_three (nums, len_nums, 0, h);
	
	for (int i = 0; i < result_number; i++){
		h[i].print_result();
	}
	
	return (0);
}
