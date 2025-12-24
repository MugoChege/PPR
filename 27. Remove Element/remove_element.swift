func remove_by_shifting (element: Int, list: inout Array<Int>) -> Int {
	var count: Int = 0;
	var len_list: Int = list.count;
	
	for i in stride(from: (len_list - 1), to: 0, by: -1){
		if (list[i] == element){
			count += 1;
			let holder: Int = list[i];
			
			for j in i..<(len_list - 1){
				list[j] = list[j + 1];
			}
			
			list[len_list - 1] = holder;
		}
	}
	
	return (count);
}

var nums: Array<Int> = [0,1,2,2,3,0,4,2];
let len_nums: Int = nums.count;
let vals: Int = 2;

let rem = remove_by_shifting(element: vals, list: &nums);

print("This is the handy work of Swift\n\n\n");
print(rem);
print("\n\n\n");

print(nums);
print(nums[0..<(len_nums - rem)]);
