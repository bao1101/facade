Module Logger Đa Năng trong C
1. Mô Tả Dự Án
Dự án này triển khai một module logger chuyên nghiệp trong ngôn ngữ C, giải quyết các hạn chế của việc chỉ sử dụng printf() để gỡ lỗi và ghi nhận thông tin trong các ứng dụng thực tế. Hệ thống logger được xây dựng với khả năng linh hoạt, mạnh mẽ, và dễ dàng tích hợp vào bất kỳ dự án C nào, tuân thủ các quy tắc mã sạch và tổ chức module.

Các yêu cầu chính của đề bài được đáp ứng:

Ghi Log Đa Đầu Ra: Hỗ trợ ghi log đồng thời ra màn hình console (sử dụng stderr cho lỗi nghiêm trọng và stdout cho thông thường) và tùy chọn ghi vào một file văn bản.

Lọc Theo Cấp Độ: Cho phép cấu hình mức độ nghiêm trọng tối thiểu của log (LogLevel) để chỉ hiển thị các thông điệp quan trọng, bỏ qua các log có mức độ ưu tiên thấp hơn. Mức lọc có thể thay đổi linh hoạt tại thời điểm chạy.

Tự Động Thêm Metadata: Tự động chèn timestamp, tên file nguồn, và số dòng vào mỗi thông điệp log để dễ dàng truy vết.

Giao Diện Tiện Lợi: Cung cấp một macro log_message(...) đơn giản để người dùng có thể ghi log mà không cần tự điền các thông tin metadata (__FILE__, __LINE__).

2. Cấu Trúc Mã Nguồn
Dự án được tổ chức gọn gàng để dễ đọc và bảo trì:

.
├── include/              # Chứa các file header (.h) của các module
│   └── logger.h          # Header của module logger
├── src/                  # Chứa các file mã nguồn (.c)
│   └── logger.c          # Triển khai module logger
│   └── main.c            # File ví dụ sử dụng logger
├── build/                # Thư mục chứa các file đối tượng (.o) và executable
├── output/               # Thư mục chứa các file log được tạo ra
│   └── application.log   # Ví dụ về file log đầu ra
├── .gitignore            # File cấu hình Git để bỏ qua các file không cần thiết
└── README.md             # File mô tả dự án (bạn đang đọc)
3. Các API, Struct, Element Chính
Dưới đây là các thành phần cốt lõi của module logger:

3.1. Các Mức Log (LogLevel)
Được định nghĩa bằng enum trong logger.h, tuân thủ tiêu chuẩn syslog:

C

typedef enum {
    LOG_EMERGENCY, // System is unusable
    LOG_ALERT,     // Action must be taken immediately
    LOG_CRITICAL,  // Critical conditions
    LOG_ERROR,     // Error conditions
    LOG_WARNING,   // Warning conditions
    LOG_NOTICE,    // Normal but significant condition
    LOG_INFO,      // Informational messages
    LOG_DEBUG      // Debug-level messages
} LogLevel;
3.2. Hàm Khởi Tạo và Giải Phóng Logger
void logger_init(const char *log_file_path, LogLevel initial_level);

Mô tả: Khởi tạo hệ thống logger.

Tham số:

log_file_path: Đường dẫn đến file log. Đặt NULL nếu không muốn ghi log ra file.

initial_level: Mức log tối thiểu sẽ được ghi (các log có mức độ nghiêm trọng thấp hơn sẽ bị bỏ qua).

void logger_shutdown();

Mô tả: Đóng file log và giải phóng các tài nguyên đã được logger sử dụng. Nên được gọi khi ứng dụng kết thúc.

3.3. Hàm Thay Đổi Mức Lọc Log
void logger_set_level(LogLevel new_level);

Mô tả: Thay đổi mức log tối thiểu được chấp nhận bởi logger tại thời điểm chạy.

3.4. Hàm Ghi Log Chính (Không nên gọi trực tiếp)
void logger_log(LogLevel level, const char *file, int line, const char *format, ...);

Mô tả: Hàm lõi thực hiện việc định dạng và ghi log ra console và file.

