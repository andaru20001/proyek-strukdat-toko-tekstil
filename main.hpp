#include <iostream>
#include <string.h>
#include <fstream>

struct Pesanan{
    std::string kode;
    std::string deskripsi;
    int tglPesan[3];
    int tenggat[3];
    Pesanan* next;
};

typedef Pesanan* Pointer;

struct Queue{
    Pointer head;
    Pointer tail;
};

struct DataStack{
    Pointer dataTarget;
    std::string Kategori;
    DataStack* next;
    DataStack* prev;
};

typedef DataStack* PointerData;

struct Stack{
    PointerData head;
    PointerData tail;
};

void buatStackData (PointerData& DS){
    DS->dataTarget = nullptr;
    DS->Kategori = "";
    DS->next = nullptr;
    DS->prev = nullptr;
}

void buatQueue(Queue& Q){                                       //Fungsi untuk memasukkan default value ke Queue
    Q.head = nullptr;
    Q.tail = nullptr;
}

void buatStack(Stack& S){                                       //Fungsi untuk memasukkan default value ke Stack
    S.head = nullptr;
    S.tail = nullptr;
}

bool QueueisEmpty(Queue& Q){                                    //Fungsi untuk mengecek apakah Queue kosong
    if (Q.head == nullptr){
        return 1;
    }
    return 0;
}

void pushStack(Stack& S, PointerData InputData) {               // Fungsi untuk memasukkan data undo ke dalam stack
  if (S.head == nullptr){
    S.head = InputData;
    S.tail = InputData;
  }
  else{
    InputData->next = S.head;
    S.head->prev = InputData;
    S.head = InputData;
  }
}

void buatPesanan(Pointer& PesananBaru){                         //Fungsi untuk memasukkan default value ke Pointer PesananBaru
    PesananBaru->kode = "";
    PesananBaru->deskripsi = "";
    for (int i=1; i<3; i++){
        PesananBaru->tenggat[i] = 0;
    }
    for (int i=1; i<3; i++){
        PesananBaru->tglPesan[i] = 0;
    }
    PesananBaru->next = nullptr;
}

void catat_log(Stack& S, Pointer& InputPesanan, int Kategori){  //Fungsi untuk mencatat perubahan ke stack. Harus dimasukkan ke fungsi-fungsi yang melakukan perubahan data
    // Kategori diisi sesuai dengan program apa yang dijalankan sebelumnya
    // 1 = tambah
    // 2 = hapus
    // 3 = edit

    PointerData newData = new DataStack;
    Pointer backup = new Pesanan;                       //Backup data yang ingin dihapus atau diedit ke dalam pointer ini
    buatStackData(newData);
    // Bagian tambah
    if (Kategori == 1){
        newData->dataTarget = InputPesanan;
        newData->Kategori = "Tambah";
    }
    //Bagian hapus
    else if (Kategori == 2 || Kategori == 3){
        buatPesanan(backup);
        backup->deskripsi = InputPesanan->deskripsi;
        backup->kode = InputPesanan->kode;
        for (int i=0; i<3; i++){
            backup->tenggat[i] = InputPesanan->tenggat[i];
        }
        for (int i=0; i<3; i++){
            backup->tglPesan[i] = InputPesanan->tglPesan[i];
        }
        backup->next = nullptr;
        newData->dataTarget = backup;
        if (Kategori == 2){
            newData->Kategori = "Hapus";
        }
        else if (Kategori == 3){
            newData->Kategori = "Edit";
        }
    }
    pushStack(S, newData);
}

std::string tambah_digit (int angka, int digitTarget){          //Fungsi untuk mengubah sebuah integer dengan digit tertentu menjadi string dengan jumlah digit yang diinginkan dengan menambahkan leading zero
    std::string hasil = "";
    int digitAngka = 1;
    int pembagi = 10;
    while (digitAngka != digitTarget){
        if (angka/pembagi == 0){
            break;
        }
        else{
            digitAngka++;
            pembagi *= 10;
        }
    }
    
    for (int i=0; i<digitTarget-digitAngka; i++){
        hasil += "0";
    }
    hasil += std::to_string(angka);
    return hasil;
}

