def division_whole (number, divisor)
	out = 0
	running_number = number
	
	while ((running_number - divisor) >= 0)
		out += 1
		running_number -= divisor
	end
	
	return out
end

def modulo_whole (number, divisor)
	running_number = number
	
	while ((running_number - divisor) >= 0)
		running_number -= divisor
	end
	
	return running_number
end

def multiplication (multiplicand, multiplier)
	out = 0
	
	for i in 0...multiplier
		out += multiplicand
	end
	
	return out
end

def division (number, divisor, no_of_figures = 10)
	base = 10
	counter = 0
	fraction = 0
	integer_quotient = division_whole(number, divisor)
	remainder = modulo_whole(number, divisor)
	running_number = remainder
	out_of = 1
	
	while ((running_number != 0) and (counter < no_of_figures))
		#running_number *= base
		running_number = multiplication(running_number, base)
		#out_of *= base
		out_of = multiplication(out_of, base)
		
		if (fraction == 0)
			fraction += division_whole(running_number, divisor)
		elsif
			#fraction *= base
			fraction = multiplication(fraction, base)
			fraction += division_whole(running_number, divisor)
		end
		
		running_number = modulo_whole(running_number, divisor)
		
		counter += 1
		
	end
	
	return [integer_quotient, fraction, out_of]
end

number = 6402
divisor = 8

puts (division(number, divisor))
#puts (modulo(number, divisor))
#puts (division_fraction(7,divisor))
