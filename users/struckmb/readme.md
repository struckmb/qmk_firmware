# Base Layers

## Home row mod, thumb keys and 6th rows
```
 -----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐-----
| Tab │     │     │     │     │     │             │     │     │     │     │     │     |
 -----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----
| C/E │     │     │(Gui)│(Ctl)│(Alt)│             │(Alt)│(Ctl)│(Gui)│     │(Adj)│(Alt)|
 -----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----
| Sft │(Sft)│     │     │     │     │             │     │     │     │     │(Sft)│(RSh)|
 -----└─────┴─────┼─────┼─────┼─────┼-----   -----┼─────┼─────┼─────┼─────┴─────┘-----
```

## Base Layout - QWERTZ
If QWERTZ_ENABLE is defined, you can switch to the following map using QWERTZ
```
 -----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐-----.
| Tab │  q  │  w  │  e  │  r  │  t  │             │  z  │  u  │  i  │  o  │  p  │  ü  |
 -----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| C/E │  a  │  s  │  d  │  f  │  g  │             │  h  │  j  │  k  │  l  │  ö  │  ä  |
 -----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----|
| Sft │  y  │  x  │  c  │  v  │  b  │             │  n  │  m  │ , ; │ . : │ ß ? │     |
 -----└─────┴─────┼─────┼─────┼─────┼-----   -----┼─────┼─────┼─────┼─────┴─────┘-----'
```

## Base Layout - BONE (matrix)
If BONEM_ENABLE is defined, you can switch to the following map using BONEM
```
 -----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐-----
| Tab │  j  │  d  │  u  │  a  │  x  │             │  p  │  h  │  l  │  m  │  w  │  ß  |
 -----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----
| C/E │  c  │  t  │  i  │  e  │  o  │             │  b  │  n  │  r  │  s  │  g  │  q  |
 -----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----
| Sft │  f  │  v  │ ü/ß*│ ä/q*│  ö  │             │  y  │  z  │ , ; │ . : │  k  │     |
 -----└─────┴─────┼─────┼─────┼─────┼-----   -----┼─────┼─────┼─────┼─────┴─────┘-----
```
*) on 5 column keyboards the missing keys are moved to here. Use the umlauts
from layer MOUSE in this case

## Base Layout - Colemak DH (german variant)
If COLEMAK_ENABLE is defined, you can switch to the following map using COLMAK
```
 -----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐-----
| Tab │  q  │  w  │  f  │  p  │  b  │             │  j  │  l  │  u  │  z  │  ö  │  ü  |
 -----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----
| C/E │  a  │  r  │  s  │  t  │  g  │             │  m  │  n  │  e  │  i  │  o  │  ä  |
 -----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----
| Sft │  y  │  x  │  c  │  d  │  v  │             │  k  │  h  │ , ; │ . : │  ß  │     |
 -----└─────┴─────┼─────┼─────┼─────┼-----   -----┼─────┼─────┼─────┼─────┴─────┘-----
```

## Base Layout - Lilypond
If LILYPOND_ENABLE is defined, you can switch to the following map using LILYPOND
```
 -----┌─────┬─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┬─────┐-----
| Tab │  q  │  w  │  j  │  r  │  t  │             │  z  │  u  │  l  │  o  │  p  │  ü  |
 -----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----
| C/E │  h  │  c  │  d  │  e  │  i  │             │  s  │  f  │  g  │  a  │  b  │  ä  |
 -----├─────┼─────┼─────┼─────┼─────┤             ├─────┼─────┼─────┼─────┼─────┤-----
| Sft │  y  │  x  │  k  │  v  │  ö  │             │  n  │  m  │ , ; │ . : │  ß  │     |
 -----└─────┴─────┼─────┼─────┼─────┼-----   -----┼─────┼─────┼─────┼─────┴─────┘-----
```


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


