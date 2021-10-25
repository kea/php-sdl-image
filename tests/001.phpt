--TEST--
Check image load
--SKIPIF--
<?php
if (!extension_loaded('SDL_image')) {
	echo 'skip';
}
?>
--FILE--
<?php

SDL_Init(SDL_INIT_VIDEO);
$window = new SDL_Window('_', SDL_Window::POS_UNDEFINED, SDL_Window::POS_UNDEFINED, 10, 10, SDL_Window::HIDDEN);

$renderer = SDL_CreateRenderer($window, 0, 0);
$texture = IMG_LoadTexture($renderer, __DIR__.'/test.png');
var_dump($texture);

$texture = IMG_LoadTexture($renderer, __DIR__.'/1x1.png');
var_dump($texture);

?>
--EXPECT--
NULL
resource(5) of type (SDL Texture)
