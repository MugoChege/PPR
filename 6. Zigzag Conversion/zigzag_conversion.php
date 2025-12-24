<?php
function zigzag ($text, $rows){
	$out = [];
	
	for ($i = 0; $i < $rows; $i++){
		array_push($out, "");
	}
	
	$straight = true;
	$textCursor = 0;
	$lenText = strlen($text);
	$lenOut = count($out);
	
	while ($textCursor < $lenText){
		if ($straight){
			for ($outCursor = 0; $outCursor < $lenOut; $outCursor++){
				if ($textCursor < $lenText){
					$out[$outCursor] .= $text[$textCursor];
					$textCursor += 1;
				} else {
					break;
				}
			}
			$straight = false;
		} else {
			for ($nonTerminalRow = 0; $nonTerminalRow < ($lenOut - 2); $nonTerminalRow++){
				for ($outCursor = 0; $outCursor < $lenOut; $outCursor++){
					if ($textCursor < $lenText){
						if ($outCursor == ($lenOut - 2 - $nonTerminalRow)){
							$out[$outCursor] .= $text[$textCursor];
							$textCursor += 1;
						} else {
							$out[$outCursor] .= " ";
						}
					} else {
						break;
					}
				}
			}
			
			$straight = true;
		}
	}
	
	return ($out);
}

$o = zigzag("PAYPALISHIRING", 4);

foreach ($o as $t){
	echo ($t);
	echo ("\n");
}
?>
