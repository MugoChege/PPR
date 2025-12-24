using System;

namespace median_of_two_sorted_arrays_ns
{
	class median_of_two_sorted_arrays_c
	{
		static float get_median(int[] list){
			int len_list = list.Length;
			bool even_length = (len_list % 2 == 0);
			float nje;
			
			if (even_length){
				nje = ((float) list[len_list / 2] + (float) list[(len_list / 2) - 1]) / 2;
			} else {
				nje = list[len_list / 2];
			}
			
			return (nje);
		}
		
		static int [] combined_list (int [] list1, int [] list2){
			int len_list1 = list1.Length;
			int len_list2 = list2.Length;
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
			
			Array.Sort(combined_list);
			
			return (combined_list);
		}
		
		static void Main (String [] args){
			int [] list1 = {1,3};
			int [] list2 = {2,4};
			int [] list_combined = combined_list(list1, list2);
			
			float median = get_median (list_combined);
			
			Console.WriteLine(median);
			Console.WriteLine("\n\n\n");
		}
	}
}
