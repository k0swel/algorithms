
#include <iostream>
#include <windows.h>
#include <winreg.h>
#include <string>

int write_program_to_regedit(const wchar_t* name, const wchar_t* path) {
    // name = имя записи из ключа реестра.
    // path = путь к программе, которую нужно добавить в автозапуск.
    name[]
    HKEY autoup_regedit_key;
    LSTATUS status = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &autoup_regedit_key);
    if (status != ERROR_SUCCESS) { // открываем ключ реестра
        std::wcerr << "Ошибки при открытии ключа реестра. Возможно указан некорректный path в реестре!" << std::endl;
        std::wcerr << "Ошибка = " << status << std::endl;
        return status;
    }
    status = RegSetValueExW(autoup_regedit_key, name, 0, REG_SZ, (const BYTE*)path, (wcslen(path) + 1) * sizeof(wchar_t));
    if (status != ERROR_SUCCESS) { // устанавливаем значение ключу реестра
        std::wcerr << "Запись в реестр не удалась. Ошибка: " << status << std::endl;
        return status;
    }
    RegCloseKey(autoup_regedit_key); // закрываем ключ реестра
    std::wcout << "Программа успешно добавлена в автозапуск!" << std::endl;
}

void del_program_from_startup(const wchar_t* name) {
    // name - значение записи из ключа реестра, которое нужно удалить
    HKEY autoup_regedit_value_delete;
    LSTATUS status = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &autoup_regedit_value_delete);
    if (status != ERROR_SUCCESS) {
        std::wcerr << "Ошибка при открытии ключа реестра (ВОЗМОЖНО программа запущена не от имени администратора)! " << std::endl;
        std::wcerr << "Ошибка = " << status << std::endl;
        return;
    }
    status = RegDeleteValueW(autoup_regedit_value_delete, name);
    if (status != ERROR_SUCCESS) {
        std::wcerr << "Ошибка при удалении значения из ключа реестра!." << std::endl;
        std::wcerr << "Ошибка = " << status << std::endl;
        RegCloseKey(autoup_regedit_value_delete);
        return;
    }
    RegCloseKey(autoup_regedit_value_delete);
    std::wcout << "Запись из реестра ( " << name << " ) успешно удалена." << std::endl;
    
}


int main()
{
    std::wstring buffer;
    std::cout << "Выберите опцию: " << std::endl;
    std::cout << "1. Добавить значение в автозагрузку." << std::endl;
    std::cout << "2. Удалить значение из автозагрузки." << std::endl;
    std::getline(std::wcin, buffer);
    if (buffer.find(L"1") != std::wstring::npos) {
        std::cout << "Введите название записи в реестре: ";
        std::wstring name_regedit_item;
        std::getline(std::wcin, name_regedit_item);
        std::cout << "Введите значение для записи: ";
        std::wstring value_regedit_item;
        std::getline(std::wcin, value_regedit_item);
        write_program_to_regedit(name_regedit_item.c_str(), value_regedit_item.c_str());
    }
    else if (buffer.find(L"2") != std::wstring::npos) {
        std::cout << "Введите название записи в реестре: ";
        std::wstring name_regedit_item;
        std::getline(std::wcin, name_regedit_item);
        del_program_from_startup(name_regedit_item.c_str());
    }
    system("pause");
}


