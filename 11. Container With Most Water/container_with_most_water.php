<?php
function absolute ($number){
	return (($number < 0) ? ($number * -1) : ($number * 1));
}

function getVolume ($height1, $height2, $width){
	$height = ($height1 < $height2) ? ($height1) : ($height2);
	
	return ($height * $width);
}

function containerPoints ($list){
	$lenList = count($list);
	$largestVolume = 0;
	$volumeIndixes = [];
	
	for ($a = 0; $a < $lenList; $a++){
		for ($b = ($lenList - 1); $b > 0; $b--){
			if ($a == $b){
				continue;
			} else if ($b < $a){
				break;
			} else {
				$interval = absolute ($a - $b);
				$volume = getVolume ($list[$a], $list[$b], $interval);
				
				if ($largestVolume < $volume){
					$largestVolume = $volume;
					$volumeIndexes = [$a, $b];
				}
			}
		}
	}
	
	return ($volumeIndexes);
}

$heightList = [1,8,6,2,5,4,8,3,7];
$heightIndices = containerPoints($heightList);
$height1 = $heightList[$heightIndices[0]];
$height2 = $heightList[$heightIndices[1]];
$interval = absolute($heightIndices[0] - $heightIndices[1]);

echo("This is the handy work of PHP\n\n");
echo(json_encode($heightIndices) . "\n");
echo("The heights given the points are: " . strval($height1) . " on one end and " . strval($height2) . " on the other end. The difference between the two points is " . strval($interval) . " giving a total volume of " . strval(getVolume($height1, $height2, $interval)) . "\n\n");
?>
