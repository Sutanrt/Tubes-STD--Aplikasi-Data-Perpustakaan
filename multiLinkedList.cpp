#include "multiLinkedList.h"

void createListPeminjam(LPeminjam &L){
    first(L)=NULL;
}
void createListBuku(LBuku &L){
    first(L)=NULL;
}
void createListRelation(LRelation &L){
    first(L)=NULL;
}
adr_peminjam createElemenPeminjam(infotype_peminjam x){
    adr_peminjam P=new elm_peminjam;
    info(P)=x;
    info(P).banyak_pinjaman=0;
    next(P)=NULL;
    first(buku(P))=NULL;
    return P;
}
adr_buku createElemenBuku(infotype_buku x){
    adr_buku P=new elm_buku;
    info(P)=x;
    info(P).banyak_peminjam=0;
    next(P)=NULL;
    return P;
}
adr_relation createElemenRelation(adr_buku x){
    adr_relation P=new elm_relation;
    next_buku(P)=x;
    next(P)=NULL;
    return P;
}
void insertFirstPeminjam(LPeminjam &L, adr_peminjam P){
    if(first(L)==NULL){
        first(L)=P;
    }else {
        next(P)=first(L);
        first(L)=P;
    }
}
void insertFirstBuku(LBuku &L,adr_buku P){
    if(first(L)==NULL){
        first(L)=P;
    }else {
        next(P)=first(L);
        first(L)=P;
    }
}
void insertFirstRelation(LRelation &L,adr_relation P){
     if(first(L)==NULL){
        first(L)=P;
    }else {
        next(P)=first(L);
        first(L)=P;
    }
}

void insertLastPeminjam(LPeminjam &L,adr_peminjam P){
    adr_peminjam temp=first(L);
    if(temp==NULL){
        first(L)=P;
    }else if (next(temp)==NULL){
        next(first(L))=P;
    }else{
        while(next(temp)!=NULL){
            temp=next(temp);
        }
        next(temp)=P;
    }
}
void insertLastBuku(LBuku &L,adr_buku P){
    adr_buku temp=first(L);
    if(temp==NULL){
        first(L)=P;
    }else if (next(first(L))==NULL){
        next(first(L))=P;
    }else{
        while(next(temp)!=NULL){
            temp=next(temp);
        }
        next(temp)=P;
    }

}
void showPeminjam(LPeminjam L){
    adr_peminjam temp=first(L);
    cout<<"Isi Data Peminjam :\n";
    while(temp!=NULL){
        cout<<"ID Peminjam: "<<info(temp).ID_peminjam<<" nama : "<<info(temp).nama<<" umur : "<<info(temp).umur<<" Jenis Kelamin: "<<info(temp).jenisKelamin<<" Banyak buku dipinjam :"<<info(temp).banyak_pinjaman<<endl;
        temp=next(temp);
    }
}
void showBuku(LBuku L){
    adr_buku temp=first(L);
     cout<<"Isi Data Buku :\n";
    while(temp!=NULL){
        cout<<"ID Buku : "<<info(temp).ID_buku<<" Judul : "<<info(temp).judul<<" Penulis : "<<info(temp).penulis<<" Jumlah halaman : "<<info(temp).halaman<<" Sisa kuota buku :"<<info(temp).kuota_buku<<" Banyak peminjam buku : "<<info(temp).banyak_peminjam<<endl;
        temp=next(temp);
    }

}

//
void insertLastRelation(LRelation &L, adr_relation P){
    adr_relation temp=first(L);
    if(temp==NULL){
        first(L)=P;
    }else if (next(temp)==NULL){
        next(first(L))=P;
    }else{
        while(next(temp)!=NULL){
            temp=next(temp);
        }
        next(temp)=P;
    }

}
void menu(){

    infotype_peminjam x;
    infotype_buku y;
    adr_peminjam P;
    adr_buku P2;
    adr_relation P3;
    LPeminjam L;
    LBuku L2;
    LRelation L3;
    createListPeminjam(L);
    createListBuku(L2);
    createListRelation(L3);
    int pilihan,pilihanLoop,pilihanLoop2;
    Header();
    //cout<<"1.Penambahan data\n"<<"2.Pinjam Buku\n"<<"3.Mengemballikan buku\n"<<"4.Menghapus data\n"<<"5.Ketersediaan Buku\n"<<"6.Data buku favorit dan bukan favorit\n"<<"7.Menampilkan data\n"<<"8.Keluar\n"<<"Pilihan anda:";
    cin>>pilihan;
    while(pilihan<8){
        //Utama

        if(pilihan==1){
            //41
                menu1(L,L2);
        }else if(pilihan==2){
                menu2(L,L2);
        }else if(pilihan==3){
                menu3(L,L2);
        }else if(pilihan==4){
                menu4(L,L2);
            //sementara
        }else if(pilihan ==5){
                menu5(L,L2);
        }else if(pilihan ==6){
                menu6(L,L2);
        }else if(pilihan ==7){
            menu7(L,L2);
            showPeminjam(L);
             showBuku(L2);
        }
        Header();
        //cout<<"1.Penambahan data\n"<<"2.Pinjam Buku\n"<<"3.Mengemballikan buku\n"<<"4.Menghapus data\n"<<"5.Ketersediaan Buku\n"<<"6.Data buku favorit dan bukan favorit\n"<<"7.Menampilkan data\n"<<"8.Keluar\n"<<"Pilihan anda:";
        cin>>pilihan;
    }

    }
    //1.Penambahan data
    //2.Pinjam Buku
    //3.Mengemballikan buku

