#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <bitset>
#include <string>
#include <ios>
#include <limits>
#include <vector>
#include <cmath>
#define max 10000000

using std::fstream;
using std::ios;
using std::ios_base;
using std::string;
using std::numeric_limits;
using std::cin;
using std::cout;
using std::endl;


using namespace std;

char SA[80],DA[80],binary[8],YA[80],yazi;
char harf,ch;
int x,i, l, t,deci;
long ilk2,son2;long ilk,son;
FILE *ree, *met;

enum Bmp_hata_mesajlari { Dosya_Acma_Hatasi, BMP_Dosyasi_Degil };

void dosya_boyutu(char* Dosya);
void kullanicigirisleri();
void oku(char *dosyaadi);
void boyutlarikarsilastir();
void metin_boyutu(char* Dosya);
void Bitler(char resi, int bits[]);
void Resme_yazi_sakla(char* file,char *file2);
/*cözüm iþlemleri için oluþturulan fonksiyonlar*/
void Dosyayiac( fstream& resim );
void DosyaKontrol( fstream& resim );
void Decode(fstream& resim);
char MetniOku(int bits[]);
void Coz();

int main(){
		 char secim;
		 system("color 02");
		 cout<<"\t -----------------------------------------------------------"<<endl;
   		 cout<<"\t !!!! Bu Program Salih Emre KUL Tarafindan Gelistirildi !!!!"<<endl;
   		 cout<<"\t -----------------------------------------------------------"<<endl;
	     cout<<"\t\n\n";
	     cout<<"\t    +=============================================+"<<endl;
	   	 cout<<"\t    |                  SEK_SOFT                   |"<<endl;
	   	 cout<<"\t    +=====+=======================================+"<<endl;
	   	 cout<<"\t    |     |                                       |"<<endl;
	   	 cout<<"\t    |  1  |  YAZIYI RESME SAKLA                   |"<<endl;
	   	 cout<<"\t    +-----+                                       |"<<endl;
	   	 cout<<"\t    |  2  |  SAKLI YAZIYI CIKAR                   |"<<endl;
	   	 cout<<"\t    +-----+                                       |"<<endl;
	   	 cout<<"\t    |  3  |  CIKIS                                |"<<endl;
	   	 cout<<"\t    |     |                                       |"<<endl;
	   	 cout<<"\t    +=====+=======================================+"<<endl;
	   	 cout<<"\t\n\n\n";
	   	 cout<<"\t     Bir Islem Seciniz..=> ";cin>>secim; 
	switch(secim) {
  				   	   case '1':	
				   				system("cls");
         		   			    cout<<"\n\n";
								kullanicigirisleri();
								boyutlarikarsilastir();
								system("cls");
								return main();
								break;
    				   case '2':
                            system("cls");
                                Coz();	   					
	  							getch();
								system("cls");
								return main();
    				   		    break;
    			       case '3': 
					   			 return 0; 
	            				 default:
								 cout<<"\aSeciminizi Yanlis Yaptiniz Lutfen Tekrar Deneyin..."<<endl;getch();system("cls");
		        				 return main();
								 break;
	 

                  }
} 
void boyutlarikarsilastir(){
                             dosya_boyutu(DA);
								metin_boyutu(SA);
								if ((son2-ilk2)<=((son-ilk)/8)){
                    		   							   cout<<DA<<" \nResim Dosyasinin Icine "<<SA<<" Metin Dosyasi Saklanabilir ";
                    		   							   cout<<"\nDevam Etmek Icin Bir Tusa Basin......";
                    							  		   getch();
                    		   							   Resme_yazi_sakla(DA,SA);
                    		   							   cout<<"\n\n\n Resim Binary'e Basari Ile Cevreeildi!! Devam Etmek Icin Bir Tusa Basi....\n\n";getch();
                    		   							  
                    	   							       }
         					 else{
        	   					 cout<<SA<<"\n Dosyasinin Boyutu Buyuk Oldugu Icin Islem Gerceklestirilemiyor!!";
        	   					 getch();
                              }
     }       
void dosya_boyutu(char* Dosya) {
		ifstream boyut(Dosya,ios::binary | ios::in );
	 	ilk = boyut.tellg();
  		boyut.seekg (0, ios::end);
  		son = boyut.tellg();
  		int D_Boyutu=son-ilk;
      		cout << " Resim Dosyasinin Boyutu : " << (son-ilk) << " Bytes. ";
    		cout << "  Bir Byte'a \n\t\tBir Bitlik Veri Gomulurse "<<(son-ilk)<<" Bytes'a  \n\t\tToplam  : "<<((son-ilk)/8) <<" Bytes Veri Gomulebilinir. ";  
          	boyut.close();
          }
