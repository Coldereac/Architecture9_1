
#include <iostream>
#include <cstdint>

int main() {
    const int N = 51; //(довжина 50 символів, кожен символ - 2 байти)
    
    char16_t str[N] = u"NOOOOOOoo, OOOooo."; //вхідний рядок
    char16_t str2[N] = u""; // Вихідний рядок 



    __asm {
        // Ініціалізація регістрів
        lea esi, str        // Завантажити адресу рядка в esi
        lea edi, str2       // 
        mov ecx, 50         // Розмір рядка (50 символів)

        replace_loop:
            mov ax, [esi]       // Завантажити поточний символ (2 байти) в ax
            cmp ax, 'O'         // Порівняти символ з 'O'
            jne not_O           // Якщо символ не 'O', перейти до not_O
            mov ax, '0'         // Замінити 'O' на '0'
            mov[edi], ax       // Зберегти замінений символ назад у рядок
        not_O:  
            mov [edi], ax       //якщо символ не 'O' то просто переносимо його у вихідний рядок
            add edi, 2          // Перейти до наступного символу (2 байти)
            add esi, 2     
            loop replace_loop   // Повторити цикл до завершення обробки рядка
    }
    // Виведення оригінального рядка
    std::wcout << (wchar_t*)str << std::endl;

    // Виведення зміненого рядка
    std::wcout << (wchar_t*)str2 << std::endl;

    return 0;
}