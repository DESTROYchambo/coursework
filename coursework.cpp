#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>
#include <vector>


using namespace std;
const string path = "products.txt"; //назва файлу


//структура товару
struct item
{
    string name;
    float price;
    int amount;
};

//функція додавання товару
void addProduct() {
    
    setlocale(LC_ALL, "rus");
    ofstream fout;  
    fout.open(path, ofstream::app); //відкриття файлу з додаванням інформації

    if (!fout.is_open()) //перевірка відкриття файлу
    {
        cout << "err" << endl;
        return;
    }

    item items{};
    cout << "\n";
    cout << "Введiть назву товару: ";
    cin >> items.name;
    cout << "Введiть цiну товару: ";
    cin >> items.price;
    cout << "Введiть кiлькiсть товару: ";
    cin >> items.amount;

    fout << items.name;
    fout << " ";
    fout << items.price;
    fout << " ";
    fout << items.amount;
    fout << "\n";
    
    
        
    

    fout.close();

}


void viewProduct() {
    setlocale(LC_ALL, "rus");
    
    ifstream fin;
    fin.open(path); //відкриття файлу для зчитування інформації

    if (!fin.is_open()) //перевірка відкриття файлу
    {
        cout << "err" << endl;
    }

    string str;

    while (!fin.eof()) {
        str = "";
        getline(fin, str);
        cout << str << endl;
    }

    fin.close();
}

void deleteProduct() {
    setlocale(LC_ALL, "rus");

    fstream deleteFile;
    deleteFile.open(path);

    if (!deleteFile.is_open()) {
        cout << "err" << endl;
    }

    vector<item>vectorItem;

    string slovo;
    string name;
    float price;
    int amount;

    cout << "Введiть iм'я товара, яке бажаєте видалити: " << endl;
    cin >> slovo;

    while (deleteFile >> name >> price >> amount) {
        if (name != slovo) {
            vectorItem.push_back({ name,price,amount });
        }
    }
    deleteFile.close();

    ofstream outFile(path); // открываем файл для записи (перезаписываем файл)
    if (outFile.is_open()) {
        for (const auto& item : vectorItem) {
            outFile << item.name << " " << item.price << " " << item.amount << "\n";
        }
        outFile.close();
    }
    else {
        std::cerr << "Не удалось открыть файл для записи.\n";
    }

}





int main(item items)
{
    setlocale(LC_ALL, "rus");
    using namespace std;
    
    int choise;
    string path = "products.txt";
   
    //вивід меню
   
        do {
            cout << " " << endl;
            cout << "|-------МЕНЮ--------|" << endl;
            cout << " " << endl;
            cout << "1.Додати товар" << endl;
            cout << "2.Видалити товар" << endl;
            cout << "3.Продивитися товар" << endl;
            cout << "4.Вийти" << endl;
            cout << " " << endl;
            cout << "|-------------------|" << endl;
            cout << " " << endl;

            cout << "Ввести вибiр: ";
            cin >> choise;

            switch (choise) {
            case 1: system("cls"); addProduct();  break;
            case 2: deleteProduct(); break;
            case 3: system("cls"); cout << "\n"; viewProduct();  break;
            case 4:  cout << " " << endl;  break;
            default: cout << "Не та цифра";
            }


        } while (choise != 4);
    
    
    



    return 0;
}