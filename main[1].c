#include <stdio.h>
#include <stdlib.h>
#include <math.h>//sqrt fonksiyonunu kullanabilmek icin eklenir.
#include <time.h> //time() fonksiyonunu kullanabilmek icin eklenir.

void cevap_anahtari_uret(char cevap_anahtari[], int s){

    srand(time(NULL));//her ögrenci için rastgele cevap anahtarý olusturur

    int sayi;
    for(int i=0;i<s;i++){

        sayi =(int)rand()%5;
        if (sayi==0)
            cevap_anahtari[i]='A';
        else if (sayi==1)
            cevap_anahtari[i]='B';
        else if (sayi==2)
            cevap_anahtari[i]='C';
        else if (sayi==3)
            cevap_anahtari[i]='D';
        else
            cevap_anahtari[i]='E';
    }
}

void cevap_anahtari_yazdir(char cevap_anahtari[], int s){
    printf("\nCEVAP ANAHTARI\n");
    for (int i=0;i<s;i++)
        printf("%.3d:%c | ",(i+1),cevap_anahtari[i]);
}

void sinavi_uygula(char ogrenci_cevaplari[][100], char cevap_anahtari[], int n, int s, double b, double d){

    srand(time(NULL));

    int ihtimal;
    for (int i=0;i<n;i++){ //ogrenci indisini tutar
        for(int j=0;j<s;j++){ //soru indisini tutar
            ihtimal=(int)(rand()%100);

            if(ihtimal<(int)(d*100))
                ogrenci_cevaplari[j][i]=cevap_anahtari[j];

            else if(((int)(d*100))<=ihtimal<((int)(d*100)+(int)(b*100)))
                ogrenci_cevaplari[j][i]='X';

            else{
                ihtimal=ihtimal%5;
                while(1){
                    if(ihtimal==0)
                        ogrenci_cevaplari[j][i]='A';
                    else if(ihtimal==1)
                        ogrenci_cevaplari[j][i]='B';
                    else if(ihtimal==2)
                        ogrenci_cevaplari[j][i]='C';
                    else if(ihtimal==3)
                        ogrenci_cevaplari[j][i]='D';
                    else
                        ogrenci_cevaplari[j][i]='E';

                    if(ogrenci_cevaplari[j][i]!=cevap_anahtari[j])
                        break;
                    else
                        ihtimal++;
                }
            }
        }
    }
}

void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[][100], int ogrenci_ID, int s){
    printf("\nOGRENCININ CEVAPLARI\n");
    for(int i=0;i<s;i++)
        printf("%c\t",ogrenci_cevaplari[i][ogrenci_ID]);
}

void ogrencilerin_cevabini_yazdir(char ogrenci_cevaplari[][100], int n, int s){
    for(int i=0;i<n;i++){
            printf("\n%.3d. ogrencinin cevaplari:\n",(i+1));
        for(int j=0;j<s;j++){
            printf("%.3d:%c | ",(i+1),ogrenci_cevaplari[j][i]);
        }
    }
}

void ogrencileri_puanla(char ogrenci_cevaplari[][100], char cevap_anahtari[], double HBN[], int n, int s){
    int dogru_cevaplar;
    int net;
    double soru_puani = 100/s;
    for (int i=0;i<n;i++){ //ogrenci indisi
        dogru_cevaplar=0;
        net=0;
        for(int j=0;j<s;j++){ // soru indisi
            if(ogrenci_cevaplari[j][i]==cevap_anahtari[j])
                dogru_cevaplar++;
        }
    net=dogru_cevaplar-((int)((s-dogru_cevaplar)/4));

    if ((net*soru_puani)<=0)
        HBN[i]=0.0;

    else
        HBN[i]=net*soru_puani;
    }
}

double sinif_ortalamasi_hesapla(double HBN[], int n){
    double toplam=0.0;
    for (int i=0;i<n;i++)
        toplam+=HBN[i];

    return (toplam/n);
}

double standart_sapma_hesapla(double ortalama, double HBN[], int n){
    double toplam=0;
    for(int i=0;i<n;i++)
        toplam+=pow((HBN[i]-ortalama),2);

    return (sqrt(toplam/n));//sqrt fonksiyonu,kendisine geçirilen arg parametre deðerinin karekökünü hesaplar.
}

void T_skoru_hesapla(double ortalama, double HBN[], int n, double std, double T_skoru[]){
    for(int i=0;i<n;i++)
        T_skoru[i]= (((HBN[i]-ortalama)/std)*10)+60;
}

