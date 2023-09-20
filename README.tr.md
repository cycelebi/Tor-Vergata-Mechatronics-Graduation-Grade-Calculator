[![en](https://img.shields.io/badge/lang-english-yellow.svg)](https://github.com/cycelebi/Tor-Vergata-Mechatronics-Graduation-Grade-Calculator/blob/main/README.md)
[![it](https://img.shields.io/badge/lang-italiano-green.svg)](https://github.com/cycelebi/Tor-Vergata-Mechatronics-Graduation-Grade-Calculator/blob/main/README.it.md)
[![tr](https://img.shields.io/badge/lang-türkçe-white.svg)](https://github.com/cycelebi/Tor-Vergata-Mechatronics-Graduation-Grade-Calculator/blob/main/README.tr.md)
[![ru](https://img.shields.io/badge/lang-русский-blue.svg)](https://github.com/cycelebi/Tor-Vergata-Mechatronics-Graduation-Grade-Calculator/blob/main/README.ru.md)


# Roma Üniversitesi Tor Vergata Mechatronik Yüksek Lisans Bölümü Mezuniyet Notu Hesaplama Aracı

## Giriş

Bu C programlama projesi, Mehmet Celebi tarafından Roma "Tor Vergata" Üniversitesi'ndeki VLSI Devre Sistemleri Tasarımı dersi için geliştirilmiştir. Proje, kullanıcıların derslerinin notlarını ve kredilerini girmelerine, ayrıca mezuniyet durumlarını belirlemelerine olanak tanıyan bir program oluşturma üzerine odaklanmaktadır.

## Program Yapısı

Program şu şekilde yapılandırılmıştır:

- Program, standart giriş ve çıkış için gerekli olan `stdio.h` kütüphanesini dahil ederek başlar.
- Program, dersin adı, kredi saati (AKTS), not ve lode durumu gibi özniteliklere sahip olan `Course` adlı bir yapı tanımlar.
- Ana işlev değişkenleri ve ders bilgilerini depolamak için bir yapı dizisi olan bir dizi tanımlar.
- Program, her dersle ilgili bilgileri kullanıcıdan toplamak için bir while döngüsüne girer. Döngü, kullanıcının ihtiyaç duyduğu kadar ders eklemesine veya silmesine izin verir.
- Döngü içinde, program kullanıcıya ders adını, AKTS'yi, notu ve lode durumunu girmesi için bir giriş sağlar. Girişleri doğrular ve ilgili yapıya depolar.
- Tüm ders bilgilerini topladıktan sonra, program toplam ağırlıklı notu, toplam AKTS'yi ve toplam lode bonuslarını hesaplar.
- Program daha sonra ders ayrıntılarını, ders adını, AKTS'yi, notu ve lode durumunu çıktılar.
- Son olarak, program ağırlıklı ortalama notu hesaplar, ek bonusları kontrol eder ve mezuniyet durumunu belirler.

## Hesaplamalar ve Formüller

Program aşağıdaki hesaplamaları gerçekleştirir:

- Ağırlıklı Not: Program, her ders için notu AKTS ile çarparak ve sonuçları toplayarak her dersin ağırlıklı notunu hesaplar. Toplam ağırlıklı not, toplam AKTS'ye bölünerek genel ağırlıklı not elde edilir.
    
    Formül: `ağırlıklıNot = toplamNot / toplamAKTS`
    
- Lode Bonusları: Program, 9 veya 12 AKTS ve lode durumu 1 (lode ile) olan dersleri kontrol eder. Bu kriterleri karşılayan derslerin sayısını sayar ve buna göre bir lode bonusu verir.
- Mezuniyet Puanı: Program, ağırlıklı ortalama notu 110/30 dönüşüm faktörüyle çarparak, lode bonuslarını, zamanında mezuniyet durumunu ve tez puanını (uygunsa) ekleyerek mezuniyet puanını hesaplar.
    
    Formül: `mezuniyetPuanı = (ağırlıklıNot * 110/30) + toplamLode + intime + tez`
    
- Formül [University of Rome Tor Vergata Websitesi'nden](http://mechatronics.uniroma2.it/wp-content/uploads/2021/02/Calculation-marks-for-the-Master.pdf) alınmıştır. Zamanla değişiklikler yapılabilir.

## Mezuniyet Durumu

Program, mezuniyet puanına dayanarak mezuniyet durumunu belirler:

- Cum Laude: Mezuniyet puanı 110 veya daha yüksekse, program öğrencinin Cum Laude ile mezun olabileceğini belirtir.
- Karar Kurulu Kararıyla Cum Laude: Mezuniyet puanı 104 ile 109 arasında ise, program öğrencinin Karar Kurulu kararıyla Cum Laude ile mezun olabileceğini belirtir.
- Mezun Olabilecek Durumda: Mezuniyet puanı 66 veya daha yüksekse, program öğrenciyi mezun olabilecek durumda olarak ilan eder.
- Mezun Olamaz Durumda: Mezuniyet puanı 66'dan düşükse, program öğrenciyi mezun olamaz durumda olarak ilan eder.

## Sonuç

Bu C programlama projesi, kullanıcıların derslerinin notlarını ve kredilerini girmelerine, ayrıca mezuniyet durumlarını belirlemelerine olanak tanır. Akademik performansı yönetmek ve değerlendirmek için kapsamlı ve verimli bir yol sunar.