void menu1(LPeminjam &L,LBuku &L2){
    infotype_peminjam x;
    infotype_buku y;
    adr_peminjam P;
    adr_buku P2;
    int pilihanLoop;
    int pilihanLoop2;
    int n,i;
    Header2();
    //cout<<"Data apa yang ingin ditambah:\n"<<"1.Peminjam\n"<<"2.Buku\n"<<"3.Keluar\n"<<"Pilihan anda:";
    cin>>pilihanLoop;
    while(pilihanLoop<3){
    //413
    i=0;
    cout<<"Banyak data yang ingin dimasukan : ";
    cin>>n;
    if(pilihanLoop==1){
        while(n>0){
             cout<<"Lokasi data ke-"<<i+1<<" ditambahkan :\n"<<"1.Didepan\n"<<"2.Dibelakang\n"<<"Pilihan anda:";
             cin>>pilihanLoop2;
             cout<<"Mohon Masukan data  peminjam ke-"<<i+1<<endl;
             //<<" (ID_peminjam,nama,umur,jeniskelamin):\n";
             //cin>>x.ID_peminjam>>x.nama>>x.umur>>x.jenisKelamin;
            x=inputPeminjam();
            P=createElemenPeminjam(x);
            //buat cari peminjam
            if(pilihanLoop2==1){
                insertFirstPeminjam(L,P);
            }else if (pilihanLoop2==2){
            insertLastPeminjam(L,P);
            }else {
                cout<<"input lokasi data tidak sesuai\n";
                n++;
            }
            i++;
            n--;
        }
        cout<<"Data Peminjam Baru :\n";
        showPeminjam(L);

    }else if(pilihanLoop==2){
        while(n>0){
             cout<<"Lokasi data ke-"<<i+1<<" ditambahkan :\n"<<"1.Didepan\n"<<"2.Dibelakang\n"<<"Pilihan anda:";
             cin>>pilihanLoop2;
             cout<<"Mohon masukan data buku ke-"<<i+1<<endl;
             //<<" (ID_buku,judul,penulis,halaman,kuota buku)\n";
            //cin>>y.ID_buku>>y.judul>>y.penulis>>y.halaman>>y.kuota_buku;
            y=inputBuku();
            cout<<"Kuota Buku : ";
            cin>>y.kuota_buku;
            //buat cari buku
            P2=createElemenBuku(y);
        if(pilihanLoop2==1){
            insertFirstBuku(L2,P2);
        }else if (pilihanLoop2==2){
            insertLastBuku(L2,P2);
        }else {
            cout<<"input lokasi data tidak sesuai\n";
                n++;
        }
            i++;
            n--;
        }
        cout<<"Data Buku Baru :\n";
        showBuku(L2);
    }
    Header2();
    //cout<<"Data apa yang ingin ditambah:\n"<<"1.Peminjam\n"<<"2.Buku\n"<<"3.Keluar\n"<<"Pilihan anda:";
    cin>>pilihanLoop;
}
}

adr_peminjam cariPeminjam(LPeminjam L,infotype_peminjam x){
    adr_peminjam temp=first(L);

    if(temp==NULL){
        return temp;
    }else{
        while(temp!=NULL&&(info(temp).ID_peminjam!=x.ID_peminjam||info(temp).nama!=x.nama||info(temp).umur!=x.umur||info(temp).jenisKelamin!=x.jenisKelamin)){
            temp=next(temp);
        }

    }
    return temp;
}
adr_buku cariBuku(LBuku L,infotype_buku y){
    adr_buku temp=first(L);
    if(temp==NULL){
        return temp;
    }else{
        while(temp!=NULL&&(info(temp).halaman!=y.halaman||info(temp).ID_buku!=y.ID_buku||info(temp).judul!=y.judul||info(temp).kuota_buku!=y.kuota_buku||info(temp).penulis!=y.penulis)){
            temp=next(temp);
        }
    }
    return temp;
}
adr_buku cariBuku2(LBuku L,infotype_buku y){
      adr_buku temp=first(L);
    if(temp==NULL){
        return temp;
    }else{
        while(temp!=NULL&&(info(temp).halaman!=y.halaman||info(temp).ID_buku!=y.ID_buku||info(temp).judul!=y.judul||info(temp).penulis!=y.penulis)){
            temp=next(temp);
        }
    }
    return temp;
}
adr_relation cariRelasi(LRelation L,adr_buku P){
    adr_relation temp=first(L);
    if(temp==NULL){
        return temp;
    }else{
        while(temp!=NULL && next_buku(temp)!=P){
            temp=next(temp);
        }
        return temp;
    }
}
adr_relation cariRelasi2(LRelation L,infotype_buku y){
    adr_relation temp=first(L);
    if(temp==NULL){
        return temp;
    }else{
        while(temp!=NULL && (info(next_buku(temp)).ID_buku!=y.ID_buku||info(next_buku(temp)).judul!=y.judul||info(next_buku(temp)).penulis!=y.penulis||info(next_buku(temp)).halaman!=y.halaman)){
            temp=next(temp);
        }
        return temp;
    }
}
void pinjamBuku(LPeminjam L,LBuku L2,adr_peminjam P,adr_buku Q,int pilihan){
    adr_relation R;
    if(P!=NULL&&Q!=NULL){
        info(P).banyak_pinjaman++;
        R=createElemenRelation(Q);
        if(pilihan==1){
            insertFirstRelation(buku(P),R);
        }else if(pilihan==2){
            insertLastRelation(buku(P),R);
        }
        info(next_buku(R)).banyak_peminjam++;
        info(next_buku(R)).kuota_buku--;

    }
}

