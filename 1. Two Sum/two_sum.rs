fn get_target (nums: &[isize], target: isize, indices: &mut [isize]){
	let len_nums: usize = nums.len();
	//let mut out : [isize; 2] = indices;
	
	for i in 0..len_nums{
		let mut exit_loop: bool = false;
		
		for j in 0..len_nums{
			if i == j{
				continue;
			} else {
				if (nums[i] + nums[j]) == target{
					//out [0] = nums[i];
					//out [1] = nums[j];
					
					indices[0] = nums[i];
					indices[1] = nums[j];
					
					exit_loop = true;
					break;
				}
			}
		}
		
		if exit_loop{
			break;
		}
	}
	
	//return &out;
}

fn main (){
	let number_list: [isize; 9] = [1,2,3,4,5,6,7,8,9];
	let target: isize = 16;
	let mut indices: [isize; 2] = [-1, -1];
	
	//indices = get_target(&number_list, target);
	get_target(&number_list, target, &mut indices);
	
	
	println!("{}\t\t\t{}\n\n\n", indices[0], indices[1]);
	//for u in 0..indices.len(){
	//	println!(indices[u]);
	//}
	
}
