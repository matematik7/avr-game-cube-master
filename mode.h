/* File: mode.h
 * Everything for mode management
 */
/* Copyright (c) 2012-2013 Domen Ipavec (domen.ipavec@z-v.si)
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
 
#ifndef MODE_H
#define MODE_H

#include <stdint.h>

#include "display.h"

#define NUM_MODES 8

typedef void (*action)(uint8_t event);

class Mode {
 public:
	DisplaySettings ds;
	uint16_t irDelay;
	uint8_t packet;
	uint8_t irBroken;
	uint8_t laps;
	action event;

	static const uint8_t EVENT_MASTER_BROKEN = 0;
	static const uint8_t EVENT_SLAVE_BROKEN = 1;
	static const uint8_t EVENT_MS10 = 2;
	static const uint8_t EVENT_MASTER_BUTTON = 3;
	static const uint8_t EVENT_SLAVE_BUTTON = 4;
};

Mode * getMode(uint8_t i);

#endif
