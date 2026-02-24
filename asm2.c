/******************************************************************************
 * Họ và tên: [Huỳnh Khánh Nam]
 * MSSV:      [PS43500]
 * Lớp:       [COM108 - CS21302]
 *****************************************************************************/

// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Hàm kiểm tra và in kết quả cho số x
void checkNumber(float x) {
    // Kiểm tra số nguyên
    if (x == (int)x) {
        int xi = (int)x;
        printf("%g la so nguyen.\n", x);

        // Kiểm tra số nguyên tố
        bool prime = true;
        if (xi < 2) prime = false;
        else {
            for (int i = 2; i <= sqrt(xi); i++) {
                if (xi % i == 0) {
                    prime = false;
                    break;
                }
            }
        }
        if (prime) printf("%d la so nguyen to.\n", xi);
        else printf("%d khong phai la so nguyen to.\n", xi);

        // Kiểm tra số chính phương
        int root = (int)sqrt(xi);
        if (root * root == xi) {
            printf("%d la so chinh phuong.\n", xi);
        } else {
            printf("%d khong phai la so chinh phuong.\n", xi);
        }

    } else {
        printf("%g khong phai la so nguyen.\n", x);
    }
}
// Hàm tìm USCLN bằng thuật toán Euclid
int uSCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm tìm BCNN dựa vào USCLN
int bCNN(int a, int b) {
    return (a * b) / uSCLN(a, b);
}

// Hàm tính tiền
void tinhTien(int start, int end) {
    // Kiểm tra hợp lệ
    if (start < 12 || end > 23 || start >= end) {
        printf("Gio khong hop le! Quan chi hoat dong tu 12h den 23h.\n");
        return;
    }

    int hours = end - start;
    double total = 0;

    // Tính tiền theo số giờ
    if (hours <= 3) {
        total = hours * 150000;
    } else {
        total = 3 * 150000 + (hours - 3) * (150000 * 0.7);
    }

    // Giảm thêm 10% nếu giờ bắt đầu từ 14h đến 17h
    if (start >= 14 && start <= 17) {
        total *= 0.9;
    }

    // In kết quả
    printf("Tong so gio: %d\n", hours);
    printf("So tien can thanh toan: %.0f VND\n", total);
}


int main() {
    int chonChucNang;
    
    do {
        printf("Chon chuc nang:\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang) {
            case 1:
                // Gọi hàm kiểm tra số nguyên
                printf("DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN\n");
                printf("Nhap vao mot so: ");
                float x;
                scanf("%f", &x);
                checkNumber(x);
                break;
            case 2:
                // Gọi hàm tìm Ước số chung và bội số chung
                printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
                printf("Nhap hai so nguyen: ");
                int a, b;
                scanf("%d %d", &a, &b);
                printf("USCLN cua %d va %d la: %d\n", a, b, uSCLN(a, b));
                printf("BCNN cua %d va %d la: %d\n", a, b, bCNN(a, b));
                break;
            case 3:
                // Gọi hàm tính tiền cho quán Karaoke
                printf("DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE\n");
                int start, end;
                printf("Nhap gio bat dau (12-23): ");
                scanf("%d", &start);
                printf("Nhap gio ket thuc (12-23): ");
                scanf("%d", &end);
                tinhTien(start, end);
                break;
            case 4:
                // Gọi hàm tính tiền điện
                printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
                break;
            case 5:
                // Gọi hàm đổi tiền
                printf("DA CHON CHUC NANG 5: DOI TIEN\n");
                break;
            case 6:
                // Gọi hàm tính lãi suất vay ngân hàng
                printf("DA CHON CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG VAY TRA GOP\n");
                break;
            case 7:
                // Gọi hàm vay tiền mua xe
                printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
                break;
            case 8:
                // Gọi hàm sắp xếp thông tin sinh viên
                printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");
                break;
            case 9:
                // Gọi hàm game FPOLY-LOTT
                printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
                break;
            case 10:
                // Gọi hàm tính toán phân số
                printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (chonChucNang != 0);

    return 0;
}