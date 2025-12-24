fn zigzag (text: String,rows: usize) -> Vec<String>{
	let mut out: Vec<String> = vec![];
	
	for i in 0..rows{
		out.push(String::new());
	}
	
	let len_text: usize = text.len() as usize;
	let mut straight: bool = true;
	let mut text_cursor: usize = 0;
	
	while (text_cursor < len_text){
		if straight{
			for row_cursor in 0..rows{
				if text_cursor < len_text{
					out[row_cursor].push(text.chars().nth(text_cursor).unwrap());
					//out[row_cursor].push_str(text[text_cursor..(text_cursor + 1)]);
					text_cursor += 1;
				} else {
					break;
				}
			}
			straight = false
		} else {
			for term in 0..(rows - 2){
				for row_cursor in 0..rows{
					if text_cursor < len_text{
						if (row_cursor == (rows - 2 - term)){
							out[row_cursor].push(text.chars().nth(text_cursor).unwrap());
							//out[row_cursor].push_str(text[text_cursor..(text_cursor + 1)]);
							text_cursor += 1;
						} else {
							out[row_cursor].push(' ');
						}
					} else {
						break;
					}
				}
			}
			straight = true;
		}
	}
	
	return (out);
}

fn main() {
	let text: String = "PAYPALISHIRING".to_string();
	let rows: usize = 4;
	
	let lines: Vec<String> = zigzag(text, rows);
	
	println!("This is the handy work of Rust\n\n\n");
	
	for i in 0..lines.len(){
		println!("{}", lines[i]);
	}
	
	println!("\n\n");
}
