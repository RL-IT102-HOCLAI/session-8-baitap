1. Phân tích Input / Output
Input	Ý nghĩa
N	Số lượng tài khoản, từ 1 đến 100
account_id	Mã tài khoản
plan_type	0 = Free, 1 = Standard, 2 = Premium
monthly_fee	Phí gói ban đầu, có thể sai lệch
remaining_days	Số ngày còn lại; <= 0 nghĩa là hết hạn
active_devices	Số thiết bị đang kết nối
Output	Ý nghĩa
MRR trước kiểm toán	Tổng monthly_fee ban đầu
Bảng sau kiểm toán	Dữ liệu đã chuẩn hóa và sắp xếp
MRR sau kiểm toán	Tổng phí sau khi hạ cấp và chuẩn hóa
Chênh lệch MRR	MRR trước trừ MRR sau
Quy tắc cần giữ đúng:
- Tài khoản hết hạn (remaining_days <= 0) chuyển về Free, phí bằng 0.
- Tài khoản chưa hết hạn được chuẩn hóa phí theo gói và giới hạn số thiết bị.
- Tài khoản trả phí xếp trước, theo phí giảm dần; các tài khoản cùng phí giữ nguyên thứ tự tương đối ban đầu.
- Dữ liệu active_devices <= 0 được sửa thành 1.
2. Hai giải pháp kỹ thuật
Giải pháp A — Xử lý tại chỗ (in-place)
Kiểm toán trực tiếp trên mảng chính, sau đó dùng các vòng lặp lồng nhau để đưa tài khoản trả phí lên trước và sắp xếp phí giảm dần. Khi đổi chỗ, chỉ đổi khi phần tử đứng sau phải được ưu tiên hơn phần tử đứng trước. Cách này giúp giữ thứ tự của các phần tử có cùng mức phí.
Giải pháp B — Dùng mảng cấu trúc phụ
Tạo hai mảng phụ: một mảng cho tài khoản trả phí, một mảng cho tài khoản Free/hạ cấp. Kiểm toán và phân nhóm, sắp xếp nhóm trả phí rồi ghép lại mảng chính.
Tiêu chí	Giải pháp A: Tại chỗ	Giải pháp B: Mảng phụ
Thời gian sắp xếp	\(O(N^2)\)	\(O(N^2)\) nếu dùng sắp xếp đơn giản
Bộ nhớ phụ	\(O(1)\) ngoài mảng chính	\(O(N)\) cho các mảng phụ
Độ phức tạp mã nguồn	Vừa phải; phải cẩn thận khi đổi chỗ	Cao hơn vì phải phân nhóm và ghép lại
Nguy cơ lỗi vòng lặp	Có thể đổi chỗ sai làm mất tính ổn định	Có thể sai chỉ số hoặc bỏ sót phần tử khi ghép
Phù hợp với giới hạn N <= 100	Rất phù hợp	Cũng phù hợp, nhưng tốn bộ nhớ hơn
Lựa chọn: Giải pháp A. Với tối đa 100 tài khoản, cách sắp xếp tại chỗ đủ nhanh, không cần mảng phụ và dễ kiểm tra hơn khi toàn bộ tài khoản đều trả phí hoặc đều Free.