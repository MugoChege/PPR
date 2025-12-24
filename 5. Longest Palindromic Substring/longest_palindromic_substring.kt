fun is_palindrome (sub: String) : Boolean{
	val len_sub: Int = sub.length;
	val mir: Int = len_sub / 2;
	var out: Boolean = false;
	
	for (i in 0 until mir){
		if (i == 0){
			out = sub[i] == sub[len_sub - 1 - i];
		} else {
			out = out && (sub[i] == sub[len_sub - 1 - i]);
		}
	}
	
	return (out);
}

fun longest_substring (text: String) : String{
	val len_text: Int = text.length;
	var longest_text: String = "";
	
	for (i in 0 until len_text){
		for (j in (len_text - 1 - i) downTo 0){
			val substring: String = text.substring(i, (i + j + 1));
			
			if (is_palindrome (substring)){
				if (longest_text.length < substring.length){
					longest_text = substring;
					break;
				}
			}
		}
	}
	
	return (longest_text);
}

fun main () {
	val word: String = "babob";
	println("This is the handy work of Kotlin\n\n\n");
	println(longest_substring(word));
	println("\n\n\n");
}
