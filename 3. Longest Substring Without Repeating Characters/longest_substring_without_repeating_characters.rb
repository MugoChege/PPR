def longest_substring (text)
	len_text = text.length()
	longest_text = ""
	
	for a in 0...len_text
		for b in a...(len_text - a)
			substring = text[a, b]
			letter = text[a + b, 1]
			#puts (substring + "\t\t\t" + letter)
			
			if (substring.include?(letter))
				if (longest_text.length() < substring.length())
					longest_text = substring
				end
				break
			end
		end
	end
	
	return longest_text
end

w = longest_substring("pwwkew")
puts (w)
puts ("\n\n")
