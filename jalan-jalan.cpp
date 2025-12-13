#include "jalan-jalan.h"

void createListLokasi(List_Lokasi &L){
    L.firstLokasi = NULL;
}

addr_Lokasi createElmLokasi(string namaLokasi){
    addr_Lokasi P = new elm_Lokasi;
    P->namaLokasi = namaLokasi;
    P->nextLokasi = NULL;
    P->firstJalan = NULL;
    return P;
}

addr_Jalan createElmJalan(string namaJalan, int jarak, addr_Lokasi tujuan){
    addr_Jalan J = new elm_Jalan;
    J->namaJalan = namaJalan;
    J->jarak = jarak;
    J->tujuan = tujuan;
    J->nextJalan = NULL;
    return J;
}

void insertLokasi(List_Lokasi &L, addr_Lokasi P){
    if (L.firstLokasi == NULL) {
        L.firstLokasi = P;
    } else {
        addr_Lokasi Q = L.firstLokasi;
        while (Q->nextLokasi != NULL) {
            Q = Q->nextLokasi;
        }
        Q->nextLokasi = P;
    }
}


addr_Lokasi findLokasi(List_Lokasi L, string namaLokasi){
    addr_Lokasi P = L.firstLokasi;
    while (P != NULL) {
        if (P->namaLokasi == namaLokasi){
            return P;
        }
        P = P->nextLokasi;
    }
    return NULL;
}

void insertJalan(List_Lokasi &L, string namaAsal,string namaTujuan, string namaJalan, int jarak){
    addr_Lokasi PAsal = findLokasi(L, namaAsal);
    addr_Lokasi PTujuan = findLokasi(L, namaTujuan);

    if (PAsal == NULL || PTujuan == NULL){
        cout << "[ERROR] Lokasi tidak ditemukan!" << endl;
        return;
    }

    bool jalanExists = false;
    addr_Jalan cekJalan = PAsal->firstJalan;
    while(cekJalan != NULL){
        if (cekJalan -> tujuan == PTujuan){
            jalanExists = true;
            break;
        }
        cekJalan = cekJalan -> nextJalan;
    }

    if (jalanExists){
        cout << "[INFO] Jalan dari " << namaAsal << "ke " << namaTujuan << " sudah ada."<< endl;
    } else {
        addr_Jalan J = createElmJalan(namaJalan, jarak, PTujuan);

        J -> nextJalan = PAsal -> firstJalan;
        PAsal -> firstJalan = J;

        cout << "[SUKSES] Menambahkan: " << namaAsal << "--(" << namaJalan << ")-->" << namaTujuan << "dengan jarak: " << jarak << endl;
    }
}

void printPeta(List_Lokasi L){
    addr_Lokasi P = L.firstLokasi;
    if (P == NULL){
        cout << "[INFO] Peta Kosong." << endl;
        return;
    }

    while (P != NULL){
        cout << "LOKASI: [" << P -> namaLokasi << "]";

        addr_Jalan J = P -> firstJalan;
        if (J == NULL){
            cout << " -> (tidak ada jalan keluar)";
        } else {
            while (J != NULL){
                cout << "\n |-- " << J -> namaJalan << " (" << J -> jarak << " km) --> [" << J -> tujuan -> namaLokasi << "]"; 
                J = J -> nextJalan;
            }
        }
        cout << endl << endl; 
        P = P -> nextLokasi;
    }
}
