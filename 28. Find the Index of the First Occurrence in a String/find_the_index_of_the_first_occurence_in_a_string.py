CASE_SENSITIVE = False

def compare_strings (text1, text2):
	out = False
	
	global CASE_SENSITIVE
	if CASE_SENSITIVE:
		text1 = text1.upper()
		text2 = text2.upper()
	
	if (text1 == "" and text2 == ""):
		out = True
		return out
	
	if len(text1) != len(text2):
		return out
	
	for i in range (len(text1)):
		if (i == 0):
			if (text1[i] == text2[i]):
				out = True
			else:
				out = False
		else:
			out = out and (text1[i] == text2[i])
	
	return out
	
def first_occurence (needle, haystack):
	len_needle = len(needle)
	len_haystack = len(haystack)
	out = -1
	
	if len_needle > len_haystack:
		out = -1
	elif len_needle == len_haystack:
		found = compare_strings(needle, haystack)
		out = 0 if found else -1
	else:
		len_searchable = len_haystack - len_needle + 1
		for i in range(len_searchable):
			#print (needle + "\t" + haystack[i: (i + len_needle)])
			if (compare_strings(needle, haystack[i: (i + len_needle)])):
				out = i
				break
	
	return out
	

print(first_occurence( haystack = "leetcode", needle = "ode"))