void metin_boyutu(char* Dosya2) {
		ifstream boyut(Dosya2,ios::binary | ios::in );
	 	ilk2 = boyut.tellg();
  		boyut.seekg (0, ios::end);
  		son2 = boyut.tellg();
  		int M_Boyutu=son2-ilk2;
  		if (!Dosya2){
                     cout<<"\n\n";
                     cout<<" "<<SA<<" Metin Dosyasi Okunamiyor.!!!";
                     }
        else{
  		     cout << "\n\n\n Metin Dosyasinin Boyutu : " << (son2-ilk2) << " Bytes. ";
             }
		boyut.close();  							   
  		}
  		
void kullanicigirisleri(){
                         cout<<"\tSifreleme Islemi Icin Bir Resim\n\t Dosyasinin Adi <.bmp > Uzantili Giriniz 	 ==> ";cin>>DA;                                   
                	     cout<<"\n\tSaklanilacak Metin Dosyasinin Adini Giriniz 	 ==> ";cin>>SA;
                         cout<<"\n\tSifrelenen Resim Dosyasi Icin\n\t  <.bmp > Uzantili Yeni Bir Isim Giriniz 	 ==> ";cin>>YA;
                         cout<<"\n\n";
                   
         }
 

void Resme_yazi_sakla(char* file,char *file2){
                            ifstream ResimD(file,ios::in|ios::binary);                                                                            
                            ifstream boyut(file,ios::in | ios::binary);
                    	 	ilk = boyut.tellg();
                      		boyut.seekg (0, ios::end);
                      		son = boyut.tellg();
                            int D_Boyutu=son-ilk;
                            unsigned char ResimI[D_Boyutu];
                            for(int i=0;i<D_Boyutu;i++)ResimD.read(reinterpret_cast< char * >( &ResimI[i] ),1);
                            ifstream MetinD(file2,ios::in); 
                            ifstream boyut2(file2,ios::in | ios::binary);
                    	 	ilk2 = boyut2.tellg();
                      		boyut2.seekg (0, ios::end);
                      		son2 = boyut2.tellg();
                      		int Metin_Boyutu=son2-ilk2;
                            unsigned char MetinI[D_Boyutu];
                            for(int i=0;i<D_Boyutu;i++)MetinD.read(reinterpret_cast< char * >( &MetinI[i] ),1);                            
                            int Dizi_Boyutu = 8*Metin_Boyutu;
                            vector<int> bits(Dizi_Boyutu);
                            for(int i=0;i<Metin_Boyutu;i++){
                                Bitler(MetinI[i],&bits[i*8]);
                            }
                            
                            int Res=0;
                            
                            for(int i=0;i<Dizi_Boyutu;i++){
                                if(Res>D_Boyutu) break;
                                if(i<Dizi_Boyutu)cout<<"Ilk : "<<ResimI[Res+54]%2<<" "<<bits[i]<<"\n";
                                
                                if(ResimI[Res+54]%2==0 && bits[i]==1) {
                                    ResimI[Res+54]=ResimI[Res+54]+1;
                                    ResimI[Res+55]=ResimI[Res+55]+1;
                                    ResimI[Res+56]=ResimI[Res+56]+1;
                                }
                                else if(ResimI[Res+54]%2==1 && bits[i]==0) {
                                    ResimI[Res+54]=ResimI[Res+54]-1;
                                    ResimI[Res+55]=ResimI[Res+55]-1;
                                    ResimI[Res+56]=ResimI[Res+56]-1;
                                }
                                
                                if(i<Dizi_Boyutu) cout<<"son : "<<ResimI[Res+54]%2<<" "<<bits[i]<<"\n";
                                Res+=3;
                                
                            }
                            
                            ofstream Cikis(YA,ios::out|ios::binary);                                                                                    
                            for(int i=0;i<D_Boyutu;i++)
                            Cikis.write(reinterpret_cast< const char * >( &ResimI[i] ),1);
                             
                            }
