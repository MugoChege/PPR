#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//float get_median (int* list, int len_list){
float get_median (vector<int> list){
	int len_list = list.size();
	bool even_length = (len_list % 2 == 0);
	float median = 0;
	
	if (even_length){
		median = ((float)list[len_list / 2] + (float)list[(len_list / 2) - 1]) / 2;
	} else {
		median = ((float)list[len_list / 2]);
	}
	
	return (median);
}

//void combine_list (int* list1, int len_list1, int* list2, int len_list2, int* list_combined){
vector<int> combine_list (int* list1, int len_list1, int* list2, int len_list2){
	sort (list1, list1 + len_list1);
	sort (list2, list2 + len_list2);
	
	vector<int> nje = {};
	
	int list1_cursor = 0;
	int list2_cursor = 0;
	
	int nje_cursor = 0;
	
	while ((list1_cursor < len_list1) || (list2_cursor < len_list2)){
		int element_list1;
		bool element_list1_is_null = true;
		int element_list2;
		bool element_list2_is_null = true;
		int appending_element; 
		
		if (list1_cursor < len_list1){
			element_list1 = list1[list1_cursor];
			element_list1_is_null = false;
		}
		
		if (list2_cursor < len_list2){
			element_list2 = list2[list2_cursor];
			element_list2_is_null = false;
		}
		
		if (!element_list1_is_null && !element_list2_is_null){
			if (element_list1 < element_list2){
				appending_element = element_list1;
				list1_cursor++;
			} else {
				appending_element = element_list2;
				list2_cursor++;
			}
		} else if (element_list1_is_null){
			appending_element = element_list2;
			list2_cursor++;
		} else if (element_list2_is_null){
			appending_element = element_list1;
			list1_cursor++;
		}
		
		nje.push_back(appending_element);
	}
	
	return (nje);
}

int main (){
	int list1[] = {1,3};
	int list2[] = {2,4};
	
	int len_list1 = sizeof(list1)/ sizeof(list1[0]);
	int len_list2 = sizeof(list2)/ sizeof(list2[0]);
	
	vector<int> list_combined = combine_list(list1, len_list1, list2, len_list2);
	
	float median = get_median(list_combined);
	
	cout << "This is the handy work of C++\n\n\n";
	
	cout << median << endl << endl << endl;
	
	return (0);
}