void sinif_basari_duzeyi_harf_notu(double ortalama, char harf_notu[2][100], int n, double T_skoru[]){
    if(80.0<ortalama<=100.0){
        printf("\nSinif Duzeyi = Ustun Basari\n");
        for(int i=0;i<n;i++){
            if(T_skoru[i]>=67.0){
                harf_notu[0][i]='A';
                harf_notu[1][i]='A';
            }
            else if(62.0<=T_skoru[i]<67.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='A';
            }
            else if(57.0<=T_skoru[i]<62.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='B';
            }
            else if(52.0<=T_skoru[i]<57.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='B';
            }
            else if(47.0<=T_skoru[i]<52.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='C';
            }
            else if(42.0<=T_skoru[i]<47.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='C';
            }
            else if(37.0<=T_skoru[i]<42.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='D';
            }
            else if(32.0<=T_skoru[i]<37.0){
                harf_notu[0][i]='F';
                harf_notu[1][i]='D';
            }
            else{
                harf_notu[0][i]='F';
                harf_notu[1][i]='F';
            }
        }
    }
    else if(70.0<ortalama<=80.0){
        printf("\nSinif Duzeyi = Mukemmel\n");
        for(int i=0;i<n;i++){
            if(T_skoru[i]>=69.0){
                harf_notu[0][i]='A';
                harf_notu[1][i]='A';
            }
            else if(64.0<=T_skoru[i]<69.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='A';
            }
            else if(59.0<=T_skoru[i]<64.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='B';
            }
            else if(54.0<=T_skoru[i]<59.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='B';
            }
            else if(49.0<=T_skoru[i]<54.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='C';
            }
            else if(44.0<=T_skoru[i]<49.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='C';
            }
            else if(39.0<=T_skoru[i]<44.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='D';
            }
            else if(34.0<=T_skoru[i]<39.0){
                harf_notu[0][i]='F';
                harf_notu[1][i]='D';
            }
            else{
                harf_notu[0][i]='F';
                harf_notu[1][i]='F';
            }
        }
    }
    else if(62.5<ortalama<=70.0){
        printf("\nSinif Duzeyi = Cok Iyi\n");
        for(int i=0;i<n;i++){
            if(T_skoru[i]>=71.0){
                harf_notu[0][i]='A';
                harf_notu[1][i]='A';
            }
            else if(66.0<=T_skoru[i]<71.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='A';
            }
            else if(61.0<=T_skoru[i]<66.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='B';
            }
            else if(56.0<=T_skoru[i]<61.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='B';
            }
            else if(51.0<=T_skoru[i]<56.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='C';
            }
            else if(46.0<=T_skoru[i]<51.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='C';
            }
            else if(41.0<=T_skoru[i]<46.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='D';
            }
            else if(36.0<=T_skoru[i]<41.0){
                harf_notu[0][i]='F';
                harf_notu[1][i]='D';
            }
            else{
                harf_notu[0][i]='F';
                harf_notu[1][i]='F';
            }
        }
    }
    else if(57.5<ortalama<=62.5){
        printf("\nSinif Duzeyi = Iyi\n");
        for(int i=0;i<n;i++){
            if(T_skoru[i]>=73.0){
                harf_notu[0][i]='A';
                harf_notu[1][i]='A';
            }
            else if(68.0<=T_skoru[i]<73.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='A';
            }
            else if(63.0<=T_skoru[i]<68.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='B';
            }
            else if(58.0<=T_skoru[i]<63.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='B';
            }
            else if(53.0<=T_skoru[i]<58.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='C';
            }
            else if(48.0<=T_skoru[i]<53.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='C';
            }
            else if(43.0<=T_skoru[i]<48.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='D';
            }
            else if(38.0<=T_skoru[i]<43.0){
                harf_notu[0][i]='F';
                harf_notu[1][i]='D';
            }
            else{
                harf_notu[0][i]='F';
                harf_notu[1][i]='F';
            }
        }
    }
    else if(52.5<ortalama<=57.5){
        printf("\nSinif Duzeyi = Ortanin Ustu\n");
        for(int i=0;i<n;i++){
            if(T_skoru[i]>=75.0){
                harf_notu[0][i]='A';
                harf_notu[1][i]='A';
            }
            else if(70.0<=T_skoru[i]<75.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='A';
            }
            else if(65.0<=T_skoru[i]<70.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='B';
            }
            else if(60.0<=T_skoru[i]<65.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='B';
            }
            else if(55.0<=T_skoru[i]<60.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='C';
            }
            else if(50.0<=T_skoru[i]<55.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='C';
            }
            else if(45.0<=T_skoru[i]<50.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='D';
            }
            else if(40.0<=T_skoru[i]<45.0){
                harf_notu[0][i]='F';
                harf_notu[1][i]='D';
            }
            else{
                harf_notu[0][i]='F';
                harf_notu[1][i]='F';
            }
        }
    }
    else if(47.5<ortalama<=52.5){
        printf("\nSinif Duzeyi = Orta\n");
        for(int i=0;i<n;i++){
            if(T_skoru[i]>=77.0){
                harf_notu[0][i]='A';
                harf_notu[1][i]='A';
            }
            else if(72.0<=T_skoru[i]<77.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='A';
            }
            else if(67.0<=T_skoru[i]<72.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='B';
            }
            else if(62.0<=T_skoru[i]<67.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='B';
            }
            else if(57.0<=T_skoru[i]<62.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='C';
            }
            else if(52.0<=T_skoru[i]<57.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='C';
            }
            else if(47.0<=T_skoru[i]<52.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='D';
            }
            else if(42.0<=T_skoru[i]<47.0){
                harf_notu[0][i]='F';
                harf_notu[1][i]='D';
            }
            else{
                harf_notu[0][i]='F';
                harf_notu[1][i]='F';
            }
        }
    }
    else if(42.5<ortalama<=47.5){
        printf("\nSinif Duzeyi = Zayif\n");
        for(int i=0;i<n;i++){
            if(T_skoru[i]>=79.0){
                harf_notu[0][i]='A';
                harf_notu[1][i]='A';
            }
            else if(74.0<=T_skoru[i]<81.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='A';
            }
            else if(69.0<=T_skoru[i]<74.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='B';
            }
            else if(64.0<=T_skoru[i]<69.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='B';
            }
            else if(59.0<=T_skoru[i]<64.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='C';
            }
            else if(54.0<=T_skoru[i]<59.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='C';
            }
            else if(49.0<=T_skoru[i]<54.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='D';
            }
            else if(44.0<=T_skoru[i]<49.0){
                harf_notu[0][i]='F';
                harf_notu[1][i]='D';
            }
            else{
                harf_notu[0][i]='F';
                harf_notu[1][i]='F';
            }
        }
    }
    else{
        printf("\nSinif Duzeyi = Kotu\n");
        for(int i=0;i<n;i++){
            if(T_skoru[i]>=81.0){
                harf_notu[0][i]='A';
                harf_notu[1][i]='A';
            }
            else if(76.0<=T_skoru[i]<81.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='A';
            }
            else if(71.0<=T_skoru[i]<76.0){
                harf_notu[0][i]='B';
                harf_notu[1][i]='B';
            }
            else if(66.0<=T_skoru[i]<71.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='B';
            }
            else if(61.0<=T_skoru[i]<66.0){
                harf_notu[0][i]='C';
                harf_notu[1][i]='C';
            }
            else if(56.0<=T_skoru[i]<61.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='C';
            }
            else if(51.0<=T_skoru[i]<56.0){
                harf_notu[0][i]='D';
                harf_notu[1][i]='D';
            }
            else if(46.0<=T_skoru[i]<51.0){
                harf_notu[0][i]='F';
                harf_notu[1][i]='D';
            }
            else{
                harf_notu[0][i]='F';
                harf_notu[1][i]='F';
            }
        }
    }
}

