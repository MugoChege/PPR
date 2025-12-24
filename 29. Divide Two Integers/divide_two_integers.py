def division_whole (number, divisor):
	out = 0
	running_number = number
	
	while ((running_number - divisor) >= 0):
		out += 1;
		running_number -= divisor
	
	return out
	
def modulo_whole (number, divisor):
	running_number = number
	while ((running_number - divisor) >= 0):
		running_number -= divisor
		
	return running_number

def multiplication (multiplicand, multiplier):
	out = 0
	
	for i in range(multiplier):
		out += multiplicand
		
	return out

def division (number, divisor, no_of_figures = 10):
	base = 10 #sorting out the place values
	counter = 0
	fraction = 0
	integer_quotient = division_whole(number,divisor)
	remainder = modulo_whole(number,divisor)
	running_number = remainder
	out_of = 1
	
	while ((running_number != 0) and (counter < no_of_figures)):
		#running_number *= base;
		running_number = multiplication(running_number, base)
		#out_of *= base
		out_of = multiplication(out_of, base)
		
		if (fraction == 0):
			fraction += division_whole(running_number, divisor)
		else:
			#fraction *= base
			fraction = multiplication(fraction, base)
			
			fraction += division_whole(running_number, divisor)
		
		running_number = modulo_whole(running_number, divisor)
		#print(str(counter) + "\t" + str(fraction) + "\t" + str(running_number))
		
		counter += 1;
		
	return [integer_quotient, fraction, out_of] #integer quotient
	
number = 6402
divisor = 8

print (division(number, divisor))
##print (modulo_whole(number, divisor))
##print (division(7, divisor))
