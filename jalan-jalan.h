#ifndef JALAN_JALAN_H
#define JALAN_JALAN_H

#include <iostream>
#include <string>

using namespace std;

struct elm_Lokasi;
struct elm_Jalan;

typedef elm_Jalan* addr_Jalan;
typedef elm_Lokasi* addr_Lokasi;

struct elm_Jalan{
    string namaJalan;
    int jarak;
    addr_Lokasi tujuan;
    addr_Jalan nextJalan;                              
};

struct elm_Lokasi{
    string namaLokasi;
    addr_Lokasi nextLokasi;
    addr_Jalan firstJalan;
};

struct List_Lokasi{
    addr_Lokasi firstLokasi;
};

void createListLokasi(List_Lokasi &L);

addr_Lokasi createElmLokasi(string namaLokasi);
addr_Jalan createElmJalan(string namaJalan, int jarak, addr_Lokasi tujuan);

void insertLokasi(List_Lokasi &L, addr_Lokasi p);
void insertJalan(List_Lokasi &L, string namaAsal, string namaTujuan, string namaJalan, int jarak);
addr_Lokasi findLokasi(List_Lokasi L, string namaLokasi);

void printPeta(List_Lokasi L);

#endif // TRANSPORT_H