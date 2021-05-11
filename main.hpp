#include <iostream>
#include <string.h>

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
    std::string dataTarget;
    std::string Kategori;
    DataStack* next;
};

typedef DataStack* PointerData;

struct Stack{
    PointerData head;
    PointerData tail;
};

void buatQueue(Queue& Q){ //Fungsi untuk memasukkan default value ke Queue
    Q.head = nullptr;
    Q.tail = nullptr;
}

void buatStack(Stack& S){ //Fungsi untuk memasukkan default value ke Stack
    S.head = nullptr;
    S.tail = nullptr;
}

bool QueueisEmpty(Queue& Q){ //Fungsi untuk mengecek apakah Queue kosong
    if (Q.head == nullptr){
        return 1;
    }
    return 0;
}

void pushStack(Stack& S, PointerData InputData) {
  if (S.head == nullptr){
    S.head = InputData;
  }
  else{
    InputData->next = S.head;
    S.head = InputData;
  }
}

void catat_log(Stack& S, Pointer& InputPesanan, int Kategori){ //Fungsi untuk mencatat perubahan ke stack. Harus dimasukkan ke fungsi-fungsi yang melakukan perubahan data
    // Kategori diisi sesuai dengan program apa yang dijalankan sebelumnya
    // 1 = tambah
    // 2 = hapus
    // 3 = edit

    // Bagian tambah
    if (Kategori == 1){
        PointerData newData = new DataStack;
        newData->dataTarget = InputPesanan->kode;
        newData->Kategori = "Tambah";
        pushStack(S, newData);
    }
}

void buatPesanan(Pointer& PesananBaru){ //Fungsi untuk memasukkan default value ke Pointer PesananBaru
    PesananBaru->kode = "";
    PesananBaru->deskripsi = "";
    for (int i=1; i<3; i++){
        PesananBaru->tenggat[i] = 0;
    }
    PesananBaru->next = nullptr;
}

std::string tambah_digit (int angka, int digitTarget){ //Fungsi untuk mengubah sebuah integer dengan digit tertentu menjadi string dengan jumlah digit yang diinginkan dengan menambahkan leading zero
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

void isi_data(Queue Q, Pointer& Pesanan, int kategori){ //Fungsi untuk mengisi informasi mengenai Pesanan; bisa juga digunakan untuk menu edit
    //Memasukkan deskipsi pesanan
    std::cout << "Masukkan deskripsi pesanan :\n";
    std::cin >> Pesanan->deskripsi;

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
            if (temp->tglPesan[0] == Pesanan->tglPesan[0] && temp->tglPesan[1] == Pesanan->tglPesan[1] && temp->tglPesan[2] == Pesanan->tglPesan[2]){
                jmlPesananHariIni++;
            }
        }
    }
    //Kategori digunakan untuk menentukan apakah fungsi ini digunakan untuk menambah pesanan atau mengedit pesanan
    //1 = Menambah pesanan
    //2 = Mengedit pesanan

    if (kategori == 1){
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
    
}

void tambah(Queue& Q, Pointer& PesananBaru){ //Fungsi untuk memasukkan pesanan ke priority queue. Priority key yang digunakan adalah tanggal tenggat waktu
    if (QueueisEmpty(Q)){
        Q.head = PesananBaru;
        Q.tail = PesananBaru;
    }
    
    else{
        Pointer temp = Q.head;
        Pointer temp2 = nullptr;
        // int check1 = std::stoi(PesananBaru->kode) % 10000; //Mengambil 4 digit paling belakang dari kode pesanan yang akan ditambahkan untuk acuan pesanan ke berapa pada tanggal yang sama
        // int check2;

        while (1){
            if (temp == nullptr){
                break;
            }
            
            if (PesananBaru->tenggat[2] >= temp->tenggat[2]){
                if (PesananBaru->tenggat[1] >= temp->tenggat[1]){
                    if (PesananBaru->tenggat[0] >= temp->tenggat[0]){
                        break;
                    }
                }
            }

            temp2 = temp;
            temp = temp->next;
        }
    
        if (temp2 == nullptr){ //Jika posisi ditemukan di awal Queue
            Q.head = PesananBaru;
            PesananBaru->next = temp;
        }
        else if (temp == nullptr){ //Jika posisi ditemukan di akhir Queue
            Q.tail = PesananBaru;
            temp2->next = PesananBaru;
        }
        else{
            PesananBaru->next = temp; //Jika posisi ditemukan di tengah-tengah Queue
            temp2->next = PesananBaru;
        }
    }
}

void find(Queue& Q, Pointer& previous, std::string search, Pointer& temp) {
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

void hapusPesanan(Queue& Q, std::string search){                //menghapus pesanan yang diinginkan
    Pointer temp;
    Pointer previous;
    if(Q.head == nullptr){
        std::cout<<"pesanan kosong"<<"\n";
        return;
    }
    find(Q, previous, search, temp);
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
}

void undo (Stack& S, Queue& Q){
    Pointer prev = nullptr;
    Pointer temp = nullptr;
    find(Q, prev, S.head->dataTarget, temp);

    if (S.head->Kategori == "Tambah"){
        prev->next = temp->next;
        temp->next = nullptr;
        delete temp;
    }
}

void daftarPesanan(const Queue& Q){
    Pointer temp = Q.head;
    while(temp){
        int i = 1;
        std::cout << "Pesanan ke-" << i << '\n';
        std::cout << "Kode " << temp->kode << '\n';
        std::cout << "Deskripsi : " << temp->deskripsi << '\n';
        std::cout << "Tanggal   : " << temp->tglPesan[0] << " " << temp->tglPesan[1] << " " << temp->tglPesan[2] << '\n';
        std::cout << "Tenggat   : " << temp->tenggat[0] << " " << temp->tenggat[1] << " " << temp->tenggat[2] << '\n';
        temp = temp->next;
    }
}

void Search(Queue& Q, std::string search){                       //nambahin fungsi search untuk display value dari pesanan yang dicari
    Pointer previous;
    Pointer temp;
    find(Q, previous, search, temp);
    std::cout << "Kode " << temp->kode << '\n';
    std::cout << "Deskripsi : " << temp->deskripsi << '\n';
    std::cout << "Tanggal   : " << temp->tglPesan[0] << " " << temp->tglPesan[1] << " " << temp->tglPesan[2] << '\n';
    std::cout << "Tenggat   : " << temp->tenggat[0] << " " << temp->tenggat[1] << " " << temp->tenggat[2] << '\n';
}