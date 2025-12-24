fn exponented (base: isize, exponent: isize) -> isize {
	let mut out: isize = 1;
	
	for i in 0..(exponent as usize){
		out *= base;
	}
	
	return out;
}

fn factorial (number: isize) -> isize {
	let mut out: isize = 1;
	
	for i in (1..=(number as usize)).rev(){
		out *= i as isize;
	}
	
	return out;
}

//ARRAY

//fn number_from_list (list: &[isize]) -> isize {
fn number_from_list (list: Vec<isize>) -> isize {
	let len_list: usize = list.len() as usize;
	let mut out: isize = 0;
	let base: isize = 10;
	
	for i in 0..(len_list as usize){
		out += (list[i] * exponented(base, (len_list as isize - i as isize - 1) as isize));
	}
	
	return out;
}

//fn number_to_list (number: isize, &mut out: &[isize]) -> () {
fn number_to_list_void (number: isize, mut out:&mut Vec<isize>) -> () {
	let len_list: usize = out.len();
	let base: isize = 10;
	let mut running_number: isize = number;
	let mut out_cursor: usize = len_list - 1;
	
	while ((running_number > 0) && (out_cursor >= 0)){
		let modulo: isize = running_number % base;
		running_number -= modulo;
		running_number /= base;
		out[out_cursor] = modulo;
		out_cursor -= 1;
	}
}


fn number_to_list (number: isize, len_list: isize) -> Vec<isize>{
	let mut out: Vec<isize> = vec![0; len_list as usize];
	let base: isize = 10;
	let mut running_number: isize = number;
	let mut out_cursor: usize = (len_list - 1) as usize;
	//println!("The number in the number to list is {} the length of out is {}", out_cursor, out.len());
	
	while ((running_number > 0) && (out_cursor >= 0)){
		let modulo: isize = running_number % base;
		running_number -= modulo;
		running_number /= base;
		out[out_cursor] = modulo;
		out_cursor = (out_cursor as isize - 1) as usize;
	}
	
	return out;
}
//ARRAY

fn list_comparison(list1: Vec<isize>, list2: Vec<isize>) -> bool {
	let len_list1: usize = list1.len();
	let len_list2: usize = list2.len();
	
	if (len_list1 != len_list2){
		return false;
	}
	
	let mut list1_bool_map: Vec<bool> = vec![false; len_list1];
	let mut list2_bool_map: Vec<bool> = vec![false; len_list2];
	
	for i in 0..len_list1{
		for j in 0..len_list2{
			if ((list1_bool_map[i] == false) && (list2_bool_map[j] == false)){
				if (list1[i] == list2[j]){
					list1_bool_map[i] = true;
					list2_bool_map[j] = true;
					break;
				}
			}
		}
	}
	
	let mut bool_counter: isize = 0;
	
	for i in 0..len_list1{
		if (list1_bool_map[i] && list2_bool_map[i]){
			bool_counter += 1;
		}
	}
	
	return len_list1 == bool_counter as usize;
}

fn appears (element: isize, list: Vec<isize>) -> isize {
	let mut out: isize = -1;
	
	for i in 0..list.len(){
		if element == list[i]{
			out += 1;
		}
	}
	
	return out;
}

fn main (){
	let mut nums: Vec<isize> = vec![1,2,3,4,3];
	let len_nums: isize = nums.len() as isize;
	
	nums.sort();
	let lowest_value_nums_number: isize = number_from_list(nums.clone());
	
	nums.reverse();
	let highest_value_nums_number: isize = number_from_list(nums.clone());
	
	println!("The lowest number from the elements is:\t{}", lowest_value_nums_number);
	println!("The highest number from the elements is:\t{}", highest_value_nums_number);
	
	let mut sample_size: isize = factorial(len_nums as isize);
	let mut unique: isize = 0;
	
	for i in 0..(len_nums as usize){
		let mut occ_code: bool = false;
		
		if i == 0{
			occ_code = true;
		} else {
			if (nums[i - 1] != nums[i]){
				occ_code = true;
			}
		}
		
		if (occ_code){
			let occurences: isize = appears(nums[i], nums.clone());
			
			if (occurences == 0){
				unique += 1;
			}
			
			if (occurences > 0){
				unique += 1;
				sample_size /= factorial(occurences + 1);
			}
		}
	}
	
	println!("This is the handy work of Rust");
	println!("The number of unique elements are:\t{}", unique);
	println!("The sample size of permutations expected is:\t{}", sample_size);
	
	let mut permutations: Vec<Vec<isize>> = vec![];
	let mut running_number: isize = lowest_value_nums_number;
	//let mut permutations_cursor: usize = 0;
	
	while (running_number <= highest_value_nums_number){
		let temp_list: Vec<isize> = number_to_list(running_number, len_nums);
		
		if list_comparison (temp_list.clone(), nums.clone()){
			permutations.push(temp_list.clone());
		}
		
		running_number += 1;
	}
	
	for i in 0..permutations.len(){
		println!("{:?}", permutations[i]);
	}
	
	//println!("The number of permutations is:\t{}", permutations.len());
}
