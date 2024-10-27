/*
Copyright 2021 @mangoiv

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
*/

#define EE_HANDS
#define GAME_ENABLE

#define POINTING_DEVICE_ROTATION_90

// comment that out if your trackball is on the left side
#define TRACKBALL_RIGHT

#ifdef TRACKBALL_RIGHT
#    define POINTING_DEVICE_INVERT_X
#    define POINTING_DEVICE_INVERT_Y
#endif

#ifdef GAME_ENABLE
#    ifdef LAYER_STATE_8BIT
#        undef LAYER_STATE_8BIT
#        define LAYER_STATE_16BIT
#    endif // LAYER_STATE_8BIT
#endif     // GAME_ENABLE
