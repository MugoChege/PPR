$combinations= [" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

def word_from_odo(relevant_digits, digits_odo)
	out = ""
	
	for i in 0...relevant_digits.length
		out += $combinations[Integer(relevant_digits[i])][digits_odo[i]];
	end
	
	return out
end

def word_fill (relevant_digits, digits_odo, depth, max_depth, sample_space)
	letter_options = $combinations[Integer(relevant_digits[depth])]
	len_letter_options = letter_options.length;
	
	for i in 0...len_letter_options
		digits_odo[depth] = i
		if (depth < (max_depth - 1))
			word_fill(relevant_digits, digits_odo, (depth + 1), max_depth, sample_space)
		else
			sample_space << (word_from_odo(relevant_digits, digits_odo))
		end
	end
end

def get_letter_combinations(digits)
	out = []
	
	len_digits = digits.length
	odo = []
	
	useable_digits = ""
	
	for i in 0...len_digits
		if ($combinations[Integer(digits[i])].length == 0)
			next
		end
		
		useable_digits += digits[i]
		odo << 0
	end
	
	len_useable_digits = useable_digits.length
	word_fill(useable_digits, odo, 0, len_useable_digits, out)
	
	return out
end

digits = "6872"
puts(get_letter_combinations(digits))

