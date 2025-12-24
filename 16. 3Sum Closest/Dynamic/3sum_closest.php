<?php

function sumOfTheResult($list){
	$out = 0;
	
	foreach ($list as $i){
		foreach ($i as $j){
			$out += $j;
		}
	}
	
	return $out;
}

function absoluteValue($number){
	return ($number > 0) ? ($number * 1) : ($number * -1);
}

function sumOfThreeClosest($list, $target = 0){
	$lenArray = count($list);
	$out = [];
	$closest = null;
	
	for ($a = 0; $a < $lenArray; $a++){
		for ($b = 0; $b < $lenArray; $b++){
			if ($b > $a){
				for ($c = 0; $c < $lenArray; $c++){
					if ($c > $b){
						if (($a != $b) && ($a != $c) && ($b != $c)){
							$aa = $list[$a];
							$bb = $list[$b];
							$cc = $list[$c];
							
							##if (($aa != $bb) && ($aa != $cc) && ($bb != $cc)) #toggle this for no similar value elements
							if (true){
								$throw = absoluteValue(($aa + $bb + $cc) - $target);
								
								if ($closest == null){
									$closest = $throw;
								}
								
								if ($throw == $closest){
									//$z = [$a, $b, $c];
									$z = [$list[$a], $list[$b], $list[$c]];
									array_push($out, $z);
								} else if ($throw < $closest){
									//$z = [$a, $b, $c];
									$z = [$list[$a], $list[$b], $list[$c]];
									array_push($out, $z);
									$closest = $throw;
								}
							}
						}
					}
				}
			}
		}
	}
	
	return ($out);
}

$nums = [-1,2,1,-4];

$closest = sumOfThreeClosest($nums, 1);
print_r($closest);
print_r(sumOfTheResult($closest));
print("\n\n\n");

?>
