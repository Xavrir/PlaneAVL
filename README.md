# PlaneAVL
Latihan AVL Menggunakan konsep pesawat terbang
/*
	Soal AVL Tree: Sistem Manajemen Pesawat
Deskripsi Masalah
Anda diminta untuk membuat sistem manajemen pesawat menggunakan AVL Tree untuk maskapai penerbangan "SkyLine Airways". Sistem ini akan menyimpan informasi pesawat berdasarkan jarak tempuh maksimum yang dapat dicapai dengan bahan bakar saat ini.
Struktur Data
Setiap node dalam AVL Tree menyimpan informasi:

Flight Code: Kode penerbangan (string, misal: "GA123")
Aircraft Type: Jenis pesawat (string, misal: "Boeing 737")
Current Fuel: Bahan bakar saat ini dalam liter (integer)
Fuel Efficiency: Efisiensi bahan bakar dalam km/liter (double)
Max Distance: Jarak tempuh maksimum = Current Fuel � Fuel Efficiency (double)

Key untuk AVL Tree: Max Distance (jarak tempuh maksimum)
Data Sample
Flight CodeAircraft TypeCurrent Fuel (L)Efficiency (km/L)Max Distance (km)GA150Boeing 73725003.28000LH401Airbus A32018003.56300SQ925Boeing 77742002.811760EK205Airbus A38055002.513750QZ8501Airbus A32015003.55250JT610Boeing 73722003.27040CI736Boeing 78738004.015200
Tugas
1. Implementasi Struktur (25 poin)
Buat struktur AVL Tree dengan fungsi-fungsi dasar:

insert() - Menambah pesawat baru
delete() - Menghapus pesawat berdasarkan flight code
search() - Mencari pesawat berdasarkan max distance
display_inorder() - Tampilkan urutan ascending (jarak terpendek ke terpanjang)
display_reverse() - Tampilkan urutan descending (jarak terpanjang ke terpendek)

2. Fungsi Operasional (25 poin)
Implementasikan fungsi-fungsi khusus:

refuel(flight_code, additional_fuel) - Mengisi bahan bakar dan update max distance
find_longest_range() - Mencari pesawat dengan jarak tempuh terpanjang
find_shortest_range() - Mencari pesawat dengan jarak tempuh terpendek
aircraft_in_range(min_distance, max_distance) - Tampilkan pesawat dalam rentang jarak tertentu

3. Menu Interaktif (20 poin)
Buat menu dengan pilihan:

Tambah pesawat baru
Hapus pesawat
Isi bahan bakar (refuel)
Cari pesawat berdasarkan jarak maksimum
Tampilkan semua pesawat (ascending)
Tampilkan semua pesawat (descending)
Tampilkan pesawat dengan jarak terpanjang
Tampilkan pesawat dengan jarak terpendek
Cari pesawat dalam rentang jarak
Keluar

4. Analisis Kasus (30 poin)
Kasus A: Insert data sample di atas satu per satu dan gambarkan proses pembentukan AVL Tree setelah setiap insertion. Tunjukkan rotasi yang terjadi!
Kasus B: Dari tree yang sudah terbentuk, lakukan operasi berikut berurutan:

Refuel pesawat "QZ8501" dengan 800 liter tambahan
Hapus pesawat "LH401"
Tambah pesawat baru: "AI101", "Boeing 747", 4800L, 2.6 km/L
Gambarkan tree setelah setiap operasi!

Kasus C: Jawab pertanyaan berikut berdasarkan tree final:

Pesawat mana yang memiliki jarak tempuh terpanjang?
Pesawat mana yang memiliki jarak tempuh terpendek?
Berapa pesawat yang memiliki jarak tempuh antara 7000-12000 km?
Jika pesawat "GA150" diisi bahan bakar hingga penuh (kapasitas maksimum 3000L), berapa jarak maksimum yang bisa dicapai?
*/
