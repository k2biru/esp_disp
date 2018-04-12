<?php
$nama="jam";
if(isset($_GET[$nama]))
{
	$data=$_GET[$nama];
	$myfile = fopen("{$nama}.txt", "w") or die("Unable to open {$nama} file!");
	$txt = (string)$data;
	echo $txt;
	fwrite($myfile, $txt);
	fclose($myfile);
}
$nama="buka";
if(isset($_GET[$nama]))
{
	$data=$_GET[$nama];
	$myfile = fopen("{$nama}.txt", "w") or die("Unable to open {$nama} file!");
	$txt = (string)$data;
	echo $txt;
	fwrite($myfile, $txt);
	fclose($myfile);
}
$nama="raw";
if(isset($_GET[$nama]))
{
	$data=$_GET[$nama];
	$myfile = fopen("{$nama}.txt", "w") or die("Unable to open {$nama} file!");
	$txt = (string)$data;
	echo $txt;
	fwrite($myfile, $txt);
	fclose($myfile);
}
echo "\ni'M OK \n";
?>