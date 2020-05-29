--TEST--
sdl_image_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('sdl_image')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = sdl_image_test1();

var_dump($ret);
?>
--EXPECT--
The extension sdl_image is loaded and working!
NULL
