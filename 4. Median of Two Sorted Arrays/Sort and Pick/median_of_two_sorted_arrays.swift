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

func combine_list (_ list1Original: Array<Int>, _ list2Original: Array<Int>) -> Array<Int>{
	var list1: Array<Int> = list1Original;
	var list2: Array<Int> = list2Original;
	
	list1.sort();
	list2.sort();
	
	let len_list1: Int = list1.count;
	let len_list2: Int = list2.count;
	
	var list1_cursor: Int = 0;
	var list2_cursor: Int = 0;
	
	var nje: Array<Int> = [];
	
	while ((list1_cursor < len_list1) || (list2_cursor < len_list2)){
		var element_list1: Int? = nil;
		var element_list2: Int? = nil;
		var appending_element: Int? = nil;
		
		if (list1_cursor < len_list1){
			element_list1 = list1[list1_cursor];
		}
		
		if (list2_cursor < len_list2){
			element_list2 = list2[list2_cursor];
		}
		
		if ((element_list1 != nil) && (element_list2 != nil)){
			if (element_list1! < element_list2!){
				appending_element = element_list1!;
				list1_cursor += 1;
			} else {
				appending_element = element_list2!;
				list2_cursor += 1;
			}
		} else if (element_list1 == nil){
			appending_element = element_list2!;
			list2_cursor += 1;
		} else if (element_list2 == nil){
			appending_element = element_list1!;
			list1_cursor += 1;
		}
		
		nje.append(appending_element!);
	}
	
	return (nje);
}

let list1: Array<Int> = [1,3];
let list2: Array<Int> = [2,4];

let list_combined: Array<Int> = combine_list (list1, list2);

let median: Float = get_median(list: list_combined);

print("This is the work of Swift.\n\n\n");
print (median);

print ("\n\n\n");
