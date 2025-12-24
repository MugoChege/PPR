func is_palindrome (sub: String) -> Bool{
	let len_sub: Int = sub.count;
	let mir: Int = len_sub / 2;
	var out: Bool = false;
	
	for i in 0..<mir{
		let frontIndex = sub.index(sub.startIndex, offsetBy: i);
		let rearIndex = sub.index(sub.startIndex, offsetBy: (len_sub - 1 - i));
		if (i == 0){
			out = (sub[frontIndex] == sub[rearIndex]);
		} else {
			out = out && (sub[frontIndex] == sub[rearIndex])
		}
	}
	
	return (out);
}

func longest_substring (text: String) -> String{
	let len_text: Int = text.count;
	var longest_text: String = "";
	
	for i in 0..<len_text{
		for j in stride(from: ((len_text - 1) - i), to: 0, by: -1){
			let frontIndex = text.index(text.startIndex, offsetBy: i);
			let rearIndex = text.index(text.startIndex, offsetBy: (i + j + 1))
			let substring: String = String(text[frontIndex..<rearIndex]);
			
			
			if (is_palindrome(sub: substring)){
				if (longest_text.count < substring.count){
					longest_text = substring;
					break;
				}
			}
			
		}
	}
	
	return (longest_text);
}

let word: String = "babob";
print("This is the handy work of Swift\n\n");
print(longest_substring(text: word));
print("\n\n");
