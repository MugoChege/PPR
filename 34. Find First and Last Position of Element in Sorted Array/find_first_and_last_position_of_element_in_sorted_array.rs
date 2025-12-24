fn first_and_last (element: isize, list: &mut [isize], out: &mut [isize]) -> (){
	let mut find_first: bool = true;
	let len_list: usize = list.len();
	
	list.sort();
	
	for i in 0..len_list{
		if (element == list[i]){
			if (find_first){
				out[0] = i as isize;
				out[1] = i as isize;
				find_first = false;
			} else {
				out[1] = i as isize;
			}
		}
	}
}

fn main () {
	let mut nums = [5,7,7,8,8,10];
	let target: isize = 8;
	let mut positions: [isize; 2] = [-1, -1];
	
	first_and_last (target, &mut nums, &mut positions);
	
	println!("\n\nThis is the handy work of Rust\n\n");
	println!("{:?}\n\n\n", positions);
}
