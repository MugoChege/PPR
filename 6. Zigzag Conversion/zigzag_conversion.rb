def zigzag(text, rows)
	out = []
	
	for a in 0...rows
		out << ""
	end
	
	len_text = text.length;
	
	straight = true
	text_cursor = 0
	
	while (text_cursor < len_text)
		if straight
			for out_cursor in 0... out.length
				if (text_cursor < len_text)
					out[out_cursor] += text[text_cursor]
					text_cursor += 1
				else
					break
				end
			end
			
			straight = false
		else
			for non_terminal_row in 0...(out.length - 2) #eliminates the first and last row
				for out_cursor in 0...out.length
					if (text_cursor < len_text)
						if (out_cursor == (rows - 2 - non_terminal_row))
							out[out_cursor] += text[text_cursor]
							text_cursor += 1
						else
							out[out_cursor] += " "
						end
					else
						break
					end
				end
			end
			straight = true
		end
	end
	
	return out
end

o = zigzag("PAYPALISHIRING", 4)

o.each() do |t|
	print(t)
	print("\n")
end
