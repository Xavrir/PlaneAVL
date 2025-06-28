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

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Plane{
	char *Flight_code;
	char *aircraft_type;
	int fuel;
	double Eficiency;
	double MaxDistance;
	Plane *right;
	Plane *left;
	int height;
}Plane;


Plane *root = NULL;

int max(int a, int b){
	return (a > b) ? a : b;
}


int get_height(Plane *n){
	if(!n) return 0;
	return n->height;
}


int calc_height(Plane *n){
	if(!n) return 0;
	return max(get_height(n->left), get_height(n->right)) + 1;
}

int balance_vec(Plane *n){
	if(!n) return 0;
	return get_height(n->left) - get_height(n->right);

}



Plane *minvalue(Plane *n){
	Plane *curr = n;
	while(curr->left){
		curr = curr->left;
	}
	return curr;
}

Plane *RightRotate(Plane *n){
	Plane *pivot = n->left;
	Plane *cut = pivot->right;
	
	pivot->right = n;
	n->left = cut;
	
	n->height = calc_height(n);
	pivot->height = balance_vec(pivot);
	return pivot;
}

Plane *LeftRotate(Plane *n){
	Plane *pivot = n->right;
	Plane *cut = pivot->left;
	
	pivot->left = n;
	n->right = cut;
	
	n->height = calc_height(n);
	pivot->height = balance_vec(pivot);
	return pivot;
}

Plane *create_node(char *Flight_code, char *aircraft_type, int fuel, double Eficiency, double MaxDistance){
	Plane *n = (Plane*)malloc(sizeof(Plane));
	n->Flight_code = strdup(Flight_code);
	n->aircraft_type = strdup(aircraft_type);
	n->fuel = fuel;
	n->Eficiency = Eficiency;
	n->MaxDistance = MaxDistance;
	n->right = NULL;
	n->left = NULL;
	n->height = 1;
	return n;
	
}


Plane *insert(Plane *n, char *Flight_code, char *aircraft_type, int fuel, double Eficiency, double MaxDistance){
	if(!n)return create_node(Flight_code, aircraft_type, fuel, Eficiency, MaxDistance);
	if(MaxDistance < n->MaxDistance){
		n->left = insert(n->left, Flight_code, aircraft_type, fuel, Eficiency, MaxDistance);
	}
	else if(MaxDistance > n->MaxDistance){
		n->right = insert(n->right, Flight_code, aircraft_type, fuel, Eficiency, MaxDistance);
	}
	else{
		printf("Data tersebut sudah pernah dimasukkan sebelumnya..\n");
	}
	n->height = calc_height(n);
	int balance = balance_vec(n);
	
//	LL
	if(balance > 1 && MaxDistance < n->left->MaxDistance){
		return RightRotate(n);
	}
	
	if(balance > 1 && MaxDistance > n->left->MaxDistance){
		n->left = LeftRotate(n->left);
		return RightRotate(n);
	}
	
	if(balance < -1 && MaxDistance > n->right->MaxDistance){
		return LeftRotate(n);
	}
	
	if(balance < -1 && MaxDistance < n->right->MaxDistance){
		n->right = RightRotate(n->right);
		return LeftRotate(n);
	}
	
	return n;
	

}



Plane *remove(Plane *n, char *Flight_code, char *aircraft_type, int fuel, double Eficiency, double MaxDistance){
	if(!n) return n;
	if(strcmp(n->Flight_code, Flight_code) > 0){
		n->right = remove(n->right, Flight_code, aircraft_type, fuel, Eficiency, MaxDistance);
	}
	else if(strcmp(n->Flight_code, Flight_code) < 0){
		n->left = remove(n->left, Flight_code, aircraft_type, fuel, Eficiency, MaxDistance);
	}
	else{
		if((!n->left) || (!n->right)){
			Plane *temp = n->left ? n->left : n->right;
			if(temp == NULL){
				temp = n;
				n = NULL;
			}
			else{
				*n = *temp;
			}
			free(temp->Flight_code);
			free(temp->aircraft_type);
			free(temp);
			
		}
		else{
			Plane *temp = minvalue(n->right);
			
			n->Flight_code = strdup(temp->Flight_code);
			n->aircraft_type = strdup(temp->aircraft_type);
			n->fuel = temp->fuel;
			n->Eficiency = temp->Eficiency;
			n->MaxDistance = temp->MaxDistance;
			
			n->right = remove(n->right, temp->Flight_code, temp->aircraft_type, temp->fuel, temp->Eficiency, temp->MaxDistance);
		}
	}
	
	n->height = calc_height(n);
	int balance = balance_vec(n);
	
//	LL
	if(balance > 1 && MaxDistance < n->left->MaxDistance){
		return RightRotate(n);
	}
	
	if(balance > 1 && MaxDistance > n->left->MaxDistance){
		n->left = LeftRotate(n->left);
		return RightRotate(n);
	}
	
	if(balance < -1 && MaxDistance > n->right->MaxDistance){
		return LeftRotate(n);
	}
	
	if(balance < -1 && MaxDistance < n->right->MaxDistance){
		n->right = RightRotate(n->right);
		return LeftRotate(n);
	}
	
	return n;
	
	
}


