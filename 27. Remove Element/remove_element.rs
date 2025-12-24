fn remove_by_shifting (element: isize, list: &mut [isize]) -> isize{
	let mut count: isize = 0;
	let len_list: usize = list.len();
	
	for i in (0..len_list).rev(){
		if (list[i] == element){
			count += 1;
			let holder: isize = list[i];
			
			for j in i..(len_list - 1){
				list[j] = list[j + 1];
			}
			
			list[len_list - 1] = holder;
		}
	}
	
	return (count);
}

fn main (){
	let mut nums = [0,1,2,2,3,0,4,2];
	let len_nums: usize = nums.len();
	
	let vals: isize = 2;
	
	let rem: isize = remove_by_shifting(vals, &mut nums);
	
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
