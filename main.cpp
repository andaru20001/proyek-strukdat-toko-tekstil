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

    bool ulang = true;
    while(ulang){
        std::cout << "PROGRAM SISTEM ANTRIAN PEMESANAN TOKO TEKSTIL\n";
        std::cout << "1. Tambah Pesanan\n2. Hapus Pesanan\n3. Search\n 4. Daftar Pesanan\n5. Edit Pesanan\n6. Undo\n7. Save & Exit\n8. Exit without Saving\n";

        // Tampilkan kode-kode untuk masuk ke salah satu programnya. 
        // Sesuaikan saja dengan urutan yang ada di README.md :
        // 1 untuk program tambah
        // 2 untuk program hapus
        // 3 untuk program search
        // 4 untuk program daftar pesanan
        // 5 untuk program edit pesanan
        // 6 untuk undo
        std::cout << "Masukan Pilihan   :\n";
        std::cin >> kodeProgram;
        
        // Jangan lupa sediakan opsi save dan exit dan exit without saving (mungkin bisa diletakkan di pilihan menu kode 7 dan 8)
        // Exit wihout saving cuma untuk error handling ketika pengguna mau membatalkan semua perubahan
        // Untuk variabel kode untuk pilih programnya disepakati aja kali ya, jadi "kodeProgram"
        std::string search;
        Pointer prev, temp;
        switch (kodeProgram){
            case 1: //Case Tambah Pesanan
                Pointer PesananBaru = new Pesanan;
                buatPesanan(PesananBaru);
                isi_data(Q, PesananBaru, 1);
                tambah(Q, PesananBaru);
                catat_log(S, PesananBaru, 1);
                break;
            case 2: //Case Hapus Pesanan
                std::cout << "Masukan Kode Pesanan  : ";
                std::cin >> search;
                hapusPesanan(Q, search);
                break;
            case 3: //Case Edit Pesanan
                std::cout << "Masukan Kode Pesanan  : ";
                std::cin >> search;
                find(Q, prev, search, temp);
                if(temp->kode == search){
                    // std::cout << temp->kode << '\n';
                    // std::cout << temp->deskripsi << '\n';
                    // std::cout << "Tanggal   : " << temp->tglPesan << '\n';
                    // std::cout << "Tenggat   : " << temp->tenggat << '\n';
                    isi_data(Q, temp, 2);
                }
                break;
            case 4:
                daftarPesanan(Q);
                break;
            case 7:
                ulang = false;
                break;
            case 8:
                ulang = false;
                break;
        }
    }
}