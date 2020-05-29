--TEST--
Check if sdl_image is loaded
--SKIPIF--
<?php
if (!extension_loaded('sdl_image')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "sdl_image" is available';
?>
--EXPECT--
The extension "sdl_image" is available