void menu2(LPeminjam &L,LBuku &L2){
    int loop,i,pilihan,tersedia;
    adr_peminjam P;
    adr_buku Q;
    adr_relation R;
    infotype_peminjam x;
    infotype_buku y;
    showPeminjam(L);
    Header3();
    cout<<"Mohon Masukan data  peminjam :\n";
    //<<" (ID_peminjam,nama,umur,jeniskelamin):\n";
    //cin>>x.ID_peminjam>>x.nama>>x.umur>>x.jenisKelamin;
    x=inputPeminjam();
    P=cariPeminjam(L,x);
    while(P==NULL){
        cout<<"Data peminjam tidak ditemukan mohon input ulang :\n";
        cout<<"Mohon Masukan data  peminjam :\n";
        //<<" (ID_peminjam,nama,umur,jeniskelamin):\n";
        //cin>>x.ID_peminjam>>x.nama>>x.umur>>x.jenisKelamin;
        x=inputPeminjam();
        P=cariPeminjam(L,x);
    }
    if(info(P).banyak_pinjaman==0){
        tersedia=banyakBukuTersedia(L2);
        cout<<"Mohon masukan banyak buku yang ingin dipinjam ";
        if(tersedia>5){
            cout<<"(Maksimal 5)\n";
        }else{
            cout<<"(Maksimal "<<tersedia<<" )\n";
        }
        cin>>loop;
        while(loop<=0||loop>5||loop>tersedia){
            cout<<"Pilihan tidak sesuai mohon input ulang : \n";
            cin>>loop;
        }
        i=0;
        showTersedia(L2);
        while(loop>0){
            cout<<"Mohon masukan data buku pinjaman ke-"<<i+1<<endl;
            //<<" (ID_buku,judul,penulis,halaman)\n";
            //cin>>y.ID_buku>>y.judul>>y.penulis>>y.halaman;
            y=inputBuku();
            Q=cariBuku2(L2,y);
            //cout<<"Tes\n";
            while(Q==NULL){
                cout<<"Data buku tidak sesuai mohon input ulang:\n";
                cout<<"Mohon masukan data buku pinjaman ke-"<<i+1<<endl;
                //" (ID_buku,judul,penulis,halaman)\n";
                //cin>>y.ID_buku>>y.judul>>y.penulis>>y.halaman;
                y=inputBuku();
                Q=cariBuku2(L2,y);
            }

            R=cariRelasi(buku(P),Q);
            //if(R==NULL&&info(Q).kuota_buku!=0){
            while(R!=NULL||info(Q).kuota_buku==0){
                if(R!=NULL){
                    cout<<"Data buku yang dimasukan sudah dipinjam\n";
                }else if(info(Q).kuota_buku==0){
                    cout<<"Kuota buku yang ingin dipinjam habis\n";
                }else if(R!=NULL&&info(Q).kuota_buku!=0){
                    cout<<"Data buku yang dimasukan sudah dipinjam dan Kuota buku yang ingin dipinjam habis\n";
                }
                cout<<"Mohon input ulang :\n\n";
                cout<<"Mohon masukan data buku pinjaman ke-"<<i+1<<endl;
                //" (ID_buku,judul,penulis,halaman)\n";
                //cin>>y.ID_buku>>y.judul>>y.penulis>>y.halaman;
                y=inputBuku();
                Q=cariBuku2(L2,y);
            //cout<<"Tes\n";
                while(Q==NULL){
                    cout<<"Data buku tidak sesuai mohon input ulang:\n";
                    cout<<"Mohon masukan data buku pinjaman ke-"<<i+1<<endl;
                    //" (ID_buku,judul,penulis,halaman)\n";
                    //cin>>y.ID_buku>>y.judul>>y.penulis>>y.halaman;
                    y=inputBuku();
                    Q=cariBuku2(L2,y);
                }
                R=cariRelasi(buku(P),Q);
            }
            cout<<"Lokasi data pinjaman"<<" ditambahkan :\n"<<"1.Didepan\n"<<"2.Dibelakang\n"<<"Pilihan anda:";
            cin>>pilihan;

            while(pilihan <=0||pilihan>2){
                cout<<"Input tidak sesuai mohon input ulang\n";
                cout<<"Lokasi data pinjaman"<<" ditambahkan :\n"<<"1.Didepan\n"<<"2.Dibelakang\n"<<"Pilihan anda:";
                cin>>pilihan;
            }
            pinjamBuku(L,L2,P,Q,pilihan);
           /* }else{
                if(R!=NULL){
                    cout<<"Data buku yang dimasukan sudah dipinjam\n";
                }else if(info(Q).kuota_buku==0){
                    cout<<"Kuota buku yang ingin dipinjam habis\n";
                }else if(R!=NULL&&info(Q).kuota_buku!=0){
                    cout<<"Data buku yang dimasukan sudah dipinjam dan Kuota buku yang ingin dipinjam habis\n";
                }
            }*/
            showHaveDipinjamCertain(L2,P);
        i++;
        loop--;
     }
     cout<<"Data pinjaman baru :\n";
     showBukuDipinjam(L,x);

    }else{
        cout<<"Masih ada buku yang dipinjam sebanyak : "<<info(P).banyak_pinjaman<<" Mohon mengembalikan buku terlebih dahulu\n";
    }


}
void showRelation(LRelation L){
    adr_relation temp=first(L);
    int i=1;
    if(temp==NULL){
        cout<<"Tidak ada buku yang dipinjam\n";
    }else {
        while(temp!=NULL){
            cout<<i<<". ID Buku : "<<info(next_buku(temp)).ID_buku<<" Judul : "<<info(next_buku(temp)).judul<<" Penulis : "<<info(next_buku(temp)).penulis<<" Jumlah halaman : "<<info(next_buku(temp)).halaman<<" Sisa kuota buku :"<<info(next_buku(temp)).kuota_buku<<" Banyak peminjam buku : "<<info(next_buku(temp)).banyak_peminjam<<endl;
            temp=next(temp);
            i++;
        }
    }
}
void showBukuDipinjam(LPeminjam L,infotype_peminjam x){
    adr_peminjam P=cariPeminjam(L,x);
    if(P==NULL){
        cout<<"Data peminjam tidak ditemukan\n";
    }else{
        cout<<"Buku yang dipinjam oleh : "<<info(P).nama<<endl;
        showRelation(buku(P));
    }
}
void mengembalikanBuku(adr_peminjam P,adr_relation R){
   adr_relation temp=first(buku(P));
    adr_relation temp2;
    if(P!=NULL && R!=NULL){
        if(first(buku(P))==R){
            deleteFirstRelation(buku(P),temp);
        }else if(next(R)==NULL){
            deleteLastRelation(buku(P),temp);
        }else{
            while(next(temp)!=NULL && next(temp)!=R){
                temp=next(temp);
            }
            deleteAfterRelation(buku(P),temp2,temp);

        }
    }
}

