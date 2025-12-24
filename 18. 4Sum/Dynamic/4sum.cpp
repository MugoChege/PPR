#include<iostream>
#include<vector>
#define NOE 4
using namespace std;

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

vector<Result> sum_of_four (vector<int> list, int target){
	vector<Result> out;
	int len_list = list.size();
	
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
											
											Result res = Result(z, NOE);
											out.push_back (res);	
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
	
	return (out);
}

int main (){
	vector<int> nums = {1,0,-1,0,-2,2};
	//int len_nums = sizeof(nums)/sizeof(nums[0]);
	int target = 0;
	
	vector<Result> res = sum_of_four(nums, target);
	
	
	cout << "This is the handy work of C++" << endl;
	
	for (int i = 0; i < res.size(); i++){
		res[i].print_result();
	}
	
	//cout << endl << endl;
	
	return 0;
}
