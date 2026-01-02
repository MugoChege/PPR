class letter_combinations_of_a_phone_number{
	public static int sample_space_cursor = 0;
	
	public static String[] combinations = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	
	public static String word_from_odo (String relevant_digits, int[] digits_odo){
		String nje = "";
		int length = digits_odo.length;
		
		for (int i = 0; i < length; i++){
			int digit = relevant_digits.charAt(i) - '0';
			nje += combinations[digit].charAt(digits_odo[i]);
		}
		
		return (nje);
	}
	
	public static void word_fill (String relevant_digits, int[] digits_odo, int depth, String[] sample_space){
		int len_letter_options = combinations[relevant_digits.charAt(depth) - '0'].length();
		int max_depth = relevant_digits.length();
		
		for (int i = 0; i < len_letter_options; i++){
			digits_odo[depth] = i;
			if (depth < (max_depth - 1)){
				word_fill (relevant_digits, digits_odo, (depth + 1), sample_space);
			} else {
				String word = word_from_odo (relevant_digits, digits_odo);
				sample_space[sample_space_cursor] = word;
				sample_space_cursor += 1;
			}
		}
	}
	
	public static String[] get_letter_combinations (String digits){
		int len_digits = digits.length();
		int odo_length = 0;
		String useable_digits = "";
		int sample_size = 0;
		
		for (int i = 0; i < len_digits; i++){
			int len_letters = combinations[digits.charAt(i) - '0'].length();
			if (len_letters == 0){
				continue;
			}
			
			useable_digits += digits.charAt(i);
			odo_length += 1;
			
			if (i == 0){
				sample_size = len_letters;
			} else {
				sample_size *= len_letters;
			}
		}
		
		int[] odo = new int[odo_length];
		String[] nje = new String[sample_size];
		
		for (int i = 0; i < odo_length; i++){
			odo[i] = 0;
		}
		
		word_fill (useable_digits, odo, 0,  nje);
		
		return (nje);
	}
	
	public static void main (String[] args){
		String digits = "68072";
		String[] words = get_letter_combinations (digits);
		
		System.out.println("This is the handy work of Java.\n\n\n");
		
		for (int i = 0; i < words.length; i++){
			System.out.println(words[i]);
		}
		
		System.out.println("\n\n\n");
	}
}