void isi_data(Queue Q, Pointer& Pesanan){                       //Fungsi untuk mengisi informasi mengenai Pesanan; bisa juga digunakan untuk menu edit
    //Memasukkan deskipsi pesanan
    std::cout << "Masukkan deskripsi pesanan :\n";
    std::getline(std::cin >> std::ws,Pesanan->deskripsi);

    //Memasukkan tanggal pesanan masuk
    std::cout << "Masukkan tanggal kapan pesanan masuk (format DD/MM/YYYY, masing-masing dipisah dengan Enter atau Space):\n";
    for (int i=0; i<3; i++){
        std::cin >> Pesanan->tglPesan[i];
    }

    //Memasukkan tanggal tenggat pesanan
    std::cout << "Masukkan tenggat waktu pesanan (format DD/MM/YYYY, masing-masing dipisah dengan Enter atau Space):\n";
    for (int i=0; i<3; i++){
        std::cin >> Pesanan->tenggat[i];
    }

    //Blok kode untuk generate kode pesanan
    int jmlPesananHariIni = 1;
    if (QueueisEmpty(Q)){
        jmlPesananHariIni = 1;
    }
    else{
        Pointer temp = Q.head;
        while (temp != nullptr){
            if (temp->tglPesan[0] == Pesanan->tglPesan[0]){
                if (temp->tglPesan[1] == Pesanan->tglPesan[1]){
                    if (temp->tglPesan[2] == Pesanan->tglPesan[2]){
                        jmlPesananHariIni++;
                    }
                }  
            }
            temp = temp->next;
        }
    }
    //Kategori digunakan untuk menentukan apakah fungsi ini digunakan untuk menambah pesanan atau mengedit pesanan
    //1 = Menambah pesanan
    //2 = Mengedit pesanan

    //Format kode = Tanggal pemesanan + Pesanan ke berapa di tanggal itu
    std::string inputKode = "";
    inputKode = tambah_digit(Pesanan->tglPesan[0], 2);
    Pesanan->kode += inputKode;
    inputKode = tambah_digit(Pesanan->tglPesan[1], 2);
    Pesanan->kode += inputKode;
    inputKode = tambah_digit(Pesanan->tglPesan[2] % 100, 2);
    Pesanan->kode += inputKode;
    inputKode = tambah_digit(jmlPesananHariIni, 4);
    Pesanan->kode += inputKode;
}

void tambah(Queue& Q, Pointer& PesananBaru){                    //Fungsi untuk memasukkan pesanan ke priority queue. Priority key yang digunakan adalah tanggal tenggat waktu; Bisa digunakan untuk menyusun kembali data yang sudah diedit
    if (QueueisEmpty(Q)){
        Q.head = PesananBaru;
        Q.tail = PesananBaru;
    }
    
    else{
        Pointer temp = Q.head;
        Pointer temp2 = nullptr;
        // int check1;
        // int check2;

        while (temp != nullptr && PesananBaru->tenggat[2] >= temp->tenggat[2] && PesananBaru->tenggat[1] >= temp->tenggat[1] && PesananBaru->tenggat[0] >= temp->tenggat[0]){
            temp2 = temp;
            temp = temp->next;
        }
    
        if (temp2 == nullptr){                          //Jika posisi ditemukan di awal Queue
            Q.head = PesananBaru;
            PesananBaru->next = temp;
        }
        else if (temp == nullptr){                      //Jika posisi ditemukan di akhir Queue
            Q.tail = PesananBaru;
            temp2->next = PesananBaru;
        }
        else{
            PesananBaru->next = temp;                   //Jika posisi ditemukan di tengah-tengah Queue
            temp2->next = PesananBaru;
        }
    }
}

void find(Queue& Q, Pointer& previous, std::string search, Pointer& temp) { //Fungsi untuk mencari data menggunakan kode pesanan
  temp = Q.head;
  previous = nullptr;
  while (temp->kode != search){
    if(temp->kode == search){
        break;
    }
    previous = temp;
    temp = temp->next;
  }
}

