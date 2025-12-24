static mut result_number: isize = 0;
const number_of_elements: usize = 3;
const sample_size: usize = 10; 

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
		println!("This is the handy work of Rust");
		for i in 0..self.number_of_values{
			print!("{}", self.values[i as usize]);
			if i < (self.number_of_values - 1){
				print!("\t");
			}
		}
		println!();
	}
}

fn factorial (number: isize) -> isize{
	let mut out: isize = 1;
	
	for i in (1..=number).rev(){
		out *= i;
	}
	
	return out;
}

fn sum_of_three (list: &[isize], target: isize, out: &mut[Result]) -> (){
	let mut result_pointer: isize = 0;
	let len_list: usize = list.len() as usize;
	
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
									out[result_pointer as usize] = Result::new(&[aa, bb, cc]);
									result_pointer += 1;
									unsafe {
										result_number = result_pointer;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

fn main() {
	//println!("{}\n\n\n", factorial(5));
	
	//let e: Result = Result{values: [2,3,4], number_of_values: 3, not_null: true};
	//let e: Result = Result::new(&[2,3,4]);
	//e.print_result();
	
	let nums: &[isize] = &[-1,0,1,2,-1,-4];
	
	let len_nums: usize = nums.len() as usize;
	
	let sample_space: isize = (factorial(len_nums as isize) / (factorial((len_nums - number_of_elements) as isize) * factorial(number_of_elements as isize)));
	
	if (sample_size < sample_space as usize){
		println!("The sample size of all combinations based of the size of the given array is less than the size allocated to handle the results of the program.\nKindly, within the program code file edit the sample size constant\n\"const sample_size: usize = {};\"\nto\n\"const sample_size: usize = {};\"\nPreferably a value that is greater than {}.\n", sample_size, sample_space, sample_space); 	
	} else {
		let def_Result: Result = Result::empty();
		
		let mut h: [Result; sample_size] = [def_Result; sample_size];
		
		sum_of_three(nums, 0, &mut h);
		
		let mut rn: isize;
		
		unsafe{
			rn = result_number;
		}
		
		for i in 0..rn{
			h[i as usize].print_result();
		}
	}
}
