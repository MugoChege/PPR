using System;

namespace permutations_ns
{
	class permutations_c
	{
		static int exponented (int radix, int exponent){
			int nje = 1;
			
			for (int i = 0; i < exponent; i++){
				nje *= radix;
			}
			
			return (nje);
		}
		
		static int factorial (int number){
			int nje = 1;
			
			for (int i = number; i > 0; i--){
				nje *= i;
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
		
		static int appears (int element, int [] list){
			int len_list = list.Length;
			int nje = -1;
			
			for (int i = 0; i < len_list; i++){
				if (element == list[i]){
					nje += 1;
				}
			}
			return (nje);
		}
		
		//reverse
		//compare
		
		static void Main (String [] args){
			int [] nums = {1,2,3,4};
			int len_nums = nums.Length;
			
			//sort
			Array.Sort(nums);
			
			int lowest_value_nums_number = number_from_list(nums);
			//reverse
			Array.Reverse(nums);
			int highest_value_nums_number = number_from_list(nums);
			
			Console.Write("The lowest number from the elements is:\t");
			Console.WriteLine(lowest_value_nums_number);
			Console.Write("The highest number from the elements is:\t");
			Console.WriteLine(highest_value_nums_number);
			
			int sample_size = factorial(len_nums);
			int unique = 0;
			
			for (int i = 0; i < len_nums; i++){
				bool occ_code = false;
				
				if (i == 0){
					occ_code = true;
				} else {
					if (nums[i - 1] != nums[i]){
						occ_code = true;
					}
				}
				
				if (occ_code){
					int occurences = appears(nums[i], nums);
					if (occurences == 0){
						unique++;
					}
					
					if (occurences > 0){
						unique++;
						sample_size /= factorial(occurences + 1);
					}
				}
			}
			
			Console.Write("The number of unique elements are:\t");
			Console.WriteLine(unique);
			Console.Write("The sample size of permutations expected is:\t");
			Console.WriteLine(sample_size);
			Console.WriteLine("\n\n\n");
			
			int [,] permutations = new int [sample_size, len_nums];
			int running_number = lowest_value_nums_number;
			int permutations_cursor = 0;
			
			while (running_number <= highest_value_nums_number){
				int [] temp_array = number_to_list(running_number, len_nums);
				
				if (list_comparison(temp_array, nums)){
					for (int i = 0; i < len_nums; i++){
						permutations[permutations_cursor, i] = temp_array[i];
					}
					permutations_cursor++;
				}
				
				running_number++;
			}
			
			for (int i = 0; i < permutations_cursor; i++){
				for (int j = 0; j < len_nums; j++){
					Console.Write(permutations[i, j]);
					/*
					if (j != (len_nums - 1)){
						Console.Write("\t");
					}
					*/
				}
				Console.WriteLine();
			}
			Console.WriteLine("\n\n\n");
		}
	}
}