void rearrange(Queue& Q, Pointer& prev, Pointer& Pesanan){      //Fungsi untuk melakukan susun ulang data yang diedit sesuai dengan tenggat baru
    //Pemisahan data dengan queue
    if (Q.head->next != nullptr){
        prev->next = Pesanan->next;
        Pesanan->next = nullptr;

        tambah(Q, Pesanan);                             //Fungsi tambah dapat kembali digunakan untuk menyusun kembali priority queue sesuai dengan tenggat yang baru
    }
}

void hapusPesanan(Queue& Q, Stack& S){                //menghapus pesanan yang diinginkan
    Pointer temp;
    Pointer previous;
    int pilihan;
    std::string search;
    if(Q.head == nullptr){
        std::cout<<"Daftar pesanan kosong\n";
        return;
    }
    std::cout<<"\nOption Penghapusan : \n1. Hapus Priority Tertinggi\n2. Hapus Pesanan by Search\nPilihan : ";
    std::cin>>pilihan;

    switch(pilihan){
        case 2:{
            std::cout << "Masukan Kode Pesanan  : ";
            std::cin >> search;

            find(Q, previous, search, temp);
            catat_log(S, temp, 2);
            if (temp->next == nullptr && Q.head == nullptr){  // jika hanya satu
            Q.head = nullptr;
            Q.tail = nullptr;
            temp = nullptr;
            }
            else if (temp == Q.head){                       //kalau pesanannya berada di awal
            Q.head = Q.head->next;
            temp->next = nullptr;
            delete temp;
            }
            else if(temp->next == nullptr){               //diakhir
            previous->next = nullptr;
            delete temp;
            }
            else{                                    //kalau pesanannya berada di tengah2
            previous->next = temp->next;
            temp->next = nullptr;
            delete temp;
            }    
            break;
        }
        case 1 :{
            catat_log(S, Q.head, 2);
            Pointer temp = nullptr;
            if(Q.head->next == nullptr){
                temp = Q.head;
                Q.head = nullptr;
                Q.tail = nullptr;
                delete temp;
            }
            else {
                temp = Q.head;
                Q.head = Q.head->next;
                temp->next = nullptr;
                delete temp;
            }
            break;
        }
    }
}

void undo (Stack& S, Queue& Q){                                 //Fungsi untuk melakukan operasi undo
    Pointer prev = nullptr;
    Pointer temp = nullptr;

    if (S.head->Kategori == "Tambah"){
        find(Q, prev, S.head->dataTarget->kode, temp);
        if (temp->next == nullptr && Q.head == nullptr){  // jika hanya satu
            Q.head = nullptr;
            Q.tail = nullptr;
            temp = nullptr;
            }
            else if (temp == Q.head){                       //kalau pesanannya berada di awal
            Q.head = Q.head->next;
            temp->next = nullptr;
            delete temp;
            }
            else if(temp->next == nullptr){               //diakhir
            prev->next = nullptr;
            delete temp;
            }
            else{                                    //kalau pesanannya berada di tengah2
            prev->next = temp->next;
            temp->next = nullptr;
            delete temp;
            }
    }
    else if (S.head->Kategori == "Hapus"){
        tambah(Q, S.head->dataTarget);
    }
    else{
        find(Q, prev, S.head->dataTarget->kode, temp);
        temp->deskripsi = S.head->dataTarget->deskripsi;
        temp->kode = S.head->dataTarget->kode;
        for (int i=0; i<3; i++){
            temp->tenggat[i] = S.head->dataTarget->tenggat[i];
        }
        for (int i=0; i<3; i++){
            temp->tglPesan[i] = S.head->dataTarget->tglPesan[i];
        }
    }
}

void cetak_data(Pointer Pesanan){                               //Fungsi untuk mencetak sebuah pointer pesanan
    std::cout << "Kode " << Pesanan->kode << '\n';
    std::cout << "Deskripsi : " << Pesanan->deskripsi << '\n';
    std::cout << "Tanggal   : " << Pesanan->tglPesan[0] << "/" << Pesanan->tglPesan[1] << "/" << Pesanan->tglPesan[2] << '\n';
    std::cout << "Tenggat   : " << Pesanan->tenggat[0] << "/" << Pesanan->tenggat[1] << "/" << Pesanan->tenggat[2] << '\n';
}

