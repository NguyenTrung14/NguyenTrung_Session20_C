#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 500
typedef struct {
    char maSanPham[20];
    char tenSanPham[100];
    int giaNhap;
    int giaBan;
    int soLuong;
} SanPham;

SanPham danhSachSanPham[MAX_PRODUCTS];
int soLuongSanPham = 0;
int doanhThu = 0;

void fgetChuoi(char *chuoi, int doDai) {
    fgets(chuoi, doDai, stdin);
    if (strlen(chuoi) > 0 && chuoi[strlen(chuoi) - 1] == '\n')
        chuoi[strlen(chuoi) - 1] = '\0';
}

void nhapSanPham() {
    char maSP[20];
    int soLuongNhap;
    printf("Nhap ma san pham: ");
    fgetChuoi(maSP, 20);

    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(danhSachSanPham[i].maSanPham, maSP) == 0) {
            printf("San pham da ton tai, nhap so luong muon them: ");
            scanf("%d", &soLuongNhap);
            getchar();
            danhSachSanPham[i].soLuong += soLuongNhap;
            doanhThu -= soLuongNhap * danhSachSanPham[i].giaNhap;
            return;
        }
    }

    if (soLuongSanPham >= MAX_PRODUCTS) {
        printf("Danh sach san pham da day!\n");
        return;
    }

    strcpy(danhSachSanPham[soLuongSanPham].maSanPham, maSP);
    printf("Nhap ten san pham: ");
    fgetChuoi(danhSachSanPham[soLuongSanPham].tenSanPham, 100);
    printf("Nhap gia nhap: ");
    scanf("%d", &danhSachSanPham[soLuongSanPham].giaNhap);
    printf("Nhap gia ban: ");
    scanf("%d", &danhSachSanPham[soLuongSanPham].giaBan);
    printf("Nhap so luong: ");
    scanf("%d", &danhSachSanPham[soLuongSanPham].soLuong);
    getchar();

    doanhThu -= danhSachSanPham[soLuongSanPham].soLuong * danhSachSanPham[soLuongSanPham].giaNhap;
    soLuongSanPham++;
}

void hienThiSanPham() {
    printf("%-5s %-20s %-30s %-10s %-10s %-10s\n", "STT", "Ma SP", "Ten SP", "Gia Nhap", "Gia Ban", "So Luong");
    for (int i = 0; i < soLuongSanPham; i++) {
        printf("%-5d %-20s %-30s %-10d %-10d %-10d\n", i + 1, danhSachSanPham[i].maSanPham, danhSachSanPham[i].tenSanPham,
               danhSachSanPham[i].giaNhap, danhSachSanPham[i].giaBan, danhSachSanPham[i].soLuong);
    }
}

void capNhatSanPham() {
    char maSP[20];
    printf("Nhap ma san pham can cap nhat: ");
    fgetChuoi(maSP, 20);

    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(danhSachSanPham[i].maSanPham, maSP) == 0) {
            printf("Nhap ten san pham moi: ");
            fgetChuoi(danhSachSanPham[i].tenSanPham, 100);
            printf("Nhap gia nhap moi: ");
            scanf("%d", &danhSachSanPham[i].giaNhap);
            printf("Nhap gia ban moi: ");
            scanf("%d", &danhSachSanPham[i].giaBan);
            printf("Nhap so luong moi: ");
            scanf("%d", &danhSachSanPham[i].soLuong);
            getchar();
            printf("Cap nhat thanh cong!\n");
            return;
        }
    }

    printf("Khong tim thay san pham voi ma da nhap!\n");
}

void sapXepSanPham(int tangDan) {
    for (int i = 0; i < soLuongSanPham - 1; i++) {
        for (int j = i + 1; j < soLuongSanPham; j++) {
            if ((tangDan && danhSachSanPham[i].giaNhap > danhSachSanPham[j].giaNhap) ||
                (!tangDan && danhSachSanPham[i].giaNhap < danhSachSanPham[j].giaNhap)) {
                SanPham temp = danhSachSanPham[i];
                danhSachSanPham[i] = danhSachSanPham[j];
                danhSachSanPham[j] = temp;
            }
        }
    }
}

void timKiemSanPham() {
    char tenSP[100];
    printf("Nhap ten san pham can tim: ");
    fgetChuoi(tenSP, 100);

    printf("%-5s %-20s %-30s %-10s %-10s %-10s\n", "STT", "Ma SP", "Ten SP", "Gia Nhap", "Gia Ban", "So Luong");
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strstr(danhSachSanPham[i].tenSanPham, tenSP)) {
            printf("%-5d %-20s %-30s %-10d %-10d %-10d\n", i + 1, danhSachSanPham[i].maSanPham, danhSachSanPham[i].tenSanPham,
                   danhSachSanPham[i].giaNhap, danhSachSanPham[i].giaBan, danhSachSanPham[i].soLuong);
        }
    }
}

void banSanPham() {
    char maSP[20];
    int soLuongBan;
    printf("Nhap ma san pham can ban: ");
    fgetChuoi(maSP, 20);

    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(danhSachSanPham[i].maSanPham, maSP) == 0) {
            printf("Nhap so luong can ban: ");
            scanf("%d", &soLuongBan);
            getchar();

            if (danhSachSanPham[i].soLuong == 0) {
                printf("San pham da het hang!\n");
                return;
            }

            if (soLuongBan > danhSachSanPham[i].soLuong) {
                printf("Khong du hang de ban!\n");
                return;
            }

            danhSachSanPham[i].soLuong -= soLuongBan;
            doanhThu += soLuongBan * danhSachSanPham[i].giaBan;
            printf("Ban thanh cong!\n");
            return;
        }
    }

    printf("Khong tim thay san pham voi ma da nhap!\n");
}

void hienThiDoanhThu() {
    printf("Doanh thu hien tai: %d\n", doanhThu);
}

int main() {
    int luaChon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Hien thi doanh thu\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        getchar();

        switch (luaChon) {
            case 1:
                nhapSanPham();
                break;
            case 2:
                hienThiSanPham();
                break;
            case 3:
            	nhapSanPham();
            	break;
            case 4:
            	capNhatSanPham();
            	break;
            case 5:{
    			int tangDan;
    			printf("Nhap lua chon (1: Tang dan, 0: Giam dan): ");
   				scanf("%d", &tangDan);
    			sapXepSanPham(tangDan);
    			printf("Danh sach san pham da duoc sap xep!\n");
    			break;
			}
            case 6:
            	timKiemSanPham();
            	break;
            case 7:
            	banSanPham();
            	break;
            case 8:
            	hienThiDoanhThu();
            	break;
            case 9:
            	break;
            default:
            	printf("Lua chon khong hop le ");
        }
		} while(luaChon!=9);
        return 0;
    }
