using System;

namespace longest_common_prefix_ns
{
	class longest_common_prefix_c
	{
		public static int prefix_cutoff(string[] words){
			int word_length = words.Length;
			bool evaluator = true;
			int nje = 0;
			int shortest_word_length = 0;
			char first_letter = '\0';
			
			for (int i = 0; i < word_length; i++){
				int len_word = words[i].Length;
				
				if (i == 0){
					shortest_word_length = len_word;
				} else {
					shortest_word_length = (shortest_word_length < len_word) ? (len_word) : (shortest_word_length);
				}
			}
			
			while ((nje < shortest_word_length) && (evaluator)){
				bool exit = false;
				
				for (int i = 0; i < word_length; i++){
					if (i == 0){
						first_letter = words[i][nje];
					} else {
						if (first_letter != words[i][nje]){
							exit = true;
							evaluator = false;
						}
					}
				}
				
				if (exit){
					break;
				}
				
				nje++;
			}
			return (nje);
		}
		
		public static void Main (string[] args) {
			string[] words = {"flower","flow","floght","flock"};
			int len_words = words.Length;
			
			int prefix = prefix_cutoff(words);
			
			Console.Write("This is the handy work of C#.\n\n\nThe first ");
			Console.Write(prefix);
			Console.Write(" characters are similar in the words.\n\n\n");
			
			for (int i = 0; i < prefix; i++){
				Console.Write(words[0][i]);
			}
			
			Console.WriteLine("\n\n");
		}
	}
}
