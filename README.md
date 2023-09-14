# GRBL-ESP32

# Thư viện gốc 
'''
https://github.com/bdring/Grbl_Esp32
'''

# Các lỗi đã fix trong thư viện gốc 
  ## lỗi không tìm thấy #include <hwcrypto/sha.h> trong file WebSocket.cpp tại thư mục .../document/Arduino/library/arduinoWebSocket
    thư mục này copy từ thư mục library từ file được tải từ Thư viện gốc
    thư viện <hwcrypto/sha.h> này hiện không còn được sử dụng trên ESP32 
    -> fix: thay thế bằng
'''
#include <sha/sha_parallel_engine.h>
'''

