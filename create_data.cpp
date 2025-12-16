#include "header.h"

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