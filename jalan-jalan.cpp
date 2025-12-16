#include "jalan-jalan.h"

void createListJalan(List_Jalan &L) {
    L.first = nullptr;
}

void createListKota(List_Kota &L) {
    L.first = nullptr;
    L.last = nullptr;
}

addr_Jalan createElmJalan(string namaJalan, string tipeJalan, int jarak) {
    addr_Jalan P = new elm_Jalan;
    P->namaJalan = namaJalan;
    P->tipeJalan = tipeJalan;
    P->jarak = jarak;
    P->next = nullptr;
    return P;
}

addr_Kota createElmKota(string namaKota, string walikota, int populasi) {
    addr_Kota P = new elm_Kota;
    P->namaKota = namaKota;
    P->walikota = walikota;
    P->populasi = populasi;
    P->firstRelasi = nullptr;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

addr_Relasi createElmRelasi(addr_Jalan P_Jalan) {
    addr_Relasi P = new elm_Relasi;
    P->linkJalan = P_Jalan;
    P->next = nullptr;
    return P;
}

void insertJalan(List_Jalan &L, addr_Jalan P){
    if (L.first == nullptr){
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertKota(List_Kota &L, addr_Kota P){
    if (L.first == nullptr){
        L.first = P;
        L.last = P;
    } else {
        P -> prev = L.last;
        L.last -> next = P;
        L.last = P;
    }
}

addr_Jalan findJalan(List_Jalan &L, string namaJalan){
    addr_Jalan P = L.first;
    while (P != nullptr){
        if (P -> namaJalan == namaJalan) return P;
        P = P -> next;
    }
    return nullptr;
}

addr_Kota findKota(List_Kota &L, string namaKota){
    addr_Kota P = L.first;
    while (P != nullptr) {
        if (P -> namaKota == namaKota) return P;
        P = P -> next;
    }
    return nullptr;
}

void hubungkanKotaJalan(List_Kota &L_Kota,List_Jalan &L_Jalan, string namaKota, string namaJalan){
    addr_Kota K = findKota(L_Kota, namaKota);
    addr_Jalan J = findJalan(L_Jalan, namaJalan);

    if (K != nullptr && J != nullptr){
        addr_Relasi R = K -> firstRelasi;
        while (R != nullptr){
            if (R -> linkJalan == J) return;
            R = R -> next;
        }
        addr_Relasi newrelasi = createElmRelasi(J);
        newrelasi -> next = K -> firstRelasi;
        K -> firstRelasi = newrelasi;
    }
}

void deleteKota(List_Kota &L, string namaKota){
    addr_Kota P = findKota(L, namaKota);
    if (P == nullptr) return;

    addr_Relasi R = P -> firstRelasi;
    while (R != nullptr){
        addr_Relasi temp = R;
        R = R -> next;
        delete temp;
    }
    P -> firstRelasi = nullptr;

    if (P == L.first) {
        L.first = P -> next;
        if (L.first != nullptr) L.first -> prev = nullptr;
        else L.last = nullptr;
    } else if (P == L.last){
        L.last = P -> prev;
        L.last -> next = nullptr;
    } else {
        P -> prev -> next = P -> next;
        P -> next -> prev = P -> prev;
    }
    delete P;
}

void deleteJalan(List_Jalan &L_Jalan, List_Kota &L_Kota, string namaJalan){
    addr_Jalan J = findJalan(L_Jalan, namaJalan);
    if (J == nullptr) return;

//Hapus RELASI di SEMUA kota yang pakai jalan ini
    addr_Kota K = L_Kota.first;
    while (K != nullptr){
        addr_Relasi R = K -> firstRelasi;
        addr_Relasi prevR = nullptr;

        while (R != nullptr){
            if (R -> linkJalan == J){
                addr_Relasi hapus = R;
                if (prevR == nullptr){
                    K -> firstRelasi = R -> next;
                    R = K -> firstRelasi;           
                } else {
                    prevR -> next = R -> next;
                    R = R -> next;
                }
                delete hapus;
            } else {
                prevR = R;
                R = R -> next;
            }
        }
        K = K -> next;
    }

// Hapus Node Jalan dari List Master (List_Jalan)
    if (J == L_Jalan.first) {
        L_Jalan.first = J->next;
    } else {
        addr_Jalan Q = L_Jalan.first;
        while (Q->next != J) {
            Q = Q->next;
        }
        Q->next = J->next;
    }
    
    delete J;
}

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