void Bitler(char resi, int bits[]){
                            int bit;
                            for(int i=0;i<8;i++){
                                bits[i]=resi%2;
                                resi=resi>>1;
                            }
}
//Ýkinci Kýsým
//Resim Dosyasindan Yazýyý Okumak Ýçin Oluþturulan Fonksiyonlar
void Coz(){
			fstream ResimDosyasi;
			try {
				Dosyayiac( ResimDosyasi );
				DosyaKontrol( ResimDosyasi );
				ResimDosyasi.close();
				
			}
			catch(Bmp_hata_mesajlari Hata_Kodu) {
				switch(Hata_Kodu) {
					case Dosya_Acma_Hatasi:
						cout<<"\a\n\t HATA!!!\n\t Dosya Acilamiyor....." << endl;
						break;
					case BMP_Dosyasi_Degil:
						ResimDosyasi.close();
						cout<<"\a\n\t HATA!!!\n\t Dosya BMP Formatinda Degil !!!" << endl;
						break;
					default:
						cout<<"\a\n\t HATA!!!\n\t Hata Olustu...." << endl;
				}
			}
		getch();
		
		
     }
void Dosyayiac(fstream& resim){
					char MDosya_adi[80];string Dosya_adi;
                    cout << " \nResim Dosyasinin Adini Giriniz                   ==>  ";
					cin >> Dosya_adi;
					resim.open( Dosya_adi.c_str(), ios::binary | ios::in);
					if ( resim.fail() )
					throw( Dosya_Acma_Hatasi );
					cout << " \nCozulen Metni Yeni Bir Dosyaya \nKaydetmek Icin TXT Uzantili Bir Isim Giriniz   ==>  ";
					cin >>MDosya_adi;
                    resim.seekg(0, std::ios_base::beg);          
                    ifstream::pos_type begin_pos = resim.tellg();
                    resim.seekg(0, std::ios_base::end);
                    int Fboyut=static_cast<int>(resim.tellg() - begin_pos);
                    cout << " Resim Dosyasinin Boyutu : " <<Fboyut<<endl;
                    resim.seekg(0,ios::beg);
                    unsigned char Resim_Icerigi[Fboyut];
                    for(i=0;i<Fboyut;i++)
                    resim.read(reinterpret_cast< char * >( &Resim_Icerigi[i] ),1);
                    unsigned char BmpIc[Fboyut];
                    for(i=0;i<Fboyut-54;i++){
                                           Resim_Icerigi[i]=Resim_Icerigi[i+54];
                                            }
                    int Deger=0;
                    for(int i=0;i<Fboyut/3;i++){
                                               BmpIc[i]=Resim_Icerigi[i*3];
                                               Deger++;
                							} 
                    int DiziBoyutu = Deger;
                    vector<int> bits(DiziBoyutu);   
                    for(int i=0;i<DiziBoyutu;i++){
                                                if(BmpIc[i]%2==0){ 
                												cout<<(int)BmpIc[i]<<" "<<BmpIc[i]%2<<" "<<i<<endl;bits[i]=0;
                												}
                                                else if(BmpIc[i]%2==1){ 
                                                                    cout<<(int)BmpIc[i]<<" "<<BmpIc[i]%2<<" "<<i<<endl; bits[i]=1;
                													}
												}
                    int MetinBoyutu=DiziBoyutu/8;
                    char Metin[MetinBoyutu];
                    for(int i=0;i<MetinBoyutu;i++){
                                                Metin[i]=MetniOku(&bits[i*8]);
                								}
                    cout<<"\n\n\t\t METIN\n";
                    cout<<"\t=========================\n";
                    for(int i=0;i<MetinBoyutu;i++){
                                                 if(Metin[i]!=EOF)
                                                 cout<<Metin[i];
                								}
                            
                    ofstream SakliMetin(MDosya_adi,ios::out|ios::binary);           
                    for(int i=0;i<MetinBoyutu;i++){ 
                                                  SakliMetin<<Metin[i];
                								}
            }       						
void DosyaKontrol( fstream& resim ){
									char res, res2;
									resim.seekg(0);
									res=resim.get();
									res2=resim.get();
									if ( res!='B' || res2!='M' || resim.fail() )
									throw( BMP_Dosyasi_Degil );
									unsigned int Bitmap;
									resim.seekg(10);
									resim.read(reinterpret_cast<char* >(&Bitmap),4);
									resim.seekg(Bitmap);
									if ( resim.fail() )
									throw( BMP_Dosyasi_Degil );
								}            
int us(int x){
     int s=1;
     for(int i=0;i<x;i++)
     s*=2;
     return s;
        }  
        
char MetniOku(int bits[]){
                           int mt=0;
                           for(int i=0;i<8;i++){
                                                mt=mt+bits[i]*us(i);
                                                }
                            return mt;
 }  



    
    
    
    
    
    
                   
