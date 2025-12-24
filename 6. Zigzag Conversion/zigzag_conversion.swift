func zigzag (text: String, rows: Int) -> Array<String> {
	var out: Array<String> = [];
	
	for a in 0..<rows{
		out.append("");
	}
	
	var len_text: Int = text.count;
	
	var straight: Bool = true;
	var text_cursor: Int = 0;
	
	while text_cursor < len_text{
		if (straight){
			for row_cursor in 0..<rows{
				if text_cursor < len_text{
					let index = text.index(text.startIndex, offsetBy: text_cursor);
					out[row_cursor].append(text[index]);
					text_cursor += 1;
				} else {
					break;
				}
			}
			straight = false;
		} else {
			for term in 0..<(rows - 2){
				for row_cursor in 0..<rows{
					if (text_cursor < len_text){
						if row_cursor == (rows - 2 - term){
							let index = text.index(text.startIndex, offsetBy: text_cursor);
							out[row_cursor].append(text[index]);
							text_cursor += 1;
						} else {
							out[row_cursor].append(" ");
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

	
let lines: Array<String> = zigzag(text: "PAYPALISHIRING", rows: 4);

print("This is the handy work of Swift\n\n\n");

for line in lines{
	print(line)
}

print("\n\n\n");
