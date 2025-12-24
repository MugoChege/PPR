using System;

namespace remove_duplicates_from_sorted_arrays_ns
{
	class remove_duplicates_from_sorted_arrays_c
	{
		public static int duplicates_shifting_remove (int [] list){
			int counter = 0;
			int len_list = list.Length;
			
			Array.Sort(list);
			
			for (int i = (len_list - 1); i >= 0; i--){
				int element = list[i];
				bool unique = true;
				
				for (int j = 0; j < i; j++){
					if (element == list[j]){
						unique = false;
						break;
					}
				}
				
				if (unique == false){
					counter ++;
					int holder = list[i];
					
					for (int j = i; j < (len_list - 1); j++){
						list[j] = list[j + 1];
					}
					
					list[len_list - 1] = holder;
				}
			}
			
			return (counter);
		}
		
		public static void Main (String [] args){
			int [] nums = {0,0,1,1,1,2,2,3,3,4};
			int len_nums = nums.Length;
			
			int rem = duplicates_shifting_remove(nums);
			
			Console.WriteLine("This is the handy work of C#\n\n");
			Console.WriteLine(rem);
			Console.WriteLine("\n\n\n");
			
			Console.Write("[");
			for (int i = 0; i < len_nums; i++){
				Console.Write(nums[i]);
				
				if (i == (len_nums - 1)){
					Console.WriteLine("]");
				} else {
					Console.Write(", ");
				}
			}
			
			Console.Write("\n\n\n[");
			for (int i = 0; i < (len_nums - rem); i++){
				Console.Write(nums[i]);
				
				if (i == ((len_nums - rem) - 1)){
					Console.WriteLine("]");
				} else {
					Console.Write(", ");
				}
			}
		}
	}
}
