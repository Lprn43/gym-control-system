#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef enum{
    STANDART,
    VIP,
    ELITE
}UyelikTipi;
typedef struct{
    char isim[30];
    float boy;
    float kilo;
    UyelikTipi tip;
}Uye;
void bilgileriYazdir(Uye*liste,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%f %f -> ",liste[i].boy,liste[i].kilo);
        float a = (liste[i].boy*liste[i].boy) / 10000.0;
        float bki = (liste[i].kilo) / a;
        if (liste[i].tip == ELITE)
        {
            printf("%d. %s -> Ozel Hoca Atandi\n",i+1,liste[i].isim);
        }
        else{
            printf("%d. %s -> BKI = %.2f , Kilo = %.2f",i+1,liste[i].isim,bki,liste[i].kilo);
        }
    }
       
}
void dosyayaKaydet(Uye *liste, int n) {
    // 1. Dosyayı yazma modunda aç
    FILE *fptr = fopen("uyeler.txt", "w");

    // Dosya açıldı mı kontrolü (Hoca buradan puan verir!)
    if (fptr == NULL) {
        printf("Dosya acilamadi!");
        return;
    }

    // 2. Döngü ile her üyeyi dosyaya yaz
    for (int i = 0; i < n; i++) {
        fprintf(fptr, "Isim: %s | Boy: %.2f | Kilo: %.2f\n", 
                liste[i].isim, liste[i].boy, liste[i].kilo);
    }

    // 3. Dosyayı kapat (Çok önemli!)
    fclose(fptr);
    printf("\nVeriler uyeler.txt dosyasina kaydedildi.\n");
}
int main()
{
    int n,i;
    printf("Kac uye var:");
    scanf("%d",&n);
    Uye* uye = malloc(n * sizeof(Uye));
    if (uye == NULL)
    {
        return 1;
    }
    
    for (i = 0; i < n; i++)
    {
        printf("Isim:");
        scanf("%s",uye[i].isim);
        printf("Boy(cm):");
        scanf("%f",&uye[i].boy);
        printf("Kilo:");
        scanf("%f",&uye[i].kilo);
        printf("Uyelik (0:Standart 1:VIP 2:Elite)");
        scanf("%u",&uye[i].tip);
    }
    printf("--- Uye Listesi ---\n");
    bilgileriYazdir(uye,n);
    dosyayaKaydet(uye,n);
    free(uye);
    return 0;
}