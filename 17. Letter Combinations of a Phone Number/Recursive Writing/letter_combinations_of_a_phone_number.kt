val combinations: Array<String> = arrayOf(" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz");
var sample_space_cursor: Int = 0;

fun char_to_int (ch: Char): Int{
	return (ch.toInt() - 48);
}

fun word_from_odo (relevant_digits: String, digits_odo: Array<Int>): String{
	var nje: String = "";
	val length: Int = digits_odo.size;
	
	for (i in 0 until length){
		val digit = char_to_int(relevant_digits[i]);
		nje += combinations[digit][digits_odo[i]];
	}
	
	return (nje);
}

fun word_fill (relevant_digits: String, digits_odo: Array<Int>, depth: Int, sample_space: Array<String>): Unit{
	val len_letter_options: Int = combinations[char_to_int(relevant_digits[depth])].length;
	val max_depth: Int = relevant_digits.length;
	var temp_digits_odo: Array<Int> = digits_odo;
	
	for (i in 0 until len_letter_options){
		temp_digits_odo[depth] = i;
		if (depth < (max_depth - 1)){
			word_fill (relevant_digits, temp_digits_odo, (depth + 1), sample_space);
		} else {
			val word: String = word_from_odo(relevant_digits, temp_digits_odo);
			sample_space[sample_space_cursor] = word;
			sample_space_cursor += 1;
		}
	}
}

fun get_letter_combinations (digits: String): Array<String>{
	val len_digits: Int = digits.length;
	var odo_length: Int = 0;
	var useable_digits: String = "";
	var sample_size: Int = 0;
	
	for (i in 0 until len_digits){
		val len_letters = combinations[char_to_int(digits[i])].length;
		if (len_letters == 0){
			continue;
		}
		
		useable_digits = useable_digits + digits[i];
		odo_length += 1;
		
		if (i == 0){
			sample_size = len_letters;
		} else {
			sample_size *= len_letters;
		}
	}
	
	var odo: Array<Int> = Array(odo_length) {0};
	var nje: Array<String> = Array(sample_size) {""};
	
	word_fill(useable_digits, odo, 0, nje);
	
	return (nje);
}

fun main (){
	val digits: String = "68072";
	var words: Array<String> = get_letter_combinations (digits);
	
	println("This is the handy work of Kotlin.\n\n\n");
	
	for (i in 0 until words.size){
		println(words[i]);
	}
	
	println("\n\n\n");
}