void deleteFirstRelation(LRelation &L,adr_relation &P){
     if(first(L)==NULL){
        P=NULL;
     }else if(next(first(L))==NULL) {
        P=first(L);
        first(L)=NULL;
        info(next_buku(P)).banyak_peminjam--;
        info(next_buku(P)).kuota_buku++;
        next_buku(P)=NULL;
     }else{
        P=first(L);
        first(L)=next(P);
        next(P)=NULL;
        info(next_buku(P)).banyak_peminjam--;
        info(next_buku(P)).kuota_buku++;
        next_buku(P)=NULL;
     }
}
void deleteLastRelation(LRelation &L,adr_relation &P){
    adr_relation temp=first(L);
    if(first(L)==NULL){
        P=NULL;
    }else if(next(first(L))==NULL){
        P=first(L);
        first(L)=NULL;
        info(next_buku(P)).banyak_peminjam--;
        info(next_buku(P)).kuota_buku++;
        next_buku(P)=NULL;
    }else {
        while(next(next(temp))!=NULL){
            temp=next(temp);
        }
        P=next(temp);
        next(temp)=NULL;
        //next(P)=NULL;
        info(next_buku(P)).banyak_peminjam--;
        info(next_buku(P)).kuota_buku++;
        next_buku(P)=NULL;
    }
}
void deleteAfterRelation(LRelation &L,adr_relation &P,adr_relation Q){
    P=next(Q);
    next(Q)=next(P);
    next(P)=NULL;
    info(next_buku(P)).banyak_peminjam--;
    info(next_buku(P)).kuota_buku++;
    next_buku(P)=NULL;
}
void menu3(LPeminjam &L,LBuku &L2){
    infotype_peminjam x;
    adr_peminjam P;
    adr_buku Q;
    adr_relation R;
    infotype_buku y;
    int loop;
     Header4();
     showHavePinjamBuku(L);
     cout<<"Mohon Masukan data  peminjam yang ingin mengembalikan buku"<<endl;
     //" (ID_peminjam,nama,umur,jeniskelamin):\n";
     //cin>>x.ID_peminjam>>x.nama>>x.umur>>x.jenisKelamin;
     x=inputPeminjam();
     P=cariPeminjam(L,x);
     while(P==NULL){
        cout<<"data peminjam tidak ditemukan mohon input ulang :\n";
        cout<<"Mohon Masukan data  peminjam yang ingin mengembalikan buku"<<endl;
        //" (ID_peminjam,nama,umur,jeniskelamin):\n";
        //cin>>x.ID_peminjam>>x.nama>>x.umur>>x.jenisKelamin;
        x=inputPeminjam();
        P=cariPeminjam(L,x);
     }
     if(info(P).banyak_pinjaman!=0){
        cout<<"Jumlah buku yang dipinjam : "<<info(P).banyak_pinjaman<<endl;
        cout<<"Banyak buku yang ingin dikembalikan : ";
        cin>>loop;
        while(loop<0||loop>info(P).banyak_pinjaman){
            cout<<"input tidak sesuai mohon input ulang\n";
            cout<<"Jumlah buku yang dipinjam : "<<info(P).banyak_pinjaman<<endl;
            cout<<"Banyak buku yang ingin dikembalikan : ";
            cin>>loop;
        }
        while(loop>0){
            showBukuDipinjam(L,info(P));
            cout<<"Masukan data buku yang ingin dikembalikan :\n";
            // (ID_buku,judul,penulis,halaman)\n";
            //cin>>y.ID_buku>>y.judul>>y.penulis>>y.halaman;
            y=inputBuku();
            R=cariRelasi2(buku(P),y);
            //cout<<"TES"<<endl;
            while(R==NULL){
                cout<<"Input tidak sesuai mohon isi ulang\n";
                showBukuDipinjam(L,info(P));
                cout<<"Masukan data buku yang ingin dikembalikan :\n";
                // (ID_buku,judul,penulis,halaman)\n";
                //cin>>y.ID_buku>>y.judul>>y.penulis>>y.halaman;
                y=inputBuku();
                R=cariRelasi2(buku(P),y);

            }
            info(P).banyak_pinjaman--;
            mengembalikanBuku(P,R);
            loop--;
        }

     }else{
        cout<<"Tidak ada buku yang dipinjam\n";
     }

}

