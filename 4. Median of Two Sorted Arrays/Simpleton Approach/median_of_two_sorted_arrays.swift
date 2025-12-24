func get_median(list: Array<Int>) -> Float{
	let len_list: Int = list.count;
	let even_length: Bool = (len_list % 2 == 0);
	var median: Float = 0.0;
	
	if (even_length){
		median = (Float(list[len_list / 2]) + Float(list[(len_list / 2) - 1])) / 2;
		//median = ((Float)list[len_list / 2] + (Float)list[(len_list / 2) - 1]) / 2;
	} else {
		median = (Float(list[len_list / 2]));
		//median = (Float)list[len_list / 2];
	}
	
	return (median);
}

func combine_list (list1: Array<Int>, list2: Array<Int>) -> Array<Int>{
	var combined_list: Array<Int> = [];
	
	for i in list1{
		combined_list.append(i);
	}
	
	for i in list2{
		combined_list.append(i);
	}
	
	combined_list.sort();
	
	return (combined_list);
}

let list1: Array<Int> = [1,3,5];
let list2: Array<Int> = [2,4];

let list_combined: Array<Int> = combine_list (list1: list1, list2: list2);

let median: Float = get_median(list: list_combined);

print("This is the work of Swift");
print (median);

print ("\n\n\n");
