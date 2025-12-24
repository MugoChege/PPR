<?php
function division_whole ($number, $divisor){
	$out = 0;
	$running_number = $number;
	
	while(($running_number - $divisor) >= 0){
		$out++;
		$running_number -= $divisor;
	}
	
	return ($out);
}

function modulo_whole ($number, $divisor){
	$running_number = $number;
	
	while (($running_number - $divisor) >= 0){
		$running_number -= $divisor;
	}
	
	return ($running_number);
}

function multiplication($multiplicand, $multiplier){
	$out = 0;
	
	for ($i = 0; $i < $multiplier; $i++){
		$out += $multiplicand;
	}
	
	return ($out);
}

function division ($number, $divisor, $no_of_figures = 10){
	$base = 10;
	$counter = 0;
	$fraction = 0;
	$integer_quotient = division_whole($number, $divisor);
	$remainder = modulo_whole($number, $divisor);
	$running_number = $remainder;
	$out_of = 1;
	
	while (($running_number != 0) && ($counter < $no_of_figures)){
		//$running_number *= $base;
		$running_number = multiplication($running_number, $base);
		//out_of *= $base;
		$out_of = multiplication($out_of, $base);
		
		if ($fraction == 0){
			$fraction += division_whole($running_number, $divisor);
		} else {
			//$fraction *= $base;
			$fraction = multiplication($fraction, $base);
			$fraction += division_whole($running_number, $divisor);
		}
		
		//echo ((string)($counter). "\t". (string)($running_number). "\t". (string)($fraction). "\n");
		$running_number = modulo_whole($running_number, $divisor);
		$counter++;
	}
	
	return ([$integer_quotient, $fraction, $out_of]);
}

$number = 6402;
$divisor = 8;

print_r (division($number, $divisor));
echo ("\n");
//echo (modulo($number, $divisor));
echo ("\n");
//echo (division_fraction(7, $divisor));
echo ("\n");

?>
