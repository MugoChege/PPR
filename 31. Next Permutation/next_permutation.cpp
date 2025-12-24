#include<iostream>
#include<algorithm>

using namespace std;

int exponented (int base, int exponent){
	int out = 1;
	
	for (int i = 0; i < exponent; i++){
		out *= base;
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

void number_to_list (int number, int* out, int len_list){
	int base = 10;
	int running_number = number;
	int out_cursor = len_list - 1;
	
	while ((running_number > 0) && (out_cursor >= 0)){
		int modulo = running_number % base;
		running_number -= modulo;
		running_number /= base;
		out[out_cursor] = modulo;
		out_cursor--;
	}
}

bool list_comparison (int* list1, int len_list1, int* list2, int len_list2){
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

void reverse_list (int* list, int len_list){
	int half_len_list = len_list / 2;
	
	for (int i = 0; i < half_len_list; i++){
		int x = list[i];
		
		list[i] = list[len_list - 1 - i];
		list[len_list - 1 - i] = x;
	}
}

int main () {
	int nums[] = {1,2,3,4,3};
	int len_nums = sizeof(nums)/sizeof(nums[0]);
	
	int nums_number = number_from_list(nums, len_nums);
	sort(nums, nums + len_nums);
	reverse_list(nums, len_nums);
	int highest_value_nums_number = number_from_list(nums, len_nums);
	
	cout << "The value of the number from the elements is:\t" << nums_number << endl;
	cout << "The highest number from the elements is:\t" << highest_value_nums_number << endl;
	
	int next_permutation[len_nums];
	int running_number = nums_number;
	
	while (running_number <= highest_value_nums_number){
		int temp_list[len_nums];
		
		for (int i = 0; i < len_nums; i++){
			temp_list[i] = 0;
		}
		
		number_to_list(running_number, temp_list, len_nums);
		//cout << temp_list[0] << temp_list[1] << temp_list[2] << temp_list[3] << "\t\t";
		//cout << list_comparison(temp_list, len_nums, nums, len_nums) << endl;
		if (list_comparison(temp_list, len_nums, nums, len_nums) && (running_number != nums_number)){
			for (int i = 0; i < len_nums; i++){
				next_permutation[i] = temp_list[i];
			}
			break;
		}
		running_number++;
	}
	
	for (int j = 0; j < len_nums; j++){
		cout << next_permutation[j];
		
		if (j != (len_nums - 1)){
			cout << "\t";
		}
	}
	cout << endl;
	
	return (0);
	
}
