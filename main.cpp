#include <iostream>
#include "jalan-jalan.h"

using namespace std;

int main() {
    List_Lokasi Surabaya;
    createListLokasi(Surabaya);

    cout << "=== SISTEM PEMETAAN JALAN KOTA SURABAYA ===" << endl;
    cout << "1. Membangun Titik Lokasi..." << endl;

    // Tambah Lokasi (Vertex)
    insertLokasi(Surabaya, createElmLokasi("Bundaran Waru"));
    insertLokasi(Surabaya, createElmLokasi("Royal Plaza"));
    insertLokasi(Surabaya, createElmLokasi("KBS"));
    insertLokasi(Surabaya, createElmLokasi("Taman Bungkul"));
    insertLokasi(Surabaya, createElmLokasi("Tunjungan Plaza"));

    cout << "2. Membangun Rute Jalan..." << endl;

    // Tambah Jalan (Edge) - Menggunakan insertJalan
    insertJalan(Surabaya, "Bundaran Waru", "Royal Plaza", "Jl. A. Yani", 5);
    insertJalan(Surabaya, "Royal Plaza", "KBS", "Jl. Wonokromo", 2);
    
    // Percabangan di KBS
    insertJalan(Surabaya, "KBS", "Taman Bungkul", "Jl. Raya Darmo", 1);
    insertJalan(Surabaya, "KBS", "Royal Plaza", "Jl. Wonokromo (Arah Balik)", 2);
    
    // Lanjut ke pusat kota
    insertJalan(Surabaya, "Taman Bungkul", "Tunjungan Plaza", "Jl. Basuki Rahmat", 3);

    // Tes Validasi Error (Lokasi Typo)
    cout << "\n--- Tes Validasi Error ---" << endl;
    insertJalan(Surabaya, "KBS", "Bulan", "Jl. Antariksa", 999);

    // Tes Validasi Duplikasi (Input jalan yang sama 2x)
    cout << "\n--- Tes Validasi Duplikasi ---" << endl;
    insertJalan(Surabaya, "Bundaran Waru", "Royal Plaza", "Jl. A. Yani", 5);

    cout << "\n===========================================" << endl;
    cout << "           VISUALISASI PETA              " << endl;
    cout << "===========================================\n" << endl;
    
    printPeta(Surabaya);

    return 0;
}