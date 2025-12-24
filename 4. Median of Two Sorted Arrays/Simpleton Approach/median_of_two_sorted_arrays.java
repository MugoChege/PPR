import java.util.Arrays;

class median_of_two_sorted_arrays{
	public static float get_median (int [] list){
		int len_list = list.length;
		boolean even_length = (len_list % 2 == 0);
		float median = 0;
		
		if (even_length){
			median = ((float)list[len_list / 2] + (float)list[(len_list / 2) - 1]) / 2;
		} else {
			median = ((float)list[len_list / 2]);
		}
		
		return (median);
	}
	
	public static int [] combine_list (int [] list1, int [] list2){
		int len_list1 = list1.length;
		int len_list2 = list2.length;
		
		int [] combined_list = new int [len_list1 + len_list2];
		int combined_list_cursor = 0;
		
		for (int i = 0; i < len_list1; i++){
			combined_list[combined_list_cursor] = list1[i];
			combined_list_cursor++;
		}
		
		for (int i = 0; i < len_list2; i++){
			combined_list[combined_list_cursor] = list2[i];
			combined_list_cursor++;
		}
		
		Arrays.sort(combined_list);
		
		return (combined_list);
	}
	
	public static void main (String [] args){
		int [] list1 = {1,3};
		int [] list2 = {2,4};
		
		int [] list_combined = combine_list(list1, list2);
		
		float median = get_median(list_combined);
		
		System.out.print(median);
		System.out.print("\n\n\n");
	}
}
