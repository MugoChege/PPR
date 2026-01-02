fn get_median (list: Vec<isize>) -> f64 {
	let len_list: usize = list.len();
	let even_length: bool = (len_list % 2 == 0);
	let mut median: f64 = 0.0;
	
	if even_length{
		median = (list[len_list / 2] as f64 + list[(len_list / 2) - 1] as f64) / 2.0;
	} else {
		median = list[len_list / 2] as f64;
	}
	
	return median;
}

//fn combine_list (list1: Vec<isize>, list2: Vec<isize>) -> Vec<isize>{
fn combine_list (list1_original: &[isize], list2_original: &[isize]) -> Vec<isize>{
	let mut list1: Vec<isize> = Vec::from(list1_original);
	let mut list2: Vec<isize> = Vec::from(list2_original);
	
	list1.sort();
	list2.sort();
	
	let mut nje: Vec<isize> = vec![];
	
	let len_list1: usize = list1.len();
	let len_list2: usize = list2.len();
	
	let mut list1_cursor: usize = 0;
	let mut list2_cursor: usize = 0;
	
	while ((list1_cursor < len_list1) || (list2_cursor < len_list2)){
		let mut element_list1: Option<isize> = None;
		let mut element_list2: Option<isize> = None;
		let mut appending_element: Option<isize> = None;
		
		if (list1_cursor < len_list1){
			element_list1 = Some(list1[list1_cursor]);
		}
		
		if (list2_cursor < len_list2){
			element_list2 = Some(list2[list2_cursor]);
		}
		
		if (element_list1 != None && element_list2 != None){
			if (element_list1 < element_list2){
				appending_element = element_list1;
				list1_cursor += 1;
			} else {
				appending_element = element_list2;
				list2_cursor += 1;
			}
		} else if (element_list1 == None){
			appending_element = element_list2;
			list2_cursor += 1;
		} else if (element_list2 == None){
			appending_element = element_list1;
			list1_cursor += 1;
		}
		
		nje.push (appending_element.unwrap());
	}
	
	return (nje);
}

fn main (){
	let list1 = [1,3];
	let list2 = [2,4];
	let mut list_combined: Vec<isize> = combine_list(&list1, &list2);
	
	let median: f64 = get_median(list_combined.clone());
	
	println!("This is the handy work of Rust\n\n{}\n\n\n", median);
}
