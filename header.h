#ifndef JALAN_JALAN_H
#define JALAN_JALAN_H

#include <iostream>
#include <string>

using namespace std;

struct elm_Jalan;
struct elm_Kota;
struct elm_Relasi;

typedef elm_Jalan* addr_Jalan;
typedef elm_Kota* addr_Kota;
typedef elm_Relasi* addr_Relasi;

struct elm_Jalan{
    string namaJalan;
    string tipeJalan;
    int jarak;
    addr_Jalan next;
};

struct List_Jalan{
    addr_Jalan first;
};

struct elm_Relasi{
    addr_Relasi next;
    addr_Jalan linkJalan;
};

struct elm_Kota{
    string namaKota;
    string walikota;
    int populasi;

    addr_Relasi firstRelasi;

    addr_Kota next;
    addr_Kota prev;
};

struct List_Kota{
    addr_Kota first;
    addr_Kota last;
};

//CREATE LIST
void createListKota(List_Kota &L);
void createListJalan(List_Jalan &L);

//CREATE ELEMENT
addr_Jalan createElmJalan(string namaJalan, string tipeJalan, int jarak);
addr_Kota createElmKota(string namaKota, string walikota, int populasi);
addr_Relasi createElmRelasi(addr_Jalan P_Jalan);

//INSERT
void insertJalan(List_Jalan &L, addr_Jalan P);
void insertKota(List_Kota &L, addr_Kota P);

//FIND
addr_Jalan findJalan(List_Jalan &L, string namaJalan);
addr_Kota findKota(List_Kota &L, string namaKota);

//CONNECT
void hubungkanKotaJalan(List_Kota &L_Kota, List_Jalan &L_Jalan, string namaKota, string namaJalan);

///DELETE
void deleteKota(List_Kota &L, string namaKota);
void deleteJalan(List_Jalan &L_Jalan, List_Kota &L_Kota, string namaJalan);

//SHOW 
void showAll(List_Kota L_Kota);
void showJalanKota(List_Kota L_Kota, string namaKota);
void showKotaPunyaJalan(List_Kota L_Kota, string namaJalan);
void showData_byTipe(List_Kota L_Kota, string tipeJalan);

#endif // JALAN_JALAN_H