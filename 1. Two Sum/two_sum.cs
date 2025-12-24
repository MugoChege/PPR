using System;

namespace TwoSum
{
	class TwoSum
	{
		static void get_target(int [] nums, int target, int [] ret)
		{
			int len_nums = nums.Length;
			
			//int [] ret = new int [2] {-1, -1};
			
			for (int a = 0; a < len_nums; a++)
			{
				bool exit_loop = false;
				for (int b = 0; b < (len_nums); b++)
				{
					//Console.WriteLine("The value is:\t" + (nums[a] + nums[b]));
					if (b == a)
					{
						continue;
					}
					else 
					{
						if ((nums[a] + nums[b]) == target)
						{
							Console.Write(nums[a]);
							Console.Write("\t\t\t");
							Console.WriteLine(nums[b]);
							
							//Console.Write(ret[0]);
							//Console.Write("\t\t\t");
							//Console.WriteLine(ret[1]);
							ret[0] = nums[a];
							ret[1] = nums[b];
							
							exit_loop = true;
							break;
						}
					}
				}
				if (exit_loop)
				{
					break;
				}
			}
			
			//return ret;
		}
		
		static void Main (string [] args)
		{
			int [] number_list  = {1,2,3,4,5,6,7,8,9};
			int target = 16;
			int [] indices = new int[2];
			
			//indices = get_target(number_list, target);
			get_target(number_list, target, indices);
			
			for (int y = 0; y < indices.Length; y++)
			{
				Console.WriteLine(indices[y]);
			}
		}
	}
}
