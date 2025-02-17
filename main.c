//
//  main.c
//  Linux Syslog Bilgilerinin Bağlı Liste İle Gösterilmesi
//
//  Created by Selin Avcı on 17.02.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Syslog kaydını tutacak yapı
typedef struct SyslogRecord {
    char timestamp[20];   // Zaman damgası (örneğin: 2025-02-17 10:30:00)
    char level[10];       // Log seviyesi (INFO, WARN, ERROR)
    char message[256];    // Log mesajı
    struct SyslogRecord* prev;  // Önceki kayıt (bağlı liste için)
    struct SyslogRecord* next;  // Sonraki kayıt (bağlı liste için)
} SyslogRecord;

// Başlangıçta boş olan listeyi temsil eden işaretçi
SyslogRecord* head = NULL;

// Yeni bir syslog kaydı eklemek için fonksiyon
void addSyslogRecord(const char* timestamp, const char* level, const char* message) {
    SyslogRecord* newRecord = (SyslogRecord*)malloc(sizeof(SyslogRecord));
    
    // Verileri yeni kayda kopyala
    strcpy(newRecord->timestamp, timestamp);
    strcpy(newRecord->level, level);
    strcpy(newRecord->message, message);
    
    // Yeni kaydın işaretçilerini ayarla
    newRecord->prev = NULL;
    newRecord->next = head;
    
    // Eğer liste boşsa, head'i yeni kayda işaret et
    if (head != NULL) {
        head->prev = newRecord;
    }
    
    // Yeni kaydı başa ekle
    head = newRecord;
}

// Syslog kayıtlarını yazdıran fonksiyon
void printSyslogRecords() {
    SyslogRecord* current = head;
    while (current != NULL) {
        printf("Timestamp: %s\n", current->timestamp);
        printf("Level: %s\n", current->level);
        printf("Message: %s\n", current->message);
        printf("----------------------------\n");
        current = current->next;
    }
}

// Kayıt silme fonksiyonu
void deleteSyslogRecord(const char* timestamp) {
    SyslogRecord* current = head;
    while (current != NULL) {
        if (strcmp(current->timestamp, timestamp) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;  // Silinen ilk eleman ise, head'i güncelle
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

// Listeyi ters yazdırma fonksiyonu
void printSyslogInReverseOrder() {
    SyslogRecord* current = head;
    
    // Listeyi sonuna kadar git
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    
    // Listeyi ters sırayla yazdır
    while (current != NULL) {
        printf("Timestamp: %s\n", current->timestamp);
        printf("Level: %s\n", current->level);
        printf("Message: %s\n", current->message);
        printf("----------------------------\n");
        current = current->prev;
    }
}

// Belleği temizlemek için fonksiyon
void freeMemory() {
    SyslogRecord* current = head;
    while (current != NULL) {
        SyslogRecord* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Kayıtları ekleyelim
    addSyslogRecord("2025-02-17 10:30:00", "INFO", "System started successfully.");
    addSyslogRecord("2025-02-17 10:35:00", "ERROR", "Disk space is running low.");
    addSyslogRecord("2025-02-17 10:40:00", "WARN", "High CPU usage detected.");
    
    // Kayıtları yazdıralım
    printf("Syslog Records:\n");
    printSyslogRecords();
    
    // Kayıt silme işlemi
    printf("\nSilme işlemi:\n");
    deleteSyslogRecord("2025-02-17 10:35:00");
    printSyslogRecords();
    
    // Listeyi ters yazdıralım
    printf("\nListeyi Tersine Çevirelim:\n");
    printSyslogInReverseOrder();
    
    // Belleği temizle
    freeMemory();
    
    return 0;
}
