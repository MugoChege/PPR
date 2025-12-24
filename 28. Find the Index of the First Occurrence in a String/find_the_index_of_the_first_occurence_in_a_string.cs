using System;

namespace find_the_index_of_the_first_occurence_in_a_string_ns
{
	class find_the_index_of_the_first_occurence_in_a_string_c
	{
		public static bool CASE_SENSITIVE = false;
		
		public static bool compare_string (string text1, string text2){
			bool nje = false;
			int len_text1 = text1.Length;
			int len_text2 = text2.Length;
			
			if ((len_text1 == 0) && (len_text2 == 0)){
				nje = true;
				return (nje);
			}
			
			if (len_text1 != len_text2){
				return (nje);
			}
			
			string text1_c = text1;
			string text2_c = text2;
			
			if (CASE_SENSITIVE){
				text1_c.ToUpper();
				text2_c.ToUpper();
			}
			
			for (int i = 0; i < len_text1; i++){
				if (i == 0){
					nje = (text1_c[i] == text2_c[i]);
				} else {
					nje = nje && (text1_c[i] == text2_c[i]);
				}
			}
			return (nje);
		}
		
		public static int first_occurence (string needle, string haystack){
			int len_needle = needle.Length;
			int len_haystack = haystack.Length;
			int nje = -1;
			
			if (len_needle > len_haystack){
				nje = -1;
			} else if (len_needle == len_haystack){
				nje = compare_string(needle, haystack) ? 0 : -1;
			} else {
				int len_searchable = len_haystack - len_needle + 1;
				
				for (int i = 0; i < len_searchable; i++){
					string substring = haystack.Substring(i,len_needle);
					
					if (compare_string(needle, substring)){
						nje = i;
						break;
					}
				}
			}
			
			return (nje);
		}
		
		public static void Main (string[] args){
			string haystack = "leetcode";
			string needle = "et";
			
			Console.WriteLine ("This is the handy work of C#.\n\n\n");
			Console.Write(first_occurence(needle, haystack));
			Console.WriteLine ("\n\n\n");
		}
	}
}
