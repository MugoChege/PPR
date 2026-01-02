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
	
	public static int[] combine_list (int[] list1, int[] list2){
		Arrays.sort(list1);
		Arrays.sort(list2);
		
		int len_list1 = list1.length;
		int len_list2 = list2.length;
		
		int[] nje = new int [len_list1 + len_list2];
		
		int nje_cursor = 0;
		int list1_cursor = 0;
		int list2_cursor = 0;
		
		while ((list1_cursor < len_list1) || (list2_cursor < len_list2)){
			int element_list1 = 0;
			boolean element_list1_is_null = true;
			int element_list2 = 0;
			boolean element_list2_is_null = true;
			int appending_element = 0;
			
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
					list1_cursor += 1;
				} else {
					appending_element = element_list2;
					list2_cursor += 1;
				}
			} else if (element_list1_is_null){
				appending_element = element_list2;
				list2_cursor += 1;
			} else if (element_list2_is_null){
				appending_element = element_list1;
				list1_cursor += 1;
			}
			
			nje[nje_cursor] = appending_element;
			nje_cursor += 1;
		}
		
		return (nje);
	}
	
	public static void main (String [] args){
		int [] list1 = {1,3};
		int [] list2 = {2,4};
		
		int [] list_combined = combine_list(list1, list2);
		
		float median = get_median(list_combined);
		
		System.out.println("This is the handy work of Java.\n\n");
		System.out.print(median);
		System.out.print("\n\n\n");
	}
}
