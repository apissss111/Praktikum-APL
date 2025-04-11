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

Kamar daftarKamar[1000];
User daftarUser[200];
int userCount = 0, kamarCount = 0;

// ==== FUNGSI & PROSEDUR ====
bool loginAdmin(string user, string pass) {
    return (user == "Muhammad Taufiqul Hafizh Muttaqin" && pass == "2409106099");
}

int loginUser(User daftarUser[], int userCount, string user, string pass) {
    for (int i = 0; i < userCount; i++) {
        if (daftarUser[i].username == user && daftarUser[i].password == pass) {
            return i;
        }
    }
    return -1;
}

void buatAkun(User daftarUser[], int &userCount) {
    cout << "\nMasukkan Username: "; cin >> daftarUser[userCount].username;
    cout << "Masukkan Password: "; cin >> daftarUser[userCount].password;
    userCount++;
    cout << "Akun berhasil dibuat!" << endl;
}

void tambahKamar(Kamar daftarKamar[], int &kamarCount) {
    cout << "Masukkan nomor kamar baru: "; cin >> daftarKamar[kamarCount].nomor;
    daftarKamar[kamarCount].status = 1;
    kamarCount++;
    cout << "Kamar berhasil ditambahkan!" << endl;
}

void lihatKamar(Kamar daftarKamar[], int kamarCount) {
    cout << "\nDaftar Kamar:\n";
    cout << "+-------+------------+\n";
    cout << "| Nomor |  Status   |\n";
    cout << "+-------+------------+\n";
    for (int i = 0; i < kamarCount; i++) {
        cout << "| " << setw(5) << daftarKamar[i].nomor << " | ";
        cout << setw(10) << (daftarKamar[i].status ? "Tersedia" : "Terpesan") << " |\n";
    }
    cout << "+-------+------------+\n";
}

void ubahStatusKamar(Kamar daftarKamar[], int kamarCount, int nomor) {
    for (int i = 0; i < kamarCount; i++) {
        if (daftarKamar[i].nomor == nomor) {
            daftarKamar[i].status = 1 - daftarKamar[i].status;
            cout << "Status kamar berhasil diubah!" << endl;
            return;
        }
    }
    cout << "Kamar tidak ditemukan!" << endl;
}

void hapusKamar(Kamar daftarKamar[], int &kamarCount, int nomor) {
    for (int i = 0; i < kamarCount; i++) {
        if (daftarKamar[i].nomor == nomor) {
            for (int j = i; j < kamarCount - 1; j++) {
                daftarKamar[j] = daftarKamar[j + 1];
            }
            kamarCount--;
            cout << "Kamar berhasil dihapus!" << endl;
            return;
        }
    }
    cout << "Kamar tidak ditemukan!" << endl;
}

void bookingKamar(Kamar daftarKamar[], int kamarCount, int nomor) {
    for (int i = 0; i < kamarCount; i++) {
        if (daftarKamar[i].nomor == nomor && daftarKamar[i].status == 1) {
            daftarKamar[i].status = 0;
            cout << "Kamar berhasil dipesan!" << endl;
            return;
        }
    }
    cout << "Kamar tidak tersedia atau tidak ditemukan!" << endl;
}

void lihatKamarTersedia(Kamar daftarKamar[], int kamarCount) {
    cout << "\nKamar yang tersedia:\n";
    for (int i = 0; i < kamarCount; i++) {
        if (daftarKamar[i].status == 1) {
            cout << "+-------+------------+\n";
            cout << "Kamar " << daftarKamar[i].nomor << " tersedia.\n";
            cout << "+-------+------------+\n";
        }
    }
}

// ==== PROGRAM UTAMA ====
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

        switch (pilihan) {
            case 1: {
                int attempt = 0;
                cin.ignore();
                while (attempt < 3) {
                    cout << "\nMasukkan Nama Admin: "; getline(cin, user);
                    cout << "Masukkan Password Admin: "; cin >> pass;
                    cin.ignore();
                    if (loginAdmin(user, pass)) {
                        isAdmin = 1;
                        break;
                    } else {
                        cout << "Login gagal! Percobaan ke-" << (attempt + 1) << " dari 3.\n";
                        attempt++;
                    }
                }
                if (attempt == 3) cout << "Gagal login sebagai admin, kembali ke menu utama.\n";
                break;
            }

            case 2:
                cout << "\nMasukkan Username: "; cin >> user;
                cout << "Masukkan Password: "; cin >> pass;
                loginIndex = loginUser(daftarUser, userCount, user, pass);
                if (loginIndex == -1) cout << "Login gagal!" << endl;
                else cout << "Login berhasil!" << endl;
                break;

            case 3:
                buatAkun(daftarUser, userCount);
                break;

            case 4:
                return 0;
        }

        while (isAdmin) {
            cout << "\n=== Menu Admin ===\n";
            cout << "1. Tambah Kamar\n2. Lihat Kamar\n3. Ubah Status Kamar\n4. Hapus Kamar\n5. Keluar\nPilihan: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1: tambahKamar(daftarKamar, kamarCount); break;
                case 2: lihatKamar(daftarKamar, kamarCount); break;
                case 3:
                    cout << "Masukkan Nomor Kamar: "; cin >> nomor;
                    ubahStatusKamar(daftarKamar, kamarCount, nomor); break;
                case 4:
                    cout << "Masukkan Nomor Kamar: "; cin >> nomor;
                    hapusKamar(daftarKamar, kamarCount, nomor); break;
                case 5: isAdmin = 0; cout << "Logout admin berhasil.\n"; break;
            }
        }

        while (loginIndex != -1) {
            cout << "\n=== Menu User ===\n";
            cout << "1. Booking Kamar\n2. Lihat Kamar\n3. Logout\nPilihan: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    cout << "Masukkan Nomor Kamar yang ingin dipesan: "; cin >> nomor;
                    bookingKamar(daftarKamar, kamarCount, nomor); break;
                case 2: lihatKamarTersedia(daftarKamar, kamarCount); break;
                case 3: loginIndex = -1; cout << "Logout user berhasil.\n"; break;
            }
        }
    }
}
