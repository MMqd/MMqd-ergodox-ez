# My ErgodoxEZ configuration
This is my configuration for the Ergodox EZ keyboard that I have used daily since 2020. The core layout has remained largely the same over time, with minor iterative adjustments and optimizations.

## Physical Configuration
* Keyboard:
    * Color: White
    * Keycaps: Blank sculpted
    * Feet: Black
        * Tip: Mark the keyboard feet and body with a pencil, to ensure proper feet orientation if the keyboard is ever disassembled or packed up.
    * No RGB (Shine or Glow)
* Switches:
    * Cherry MX Brown
    * Filmed with 0.15mm films
    * Lubricated with Krytox 205g0
    * O-rings: 2mm, 40A hardness

## Installation
0. Install QMK
1. Install `teensy_loader_cli` using your package manager
2. Clone the `https://github.com/qmk/qmk_firmware` repository
3. Clone this repository and move it into `qmk_firmware/keyboards/ergodox_ez/keymaps`
4. Inside `qmk_firmware` run `make ergodox_ez:MMqd-ergodox-ez && teensy_loader_cli --mcu=atmega32u4 -w ergodox_ez_base_MMqd-ergodox-ez.hex && rm ergodox_ez_base_MMqd-ergodox-ez.hex`

## Features
* Dimmed layer LEDs for low light environments
* Thumb cluster provides easy access to modifiers and layer switching
* Colemak layout
* QWERTY layout layer for gaming
* Mouse layer removes the need for an external mouse for day-to-day tasks

## Design Considerations
Disable unused keys to prevent miss-presses
    * Except for when it is easier/necessary for a key combination 
* Optimize finger travel distances for common key combinations
* Utilize keys for multiple functions (tap for key, hold for modifier)
* Optimized for Vim, i3, and programming workflows
* Prevent unnatural finger stretching/compressing

## Layout
All empty keys are keys inherited from Layer 0.

**Note:** Keys with dual functions can be double tapped to use the normal key press, ignoring the modifier assigned to holding the key down. This allows you to hold the base key.

### Keycap Rotation
To improve thumb access, some keycaps are rotated 180° from their default orientation. This is especially important for keys near the thumb cluster, which are normally meant to be pressed by other fingers. Keys marked with `x` are rotated. The halves of the keyboard are mirrored.

```
,--------------------------------------------------.           ,--------------------------------------------------.
|  x     |  x   |  x   |  x   |  x   |  x   |  x   |           |  x   |  x   |  x   |  x   |  x   |  x   |  x     |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
|  x     |  x   |  x   |  x   |  x   |  x   |      |           |      |  x   |  x   |  x   |  x   |  x   |  x     |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  |      |      |      |  x   |  x   |                                       |  x   |  x   |      |      |      |
  `----------------------------------'                                       `----------------------------------'
                                        ,-------------.     ,-------------.
                                        |  x   |  x   |     |  x   |  x   |
                                ,-------|------|------|     |------+------+------.
                                |       |      |      |     |      |      |      |
                                |  x    |      |------|     |------|      |  x   |
                                |       |      |      |     |      |      |      |
                                `---------------------'     `--------------------'
```

### Layer 0: Default
```
,--------------------------------------------------.           ,--------------------------------------------------.
|        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
| TAB    |   Q  |   W  |   F  |   P  |   G  | Laye |           | Laye |   L  |   L  |   U  |   Y  |   ;  |        |
|--------+------+------+------+------+------| r 3  |           | r 4  |------+------+------+------+------+--------|
| LShift |   A  |   R  |   S  |   T  |   D  |------|           |------|   N  |   E  |   E  |   I  |   O  |        |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
| LCtrl  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  |        |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  | LALT |      |      | TAB/ | DEL/ |                                       | TAB/ | DEL/ |      |      |      |
  |      |      |      | SUPER| ALT  |                                       | SUPER| LALT |      |      |      |
  `----------------------------------'                                       `----------------------------------'
                                        ,-------------.     ,-------------.
                                        |      |      |     |      |      |
                                ,-------|------|------|     |------+------+--------.
                                |       |      |      |     |      |      | BACKS  |
                                |SPACE/ | ESC/ |------|     |------|Enter/| PACE/  |
                                |Layer 2| LCTRL|      |     |      |LSHIFT| Layer 1|
                                `---------------------'     `----------------------'
