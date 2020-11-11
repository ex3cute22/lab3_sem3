#include <iostream>
#include <stdlib.h>
#include <locale>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#define fflush while (getchar() != '\n')
#define AMOUNTCAR 3 

//using namespace std;

class car {
private:
    std::string marka; //Марка
    std::string model; //Модель
    float engine; //Объём двигателя
    int power; //Кол-во л.с.
    std::string transmission; //Коробка передач
    std::string color; //Цвет машины
    int year; //Год автомобиля
    int price; //Цена:
public:
    void Init() {
        marka = " ";
        model = " ";
        engine = 0;
        power = 0;
        transmission = " ";
        color = " ";   
        year = 0;
        price = 0;
    }
    void Init(std:: string _marka, std:: string _model, float _engine, int _power, std:: string _transmission, std:: string _color, int _year, int _price) {
        marka = " ";
        model = " ";
        marka =_marka;
        model = _model;
        engine = _engine;
        power = _power;
        transmission = " ";
        color = " ";
        transmission = _transmission;
        color = _color;
        year = _year;
        price = _price;
    }
    void Read() {
        printf("Введите марку машины: ");
        std:: cin >> marka;
        printf("Введите модель машины: ");
        std::cin >> model;
        printf("Введите объём двигателя: ");
        scanf_s("%f", &engine);
        fflush;
        printf("Введите кол-во л.с.: ");
        scanf_s("%d", &power);
        fflush;
        printf("Введите тип трансмиссии(коробка передач): ");
        std::cin >> transmission;
        printf("Введите цвет автомобиля: ");
        std::cin >> color;
        printf("Введите год автомобиля: ");
        scanf_s("%d", &year);
        fflush;
        printf("Введите цену за данный автомобиль: ");
        scanf_s("%d", &price);
        fflush;
        printf("\n");
    }
    void Display() {
        std::cout << marka << std::endl;
        std::cout << model << std::endl;
        std::cout << engine << std::endl;
        std::cout << power << std::endl;
        std::cout << transmission << std::endl;
        std::cout << color << std::endl;
        std::cout << year << std::endl;
        std::cout << price << std::endl << std::endl;

    }
    void Add(car object) {
        int sum = price + object.price;
        if (sum > 350000) {
            marka = "Ferrari"; model = "F430"; engine = 5.0; power = 440; transmission = "Автомат", color = "Красный", year = 2018; price = 350000;
        }
        else if (sum > 250000) {
            marka = "Nissan"; model = "Skyline"; engine = 3.0; power = 270; transmission = "Автомат", color = "Серебристый", year = 2004; price = 250000;
        }
        else if (sum > 150000) {
            marka = "ВАЗ"; model = "2101"; engine = 1.0; power = 60; transmission = "Механика", color = "Красный", year = 1988; price = 150000;
        }
        else {
            marka = "ЗАЗ"; model = "966"; engine = 0.8; power = 40; transmission = "Механика", color = "Синий", year = 1966; price = 0;
        }
    }
    void Sale(int &_balance) {
       _balance += price;
    }
    void Paint() {
        std::string newColor;
        std:: cout << "\nСтарый цвет: " << color << "\tНовый цвет: ";
        std::cin >> newColor;
        color = newColor;
    }
};

int balance = 0;