Lưu ý: Không nên gọi trực tiếp. Thay vào đó, hãy sử dụng macro log_message tiện lợi hơn.

3.5. Macro Tiện Lợi (log_message)
Macro này giúp đơn giản hóa việc ghi log bằng cách tự động thêm thông tin __FILE__ và __LINE__.

C

#define log_message(level, format, ...) \
    logger_log(level, __FILE__, __LINE__, format, ##__VA_ARGS__)
Ví dụ sử dụng:

C

log_message(LOG_INFO, "Ứng dụng bắt đầu.");
log_message(LOG_ERROR, "Không thể kết nối CSDL. Mã lỗi: %d", err_code);
4. Cách Biên Dịch và Chạy Mã Nguồn
Để biên dịch và chạy dự án này, bạn cần có một trình biên dịch C (như GCC).

4.1. Biên dịch
Mở terminal và điều hướng đến thư mục gốc của dự án, sau đó chạy lệnh sau:

Bash

# Tạo thư mục build nếu chưa có
mkdir -p build

# Biên dịch các file nguồn thành các file đối tượng trong thư mục build
gcc -c src/logger.c -o build/logger.o -I./include
gcc -c src/main.c -o build/main.o -I./include

# Liên kết các file đối tượng để tạo executable
gcc build/logger.o build/main.o -o build/my_application
4.2. Chạy
Sau khi biên dịch thành công, bạn có thể chạy ứng dụng từ thư mục build:

Bash

./build/my_application
Khi chạy, các thông điệp log sẽ được in ra console và một file application.log sẽ được tạo (hoặc cập nhật) trong thư mục output/.

5. Flowchart (Luồng Hoạt Động Của Logger)
Đoạn mã

graph TD
    A[Khởi tạo Logger: logger_init(log_file_path, initial_level)] --> B{log_file_path có NULL không?}
    B -- Có --> C[Không ghi ra file]
    B -- Không --> D[Mở log_file ở chế độ append]
    D --> E[Đặt current_log_level = initial_level]
    E --> F[Ghi log: log_message(level, format, ...)]
    F --> G{level > current_log_level?}
    G -- Có --> H[Bỏ qua log]
    G -- Không --> I[Lấy Timestamp hiện tại]
    I --> J[Định dạng Message với vsnprintf]
    J --> K[In ra Console: stdout/stderr]
    K --> L[fflush(Console)]
    L --> M{log_file có NULL không?}
    M -- Có --> N[Kết thúc]
    M -- Không --> O[Ghi vào File Log: log_file]
    O --> P[fflush(log_file)]
    P --> N
    Q[Thay đổi mức log: logger_set_level(new_level)] --> E
    N --> R[Đóng Logger: logger_shutdown()]
    R --> S{log_file có NULL không?}
    S -- Có --> T[Kết thúc]
    S -- Không --> U[Đóng log_file]
    U --> T
Mô tả luồng:

Khởi tạo (logger_init): Thiết lập đường dẫn file log (nếu có) và mức lọc log ban đầu.

Ghi Log (log_message / logger_log):

Macro log_message tự động chèn __FILE__ và __LINE__ và gọi hàm logger_log.

Hàm logger_log đầu tiên kiểm tra xem mức log của thông điệp có thấp hơn mức lọc hiện tại không. Nếu có, thông điệp sẽ bị bỏ qua.

Nếu được phép, hàm sẽ lấy timestamp, định dạng chuỗi thông điệp, và in ra console (stdout hoặc stderr tùy mức độ nghiêm trọng).

Cuối cùng, nếu file log đã được cấu hình, thông điệp cũng sẽ được ghi vào file. fflush được sử dụng để đảm bảo dữ liệu được ghi ngay lập tức.

Thay đổi mức lọc (logger_set_level): Có thể gọi bất cứ lúc nào để thay đổi mức lọc log mà không cần khởi tạo lại logger.

Giải phóng (logger_shutdown): Đóng file log khi ứng dụng kết thúc để đảm bảo tất cả dữ liệu đã được ghi và giải phóng tài nguyên.