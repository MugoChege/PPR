static CASE_SENSITIVE: bool = false;

fn compare_string (text1: String, text2: String) -> bool {
	let mut nje: bool = false;
	let len_text1: usize = text1.len();
	let len_text2: usize = text2.len();
	
	if ((len_text1 == 0) && (len_text2 == 0)){
		nje = true;
		return (nje);
	}
	
	if (len_text1 != len_text2){
		return (nje);
	}
	
	let mut text1_c: String = text1;
	let mut text2_c: String = text2;
	
	if (CASE_SENSITIVE){
		text1_c.to_uppercase();
		text2_c.to_uppercase();
	}
	
	nje = text1_c == text2_c;
	
	return(nje);
}

fn first_occurence (needle: String, haystack: String) -> isize{
	let len_needle: usize = needle.len();
	let len_haystack: usize = haystack.len();
	
	let mut nje: isize = -1;
	
	if (len_needle > len_haystack){
		nje = -1;
	} else if (len_needle == len_haystack){
		nje = if (compare_string(needle, haystack)) {0} else {-1};
	} else {
		let len_searchable: usize = len_haystack - len_needle +1;
		
		for i in 0..len_searchable{
			let substring: String = haystack[i..(i + len_needle)].to_string();
			
			if (compare_string(needle.clone(), substring.clone())){
				nje = i as isize;
				break;
			}
		}
	}
	
	return (nje);
}

fn main(){
	let haystack: String = "leetcode".to_string();
	let needle: String = "ode".to_string();
	
	println!("This is the handy work of Rust.\n\n\n{}\n\n\n", first_occurence(needle.clone(), haystack.clone()));
}
