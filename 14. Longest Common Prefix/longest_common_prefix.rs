fn prefix_cutoff(words: Vec<String>) -> isize {
	let word_length: usize = words.len();
	let mut evaluator: bool = true;
	let mut out: isize = 0;
	let mut shortest_word_length: usize = 0;
	let mut first_letter: char = '\0';
	
	for i in 0..word_length{
		let len_word: usize = words[i].len();
		
		if (i == 0){
			shortest_word_length = len_word;
		} else {
			shortest_word_length = if (shortest_word_length < len_word) {(len_word)} else {(shortest_word_length)};
		}
	}
	
	while (out < (shortest_word_length as isize)) && (evaluator){
		let mut exit: bool = false;
		
		for i in 0..word_length{
			if (i == 0){
				first_letter = words[i].chars().nth(out as usize).unwrap();
			} else {
				if (first_letter != words[i].chars().nth(out as usize).unwrap()){
					exit = true;
					evaluator = false;
				}
			}
		}
		
		if (exit){
			break;
		}
		
		out += 1;
	}
	
	return (out);
}

fn main () {
	//let words: Vec<String> = vec!["flower","flow","floght","flock"];
	let w = ["flower","flow","flight","flock"];
	let mut words: Vec<String> = vec![];
	
	for i in 0..w.len(){
		words.push(w[i].to_string());
	}
	
	let len_words: usize = words.len();
	
	let prefix: isize = prefix_cutoff(words.clone());
	
	print!("This is the handy work of Rust.\n\n\nThe first {} characters are similar in the words.\n\n\n", prefix);
	
	for i in 0..(prefix as usize){
		print!("{}", words[0].chars().nth(i).unwrap());
	}
	
	print!("\n\n\n");
}
