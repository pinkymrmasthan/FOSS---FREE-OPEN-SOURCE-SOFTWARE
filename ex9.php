<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>

<?php

$myfile = fopen("myfile.txt", "w") or die("Unable to open");
$txt = "This is an txt file created by php code. \n";
fwrite($myfile, $txt);
$txt1 = "This is another txt file created by php code. \n";
fwrite($myfile, $txt1);
echo "File created successfully..";

?>
</body>
</html>