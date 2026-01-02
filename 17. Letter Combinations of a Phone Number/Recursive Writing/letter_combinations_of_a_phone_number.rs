const combinations: [&str; 10] = [" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];

fn word_from_odo (relevant_digits: &String, digits_odo: &Vec<usize>) -> String {
	let mut nje: String = "".to_string();
	let length: usize = relevant_digits.len();
	
	for i in 0..length{
		let digit: usize = relevant_digits.chars().nth(i).unwrap().to_digit(10).unwrap() as usize;
		nje.push(combinations[digit].chars().nth(digits_odo[i]).unwrap());
	}
	
	return (nje);
}

fn word_fill (relevant_digits: &String, digits_odo: &Vec<usize>, depth: usize, mut sample_space: &mut Vec<String>) -> (){
	let len_letter_options: usize = combinations[relevant_digits.chars().nth(depth).unwrap().to_digit(10).unwrap() as usize].len();
	let max_depth: usize = relevant_digits.len();
	let mut temp_digits_odo: Vec<usize> = digits_odo.clone();
	
	for i in 0..len_letter_options{
		temp_digits_odo[depth] = i;
		if (depth < (max_depth - 1)){
			word_fill (&relevant_digits, &temp_digits_odo, (depth + 1), &mut sample_space);
		} else {
			let word: String = word_from_odo(relevant_digits, &temp_digits_odo);
			sample_space.push(word);
		}
	}
}

fn get_letter_combinations (digits: String) -> Vec<String> {
	let len_digits: usize = digits.len();
	let mut useable_digits: String = "".to_string();
	let mut odo: Vec<usize> = vec![];
	let mut nje: Vec<String> = vec![];
	
	for i in 0..len_digits{
		let len_letters: usize = combinations[digits.chars().nth(i).unwrap().to_digit(10).unwrap() as usize].len();
		if (len_letters == 0){
			continue;
		}
		
		useable_digits.push(digits.chars().nth(i).unwrap());
		odo.push(0);
	}
	
	word_fill (&useable_digits, &odo.clone(), 0, &mut nje);
	
	return (nje);
}

fn main () {
	let digits: String = "68072".to_string();
	let words: Vec<String> = get_letter_combinations(digits);
	
	println!("This is the handy work of Rust.\n\n\n");
	
	for i in words{
		println!("{}", i);
	}
	
	println!("\n\n\n");
}
