# Modul ESP8266 with RTC OLED
![](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/picture/01.jpg)

![](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/picture/02.png)

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

### ⚠️ Warning
- Lampu indikator akan tetap "ON" walaupun posisi switch OFF. Agar bisa upload Program pastikan switch digeser ke posisi ON  
- Pastikan install driver  Serial USB terlebih dahulu. Driver menggunakan chip ch340
- Hindari Mengeser posisi Joystick ke kanan karena membuat reset 
- Bila karena suatu keadaan program tidak bisa di program, lepasa dan pasang kabel  yang terhubung ke komputer
- bila ada masalah Serial USB di windows11, maka gunakan komputer dengan OS windows 10 kebawah

### Source code main.c
1. Blinky LED source di [sini](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/src/01-blinky/main.cpp)
2. Test Oled di [sini](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/src/02-oled/main.cpp)
3. Test Wifi di [sini](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/src/03-wifi/main.cpp)

Untuk Test WIFI pastikan mengubah SSID dan password sesuai dengan acces point di tempat anda pada bagian kode:
```C
const char *ssid     = "your-wifi";  
const char *password = "your-password";  
```
Untuk mengetahui IP pastikan cek Serial segera setelah upload program. Pastikan serial monitor dikonfigurasi dengan baudrate 115200


4. Test pcf8563 di [sini](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/src/04-pcf8563/main.cpp). 

Untuk test pcf8563 Menggunakan terminal serial dengan baudrate 115200 8bit Noparity 1 stop bit

5. Test Joystick di [sini](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/src/05-joystick/main.cpp)

Untuk test Joystick Menggunakan terminal serial dengan baudrate 115200 8bit Noparity 1 stop bit. Bisa juga langsung cek tampilan OLED

6. Test Final  di [sini](https://github.com/hwthinker/esp8266-18650-rtc-oled/blob/main/src/06-all/main.cpp)

Untuk Test Final pastikan mengubah SSID dan password sesuai dengan acces point di tempat anda pada bagian kode:

```C
const char *ssid     = "your-wifi";  
const char *password = "your-password";  
```

## Referensi
- https://www.hackster.io/umpheki/esp8266-clock-module-development-board-d6bcfe
