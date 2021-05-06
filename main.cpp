#include "main.hpp"

int main(){
    // Di sini untuk isi bagian menu

    // Menu isinya header (Nama programnya, dibingkai juga boleh),
    
    
    // Inisialisasi queue sama stack,
    int kodeProgram = 0;
    Stack S;
    buatStack(S);
    Queue Q;
    buatQueue(Q);

    // Backup data yang sudah disimpan,


    // Tampilkan kode-kode untuk masuk ke salah satu programnya. 
    // Sesuaikan saja dengan urutan yang ada di README.md :
    // 1 untuk program tambah
    // 2 untuk program hapus
    // 3 untuk program search
    // 4 untuk program daftar pesanan
    // 5 untuk program edit pesanan
    // 6 untuk undo
    std::cin >> kodeProgram;
    
    // Jangan lupa sediakan opsi save dan exit dan exit without saving (mungkin bisa diletakkan di pilihan menu kode 7 dan 8)
    // Exit wihout saving cuma untuk error handling ketika pengguna mau membatalkan semua perubahan
    // Untuk variabel kode untuk pilih programnya disepakati aja kali ya, jadi "kodeProgram"

    switch (kodeProgram){
        case 1:
            Pointer PesananBaru = new Pesanan;
            buatPesanan(PesananBaru);
            isi_data(Q, PesananBaru);
            tambah(Q, PesananBaru);
            catat_log(S, PesananBaru, 1);
            break;
    }
}