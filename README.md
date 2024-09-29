# Modul ESP8266 with RTC OLED
![](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/picture/01.jpg)


## koneksi
### LED Board
| Perangkat   | GPIO |
|-------------|------|
| LED Board   | 16   | 
| LED ESP     | 2    |

### Joystick
| Tombol               | GPIO |
|----------------------|------|
| Joystick LEFT Button  | 0    |
| Joystick RIGHT Button | x (reset)   |
| Joystick UP Button    | 12   | 
| Joystick DOWN Button  | 13   | 
| Joystick TOP Button   | 14   |

### PCF8563 (RTC)
| Perangkat  | GPIO |
|------------|------|
| PCF8563 SDA| 0    | 
| PCF8563 SCL| 2    |

### OLED Display
| Perangkat | GPIO |
|-----------|------|
| OLED SDA  | 5    | 
| OLED SCL  | 4    |

Source bisa dicek 
1. Blinky LED source di [sini](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/src/01-blinky/main.cpp)
1. Test Oled di [sini](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/src/02-oled/main.cpp)
1. Test Wifi di [sini](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/src/03-wifi/main.cpp)
1. Test pcf8563 di [sini](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/src/04-pcf8563/main.cpp)
1. Test Joystick di [sini](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/src/05-joystick/main.cpp)
1. Test Final  di [sini](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/src/06-all/main.cpp)



