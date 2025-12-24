using System;

namespace find_first_and_last_position_of_element_in_sorted_array_ns
{
	class find_first_and_last_position_of_element_in_sorted_array_c
	{
		public static int [] first_and_last(int element, int[] list){
			bool find_first = true;
			int [] nje = {-1,-1};
			int len_list = list.Length;
			Array.Sort(list);
			
			for (int i = 0; i < len_list; i++){
				if(element == list[i]){
					if (find_first){
						nje[0] = i;
						nje[1] = i;
						find_first = false;
					} else {
						nje[1] = i;
					}
				}
			}
			
			return (nje);
		}
		
		public static void Main (String[] args){
			int [] nums = {5,7,7,8,8,10,2};
			int target = 8;
			
			int [] positions = first_and_last (target, nums);
			
			Console.Write("This is the handy work of C#\n\n\n[");
			Console.Write(positions[0]);
			Console.Write(", ");
			Console.Write(positions[1]);
			Console.WriteLine("]\n\n");
			
		}
	}
}
