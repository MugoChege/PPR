const number_of_elements: usize = 3;

#[derive(Copy, Clone)]
struct Result{
	values: [isize; number_of_elements],
	number_of_values: isize,
	not_null: bool
}

impl Result{
	fn new(list: &[isize]) -> Self{
		let len_list = list.len() as isize;
		let mut arr: [isize; number_of_elements] = [0; number_of_elements];
		
		for i in 0..len_list{
			arr[i as usize] = list[i as usize];
		}
		
		return Result{values: arr, number_of_values: len_list, not_null: true};
	}
	
	fn empty() -> Self{
		return Result{values: [0; number_of_elements], number_of_values: number_of_elements as isize, not_null: false};
	}
	
	fn set_values (&mut self, list: &[isize]){
		self.not_null = true;
		self.number_of_values = list.len() as isize;
		
		for i in 0..self.number_of_values{
			self.values[i as usize] = list[i as usize];
		}
	}
	
	fn print_values (self) -> (){
		println!("This is the handy work of Rust");
		
		let mut out: isize = 0;
		
		for i in 0..self.number_of_values{
			print!("{}", self.values[i as usize]);
			out += self.values[i as usize];
			
			if i < (self.number_of_values - 1){
				print!("\t");
			}
		}
		println!("\nThe sum of the values is {}\n\n", out);
	}
	
	fn empty_result (&mut self) -> (){
		self.not_null = false;
		
		for i in 0..self.number_of_values{
			self.values[i as usize] = 0;
		}
		
		self.number_of_values = 0;
	}
}

fn absolute (number: isize) -> isize{
	return if (number < 0) {(number * -1)} else {(number * 1)};
}

fn sum_of_three_closest (list: &[isize], target: isize) -> Vec<Result>{
//fn sum_of_three_closest (list: &[isize], target: isize) -> Result{
	let mut closest_difference: isize = 0;
	let mut first_execution: bool = true;
	let len_list: usize = list.len();
	let mut out: Vec<Result> = vec![];
	//let mut out: Result;
	
	for a in 0..len_list{
		for b in 0..len_list{
			if b > a{
				for c in 0..len_list{
					if c > b{
						if (a != b) && (a != c) && (b != c){
							let aa = list[a];
							let bb = list[b];
							let cc = list[c];
							
							//if (aa != bb) && (aa != cc) && (bb != cc){
							
							if true{	
								let difference: isize = absolute((aa + bb + cc) - target);
								let mut update_array: bool = false;
								
								if first_execution{
									closest_difference = difference;
									first_execution = false;
									update_array = true;
								} else {
									if (difference < closest_difference){
										closest_difference = difference;
										/*
										//This is the one that returns the first combination
										out = Result::empty();	
										*/
									
									//BEGIN if commenting out for the first occurrence outcome
										out = vec![];
										update_array = true;
									} else if (difference == closest_difference){
										update_array = true;
									//END if commenting out for the first occurrence outcome
									}
								}
								
								if update_array{
									let y: [isize; number_of_elements] = [aa, bb, cc];
									
									let res: Result = Result::new(&y);
									
									out.push(res);
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
	let nums: &[isize] = &[-1,2,1,-4];
	let len_nums: usize = nums.len() as usize;
	
	let res: Vec<Result> = sum_of_three_closest(nums, 1);
	
	for i in 0..res.len(){
		res[i].print_values();
	}
}