void menu4(LPeminjam &L,LBuku &L2){
    //hapus data
    int pilihan;
    infotype_peminjam x;
    infotype_buku y;
    adr_peminjam P,temp,temp2;
    adr_buku Q,temp3,temp4;
    //cout<<"1.Menghapus data Peminjam\n"<<"2.Menghapus data Buku\n"<<"3.Keluar\n"<<"Pilihan anda :\n";
    Header5();
    cin>>pilihan;
    while(pilihan<3){
        if(pilihan==1){
            showPeminjam(L);
             cout<<"Mohon Masukan data  peminjam yang ingin dihapus :\n";
             //<<" (ID_peminjam,nama,umur,jeniskelamin):\n";
             //cin>>x.ID_peminjam>>x.nama>>x.umur>>x.jenisKelamin;
             x=inputPeminjam();
             P=cariPeminjam(L,x);
             while(P==NULL){
                    cout<<"Data peminjam tidak ada mohon input ulang\n";
                    cout<<"Mohon Masukan data  peminjam yang ingin dihapus :\n";
                    //<<" (ID_peminjam,nama,umur,jeniskelamin):\n";
                    //cin>>x.ID_peminjam>>x.nama>>x.umur>>x.jenisKelamin;
                    x=inputPeminjam();
                    P=cariPeminjam(L,x);
             }
             removeRelation(buku(P));
             if(first(L)==P){
                 deleteFirstPeminjam(L,temp);
             }else if(next(P)==NULL){
                deleteLastPeminjam(L,temp);
             }else {
                temp=first(L);
                while(next(temp)!=P){
                    temp=next(temp);
                }
                deleteAfterPeminjam(L,temp2,temp);
             }
            cout<<"Data baru:\n";
            showPeminjam(L);
        }else if(pilihan==2){
            showBuku(L2);
            cout<<"Mohon masukan data buku yang ingin dihapus (ID_buku,judul,penulis,halaman)\n";
            cin>>y.ID_buku>>y.judul>>y.penulis>>y.halaman;
            Q=cariBuku2(L2,y);
            while(Q==NULL){
                cout<<"Data buku yang dimasukan tidak ada mohon input ulang\n";
                cout<<"Mohon masukan data buku yang ingin dihapus\n";
                //(ID_buku,judul,penulis,halaman)\n";
                //cin>>y.ID_buku>>y.judul>>y.penulis>>y.halaman;
                y=inputBuku();
                Q=cariBuku2(L2,y);
            }
            removeCertainRelation(L,Q);
            if(first(L2)==Q){
                deleteFirstBuku(L2,temp3);
            }else if(next(Q)==NULL){
                deleteLastBuku(L2,temp3);
            }else {
                temp3=first(L2);
                while(next(temp3)!=Q){
                    temp3=next(temp3);
                }
                deleteAfterBuku(L2,temp4,temp3);
            }
            cout<<"Data baru :\n";
            showBuku(L2);
        }
        //cout<<"1.Menghapus data Peminjam\n"<<"2.Menghapus data Buku\n"<<"3.Keluar\n"<<"Pilihan anda :\n";
        Header5();
        cin>>pilihan;
    }
}

void showHavePinjamBuku(LPeminjam L){
    adr_peminjam temp=first(L);
    cout<<"Data Peminjam yang sedang meminjam buku : \n";
    while(temp!=NULL){
        if(info(temp).banyak_pinjaman>0){
            cout<<"ID Peminjam: "<<info(temp).ID_peminjam<<" nama : "<<info(temp).nama<<" umur : "<<info(temp).umur<<" Jenis Kelamin: "<<info(temp).jenisKelamin<<" Banyak buku dipinjam :"<<info(temp).banyak_pinjaman<<endl;
        }
        temp=next(temp);
    }
}

void removeRelation(LRelation &L){
    adr_relation P;
    while(first(L)!=NULL){
        deleteFirstRelation(L,P);

    }
}

//void removeCertainRelation(adr_peminjam &L,adr_buku P);
void removeCertainRelation(LPeminjam L,adr_buku P){
    adr_peminjam temp=first(L);
    adr_relation R,temp2,temp3;
    while(temp!=NULL){
        R=cariRelasi(buku(temp),P);
        if(R!=NULL){
            if(first(buku(temp))==R){
                deleteFirstRelation(buku(temp),temp2);
            }else if(next(R)==NULL){
                deleteLastRelation(buku(temp),temp2);
            }else {
                temp3=first(buku(temp));
                while(next(temp3)!=R){
                    temp3=next(temp3);
                }
                deleteAfterRelation(buku(temp),temp2,temp3);
            }
            info(temp).banyak_pinjaman--;
        }
        temp=next(temp);
    }

}

void deleteFirstPeminjam(LPeminjam &L,adr_peminjam &P){
    if(first(L)==NULL){
        P=NULL;
    }else if(next(first(L))==NULL){
        P=first(L);
        first(L)=NULL;
    }else {
        P=first(L);
        first(L)=next(P);
        next(P)=NULL;
    }
}

void deleteFirstBuku(LBuku &L,adr_buku &P){
    if(first(L)==NULL){
        P=NULL;
    }else if(next(first(L))==NULL){
        P=first(L);
        first(L)=NULL;
    }else {
        P=first(L);
        first(L)=next(P);
        next(P)=NULL;
    }

}

void deleteLastPeminjam(LPeminjam &L,adr_peminjam &P){
    adr_peminjam temp=first(L);
    if(first(L)==NULL){
        P=NULL;
    }else if(next(first(L))==NULL){
        P=first(L);
        first(L)=NULL;
    }else{
        while(next(temp)!=NULL&&next(next(temp))!=NULL){
            temp=next(temp);
        }
        P=next(temp);
        next(temp)=NULL;
    }
}

void deleteLastBuku(LBuku &L,adr_buku &P){
    adr_buku temp=first(L);
    if(first(L)==NULL){
        P=NULL;
    }else if(next(first(L))==NULL){
        P=first(L);
        first(L)=NULL;
    }else{
        while(next(temp)!=NULL&&next(next(temp))!=NULL){
            temp=next(temp);
        }
        P=next(temp);
        next(temp)=NULL;
    }

}
void deleteAfterPeminjam(LPeminjam &L,adr_peminjam &P,adr_peminjam Q){
    P=next(Q);
    next(Q)=next(P);
    next(P)=NULL;
}
void deleteAfterBuku(LBuku &L,adr_buku &P,adr_buku Q){
    P=next(Q);
    next(Q)=next(P);
    next(P)=NULL;

}
void showTersedia(LBuku L){
    adr_buku temp=first(L);
    cout<<"List Data buku yang tersedia:\n";
    if(temp==NULL){
        cout<<"Tidak ada buku yang tersedia\n";
    }else{
         while(temp!=NULL){
                if(info(temp).kuota_buku!=0){
                     cout<<"ID Buku : "<<info(temp).ID_buku<<" Judul : "<<info(temp).judul<<" Penulis : "<<info(temp).penulis<<" Jumlah halaman : "<<info(temp).halaman<<" Sisa kuota buku :"<<info(temp).kuota_buku<<" Banyak peminjam buku : "<<info(temp).banyak_peminjam<<endl;
                }
                temp=next(temp);

         }
    }
}

