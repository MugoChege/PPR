const number_of_elements: usize = 4;
static mut result_number: usize = 0;
const sample_size: usize = 15;

#[derive(Copy, Clone)]
struct Result {
	values: [isize; number_of_elements],
	no_of_values: usize,
	not_null: bool,
}

impl Result {
	fn new (list: &[isize]) -> Self{
		let len_list: usize = list.len() as usize;
		let mut arr: [isize; number_of_elements] = [0; number_of_elements];
		
		for i in 0..len_list{
			arr[i] = list[i];
		}
		
		return Result{values: arr, no_of_values: len_list, not_null: true};
	}
	
	fn empty () -> Self{
		let arr: [isize; number_of_elements] = [0; number_of_elements];
		
		return Result{values: arr, no_of_values: 0, not_null: false};
	}
	
	fn print_results(&self) -> (){
		for i in 0..self.no_of_values{
			print!("{}", self.values[i]);
			if i < (self.no_of_values - 1){
				print!("\t");
			}
		}
		print!("\n");
	}
}

fn not_equal_list (list: &[isize]) -> bool{
	let mut out: bool = true;
	let len_list: usize = list.len() as usize;
	for i in 0..len_list{
		for j in i..len_list{
			if i != j{
				if list[i] == list[j]{
					out = false;
				}
			}
		}
	}
	return out;
}

fn factorial (number: isize) -> isize{
	let mut out: isize = 1;
	
	for i in (1..=number).rev(){
		out *= i;
	}
	
	return out;
}

fn sum_of_four(list: &[isize], target: isize, out: &mut[Result]){
	let mut result_cursor: usize = 0;
	let len_list: usize = list.len();
	
	for a in 0..len_list{
		for b in 0..len_list{
			if b > a{
				for c in 0..len_list{
					if c > b{
						for d in 0..len_list{
							if d > c{
								if (not_equal_list(&[a as isize, b as isize, c as isize, d as isize])){
									let aa: isize = list[a];
									let bb: isize = list[b];
									let cc: isize = list[c];
									let dd: isize = list[d];
									
									//if (not_equal_list(&[aa, bb, cc, dd]);
									if true{
										if (aa + bb + cc + dd) == target{
											out[result_cursor] = Result::new(&[aa, bb, cc, dd]);
											result_cursor += 1;
											unsafe{
												result_number = result_cursor;
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
	}
}

fn main (){
	let nums: &[isize] = &[1,0,-1,0,-2,2];
	let len_nums: isize = nums.len() as isize;
	let target = 0;
	
	let sample_space: isize = (factorial(len_nums) / (factorial(len_nums - number_of_elements as isize) * factorial(number_of_elements as isize)));
	
	if (sample_size < sample_space as usize){
		println!("The sample size of all combinations based of the size of the given array is less than the size allocated to handle the results of the program.\nKindly, within the program code file edit the sample size constant\n\"const sample_size: usize = {};\"\nto\n\"const sample_size: usize = {};\"\nPreferably a value that is greater than {}.\n", sample_size, sample_space, sample_space); 
	} else {
		let mut h: [Result; sample_size] = [Result::empty(); sample_size];
		
		sum_of_four(nums, target, &mut h);
		
		println!("The handy work of Rust:\n\n");
		
		let mut rn: isize;
		
		unsafe{
			rn = result_number as isize;
		}
		
		for i in 0..rn{
			h[i as usize].print_results();
		}
	}
	println!("\n\n");
}
