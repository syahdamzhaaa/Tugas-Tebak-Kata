#include <iostream>
#include <string>

using namespace std;

bool findWord(const string* matriks, int Baris, int Kolom, const string& kata) {
    string kataUpper = kata;
    for (char& c : kataUpper) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A'; 
        }
    }
    int panjangKata = kataUpper.length();

    for (int horizontal = 0; horizontal < Baris; ++horizontal) {
        for (int vertikal = 0; vertikal <= Kolom - panjangKata; ++vertikal) {
            string potongan = matriks[horizontal].substr(vertikal, panjangKata);
            for (char& c : potongan) {
                if (c >= 'a' && c <= 'z') {
                    c = c - 'a' + 'A'; 
                }
            }
            if (potongan == kataUpper) {
                return true;
            }
        }
    }

    for (int vertikal = 0; vertikal < Kolom; ++vertikal) {
        for (int horizontal = 0; horizontal <= Baris - panjangKata; ++horizontal) {
            string VertikalKata = "";
            for (int i = 0; i < panjangKata; ++i) {
                VertikalKata += matriks[horizontal + i][vertikal];
            }
            for (char& c : VertikalKata) {
                if (c >= 'a' && c <= 'z') {
                    c = c - 'a' + 'A'; 
                }
            }
            if (VertikalKata == kataUpper) {
                return true;
            }
        }
    }
    for (int horizontal = 0; horizontal <= Baris - panjangKata; ++horizontal) {
        for (int vertikal = 0; vertikal <= Kolom - panjangKata; ++vertikal) {
            bool ditemukan = true;
            for (int i = 0; i < panjangKata; ++i) {
                if (matriks[horizontal + i][vertikal + i] != kataUpper[i]) {
                    ditemukan = false;
                    break;
                }
            }
            if (ditemukan) {
                return true;
            }
        }
    }

    for (int horizontal = 0; horizontal <= Baris - panjangKata; ++horizontal) {
        for (int vertikal = Kolom - 1; vertikal >= panjangKata - 1; --vertikal) {
            bool ditemukan = true;
            for (int i = 0; i < panjangKata; ++i) {
                if (matriks[horizontal + i][vertikal - i] != kataUpper[i]) {
                    ditemukan = false;
                    break;
                }
            }
            if (ditemukan) {
                return true;
            }
        }
    }

    for (int horizontal = Baris - 1; horizontal >= panjangKata - 1; --horizontal) {
        for (int vertikal = 0; vertikal <= Kolom - panjangKata; ++vertikal) {
            bool ditemukan = true;
            for (int i = 0; i < panjangKata; ++i) {
                if (matriks[horizontal - i][vertikal + i] != kataUpper[i]) {
                    ditemukan = false;
                    break;
                }
            }
            if (ditemukan) {
                return true;
            }
        }
    }

    for (int horizontal = Baris - 1; horizontal >= panjangKata - 1; --horizontal) {
        for (int vertikal = Kolom - 1; vertikal >= panjangKata - 1; --vertikal) {
            bool ditemukan = true;
            for (int i = 0; i < panjangKata; ++i) {
                if (matriks[horizontal - i][vertikal - i] != kataUpper[i]) {
                    ditemukan = false;
                    break;
                }
            }
            if (ditemukan) {
                return true;
            }
        }
    }

    return false;

}
    
    
int main() {

    int jumlahKata;
    cin >> jumlahKata;

    string* kata = new string[jumlahKata];
    for (int i = 0; i < jumlahKata; ++i) {
        cin >> kata[i];
    }
    const int Baris = 23; 
    const int Kolom = 23; 
    string matriks[Baris] = {
        "AAFLKHPFSSUFICICLESGNNH",
        "SFVREOMRWLRTTSXOQQNAOAO",
        "QEIAIFXAEIRFVFYSXIMINJI",
        "WSTRLGOCAPBIAFIWIWTUACM",
        "FEYAEAISTPCRLUJKOAKCERS",
        "RVDAKPNDDEEHDEMSNCKKFOAH",
        "MRNEDSLCRRIWNRSAAFITMMI",
        "YAAECIEAHYMOTAVHRSSTISB",
        "RJSEWELCCENNIETOHWSGLSE",
        "ATANYYMOIEESNESIOIRELTR",
        "UTENEWEBHMYBETNNRAIEBEN",
        "RCLKUTEAEQJLSGSHTGDSKOA",
        "BHOICATNRRSDDECEHOOLGIT",
        "ENSLUARIRSETALOCOHCTOHE",
        "FZFUDQJYMADOYIWYGLOVESU",
        "TEKALFWONSNAEBMIEJTZNTG",
        "ESWPOSJXEUTUYOZUWAKEZHM",
        "KZUHBPEZEERFLMSNOWBALLH",
        "NSNOWBOARDYTVWYCLEVOHSA",
        "ACOCRQLGZIYCHODRAZZILBI",
        "LBVKKWANZAAQINWOLPWONSL",
        "BFREEZINGRAINSLILGTMELT",
        "HQPYLWHFMNFFUFPSWXNUMMV"
    };
    for (int i = 0; i < jumlahKata; ++i) {
        if (findWord(matriks, Baris, Kolom, kata[i])) {
            cout << "Ada" << endl;
        } else {
            cout << "Tidak Ada" << endl;
        }
    }

    delete[] kata;

    return 0;

}


