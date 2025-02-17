Bu proje, Linux işletim sisteminde sistem günlüklerini (syslog) işlemek için bir bağlı liste veri yapısının nasıl kullanılacağını gösteren bir uygulamadır. 
Syslog kayıtları, zaman damgası, log seviyesi ve mesaj içeriği gibi bilgileri içerir. 
Uygulama, syslog verilerini bir çift yönlü bağlı listeyle yönetmektedir.


Proje Açıklaması:
Bu yazılım, syslog verilerini depolamak ve yönetmek için çift yönlü bağlı liste kullanmaktadır. 
Uygulama aşağıdaki işlevleri gerçekleştirir:
* Syslog kaydı eklemek
* Syslog kayıtlarını listelemek
* Belirli bir syslog kaydını silmek
* Syslog kayıtlarını ters sırayla yazdırmak
* Bellek temizliği sağlamak


Proje İçeriği:
Bu proje aşağıdaki temel özelliklere sahiptir:
1. Syslog Kaydı Ekleme: Kullanıcı, belirli bir zaman damgası, log seviyesi ve mesaj içeriği girerek syslog kaydını sisteme ekleyebilir.
2. Syslog Kayıtlarını Yazdırma: Eklemiş olduğunuz syslog kayıtlarını sırasıyla görüntüleme imkanı sunar.
3. Syslog Kaydı Silme: Kullanıcı, belirli bir timestamp (zaman damgası) ile eşleşen kaydı silebilir.
4. Syslog Kayıtlarını Tersine Yazdırma: Kayıtları tersten sıralayarak yazdırma fonksiyonu eklenmiştir.
5. Bellek Temizliği: Dinamik bellek kullanımı ile ilgili bellek sızıntılarını engellemek için bellek temizliği sağlanmıştır.


Kullanılan Teknolojiler:
C Programlama Dili: Kodun yazılmasında C dili kullanılmıştır.
Bağlı Liste Veri Yapısı: Syslog verilerini yönetmek için çift yönlü bağlı liste kullanılmıştır.


Gereksinimler:
C derleyicisi (GCC önerilir)
Git (proje kodlarını GitHub'dan almak için)
Linux işletim sistemi (syslog üzerinde çalışma yapılması için)


Kullanım:
Program çalıştırıldığında syslog kayıtları eklenir, eklenen kayıtlar yazdırılır, bir kayıt silinir ve sonuçlar ters sırayla yazdırılır. 
Örnek kullanım:

Kayıt Ekleme: "2025-02-17 10:30:00", "INFO", "System started successfully."
Kayıt Silme: "2025-02-17 10:35:00"
Listeyi Tersine Çevirelim: Kayıtları ters sırayla görüntüler.


Kod Yapısı:
* syslog.c: Projenin ana kodunun bulunduğu dosyadır. Syslog kayıtlarının eklenmesi, silinmesi ve yazdırılması işlemleri burada yapılır.

* README.md: Projeyi anlatan dökümantasyondur.

* Makefile (isteğe bağlı): Derleme için bir Makefile dosyası ekleyebilirsiniz


Örnek Çıktı Ekranı
Program çalıştırıldığında şu şekilde bir çıktı alabilirsiniz:

Syslog Records:
Timestamp: 2025-02-17 10:40:00
Level: WARN
Message: High CPU usage detected.
----------------------------
Timestamp: 2025-02-17 10:35:00
Level: ERROR
Message: Disk space is running low.
----------------------------
Timestamp: 2025-02-17 10:30:00
Level: INFO
Message: System started successfully.
----------------------------

Silme işlemi:
Timestamp: 2025-02-17 10:40:00
Level: WARN
Message: High CPU usage detected.
----------------------------
Timestamp: 2025-02-17 10:30:00
Level: INFO
Message: System started successfully.
----------------------------

Listeyi Tersine Çevirelim:
Timestamp: 2025-02-17 10:30:00
Level: INFO
Message: System started successfully.
----------------------------
Timestamp: 2025-02-17 10:40:00
Level: WARN
Message: High CPU usage detected.
----------------------------
Program ended with exit code: 0

Bu çıktı örneği, programın nasıl çalıştığını ve kullanıcıya hangi bilgilerin sunulduğunu gösterir. 
Her aşamada syslog kayıtlarının nasıl eklendiğini, silindiğini ve ters sırayla görüntülendiğini anlatan adımlar yer alır.


Katkı Sağlama
Eğer bu projeye katkıda bulunmak isterseniz, lütfen öncelikle bir pull request gönderin. Katkılarınız için teşekkür ederiz!


Lisans
Bu proje MIT Lisansı ile lisanslanmıştır.
