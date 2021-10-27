# SDL_image PHP Extension
[SDL_image](https://www.libsdl.org/projects/SDL_image/) for PHP allows to load images (PNG, JPG, BMP, TGA, TIF, etc.) and create SDL_Texture or SDL_Surface.
It requires SDL PHP Extension.

## Building

```bash
$ phpize
$ ./configure --enable-sdl_image
$ make
$ make install
```

Run tests with installed PHP (avoids skipped tests):

```
$ php run-tests.php --show-diff -q
```

## Requirements

Require PHP 8+ and SDL PHP extension

```
$ pecl install sdl-devel
```
