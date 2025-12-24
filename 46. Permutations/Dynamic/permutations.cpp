#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int exponented (int base, int exponent){
	int out = 1;
	
	for (int i = 0; i < exponent; i++){
		out *= base;
	}
	
	return (out);
}

int number_from_list (vector<int> list){
	int len_list = list.size();
	int out = 0;
	int base = 10;
	
	for (int i = 0; i < len_list; i++){
		out += (list[i] * exponented(base, (len_list - 1 - i)));
	}
	
	return (out);
}

vector<int> number_to_list (int number, int len_list){
	//int len_list = list.size();
	int base = 10;
	int running_number = number;
	int out_cursor = len_list - 1;
	vector<int> out(len_list, 0); 
	
	while ((running_number > 0) && (out_cursor >= 0)){
		int modulo = running_number % base;
		running_number -= modulo;
		running_number /= base;
		out[out_cursor] = modulo;
		out_cursor--;
	}
	
	return (out);
}

bool list_comparison (vector<int> list1, vector<int> list2){
	int len_list1 = list1.size();
	int len_list2 = list2.size();
	
	if (len_list1 != len_list2){
		return (false);
	}
	
	bool list1_bool_map[len_list1];
	bool list2_bool_map[len_list2];
	
	for (int i = 0; i < len_list1; i++){
		list1_bool_map[i] = false;
		list2_bool_map[i] = false;
	}
	
	for (int i = 0; i < len_list1; i++){
		for (int j = 0; j < len_list2; j++){
			if ((list1_bool_map[i] == false) && (list2_bool_map[j] == false)){
				if (list1[i] == list2[j]){
					list1_bool_map[i] = true;
					list2_bool_map[j] = true;
					break;
				}
			}
		}
	}
	
	int bool_counter = 0;
	
	for (int i = 0; i < len_list1; i++){
		if (list1_bool_map[i] && list2_bool_map[i]){
			bool_counter++;
		}
	}
	
	return (len_list1 == bool_counter);
}

int appears (int element, vector<int> list){
	int len_list = list.size();
	int out = -1;
	
	for (int i = 0; i < len_list; i++){
		if (element == list[i]){
			out += 1;
		}
	}
	return (out);
}

void reverse_list (vector<int>* list_ptr){
	vector<int>& list = *list_ptr;
	int len_list = list.size();
	int half_len_list = len_list / 2;
	
	for (int i = 0; i < half_len_list; i++){
		int x = list[i];
		
		list[i] = list[len_list - 1 - i];
		list[len_list - 1 - i] = x;
	}
}

int main () {
	vector<int> nums = {1,2,3,4};
	int len_nums = nums.size();
	
	//sort(nums, nums + len_nums);
	sort(nums.begin(), nums.end());
	int lowest_value_nums_number = number_from_list(nums);
	reverse_list(&nums);
	int highest_value_nums_number = number_from_list(nums);
	
	cout << "This is the handy work of C++" << endl;
	cout << "The lowest number from the elements is:\t" << lowest_value_nums_number << endl;
	cout << "The highest number from the elements is:\t" << highest_value_nums_number << endl;
	
	int unique = 0;
	
	for (int i = 0; i < len_nums; i++){
		bool occ_code = false;
		
		if (i == 0){
			occ_code = true;
		} else {
			if (nums[i - 1] != nums[i]){
				occ_code = true;
			}
		}
		
		if (occ_code){
			int occurences = appears(nums[i], nums);
			if (occurences >= 0){
				unique++;
			}
		}
	}
	
	cout << "The number of unique elements are:\t" << unique << endl;
	
	//vector<array<int, len_nums>> permutations;
	vector<vector<int>> permutations;
	int running_number = lowest_value_nums_number;
	
	while (running_number <= highest_value_nums_number){
		vector<int> temp_list = number_to_list(running_number, len_nums);
		
		if (list_comparison(temp_list, nums)){
			permutations.push_back(temp_list);
		}
		
		running_number ++;
	}
	
	for (int i = 0; i < permutations.size(); i++){
		for (int j = 0; j < permutations[i].size(); j++){
			cout << permutations[i][j];
			
			if (j != (len_nums - 1)){
				cout << "\t";
			}
		}
		cout << endl;
	}
	
	return (0);
	
}
