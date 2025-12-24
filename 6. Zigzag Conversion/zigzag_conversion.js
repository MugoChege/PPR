function zigzag (text, rows){
	let out = [];
	
	for (let i = 0; i < rows; i++){
		out.push ("");
	}
	
	let lenText = text.length;
	let textCursor = 0;
	let straight = true;
	let lenOut = out.length;
	
	while (textCursor < lenText){
		if (straight){
			for (let outCursor = 0; outCursor < lenOut; outCursor++){
				if (textCursor < lenText){
					out[outCursor] += text[textCursor];
					textCursor += 1;
				} else {
					break;
				}
			}
			
			straight = false;
		} else {
			for (let nonTerminalRows = 0; nonTerminalRows < (lenOut - 2); nonTerminalRows++){
				for (let outCursor = 0; outCursor < lenOut; outCursor++){
					if (textCursor < lenText){
						if (outCursor == (rows - 2 - nonTerminalRows)){
							out[outCursor] += text[textCursor];
							textCursor += 1;
						} else {
							out[outCursor] += " "
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

let o = zigzag("PAYPALISHIRING", 4);

for (t of o){
	console.log(t);
}
