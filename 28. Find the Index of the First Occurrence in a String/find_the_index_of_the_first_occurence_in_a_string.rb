$CASE_SENSITIVE = false

def compare_strings (text1, text2)
	out = false
	
	if ($CASE_SENSITIVE)
		text1 = text.upcase()
		text2 = text.upcase()
	end
	
	if (text1 == "" and text2 == "")
		out = true
		return out
	end
	
	if (text1.length() != text2.length)
		return out
	end
	
	for i in 0...text1.length()
		if (i == 0)
			if (text1[i] == text2[i])
				out = true
			else
				out = false
			end
		else
			out = out and (text1[i] == text2[i])
		end
	end
	
	return out
end

def first_occurence (needle, haystack)
	len_needle = needle.length()
	len_haystack = haystack.length()
	out = -1
	
	if (len_needle > len_haystack)
		out = -1
	elsif
		found = compare_strings(needle, haystack)
		out = (found) ? 0 : -1
	else
		len_searchable = len_haystack - len_needle + 1
		for i in 0...len_searchable
			if (compare_strings(needle, haystack[i...(i + len_needle)])) #complete this at least
				out = i
				break
			end
		end
	end
	
	return out
end

puts (first_occurence("ode", "leetcode"));
