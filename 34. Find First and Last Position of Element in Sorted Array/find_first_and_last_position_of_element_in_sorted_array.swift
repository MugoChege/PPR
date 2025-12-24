func first_and_last (element: Int, list: inout Array<Int>) -> Array<Int>{
	var find_first: Bool = true;
	var out: Array<Int> = [-1, -1];
	let len_list: Int = list.count;
	list.sort();
	
	for i in 0..<len_list{
		if (element == list[i]){
			if (find_first){
				out[0] = i;
				out[1] = i;
				find_first = false;
			} else {
				out[1] = i;
			}
		}
	}
	
	return (out);
}

var nums: Array<Int> = [5,7,7,8,8,10];
let target: Int = 8;

let positions: Array<Int> = first_and_last(element: target, list: &nums);

print("\n\nThis is the handy work of Swift\n\n\n");
print(nums);

print("\n\n\n\n");
print(positions);
print("\n\n\n\n");