```

### Layer 1: Numbers and Symbols
The number keys are positioned based on the principle that larger numbers are used less than smaller ones, with more commonly used digits placed closer to the index fingers. Even numbers are assigned to the left hand, while odd numbers are on the right. The largest numbers are placed diagonally from the index fingers in the hardest to reach positions. This placement minimizes overall finger travel when entering numbers.

```
,--------------------------------------------------.           ,--------------------------------------------------.
|        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
|        |   6  |   4  |   2  |   0  |   8  |      |           |      |   9  |   1  |   3  |   5  |   7  |        |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        |   !  |   #  |   '  |   %  |   |  |------|           |------|   +  |   -  |   "  |   &  |   =  |        |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        |   _  |   @  |   ^  |   ~  |   ~  |      |           |      |   *  |   *  |   $  |   `  |   \  |        |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  |      |      |      |      |      |                                       |      |      |      |      |      |
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.     ,-------------.
                                       |      |      |     |      |      |
                                ,------|------|------|     |------+------+------.
                                |      |      |      |     |      |      |      |
                                |  (   |  )   |------|     |------|      |      |
                                |      |      |      |     |      |      |      |
                                `--------------------'     `--------------------'
```

### Layer 2: Navigation
```
,--------------------------------------------------.           ,--------------------------------------------------.
|        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
|        |      |  {   |  [   |   <  |      |      |           |      |      |  >   |  ]   |   }  |      |        |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        |Mouse |Mouse |Mouse |Mouse | WWW  |------|           |------| WWW  | Left | Down | Up   |Right |        |
|        |Left  |Down  |Up    |Right | BACK |------|           |------| FORW |      |      |      |      |        |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        | HOME/| END/ |PDDWN/| PGUP/|      |      |           |      |Scroll|Scroll|Mouse |Mouse |      |        |
|        | LCTRL|LSHIFT|LCTRL |LSHIFT|      |      |           |      |Down  |Up    |Accel2|Accel0|      |        |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  |      |      |      |      |      |                                       | Mouse |      |      |      |      |
  |      |      |      |      |      |                                       | 3     |      |      |      |      |
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.     ,---------------.
                                       |      |      |     |      |        |
                                ,------|------|------|     |------+--------+---------.
                                |      |      |      |     |      |        |         |
                                |      |      |------|     |------| Mouse 1| Mouse 2 |
                                |      |      |      |     |      |        |         |
                                `--------------------'     `-------------------------'
```

### Layer 3: QWERTY
QWERTY layer for gaming with some extra keys for easy access.
```
,--------------------------------------------------.           ,--------------------------------------------------.
|        |   1  |   2  |   3  |   4  |   5  |  6   |           |      |      |      |      |      |      |        |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
|        |   Q  |   W  |   E  |   R  |   T  | Laye |           |      |   Y  |   U  |   I  |   O  |   P  |        |
|--------+------+------+------+------+------| r 0  |           |      |------+------+------+------+------+--------|
|        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |        |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        |   Z  |   X  |   C  |   V  |   B  |  Y   |           |      |   N  |   M  |   ,  |   .  |   /  |        |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  |      |   H  |   J  |   K  | ESC  |                                       |      |      |      |      |      |
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.     ,-------------.
                                       |  U   |  I   |     |      |      |
                                ,------|------|------|     |------+------+------.
                                |      |      |  O   |     |      |      |      |
                                |SPACE |ENTER |------|     |------|      |      |
                                |      |      |  P   |     |      |      |      |
                                `--------------------'     `--------------------'
```

### Layer 4: Colemak with rotated keys test (legacy)
Certain frequently used keys have been rotated to sit directly over the index fingers rather than on the sides. This makes them quicker and easier to access compared to their default positions.

```
,--------------------------------------------------.           ,--------------------------------------------------.
|        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
|--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
|        |      |      |      |  D   |  V   |      |           |      |      |   H  |      |      |      |        |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        |      |      |      |      |  P   |------|           |------|  M   |      |      |      |      |        |
|--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
|        |      |      |      |  G   |      |      |           |      |      |   L  |      |      |      |        |
`--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  |      |      |      |      |      |                                       |      |      |      |      |      |
  `----------------------------------'                                       `----------------------------------'
                                       ,-------------.     ,-------------.
                                       |      |      |     |      |      |
                                ,------|------|------|     |------+------+------.
                                |      |      |      |     |      |      |      |
                                |      |      |------|     |------|      |      |
                                |      |      |      |     |      |      |      |
                                `--------------------'     `--------------------'
```
