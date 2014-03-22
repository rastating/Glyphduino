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

#ifndef Glyphduino_h
#define Glyphduino_h

#include "Arduino.h"
#include "Glyphduino.h"

Glyphduino::Glyphduino(LiquidCrystal *lcd)
{
	this->lcd = lcd;
}

void Glyphduino::getGlyph(uint8_t glyphId, unsigned char* array)
{
	switch (glyphId)
	{
		case GLYPHDUINO_BATTERY_EMPTY:
			array[0] = 0b01110;
			array[1] = 0b11011;
			array[2] = 0b10001;
			array[3] = 0b10001;
			array[4] = 0b10001;
			array[5] = 0b10001;
			array[6] = 0b10001;
			array[7] = 0b11111;
			break;

		case GLYPHDUINO_BATTERY_1_BAR:
			array[0] = 0b01110;
			array[1] = 0b11011;
			array[2] = 0b10001;
			array[3] = 0b10001;
			array[4] = 0b10001;
			array[5] = 0b10001;
			array[6] = 0b11111;
			array[7] = 0b11111;
			break;

		case GLYPHDUINO_BATTERY_2_BAR:
			array[0] = 0b01110;
			array[1] = 0b11011;
			array[2] = 0b10001;
			array[3] = 0b10001;
			array[4] = 0b10001;
			array[5] = 0b11111;
			array[6] = 0b11111;
			array[7] = 0b11111;
			break;

		case GLYPHDUINO_BATTERY_3_BAR:
			array[0] = 0b01110;
			array[1] = 0b11011;
			array[2] = 0b10001;
			array[3] = 0b10001;
			array[4] = 0b11111;
			array[5] = 0b11111;
			array[6] = 0b11111;
			array[7] = 0b11111;
			break;

		case GLYPHDUINO_BATTERY_4_BAR:
			array[0] = 0b01110;
			array[1] = 0b11011;
			array[2] = 0b10001;
			array[3] = 0b11111;
			array[4] = 0b11111;
			array[5] = 0b11111;
			array[6] = 0b11111;
			array[7] = 0b11111;
			break;

		case GLYPHDUINO_BATTERY_5_BAR:
			array[0] = 0b01110;
			array[1] = 0b11011;
			array[2] = 0b11111;
			array[3] = 0b11111;
			array[4] = 0b11111;
			array[5] = 0b11111;
			array[6] = 0b11111;
			array[7] = 0b11111;
			break;

		case GLYPHDUINO_BATTERY_FULL:
			array[0] = 0b01110;
			array[1] = 0b11111;
			array[2] = 0b11111;
			array[3] = 0b11111;
			array[4] = 0b11111;
			array[5] = 0b11111;
			array[6] = 0b11111;
			array[7] = 0b11111;
			break;
	}
}

void Glyphduino::registerGlyph(uint8_t num, uint8_t glyphId)
{
	unsigned char glyph[8];
	this->getGlyph(glyphId, glyph);
	this->lcd->createChar(num, glyph);
	this->registrationMap[num] = glyphId;
}

void Glyphduino::printGlyph(uint8_t glyphId, int8_t col, int8_t row)
{
	uint8_t characterIndex = -1;
	for (uint8_t i = 0; i < 8; i++)
	{
		if (registrationMap[i] == glyphId)
		{
			characterIndex = i;
			break;
		}
	}

	if (characterIndex > -1)
	{
		if (col > -1 && row > -1)
		{
			this->lcd->setCursor(col, row);
		}

		this->lcd->write(characterIndex);
	}
}

void Glyphduino::printGlyph(uint8_t glyphId)
{
	this->printGlyph(glyphId, -1, -1);
}

#endif