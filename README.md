# 2048 
* Họ và tên: Ngô Thảo Hương
* MSV: 21020338

* Game 2048 cổ điển

*********************************************
# Mục lục
1. [Hướng dẫn cài đặt](#hướng-dẫn-cài-đặt)
2. [Mô tả chung về trò chơi, các ý tưởng chính](https://github.com/nghinn1012/SDL_2048/blob/main/README.md#m%C3%B4-t%E1%BA%A3-chung-v%E1%BB%81-tr%C3%B2-ch%C6%A1i-c%C3%A1c-%C3%BD-t%C6%B0%E1%BB%9Fng-ch%C3%ADnh)
3. [Mô tả các chức năng đã cài đặt](#mô-tả-các-chức-năng-đã-cài-đặt)
4. [Các kỹ thuật lập trình được sử dụng trong chương trình](#các-kỹ-thuật-lập-trình-được-sử-dụng-trong-chương-trình)
5. [Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình](https://github.com/nghinn1012/SDL_2048/blob/main/README.md#k%E1%BA%BFt-lu%E1%BA%ADn-h%C6%B0%E1%BB%9Bng-ph%C3%A1t-tri%E1%BB%83n-v%C3%A0-c%C3%A1c-%C4%91i%E1%BB%81u-t%C3%A2m-%C4%91%E1%BA%AFc-r%C3%BAt-ra-%C4%91%C6%B0%E1%BB%A3c-sau-khi-ho%C3%A0n-thi%E1%BB%87n-ch%C6%B0%C6%A1ng-tr%C3%ACnh)

### Hướng dẫn cài đặt

* Cài đặt [MinGW-W64 GCC-7.3.0-SEH](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-win32/seh/x86_64-7.3.0-release-win32-seh-rt_v5-rev0.7z/download) và [git](https://git-scm.com/downloads).
#### Cài đặt MinGW-W64 (64bit)
* Giải nén file x86_64-7.3.0-release-win32-seh-rt_v5-rev0.7z
* Copy thư mục mingw64 vào (Ví dụ D:\software)
* Cài đặt đường dẫn PATH đến \mingw64\bin
* Kiểm tra bằng cách gọi g++ và mingw32-make trong terminal
#### Clone repository về máy
* Mở một trình Terminal và nhập lần lượt các lệnh  
`$ git clone https://github.com/nghinn1012/SDL_2048`  
`$ cd SDL_2048`  
#### Chạy chương trình 
* Chạy các lệnh sau  
`$ mingw32-make`   
`$ ./SDL_2048.exe`

### Mô tả chung về trò chơi, các ý tưởng chính  

* Game được lấy cảm hứng từ 2048 cổ điển, viết bằng ngôn ngữ C++ và sử dụng thư viện SDL2

#### Luật chơi của game
* Người chơi sẽ được cấp cho một bảng kích cỡ 4x4 với 2 ô số mở đầu, những ô có cùng giá trị sẽ sát nhập vào nhau và tạo ra một ô có giá trị gấp đôi. Nhiệm vụ của người chơi là sát nhập các ô một cách khéo léo để tạo ra ô chiến thắng 2048. Bằng cách

+ Nhấn UP để dồn các ô lên phía trên

+ Nhấn DOWN để dồn các ô xuống phía dưới

+ Nhấn LEFT để dồn các ô sang bên trái

+ Nhấn RIGHT để dồn các ô sang bên phải

+ Nhấn 9 để tạm dừng nhạc

+ Nhấn 0 để tiếp tục nhạc

* Mỗi khi 2 ô cùng giá trị và được sát nhập điểm của người chơi sẽ được công thêm bằng đúng giá trị của ô mới được tạo ra từ việc sát nhập

### Mô tả các chức năng đã cài đặt

#### Màn hình chính của game với board 4x4 
* Cửa sổ chơi cùng tên game "2048"
* Board game 4x4 giống với game 2048 cổ điển
* Các ô điểm mang giá trị 2,4,8,16,32,64,128,256,512,1024,2048 với các màu khác nhau 
#### Âm thanh 
* Âm thanh sinh động, có thể dừng âm bằng nút 9 và resume bằng nút 0
#### Ghi lại điểm
* Hiện điểm hiện tại, cập nhật sau mỗi lần thao tác
* Lưu điểm cao nhất
#### Nút Newgame
* Có thể chuyển qua New Game trong khi đang chơi hoặc tự động chuyển khi thua
#### Thông báo thắng/thua 
* Thắng sẽ in ra "You Win" 
* Thua sẽ in ra "You Lose" và tự động chuyển về NewGame sau đó

> Video: https://www.youtube.com/watch?v=0KYItvqyT_s

### Các kỹ thuật lập trình được sử dụng trong chương trình

* Xử lí sự kiện chuột, bàn phím
* Sử dụng các extension của thư viện để tạo màn hình game
* Render chữ lên màn hình với SDL_ttf
* Chèn âm thanh với SDL_mixer
* Giải phóng bộ nhớ

* Sinh số giả ngẫu nhiên 
* Các thư viện chuẩn của C++
* Sử dụng mảng, con trỏ, string.
* Sử dụng Class
* Cách cấp phát động và quản lí bộ nhớ
* Nhập xuất file
* Tách file và quản lý file trong project

### Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình

#### Kết luận
* Làm game cần đầu tư nhiều thời gian, công sức để tạo ra một game hoàn chỉnh
* Cần chú trọng phát triển những ý tưởng có khả năng, vì có nhiều ý tưởng hay nhưng khó thực thi
* Ngôn ngữ lập trình và thư viện đồ hoạ cơ bản cũng có thể tạo ra game tốt nếu mình biết cách sử dụng

#### Hướng phát triển
* Thêm các kích thước mới nxn cho game
* Thêm cửa sổ lúc vào chơi, hình ảnh cho game
* Lưu lại tên, điểm số của từng người chơi
* Tạo thêm các nút pause, nút tắt âm thanh, nút next level mới
* Cải thiện lại giao diện cho game
* Tạo thêm nút undo lại 1 hoặc nhiều bước trước đó
* Thử sức với các thư viện đồ hoạ khác, cũng như tối ưu lại code

#### Những điều tâm đắc rút ra 

> 2048 là tựa game kinh điển đã xuất hiện cách đây khá lâu, và giờ em đã được thử sức làm lại nó với C++ và SDL_2. Mặc dù chưa được hoàn chỉnh các chức năng nhưng em nhận thấy được rằng ngôn ngữ trong lập trình không quá quan trọng, quan trọng là cần hiểu vấn đề cặn kẽ và sử dụng các công cụ một cách hợp lý. Quan trọng hơn trong quá trình làm game là ta cần biết cách tổ chức, xử lý thành những phần nhỏ để giúp quá trình kiểm tra lại trở nên dễ dàng hơn. Qua đó ta sẽ học được cách tư duy, hiểu được quá trình xây dựng, hoàn thiện game.

### Nguồn tham khảo
* https://lazyfoo.net
* https://wiki.libsdl.org
* https://www.libsdl.org


 









