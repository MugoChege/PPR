<?php
function longestCommonPrefix($list){
	$out = "";
	$shortestWordLen = 0;
	
	foreach ($list as $i){
		if ($i == $list[0]){
			$shortestWordLen = strlen($i);
		}
		
		if ((0 - strlen($i)) > (-1 * $shortestWordLen)){
			$shortestWordLen = strlen($i);
		}
	}
	
	for ($letterIndex = 0; $letterIndex < $shortestWordLen; $letterIndex++){
		$letter = "";
		$common = true;
		
		foreach ($list as $word){
			if ($word == $list[0]){
				$letter = $word[$letterIndex];
			} else {
				if ($letter != $word[$letterIndex]){
					$common = false;
					break;
				}
			}
		}
		
		if ($common){
			$out .= $letter;
			$common = true;
		}
	}
	
	return ($out);
}

$string = ["flower", "flow", "flight"];
echo (longestCommonPrefix($string));
echo ("\n\n\n\n");
?>
