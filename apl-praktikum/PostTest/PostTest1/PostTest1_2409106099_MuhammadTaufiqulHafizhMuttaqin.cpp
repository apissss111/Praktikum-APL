#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    // Login
    string username, password;
    while (true) {
        cout << "Masukkan Username: ";
        getline(cin, username);
        cout << "Masukkan Password: ";
        getline(cin, password);

        if (username == "Muhammad Taufiqul Hafizh Muttaqin" && password == "2409106099") {
            cout << "Login Berhasil!" << endl;
            break;
        } else {
            cout << "Username atau Password salah. Coba lagi." << endl;
        }
    }

    // Menu Utama
    while (true) {
        int pilihanUtama;
        cout << "\n== SISTEM HITUNG BANGUN DATAR DAN BANGUN RUANG ==" << endl;
        cout << "1. Hitung Luas" << endl;
        cout << "2. Hitung Keliling" << endl;
        cout << "3. Hitung Volume" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilih menu: ";
        cin >> pilihanUtama;

        switch (pilihanUtama) {
            case 1: {  // Menu Hitung Luas
                int pilihanLuas;
                cout << "\n== HITUNG LUAS ==" << endl;
                cout << "1. Persegi" << endl;
                cout << "2. Persegi Panjang" << endl;
                cout << "3. Lingkaran" << endl;
                cout << "4. Segitiga" << endl;
                cout << "5. Kembali" << endl;
                cout << "Pilih bangun: ";
                cin >> pilihanLuas;

                switch (pilihanLuas) {
                    case 1: {
                        float sisi;
                        cout << "Masukkan panjang sisi persegi: ";
                        cin >> sisi;
                        cout << "Luas Persegi: " << sisi * sisi << endl;
                        break;
                    }
                    case 2: {
                        float panjang, lebar;
                        cout << "Masukkan panjang persegi panjang: ";
                        cin >> panjang;
                        cout << "Masukkan lebar persegi panjang: ";
                        cin >> lebar;
                        cout << "Luas Persegi Panjang: " << panjang * lebar << endl;
                        break;
                    }
                    case 3: {
                        float jariJari;
                        cout << "Masukkan jari-jari lingkaran: ";
                        cin >> jariJari;
                        cout << "Luas Lingkaran: " << 3.14 * jariJari * jariJari << endl;
                        break;
                    }
                    case 4: {
                        float alas, tinggi;
                        cout << "Masukkan alas segitiga: ";
                        cin >> alas;
                        cout << "Masukkan tinggi segitiga: ";
                        cin >> tinggi;
                        cout << "Luas Segitiga: " << 0.5 * alas * tinggi << endl;
                        break;
                    }
                    case 5:
                        break;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                }
                break;
            }

            case 2: {  // Menu Hitung Keliling
                int pilihanKeliling;
                cout << "\n== HITUNG KELILING ==" << endl;
                cout << "1. Persegi" << endl;
                cout << "2. Persegi Panjang" << endl;
                cout << "3. Lingkaran" << endl;
                cout << "4. Segitiga" << endl;
                cout << "5. Kembali" << endl;
                cout << "Pilih bangun: ";
                cin >> pilihanKeliling;

                switch (pilihanKeliling) {
                    case 1: {
                        float sisi;
                        cout << "Masukkan panjang sisi persegi: ";
                        cin >> sisi;
                        cout << "Keliling Persegi: " << 4 * sisi << endl;
                        break;
                    }
                    case 2: {
                        float panjang, lebar;
                        cout << "Masukkan panjang persegi panjang: ";
                        cin >> panjang;
                        cout << "Masukkan lebar persegi panjang: ";
                        cin >> lebar;
                        cout << "Keliling Persegi Panjang: " << 2 * (panjang + lebar) << endl;
                        break;
                    }
                    case 3: {
                        float jariJari;
                        cout << "Masukkan jari-jari lingkaran: ";
                        cin >> jariJari;
                        cout << "Keliling Lingkaran: " << 2 * 3.14 * jariJari << endl;
                        break;
                    }
                    case 4: {
                        float sisi1, sisi2, sisi3;
                        cout << "Masukkan panjang sisi-sisi segitiga: ";
                        cin >> sisi1 >> sisi2 >> sisi3;
                        cout << "Keliling Segitiga: " << sisi1 + sisi2 + sisi3 << endl;
                        break;
                    }
                    case 5:
                        break;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                }
                break;
            }

            case 3: {  // Menu Hitung Volume
                int pilihanVolume;
                cout << "\n== HITUNG VOLUME ==" << endl;
                cout << "1. Kubus" << endl;
                cout << "2. Balok" << endl;
                cout << "3. Bola" << endl;
                cout << "4. Kerucut" << endl;
                cout << "5. Kembali" << endl;
                cout << "Pilih bangun: ";
                cin >> pilihanVolume;

                switch (pilihanVolume) {
                    case 1: {
                        float sisi;
                        cout << "Masukkan panjang sisi kubus: ";
                        cin >> sisi;
                        cout << "Volume Kubus: " << pow(sisi, 3) << endl;
                        break;
                    }
                    case 2: {
                        float panjang, lebar, tinggi;
                        cout << "Masukkan panjang balok: ";
                        cin >> panjang;
                        cout << "Masukkan lebar balok: ";
                        cin >> lebar;
                        cout << "Masukkan tinggi balok: ";
                        cin >> tinggi;
                        cout << "Volume Balok: " << panjang * lebar * tinggi << endl;
                        break;
                    }
                    case 3: {
                        float jariJari;
                        cout << "Masukkan jari-jari bola: ";
                        cin >> jariJari;
                        cout << "Volume Bola: " << (4.0 / 3.0) * 3.14 * pow(jariJari, 3) << endl;
                        break;
                    }
                    case 4: {
                        float jariJari, tinggi;
                        cout << "Masukkan jari-jari kerucut: ";
                        cin >> jariJari;
                        cout << "Masukkan tinggi kerucut: ";
                        cin >> tinggi;
                        cout << "Volume Kerucut: " << (1.0 / 3.0) * 3.14 * pow(jariJari, 2) * tinggi << endl;
                        break;
                    }
                    case 5:
                        break;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                }
                break;
            }

            case 4: {
                cout << "Logout berhasil." << endl;
                return 0;
            }

            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
