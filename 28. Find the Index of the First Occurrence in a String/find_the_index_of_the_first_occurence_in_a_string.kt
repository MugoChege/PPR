val CASE_SENSITIVE: Boolean = false;

fun compare_string (text1: String, text2: String) : Boolean{
	var out: Boolean = false;
	val len_text1 = text1.length;
	val len_text2 = text2.length;
	
	if ((len_text1 == 0) && (len_text2 == 0)){
		out = true;
		return (out);
	}
	
	if (len_text1 != len_text2){
		return (out);
	}
	
	var text1_c: String = text1;
	var text2_c: String = text2;
	
	if (CASE_SENSITIVE){
		text1_c = text1.toUpperCase();
		text2_c = text2.toUpperCase();
	}
	
	out = (text1_c == text2_c);
	
	return (out);
}

fun first_occurence (needle: String, haystack: String) : Int{
	val len_needle: Int = needle.length;
	val len_haystack: Int = haystack.length;
	
	var nje: Int = -1;
	
	if (len_needle > len_haystack){
		nje = -1;
	} else if (len_needle == len_haystack){
		nje = if (compare_string(needle, haystack)) 0 else -1;
	} else {
		val len_searchable: Int = len_haystack - len_needle + 1;
		
		for (i in 0 until len_searchable){
			var substring = haystack.substring(i , i + len_needle);
			
			if (compare_string(needle, substring)){
				nje = i;
				break;
			}
		}
	}
	
	return (nje);
}

fun main () {
	val haystack: String = "leetcode";
	val needle: String = "et";
	
	println("This is the handy work of Kotlin.\n\n\n");
	println(first_occurence(needle, haystack));
	println("\n\n\n");
}
