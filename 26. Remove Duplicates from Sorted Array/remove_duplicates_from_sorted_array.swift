func duplicates_shifting_remove (list: inout Array<Int>) -> Int{
	var counter: Int  = 0;
	let len_list: Int = list.count;
	
	list.sort();
	
	for i in stride(from: (len_list - 1), to: 0, by: -1){
		let element: Int = list[i];
		var unique: Bool = true;
		
		for j in 0..<i{
			if (element == list[j]){
				unique = false;
				break;
			}
		}
		
		if unique == false{
			counter += 1;
			var holder = list[i];
			
			for j in i..<(len_list - 1){
				list[j] = list[j + 1];
			}
			
			list[len_list - 1] = holder;
		}
	}
	
	return (counter);
}

var nums: Array<Int> = [0,0,1,1,1,2,2,3,3,4];
var len_nums: Int = nums.count;

let rem = duplicates_shifting_remove(list: &nums);

print("This is the handy work of Swift\n\n\n");
print(rem);
print("\n\n\n");

print(nums);
print(nums[0..<(len_nums - rem)]);
