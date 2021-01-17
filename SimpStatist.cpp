#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <graphics.h>
#include <unistd.h>
using namespace std;
struct giatrii{
	int giatri;
	int tanso;
	int tungdo;
	bool hl;
};
	int i, j;
int main(int argc, char *argv[]) {
	srand(time(0));
	int n = 0, demtc = 0;
	bool osk = false;
	string s;
	while (!osk) {
		cout << "So gia tri cua dau hieu la (luu y chi nhap so nguyen duong): ";
		cin >> s;
		osk = true;
		if ((s[0]) < '1' || (s[0] > '9')) osk = false;
		for (j = 1; j < s.size(); j++) {
				if ((s[j] < '0') || (s[j] > '9')) {
					osk = false;
			}  
		}
	}
	n = atoi(s.c_str());
	cout << endl;
	int* a = new int [n];
	for (i = 0; i < n; i++) {
		string s;
		bool ok = false;
		while (!ok) {
			cout << "So thu " << i + 1 << " la (luu y chi nhap so tu nhien): ";
			cin >> s;
			ok = true;
			for (j = 0; j < s.size(); j++) {
					if ((s[j] < '0') || (s[j] > '9')) {
						ok = false;
				}  
			}
		}
		a[i] = atoi(s.c_str());
		cout << endl;
	}
	giatrii* bangtt = new giatrii [n];
	for (i = 0; i < n; i++) {
		bool kt = false;
		int ntt;
		while (kt != true) {
			int ntt1 = 1 + rand() % (1000 + (-1) + 1);
			kt = true;
			for (j = 0; j < n; j++) {
				if (ntt1 == a[j]) {
					kt = false;
					break;
				}
			}
			ntt = ntt1;
		}
		bangtt[i].giatri = ntt;
		bangtt[i].tanso = ntt;
		bangtt[i].hl = false;
	}
	
	
	
	for (i = 0; i < n; i++) {
		bool ok = true;
		for (j = 0; j < n; j++) {
			if (a[i] == bangtt[j].giatri) {
				ok = false;
				break;
			}
		}
		
		if (ok == true) {
			bangtt[i].giatri = a[i];
			int demcb = 0;
			for (j = i; j < n; j++) {
				if (a[i] == a[j]) {
					demcb += 1;
				}
			}
			bangtt[i].tanso = demcb;
			demtc++;
			bangtt[i].hl = true;
		}
	}
	
	
	
	
	giatrii* bang = new giatrii [demtc];
	int dem = 0;
	for (i = 0; i < n; i++) {
		if (bangtt[i].hl > 0) {
			bang[dem].giatri = bangtt[i].giatri;
			bang[dem].tanso = bangtt[i].tanso;
			dem += 1;
		}
	}
	

	delete[]bangtt;
	
	cout << "Bang tan so: " << endl;
	
	
	cout << "_______________";
	for (i = 0; i < demtc; i++) {
		 cout << "__________";
	}
	cout << "__________";
	cout << endl;
	cout << "| Gia tri (x) |";
	for (i = 0; i < demtc; i++) {
		cout << " " << bang[i].giatri;
		int med = 0, bientt = bang[i].giatri;
		while (bientt != 0) {
			bientt /= 10;
			med++;
		}
		for (int i = 1; i <= 8 - med; i++) {
			cout << " ";
		}
		cout << "|";
	}
	cout << "         |";
	cout << endl;
	cout << "_______________";
	for (i = 0; i < demtc; i++) {
		cout << "__________";
	}
	cout << "__________";
	cout << endl;
	cout << "| Tanso (y)   |";
	for (i = 0; i < demtc; i++) {
		cout << " " << bang[i].tanso;
		int med = 0, bientt = bang[i].tanso;
		while (bientt != 0) {
			bientt /= 10;
			med++;
		}
		for (int i = 1; i <= 8 - med; i++) {
			cout << " ";
		}
		cout << "|";
	}
	cout << " " << "N = " << n;
	int med = 0, bientt = n;
	while (bientt != 0) {
		bientt /= 10;
		med++;
	}
	for (int i = 1; i <= 8 - med - 4; i++) {
		cout << " ";
	}
	cout << "|";
	cout << endl;
	
	cout << "_______________";
	
	for (i = 0; i < demtc; i++) {
		cout << "__________";
	}
	cout << "__________";
	cout << endl;
	cout << "Co " << demtc << " nhom gia tri khac nhau" << endl;
	
	
	
	int max = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	cout << "Gia tri lon nhat la: " << max << endl;
	
	
	
	int min = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	cout << "Gia tri nho nhat la: " << min << endl;
	
	
	
	int maxts = bang[0].tanso, vt = 0;
	bool yon = true;
	for (i = 1; i < demtc; i++) {
		if (bang[i].tanso > maxts) {
			maxts = bang[i].tanso;
			vt = i;
		}
		if (bang[i].tanso == maxts) {
			yon = false;
		}
	}
	
	
	
	if (yon == true) cout << "Gia tri co tan so lon nhat (mot) la: " << bang[vt].giatri << endl;
	else {
		cout << "Cac gia tri co tan so lon nhat (mot) la: ";
		for (i = 0; i < demtc; i++) {
			if (bang[i].tanso == maxts) {
				if (i = demtc - 1) {
					cout << bang[i].giatri;
				} else {
					cout << bang[i].giatri << ", ";
				}
			}
		}
	}
	cout << endl;
	
	
	
	float t = 0;
	for (i = 0; i < demtc; i++) {
		t += bang[i].giatri * bang[i].tanso;
	}
	cout << "So trung binh cong la: " << double(t / n) << endl;
	
	
	
	int* arr = new int [demtc];
	for (i = 0; i < demtc; i++) {
		arr[i] = bang[i].tanso;
	}
	
	
	
	for (i = 0; i < demtc - 1; i++) {
		for (j = i + 1; j < demtc; j++) {
			if (arr[i] > arr[j]) {
				int tg = arr[i];
				arr[i] = arr[j];
				arr[j] = tg;
			}
		}
	}
	
	
	
	for (i = 0; i < demtc; i++) {
		for (j = 0; j < demtc; j++) {
			if (arr[i] == bang[j].tanso) {
				bang[j].tungdo = i;
			}
		}
	}
	
	
	
	
	
	int** td = new int* [demtc];
	for (i = 0; i < demtc; i++) {
		td[i] = &bang[i].tungdo;
	}
	
	
	
	for (i = 0; i < demtc - 1; i++) {
		for (j = i + 1; j < demtc; j++) {
			if (*(td[i]) > *(td[j])) {
				int* tg = td[i];
				td[i] = td[j];
				td[j] = tg;
			}
		}
	}
	
	
	
	if (*(td[0]) > 0) {
		int st = *(td[0]);
		for (i = 0; i < demtc; i++) {
			*(td[i]) = *(td[i]) - st;
		}
	}
	
	
	
	for (i = 1; i < demtc; i++) {
		if (*(td[i - 1]) != *(td[i]) - 1 && *(td[i]) != *(td[i - 1])) {
			int st2 = *(td[i]) - (*(td[i - 1]) + 1);
			for (j = i; j < demtc; j++) {
				*(td[j]) = *(td[j]) - st2;
			}
		}
	}
	
	
	
	int demtc2 = *(td[demtc - 1]) + 1;
	giatrii* dembang = new giatrii [demtc2];
	for (i = 0; i < demtc2; i++) {
		bool ktt = false;
		int nttt;
		while (ktt != true) {
			int nttt1 = 1 + rand() % (100 + (-1) + 1);
			ktt = true;
			for (j = 0; j < demtc; j++) {
				if (nttt1 == *(td[i])) {
					ktt = false;
					break;
				}
			}
			nttt = nttt1;
		}
		dembang[i].giatri = nttt;
		dembang[i].tanso = nttt;
	}
	int demmm = -1;
	for (i = 0; i < demtc; i++) {
		bool okk = true;
		for (j = 0; j < demtc2; j++) {
		if (*(td[i]) == dembang[j].giatri) {
			okk = false;
			break;
		}
	}
	
		if (okk == true) {
			demmm++;
			dembang[demmm].giatri = *(td[i]);
			int demcb = 0;
			for (j = i; j < demtc; j++) {
			if (dembang[demmm].giatri == *(td[j])) {
				demcb += 1;
			}
		}
		dembang[demmm].tanso = demcb;
		}
	}
	int* y2 = new int [demtc2];
	for (i = 0; i < demtc2; i++) {
		bool ktt = false;
		int nttt;
		while (ktt != true) {
			int nttt1 = 1 + rand() % (100 + (-1) + 1);
			ktt = true;
			for (j = 0; j < demtc; j++) {
				if (nttt1 == arr[i]) {
					ktt = false;
					break;
				}
			}
			nttt = nttt1;
		}
		y2[i] = nttt;
	}
	demmm = -1;
	for (i = 0; i < demtc; i++) {
		bool okk = true;
		for (j = 0; j < demtc2; j++) {
		if (arr[i] == y2[j]) {
			okk = false;
			break;
		}
	}
	
		if (okk == true) {
			demmm++;
			y2[demmm] = arr[i];
		}
	}
	
	cout << "Bieu do: (xuat hien sau 3 giay)" << endl;
	sleep(3);
	






	
	
	initwindow(700, 700);			
	setbkcolor(15);					
   	cleardevice();
	setcolor(0);					
	line(0, 700 - 50, 50, 700 - 50);
	line(50, 700, 50, 700 - 50);
	settextstyle(4, 1, 1);
	outtextxy(40, 700 - 40, "O");
	int x = 20, y = 700 - 50, x1 = 50, y1 = 700 - 50;
	for (i = 0; i < demtc; i++) {
		x += 30;
		x1 += 30;
		line(x, y, x1, y1);
		moveto(x1, y1);
		lineto(x1, y1 - 10);
		moveto(x1, y1);
		lineto(x1, y1 + 10);
		line(x1, y1, x1, y1 - (30 * (bang[i].tungdo + 1)));
		setlinestyle(0, 0, 3);
		putpixel(x1, y1 - (30 * (bang[i].tungdo + 1)), 0);
		putpixel(x1, y1 - (30 * (bang[i].tungdo + 1)) - 1, 0);
		putpixel(x1 - 1, y1 - (30 * (bang[i].tungdo + 1)) - 1, 0);
		putpixel(x1 - 1, y1 - (30 * (bang[i].tungdo + 1)), 0);
		putpixel(x1 - 1, y1 - (30 * (bang[i].tungdo + 1)) + 1, 0);
		putpixel(x1, y1 - (30 * (bang[i].tungdo + 1)) + 1, 0);
		putpixel(x1 + 1, y1 - (30 * (bang[i].tungdo + 1)) + 1, 0);
		putpixel(x1 + 1, y1 - (30 * (bang[i].tungdo + 1)), 0);
		putpixel(x1 + 1, y1 - (30 * (bang[i].tungdo + 1)) - 1, 0);
		setlinestyle(0, 0, 1);
	}
	x += 30;
	x1 += 50;
	line(x, y, x1, y1);
	moveto(x1, y1);
	lineto(x1 - 10, y1 + 10);
	moveto(x1, y1);
	lineto(x1 - 10, y1 - 10);
	x1 -= 20;
	y1 += 30;
	settextstyle(3, 1, 1);
	char xxx[5];
	outtextxy(x1, y1, "(x)");
	bool vdn;
	x = 50, y = 700 - 20, x1 = 50, y1 = 700 - 50;
	for (i = 0; i < demtc2; i++) {
		setcolor(0);
		setlinestyle(0, 0, 1);
		y -= 30;
		y1 -= 30;
		line(x, y, x1, y1);
		moveto(x1, y1);
		lineto(x1 - 10, y1);
		moveto(x1, y1);
		lineto(x1 + 10, y1);
		int x2 = x1 + 10;
		vdn = true;
		int deem = 0;
		while (vdn == true) {
			for (j = 1; j <= 3; j++) {
				bool kthu = true;
				if (getpixel(x2 + 2, y1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2, y1 - 1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2 - 1, y1 - 1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2 - 1, y1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2 - 1, y1 + 1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2, y1 + 1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2 + 1, y1 + 1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2 + 1, y1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2 + 1, y1 - 1) != 0) {
					kthu = false;
				}
				if (kthu == true) {
					deem++;
				}
				if (deem == dembang[i].tanso) {
					vdn = false;
					break;
				}
				else {
					setcolor(0);
					x2++;
					lineto(x2, y1);
					moveto(x2, y1);
				}
			}
			if (vdn != false) {
				bool kthu = true;
				if (getpixel(x2 + 2, y1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2, y1 - 1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2 - 1, y1 - 1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2 - 1, y1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2 - 1, y1 + 1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2, y1 + 1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2 + 1, y1 + 1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2 + 1, y1) != 0) {
					kthu = false;
				}
				if (getpixel(x2 + 2 + 1, y1 - 1) != 0) {
					kthu = false;
				}
				if (kthu == true) {deem++;}
				if (deem == dembang[i].tanso) {
					vdn = false;
				}
				else {
					setcolor(15);
					x2 += 1;
					lineto(x2, y1);
					moveto(x2, y1);
				}
			}
		}
	}
	setcolor(0);
	setlinestyle(0, 0, 1);
	y -= 30;
	y1 -= 50;
	line(x, y, x1, y1);
	moveto(x1, y1);
	lineto(x1 - 10, y1 + 10);
	moveto(x1, y1);
	lineto(x1 + 10, y1 + 10);
	x1 -= 20;
	y1 += 30;
	settextstyle(3, 1, 1);
	outtextxy(x1, y1, "(y)");
	outtextxy(600, 100, "Xin loi! Chuong trinh khong the viet cac gia tri tren truc toa do.");
	outtextxy(620, 150, "Thay vao do, hay an cua so (|-|) de xem cac gia tri tren truc toa do.");
	
	cout << "Cac gia tri (gia tri) tren truc x (lan luot tu trai sang phai): ";
	for (i = 0; i < demtc; i++) {
		if (i == demtc - 1) {
			cout << bang[i].giatri << "." << endl;
		} else {
			cout << bang[i].giatri << ", ";
		}
	}
	cout << "Cac gia tri (tan so) tren truc y (lan luot tu duoi len tren): ";
	for (i = 0; i < demtc2; i++) {
		if (i == demtc2 - 1) {
			cout << y2[i] << "." << endl;
		} else {
			cout << y2[i] << ", ";
		}
 	}
	cout << "Dong ung dung de thoat" << endl;
	delay(300000);
	delete[]a;
	delete[]arr;
	delete[]bang;
	delete[]td;
	delete[]dembang;
	delete[]y2;
	return 0;
}
