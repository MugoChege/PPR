fun zigzag (text: String, rows: Int) : Array<String>{
	var out: Array<String> = Array(rows){""};
	
	var len_text: Int = text.length;
	var straight: Boolean = true;
	var text_cursor: Int = 0;
	
	while (text_cursor < len_text){
		if (straight) {
			for (row_cursor in 0 until rows){
				if (text_cursor < len_text){
					//out[row_cursor] += text[text_cursor];
					out[row_cursor] = out[row_cursor] + text[text_cursor];
					//out[row_cursor].plus(text[text_cursor]);
					text_cursor += 1;
				} else {
					break;
				}
			}
			straight = false;
		} else {
			for (term in 0 until (rows - 2)){
				for (row_cursor in 0 until rows){
					if (text_cursor < len_text){
						if (row_cursor == (rows - 2 - term)){
							//out[row_cursor] += text[text_cursor];
							out[row_cursor] = out[row_cursor] + text[text_cursor];
							//out[row_cursor].plus(text[text_cursor]);
							text_cursor++;
						} else {
							//out[row_cursor] += ' ';
							out[row_cursor] = out[row_cursor] + ' ';
							//out.plus(' ');
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

fun main (){
	val text: String = "PAYPALISHIRING";
	val rows: Int = 5;
	
	var line: Array<String> = zigzag(text, rows);
	
	println("This is the handy work of Kotlin\n\n\n");
	
	for (i in 0 until line.size){
		println(line[i]);
	}
	
	println("\n\n\n");
}