void daftarPesanan(Queue Q){                                    //Fungsi untuk mencetak pesanan-pesanan yang ada
    if (QueueisEmpty(Q)){
        std::cout << "Daftar pesanan kosong\n";
    }
    else{
        Pointer temp = Q.head;
        int i = 1;
        while(temp){    
            std::cout << "Pesanan ke-" << i << '\n';
            cetak_data(temp);
            i++;
            temp = temp->next;
        }
    }
}

void Search(Queue& Q, std::string search){                       //nambahin fungsi search untuk display value dari pesanan yang dicari
    Pointer previous;
    Pointer temp;
    find(Q, previous, search, temp);
    cetak_data(temp);
}

void clrscr(){                                                   //Fungsi clear screen dengan mencetak new line sebanyak 60 kali
    for (int i=1; i<=60; i++){
        std::cout << "\n";
    }
}

void title(std::string text){                                   //Fungsi untuk mencetak judul dari sebuah fungsi/program utama
    int panjang = text.length();
    for (int i=1; i<=panjang; i++){
        std::cout << "=";
    }
    std::cout << "\n" << text << "\n";
    for (int i=1; i<=panjang; i++){
        std::cout << "=";
    }
    std::cout << "\n\n";
}

void save_data(Queue& Q){                                       //Fungsi untuk melakukan save data ke dalam file data.txt supaya bisa diakses kembali ketika membuka program
    std::ofstream data;
    Pointer temp = Q.head;
    data.open("data.txt", std::ios::out | std::ios::trunc);

    while(temp != nullptr){
        data << temp->kode << "\n";
        data << temp->deskripsi << "\n";
        for (int i=0; i<3; i++){
            if (i == 2){
                data << temp->tglPesan[i] << "\n";
            }
            else{
                data << temp->tglPesan[i] << " ";
            }
        }
        for (int i=0; i<3; i++){
            if (i == 2){
                data << temp->tenggat[i];
            }
            else{
                data << temp->tenggat[i] << " ";
            }
        }

        if (temp->next != nullptr){
            data << "\n";
        }
        temp = temp->next;
    }
    data.close();
}

void save_log(Stack& S){                                        //Fungsi untuk mencatat perubahan yang terjadi di dalam program ke dalam file log.txt
    std::ofstream log;
    PointerData temp = S.tail;
    log.open("log.txt", std::ios::out | std::ios::app);

    while(temp != nullptr){
        log << "Melakukan " << temp->Kategori << " pada pesanan dengan kode " << temp->dataTarget->kode << "\n";
        temp = temp->prev;
    }
    log.close();
}

bool cek_file(){                                                //Fungsi untuk mengecek apakah file data (data.txt) sudah ada atau belum
    std::ifstream data;
    data.open("data.txt");
    if (data){
        return 1;
    }
    return 0;
}

void load_data(Queue& Q){                                       //Fungsi untuk load data dari file data.txt
    Pointer DataPesanan = nullptr;
    std::ifstream data;
    std::string temp;
    int convert;
    bool first = 1;
    data.open("data.txt");
    while (!data.eof()){
        DataPesanan = new Pesanan;
        buatPesanan(DataPesanan);
        if (first != 1){
            std::getline(data, temp);
        }
        std::getline(data, temp);                       
        if (temp == ""){                                //Jika data.txt kosong, loop diberhentikan dan fungsi load_data() dihentikan/tidak load data apapun dari data.txt
            break;
        }
        DataPesanan->kode = temp;
        std::getline(data, temp);
        DataPesanan->deskripsi = temp;
        temp = "";
        convert = 0;
        for (int i=0; i<3; i++){
            data >> temp;
            convert = std::stoi(temp);
            DataPesanan->tglPesan[i] = convert;
        }
        temp = "";
        convert = 0;
        for (int i=0; i<3; i++){
            data >> temp;
            convert = std::stoi(temp);
            DataPesanan->tenggat[i] = convert;
        }
        tambah(Q, DataPesanan);
        first = 0;
    }
    data.close();
}