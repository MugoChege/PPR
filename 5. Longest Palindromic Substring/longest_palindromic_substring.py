def is_palindrome (sub):
	len_sub = len(sub)
	mir = len_sub // 2
	out = False
	
	for a in range(mir):
		if a == 0:
			out = (sub[a] == sub[len_sub - 1 - a])
		else:
			out = out and (sub[a] == sub[len_sub - 1 - a])
	
	return out

def longest_substring (text):
	len_text = len (text)
	longest_text = ""
	
	for a in range (len_text):
		for b in range (0, (len_text) - a):
			substring = text[a:a + b + 1]
			
			if (is_palindrome(substring)):
				if (len(longest_text) < len(substring)):
					longest_text = substring
				#break
	
	return longest_text

word = "babab"
print(longest_substring(word))
