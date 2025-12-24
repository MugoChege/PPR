class longest_common_prefix{
	public static int prefix_cutoff(String[] words){
		int word_length = words.length;
		boolean evaluator = true;
		int out = 0;
		int shortest_word_length = 0;
		char first_letter = '\0';
		
		for (int i = 0; i < word_length; i++){
			int len_word = words[i].length();
			
			if (i == 0){
				shortest_word_length = len_word;
			} else {
				shortest_word_length = (shortest_word_length < len_word) ? (len_word) : (shortest_word_length);
			}
		}
		
		while ((out < shortest_word_length) && (evaluator)){
			boolean exit = false;
			
			for (int i = 0; i < word_length; i++){
				if (i == 0){
					first_letter = words[i].charAt(out);
				} else {
					if (first_letter != words[i].charAt(out)){
						exit = true;
						evaluator = false;
					}
				}
			}
			
			if (exit){
				break;
			}
			
			out++;
		}
		
		return (out);
	}
	
	public static void main (String[] args){
		String[] words = {"flower","flow","floght","flock"};
		int len_words = words.length;
		
		int prefix = prefix_cutoff(words);
		
		System.out.println("This is the handy work of Java.\n\n\nThe first ");
		System.out.print(prefix);
		System.out.print(" characters are similar in the words.\n\n");
		
		for (int i = 0; i < prefix; i++){
			System.out.print(words[0].charAt(i));
		}
		
		System.out.print("\n\n\n");
		
	}
}
