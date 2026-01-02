using System;

namespace letter_combinations_of_a_phone_number_ns
{
	class letter_combinations_of_a_phone_number_c
	{
	
	public static int sample_space_cursor = 0;
	public static string[] combinations = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	
	public static string word_from_odo (string relevant_digits, int[] digits_odo){
		string nje = "";
		int length = digits_odo.Length;
		
		for (int i = 0; i < length; i++){
			//int digit = int.Parse(relevant_digits[i]) % 10;
			int digit = relevant_digits[i] - '0';
			nje += combinations[digit][digits_odo[i]];
		}
		
		return (nje);
	}
	
	public static void word_fill (string relevant_digits, int[] digits_odo, int depth, string[] sample_space){
		//int let_letter_options = combinations[int.Parse(relevant_digits[depth])];
		int len_letter_options = combinations[relevant_digits[depth] - '0'].Length;
		int max_depth = relevant_digits.Length;
		
		for (int i = 0; i < len_letter_options; i++){
			digits_odo[depth] = i;
			if (depth < (max_depth - 1)){
				word_fill (relevant_digits, digits_odo, (depth + 1), sample_space);
			} else {
				string word = word_from_odo (relevant_digits, digits_odo);
				sample_space[sample_space_cursor] = word;
				sample_space_cursor += 1;
			}
		}
	}
	
	public static string[] get_letter_combinations (string digits){
		int len_digits = digits.Length;
		int odo_length = 0;
		string useable_digits = "";
		int sample_size = 0;
		
		for (int i = 0; i < len_digits; i++){
			//int len_letters = combinations[int.Parse(digits[i])].Length;
			int len_letters = combinations[digits[i] - '0'].Length;
			if (len_letters == 0){
				continue;
			}
			
			useable_digits += digits[i];
			odo_length += 1;
			
			if (i == 0){
				sample_size = len_letters;
			} else {
				sample_size *= len_letters;
			}
		}
		
		int[] odo = new int[odo_length];
		string[] nje = new string[sample_size];
		
		for (int i = 0; i < odo_length; i++){
			odo[i] = 0;
		}
		
		word_fill (useable_digits, odo, 0,  nje);
		
		return (nje);
	}
	
	public static void Main (string[] args){
		string digits = "68072";
		string[] words = get_letter_combinations (digits);
		
		Console.WriteLine("This is the handy work of C#.\n\n\n");
		
		for (int i = 0; i < words.Length; i++){
			Console.WriteLine(words[i]);
		}
		
		Console.WriteLine("\n\n\n");
	}
	
	}
}
