def longest_common_prefix (list)
	out = ""
	shortest_word_len = 0
	
	for i in list
		if i == list[0]
			shortest_word_len = i.length
		end
		
		if ((0 - i.length) > (-1 * shortest_word_len))
			shortest_word_len = i.length
		end
	end
	
	for letter_index in 0...shortest_word_len
		letter = ""
		common = true
		
		for word in list
			if word == list[0]
				letter = word[letter_index]
			else
				if letter != word[letter_index]
					common = false
					break
				end
			end
		end
		
		if common
			out << letter
			common = true
		end
	end
	
	return out
end

strings = ["flower", "flow", "flight"]
puts (longest_common_prefix(strings));
puts ("\n\n\n\n")
