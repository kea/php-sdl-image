--TEST--
Check image load to surface
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

$surface = IMG_Load(__DIR__.'/test.png');
var_dump($surface);

$surface = IMG_Load(__DIR__.'/1x1.png');
var_dump($surface instanceof SDL_Surface);
var_dump($surface->w, $surface->h, $surface->format->palette->ncolors);

?>
--EXPECT--
NULL
bool(true)
int(1)
int(1)
int(1)

