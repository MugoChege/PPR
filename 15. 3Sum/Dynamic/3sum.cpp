#include <iostream>
#include <vector>
#define NOE 3

using namespace std;

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
			//cout << "This is the handy work of C++" << endl;
			for (int i = 0; i < number_of_elements; i++){
				cout << values[i];
				if (i < (number_of_values - 1)){
					cout << "\t";
				}
			}
			cout << endl;
		}
};

vector<Result> sum_of_three (vector<int> list, int target){
	vector<Result> out;
	int len_list = list.size();
	
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
									
									out.push_back(Result(y, NOE));
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
	vector<int> nums = {-1,0,1,2,-1,-4};
	int target = 0;
	
	vector<Result> res = sum_of_three(nums, target);
	
	cout << "This is the handy work of C++" << endl;
	
	for (int i = 0; i < res.size(); i++){
		res[i].print_result();
	}
	
	return (0);
	
}
