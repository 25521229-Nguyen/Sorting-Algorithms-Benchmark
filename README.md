# Đánh giá & So sánh Hiệu năng các Thuật toán Sắp xếp

Dự án thử nghiệm và so sánh thời gian thực thi của 4 thuật toán sắp xếp trên tập dữ liệu 1 triệu số thực double.

Thuật toán thử nghiệm
	1. QuickSort
	2. HeapSort
	3. MergeSort
	4. C++ std::sort (Introsort)

Bộ dữ liệu kiểm thử (10 dãy x 1,000,000 phần tử)
	Dãy 1: Đã sắp xếp tăng dần
	Dãy 2: Đã sắp xếp giảm dần
	Dãy 3 -> 10: Trật tự ngẫu nhiên

Hướng dẫn chạy chương trình

### 1. Tạo dữ liệu thực nghiệm
Chạy file Python để tạo 10 file dữ liệu:
```bash
python scripts/generate_data.py