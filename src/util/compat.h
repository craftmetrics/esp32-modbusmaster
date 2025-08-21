
#ifndef _UTIL_COMPAT_H_
#define _UTIL_COMPAT_H_

#include "esp_timer.h"

/** @ingroup util_compat
    Return low byte of a 16-bit integer.

    @param uint16_t ww (0x0000..0xFFFF)
    @return low byte of input (0x00..0xFF)
*/
static inline uint8_t lowByte(uint16_t w)
{
    return (uint8_t)((w)&0xFF);
}

/** @ingroup util_compat
    Return high byte of a 16-bit integer.

    @param uint16_t ww (0x0000..0xFFFF)
    @return high byte of input (0x00..0xFF)
*/
static inline uint8_t highByte(uint16_t w)
{
    return (uint8_t)((w) >> 8);
}

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

uint16_t word(unsigned char h, unsigned char l)
{
    return (h << 8) | l;
}
uint16_t word(unsigned int w)
{
    return w;
}

unsigned long IRAM_ATTR millis()
{
    return (unsigned long) (esp_timer_get_time() / 1000ULL);
}


#endif /* _UTIL_COMPAT_H_ */
