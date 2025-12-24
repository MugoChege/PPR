fn duplicates_shifting_remove (list: &mut [isize]) -> isize{
	let mut counter: isize = 0;
	let len_list: usize = list.len();
	
	list.sort();
	
	for i in (0..=(len_list - 1)).rev(){
		let element: isize = list[i];
		let mut unique: bool = true;
		
		for j in 0..i{
			if element == list[j]{
				unique = false;
				break;
			}
		}
		
		if unique == false{
			counter += 1;
			let holder: isize = list[i];
			
			for j in i..(len_list - 1){
				list[j] = list[j + 1];
			}
			
			list[len_list - 1] = holder;
		}
	}
	
	return (counter);
}

fn main () {
	let mut nums = [0,0,1,1,1,2,2,3,3,4];
	let len_nums: usize = nums.len();
	
	let rem: isize = duplicates_shifting_remove(&mut nums);
	
	println!("This is the handy work of Rust\n\n");
	
	println!("{}\n\n\n", rem);
	
	println!("{:?}\n\n\n", nums);
	
	
	print!("[");
	
	for i in 0..(len_nums - rem as usize){
		print!("{}", nums[i]);
		
		if (i == ((len_nums - rem as usize) - 1)){
			println!("]");
		} else {
			print!(", ");
		}
	}
	
}
