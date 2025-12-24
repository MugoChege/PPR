fun prefix_cutoff(words: Array<String>) : Int{
	val word_length: Int = words.size;
	var evaluator: Boolean = true;
	var out: Int = 0;
	var shortest_word_length: Int = 0;
	var first_letter: Char = '\u0000';
	
	for (i in 0 until word_length){
		val len_word: Int = words[i].length;
		
		if (i == 0){
			shortest_word_length = len_word;
		} else {
			shortest_word_length = if (shortest_word_length < len_word) (len_word) else (shortest_word_length);
		}
	}
	
	while ((out < shortest_word_length) && (evaluator)){
		var exit: Boolean = false;
		
		for (i in 0 until word_length){
			if (i == 0){
				first_letter = words[i][out];
			} else {
				if (first_letter != words[i][out]){
					exit = true;
					evaluator = false;
				}
			}
		}
		
		if (exit){
			break;
		}
		
		out += 1;
	}
	
	return (out);
}

fun main () {
	val words: Array<String> = arrayOf("flower","flow","flight","flock");
	val len_words: Int = words.size;
	
	val prefix: Int = prefix_cutoff(words);
	
	print("This is the handy work of Kotlin.\n\n\nThe first ");
	print(prefix);
	print(" characters are similar in the words.\n\n\n");
	
	for (i in 0 until prefix){
		print (words[0][i]);
	}
	
	print("\n\n\n");
}
