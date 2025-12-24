fun exponented (base: Int, exponent: Int): Int{
	var out: Int = 1;
	
	for (i in 0 until exponent){
		out *= base;
	}
	
	return (out);
}

fun number_from_list (list: Array<Int>): Int{
	var out: Int = 0;
	val len_list: Int = list.size;
	val base: Int = 10;
	
	for (i in 0 until len_list){
		out += (list[i] * exponented (base, (len_list - 1 - i)));
	}
	
	return (out);
}

fun number_to_list(number: Int, len_list: Int): Array<Int>{
	val base: Int = 10;
	var running_number: Int = number;
	var out: Array<Int> = Array (len_list) {0};
	var out_cursor = len_list - 1;
	
	while ((running_number > 0) && (out_cursor >= 0)){
		var modulo = running_number % base;
		running_number -= modulo;
		running_number /= base;
		out[out_cursor] = modulo;
		out_cursor -= 1;
	}
	
	return (out);
}

fun list_comparison (list1: Array<Int>, list2: Array<Int>): Boolean{
	val len_list1: Int = list1.size;
	val len_list2: Int = list2.size;
	
	if (len_list1 != len_list2){
		return (false);
	}
	
	var list1_bool_map: Array<Boolean> = Array(len_list1) {false};
	var list2_bool_map: Array<Boolean> = Array(len_list2) {false};
	
	for (i in 0 until len_list1){
		for (j in 0 until len_list2){
			if ((list1_bool_map[i] == false) && (list2_bool_map[j] == false)){
				if (list1[i] == list2[j]){
					list1_bool_map[i] = true;
					list2_bool_map[j] = true;
					break;
				}
			}
		}
	}
	
	var bool_counter: Int = 0;
	
	for (i in 0 until len_list1){
		if (list1_bool_map[i] && list2_bool_map[i]){
			bool_counter += 1;
		}
	}
	
	return (len_list1 == bool_counter);
}

fun main (){
	val nums: Array<Int> = arrayOf(1,2,3,4,3);
	val len_nums: Int = nums.size;
	
	val nums_number = number_from_list(nums);
	nums.sort();
	nums.reverse();
	val highest_value_nums_number = number_from_list(nums);
	
	print("The value of the number from the elements is:\t");
	println(nums_number);
	print("The highest number from the elements is:\t");
	println(highest_value_nums_number);
	
	var next_permutation: Array<Int> = Array(len_nums) {0};
	var running_number: Int = nums_number;
	
	while (running_number <= highest_value_nums_number){
		var temp_list: Array<Int> = number_to_list(running_number, len_nums);
		
		if (list_comparison(temp_list, nums) && (running_number != nums_number)){
			for (i in 0 until len_nums){
				next_permutation[i] = temp_list[i];
			}
			
			break;
		}
		running_number += 1;
	}
	
	for (i in 0 until len_nums){
		print(next_permutation[i]);
		
		if (i != (len_nums - 1)){
			print("\t");
		}
	}
	
	println();
}
