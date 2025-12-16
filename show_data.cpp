#include "header.h"
//f. Menampilkan data keseluruhan kota beserta jalan yang terdapa di kota tersebut.  
void showAll(List_Kota L_Kota) {
    addr_Kota P = L_Kota.first;
    while (P != nullptr) {
        cout    << "KOTA: " << P -> namaKota << endl
                << ", WALIKOTA: " << P -> walikota << endl
                << ", POPULASI: " << P -> populasi << endl; 

        addr_Relasi R = P -> firstRelasi;
        if (R == nullptr) {
            cout << " - (Tidak ada data Jalan)" << endl;
        } else {
            while (R != nullptr) {
                cout << "   -> " << R -> linkJalan -> namaJalan << " [" << R -> linkJalan -> tipeJalan << "]" << endl;
                R = R -> next;
            }
        }
        cout << endl;
        P = P -> next;
    }
}

//g. Menampilkan data kota yang memiliki nama jalan tertentu.
//c. Penentuan relasi kota dan jalan (dan sebalikknya).
void showKotaPunyaJalan(List_Kota L_Kota, string namaJalan) {
    cout << "Kota yang memiliki Jl." << namaJalan << " : " << endl;
    addr_Kota P = L_Kota.first;
    bool found = false;
    while (P != nullptr) {
        addr_Relasi R = P -> firstRelasi;
        while (R != nullptr) {
            if (R -> linkJalan -> namaJalan == namaJalan) {
                cout << "- " << P -> namaKota << endl;
                found = true;
                break;
            }
            R = R -> next;
        }
        P = P -> next;
    } 
    if (!found) cout << "Tidak ditemukan.";
    cout << endl;
}

//h. Menampilkan data jalan yang dimiliki suatu kota tertentu.
void showJalanKota(List_Kota L_Kota, string namaKota) {
    addr_Kota P = findKota(L_Kota, namaKota);
    
    if (P == nullptr) {
        cout << "Kota " << namaKota << " tidak ditemukan." << endl;
        return;
    }

    cout << "Daftar Jalan di Kota " << P->namaKota << ":" << endl;
    addr_Relasi R = P->firstRelasi;
    
    if (R == nullptr) {
        cout << "- (Tidak ada data jalan)" << endl;
    } else {
        while (R != nullptr) {
            cout << "  -> " << R->linkJalan->namaJalan 
                << " (" << R->linkJalan->tipeJalan << ", " 
                << R->linkJalan->jarak << " km)" << endl;
            R = R->next;
        }
    }
    cout << endl;
}

//i. Menampilkan data kota dan nama jalan yang memiliki tipe jalan tertentu. 
void showData_byTipe(List_Kota L_Kota, string tipeJalan) {
    cout << "=== PENCARIAN TIPE JALAN: " << tipeJalan << " ===" << endl;
    
    addr_Kota P = L_Kota.first;
    bool found = false;

    while (P != nullptr) {
        addr_Relasi R = P->firstRelasi;
        while (R != nullptr) {
            if (R->linkJalan->tipeJalan == tipeJalan) {
                cout << "Kota: " << P->namaKota 
                    << " | Jalan: " << R->linkJalan->namaJalan 
                    << " (" << R->linkJalan->jarak << " km)" << endl;
                found = true;
            }
            R = R->next;
        }
        P = P->next;
    }

    if (!found) {
        cout << "Tidak ditemukan jalan dengan tipe '" << tipeJalan << "'." << endl;
    }
    cout << endl;
}