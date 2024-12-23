#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
typedef struct {
    char maSach[20];
    char tenSach[100];
    char tacGia[100];
    float giaTien;
    char theLoai[50];
} Book;

Book books[MAX_BOOKS];
int bookCount = 0;

void nhapThongTinSach() {
    printf("Nhap so luong sach: ");
    scanf("%d", &bookCount);
    getchar(); // Xoa ky tu \n trong bo dem

    for (int i = 0; i < bookCount; i++) {
        printf("\nNhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        fgets(books[i].maSach, 20, stdin);
        books[i].maSach[strcspn(books[i].maSach, "\n")] = '\0';

        printf("Ten sach: ");
        fgets(books[i].tenSach, 100, stdin);
        books[i].tenSach[strcspn(books[i].tenSach, "\n")] = '\0';

        printf("Tac gia: ");
        fgets(books[i].tacGia, 100, stdin);
        books[i].tacGia[strcspn(books[i].tacGia, "\n")] = '\0';

        printf("Gia tien: ");
        scanf("%f", &books[i].giaTien);
        getchar();

        printf("The loai: ");
        fgets(books[i].theLoai, 50, stdin);
        books[i].theLoai[strcspn(books[i].theLoai, "\n")] = '\0';
    }
}

void hienThiThongTinSach() {
    printf("\nDanh sach cac sach:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("\nSach thu %d:\n", i + 1);
        printf("Ma sach: %s\n", books[i].maSach);
        printf("Ten sach: %s\n", books[i].tenSach);
        printf("Tac gia: %s\n", books[i].tacGia);
        printf("Gia tien: %.2f\n", books[i].giaTien);
        printf("The loai: %s\n", books[i].theLoai);
    }
}

void themSachVaoViTri() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nDanh sach sach da day!\n");
        return;
    }

    int viTri;
    printf("\nNhap vi tri muon them (tu 1 den %d): ", bookCount + 1);
    scanf("%d", &viTri);
    getchar();

    if (viTri < 1 || viTri > bookCount + 1) {
        printf("\nVi tri khong hop le!\n");
        return;
    }

    for (int i = bookCount; i >= viTri; i--) {
        books[i] = books[i - 1];
    }

    printf("\nNhap thong tin sach moi:\n");
    printf("Ma sach: ");
    fgets(books[viTri - 1].maSach, 20, stdin);
    books[viTri - 1].maSach[strcspn(books[viTri - 1].maSach, "\n")] = '\0';

    printf("Ten sach: ");
    fgets(books[viTri - 1].tenSach, 100, stdin);
    books[viTri - 1].tenSach[strcspn(books[viTri - 1].tenSach, "\n")] = '\0';

    printf("Tac gia: ");
    fgets(books[viTri - 1].tacGia, 100, stdin);
    books[viTri - 1].tacGia[strcspn(books[viTri - 1].tacGia, "\n")] = '\0';

    printf("Gia tien: ");
    scanf("%f", &books[viTri - 1].giaTien);
    getchar();

    printf("The loai: ");
    fgets(books[viTri - 1].theLoai, 50, stdin);
    books[viTri - 1].theLoai[strcspn(books[viTri - 1].theLoai, "\n")] = '\0';

    bookCount++;
}

void xoaSachTheoMaSach() {
    char maSach[20];
    printf("\nNhap ma sach can xoa: ");
    fgets(maSach, 20, stdin);
    maSach[strcspn(maSach, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].maSach, maSach) == 0) {
            found = 1;
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            printf("\nDa xoa sach co ma %s.\n", maSach);
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay sach co ma %s.\n", maSach);
    }
}

void capNhatThongTinSach() {
    char maSach[20];
    printf("\nNhap ma sach can cap nhat: ");
    fgets(maSach, 20, stdin);
    maSach[strcspn(maSach, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].maSach, maSach) == 0) {
            found = 1;
            printf("\nNhap thong tin moi cho sach:\n");
            printf("Ten sach: ");
            fgets(books[i].tenSach, 100, stdin);
            books[i].tenSach[strcspn(books[i].tenSach, "\n")] = '\0';

            printf("Tac gia: ");
            fgets(books[i].tacGia, 100, stdin);
            books[i].tacGia[strcspn(books[i].tacGia, "\n")] = '\0';

            printf("Gia tien: ");
            scanf("%f", &books[i].giaTien);
            getchar();

            printf("The loai: ");
            fgets(books[i].theLoai, 50, stdin);
            books[i].theLoai[strcspn(books[i].theLoai, "\n")] = '\0';

            printf("\nDa cap nhat thong tin sach.\n");
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay sach co ma %s.\n", maSach);
    }
}

void sapXepSachTheoGia(int tangDan) {
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = i + 1; j < bookCount; j++) {
            if ((tangDan && books[i].giaTien > books[j].giaTien) ||
                (!tangDan && books[i].giaTien < books[j].giaTien)) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("\nDa sap xep sach theo gia.\n");
}

void timKiemSachTheoTen() {
    char tenSach[100];
    printf("\nNhap ten sach can tim: ");
    fgets(tenSach, 100, stdin);
    tenSach[strcspn(tenSach, "\n")] = '\0';

    int found = 0;
    printf("\nKet qua tim kiem:\n");
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].tenSach,"%s")) {
			printf("\nMa sach: %s\n", books[i].maSach);
			printf("Ten sach: %s\n", books[i].tenSach);
			printf("Tac gia: %s\n", books[i].tacGia);
			printf("Gia tien: %.2f\n", books[i].giaTien);
			printf("The loai: %s\n", books[i].theLoai);
			found = 1;
		}
	};
	if (!found) {
		printf("\nKhong tim thay sach co ten %s.\n", tenSach);
		}
	}
	void menu() {
	int choice;
	do {
	printf("\nMENU\n");
	printf("1. Nhap thong tin sach\n");
	printf("2. Hien thi thong tin sach\n");
	printf("3. Them sach vao vi tri\n");
	printf("4. Xoa sach theo ma sach\n");
	printf("5. Cap nhat thong tin sach\n");
	printf("6. Sap xep sach theo gia\n");
	printf("7. Tim kiem sach theo ten\n");
	printf("8. Thoat\n");
	printf("Lua chon cua ban: ");
	scanf("%d", &choice);
	getchar(); 
	switch (choice) {
		case 1:
			nhapThongTinSach();
			break;
		case 2:
			hienThiThongTinSach();
			break;
		case 3:
			themSachVaoViTri();
			break;
		case 4:
			xoaSachTheoMaSach();
			break;
		case 5:
			capNhatThongTinSach();
			break;
		case 6: {
			int tangDan;
			printf("\nNhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
			scanf("%d", &tangDan);
			getchar();
			sapXepSachTheoGia(tangDan);
			break; 
			}
		case 7:
			timKiemSachTheoTen();
			break;
		case 8:
			printf("\nThoat chuong trinh.\n");
			break;
		default:
			printf("\nLua chon khong hop le!\n");
			}
		} while (choice != 8);
		}
int main() {
	menu();
	return 0;
}
