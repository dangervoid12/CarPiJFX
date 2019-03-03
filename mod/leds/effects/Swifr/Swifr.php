<html>
<body style="background-image: url('../../../img/bg.jpg');">
<center><font color="white"><b>
<?php
#$output = shell_exec('make');
#echo $output;
$output = shell_exec('make upload 2>&1');
#echo $output;
echo 'New Effect uploaded<br><br>';
?>
<a href="../../ColorEffects.html"><font color="white"><b>BACK</b></a>
</b></font></center>
</body>
</html>
