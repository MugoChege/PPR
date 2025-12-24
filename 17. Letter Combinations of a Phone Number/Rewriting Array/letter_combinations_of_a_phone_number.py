combinations = {
	0: " ",
	1: "",
	2: "abc",
	3: "def",
	4: "ghi",
	5: "jkl",
	6: "mno",
	7: "pqrs",
	8: "tuv",
	9: "wxyz"
	}
	
def letter_combinations (digits):
	out = []
	digits = str(digits)
	
	# this is the solution that does not account for the number of times that out is rewritten
	# to avoid out being rewritten a recurssive function can be explored
	
	for d in digits:
		letters = combinations[int(d)]
		if (out == []) and (len(out) == 0):
			for l in letters:
				out.append(l)
		else:
			holder = []
			for l in letters:
				for o in out:
					holder.append(o + l)
			out = holder
			
	out.sort()
	
	return out
	
digits = "23"
print(letter_combinations(digits))
