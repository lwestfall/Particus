#ifndef LIT_PIXEL
#define LIT_PIXEL

#include <cstdint>

class lit_pixel {
public:
    lit_pixel(uint8_t x, uint8_t y, uint8_t rgb) {
        this->x = x;
        this->y = y;
        this->rgb = rgb;
    }

private:
    uint8_t x;
    uint8_t y;
    uint8_t rgb;
};

#endif /* LIT_PIXEL */
