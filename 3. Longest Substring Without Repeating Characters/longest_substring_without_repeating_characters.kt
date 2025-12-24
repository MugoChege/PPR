fun string_find (text: String, l: Char): Boolean{
	var out: Boolean = false;
	var len_text: Int = text.length;
	
	for (a in 0..(len_text - 1)){
		if (text[a] == l){
			out = true;
			break;
		}
	}
	
	return (out);
}

fun longest_substring (text: String): String{
	var len_text: Int = text.length;
	var longest_text = "";
	
	for (a in 0..(len_text - 1)){
		for (b in (a)..(len_text - a - 1)){
			if ((a + b) >= len_text){
				break;
			}
			
			var substring: String = text.substring(a, (a + b));
			var letter: Char = text[a + b];
			
			//println(substring + "\t\t\t" + letter);
			
			if (substring.contains(letter)){
			//if (string_find(substring, letter)){
				if (longest_text.length < substring.length){
					longest_text = substring;
				}
				break;
			}
		}
	}
	
	return (longest_text);
}

fun main () {
	var f: String = "pwwkew";
	//var len_f: Int = f.length;
	var ret: String;
	
	ret = longest_substring(f);
	
	println(ret);
}
