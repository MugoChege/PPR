fun get_target (nums: Array<Int>, target: Int): Array<Int?>{
	var len_nums: Int = nums.size;
	var out: Array<Int?> = arrayOf(null, null);
	for (i in 0..(len_nums - 1)){
		var exit_loop: Boolean = false;
		for (j in 0..(len_nums - 1)){
			if (i == j){
				continue;
			} else {
				if ((nums[i] + nums[j]) == target){
					out[0] = nums[i]; //?: null
					out[1] = nums[j]; //?: null
					exit_loop = true;
				}
			}
		}
		
		if (exit_loop){
			break;
		}
	}

	return (out);
}

fun main () {
	var number_list: Array<Int> = arrayOf(1,2,3,4,5,6,7,8,9);
	var target: Int = 16;
	
	var indices: Array<Int?> = get_target (number_list, target);
	
	for (i in indices){
		println (i);
	}
	
}
