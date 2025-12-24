const number_of_elements: usize = 3;

#[derive(Clone, Copy)]
struct Result {
	values: [isize; number_of_elements],
	number_of_values: usize,
	not_null: bool
}

impl Result{
	
	fn new(list: &[isize]) -> Self{
		let mut arr: [isize; number_of_elements] = [0;number_of_elements];
		let count = list.len();
		
		for i in 0..count{
			arr[i as usize] = list[i as usize];
		}
		
		return Result{values: arr, number_of_values: count, not_null: true};
	}
	
	fn empty() -> Self{
		let arr: [isize; number_of_elements] = [0; number_of_elements];
		return Result{values: arr, number_of_values: number_of_elements, not_null: false};
	}
	
	fn set_result(&mut self, list: &[isize], count: usize) -> (){
		for i in 0..count{
			self.values[i as usize] = list[i as usize];
		}
	}
	
	fn print_result(self){
		for i in 0..self.number_of_values{
			print!("{}", self.values[i as usize]);
			if i < (self.number_of_values - 1){
				print!("\t");
			}
		}
		println!();
	}
}

fn sum_of_three (list: &[isize], target: isize) -> Vec<Result> {
	let len_list: usize = list.len() as usize;
	let mut out: Vec<Result> = vec![];
	
	for a in 0..len_list{
		for b in a..len_list{
			if b > a{
				for c in a..len_list{
					if c > b{
						if (a != b) && (a != c) && (b != c){
							let aa = list[a];
							let bb = list[b];
							let cc = list[c];
							
							if (aa != bb) && (aa != cc) && (bb != cc){
								if (aa + bb + cc) == target{
									let r: Result = Result::new(&[aa, bb, cc]);
									
									out.push(r);
								}
							}
						}
					}
				}
			}
		}
	}
	
	return out;
}

fn main (){
	let nums: &[isize] = &[-1,0,1,2,-1,-4];
	
	let len_nums: usize = nums.len() as usize;
	
	let res: Vec<Result> = sum_of_three(nums, 0);

	println!("This is the handy work of Rust");
	
	for i in 0..res.len(){
		res[i as usize].print_result();
	}
}
