#include<stdio.h>
#include<stdlib.h>

float get_median (int* list, int len_list){
	int even_length = (len_list % 2 == 0);
	float median;
	
	if (even_length){
		median = ((float) list[len_list / 2] + (float) list[(len_list / 2) - 1]) / 2; 
	} else {
		median = (list[len_list / 2]);
	}
	
	return (median);
}

int compare (const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

void combine_list (int* list1, int len_list1, int* list2, int len_list2, int* nje){
	qsort (list1, len_list1, sizeof(list1[0]), compare);
	qsort (list2, len_list2, sizeof(list2[0]), compare);
	
	int list1_cursor = 0;
	int list2_cursor = 0;
	
	int nje_cursor = 0;
	
	while ((list1_cursor < len_list1) || (list2_cursor < len_list2)){
		int element_list1;
		int element_list1_is_null = 1;
		int element_list2;
		int element_list2_is_null = 1;
		int appending_element; 
		
		if (list1_cursor < len_list1){
			element_list1 = list1[list1_cursor];
			element_list1_is_null = 0;
		}
		
		if (list2_cursor < len_list2){
			element_list2 = list2[list2_cursor];
			element_list2_is_null = 0;
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
		
		nje[nje_cursor] = appending_element;
		nje_cursor++;
	}
}

int main () {
	int list1[] = {1,3,5};
	int list2[] = {2,4};
	int len_list1 = sizeof(list1) / sizeof(list1[0]);
	int len_list2 = sizeof(list2) / sizeof(list2[0]);
	
	int list_combined[len_list1 + len_list2];
	
	combine_list (list1, len_list1, list2, len_list2, list_combined);
	
	float median = get_median (list_combined, (len_list1 + len_list2));
	
	printf("This is the handy work of C.\n\n\nThe median of the two arrays is:\t%f\n\n\n", median);
	
	return (0);
}
