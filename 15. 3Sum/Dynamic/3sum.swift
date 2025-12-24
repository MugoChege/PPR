//var result_number: Int = 0;
let number_of_elements: Int = 3;
//let sample_size: Int = 20;

struct Result {
	var values: Array<Int>
	var number_of_values: Int
	var not_null: Bool
	
	mutating func set_values(list: Array<Int>) -> Void{
		var len_list: Int = list.count;
		number_of_values = len_list;
		not_null = true;
		
		for i in 0..<len_list{
			//values.append(list[i])
			values[i] = list[i];
		}
	}
	
	func print_results() -> Void{
		print ("This is the handy work of Swift");
		for i in 0..<number_of_values{
			print("\(values[i])", terminator: "\t");
			if i < (number_of_values - 1){
				print(terminator: "\t");
			}
		}
		print();
	}
}

func factorial (number: Int) -> Int {
	var out = 1;
	
	for i in stride(from: number, to: 1, by: -1){
		out *= i;
	}
	
	return out;
}

func sum_of_three (list: Array<Int>, target: Int) -> Array<Result>{
	//var result_pointer: Int = 0;
	let len_list: Int = list.count;
	var out: Array<Result> = [];
	for a in 0..<len_list{
		for b in 0..<len_list{
			if a > b{
				for c in 0..<len_list{
					if b > c{
						if (a != b) && (a != c) && (b != c){
							var aa = list[a];
							var bb = list[b];
							var cc = list[c];
							
							if (aa != bb) && (aa != cc) && (bb != cc){
								if (aa + bb + cc) == target{
									var y: Array<Int> = [aa, bb, cc];
									//let r: Result = 
									out.append(Result(values: y, number_of_values: y.count, not_null: true));
									//result_pointer += 1;
									//result_number = result_pointer;
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

let nums: Array<Int> = [-1,0,1,2,-1,-4];
let len_nums: Int = nums.count;

let sample_space = (factorial(number: len_nums) / (factorial(number: (len_nums - number_of_elements)) * factorial(number: number_of_elements)));

var h: Array<Result> = sum_of_three(list: nums, target: 0);

for i in 0..<h.count{
	h[i].print_results();
}

