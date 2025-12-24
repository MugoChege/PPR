using System;

namespace longest_palindromic_substring_ns
{
	class longest_palindromic_substring_c
	{
		public static bool is_palindrome (string sub){
			int len_sub = sub.Length;
			int mir = len_sub / 2;
			bool nje = false;
			
			for (int i = 0; i < mir; i++){
				if (i == 0){
					nje = (sub[i] == sub[len_sub - 1 - i]);
				} else {
					nje = nje && (sub[i] == sub[len_sub - 1 - i]);
				}
			}
			
			return (nje);
		}
		
		public static string longest_substring (string text){
			int len_text = text.Length;
			string longest_text = "";
			
			for (int i = 0; i < len_text; i++){
				for (int j = (len_text - i); j >= 0; j--){
					string substring = text.Substring(i, (j));
					
					if (is_palindrome(substring)){
						if (longest_text.Length < substring.Length){
							longest_text = substring;
							break;
						}
					}
				}
			}
			return (longest_text);
		}
		
		public static void Main (string[] args){
			string word = "babob";
			Console.WriteLine("This is the handy work of C#.\n\n\n");
			Console.WriteLine(longest_substring(word));
			Console.WriteLine("\n\n\n");
		}
	}
}
