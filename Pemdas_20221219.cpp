// Pemdas_20221219.cpp
// Gamma Rizquha Wiradisastra
// 152021181

#include <iostream>
#include <string>

using namespace std;

struct Mhs
{
	string nama;
	string namaBayar;
	string namaBelum;
	float tgs1;
	float tgs2;
	float uts;
	float uas;
	float na;
	int bayar;
	char indeks;
};

float rataRata(Mhs[], int);
string nilaiMaks(Mhs[], Mhs[], int, int);
char cariIndeks(Mhs[], int);

int main() 
{
	Mhs nama[100];
	Mhs nilai[100];
	Mhs status[100];
	int banyak = 5;
	int k = 0;
	int j = 0;

	for (int i = 0; i < banyak; i++)
	{
		string a;
		int b;

		cout << "Nama: ";
		cin >> a;
		cout << "Sudah bayar? (0 : Belum, 1 : Sudah) ";
		cin >> b;

		nama[i].nama = a;
		status[i].bayar = b;
		if (status[i].bayar == 1)
		{
			nama[k].namaBayar = nama[i].nama;
			k++;
		}
		else
		{
			nama[j].namaBelum = nama[i].nama;
			j++;
		}
		cout << "----" << endl;
	}

	cout << endl << "DAFTAR MAHASISWA YANG BELUM BAYAR" << endl;
	for (int i = 0; i < j; i++)
	{
		cout << i + 1 << ". " << nama[i].namaBelum << endl;
	}

	cout << endl << "DAFTAR MAHASISWA YANG SUDAH BAYAR" << endl;
	for (int i = 0; i < banyak - j; i++)
	{
		
		cout << i + 1 << ". " << nama[i].namaBayar << endl;
	}

	k = 0;

	cout << endl << "INPUT NILAI MAHASISWA SUDAH BAYAR" << endl;
	for (int i = 0; i < banyak; i++)
	{
		if (status[i].bayar == 1)
		{
			float n = 0, o = 0, p = 0, q = 0;

			cout << "#MHS-" << k << endl;
			cout << "Nama: " << nama[k].namaBayar << endl;
			cout << "Tugas 1 (10%): ";
			cin >> n;
			cout << "Tugas 2 (20%): ";
			cin >> o;
			cout << "UTS (30%): ";
			cin >> p;
			cout << "UAS (40%): ";
			cin >> q;

			nilai[k].tgs1 = n;
			nilai[k].tgs2 = o;
			nilai[k].uts = p;
			nilai[k].uas = q;
			nilai[k].na = (0.1 * n) + (0.2 * o) + (0.3 * p) + (0.4 * q);
			nilai[k].indeks = cariIndeks(nilai, k);
			k++;
			cout << "-----" << endl;
		}
	}
	cout << "---------end of input nilai" << endl;

	cout << endl << "DAFTAR REKAP NILAI MAHASISWA" << endl;
	for (int i = 0; i < k; i++)
	{
		cout << "#MHS-" << i + 1 << endl;
		cout << "Nama: " << nama[i].namaBayar << endl;
		cout << "Tugas 1: " << nilai[i].tgs1 << endl;
		cout << "Tugas 2: " << nilai[i].tgs2 << endl;
		cout << "UTS: " << nilai[i].uts << endl;
		cout << "UAS: " << nilai[i].uas << endl;
		cout << "Nilai Akhir: " << nilai[i].na << endl;
		cout << "Index: " << nilai[i].indeks << endl;
		cout << "-----" << endl << endl;
	}

	cout << "REKAP NILAI KELAS" << endl;
	cout << "Rata-Rata Nilai Akhir, adalah " << rataRata(nilai, k) << endl;
	cout << "Nilai Akhir Terbesar, adalah " << nilaiMaks(nama, nilai, k, 1) << endl;
	cout << "Nilai UAS Terbesar, adalah " << nilaiMaks(nama, nilai, k, 2) << endl;
	cout << "Nilai UTS Terbesar, adalah " << nilaiMaks(nama, nilai, k, 3) << endl;
	cout << "Nilai Tugas 1 Terbesar, adalah " << nilaiMaks(nama, nilai, k, 4) << endl;
	cout << "Nilai Tugas 2 Terbesar, adalah " << nilaiMaks(nama, nilai, k, 5) << endl;


	return 0;
}

string nilaiMaks(Mhs _nama[], Mhs _nilai[], int _byk, int op)
{
	string nama = "";
	float a = -1;
	for (int i = 0; i < _byk; i++)
	{
		if (op == 1)
		{
			if (_nilai[i].na > a)
			{
				a = _nilai[i].na;
				nama = _nama[i].namaBayar;
			}
		}
		else if (op == 2)
		{
			if (_nilai[i].uas > a)
			{
				a = _nilai[i].uas;
				nama = _nama[i].namaBayar;
			}
		}
		else if (op == 3)
		{
			if (_nilai[i].uts > a)
			{
				a = _nilai[i].uts;
				nama = _nama[i].namaBayar;
			}
		}
		else if (op == 4)
		{
			if (_nilai[i].tgs1 > a)
			{
				a = _nilai[i].tgs1;
				nama = _nama[i].namaBayar;
			}
		}
		else if (op == 5)
		{
			if (_nilai[i].tgs2 > a)
			{
				a = _nilai[i].tgs2;
				nama = _nama[i].namaBayar;
			}
		}
	}
	return (nama + ", dengan nilai: " + to_string(a));
}

float rataRata(Mhs _jmlNilai[], int _byk)
{
	float avg, total = 0;

	for (int i = 0; i < _byk; i++)
	{
		total += _jmlNilai[i].na;
	}
	avg = total / _byk;
	return avg;
}

char cariIndeks(Mhs _nilai[], int _byk)
{
	if (_nilai[_byk].na > 80)
	{
		return 'A';
	}
	else if (_nilai[_byk].na > 70)
	{
		return 'B';
	}
	else if (_nilai[_byk].na > 60)
	{
		return 'C';
	}
	else if (_nilai[_byk].na > 50)
	{
		return 'D';
	}
	else
	{
		return 'E';
	}
}