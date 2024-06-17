#include <iostream> 
#include <string> 
#include <locale.h> 
#include <fstream> 
#include <filesystem> 

using namespace std;
const string path = "products.txt"; //назва файлу 


//структура товару 
struct product
{
    char name[50];
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
    
        product item{};
        cout << "\n";
        cout << "Введiть назву товару: ";
        cin >> item.name;
        cout << "Введiть цiну товару: ";
        cin >> item.price;
        cout << "Введiть кiлькiсть товару: ";
        cin >> item.amount;

        fout << item.name;
        fout << " ";
        fout << item.price;
        fout << " ";
        fout << item.amount;
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
        return;
    }
    
    string str;

    while (!fin.eof()) {
        str = "";
        getline(fin, str);
        cout << str << endl;
    }
   
    fin.close();
}

void removeProduct() {
    setlocale(LC_ALL, "rus");
    string slovo;
    cout << "Введiть iм'я товара, яке бажаєте видалити: " << endl;
    cin >> slovo;

    ifstream inputFile(path); //відкриття і перевірка початкового файлу 
    if (!inputFile.is_open()) {
        cout << "err" << endl;
        return;
    }

    ofstream tempFile("temp.txt"); //відкриття і перевірка тимчасового файлу
    if (!tempFile.is_open()) {
        cout << "err" << endl;
        inputFile.close();
        return;
    }

    //читаємо строки з початкового файлу та записуємо потрібні строки в тимчасовий файл
    string line;
    while (getline(inputFile, line)) {
        if (line.find(slovo) == string::npos) {
            tempFile << line << endl;
        }
    }

    //закриття файлів
    inputFile.close();
    tempFile.close();
    
    remove(path.c_str()); //видалення початкового файлу

    rename("temp.txt", path.c_str()); //перейменування тимчасового файлу в початковий
}


int main(product item)
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
        case 2: removeProduct(); break;
        case 3: system("cls"); cout << "\n"; viewProduct();  break;
        case 4:  cout << " " << endl;  break;
        default: cout << "Не та цифра";
        }

    } while (choise != 4);

    return 0;
}