void search(Plane *n, double MaxDistance){
	if(!n || n->MaxDistance == MaxDistance)
		printf("Flight Code: %s\nAircraft Type: %s\nCurrent Fuel: %d\nFuel Efficiency: %.1f\nMax Distance: %.1f\n", n->Flight_code, n->aircraft_type, n->fuel, n->Eficiency, n->MaxDistance);
	if(n->MaxDistance < MaxDistance){
		search(n->right, MaxDistance);
	search(n->left, MaxDistance);
	}
	
	
}

void searchA(Plane *n, char *Flight_code){
	if(!n || strcmp(Flight_code, n->Flight_code) == 0)
		return;
	if(strcmp(Flight_code, n->Flight_code) > 0) {
		searchA(n->right, Flight_code);
	}
	searchA(n->left, Flight_code);
}

void inorderA(Plane *n){ // ascending
	if(n){
		inorderA(n->left);
		printf("Flight Code: %s\nAircraft Type: %s\nCurrent Fuel: %d\nFuel Efficiency: %.1f\nMax Distance: %.1f\n", n->Flight_code, n->aircraft_type, n->fuel, n->Eficiency, n->MaxDistance);
		inorderA(n->right);
	}
}

void inorderD(Plane *n){ // Descending
	if(n){
		inorderD(n->right);
		printf("Flight Code: %s\nAircraft Type: %s\nCurrent Fuel: %d\nFuel Efficiency: %.1f\nMax Distance: %.1f\n", n->Flight_code, n->aircraft_type, n->fuel, n->Eficiency, n->MaxDistance);
		inorderD(n->left);
	}
}


void Show_Long_Distance(Plane *n){
	Plane *curr = n;
	while(curr->right){
		curr = curr->right;
	}
	printf("Flight Code: %s\nAircraft Type: %s\nCurrent Fuel: %d\nFuel Efficiency: %.1f\nMax Distance: %.1f\n", n->Flight_code, n->aircraft_type, n->fuel, n->Eficiency, n->MaxDistance);

}

void Show_short_Distance(Plane *n){
	Plane *curr = n;
	while(curr->left){
		curr = curr->left;
	}
	printf("Flight Code: %s\nAircraft Type: %s\nCurrent Fuel: %d\nFuel Efficiency: %.1f\nMax Distance: %.1f\n", n->Flight_code, n->aircraft_type, n->fuel, n->Eficiency, n->MaxDistance);

}


int main(){
	int choice;
	char Flight_code[100];
	char Aircraft_type[100];
	int fuel;
	double Eficiency;
	double MaxDistance;
	do{
		printf("==================================================\n");
		printf("====SkyLine Airways - Aircraft Management System==\n");
		printf("==================================================\n");
		printf("1. Add New Aircraft\n2. Remove Aircraft\n3. Refuel Aircraft\n4. Search Aircraft by Max Distance\n5. Display All Aircraft (Ascending by Distance)\n6. Display All Aircraft (Descending by Distance)\n7. Show Aircraft with Longest Range\n8. Show Aircraft with Shortest Range\n9. Find Aircraft in Distance Range\n10. Exit\n");
		printf("Enter your choice (1-10): ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("== Add New Aircraft ==\n");
				printf("Flight code: ");getchar();
				fgets(Flight_code, 100, stdin);
				printf("Aircraft Type: ");
				fgets(Aircraft_type, 100, stdin);
				printf("Current Fuel: ");
				scanf("%d", &fuel);
				printf("Fuel Efficency: ");
				scanf("%lf", &Eficiency);
				MaxDistance = Eficiency * fuel;
				root = insert(root, Flight_code, Aircraft_type, fuel, Eficiency, MaxDistance);
				printf("Inserted...");
				break;
			case 2:
				printf("== Remove Aircraft ==\n");
				printf("Flight code to remove: ");
				getchar();
				fgets(Flight_code, 100, stdin);
				searchA(root, Flight_code);
				root = remove(root, Flight_code, Aircraft_type, fuel, Eficiency, MaxDistance);
				printf("Removing...");
				break;
			case 5:
				inorderA(root);
				break;
			case 6:
				inorderD(root);
				break;
			default:
				printf("Wrong input");
				continue;
				
				
		}
	}while(choice != 10);
	return 0;
}