void showNotTersedia(LBuku L){
    adr_buku temp=first(L);
    cout<<"List Data buku yang tidak tersedia:\n";
    if(temp==NULL){
        cout<<"Tidak ada buku yang habis\n";
    }else{
         while(temp!=NULL){
                if(info(temp).kuota_buku==0){
                     cout<<"ID Buku : "<<info(temp).ID_buku<<" Judul : "<<info(temp).judul<<" Penulis : "<<info(temp).penulis<<" Jumlah halaman : "<<info(temp).halaman<<" Sisa kuota buku :"<<info(temp).kuota_buku<<" Banyak peminjam buku : "<<info(temp).banyak_peminjam<<endl;
                }

                temp=next(temp);

         }
    }
}
int banyakBukuTersedia(LBuku L){
    adr_buku temp=first(L);
    int i=0;
    if(temp==NULL){
        i=0;
    }else{
         while(temp!=NULL){
                if(info(temp).kuota_buku!=0){
                        i++;
                }
                temp=next(temp);
         }
    }
    return i;
}
int banyakBuku(LBuku L){
        adr_buku temp=first(L);
    int i=0;
    if(temp==NULL){
        i=0;
    }else{
         while(temp!=NULL){
                i++;
                temp=next(temp);
         }
    }
    return i;

}
int banyakBukuNotTersedia(LBuku L){
      adr_buku temp=first(L);
    int i=0;
    if(temp==NULL){
        i=0;
    }else{
         while(temp!=NULL){
                if(info(temp).kuota_buku==0){
                        i++;
                }
                temp=next(temp);
         }
    }
    return i;
}

void menu5(LPeminjam &L,LBuku &L2){
    int pilihan,i ;
    //cout<<"Menampilkan :\n"<<"1.Buku yang tersedia untuk dipinjam\n"<<"2.Buku yang tidak tersedia untuk dipinjam\n"<<"3.Keluar\n"<<"Pilihan anda : ";
    Header6();
    cin>>pilihan;
    while(pilihan<1&&pilihan>3){
        cout<<"Pilihan tidak sesuai mohon input kembali\n\n";
        //cout<<"Menampilkan :\n"<<"1.Buku yang tersedia untuk dipinjam\n"<<"2.Buku yang tidak tersedia untuk dipinjam\n"<<"3.Keluar\n"<<"Pilihan anda : ";
        Header6();
        cin>>pilihan;
    }
    while(pilihan<3){
        if(pilihan==1){
                i=banyakBukuTersedia(L2);
                cout<<"Banyak buku tersedia : "<<i<<endl;
                showTersedia(L2);

        }else if(pilihan==2){
                i=banyakBukuNotTersedia(L2);
                cout<<"Banyak buku tidak tersedia : "<<i<<endl;
                showNotTersedia(L2);
        }
        Header6();
        //cout<<"Menampilkan :\n"<<"1.Buku yang tersedia untuk dipinjam\n"<<"2.Buku yang tidak tersedia untuk dipinjam\n"<<"3.Keluar\n"<<"Pilihan anda : ";
        cin>>pilihan;
        while(pilihan<1&&pilihan>3){
            cout<<"Pilihan tidak sesuai mohon input kembali\n\n";
            //cout<<"Menampilkan :\n"<<"1.Buku yang tersedia untuk dipinjam\n"<<"2.Buku yang tidak tersedia untuk dipinjam\n"<<"3.Keluar\n"<<"Pilihan anda : ";
            Header6();
            cin>>pilihan;
        }
    }
}
int bukuFavorit(LBuku L){
 adr_buku P=first(L);
 adr_buku temp;
 int i=0;
 if(P==NULL){
    i=0;
 }else{
    i=info(P).banyak_peminjam;
    temp=next(first(L));
    while(temp!=NULL){

        if(i<info(temp).banyak_peminjam){
            i=info(temp).banyak_peminjam;
        }
        temp=next(temp);
    }
 }
 return i;

}
int bukuNotFavorit(LBuku L){
 adr_buku P=first(L);
 adr_buku temp;
 int i=0;
 if(P==NULL){
    i=0;
 }else{
    i=info(P).banyak_peminjam;
    temp=next(first(L));
    while(temp!=NULL){

        if(i>info(temp).banyak_peminjam){
            i=info(temp).banyak_peminjam;
        }
        temp=next(temp);
    }
 }
 return i;
}


void showBukuFavorit(LBuku L){
    int fav=bukuFavorit(L);
    adr_buku temp=first(L);
    cout<<"Data buku favorit:\n";
    while(temp!=NULL){
        if(info(temp).banyak_peminjam==fav){
            cout<<"ID Buku : "<<info((temp)).ID_buku<<" Judul : "<<info((temp)).judul<<" Penulis : "<<info((temp)).penulis<<" Jumlah halaman : "<<info((temp)).halaman<<" Sisa kuota buku :"<<info((temp)).kuota_buku<<" Banyak peminjam buku : "<<info((temp)).banyak_peminjam<<endl;
        }
        temp=next(temp);
    }
}
void showBukuNotFavorit(LBuku L){
    int fav=bukuNotFavorit(L);
    adr_buku temp=first(L);
    cout<<"Data buku favorit:\n";
    while(temp!=NULL){
        if(info(temp).banyak_peminjam==fav){
            cout<<"ID Buku : "<<info((temp)).ID_buku<<" Judul : "<<info((temp)).judul<<" Penulis : "<<info((temp)).penulis<<" Jumlah halaman : "<<info((temp)).halaman<<" Sisa kuota buku :"<<info((temp)).kuota_buku<<" Banyak peminjam buku : "<<info((temp)).banyak_peminjam<<endl;
        }
        temp=next(temp);
    }

}



