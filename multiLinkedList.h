#ifndef MULTILINKEDLIST_H_INCLUDED
#define MULTILINKEDLIST_H_INCLUDED

#include <iostream>
using namespace std;
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define buku(P) P->buku
#define next_buku(P) P->next_buku

struct infotype_peminjam{
    string ID_peminjam;
    string nama;
    int umur;
    string jenisKelamin;
    int banyak_pinjaman;
};
struct infotype_buku{
    string ID_buku;
    string judul;
    string penulis;
    string halaman;
    int kuota_buku;
    int banyak_peminjam;
};
typedef struct elm_peminjam *adr_peminjam;
typedef struct elm_buku *adr_buku;
typedef struct elm_relation *adr_relation;

struct LBuku{
    adr_buku first;
};
struct elm_relation{
    adr_buku next_buku;
    adr_relation next;
};
struct LRelation{
    adr_relation first;
};
struct elm_peminjam{
    infotype_peminjam info;
    adr_peminjam next;
    LRelation buku;
};
//first(buku(P))
struct elm_buku{
    infotype_buku info;
    adr_buku next;
};
struct LPeminjam{
    adr_peminjam first;
};


void createListPeminjam(LPeminjam &L);
void createListBuku(LBuku &L);
void createListRelation(LRelation &L);

adr_peminjam createElemenPeminjam(infotype_peminjam x);
adr_buku createElemenBuku(infotype_buku x);
adr_relation createElemenRelation(adr_buku x);

void insertFirstPeminjam(LPeminjam &L, adr_peminjam P);
void insertFirstBuku(LBuku &L,adr_buku P);
//
void insertFirstRelation(LRelation &L,adr_relation);
//

void insertLastPeminjam(LPeminjam &L,adr_peminjam P);
void insertLastBuku(LBuku &L,adr_buku P);
//
void insertLastRelation(LRelation &L, adr_relation P);
//
//
void deleteFirstPeminjam(LPeminjam &L,adr_peminjam &P);
void deleteFirstBuku(LBuku &L,adr_buku &P);
void deleteFirstRelation(LRelation &L,adr_relation &P);

void deleteLastPeminjam(LPeminjam &L,adr_peminjam &P);
void deleteLastBuku(LBuku &L,adr_buku &P);
void deleteLastRelation(LRelation &L,adr_relation &P);
//
void insertAfterPeminjam(LPeminjam &L,adr_peminjam P,adr_peminjam Q);
void insertAfterBuku(LBuku &L,adr_buku P,adr_buku Q);
//
void insertAfterRelation(LRelation &L,adr_relation P,adr_relation Q);
//
//
void deleteAfterPeminjam(LPeminjam &L,adr_peminjam &P,adr_peminjam Q);
void deleteAfterBuku(LBuku &L,adr_buku &P,adr_buku Q);
void deleteAfterRelation(LRelation &L,adr_relation &P,adr_relation Q);
//
adr_peminjam cariPeminjam(LPeminjam L,infotype_peminjam x);
adr_buku cariBuku(LBuku L,infotype_buku y);
adr_buku cariBuku2(LBuku L,infotype_buku y);
adr_relation cariRelasi(LRelation L,adr_buku P);
adr_relation cariRelasi2(LRelation L,infotype_buku y);

void pinjamBuku(LPeminjam L,LBuku L2,infotype_peminjam x,infotype_buku y);
void mengembalikanBuku(adr_peminjam P,adr_relation R);


void showBukuFavorit(LBuku L);
void showBukuTidakFavorit(LBuku L);

void showBukuDipinjam(LPeminjam,infotype_peminjam);

void showHavePinjamBuku(LPeminjam);

void menu();
void menu1(LPeminjam &L,LBuku &L2);
void menu2(LPeminjam &L,LBuku &L2);
void menu3(LPeminjam &L,LBuku &L2);
void menu4(LPeminjam &L,LBuku &L2);
void menu5(LPeminjam &L,LBuku &L2);
void menu6(LPeminjam &L,LBuku &L2);
void menu7(LPeminjam &L,LBuku &L2);

void showPeminjam(LPeminjam L);
void showBuku(LBuku L);

void showRelation(LRelation L);

void removeRelation(LRelation &L);
void removeCertainRelation(LPeminjam L,adr_buku P);

void showTersedia(LBuku L);
void showNotTersedia(LBuku L);


int banyakBukuNotTersedia(LBuku L);
int banyakBukuTersedia(LBuku L);
int banyakBuku(LBuku L);

int bukuFavorit(LBuku L);
int bukuNotFavorit(LBuku L);

void showBukuFavorit(LBuku L);
void showBukuNotFavorit(LBuku L);

void showHaveDipinjamCertain(LBuku L,adr_peminjam P);
void showBukuDipinjamCertain(LPeminjam &L,adr_peminjam P);
void showPeminjamCertain(LPeminjam &L,adr_buku P);
void showAllPeminjamDipinjam(LPeminjam L);

infotype_peminjam inputPeminjam();
infotype_buku inputBuku();

void Header();
void Header2();
void Header3();
void Header4();
void Header5();
void Header6();
void Header7();
void Header8();
#endif // MULTILINKEDLIST_H_INCLUDED


