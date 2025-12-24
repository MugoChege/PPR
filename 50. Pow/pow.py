def power (significand, exponent):
	out = 1
	
	if (exponent > 0):
		for i in range(exponent):
			out *= significand
	elif (exponent < 0):
		exponent *= -1
		for i in range (exponent):
			out /= significand
	elif (exponent == 0):
		out = 1
	
	return out
	
significand = 2
exponent = 0

print (power(significand, exponent))
