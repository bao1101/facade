Hướng dẫn sử dụng Driver LED WS2812B (NeoPixel)
Đây là một driver phần mềm cấp cao được thiết kế để điều khiển các dải đèn LED RGB địa chỉ hóa như WS2812B (NeoPixel). Driver này cung cấp các hàm tiện ích để tạo, quản lý và thao tác dữ liệu màu cho toàn bộ dải LED, sẵn sàng để được gửi đi bởi một vi điều khiển.

1. Cấu trúc Dự án
Dự án bao gồm ba file chính:

led_driver.h: Chứa các định nghĩa API công khai cho driver LED.

led_driver.c: Triển khai logic bên trong của driver LED.

main.c: Chương trình chính dùng để mô phỏng và kiểm thử driver.

2. Định dạng Dữ liệu Màu
Mỗi pixel LED được điều khiển bởi một giá trị uint32_t. Mặc dù là 32-bit, chỉ 24 bit thấp hơn được sử dụng để định nghĩa màu sắc theo thứ tự Green (G), Red (R), Blue (B).

Định dạng 24-bit trong uint32_t (0x00GGRRBB):

Bit (31-24)

Bit (23-16)

Bit (15-8)

Bit (7-0)

Không sử dụng

Green (8 bits)

Red (8 bits)

Blue (8 bits)

0x00

0-255

0-255

0-255

3. Các Hàm API của Driver (led_driver.h)
3.1. Khởi tạo và Giải phóng
int led_init(size_t num_pixels);

Khởi tạo một bộ đệm cho dải LED với số lượng pixel đã cho.

Trả về 0 nếu thành công, -1 nếu thất bại (ví dụ: cấp phát bộ nhớ không thành công). Bộ đệm sẽ được khởi tạo về màu đen (0x00000000).

void led_shutdown();

Giải phóng bộ nhớ đã được cấp phát cho dải LED, ngăn ngừa rò rỉ bộ nhớ.

3.2. Đặt Màu Pixel
void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b);

Đặt màu cho một pixel cụ thể tại index đã cho.

Sử dụng ba giá trị 8-bit riêng biệt cho Red, Green và Blue.

Hàm sẽ bỏ qua nếu index không hợp lệ (ngoài phạm vi 0 đến num_pixels - 1).

3.3. Các Hàm Tiện ích
void led_fill(uint8_t r, uint8_t g, uint8_t b);

Điền toàn bộ dải LED với một màu duy nhất.

void led_clear();

Tắt tất cả các pixel (bằng cách đặt màu của chúng thành màu đen (0, 0, 0)).

const uint32_t* led_get_buffer();

Lấy một con trỏ hằng (chỉ đọc) tới bộ đệm dữ liệu, sẵn sàng để được "gửi" đi. Hàm này chủ yếu dùng cho mục đích kiểm thử.

size_t led_get_pixel_count();

Lấy số lượng pixel trên dải LED đã được khởi tạo. Trả về 0 nếu dải chưa được khởi tạo.

4. Cách Biên dịch và Chạy
Để biên dịch dự án, bạn có thể sử dụng GCC (GNU Compiler Collection):

Bash

gcc -o led_test main.c led_driver.c -Wall -Wextra -std=c11
-o led_test: Đặt tên file thực thi là led_test.

main.c led_driver.c: Các file mã nguồn cần biên dịch.

-Wall -Wextra: Bật tất cả các cảnh báo phổ biến và bổ sung để phát hiện các lỗi tiềm ẩn.

-std=c11: Biên dịch mã theo chuẩn C11.