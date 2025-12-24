func longest_substring (text: String) -> String{
	let len_text: Int = text.count;
	var longest_text: String = "";
	
	for a in 0..<len_text{
		if (len_text - a) > a{
			for b in a..<(len_text - a){
				if ((a + b) >= len_text) || (b < a){
					break;
				} else {
				
					let startIndex = text.index(text.startIndex, offsetBy: a);
					let endIndex = text.index(text.startIndex, offsetBy: (a + b));
					
					var substring: String = String(text[startIndex..<endIndex]);
					var letter: Character = text[text.index(text.startIndex, offsetBy: (a + b))];
					
					if substring.contains(letter){
						if longest_text.count < substring.count{
							longest_text = substring;
						}
						break;
					}
				}
			}
		}
	}
	
	return longest_text;
}

var f: String = "pwwkew";
var ret: String = longest_substring(text: f);

print(ret);
