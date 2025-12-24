<?php
function sumOfThree ($list, $target = 0){
	$lenList = count ($list);
	$out = [];
	
	for ($a = 0; $a < $lenList; $a++){
		for ($b = 0; $b < $lenList; $b++){
			if ($b > $a){
				for ($c = 0; $c < $lenList; $c++){
					if ($c > $b){
						if (($a != $b) && ($a != $c) && ($b != $c)){
							$aa = $list[$a];
							$bb = $list[$b];
							$cc = $list[$c];
							if (($aa != $bb) && ($aa != $cc) && ($bb != $cc)){
								if (($aa + $bb + $cc) == $target){
									//$z = [$a, $b, $c];
									$z = [$list[$a], $list[$b], $list[$c]];
									array_push($out, $z);
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

$nums = [-1,0,1,2,-1,-4];

print_r (sumOfThree($nums));
?>