void ogrenci_notlari_yazdir(double HBN[], double T_skoru[], char harf_notu[2][100],int n){
    printf("\nOgrenci notlari:\n");
    for(int i=0;i<n;i++)
        printf("%.3d. ogrencinin HBN: %lf, T-skoru: %lf, harf notu: %c%c \n",(i+1),HBN[i],T_skoru[i],harf_notu[0][i],harf_notu[1][i]);
}

int main()
{
    int n,s;
    double b,d;
    printf("Ogrenci sayisini giriniz (Max 100)= ");
    scanf("%d",&n);
    printf("\nSoru sayisini giriniz (Max 100)= ");
    scanf("%d",&s);
    printf("\nSorunun bos birakilma ihtimalini giriniz (0.0-1.0) = ");
    scanf("%lf",&b);
    printf("Sorunun dogru cevaplanma ihtimalini giriniz (0.0-1.0) = ");
    scanf("%lf",&d);

    char cevap_anahtari [s];
    char ogrenci_cevaplari[s][100];
    char harf_notu[2][100];
    double HBN[n];
    double T_skoru[n];

    cevap_anahtari_uret(cevap_anahtari,s);
    sinavi_uygula(ogrenci_cevaplari, cevap_anahtari,n,s,b,d);
    cevap_anahtari_yazdir(cevap_anahtari,s);
    ogrencilerin_cevabini_yazdir(ogrenci_cevaplari,n,s);

    ogrencileri_puanla(ogrenci_cevaplari,cevap_anahtari,HBN,n,s);
    double ort=sinif_ortalamasi_hesapla(HBN,n);
    double sts=standart_sapma_hesapla(ort,HBN,n);
    T_skoru_hesapla(ort,HBN,n,sts,T_skoru);
    sinif_basari_duzeyi_harf_notu(ort,harf_notu,n,T_skoru);
    printf("Sinif Ortalamasi= %lf\n",ort);
    printf("Standart Sapma= %lf\n",sts);
    ogrenci_notlari_yazdir(HBN,T_skoru,harf_notu,n);

    return 0;
}
