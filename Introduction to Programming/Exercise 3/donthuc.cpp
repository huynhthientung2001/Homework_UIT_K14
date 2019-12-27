#include <iostream>
using namespace std;
struct DONTHUC
{
	int heso;
	int somu;
};
struct PHANSO
{
	int tu;
	int mau;
};
void nhapDonThuc(DONTHUC& a);
void xuatDonThuc(DONTHUC a);
void tich(DONTHUC a, DONTHUC b);
void thuong(DONTHUC a, DONTHUC b);
void daoHam(DONTHUC a);
void giaTriDonThucTaiX0(DONTHUC a, int x);
int UCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}
void rutGonPhanSo(PHANSO& a)
{
	int x = UCLN(a.tu, a.mau);
	a.tu /= x;
	a.mau /= x;
}
int main()
{
	DONTHUC x1, x2;
	int x0;
	cout << "Moi ban nhap don thuc thu nhat:\n";
	nhapDonThuc(x1);
	cout << "Don thuc ban vua nhap la:\t"; xuatDonThuc(x1);
	cout << "Nhap x0: "; cin >> x0;
	giaTriDonThucTaiX0(x1, x0);
	daoHam(x1);
	cout << "-------------------------------------\n";
	cout << "Moi ban nhap don thuc thu hai:\n";
	nhapDonThuc(x2);
	cout << "Don thuc ban vua nhap la:\t"; xuatDonThuc(x2);
	cout << "Nhap x0: "; cin >> x0;
	giaTriDonThucTaiX0(x2, x0);
	daoHam(x2);
	cout << "-------------------------------------\n";
	tich(x1, x2);
	thuong(x1, x2);
	return 0;
}
void giaTriDonThucTaiX0(DONTHUC a, int x)
{
	cout << "Gia tri cua don thuc tai x0 la:\t";
	if (x == 0) cout << "0\n";
	else
	{
		int s = 1;
		for (int i = 1; i <= a.somu; i++)
			s *= x;
		cout << a.heso * s << endl;
	}
	
}
void daoHam(DONTHUC a)
{
	DONTHUC c;
	c.heso = a.heso * a.somu;
	c.somu = a.somu - 1;
	cout << "Don thuc sau khi dao ham la:\t";
	if (c.heso == 0) cout << "0\n";
	else if (c.somu == 0) cout << c.heso << endl;
	else xuatDonThuc(c);
}
void thuong(DONTHUC a, DONTHUC b)
{
	DONTHUC c;
	c.somu = a.somu - b.somu;
	PHANSO d;
	d.tu = a.heso;
	d.mau = b.heso;
	rutGonPhanSo(d);
	if (c.somu == 0) cout << "Thuong cua hai don thuc la:\t" << d.tu << "/" << d.mau;
	else cout << "Thuong cua hai don thuc la:\t (" << d.tu << "/" << d.mau << ")x^" << c.somu << endl;

}
void tich(DONTHUC a, DONTHUC b)
{
	DONTHUC c;
	c.heso = a.heso * b.heso;
	c.somu = a.somu + b.somu;
	cout << "Tich cua hai don thuc la:\t";
	xuatDonThuc(c);
}
void xuatDonThuc(DONTHUC a)
{
	if ((a.heso == 1) && a.somu) cout << "x^" << a.somu << endl;
	else if (a.somu == 0) cout << a.heso << endl;
	else cout << a.heso << "x^" << a.somu << endl;
}
void nhapDonThuc(DONTHUC &a)
{
	do
	{
		cout << "Nhap he so: "; cin >> a.heso;
	} while (a.heso == 0);
	cout << "Nhap so mu: "; cin >> a.somu;
}
