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
    std::string search;
    Pointer prev, temp;
    Pointer PesananBaru = new Pesanan;

    bool ulang = true;
    while(ulang){
        //clrscr();
        title("PROGRAM SISTEM ANTRIAN PEMESANAN TOKO TEKSTIL");
        std::cout << "1. Tambah Pesanan\n2. Hapus Pesanan\n3. Search\n4. Daftar Pesanan\n5. Edit Pesanan\n6. Undo\n7. Save & Exit\n8. Exit without Saving\n";

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
        
        switch (kodeProgram){
            case 1: {//Case Tambah Pesanan
                //clrscr();
                title("TAMBAH PESANAN");

                PesananBaru = new Pesanan;
                buatPesanan(PesananBaru);
                isi_data(Q, PesananBaru);
                tambah(Q, PesananBaru);
                catat_log(S, PesananBaru, 1);
                break;}
            case 2: {//Case Hapus Pesanan
                //clrscr();
                title("HAPUS PESANAN");
                
                std::cout << "Masukan Kode Pesanan  : ";
                std::cin >> search;
                find(Q, prev, search, temp);
                catat_log(S, temp, 2);
                hapusPesanan(Q, search);
                break;}
            case 3: {//case search (display value dari pesanan yang ingin dicari)
                //clrscr();
                title("CARI PESANAN");

                std::cout << "Masukan Kode Pesanan  : ";
                std::cin >> search;
                Search(Q, search);
                break;}
            case 4:  {//case daftar pesanan
                //clrscr();
                title("DAFTAR PESANAN");

                daftarPesanan(Q);
                std::cout << "Tekan Enter untuk kembali ke menu utama\n";
                std::cin.get();
                std::cin.get();
                break;}
            case 5:  {//Case Edit Pesanan
                //clrscr();
                title("EDIT PESANAN");

                std::cout << "Masukan Kode Pesanan  : ";
                std::cin >> search;
                find(Q, prev, search, temp);
                if(temp->kode == search){
                    catat_log(S, temp, 3);
                    std::cout << "CHECK 1\n";
                    isi_data(Q, temp);
                    std::cout << "CHECK 2\n";
                    rearrange(Q, prev, temp);
                    std::cout << "CHECK 3\n";
                }
                break;}
            case 6:{
                //clrscr();
                title("UNDO PERUBAHAN");

                cetak_data(S.head->dataTarget);
                std::cout << "\nJenis operasi : " << S.head->Kategori;
                std::cout << "\n\nApakah anda ingin membatalkan perubahan sebelumnya? (y/Y untuk konfirmasi, n/N untuk tolak)\n";
                while(1){
                    char konfirm;
                    std::cin >> konfirm;
                    if (konfirm == 'Y' || konfirm == 'y'){
                        undo(S, Q);
                        break;
                    }
                    else if (konfirm == 'N' || konfirm == 'n'){
                        break;
                    }
                    else{
                        std::cout << "Input salah, masukkan kembali input konfirmasi :\n";
                    }
                }
                break;}
            case 7:{

                break;}
            case 8:{
                ulang = false;
                break;}
        }
    }

    return 0;
}