void menu6(LPeminjam &L,LBuku &L2){
    int pilihan;
    //cout<<"Menampilkan data :\n"<<"1.Buku favorit\n"<<"2.Buku tidak favorit"<<"3.Keluar\n"<<"Pilihan anda :\n";
    Header7();
    cin>>pilihan;
    while(pilihan<1||pilihan>3){
        cout<<"Pilihan tidak valid mohon input ulang :\n\n";
        //cout<<"Menampilkan data :\n"<<"1.Buku favorit\n"<<"2.Buku tidak favorit"<<"3.Keluar\n"<<"Pilihan anda :\n";
        Header7();
        cin>>pilihan;
    }
    while(pilihan <3){
        if(pilihan==1){
            cout<<"Data buku favorit : ";
            showBukuFavorit(L2);
        }else if(pilihan==2){
            cout<<"Data buku tidak favorit : ";
            showBukuNotFavorit(L2);
        }
        //cout<<"Menampilkan data :\n"<<"1.Buku favorit\n"<<"2.Buku tidak favorit"<<"3.Keluar\n"<<"Pilihan anda :\n";
        Header7();
        cin>>pilihan;
        while(pilihan<1||pilihan>3){
            cout<<"Pilihan tidak valid mohon input ulang :\n\n";
            Header7();
            //cout<<"Menampilkan data :\n"<<"1.Buku favorit\n"<<"2.Buku tidak favorit"<<"3.Keluar\n"<<"Pilihan anda :\n";
            cin>>pilihan;
        }
    }
}
void showHaveDipinjamCertain(LBuku L,adr_peminjam P){
    adr_buku temp=first(L);
    adr_relation R;
    cout<<"Buku yang dapat dipinjam\n";
    while(temp!=NULL){
        R=cariRelasi(buku(P),temp);
        if(R==NULL&&info(temp).kuota_buku!=0){
            cout<<"ID Buku : "<<info((temp)).ID_buku<<" Judul : "<<info((temp)).judul<<" Penulis : "<<info((temp)).penulis<<" Jumlah halaman : "<<info((temp)).halaman<<" Sisa kuota buku :"<<info((temp)).kuota_buku<<" Banyak peminjam buku : "<<info((temp)).banyak_peminjam<<endl;
        }
        temp=next(temp);
    }
}

void menu7(LPeminjam &L,LBuku &L2){
    int pilihan;
    adr_peminjam P;
    adr_buku Q;
    infotype_peminjam x;
    infotype_buku y;
    Header8();
    cin>>pilihan;
    while(pilihan<0||pilihan>6){
        Header8();
        cout<<"Pilihan tidak sesuai mohon input ulang:\n";
        cin>>pilihan;
    }
    while(pilihan<6){
        if(pilihan ==1){
            showPeminjam(L);
        }else if(pilihan ==2){
            showBuku(L2);
        }else if(pilihan==3){
            cout<<"Masukan data peminjam yang ingin dicari data buku yang dipinjam :\n";
            // (ID_peminjam,nama,umur,jeniskelamin)\n";
            //cin>>x.ID_peminjam>>x.nama>>x.umur>>x.jenisKelamin;
            x=inputPeminjam();
            P=cariPeminjam(L,x);
            while(P==NULL){
                cout<<"Masukan data peminjam yang ingin dicari data buku yang dipinjam :\n";
                // (ID_peminjam,nama,umur,jeniskelamin)\n";
                //cin>>x.ID_peminjam>>x.nama>>x.umur>>x.jenisKelamin;
                x=inputPeminjam();
                P=cariPeminjam(L,x);
            }
            showBukuDipinjamCertain(L,P);
        }else if(pilihan ==4){
            cout<<"Masukan data Buku yang ingin dicari data peminjam :\n";
            // (ID_buku,judul,penulis,halaman)\n";
            //cin>>y.ID_buku>>y.judul>>y.penulis>>y.halaman;
            y=inputBuku();
            Q=cariBuku2(L2,y);
            while(Q==NULL){
                cout<<"Data buku tidak ada mohon input ulang:\n";
                cout<<"Masukan data Buku yang ingin dicari data peminjam :\n";
                // (ID_buku,judul,penulis,halaman)\n";
               // cin>>y.ID_buku>>y.judul>>y.penulis>>y.halaman;
               y=inputBuku();
                Q=cariBuku2(L2,y);
        }
            showPeminjamCertain(L,Q);

        }else if(pilihan==5){
            showAllPeminjamDipinjam(L);
        }
        Header8();
        cin>>pilihan;
        while(pilihan<0||pilihan>6){

        cout<<"Pilihan tidak sesuai mohon input ulang:\n\n";
        Header8();
        cin>>pilihan;
        }

    }



}
void showBukuDipinjamCertain(LPeminjam &L,adr_peminjam P){
    showRelation(buku(P));
}
void showPeminjamCertain(LPeminjam &L,adr_buku P){
    adr_peminjam temp=first(L);
    adr_relation R;
    cout<<"Data Peminjam yang meminjam Buku :"<<info(P).judul<<endl;
    while(temp!=NULL){
        R=cariRelasi(buku(temp),P);
        if(R!=NULL){
         cout<<"ID Peminjam: "<<info(temp).ID_peminjam<<" nama : "<<info(temp).nama<<" umur : "<<info(temp).umur<<" Jenis Kelamin: "<<info(temp).jenisKelamin<<" Banyak buku dipinjam :"<<info(temp).banyak_pinjaman<<endl;
        }
        temp=next(temp);
    }
}
void showAllPeminjamDipinjam(LPeminjam L){
    adr_peminjam temp=first(L);
    adr_relation R;

    while(temp!=NULL){
        cout<<"ID Peminjam: "<<info(temp).ID_peminjam<<" nama : "<<info(temp).nama<<" umur : "<<info(temp).umur<<" Jenis Kelamin: "<<info(temp).jenisKelamin<<" Banyak buku dipinjam :"<<info(temp).banyak_pinjaman<<endl;
        cout<<"\nData Buku yang dipinjam:\n";
        showRelation(buku(temp));
        cout<<"\n\n";
        temp=next(temp);
    }


}

