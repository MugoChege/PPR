using System;

namespace next_permutation_ns
{
	class next_permutation_c
	{
		static int exponented (int radix, int exponent){
			int nje = 1;
			
			for (int i = 0; i < exponent; i++){
				nje *= radix;
			}
			
			return (nje);
		}
		
		static int number_from_list (int [] list){
			int len_list = list.Length;
			int nje = 0;
			int radix = 10;
			
			for (int i = 0; i < len_list; i++){
				nje += (list[i] * exponented(radix, (len_list - 1 - i)));
			}
			
			return (nje);
		}
		
		static int [] number_to_list (int number, int len_list){
			int [] nje = new int [len_list];
			
			for (int i = 0; i < len_list; i++){
				nje[i] = 0;
			}
			
			int radix = 10;
			int running_number = number;
			int nje_cursor = len_list - 1;
			
			while ((running_number > 0) && (nje_cursor >= 0)){
				int modulo = running_number % radix;
				running_number -= modulo;
				running_number /= radix;
				nje[nje_cursor] = modulo;
				nje_cursor--;
			}
			
			return (nje);
		}
		
		static bool list_comparison (int [] list1, int [] list2){
			int len_list1 = list1.Length;
			int len_list2 = list2.Length;
			
			if (len_list1 != len_list2){
				return (false);
			}
			
			bool [] list1_bool_map = new bool[len_list1];
			bool [] list2_bool_map = new bool[len_list1];
			
			for (int i = 0; i < len_list1; i++){
				list1_bool_map[i] = false;
				list2_bool_map[i] = false;
			}
			
			for (int i = 0; i < len_list1; i++){
				for (int j = 0; j < len_list1; j++){
					if ((list1_bool_map[i] == false) && (list2_bool_map[j] == false)){
						if (list1[i] == list2[j]){
							list1_bool_map[i] = true;
							list2_bool_map[j] = true;
							break;
						}
					}
				}
			}
			
			int bool_counter = 0;
			
			for (int i = 0; i < len_list1; i++){
				if (list1_bool_map[i] && list2_bool_map[i]){
					bool_counter++;
				}
			}
			
			return (len_list1 == bool_counter);
		}
		
		static void Main (String [] args){
			int [] nums = {1,2,3,4,3};
			int len_nums = nums.Length;
			
			int nums_number = number_from_list(nums);
			Array.Sort(nums);
			Array.Reverse(nums);
			int highest_value_nums_number = number_from_list(nums);
			
			Console.Write("The value of the number from the elements is:\t");
			Console.WriteLine(nums_number);
			Console.Write("The highest number from the elements is:\t");
			Console.WriteLine(highest_value_nums_number);
			
			int running_number = nums_number;
			int [] next_permutation = new int [len_nums];
			
			while (running_number <= highest_value_nums_number){
				int [] temp_array = number_to_list(running_number, len_nums);
				
				if (list_comparison(temp_array, nums) && (running_number != nums_number)){
					for (int i = 0; i < len_nums; i++){
						next_permutation[i] = temp_array[i];
					}
					break;
				}
				
				running_number++;
			}
			
			for (int i = 0; i < len_nums; i++){
				Console.Write(next_permutation[i]);
				/*
				if (j != (len_nums - 1)){
					Console.Write("\t");
				}
				*/
			}
			Console.WriteLine("\n\n\n");
		}
	}
}
