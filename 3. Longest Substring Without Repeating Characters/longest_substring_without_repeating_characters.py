def longest_substring (text):
	len_text = len (text)
	longest_text = ""
	
	for a in range (len_text):
		for b in range (a, (len_text) - a):
			substring = text[a:a + b]
			letter = text[a + b: a + b + 1]
			print (substring + "\t\t\t" + letter + "\t\t\t" + text[a + b])
			
			if (letter in substring):
			#	break
			#else:
				if (len(longest_text) < len(substring)):
					longest_text = substring
				break
	
	return longest_text
	
w = longest_substring("pwwkew")
print (w)
print ("\n\n\n")