infotype_peminjam inputPeminjam(){
    infotype_peminjam x;
   // cout<<"Masukan data peminjam:\n";
    cout<<"ID Peminjam: ";
    cin>>x.ID_peminjam;
    cout<<"Nama Peminjam: ";
    cin>>x.nama;
    cout<<"Umur Peminjam : ";
    cin>>x.umur;
    cout<<"Jenis Kelamin Peminjam : ";
    cin>>x.jenisKelamin;
    return x;
}
infotype_buku inputBuku(){
    infotype_buku y;
   // cout<<"Masukan data buku :\n";
    cout<<"ID Buku : ";
    cin>>y.ID_buku;
    cout<<"Judul Buku : ";
    cin>>y.judul;
    cout<<"Penulis Buku : ";
    cin>>y.penulis;
    cout<<"Jumlah Halaman Buku : ";
    cin>>y.halaman;
    return y;
}
void Header(){
     cout<<"========================================\n";
     cout<<"|      Program Data Perpustakaan       |\n";
     cout<<"========================================\n";
     cout<<"| Sutan Rifky Tedjasukmana-1301223465  |\n";
     cout<<"|      Bijak Prasodjo-1301223233       |\n";
     cout<<"|              IF-46-07                |\n";
     cout<<"========================================\n";
     cout<<"|             MENU UTAMA               |\n";
     cout<<"----------------------------------------\n";
     cout<<"|1.Penambahan data                     |\n";
     cout<<"|2.Pinjam Buku                         |\n";
     cout<<"|3.Mengembalikan Buku                  |\n";
     cout<<"|4.Menghapus Data                      |\n";
     cout<<"|5.Ketersediaan Buku                   |\n";
     cout<<"|6.Data Buku Favorit dan Bukan Favorit |\n";
     cout<<"|7.Menampilkan Data                    |\n";
     cout<<"|8.Keluar                              |\n";
     cout<<"========================================\n";
     cout<<"Pilihan anda :";
}
void Header2(){
    //cout<<"Data apa yang ingin ditambah:\n"<<"1.Peminjam\n"<<"2.Buku\n"<<"3.Keluar\n"<<"Pilihan anda:";
    cout<<"===========================\n";
    cout<<"|     Penambahan Data     |\n";
    cout<<"===========================\n";
    cout<<"|1.Menambah data peminjam |\n";
    cout<<"|2.Menambah data buku     |\n";
    cout<<"|3.Keluar                 |\n";
    cout<<"===========================\n";
    cout<<"Pilihan anda:";


}
void Header3(){
    cout<<"===========================\n";
    cout<<"|      Meminjam Buku      |\n";
    cout<<"===========================\n";
}
void Header4(){
    cout<<"===========================\n";
    cout<<"|   Mengembalikan Buku    |\n";
    cout<<"===========================\n";
}
void Header5(){
    //cout<<"1.Menghapus data Peminjam\n"<<"2.Menghapus data Buku\n"<<"3.Keluar\n"<<"Pilihan anda :\n";
    cout<<"============================\n";
    cout<<"|      Menghapus Data      |\n";
    cout<<"============================\n";
    cout<<"|1.Menghapus data peminjam |\n";
    cout<<"|2.Menghapus data buku     |\n";
    cout<<"|3.Keluar                  |\n";
    cout<<"============================\n";
    cout<<"Pilihan anda: ";
}
void Header6(){
    //cout<<"Menampilkan :\n"<<"1.Buku yang tersedia untuk dipinjam\n"<<"2.Buku yang tidak tersedia untuk dipinjam\n"<<"3.Keluar\n"<<"Pilihan anda : ";
    cout<<"=============================================\n";
    cout<<"|             Ketersediaan Buku             |\n";
    cout<<"=============================================\n";
    cout<<"|1.Buku tersedia untuk dipinjam             |\n";
    cout<<"|2.Buku yang tidak tersedia untuk dipinjam  |\n";
    cout<<"|3.Keluar                                   |\n";
    cout<<"=============================================\n";
    cout<<"Pilihan anda: ";
}
void Header7(){
    //cout<<"Menampilkan data :\n"<<"1.Buku favorit\n"<<"2.Buku tidak favorit"<<"3.Keluar\n"<<"Pilihan anda :\n";
    cout<<"=============================================\n";
    cout<<"|    Data Buku Favorit dan Bukan Favorit    |\n";
    cout<<"=============================================\n";
    cout<<"|1.Data buku favorit                        |\n";
    cout<<"|2.Data buku tidak favorit                  |\n";
    cout<<"|3.Keluar                                   |\n";
    cout<<"=============================================\n";
    cout<<"Pilihan anda : ";

}
void Header8(){

    cout<<"====================================================================\n";
    cout<<"|                        Menampilkan Data                          |\n";
    cout<<"====================================================================\n";
    cout<<"|1.Menampilkan seluruh data peminjam                               |\n";
    cout<<"|2.Menampilkan seluruh data buku                                   |\n";
    cout<<"|3.Menampilkan buku yang dipinjam oleh peminjam tertentu           |\n";
    cout<<"|4.Menampilkan seluruh peminjam buku tertentu                      |\n";
    cout<<"|5.Menampilkan semua peminjam beserta seluruh buku yang dipinjam   |\n";
    cout<<"|6.Keluar                                                          |\n";
    cout<<"====================================================================\n";

}
/*
1
1
5
1
1 Sutan 18 Pria
2
2 Afif 19 Pria
1
3 Kurniawan 20 Pria
1
4 Supriyadi 19 pria
2
5 Fansyah 1 Pria
2
5
1
1b One_Piece Oda 1220 1000
2
2b JJK GEGE 150 500
1
3b Bleach Kubo 450 300
2
4b Fairy_tail moshima 560 500
1
5b KNY gotoge 130 3
3
2
3 Kurniawan 20 Pria
1
5b KNY gotoge 130
1
2
4 Supriyadi 19 pria
1
5b KNY gotoge 130
1
2
5 Fansyah 1 Pria
1
5b KNY gotoge 130
1
*/
/*
Negloop sampai 5 buku;
*/
