#ifndef _LGT_WDT_H_
#define _LGT_WDT_H_
#include <stdint.h>

//看门狗时钟选择32KHz，arduino启动默认配置
#define WATCHDOG_OFF    (0)
#define WATCHDOG_64MS   (_BV(WDE))
#define WATCHDOG_128MS   (_BV(WDP0) | _BV(WDE))
#define WATCHDOG_256MS   (_BV(WDP1) | _BV(WDE))
#define WATCHDOG_512MS  (_BV(WDP1) | _BV(WDP0) | _BV(WDE))
#define WATCHDOG_1S  (_BV(WDP2) | _BV(WDE))
#define WATCHDOG_2S  (_BV(WDP2) | _BV(WDP0) | _BV(WDE))
#define WATCHDOG_4S     (_BV(WDP2) | _BV(WDP1) | _BV(WDE))
#define WATCHDOG_8S     (_BV(WDP2) | _BV(WDP1) | _BV(WDP0) | _BV(WDE))
#define WATCHDOG_16S     (_BV(WDP3) | _BV(WDE))
#define WATCHDOG_32S     (_BV(WDP3) | _BV(WDP0) | _BV(WDE))

#define wdt_reset() __asm__ __volatile__ ("wdr")

static __inline__
__attribute__ ((__always_inline__))
void wdt_enable(uint8_t x) {
  WDTCSR = _BV(WDCE) | _BV(WDE);
  WDTCSR = x;
}

// Watchdog functions. These are only safe with interrupts turned off.
static __inline__
__attribute__ ((__always_inline__))
void wdt_disable() {
  MCUSR &= ~_BV(WDRF);
  WDTCSR = _BV(WDCE) | _BV(WDE);
  WDTCSR = 0;
}

#endif
