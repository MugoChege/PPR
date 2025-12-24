let number_of_elements = 3;
//var result_number = 0;

class Result{
	var values: Array<Int> = [];
	var number_of_values: Int = 0;
	var not_null: Bool = false;
	
	func set_values (list: Array<Int>) -> Void{
		self.not_null = true;
		self.number_of_values = list.count;
		self.values = [];
		
		for i in 0..<list.count{
			self.values.append(list[i]);
		}
	}
	
	func empty_values() -> Void{
		self.not_null = false;
		self.number_of_values = 0;
		
		for i in 0..<number_of_elements{
			self.values[i] = 0;
		}
	}
	
	init (list: Array<Int>){
		self.set_values (list: list);
	}
	
	convenience init (){
		//empty_values();
		//self.init(Array(repeating: 0, count:number_of_elements);
		self.init(list: []);
	}
	
	func print_values (){
		print("This is the handy work of Swift");
		var out: Int = 0;
		
		for i in 0..<self.number_of_values{
			print("\(self.values[i])", terminator: "");
			out += self.values[i];
			
			if i < (self.number_of_values - 1){
				print("\t", terminator: "");
			}
		}
		
		print("\nThe sum of the values iis:\t\(out)");
	}
}

func factorial (number: Int) -> Int{
	var out: Int = 1;
	
	for i in stride(from:number, to: 1, by: -1){
		out *= i;
	}
	
	return out;
}

func absolute (number: Int) -> Int{
	return (number < 0) ? (number * -1) : (number * 1);
}

func sum_of_three_closest (list: Array<Int>, target: Int) -> Array<Result> {
	//var result_cursor: Int = 0;
	var closest_difference: Int = 0;
	var first_execution: Bool = true;
	var out: Array<Result> = [];
	let len_list: Int = list.count;
	
	for a in 0..<len_list{
		for b in 0..<len_list{
			if b > a{
				for c in 0..<len_list{
					if c > b{
						if (a != b) && (a != c) && (b != c){
							let aa: Int = list[a];
							let bb: Int = list[b];
							let cc: Int = list[c];
							
							//if (aa != bb) && (aa != cc) && (bb != cc){
							if (true){
								let difference: Int = absolute(number: ((aa + bb + cc) - target));
								var update_array: Bool = false;
								
								if (first_execution){
									closest_difference = difference;
									first_execution = false;
									
									update_array = true;
								} else {
									if (difference < closest_difference){
										closest_difference = difference;
										
										//out.removeAll();
										out = [];
										
										update_array = true;
									} else if (difference == closest_difference){
										update_array = true;
									}
								}
								
								if update_array{
									let y: Array<Int> = [aa, bb, cc];
									
									out.append(Result(list: y));
								}
							}
						}
					}
				}
			}
		}
	}
	
	return (out);
}


let nums: Array<Int> = [-1,2,1,-4];
let len_nums: Int = nums.count;
let target: Int = 1;

let sample_space: Int = (factorial(number: len_nums) / (factorial(number: (len_nums - number_of_elements)) * factorial(number: number_of_elements)));

var h: Array<Result> = sum_of_three_closest(list: nums, target: target);


for i in 0..<h.count{
	h[i].print_values();
}
