import numpy as np

# Số lượng phần tử trong mỗi dãy (1 triệu số thực)
N = 1_000_000

print("Bắt đầu sinh dữ liệu và ghi ra file...")

# 1. Dãy 1: Tăng dần
arr_asc = np.sort(np.random.rand(N))
np.savetxt('day_1_tang_dan.txt', arr_asc, fmt='%.6f')
print("-> Đã tạo: day_1_tang_dan.txt")

# 2. Dãy 2: Giảm dần
arr_desc = np.sort(np.random.rand(N))[::-1]
np.savetxt('day_2_giam_dan.txt', arr_desc, fmt='%.6f')
print("-> Đã tạo: day_2_giam_dan.txt")

# 3. Dãy 3 đến 10: Trật tự hoàn toàn ngẫu nhiên
for i in range(1, 9):
    arr_rand = np.random.rand(N)
    file_name = f'day_{i+2}_ngau_nhien_{i}.txt'
    np.savetxt(file_name, arr_rand, fmt='%.6f')
    print(f"-> Đã tạo: {file_name}")

print("\nHoàn tất! 10 file dữ liệu đã sẵn sàng.")