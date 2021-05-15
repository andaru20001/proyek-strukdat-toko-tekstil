//File ini cuma buat coret-coretan; buat debugging dan testing

#include "main.hpp"

int main(){
    Queue Q;
    buatQueue(Q);
    std::cout << "CHECK\n";
    Pointer PesananBaru = new Pesanan;
    Pointer PesananBaru2 = new Pesanan;
    std::cout << "CHECK\n";
    
    buatPesanan(PesananBaru);
    std::cout << "CHECK 1\n";
    isi_data(Q, PesananBaru);
    std::cout << "CHECK 2\n";
    tambah(Q, PesananBaru);
    std::cout << "CHECK 3\n";

    buatPesanan(PesananBaru2);
    std::cout << "CHECK 4\n";
    isi_data(Q, PesananBaru2);
    std::cout << "CHECK 5\n";
    tambah(Q, PesananBaru2);
    std::cout << "CHECK 6\n";

    return 0;
}