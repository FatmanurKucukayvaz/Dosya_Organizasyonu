#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <istream>
#include <ostream>
#include <math.h>

using namespace std;

int katlama_adr(int sayi)
{
    int dizi[9];
    int i,a,b,c;
    for(i=8;i>=0;i--){
        dizi[i]=sayi%10;
        sayi=sayi/10;
    }
    int adr;
    a=dizi[8]*100+dizi[7]*10+dizi[6];
    b=dizi[3]*100+dizi[4]*10+dizi[5];
    c=dizi[2]*100+dizi[1]*10+dizi[0];
    adr=a+b+c;
    adr=adr%1000;
    return adr;
}
int kare_ort_adr(int sayi)
{
    unsigned kare_sayi;
    int dizi[11];  //10
    int i,adr2;
    kare_sayi=pow(sayi,2);
    for(i=10;i>=0;i--){ //i=9
        dizi[i]=kare_sayi%10;
        kare_sayi=kare_sayi/10;
    }
    adr2=dizi[3]*100+dizi[4]*10+dizi[5];
    return adr2;
}

static const char harfler[] = "abcdefghijklmnopqrstuvwxyz";
int string_uzunluk = sizeof(harfler) - 1;

int main()
{
    ofstream randomDosya("Kayit.txt",ios::out);
    srand(time(NULL));
    srand(time(0));
    int sayi,i;

    for(i=1;i<=500;i++){
        sayi=100000000+rand()%900000000;
        //sayi=100100001;
        randomDosya<<sayi<<" ";
        for(int j=0; j < 10; j++)
        {
            randomDosya<< harfler[rand() % string_uzunluk];
        }
        randomDosya<<" ";
        for(int j=0; j < 10; j++)
        {
            randomDosya<< harfler[rand() % string_uzunluk];
        }
        randomDosya<<endl;
    }
    randomDosya.close();
    int yer;
    int okulno;
    string ad,soyad;
    int say=0,j;
    int index[500];
    for(i=0;i<500;i++){
        index[i]=-1;
    }
    ifstream dosyaOku ("Kayit.txt",ios::in);
    ofstream bolenKalan;
    bolenKalan.open("BolenKalan.txt",ios::out);
    for(i=0;i<1000;i++){
        bolenKalan<<"                               \n";
    }
    for(i=0;i<500;i++){
        say=0;
        dosyaOku>>okulno>>ad>>soyad;
        yer=okulno%1001;
        for(j=0;j<500;j++){
            if(index[j]==yer)
                say++;
        }
        index[i]=yer;
        bolenKalan.seekp(0);
        yer=yer+say;
        bolenKalan.seekp(yer*33);
        bolenKalan<<okulno<<" "<<ad<<" "<<soyad;
    }
    bolenKalan.close();
    ofstream bolenKalanAyrik;
    bolenKalanAyrik.open("BolenKalanAyrik.txt");
    for(i=0;i<2000;i++){
        bolenKalanAyrik<<"                               \n";
    }
    for(i=0;i<500;i++){
        index[i]=-1;
    }
    dosyaOku.seekg(0);
    for(i=0;i<500;i++){
        say=0;
        dosyaOku>>okulno>>ad>>soyad;
        yer=okulno%1001;
        for(j=0;j<500;j++){
            if(index[j]==yer)
                say++;
        }
        index[i]=yer;
        if(say==0){
            bolenKalanAyrik.seekp(0);
            bolenKalanAyrik.seekp(yer*33);
            bolenKalanAyrik<<okulno<<" "<<ad<<" "<<soyad;
        }
        else{
            bolenKalanAyrik.seekp(0);
            yer=yer+say+1000-1;
            bolenKalanAyrik.seekp(yer*33);
            bolenKalanAyrik<<okulno<<" "<<ad<<" "<<soyad;
        }
    }
    bolenKalanAyrik.close();
    ofstream katlama;
    katlama.open("Katlama.txt");
    for(i=0;i<1000;i++){
        katlama<<"                               \n";
    }
    for(i=0;i<500;i++){
        index[i]=-1;
    }
    dosyaOku.seekg(0);
    for(i=0;i<500;i++){
        say=0;
        dosyaOku>>okulno>>ad>>soyad;
        yer=katlama_adr(okulno);
        for(j=0;j<500;j++){
            if(index[j]==yer)
                say++;
        }
        index[i]=yer;
        katlama.seekp(0);
        yer=yer+say;
        katlama.seekp(yer*33);
        katlama<<okulno<<" "<<ad<<" "<<soyad;
    }
    katlama.close();
    ofstream katlamaAyrik;
    katlamaAyrik.open("KatlamaAyrik.txt");
    for(i=0;i<2000;i++){
        katlamaAyrik<<"                               \n";
    }
    for(i=0;i<500;i++){
        index[i]=-1;
    }
    dosyaOku.seekg(0);
    for(i=0;i<500;i++){
        say=0;
        dosyaOku>>okulno>>ad>>soyad;
        yer=katlama_adr(okulno);
        for(j=0;j<500;j++){
            if(index[j]==yer)
                say++;
        }
        index[i]=yer;
        if(say==0){
            katlamaAyrik.seekp(0);
            katlamaAyrik.seekp(yer*33);
            katlamaAyrik<<okulno<<" "<<ad<<" "<<soyad;
        }
        else{
            katlamaAyrik.seekp(0);
            yer=yer+say+1000-1;
            katlamaAyrik.seekp(yer*33);
            katlamaAyrik<<okulno<<" "<<ad<<" "<<soyad;
        }
    }
    katlamaAyrik.close();
    ofstream kareOrt;
    kareOrt.open("KareOrtasi.txt");
    for(i=0;i<1000;i++){
        kareOrt<<"                               \n";
    }
    for(i=0;i<500;i++){
        index[i]=-1;
    }
    dosyaOku.seekg(0);
    for(i=0;i<500;i++){
        say=0;
        dosyaOku>>okulno>>ad>>soyad;
        yer=kare_ort_adr(okulno);
        for(j=0;j<500;j++){
            if(index[j]==yer)
                say++;
        }
        index[i]=yer;
        kareOrt.seekp(0);
        yer=yer+say;
        kareOrt.seekp(yer*33);
        kareOrt<<okulno<<" "<<ad<<" "<<soyad;
    }
    kareOrt.close();
    ofstream kareOrtAyrik;
    kareOrtAyrik.open("KareOrtasiAyrik.txt");
    for(i=0;i<2000;i++){
        kareOrtAyrik<<"                               \n";
    }
    for(i=0;i<500;i++){
        index[i]=-1;
    }
    dosyaOku.seekg(0);
    for(i=0;i<500;i++){
        say=0;
        dosyaOku>>okulno>>ad>>soyad;
        yer=kare_ort_adr(okulno);
        for(j=0;j<500;j++){
            if(index[j]==yer)
                say++;
        }
        index[i]=yer;
        if(say==0){
            kareOrtAyrik.seekp(0);
            kareOrtAyrik.seekp(yer*33);
            kareOrtAyrik<<okulno<<" "<<ad<<" "<<soyad;
        }
        else{
            kareOrtAyrik.seekp(0);
            yer=yer+say+1000-1;
            kareOrtAyrik.seekp(yer*33);
            kareOrtAyrik<<okulno<<" "<<ad<<" "<<soyad;
        }
    }
    int aranacak;
    int secim;
    int sec;
    int adr;
    int adr1;
    int sayac=0;
    int elde;
    int hiz[6];
    kareOrtAyrik.close();
    while(1)
    {
    cout<<"Arama yapmak icin 1'e programdan cikmak icin 0'a basin: ";
    cin>>sec;
    if(sec==1){
    cout<<"Kayitlarda aramak istediginiz kisinin numarasini girin: ";
    cin>>aranacak;
    cout<<"Arama yapmak icin 1'e kisi numarasini degistirmek icin 0'a basin: ";
    cin>>secim;
    switch(secim)
    {
    case 0:
        {
            cout<<"Kayitlarda aramak istediginiz kisinin numarasini girin: ";
            cin>>aranacak;
            break;
        }
    case 1:
        {
            hiz[0]=1;
            dosyaOku.seekg(0);
            for(i=0;i<500;i++){
                dosyaOku>>okulno>>ad>>soyad;
                if(okulno==aranacak){
                    cout<<"LINEER DOSYADAKI KAYIT: "<<okulno<<" "<<ad<<" "<<soyad<<endl<<endl;
                    hiz[0]++;
                    break;
                }
                if(i==499){
                    cout<<"BULUNAMADI"<<endl;
                    break;
                }
                hiz[0]++;
                }
            hiz[1]=5;
            ifstream bolenKalanOku("BolenKalan.txt",ios::in);
            adr=aranacak%1001;
            bolenKalanOku.seekg(0);
            bolenKalanOku.seekg(adr*33);
            bolenKalanOku>>okulno>>ad>>soyad;
            if(okulno==aranacak){
                cout<<"BOLEN KALAN DOSYASINDAKI KAYIT: "<<okulno<<" "<<ad<<" "<<soyad<<endl<<endl;
                hiz[1]++;
            }
            else{
                adr1=adr;
                while(okulno!=aranacak){
                    sayac++;
                    adr1++;
                    adr=adr1%1001;
                    bolenKalanOku.seekg(0);
                    bolenKalanOku.seekg(adr*33);
                    bolenKalanOku>>okulno>>ad>>soyad;
                    if(okulno==aranacak){
                        cout<<"BOLEN KALAN DOSYASINDAKI KAYIT: "<<okulno<<" "<<ad<<" "<<soyad<<endl<<endl;
                        hiz[1]=hiz[1]+6;
                        break;
                    }
                    hiz[1]=hiz[1]+6;
                    if(sayac==500)
                        break;
                }
            }
            hiz[2]=5;
            ifstream bolenKalanAyrikOku("BolenKalanAyrik.txt",ios::in);
            say=0;
            adr=aranacak%1001;
            bolenKalanAyrikOku.seekg(0);
            bolenKalanAyrikOku.seekg(adr*33);
            bolenKalanAyrikOku>>okulno>>ad>>soyad;
            if(okulno==aranacak){
                cout<<"BOLEN KALAN AYRIK DOSYASINDAKI KAYIT: "<<okulno<<" "<<ad<<" "<<soyad<<endl<<endl;
                hiz[2]++;
            }
            else{
                adr1=adr;
                sayac=0;
                while(okulno!=aranacak){
                sayac++;
                say++;
                adr=adr1+say+1000-1;
                bolenKalanAyrikOku.seekg(0);
                bolenKalanAyrikOku.seekg(adr*33);
                bolenKalanAyrikOku>>okulno>>ad>>soyad;
                if(okulno==aranacak){
                    cout<<"BOLEN KALAN AYRIK DOSYASINDAKI KAYIT: "<<okulno<<" "<<ad<<" "<<soyad<<endl<<endl;
                    hiz[2]=hiz[2]+6;
                    break;
                }
                hiz[2]=hiz[2]+6;
                if(sayac==500)
                        break;
                }
            }
            hiz[3]=5;
            ifstream katlamaOku("Katlama.txt",ios::in);
            adr=katlama_adr(aranacak);
            katlamaOku.seekg(0);
            katlamaOku.seekg(adr*33);
            katlamaOku>>okulno>>ad>>soyad;
            if(okulno==aranacak){
                cout<<"KATLAMA DOSYASINDAKI KAYIT: "<<okulno<<" "<<ad<<" "<<soyad<<endl<<endl;
                hiz[3]++;
            }
            else{
                sayac=0;
                while(okulno!=aranacak){
                    sayac++;
                    adr++;
                    katlamaOku.seekg(0);
                    katlamaOku.seekg(adr*33);
                    katlamaOku>>okulno>>ad>>soyad;
                    if(okulno==aranacak){
                        cout<<"KATLAMA DOSYASINDAKI KAYIT: "<<okulno<<" "<<ad<<" "<<soyad<<endl<<endl;
                        hiz[3]++;
                        break;
                    }
                    hiz[3]=hiz[3]+5;
                    if(sayac==500)
                        break;
                }
            }
            hiz[4]=5;
            ifstream katlamaAyrikOku("KatlamaAyrik.txt",ios::in);
            say=0;
            adr=katlama_adr(aranacak);
            katlamaAyrikOku.seekg(0);
            katlamaAyrikOku.seekg(adr*33);
            katlamaAyrikOku>>okulno>>ad>>soyad;
            if(okulno==aranacak){
                cout<<"KATLAMA AYRIK DOSYASINDAKI KAYIT: "<<okulno<<" "<<ad<<" "<<soyad<<endl<<endl;
                hiz[4]++;
            }
            else{
                adr1=adr;
                sayac=0;
                while(okulno!=aranacak){
                sayac++;
                say++;
                adr=adr1+say+1000-1;
                katlamaAyrikOku.seekg(0);
                katlamaAyrikOku.seekg(adr*33);
                katlamaAyrikOku>>okulno>>ad>>soyad;
                if(okulno==aranacak){
                    cout<<"KATLAMA AYRIK DOSYASINDAKI KAYIT: "<<okulno<<" "<<ad<<" "<<soyad<<endl<<endl;
                    hiz[4]++;
                    break;
                }
                hiz[4]=hiz[4]+6;
                if(sayac==500)
                        break;
                }
            }
            hiz[5]=5;
            ifstream kareOrtOku("KareOrtasi.txt",ios::in);
            adr=kare_ort_adr(aranacak);
            kareOrtOku.seekg(0);
            kareOrtOku.seekg(adr*33);
            kareOrtOku>>okulno>>ad>>soyad;
            if(okulno==aranacak){
                cout<<"KARE ORTASI DOSYASINDAKI KAYIT: "<<okulno<<" "<<ad<<" "<<soyad<<endl<<endl;
                hiz[5]++;
            }
            else{
                sayac=0;
                while(okulno!=aranacak){
                    sayac++;
                    adr++;
                    kareOrtOku.seekg(0);
                    kareOrtOku.seekg(adr*33);
                    kareOrtOku>>okulno>>ad>>soyad;
                    if(okulno==aranacak){
                        cout<<"KARE ORTASI DOSYASINDAKI KAYIT: "<<okulno<<" "<<ad<<" "<<soyad<<endl<<endl;
                        hiz[5]++;
                        break;
                    }
                    hiz[5]=hiz[5]+5;
                    if(sayac==500)
                        break;
                }
            }
            hiz[6]=5;
            ifstream kareOrtAyrikOku("KareOrtasiAyrik.txt",ios::in);
            say=0;
            adr=kare_ort_adr(aranacak);
            kareOrtAyrikOku.seekg(0);
            kareOrtAyrikOku.seekg(adr*33);
            kareOrtAyrikOku>>okulno>>ad>>soyad;
            if(okulno==aranacak){
                cout<<"KARE ORTASI AYRIK DOSYASINDAKI KAYIT: "<<okulno<<" "<<ad<<" "<<soyad<<endl<<endl;
                hiz[6]++;
            }
            else{
                adr1=adr;
                sayac=0;
                while(okulno!=aranacak){
                sayac++;
                say++;
                adr=adr1+say+1000-1;
                kareOrtAyrikOku.seekg(0);
                kareOrtAyrikOku.seekg(adr*33);
                kareOrtAyrikOku>>okulno>>ad>>soyad;
                if(okulno==aranacak){
                    cout<<"KARE ORTASI AYRIK DOSYASINDAKI KAYIT: "<<okulno<<" "<<ad<<" "<<soyad<<endl<<endl;
                    hiz[6]++;
                    break;
                }
                hiz[6]=hiz[6]+6;
                if(sayac==500)
                        break;
                }
            }
            elde=hiz[0];
            for(i=1;i<7;i++){
                if(hiz[i]<elde){
                    elde=hiz[i];
                }
            }
            for(i=0;i<7;i++){
                if(elde==hiz[i]){
                    if(i==0)
                        cout<<"EN HIZLI ARAMA YAPAN YONTEM LINEER DOSYA"<<endl;
                    if(i==1)
                        cout<<"EN HIZLI ARAMA YAPAN YONTEM BOLEN KALAN YONTEMI"<<endl;
                    if(i==2)
                        cout<<"EN HIZLI ARAMA YAPAN YONTEM AYRIK BOLEN KALAN YONTEMI"<<endl;
                    if(i==3)
                        cout<<"EN HIZLI ARAMA YAPAN YONTEM KATLAMA YONTEMI"<<endl;
                    if(i==4)
                        cout<<"EN HIZLI ARAMA YAPAN YONTEM AYRIK KATLAMA YONTEMI"<<endl;
                    if(i==5)
                        cout<<"EN HIZLI ARAMA YAPAN YONTEM KARE ORTASI YONTEMI"<<endl;
                    if(i==6)
                        cout<<"EN HIZLI ARAMA YAPAN YONTEM AYRIK KARE ORTASI YONTEMI"<<endl;
                }
            }
            break;
        }
    default:
        {
            cout<<"YANLIS SECIM YAPTINIZ!!"<<endl;
            break;
        }
    }
    }
    else if(sec==0)
        break;
     else
    {
        cout<<"YANLIS GIRIS"<<endl;
        continue;
    }
    if(secim!=0 || secim!=1)
        continue;

    }


    return 0;
}
