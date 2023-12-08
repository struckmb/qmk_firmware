
# Base Layers

## Home row mod, thumb keys and 6th rows
This is added to all base layers
```
.-----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐-----.
| Tab │     │     │     │     │     │             │     │     │     │(Mse)│     │     |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| C/E │     │     │(Gui)│(Ctl)│(Alt)│             │(Alt)│(Ctl)│(Gui)│     │     │(Alt)|
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| Sft │(Sft)│     │     │     │     │             │     │     │     │     │(Sft)│(RSh)|
'-----└─────┴─────┴─────┼─────┼─────┼-----. .-----┼─────┼─────┼─────┴─────┴─────┘-----'
                  | PUp │ Esc │Enter│ App | |BkSpc│Space│ Tab │ PDn |
                  'OsMeh└─Fn──┴─Num─┴-----' '-----┴─Sym─┴─Nav─┘OsHyp'
```
Pressing Fn+Nav simultaniously activates Adj layer

## Base Layout - QWERTZ
If QWERTZ_ENABLE is defined, you can switch to the following map
```
.-----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐-----.
| Tab │  q  │  w  │  e  │  r  │  t  │             │  z  │  u  │  i  │  o  │  p  │  ü  |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| C/E │  a  │  s  │  d  │  f  │  g  │             │  h  │  j  │  k  │  l  │  ö  │  ä  |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| Sft │  y  │  x  │  c  │  v  │  b  │             │  n  │  m  │ , ; │ . : │ ß ? │ Sft |
'-----└─────┴─────┼─────┼─────┼─────┼-----. .-----┼─────┼─────┼─────┼─────┴─────┘-----'
```

## Base Layout - BONE (matrix)
If BONE_ENABLE is defined, you can switch to the following map
```
.-----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐-----.
| Tab │  j  │  d  │  u  │  a  │  x  │             │  p  │  h  │  l  │  m  │  w  │  ß  |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| C/E │  c  │  t  │  i  │  e  │  o  │             │  b  │  n  │  r  │  s  │  g  │  q  |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| Sft │  f  │  v  │ ß/ü*│ q/ä*│  ö  │             │  y  │  z  │ , ; │ . : │  k  │ Sft |
'-----└─────┴─────┼─────┼─────┼─────┼-----. .-----┼─────┼─────┼─────┼─────┴─────┘-----'
```
*) on 5 column keyboards the missing keys are moved to here. Use the umlauts
from MOUSE layer in that case.

## Base Layout - Colemak DH (german variant)
If COLEMAK_ENABLE is defined, you can switch to the following map
```
.-----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐-----.
| Tab │  q  │  w  │  f  │  p  │  b  │             │  j  │  l  │  u  │  z  │  ö  │  ü  |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| C/E │  a  │  r  │  s  │  t  │  g  │             │  m  │  n  │  e  │  i  │  o  │  ä  |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| Sft │  y  │  x  │  c  │  d  │  v  │             │  k  │  h  │ , ; │ . : │  ß  │ Sft |
'-----└─────┴─────┼─────┼─────┼─────┼-----. .-----┼─────┼─────┼─────┼─────┴─────┘-----'
```

## Base Layout - Mine
If MINE_ENABLE is defined, you can switch to the following map
```
.-----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐-----.
| Tab │  j  │  l  │  u  │  a  │  q  │             │  w  │  b  │  d  │  g  │  y  │  ß  |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| C/E │  c  │  r  │  i  │  e  │  o  │             │  m  │  n  │  t  │  s  │  h  │  z  |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| Sft │  v  │  x  │  ü  │  ä  │  ö  │             │  p  │  f  │ , ; │ . : │  k  │ Sft |
'-----└─────┴─────┼─────┼─────┼─────┼-----. .-----┼─────┼─────┼─────┼─────┴─────┘-----'
```

## Base Layout - Workman
If WORKMAN_ENABLE is defined, you can switch to the following map
```
.-----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐-----.
| Tab │  q  │  w  │  f  │  p  │  b  │             │  j  │  l  │  u  │  z  │  ö  │  ü  |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| C/E │  a  │  r  │  s  │  t  │  g  │             │  m  │  n  │  e  │  i  │  o  │  ä  |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| Sft │  y  │  x  │  c  │  d  │  v  │             │  k  │  h  │ , ; │ . : │  ß  │     |
'-----└─────┴─────┼─────┼─────┼─────┼-----. .-----┼─────┼─────┼─────┼─────┴─────┘-----'
```

# Other layers

## Symbol/Numbers layer
```
.-----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐------.
|     │  @  │  _  │  [  │  ]  │ ^ ° │             │ 0 = │ 1 ! │ 2 " │ 4 $ │ 8 ( │  !   |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------|
|     │  \  │  /  │  {  │  }  │  *  │             │ < > │  (  │  )  │ - _ │  &  │  =   |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------|
|     │ # ' │  $  │  |  │  ~  │  ´  │             │ + * │  %  │  "  │  '  │  €  │      |
'-----└─────┴─────┴─────┼─────┼─────┼-----. .-----┼─────┼─────┼─────┴─────┴─────┘------'
                  |     │  §  │     │     | |     │     │  ¢  │     |
                     ---└─────┴─────┴-----' '-----┴─────┴─────┘---
```
The missing numeric keys can be achieved by means of combos. E.g.
simultaniously pressing 1 and 4 yields 5.

## Navigation/Fn layer
```
.-----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐------.
|     │ PgUp│ BSp │  ↑  │ Del │ PgDn│             │ F10 │  F1 │  F2 │  F4 │  F8 │OsAlt |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------|
|     │ Home│  ←  │  ↓  │  →  │ End │             │OsGui│ F11 │ F12 │OsSft│ RSft│OsCtl |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------|
|     │ Ins │ Cut │ Copy│Paste│PrScr│             │Power│OsAGr│OsMeh│OsHyp│CapsW│CapsW |
'-----└─────┴─────┴─────┼─────┼─────┼-----. .-----┼─────┼─────┼─────┴─────┴─────┘------'
                  |     │ Adj │     │     | |     │ App │ Adj │     |
                     ---└─────┴─────┴-----' '-----┴─────┴─────┘---
```
The missing Fn keys can be achieved by means of combos. E.g. simultaniously
pressing F10 and F2 yields F12.

## Mouse/Media layer
```
.-----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐------.
|     │ vvv │ <<< │  ↑  │ >>> │ ^^^ │             │MsSp+│  ü  │ Vol+│ (v) │Eject│  XXX |
|-----├─────┼─────┼Mouse┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------|
|     │  ä  │  ←  │  ↓  │  →  │Pause│             │MsSpN│ Prev│ Vol-│ XXX │ Next│  XXX |
|-----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤------|
|     │ MB4 │ XXX │  ü  │  ä  │ MB5 │             │MsSp-│ Play│ Mute│ Stop│ Sft │      |
'-----└─────┴─────┴─────┼─────┼─────┼-----. .-----┼─────┼─────┼─────┴─────┴─────┘------'
                  |     │ MB2 │ MB1 │ MB3 | |     │LShft│ MB3 │     |
                     ---└─────┴─────┴-----' '-----┴─────┴─────┘---
```
Scroll up and down buttons are the opposite direction compared to PgUp/PgDn on
navigation layer to achieve a natural scrolling without tweaking the os.

# Copyright
Copyright 2023 Björn Struckmeier bstruckmeier@gmail.com @struckmb

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.


