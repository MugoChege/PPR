func get_target (nums: Array<Int>, target: Int) -> Array<Int>{
	var len_nums: Int = nums.count;
	var out: Array<Int> = [-1, -1];
	
	for i in 0..<len_nums{
		var exit_loop: Bool = false;
		for j in 0..<len_nums{
			if (i == j){
				continue;
			} else {
				if ((nums[i] + nums[j]) == target){
					out[0] = nums[i];
					out[1] = nums[j];
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

var number_list: Array<Int> = [1,2,3,4,5,6,7,8,9];
var target: Int = 16;
var indices: Array<Int> = [-1, -1];

indices = get_target(nums: number_list, target: target);

for i in 0..<indices.count{
	print(indices[i]);
}
