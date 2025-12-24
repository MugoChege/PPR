let number_of_elements: Int = 4;
class Result{
	var values: Array<Int>;
	//var values: Int;
	var number_of_elements: Int;
	var not_null: Bool;
	
	func set_values(list: Array<Int>) -> Void{
		//self.not_null = true;
		//self.number_of_elements = list.count;
		//self.values = [];
		
		for i in 0..<list.count{
			self.values.append(list[i]);
		}
	}
	
	init (list: Array<Int>){
		self.not_null = true;
		self.number_of_elements = list.count;
		self.values = [];
		self.set_values(list: list);
	}
	
	public func print_values() -> Void{
		for i in 0..<self.number_of_elements{
			print("\(self.values[i])", terminator: "");
			
			if i < (self.number_of_elements - 1){
				print("\t", terminator: "");
			}
		}
		
		print();
	}
	
	init (){
		self.not_null = false;
		self.number_of_elements = 0;
		self.values = [];
		//self.set_values(list: list);
	}
	


}

func not_equal_list(list: Array<Int>) -> Bool{
	var nje: Bool = true;
	let len_list: Int = list.count;
	
	for i in 0..<len_list{
		for j in i..<len_list{
			if i != j{
				if list[i] == list[j]{
					nje = false;
				}
			}
		}
	}
	
	return nje;
}

func factorial(number: Int) -> Int{
	var nje: Int = 1;
	
	for i in stride(from: number, to: 1, by: -1){
		nje *= i;
	}
	
	return nje;
}

func sum_of_four (list: Array<Int>, target: Int) -> Array<Result>{
	let len_list: Int = list.count;
	var nje: Array<Result> = [];
	
	for a in 0..<len_list{
		for b in 0..<len_list{
			if b > a{
				for c in 0..<len_list{
					if c > b{
						for d in 0..<len_list{
							if d > c{
								if not_equal_list(list: [a, b, c, d]){
									let aa: Int = list[a];
									let bb: Int = list[b];
									let cc: Int = list[c];
									let dd: Int = list[d];
									
									//if not_equal_list([aa, bb, cc, dd]){
									if true{
										if (aa + bb + cc + dd) == target{
											let z: Array<Int> = [aa, bb, cc, dd];
											nje.append(Result(list: z));
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
	
	return nje;
}

let nums: Array<Int> = [1,0,-1,0,-2,2];
let len_nums: Int = nums.count;
let target: Int = 0;

let sample_space: Int = (factorial(number: len_nums) / (factorial(number: (len_nums - number_of_elements)) * factorial(number: number_of_elements)));

let h: Array<Result> = sum_of_four(list: nums, target: target);

print("This is the handy work of Swift");

for i in 0..<h.count{
	h[i].print_values();
}

print();
