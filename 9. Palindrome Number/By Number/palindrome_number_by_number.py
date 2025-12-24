negative_as_i_squared = True

def reverse_number (number, base = 10):
	nh = number
	out = 0
	i = 1;
	while (nh > 0):
		out *= i
		mod = nh % base
		out += mod
		nh -= mod
		nh //= base
		i = 10
		
	return out
	
def palindrome_checker(number):
	out = False
	negative = (number < 0)
	
	number = (number * -1) if (number < 0) else (number * 1)
	
	reversed_number = reverse_number(number)
	
	if (negative_as_i_squared):
		out = (number == reversed_number)
	else:
		if (negative):
			out = ((number * -1) == reversed_number) #logic betrays this but it was in the challenge because where will one come across the reverse of -121 as 121-
		else:
			out = (number == reversed_number)
	
	return out
	
print (palindrome_checker(23232))
