#include <iostream>
#include <algorithm>

using namespace std;

float get_median (int* list, int len_list){
	bool even_length = (len_list % 2 == 0);
	float median = 0;
	
	if (even_length){
		median = ((float)list[len_list / 2] + (float)list[(len_list / 2) - 1]) / 2;
	} else {
		median = ((float)list[len_list / 2]);
	}
	
	return (median);
}

void combine_list (int* list1, int len_list1, int* list2, int len_list2, int* list_combined){
	int list_combined_cursor = 0;
	
	for (int i = 0; i < len_list1; i++){
		list_combined[list_combined_cursor] = list1[i];
		list_combined_cursor++;
	}
	
	for (int i = 0; i < len_list2; i++){
		list_combined[list_combined_cursor] = list2[i];
		list_combined_cursor++;
	}
	
	sort(list_combined, list_combined + list_combined_cursor);
}

int main (){
	int list1[] = {1,3};
	int list2[] = {2,4};
	
	int len_list1 = sizeof(list1)/ sizeof(list1[0]);
	int len_list2 = sizeof(list2)/ sizeof(list2[0]);
	
	int list_combined [len_list1 + len_list2];
	combine_list(list1, len_list1, list2, len_list2, list_combined);
	
	float median = get_median(list_combined, (len_list1 + len_list2));
	
	cout << median << endl << endl << endl;
	
	return (0);
}
