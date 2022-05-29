# 2048 

* Game 2048 cổ điển

*********************************************
### Hướng dẫn cài đặt

* Cài đặt [Codeblock](https://sourceforge.net/projects/codeblocks/) và SDL2, SDL_image, SDL_ttf.
* Thêm các thư viện đồ hoạ vào build option
* Chạy file project sdl2048.cbp 
* F9 (build and run) để chạy và chơi game

### Mô tả 

Lấy ý tưởng từ game 2048, sử dụng 4 phím [UP], [DOWN], [LEFT], [RIGHT] để di chuyển các ô số và gom lại để đạt được 2048

### Các chức năng

* Màn hình chính của game với board 4x4 
* Âm thanh sinh động, có thể dừng âm bằng nút 9 và resume bằng nút 0
* Hiện điểm hiện tại 
* Lưu điểm cao 
* Có thể chuyển qua New Game trong khi đang chơi hoặc tự động chuyển khi thua
* Thông báo thắng/thua

> Video: [link](https://www.youtube.com/watch?v=0KYItvqyT_s)

### Kỹ thuật đã sử dụng

* Xử lí sự kiện chuột, bàn phím
* Sử dụng các extension của thư viện để tạo màn hình game
* Render chữ lên màn hình với SDL_ttf
* Chèn âm thanh với SDL_mixer

* Sinh số giả ngẫu nhiên 
* Các thư viện chuẩn của C++
* Cách cấp phát động và quản lí bộ nhớ
* Tách file và quản lý file trong project

### Kết luận

> 2048 là tựa game kinh điển đã xuất hiện cách đây khá lâu, và giờ em đã được thử sức làm lại nó với C++ và SDL_2. Mặc dù chưa được hoàn chỉnh các chức năng nhưng em nhận thấy được rằng ngôn ngữ trong lập trình không quá quan trọng, quan trọng là cần hiểu vấn đề cặn kẽ và sử dụng các công cụ một cách hợp lý.
 
Hướng phát triển
* Thêm các kích thước mới nxn cho game
* Thêm cửa sổ lúc vào chơi, hình ảnh cho game
* Lưu lại tên, điểm số của từng người chơi








