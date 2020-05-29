--TEST--
sdl_image_test2() Basic test
--SKIPIF--
<?php
if (!extension_loaded('sdl_image')) {
	echo 'skip';
}
?>
--FILE--
<?php
var_dump(sdl_image_test2());
var_dump(sdl_image_test2('PHP'));
?>
--EXPECT--
string(11) "Hello World"
string(9) "Hello PHP"
