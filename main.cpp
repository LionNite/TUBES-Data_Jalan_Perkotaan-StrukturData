#include "header.h"

int main() {
    List_Kota L_Kota;
    List_Jalan L_Jalan;

    createListKota(L_Kota);
    createListJalan(L_Jalan);

    int pilihan;
    string namaKota, walikota, namaJalan, tipeJalan;
    int populasi, jarak;

//Menu Utama
do{ 
    cout << "========== Menu Sistem Kota & Jalan ==========" << endl;
    cout << "1. Tambah Kota" << endl;
    cout << "2. Tambah Jalan" << endl;
    cout << "3. Hubungkan Kota dan Jalan" << endl;
    cout << "4. Tampilkan Semua Data" << endl;
    cout << "5. Tampilkan Jalan di Kota Tertentu" << endl;
    cout << "6. Tampilkan Kota yang Memiliki Jalan Tertentu" << endl;
    cout << "7. Tampilkan Data Berdasarkan Tipe Jalan" << endl;
    cout << "8. Hapus Kota" << endl;
    cout << "9. Hapus Jalan" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore(); //membersihkan buffer new line

    switch (pilihan) {
//1. Menambahkan data kota baru
    case 1:
        cout << "Nama Kota : ";
        getline(cin, namaKota);
        cout << "Nama Walikota : ";
        getline(cin, walikota);
        cout << "Populasi : ";
        cin >> populasi;

        insertKota(L_Kota, createElmKota(namaKota, walikota, populasi));
        cout << "Kota Berhasil Ditambahkan.\n" << endl;
        break;

//2. Menambahkan data jalan baru
    case 2:
        cout << "Nama Jalan : ";
        getline(cin, namaJalan);
        cout << "Tipe Jalan : ";
        getline(cin, tipeJalan);
        cout << "Jarak (km) : ";
        cin >> jarak;

        insertJalan(L_Jalan, createElmJalan(namaJalan, tipeJalan, jarak));
        cout << "Jalan Berhasil Ditambahkan.\n" << endl;
        break;

//3. Menghubungkan kota dengan jalan tertentu
    case 3:
        cout << "Nama Kota : ";
        getline(cin, namaKota);
        cout << "Nama Jalan : ";
        getline(cin, namaJalan);

        hubungkanKotaJalan(L_Kota, L_Jalan, namaKota, namaJalan);
        cout << "Kota dan Jalan Berhasil dihubungkan.\n" << endl;
        break;

//4. Menampilkan seluruh data kota beserta jalan
    case 4:
        showAll(L_Kota);
        break;

//5. Menampilkan jalan yang dimiliki oleh kota tertentu
    case 5:
        cout << "Nama Kota: ";
        getline(cin, namaKota);
        showJalanKota(L_Kota, namaKota);
        break;

//6. Menampilkan kota yang memiliki jalan tertentu
    case 6:
        cout << "Nama Jalan : ";
        getline(cin, namaJalan);
        showKotaPunyaJalan(L_Kota, namaJalan);
        break;

//7. Menampilkan data berdasarkan tipe jalan
    case 7:
        cout << "Tipe Jalan : ";
        getline(cin, tipeJalan);
        showData_byTipe(L_Kota, tipeJalan);
        break;

//8. Menghapus data kota beserta seluruh relasinya
    case 8:
        cout << "Nama Kota yang ingin dihapus : ";
        getline(cin, namaKota);
        deleteKota(L_Kota, namaKota);
        cout << "Kota Berhasil dihapus.\n" << endl;
        break;

//9. Menghapus data jalan dan relasinya di semua kota
    case 9:
        cout << "Nama Jalan yang ingin dihapus : ";
        getline(cin, namaJalan);
        deleteJalan(L_Jalan, L_Kota, namaJalan);
        cout << "Jalan Berhasil dihapus.\n" << endl;
        break;

//0. Keluar dari program
    case 0:
        cout << "Keluar dari program." << endl;
        break;

    //Jika inputan tidak sesuai
    default:
        cout << "Pilihan tidak valid!" << endl;
    }
} while (pilihan != 0);
    return 0;    //Program selesai
}
