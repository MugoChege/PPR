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

void combine_list (int* list1, int len_list1, int* list2, int len_list2, int* combined_list){
	int combined_list_cursor = 0;
	
	for (int i = 0; i < len_list1; i++){
		combined_list[combined_list_cursor] = list1[i];
		combined_list_cursor++;
	}
	
	for (int i = 0; i < len_list2; i++){
		combined_list[combined_list_cursor] = list2[i];
		combined_list_cursor++;
	}
	
	qsort (combined_list, combined_list_cursor, sizeof(combined_list[0]), compare);
	/*
	for (int i = 0; i < combined_list_cursor; i++){
		printf("%d\t%d\n", i, combined_list[i]);
	}
	*/
}

int main () {
	int list1[] = {1,3,5};
	int list2[] = {2,4};
	int len_list1 = sizeof(list1) / sizeof(list1[0]);
	int len_list2 = sizeof(list2) / sizeof(list2[0]);
	
	int list_combined[len_list1 + len_list2];
	
	combine_list (list1, len_list1, list2, len_list2, list_combined);
	
	float median = get_median (list_combined, (len_list1 + len_list2));
	
	printf("The median of the two arrays is:\t%f\n\n\n", median);
	
	return (0);
}
