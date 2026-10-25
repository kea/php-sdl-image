# SDL_image PHP Extension
[SDL_image](https://www.libsdl.org/projects/SDL_image/) for PHP allows to load images (PNG, JPG, BMP, TGA, TIF, etc.) and create SDL_Texture or SDL_Surface.
It requires SDL PHP Extension.

## Installing with PIE

Install with [PIE](https://github.com/php/pie) (PHP Installer for Extensions):

```bash
$ pie install kea/php-sdl-image
```

The SDL_image development files (e.g. `libsdl2-image-dev` on Debian/Ubuntu) and the SDL PHP extension must be installed first.
If SDL_image is in a non-standard location:

```bash
$ pie install kea/php-sdl-image --with-sdl_image=/opt/sdl_image
```

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
