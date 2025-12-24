def zigzag (text, rows):
	out = []
	
	for a in range(rows):
		out.append("")
		
	len_text = len(text)
	
	straight = True
	text_cursor = 0
	
	while (text_cursor < len_text):
		if straight:
			for row_cursor in range(len(out)):
				if (text_cursor < len_text):
					out[row_cursor] += text[text_cursor]
					text_cursor += 1
				else:
					break
			straight = False
		else:
			for terminals in range(len(out) - 2):
				for row_cursor in range(len(out)):
					if (text_cursor < len_text):
						#if (row_cursor == (rows - 1 - (a % rows))): #
						if (row_cursor == (rows - 2 - terminals)):
							out[row_cursor] += text[text_cursor]
							text_cursor += 1
						else:
							out[row_cursor] += " "
					else:
						break
			straight = True
	
	return out
	
lines = zigzag("PAYPALISHIRING", 4)

for line in lines:
	print(line)
