combinations= [" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

def word_from_odo (relevant_digits, digits_odo):
	out = ""
	
	for i in range(len(relevant_digits)):
		out += combinations[int(relevant_digits[i])][digits_odo[i]]
	
	return out

def word_fill (relevant_digits, digits_odo, depth, max_depth, sample_space):
	#max_depth is the length of the relevant_digits
	letter_options = combinations[int(relevant_digits[depth])]
	len_letter_options = len(letter_options)
	
	for i in range(len_letter_options):
		digits_odo[depth] = i
		if (depth < (max_depth - 1)):
			word_fill(relevant_digits, digits_odo, depth + 1, max_depth, sample_space)
		else:
			##  sampe_space[sample_space_cursor] = ""
			sample_space.append(word_from_odo(relevant_digits, digits_odo))
			#should be append for the dynamic array programming languages


def get_letter_combinations (digits):
	out = []
	
	len_digits = len(digits)
	odo = []
	
	useable_digits = ""
	sample_size = 0
	for i in range(len_digits):
		no_of_letters = len(combinations[int(digits[i])])
		
		if no_of_letters == 0:
			continue
		
		useable_digits += digits[i]
		
		if (sample_size == 0):
			sample_size = len(combinations[int(digits[i])])
		else:
			sample_size *= len(combinations[int(digits[i])])
		
		odo.append(0)
	
	print("The useable digits are\t" + str(useable_digits))
	print("The size of the combinations is\t" + str(sample_size))
	len_useable_digits = len(useable_digits)
	word_fill (useable_digits, odo, 0, len_useable_digits, out)
	
	return out
	
digits = "6872"
print(get_letter_combinations(digits))
