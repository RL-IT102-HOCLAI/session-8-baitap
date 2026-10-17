1. Phân tích Input / Output
Input	Ý nghĩa
N	Số lượng tài khoản, từ 1 đến 100
user_id	Mã tài khoản
username	Tên tài khoản
plan_type	Gói dịch vụ: 1 = Free, 2 = Personal, 3 = Family
days_overdue	Số ngày nợ cước, không được âm
active_devices	Số thiết bị đang kết nối, không được âm
Output	Ý nghĩa
Bảng tài khoản	Thông tin sau khi xử lý
Phí dịch vụ thực thu	Phí gói sau xử lý cộng phụ thu nếu đủ điều kiện
Tổng doanh thu	Tổng phí thực thu của tất cả tài khoản
Số tài khoản hạ cấp	Số tài khoản bị chuyển về Free do nợ cước
2. Các bước xử lý
1. Nhập số lượng tài khoản N, kiểm tra 1 <= N <= 100.
2. Nhập thông tin từng tài khoản; kiểm tra gói dịch vụ, số ngày nợ và số thiết bị.
3. Gán phí cơ bản theo gói: Free = 0, Personal = 120.000, Family = 250.000 VNĐ.
4. Nếu days_overdue >= 3, hạ gói xuống Free, đặt phí bằng 0 và tăng số tài khoản bị hạ cấp.
5. Sau khi hạ cấp, nếu gói vẫn là Personal và có hơn 1 thiết bị, tính phụ thu 30.000 VNĐ cho mỗi thiết bị vượt giới hạn.
6. Cộng phí thực thu, sau đó in bảng tổng hợp.