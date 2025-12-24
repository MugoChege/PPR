def is_palindrome(sub)
	len_sub = sub.length
	mirror = len_sub / 2
	out = false
	
	for a in 0...mirror
		if a == 0
			out = (sub[a] == sub [len_sub - 1 - a])
		else
			out = out and (sub[a] == sub[len_sub - 1 - a])
		end
	end
	
	return out
end

def longest_substring(text)
	len_text = text.length
	longest_text = ""
	
	for a in 0...len_text
		for b in 1...(len_text - a)
			substring = text[a... (a + b + 1)]
			
			if (is_palindrome(substring))
				if (longest_text.length < substring.length)
					longest_text = substring
				
				end
				#break
			end
		end
	end
	
	return longest_text
end

puts(longest_substring("babab"))
puts("\n\n\n\n")
