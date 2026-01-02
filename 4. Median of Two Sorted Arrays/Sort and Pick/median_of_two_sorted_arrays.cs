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
		
		static int[] combined_list (int [] list1, int[] list2){
			Array.Sort(list1);
			Array.Sort(list2);
			
			int len_list1 = list1.Length;
			int len_list2 = list2.Length;
			
			int[] nje = new int [len_list1 + len_list2];
			
			int nje_cursor = 0;
			int list1_cursor = 0;
			int list2_cursor = 0;
			
			while ((list1_cursor < len_list1) || (list2_cursor < len_list2)){
				int? element_list1 = null;
				int? element_list2 = null;
				int? appending_element = null;
				
				if (list1_cursor < len_list1){
					element_list1 = list1[list1_cursor];
				}
				
				if (list2_cursor < len_list2){
					element_list2 = list2[list2_cursor];
				}
				
				if ((element_list1 != null) && (element_list2 != null)){
					if (element_list1 < element_list2){
						appending_element = element_list1;
						list1_cursor += 1;
					} else {
						appending_element = element_list2;
						list2_cursor += 1;
					}
				} else if (element_list1 == null){
					appending_element = element_list2;
					list2_cursor += 1;
				} else if (element_list2 == null){
					appending_element = element_list1;
					list1_cursor += 1;
				}
				if (appending_element != null){
					nje[nje_cursor] = appending_element ?? -222;
				}
				nje_cursor += 1;
			}
			
			return (nje);
		}
		
		static void Main (String [] args){
			int [] list1 = {1,3};
			int [] list2 = {2,4};
			int [] list_combined = combined_list(list1, list2);
			
			float median = get_median (list_combined);
			
			Console.WriteLine("This is the handy work of C#\n\n\n");
			Console.WriteLine(median);
			Console.WriteLine("\n\n\n");
		}
	}
}
