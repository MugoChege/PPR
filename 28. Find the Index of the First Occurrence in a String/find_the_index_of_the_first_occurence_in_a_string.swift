let CASE_SENSITIVE: Bool = false;

func compare_string (text1: String, text2: String) -> Bool {
	var nje: Bool = false;
	let len_text1: Int = text1.count;
	let len_text2: Int = text2.count;
	
	if ((len_text1 == 0) && (len_text2 == 0)){
		nje = true;
		return (nje);
	}
	
	if (len_text1 != len_text2){
		return (nje);
	}
	
	var text1_c: String = text1;
	var text2_c: String = text2;
	
	if (CASE_SENSITIVE){
		text1_c.uppercased();
		text2_c.uppercased();
	}
	
	nje = text1_c == text2_c;
	
	return (nje);
}

func first_occurence (needle: String, haystack: String) -> Int{
	let len_needle: Int = needle.count;
	let len_haystack: Int = haystack.count;
	
	var nje: Int = -1;
	
	if (len_needle > len_haystack){
		nje = -1;
	} else if (len_needle == len_haystack){
		nje = (compare_string(text1: needle, text2: haystack)) ? 0 : -1;
	} else {
		let len_searchable: Int = len_haystack - len_needle + 1;
		
		for i in 0..<len_searchable{
			let beg = haystack.index(haystack.startIndex, offsetBy: i);
			let end = haystack.index(haystack.startIndex, offsetBy: i + len_needle);
			var substring: String = String(haystack[beg..<end]);
			
			if (compare_string(text1: needle, text2: substring)){
				nje = i;
				break;
			}
		}
	}
	
	return (nje);
}


let haystack: String = "leetcode";
let needle: String = "od";

print("This is the handy work of Swift.\n\n\n");
print(first_occurence(needle: needle, haystack: haystack));
print("\n\n\n");
