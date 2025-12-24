<?php

$negativeAsISquared = true;

function reverseNumber($number, $base = 10){
	$nh = $number;
	$out = 0;
	$i = 1;
	
	while ($nh > 0){
		$out *= $i;
		$mod = $nh % $base;
		$out += $mod;
		$nh -= $mod;
		$nh /= $base;
		$i = 10;
	}
	
	return ($out);
}

function palindromeChecker($number){
	$out = null;
	$negative = ($number < 0);
	
	$number = ($number < 0) ? ($number * -1) : ($number * 1);
	
	$reversed_number = reverseNumber($number);
	
	if ($negativeAsISquared){
		$out = ($number == $reversed_number);
	} else {
		if ($negative){
			$out = ($number == $reversed_number);
		} else {
			if ($negative){
				$out = (($number * -1) == $reversed_number);
			} else {
				$out = ($number == $reversed_number);
			}
		}
	}
	
	return ($out);
}

print ("This is the handy work of PHP\n\n");

print((palindromeChecker(232321)) ? ("True") : ("False"));

print("\n\n");
?>
