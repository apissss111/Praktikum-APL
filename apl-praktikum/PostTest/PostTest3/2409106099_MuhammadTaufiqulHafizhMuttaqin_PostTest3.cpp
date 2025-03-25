#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Kamar {
    int nomor;
    int status; // 1: tersedia, 0: terpesan
};

struct User {
    string username;
    string password;
};

Kamar daftarKamar[1000]; // Array untuk menyimpan kamar
User daftarUser[200]; // Array untuk menyimpan user
int userCount = 0, kamarCount = 0;

int main() {
    int pilihan;
    string user, pass;
    int loginIndex = -1;
    int isAdmin = 0;
    int nomor;
    
    while (true) {
        cout << "\n=== Sistem Pemesanan Kamar Hotel ===\n";
        cout << "1. Login Admin\n2. Login User\n3. Buat Akun\n4. Keluar\nPilihan: ";
        cin >> pilihan;
        
        int attempt = 0;
        switch (pilihan) {
            case 1:
                cin.ignore(); 
                while (attempt < 3) {
                    cout << "\nMasukkan Nama Admin: "; getline(cin, user);
                    cout << "Masukkan Password Admin: "; cin >> pass;
                    cin.ignore(); 
                    if (user == "Muhammad Taufiqul Hafizh Muttaqin" && pass == "2409106099") {
                        isAdmin = 1;
                        break;
                    } else {
                        cout << "Login gagal! Percobaan ke-" << (attempt + 1) << " dari 3." << endl;
                        attempt++;
                    }
                }
                if (attempt == 3) {
                    cout << "Gagal login sebagai admin, kembali ke menu utama.\n";
                }
                break;
            
            case 2:
                cout << "\nMasukkan Username: "; cin >> user;
                cout << "Masukkan Password: "; cin >> pass;
                loginIndex = -1;
                for (int i = 0; i < userCount; i++) {
                    if (daftarUser[i].username == user && daftarUser[i].password == pass) {
                        loginIndex = i;
                        break;
                    }
                }
                if (loginIndex == -1) {
                    cout << "Login gagal!" << endl;
                } else {
                    cout << "Login berhasil!" << endl;
                }
                break;
            
            case 3:
                cout << "\nMasukkan Username: "; cin >> daftarUser[userCount].username;
                cout << "Masukkan Password: "; cin >> daftarUser[userCount].password;
                userCount++;
                cout << "Akun berhasil dibuat!" << endl;
                break;
            
            case 4:
                return 0;
        }
        
        while (isAdmin) {
            cout << "\n=== Menu Admin ===\n";
            cout << "1. Tambah Kamar\n2. Lihat Kamar\n3. Ubah Status Kamar\n4. Hapus Kamar\n5. Keluar\nPilihan: ";
            cin >> pilihan;
            
            switch (pilihan) {
                case 1:
                    cout << "Masukkan nomor kamar baru: "; cin >> daftarKamar[kamarCount].nomor;
                    daftarKamar[kamarCount].status = 1;
                    kamarCount++;
                    cout << "Kamar berhasil ditambahkan!" << endl;
                    break;
                
                case 2:
                    cout << "\nDaftar Kamar:\n";
                    cout << "+-------+------------+\n";
                    cout << "| Nomor |  Status   |\n";
                    cout << "+-------+------------+\n";
                    for (int i = 0; i < kamarCount; i++) {
                        cout << "| " << setw(5) << daftarKamar[i].nomor << " | ";
                        cout << setw(10) << (daftarKamar[i].status ? "Tersedia" : "Terpesan") << " |\n";
                    }
                    cout << "+-------+------------+\n";
                    break;
                
                case 3:
                    cout << "\nMasukkan Nomor Kamar yang ingin diubah statusnya: "; cin >> nomor;
                    for (int i = 0; i < kamarCount; i++) {
                        if (daftarKamar[i].nomor == nomor) {
                            daftarKamar[i].status = 1 - daftarKamar[i].status;
                            cout << "Status kamar berhasil diubah!" << endl;
                            break;
                        }
                    }
                    break;
                
                case 4:
                    cout << "\nMasukkan Nomor Kamar yang ingin dihapus: "; cin >> nomor;
                    for (int i = 0; i < kamarCount; i++) {
                        if (daftarKamar[i].nomor == nomor) {
                            for (int j = i; j < kamarCount - 1; j++) {
                                daftarKamar[j] = daftarKamar[j + 1];
                            }
                            kamarCount--;
                            cout << "Kamar berhasil dihapus!" << endl;
                            break;
                        }
                    }
                    break;
                
                case 5:
                    isAdmin = 0;
                    cout << "Logout admin berhasil, kembali ke menu utama.\n";
                    break;
            }
        }

        while (loginIndex != -1) {
            cout << "\n=== Menu User ===\n";
            cout << "1. Booking Kamar\n2. Lihat Kamar\n3. Logout\nPilihan: ";
            cin >> pilihan;
            
            switch (pilihan) {
                case 1:
                    cout << "\nMasukkan Nomor Kamar yang ingin dipesan: "; cin >> nomor;
                    for (int i = 0; i < kamarCount; i++) {
                        if (daftarKamar[i].nomor == nomor && daftarKamar[i].status == 1) {
                            daftarKamar[i].status = 0;
                            cout << "Kamar berhasil dipesan!" << endl;
                            break;
                        }
                    }
                    break;
                
                case 2:
                    cout << "\nKamar yang tersedia:\n";
                    for (int i = 0; i < kamarCount; i++) {
                        if (daftarKamar[i].status == 1) {
                            cout << "+-------+------------+\n";
                            cout << "Kamar " << daftarKamar[i].nomor << " tersedia." << endl;
                            cout << "+-------+------------+\n";
                        }
                    }
                    break;
                
                case 3:
                    loginIndex = -1;
                    cout << "Logout user berhasil.\n";
                    break;
            }
        }
    }
    return 0;
}
