#pragma once
#include<cstdint>
class Color {
private:
	uint32_t rgba;
public:
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	Color(uint8_t r, uint8_t b, uint8_t g) {
		red = r;
		green = g;
		blue = b;
	}
	//TODO:	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) {}

};