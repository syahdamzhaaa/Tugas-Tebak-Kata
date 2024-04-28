#include <iostream>
#include <string>

using namespace std;

bool findWord(const string* matriks, int Baris, int Kolom, const string& kata) {
		 int panjangKata = kata.length();

    for (int horizontal = 0; horizontal < Baris; ++horizontal) {
        for (int vertikal = 0; vertikal <= Kolom - panjangKata; ++vertikal) {
            string potongan = matriks[horizontal].substr(vertikal, panjangKata);
            if (potongan == kata) {
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
            if (VertikalKata == kata) {
                return true;
            }
        }
    }
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


