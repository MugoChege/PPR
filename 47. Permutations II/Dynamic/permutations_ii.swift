func exponented (base: Int, exponent: Int) -> Int{
	var out = 1;
	
	for _ in 0..<exponent{
		out *= base;
	}
	
	return out;
}

func number_from_list (list: Array<Int>) -> Int{
	var out: Int = 0;
	var len_list: Int = list.count;
	let base: Int = 10
	
	for i in 0..<len_list{
		out += (list[i] * exponented (base: base, exponent: (len_list - 1 - i)));
	}
	
	return out;
}

func number_to_list (number: Int, original_list_len: Int = 0) -> Array<Int> {
	var out: Array<Int> = [];
	let base: Int = 10;
	var running_number: Int = number;
	
	while running_number > 0{
		var modulo: Int = running_number % base;
		running_number -= modulo;
		running_number /= base;
		out.append(modulo);
	}
	
	if (original_list_len != 0){
		while (out.count < original_list_len){
			out.append(0);
		}
	}
	
	out.reverse();
	
	return out;
}

func list_comparison (list1: Array<Int>, list2: Array<Int>) -> Bool{
	let len_list1: Int = list1.count;
	let len_list2: Int = list2.count;
	
	if (len_list1 != len_list2){
		return false;
	}
	
	var list1_bool_map: Array<Bool> = [];
	var list2_bool_map: Array<Bool> = [];
	
	for i in 0..<len_list1{
		list1_bool_map.append(false);
		list2_bool_map.append(false);
	}
	
	for i in 0..<len_list1{
		for j in 0..<len_list2{
			if (list1_bool_map[i] == false) && (list2_bool_map[j] == false){
				if (list1[i] == list2[j]){
					list1_bool_map[i] = true;
					list2_bool_map[j] = true;
					break;
				}
			}
		}
	}
	
	var bool_counter: Int = 0;
	
	for i in 0..<len_list1{
		if list1_bool_map[i] && list2_bool_map[i]{
			bool_counter += 1;
		}
	}
	
	return (list1_bool_map.count == bool_counter);
}

func appears (element: Int, list: Array<Int>) -> Int{
	var out: Int = -1;
	
	for i in 0..<(list.count){
		if (element == list[i]){
			out += 1;
		}
	}
	
	return out;
}

var nums: Array<Int> = [1,2,3,3];
let len_nums: Int = nums.count;
nums.sort();
let lowest_value_nums_number = number_from_list(list: nums);
nums.reverse();
let highest_value_nums_number = number_from_list(list: nums);

print(lowest_value_nums_number);
print(highest_value_nums_number);

var permutations: Array<Array<Int>> = [];
var running_number: Int = lowest_value_nums_number;

while (running_number <= highest_value_nums_number){
	var temp_nums_list: Array<Int> = number_to_list(number: running_number, original_list_len: len_nums);
	if (list_comparison(list1: temp_nums_list, list2: nums)){
		permutations.append(temp_nums_list);
	}
	
	running_number += 1;
}

print (permutations);
