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

fn combine_list (list1: Vec<isize>, list2: Vec<isize>) -> Vec<isize>{
	let len_list1: usize = list1.len();
	let len_list2: usize = list2.len();
	let mut combined_list: Vec<isize> = vec![];
	
	for i in 0..len_list1{
		combined_list.push(list1[i]);
	}
	
	for i in 0..len_list2{
		combined_list.push(list2[i]);
	}
	
	combined_list.sort();
	
	return combined_list;
}

fn main (){
	let list1: Vec<isize> = vec![1,3];
	let list2: Vec<isize> = vec![2,4];
	let mut list_combined: Vec<isize> = combine_list(list1.clone(), list2.clone());
	
	let median: f64 = get_median(list_combined.clone());
	
	println!("This is the handy work of Rust\n\n{}\n\n\n", median);
}
