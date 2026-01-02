fun get_median (list: Array<Int>): Float{
	val len_list: Int = list.size;
	val even_length: Boolean = (len_list % 2 == 0);
	var median: Float = 0.0f;
	
	if (even_length){
		median = ((list[len_list / 2].toFloat() + list[(len_list / 2) - 1].toFloat()) / 2);
	} else {
		median = (list[len_list / 2]).toFloat();
	}
	
	return (median);
}

fun combine_list (list1_original: Array<Int>, list2_original: Array<Int>) : Array<Int>{
	var list1: Array<Int> = list1_original;
	var list2: Array<Int> = list2_original;
	
	list1.sort();
	list2.sort();
	
	val len_list1: Int = list1.size;
	val len_list2: Int = list2.size;
	
	var nje: Array<Int> = Array<Int>(len_list1 + len_list2){0};
	
	var nje_cursor: Int = 0;
	var list1_cursor: Int = 0;
	var list2_cursor: Int = 0;
	
	while ((list1_cursor < len_list1) || (list2_cursor < len_list2)){
		var element_list1: Int? = null;
		var element_list2: Int? = null;
		var appending_element: Int? = null;
		
		if (list1_cursor < len_list1){
			element_list1 = list1[list1_cursor];
		}
		
		if (list2_cursor < len_list2){
			element_list2 = list2[list2_cursor];
		}
		
		if ((element_list1 != null) && (element_list2 != null)){
			if (element_list1 < element_list2){
				appending_element = element_list1;
				list1_cursor += 1;
			} else {
				appending_element = element_list2;
				list2_cursor += 1;
			}
		} else if (element_list1 == null){
			appending_element = element_list2;
			list2_cursor += 1;
		} else if (element_list2 == null){
			appending_element = element_list1;
			list1_cursor += 1;
		}
		
		nje[nje_cursor] = appending_element!!;
		nje_cursor += 1;
	}
	
	return (nje);
}

fun main (){
	val list1: Array<Int> = arrayOf(1,3);
	val list2: Array<Int> = arrayOf(2,4);
	
	var list_combined = combine_list(list1, list2);
	
	var median = get_median(list_combined);
	
	println("This is the handy work of Kotlin.\n\n\n");
	println(median);
	println("\n\n\n");
}
