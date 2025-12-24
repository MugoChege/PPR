fn longest_substring (text: String) -> String {
	let len_text: usize = text.len();
	let mut longest_text: String = "".to_string();
	
	for a in 0..len_text{
		for b in a..len_text{
			if (a + b) >= len_text{
				break;
			}
			
			let substring: String = text[a..(a + b)].to_string();
			let letter: &str = &text[(a + b)..(a + b + 1)];
			
			if substring.contains(letter){
				if longest_text.len() < substring.len(){
					longest_text = substring;
				}
				break;
			}
		}
	}
	return longest_text;
}

fn main () {
	let f: String = "pwwkew".to_string();
	let ret: String = longest_substring(f);
	
	println!("{}", ret);
}
