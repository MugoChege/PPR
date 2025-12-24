struct HeightPoint{
	heightPoint1: isize,
	heightPoint2: isize,
}

fn absolute (number: isize) -> isize{
	return (if (number < 0)  {(number * -1)} else {(number * 1)});
}

fn get_volume (height1: isize, height2: isize, width: isize) -> isize{
	let height = if (height1 < height2) {(height1)} else {(height2)};
	
	return (height * width);
}

fn container_points(list: &[isize]) -> HeightPoint{
	let len_list: isize = list.len() as isize;
	let mut out: HeightPoint = HeightPoint{heightPoint1: 0, heightPoint2: 0};
	let mut largest_volume: isize = 0;
	
	for a in 0..len_list{
		for b in (0..(len_list)).rev(){
			if a == b{
				continue;
			} else if b < a{
				break;
			} else {
				let interval: isize = absolute((a - b) as isize);
				let volume: isize = get_volume (list[a as usize], list[b as usize], interval);
				//println!("{}\t{}\t{}\t{}\t{}\t{}", a, b, list[a as usize], list[b as usize], interval, volume);
				
				if largest_volume < volume{
					largest_volume = volume;
					
					out.heightPoint1 = a;
					out.heightPoint2 = b;
				}
			}
		}
	}
	return out;
}

fn main (){
	let height_list: &[isize] = &[1,8,6,2,5,4,8,3,7];
	let len_height_list: isize = height_list.len() as isize;
	
	let height_indices: HeightPoint = container_points(height_list);
	
	let height1: isize = height_list[height_indices.heightPoint1 as usize];
	let height2: isize = height_list[height_indices.heightPoint2 as usize];
	
	let interval: isize = absolute(height_indices.heightPoint1 - height_indices.heightPoint2);
	
	println!("This is the handy work of Rust\n\n");
	
	println!("[{}, {}]", height_indices.heightPoint1, height_indices.heightPoint2);
	
	println!("The heights given the points are: {} on one end and {} on the other end. The difference between the two points is {} giving a total volume of {}\n\n\n", height1, height2, interval, get_volume(height1, height2, interval));
}
