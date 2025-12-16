#include "header.h"

//a. Penambahan data Kota
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

//b. Penambahan data Jalan
void insertJalan(List_Jalan &L, addr_Jalan P){
    if (L.first == nullptr){
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

//fungsi bantuan untuk prosedur hubungkanKotaJalan
addr_Jalan findJalan(List_Jalan &L, string namaJalan){
    addr_Jalan P = L.first;
    while (P != nullptr){
        if (P -> namaJalan == namaJalan) return P;
        P = P -> next;
    }
    return nullptr;
}

//fungsi bantuan untuk prosedur hubungkanKotaJalan
addr_Kota findKota(List_Kota &L, string namaKota){
    addr_Kota P = L.first;
    while (P != nullptr) {
        if (P -> namaKota == namaKota) return P;
        P = P -> next;
    }
    return nullptr;
}

//c. Penentuan relasi kota dan jalan (dan sebalikknya).
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