//void Add(car* q, car* q1) {
//    int sum = q->price + q1->price;
//    if (sum > 350000) { strcpy_s(q->marka, "Ferrari"); strcpy_s(q->model, "F430"); q->engine = 5, 0; q->power = 440; strcpy_s(q->transmission, "Автомат"); strcpy_s(q->color, "Красный"); q->year = 2018; q->price = 350000; }
//    else if (sum > 250000) { strcpy_s(q->marka, "Nissan"); strcpy_s(q->model, "Skyline"); q->engine = 3, 0; q->power = 270; strcpy_s(q->transmission, "Автомат"); strcpy_s(q->color, "Серебристый"); q->year = 2004; q->price = 250000; }
//    else if (sum > 150000) { strcpy_s(q->marka, "ВАЗ"); strcpy_s(q->model, "2101"); q->engine = 1, 0; q->power = 60; strcpy_s(q->transmission, "Механика"); strcpy_s(q->color, "Красный"); q->year = 1988; q->price = 150000; }
//    else { strcpy_s(q->marka, "ЗАЗ"); strcpy_s(q->model, "966"); q->engine = 0, 8; q->power = 40; strcpy_s(q->transmission, "Механика"); strcpy_s(q->color, "Синий"); q->year = 1966; q->price = 0; }
//}
//
//
//


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    system("color 70");

    int balance = 0;

    //Статические обьекты класса
    car toyota;
    car bmw;

    toyota.Init("toyota", "carib", 1.3, 83, "автомат", "зелёный", 1998, 100000);
    bmw.Init("bmw", "m5", 2.0, 200, "автомат", "чёрный", 2020, 300000);
    toyota.Add(bmw);
    toyota.Display();
    system("pause");
    system("cls");

    //Динамические обьекты класса
    car* lamba;
    lamba = (car*)calloc(AMOUNTCAR, sizeof(car));
    lamba = (car*)realloc(lamba, sizeof(car) * AMOUNTCAR * 2);
    lamba = (car*)calloc(AMOUNTCAR, sizeof(car) * 2);
    (lamba)->Init();
    (lamba + 1)->Init("lamba", "veneno", 4.6, 400, "автомат", "красный", 2019, 400000);
    (lamba + 2)->Init();
    (lamba + 2)->Read();
    for (int i = 1; i < AMOUNTCAR; i++)
        (lamba + i)->Display();
    free(lamba);
    system("pause");
    system("cls");

    //Применение new, delete, delete[]
    car* Cars = new car[AMOUNTCAR];
    Cars[0].Init();
    Cars[1].Init("toyota", "carib", 1.3, 83, "автомат", "зелёный", 1998, 100000);
    Cars[2].Init();
    Cars[2].Read();
    Cars[2].Paint();
    Cars[2].Sale(balance);
    Cars[1].Sale(balance);
    std::cout << "Баланс: " << balance << std::endl;

  
    for (int i = 1; i < AMOUNTCAR; i++)
        Cars[i].Display();
    system("pause");
    system("cls");
    delete[] Cars;



 //    cars[0].Init();
 //cars[1].Init("toyota", "carib", 1.3, 83, "автомат", "зелёный", 1998, 100000);
 //toyota = cars[1];
 //bmw = cars[2];
 //cars[2].Read();
 //cars[2].Paint();
 //cars[1].Display();
 //cars[2].Display();
 //cars[2].Sale(balance);
 //cars[1].Sale(balance);
 //std::cout << "Баланс: " << balance;



   /*
    printf("\n");
    for (int i = 0; i < k; i++) {
        Init(car + i);
        Read(q + i);
    }
    system("cls");
    for (int i = 0; i < k; i++) 
        Display(q + i);
    }
    printf("\nКакой автомобиль вы хотите продать?\nУкажите порядковый номер: ");
    int num;
    int num1;
    scanf_s("%d", &num);
    fflush;
    Sale(q + num - 1);
    for (int i = num - 1; i < k; i++) {
        q[i] = q[i + 1];
    }
    k--;
    system("cls");
    printf("Поздравяем вас с продажей автомобиля\nВаш баланс: %d руб.\n\n", balance);
    for (int i = 0; i < k; i++) {
        Display(q + i);
    }
    printf("\nКакую машину вы хотите покрасить?\nУкажите порядковый номер: ");
    scanf_s("%d", &num);
    fflush;
    printf("\nСтарый цвет: %s \tНовый цвет: ", q[num - 1].color);
    gets_s(color);
    puts("\n");
    Paint(q + num - 1, color);
    for (int i = 0; i < k; i++) {
        Display(q + i);
    }
    system("pause");
    system("cls");
    for (int i = 0; i < k; i++) {
        Display(q + i);
    }
    puts("\n");
    if (k >= 2) {
        printf("Какие 2 машины вы хотите обменять на другую(функция сложения)?\nУкажите порядковые номера.\nПервая машина: ");
        scanf_s("%d", &num);
        fflush;
        printf("Вторая машина: ");
        scanf_s("%d", &num1);
        fflush;
        Add(q + num - 1, q + num1 - 1);
        for (int i = num1 - 1; i < k; i++) {
            q[i] = q[i + 1];
        }
        k--;
    }
    else ("Обменять машины не получилось, так как их кол-во меньше 2");
    puts("\n");
    for (int i = 0; i < k; i++) {
        Display(q + i);
    }*/
}

