<html>
<body style="background-image: url(../../img/bg.jpg);">
<?php

echo "<font color=white><b>New colors:";
#echo "<br>";
$colorLeft = "";
$colorRight = "";
echo "  Left: ";
if (isset ($_POST['colorLeft'])) {
 echo  $_POST['colorLeft'];
	$colorLeft = $_POST['colorLeft'];
} 

echo '<br>'; 
echo "  Right: ";
if (isset ($_POST['colorRight'])) {
  echo $_POST['colorRight'];
  $colorRight = $_POST['colorRight'];

}

$myfileNew = fopen("newColors.ino", "w") or die("Unable to open file!");

$myFile1 = fopen("parts/colors1.ino" ,"r") or die("Unable to open");
$txt1 = fread($myFile1,filesize("parts/colors1.ino"));
#fclose($myFile1);

$myFile2 = fopen("parts/colors2.ino" ,"r") or die("Unable to open");
$txt2 = fread($myFile2,filesize("parts/colors2.ino"));
#fclose($myFile2);



fwrite($myfileNew, $txt1);
$txt = "color1 = 0x";
# + $colorLeft + ";\n color2 = 0x" + $colorRight + ";\n" ;
fwrite($myfileNew, $txt);
$colorLeft =  substr($colorLeft, 1);
fwrite($myfileNew,$colorLeft);
fwrite($myfileNew, ";\n color2 = 0x");
$colorRight = substr($colorRight, 1);
fwrite($myfileNew, $colorRight);
fwrite($myfileNew, ";\n");
fwrite($myfileNew, $txt2);
fclose($myfileNew);
fclose($myFile1);
fclose($myFile2);

$output = shell_exec('make');
#echo $output;
$output = shell_exec('make upload 2>&1');
#echo $output;
echo '<br> New Colors uploaded';
#echo '</b></font>';
?>
</body>
</html>
