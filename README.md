# get_next_line

42 okulunun dosyadan satır okuma projesi - Her çağrıda bir satır döndüren fonksiyon implementasyonu.

## 📋 Proje Hakkında

get_next_line, bir dosya tanımlayıcısından (file descriptor) her çağrıldığında bir satır okuyan fonksiyondur. Static değişkenler kullanarak önceki okuma durumunu saklayan ve buffer yönetimi yapan önemli bir C projesidir.

## 🎯 Özellikler

- **Satır Satır Okuma**: Her çağrıda bir satır döndürür
- **Çoklu Dosya Desteği**: Birden fazla file descriptor'ı aynı anda okuyabilir (bonus)
- **Buffer Yönetimi**: BUFFER_SIZE ile ayarlanabilir buffer boyutu
- **Static Değişkenler**: Okuma durumunu kaydeder
- **Memory Yönetimi**: Dinamik bellek tahsisi ve serbest bırakma

## 🛠️ Teknolojiler

- **C Dili** (100%)
- **Static Variables**: Durum saklama
- **Dynamic Memory**: malloc/free kullanımı
- **File I/O**: read() sistem çağrısı
- **Buffer Management**: Efficient data handling

## 📦 Kurulum

### Derleme

```bash
# Temel versiyon
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

# Bonus (çoklu fd)
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

## 💻 Kullanım

### Temel Kullanım

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Bonus - Çoklu File Descriptor

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

char *line1 = get_next_line(fd1);
char *line2 = get_next_line(fd2);
char *line3 = get_next_line(fd1);  // Her fd kendi durumunu tutar

free(line1);
free(line2);
free(line3);
```

## 📚 Fonksiyon Prototipi

```c
char *get_next_line(int fd);
```

**Parametreler:**
- `fd`: Okunacak dosya tanımlayıcısı

**Dönüş Değeri:**
- Okunan satır (newline dahil)
- `NULL`: Dosya sonu veya hata

## 🔧 Buffer Size

BUFFER_SIZE derleme zamanında tanımlanır:

```bash
# Küçük buffer
gcc -D BUFFER_SIZE=1 ...

# Büyük buffer
gcc -D BUFFER_SIZE=1024 ...

# Optimal buffer
gcc -D BUFFER_SIZE=42 ...
```

## 🧪 Test Senaryoları

```c
// Test 1: Normal dosya okuma
fd = open("test.txt", O_RDONLY);
while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}

// Test 2: Boş dosya
fd = open("empty.txt", O_RDONLY);
line = get_next_line(fd);  // NULL dönmeli

// Test 3: Stdin okuma
line = get_next_line(0);  // Klavyeden okur

// Test 4: Çok uzun satırlar
// BUFFER_SIZE'dan büyük satırları test et
```

## 🎓 Öğrenilen Kavramlar

- **Static Variables**: Program boyunca veri saklama
- **Buffer Management**: Verimli bellek kullanımı
- **File I/O**: read() sistem çağrısı kullanımı
- **String Manipulation**: Dinamik string işlemleri
- **Memory Leaks**: Bellek sızıntısı önleme
- **Edge Cases**: Özel durumları yönetme

## ⚠️ Dikkat Edilmesi Gerekenler

- ✅ Her satır `\n` ile bitmelidir (varsa)
- ✅ Dosya sonunda newline yoksa düzgün handle edilmeli
- ✅ Memory leak olmamalı
- ✅ Bonus'ta her fd ayrı static değişken kullanmalı
- ✅ Negatif fd, kapalı fd gibi hata durumları kontrol edilmeli

## 📝 42 Norm Uyumluluğu

Bu proje 42 okul kodlama standartlarına uygundur:
- Fonksiyon başına maksimum 25 satır
- Satır başına maksimum 80 karakter
- Maksimum 5 fonksiyon per dosya

## 📧 İletişim

Proje Sahibi: TroubledKezoo1

Proje Linki: [https://github.com/TroubledKezoo1/get_next_line](https://github.com/TroubledKezoo1/get_next_line)