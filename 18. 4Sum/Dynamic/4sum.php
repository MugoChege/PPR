<?php
function notEqualList ($list){
	$lenList = count($list);
	$out = true;
	
	for ($i = 0; $i < $lenList; $i++){
		for ($j = $i; $j < $lenList; $j++){
			if ($i != $j){
				if ($list[$i] == $list[$j]){
					$out = false;
				}
			}
		}
	}
	
	return ($out);
}

function sumOfFour($list, $target = 0){
	$lenList = count($list);
	$out = [];
	
	for ($a = 0; $a < $lenList; $a++){
		for ($b = 0; $b < $lenList; $b++){
			if ($b > $a){
				for ($c = 0; $c < $lenList; $c++){
					if ($c > $b){
						for ($d = 0; $d < $lenList; $d++){
							if ($d > $c){
								if (notEqualList([$a,$b,$c,$d])){
								//if (true){
									$aa = $list[$a];
									$bb = $list[$b];
									$cc = $list[$c];
									$dd = $list[$d];
									
									//if (notEqualList([$aa, $bb, $cc, $dd])){ //if the values in the array should be different to each other
									if (true){
										if (($aa + $bb + $cc + $dd) == $target){
											//$z = [$a, $b, $c, $d];
											$z = [$list[$a], $list[$b], $list[$c], $list[$d]];
											
											array_push($out, $z);
										}
									}
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

$nums = [1,0,-1,0,-2,2];
echo (json_encode(sumOfFour($nums)));
echo ("\n\n\n");
?>
