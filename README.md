# 2048 

* Game 2048 cổ điển

*********************************************
# Table of contents1. [Hướng dẫn cài đặt](#hướng-dẫn-cài-đặt)
2. [Mô tả chung về trò chơi, các ý tưởng chính](#mô-tả-chung-về-trò-chơi)
3. [Mô tả các chức năng đã cài đặt](#mô-tả-các-chức-năng-đã-cài-đặt)
4. [Các kỹ thuật lập trình được sử dụng trong chương trình](#các-kỹ-thuật-lập-trình-được-sử-dụng-trong-chương-trình)
5. [Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình](https://github.com/nghinn1012/SDL_2048/blob/main/README.md#k%E1%BA%BFt-lu%E1%BA%ADn-h%C6%B0%E1%BB%9Bng-ph%C3%A1t-tri%E1%BB%83n-v%C3%A0-c%C3%A1c-%C4%91i%E1%BB%81u-t%C3%A2m-%C4%91%E1%BA%AFc-r%C3%BAt-ra-%C4%91%C6%B0%E1%BB%A3c-sau-khi-ho%C3%A0n-thi%E1%BB%87n-ch%C6%B0%C6%A1ng-tr%C3%ACnh)

### Hướng dẫn cài đặt

* Cài đặt [MinGW-W64 GCC-7.3.0-SEH](#https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-win32/seh/x86_64-7.3.0-release-win32-seh-rt_v5-rev0.7z/download) và [git](#https://git-scm.com/downloads).
#### Cài đặt MinGW-W64 (64bit)
* Giải nén file x86_64-7.3.0-release-win32-seh-rt_v5-rev0.7z
* Copy thư mục mingw64 vào (Ví dụ D:\software)
* Cài đặt đường dẫn PATH đến \mingw64\bin
* Kiểm tra bằng cách gọi g++ và mingw32-make trong terminal
#### Clone repository về máy
* Mở một trình Terminal và nhập lần lượt các lệnh
'$ git clone https://github.com/nghinn1012/SDL_2048
$ cd SDL_2048'
### Chạy chương trình 
* Chạy các lệnh sau
'$ mingw32-make
$ ./SDL_2048.exe

### Mô tả chung về trò chơi, các ý tưởng chính

Lấy ý tưởng từ game 2048, sử dụng 4 phím [UP], [DOWN], [LEFT], [RIGHT] để di chuyển các ô số và gom lại để đạt được 2048

### Mô tả các chức năng đã cài đặt

* Màn hình chính của game với board 4x4 
* Âm thanh sinh động, có thể dừng âm bằng nút 9 và resume bằng nút 0
* Hiện điểm hiện tại 
* Lưu điểm cao 
* Có thể chuyển qua New Game trong khi đang chơi hoặc tự động chuyển khi thua
* Thông báo thắng/thua

> Video: https://www.youtube.com/watch?v=0KYItvqyT_s

### Các kỹ thuật lập trình được sử dụng trong chương trình

* Xử lí sự kiện chuột, bàn phím
* Sử dụng các extension của thư viện để tạo màn hình game
* Render chữ lên màn hình với SDL_ttf
* Chèn âm thanh với SDL_mixer

* Sinh số giả ngẫu nhiên 
* Các thư viện chuẩn của C++
* Cách cấp phát động và quản lí bộ nhớ
* Tách file và quản lý file trong project

### Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình

> 2048 là tựa game kinh điển đã xuất hiện cách đây khá lâu, và giờ em đã được thử sức làm lại nó với C++ và SDL_2. Mặc dù chưa được hoàn chỉnh các chức năng nhưng em nhận thấy được rằng ngôn ngữ trong lập trình không quá quan trọng, quan trọng là cần hiểu vấn đề cặn kẽ và sử dụng các công cụ một cách hợp lý.
 
Hướng phát triển
* Thêm các kích thước mới nxn cho game
* Thêm cửa sổ lúc vào chơi, hình ảnh cho game
* Lưu lại tên, điểm số của từng người chơi








