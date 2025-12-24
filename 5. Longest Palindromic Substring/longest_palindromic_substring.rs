fn is_palindrome (sub: String) -> bool{
	let len_sub: usize = sub.len();
	let mir: usize = len_sub / 2;
	let mut out: bool = false;
	
	for i in 0..mir{
		if (i == 0){
			out = (sub.chars().nth(i).unwrap() == sub.chars().nth(len_sub - 1 - i).unwrap())
		} else {
			out = out && (sub.chars().nth(i).unwrap() == sub.chars().nth(len_sub - 1 - i).unwrap());
		}
	}
	
	return (out);
}

fn longest_substring (text: String) -> String{
	let len_text: usize = text.len();
	let mut longest_text: String = "".to_string();
	
	for i in 0..len_text{
		for j in (0..(len_text - i - 1)).rev(){
			let substring: String = text[i..(i + j + 1)].to_string();
			
			if (is_palindrome(substring.clone())){
				if (longest_text.len() < substring.len()){
					longest_text = substring;
					break;
				}
			}
		}
	}
	
	return (longest_text);
}

fn main () {
	let word: String = "babab".to_string();
	println!("This is the handy work of Rust.\n\n\n");
	println!("{}", longest_substring(word));
	println!("\n\n\n");
}
