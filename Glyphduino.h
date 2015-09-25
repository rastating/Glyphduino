// Copyright (C) 2014 rastating
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.

#include "../LiquidCrystal/src/LiquidCrystal.h"

const uint8_t GLYPHDUINO_BATTERY_EMPTY = 0;
const uint8_t GLYPHDUINO_BATTERY_1_BAR = 1;
const uint8_t GLYPHDUINO_BATTERY_2_BAR = 2;
const uint8_t GLYPHDUINO_BATTERY_3_BAR = 3;
const uint8_t GLYPHDUINO_BATTERY_4_BAR = 4;
const uint8_t GLYPHDUINO_BATTERY_FULL = 5;
const uint8_t GLYPHDUINO_HEART = 6;
const uint8_t GLYPHDUINO_HEART_EMPTY = 7;
const uint8_t GLYPHDUINO_CLOCK = 8;
const uint8_t GLYPHDUINO_MUSIC_NOTE = 9;
const uint8_t GLYPHDUINO_DOGECOIN = 10;
const uint8_t GLYPHDUINO_BELL = 11;
const uint8_t GLYPHDUINO_SPEAKER = 12;
const uint8_t GLYPHDUINO_CROSS = 13;
const uint8_t GLYPHDUINO_TICK = 14;
const uint8_t GLYPHDUINO_ARROW_NE = 15;
const uint8_t GLYPHDUINO_ARROW_NW = 16;
const uint8_t GLYPHDUINO_ARROW_SW = 17;
const uint8_t GLYPHDUINO_ARROW_SE = 18;
const uint8_t GLYPHDUINO_LOCK = 19;
const uint8_t GLYPHDUINO_LOCK_UNLOCKED = 20;
const uint8_t GLYPHDUINO_OHM = 21;
const uint8_t GLYPHDUINO_PI = 22;
const uint8_t GLYPHDUINO_BAR_1 = 23;
const uint8_t GLYPHDUINO_BAR_2 = 24;
const uint8_t GLYPHDUINO_BAR_3 = 25;
const uint8_t GLYPHDUINO_BAR_4 = 26;
const uint8_t GLYPHDUINO_BAR_5 = 27;
const uint8_t GLYPHDUINO_BAR_6 = 28;
const uint8_t GLYPHDUINO_BAR_7 = 29;
const uint8_t GLYPHDUINO_THERMO = 30;
const uint8_t GLYPHDUINO_HUM0 = 31;
const uint8_t GLYPHDUINO_HUM50 = 32;
const uint8_t GLYPHDUINO_HUM100 = 33;


class Glyphduino
{
	public:
		Glyphduino(LiquidCrystal *lcd);
		void registerGlyph(uint8_t num, uint8_t glyphId);
		void printGlyph(uint8_t glyphId, int8_t col, int8_t row);
		void printGlyph(uint8_t glyphId);

	private:
		LiquidCrystal *lcd;
		uint8_t registrationMap[8];
		void getGlyph(uint8_t glyphId, unsigned char* array);
};
