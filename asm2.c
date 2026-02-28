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
#include <string.h>

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

// Hàm tính tiền điện theo biểu giá bậc thang
void tinhTienDien(int kwh) {
    double total = 0;

    if (kwh <= 50) {
        total = kwh * 1678;
    } else if (kwh <= 100) {
        total = 50 * 1678 + (kwh - 50) * 1734;
    } else if (kwh <= 200) {
        total = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    } else if (kwh <= 300) {
        total = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
    } else if (kwh <= 400) {
        total = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
    } else {
        total = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;
    }

    printf("So kWh su dung: %d\n", kwh);
    printf("So tien phai tra: %.0f VND\n", total);
}

// Hàm đổi tiền thành các mệnh giá
void doiTien(int tongtien) {
    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int size = sizeof(menhGia) / sizeof(menhGia[0]);

    printf("So tien can doi: %d\n", tongtien);
    printf("Ket qua doi tien:\n");

    for (int i = 0; i < size; i++) {
        int soTo = tongtien / menhGia[i];
        if (soTo > 0) {
            printf("%d to %d\n", soTo, menhGia[i]);
            tongtien %= menhGia[i];
        }
    }
}

// Hàm tính lãi suất vay ngân hàng vay trả góp
void tinhLaiVay(double tienVay) {
    double gocMoiThang = tienVay / 12; // trả đều gốc
    double conLai = tienVay;

    printf("Ky han | Lai phai tra | Goc phai tra | Tong phai tra | So tien con lai\n");
    printf("-----------------------------------------------------------------------\n");

    for (int thang = 1; thang <= 12; thang++) {
        double lai = conLai * 0.05; // 5% mỗi tháng
        double tong = lai + gocMoiThang;
        conLai -= gocMoiThang;

        printf("%2d     | %10.0f   | %10.0f   | %12.0f   | %12.0f\n",
               thang, lai, gocMoiThang, tong, conLai);
    }
}

// Hàm vay tiền mua xe
void vayMuaXe(int percent) {
    double giaXe = 500000000; // 500 triệu
    double traTruoc = giaXe * (100 - percent) / 100.0;
    double soTienVay = giaXe * percent / 100.0;

    int soThang = 24 * 12; // 24 năm = 288 tháng
    double laiThang = 0.072 / 12; // 7.2%/năm = 0.6%/tháng

    // Công thức annuity
    double traHangThang = (soTienVay * laiThang) / (1 - pow(1 + laiThang, -soThang));

    printf("Phan tram vay: %d%%\n", percent);
    printf("So tien tra truoc: %.0f VND\n", traTruoc);
    printf("So tien vay: %.0f VND\n", soTienVay);
    printf("So tien phai tra hang thang trong %d thang: %.0f VND\n", soThang, traHangThang);
}

#define MAX 100

// Khai báo cấu trúc sinh viên
typedef struct {
    char hoten[50];
    double diem;
    char hocluc[20];
} SinhVien;

// Hàm xác định học lực dựa vào điểm
void xep_loai(SinhVien *sv) {
    if (sv->diem >= 9.0)
        strcpy(sv->hocluc, "Xuat sac");
    else if (sv->diem >= 8.0)
        strcpy(sv->hocluc, "Gioi");
    else if (sv->diem >= 6.5)
        strcpy(sv->hocluc, "Kha");
    else if (sv->diem >= 5.0)
        strcpy(sv->hocluc, "Trung binh");
    else
        strcpy(sv->hocluc, "Yeu");
}

// Hàm sắp xếp sinh viên theo điểm giảm dần
void sap_xep(SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

// Hàm hiển thị danh sách sinh viên
void hien_thi(SinhVien sv[], int n) {
    printf("\nDanh sach sinh vien sau khi sap xep:\n");
    printf("%-20s %-10s %-15s\n", "Ho ten", "Diem", "Hoc luc");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10.2f %-15s\n", sv[i].hoten, sv[i].diem, sv[i].hocluc);
    }
}

// Hàm xử lý game FPOLY-LOTT
void fpoly_lott(int so1, int so2) {
    int random1, random2;
    int trung = 0;

    // Sinh số ngẫu nhiên từ 1 đến 15
    srand(time(NULL));
    random1 = rand() % 15 + 1;
    random2 = rand() % 15 + 1;

    printf("\nHe thong sinh ra: %02d va %02d\n", random1, random2);

    // Kiểm tra số trúng
    if (so1 == random1 || so1 == random2) trung++;
    if (so2 == random1 || so2 == random2) trung++;

    // Kết quả
    if (trung == 0) {
        printf("Chuc ban may man lan sau!\n");
    } else if (trung == 1) {
        printf("Chuc mung ban da trung giai NHI!\n");
    } else if (trung == 2) {
        printf("Chuc mung ban da trung giai NHAT!\n");
    }
}

