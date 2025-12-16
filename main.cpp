#include "header.h"

int main() {
    List_Kota LK;
    List_Jalan LJ;

    createListKota(LK);
    createListJalan(LJ);

    // 1. Input Data Master Jalan
    insertJalan(LJ, createElmJalan("Jl. Sudirman", "Protokol", 12));
    insertJalan(LJ, createElmJalan("Jl. A. Yani", "Arteri", 10));
    insertJalan(LJ, createElmJalan("Jl. Diponegoro", "Satu Arah", 8));
    insertJalan(LJ, createElmJalan("Jl. Tol Waru", "Tol", 20));

    // 2. Input Data Kota
    insertKota(LK, createElmKota("Surabaya", "Eri Cahyadi", 3000000));
    insertKota(LK, createElmKota("Jakarta", "Heru Budi", 10000000));
    insertKota(LK, createElmKota("Malang", "Sutiaji", 900000));

    // 3. Hubungkan Kota dengan Jalan (Relasi M-N)
    hubungkanKotaJalan(LK, LJ, "Surabaya", "Jl. Sudirman");
    hubungkanKotaJalan(LK, LJ, "Surabaya", "Jl. A. Yani");
    hubungkanKotaJalan(LK, LJ, "Surabaya", "Jl. Diponegoro");

    // Nama jalan sama di kota beda
    hubungkanKotaJalan(LK, LJ, "Jakarta", "Jl. Sudirman");
    hubungkanKotaJalan(LK, LJ, "Jakarta", "Jl. Diponegoro");
    hubungkanKotaJalan(LK, LJ, "Malang", "Jl. A. Yani");

    // 4. Tampilkan Hasil
    cout << "=== DATA JALAN PERKOTAAN ===" << endl;
    showAll(LK);

    // 5. Contoh Query & Delete
    cout << "----------------------------" << endl;
    showKotaPunyaJalan(LK, "Jl. Sudirman");
    showKotaPunyaJalan(LK, "Jl. A. Yani");
    
    cout << "\n[Menghapus 'Jl. Sudirman' dari database...]" << endl;
    deleteJalan(LJ, LK, "Jl. Sudirman");

    cout << "\n=== DATA SETELAH UPDATE ===" << endl;
    showAll(LK);

    // Tes Poin H
    showJalanKota(LK, "Surabaya");

    // Tes Poin I: Panggil dengan nama baru
    showData_byTipe(LK, "Protokol");

    return 0;
}