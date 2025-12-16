#include "header.h"

//d. Menghapus data Kota
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

//e. Menghapus data Jalan 
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