// Định nghĩa struct PhanSo
typedef struct {
    int tu;
    int mau;
} PhanSo;


// Hàm rút gọn phân số
void rutGon(PhanSo *ps) {
    int ucln = uSCLN(ps->tu, ps->mau);
    ps->tu /= ucln;
    ps->mau /= ucln;

    // Đưa dấu âm lên tử
    if (ps->mau < 0) {
        ps->tu = -ps->tu;
        ps->mau = -ps->mau;
    }
}

// Hàm nhập phân số
void nhap(PhanSo *ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    printf("Nhap mau so: ");
    scanf("%d", &ps->mau);

    while (ps->mau == 0) {
        printf("Mau so phai khac 0. Nhap lai: ");
        scanf("%d", &ps->mau);
    }
}

// Hàm in phân số
void in(PhanSo ps) {
    printf("%d/%d", ps.tu, ps.mau);
}

// Hàm cộng
PhanSo cong(PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.tu = a.tu * b.mau + b.tu * a.mau;
    kq.mau = a.mau * b.mau;
    rutGon(&kq);
    return kq;
}

// Hàm trừ
PhanSo tru(PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.tu = a.tu * b.mau - b.tu * a.mau;
    kq.mau = a.mau * b.mau;
    rutGon(&kq);
    return kq;
}

// Hàm nhân
PhanSo nhan(PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.tu = a.tu * b.tu;
    kq.mau = a.mau * b.mau;
    rutGon(&kq);
    return kq;
}

// Hàm chia
PhanSo chia(PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.tu = a.tu * b.mau;
    kq.mau = a.mau * b.tu;
    rutGon(&kq);
    return kq;
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
                int a, b;
                printf("Nhap so nguyen thu nhat: ");
                scanf("%d", &a);
                printf("Nhap so nguyen thu hai: ");
                scanf("%d", &b);
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
                int kwh;
                printf("Nhap so kWh su dung: ");
                scanf("%d", &kwh);
                tinhTienDien(kwh);
                break;
            case 5:
                // Gọi hàm đổi tiền
                printf("DA CHON CHUC NANG 5: DOI TIEN\n");
                int tongtien;
                printf("Nhap tong so tien can doi: ");
                scanf("%d", &tongtien);
                doiTien(tongtien);
                break;
            case 6:
                // Gọi hàm tính lãi suất vay ngân hàng
                printf("DA CHON CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG VAY TRA GOP\n");
                double tienVay;
                printf("Nhap so tien vay: ");
                scanf("%lf", &tienVay);
                tinhLaiVay(tienVay);
                break;
            case 7:
                // Gọi hàm vay tiền mua xe
                printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
                double percent;
                printf("Nhap phan tram vay (0-100): ");
                scanf("%lf", &percent);
                vayMuaXe(percent);
                break;
            case 8:
                // Gọi hàm sắp xếp thông tin sinh viên
                printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");
                SinhVien sv[MAX];
                int n;
                printf("Nhap so luong sinh vien: ");
                scanf("%d", &n);
                getchar(); // loại bỏ ký tự xuống dòng sau scanf
                for (int i = 0; i < n; i++) {
                    printf("Nhap ho ten sinh vien %d: ", i + 1);
                    printf("Ho ten: ");
                    fgets(sv[i].hoten, sizeof(sv[i].hoten), stdin);
                    size_t len = strlen(sv[i].hoten);
                    if (len > 0 && sv[i].hoten[len - 1] == '\n') {
                        sv[i].hoten[len - 1] = '\0'; // loại bỏ ký tự xuống dòng
                    }
                    printf("Diem: ");
                    scanf("%lf", &sv[i].diem);
                    getchar(); // loại bỏ ký tự xuống dòng sau scanf
                    xep_loai(&sv[i]);
                }
           
                sap_xep(sv, n);
                hien_thi(sv, n);
                break;
            
            case 9:
                // Gọi hàm game FPOLY-LOTT
                printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
                int so1, so2;
                printf("Nhap so thu nhat (1-15): ");
                scanf("%d", &so1);
                printf("Nhap so thu hai (1-15): ");
                scanf("%d", &so2);    
                fpoly_lott(so1, so2);
                break;
            case 10:
                // Gọi hàm tính toán phân số
                printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
                PhanSo ps1, ps2;
                printf("Nhap phan so thu nhat:\n");
                nhap(&ps1);

                printf("Nhap phan so thu hai:\n");
                nhap(&ps2);

                PhanSo tong = cong(ps1, ps2);
                PhanSo hieu = tru(ps1, ps2);
                PhanSo tich = nhan(ps1, ps2);
                PhanSo thuong = chia(ps1, ps2);

                printf("\nTong = ");
                in(tong);

                printf("\nHieu = ");
                in(hieu);

                printf("\nTich = ");
                in(tich);

                printf("\nThuong = ");
                in(thuong);
                
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
