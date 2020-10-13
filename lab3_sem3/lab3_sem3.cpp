﻿#include <iostream>
#include <stdlib.h>
#include <locale>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#define fflush while (getchar() != '\n')

class car {
public:
    char marka[30]; //Марка
    char model[30]; //Модель
    float engine; //Объём двигателя
    int power; //Кол-во л.с.
    char transmission[9]; //Коробка передач
    char color[20]; //Цвет машины
    int year; //Год автомобиля
    int price; //Цена
public:
    void Init() {
        ;
    }
    void Read() {
        //printf("Введите марку машины: ");
        //gets_s(marka);
        //printf("Введите модель машины: ");
        //gets_s(model);
        //printf("Введите объём двигателя: ");
        //scanf_s("%f", &q->engine);
        //fflush;
        //printf("Введите кол-во л.с.: ");
        //scanf_s("%d", &q->power);
        //fflush;
        //printf("Введите тип трансмиссии(коробка передач): ");
        //gets_s(q->transmission);
        //printf("Введите цвет автомобиля: ");
        //gets_s(q->color);
        //printf("Введите год автомобиля: ");
        //scanf_s("%d", &q->year);
        //fflush;
        //printf("Введите цену за данный автомобиль: ");
        //scanf_s("%d", &q->price);
        //fflush;
        //printf("\n");
    }
    void Display() {
        printf("%-12s %-12s %-5.1fл. %-4dл.с. %-10s %-15s %-6dг.\t %-16dрублей\n", marka, model, engine, power, transmission, color, year, price);  
    }
    void Add() {
        ;
    }
    void Sale() {
        ;
    }
    void Paint() {

    }
};

int balance = 0;

void Init(car* q) {
    q->marka[0] = 0;
    q->model[0] = 0;
    q->engine = 0;
    q->power = 0;
    q->transmission[0] = 0;
    q->color[0] = 0;
    q->year = 0;
    q->price = 0;
}

void Read(car* q) {
    printf("Введите марку машины: ");
    gets_s(q->marka);
    printf("Введите модель машины: ");
    gets_s(q->model);
    printf("Введите объём двигателя: ");
    scanf_s("%f", &q->engine);
    fflush;
    printf("Введите кол-во л.с.: ");
    scanf_s("%d", &q->power);
    fflush;
    printf("Введите тип трансмиссии(коробка передач): ");
    gets_s(q->transmission);
    printf("Введите цвет автомобиля: ");
    gets_s(q->color);
    printf("Введите год автомобиля: ");
    scanf_s("%d", &q->year);
    fflush;
    printf("Введите цену за данный автомобиль: ");
    scanf_s("%d", &q->price);
    fflush;
    printf("\n");
}

void Display(car* q) {
    printf("%-12s %-12s %-5.1fл. %-4dл.с. %-10s %-15s %-6dг.\t %-16dрублей\n", q->marka, q->model, q->engine, q->power, q->transmission, q->color, q->year, q->price);
}


void Add(car* q, car* q1) {
    int sum = q->price + q1->price;
    if (sum > 350000) { strcpy_s(q->marka, "Ferrari"); strcpy_s(q->model, "F430"); q->engine = 5, 0; q->power = 440; strcpy_s(q->transmission, "Автомат"); strcpy_s(q->color, "Красный"); q->year = 2018; q->price = 350000; }
    else if (sum > 250000) { strcpy_s(q->marka, "Nissan"); strcpy_s(q->model, "Skyline"); q->engine = 3, 0; q->power = 270; strcpy_s(q->transmission, "Автомат"); strcpy_s(q->color, "Серебристый"); q->year = 2004; q->price = 250000; }
    else if (sum > 150000) { strcpy_s(q->marka, "ВАЗ"); strcpy_s(q->model, "2101"); q->engine = 1, 0; q->power = 60; strcpy_s(q->transmission, "Механика"); strcpy_s(q->color, "Красный"); q->year = 1988; q->price = 150000; }
    else { strcpy_s(q->marka, "ЗАЗ"); strcpy_s(q->model, "966"); q->engine = 0, 8; q->power = 40; strcpy_s(q->transmission, "Механика"); strcpy_s(q->color, "Синий"); q->year = 1966; q->price = 0; }
}


void Sale(car* q) {
    balance += q->price;
}

void Paint(car* q, char* color) {
    strcpy_s(q->color, color);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    system("color 70");


    car bmw{ "bmw", "m5", 2.0, 200, "автомат", "черный", 2020, 300000 };
    car nissan{ "nissan", "sunny", 1.5, 140, "механика", "серебристый", 2001, 150000 };
    car toyota{ "toyota", "carib", 1.3, 83, "автомат", "зелёный", 1998, 100000 };


  /*  int k;
    char color[20];
    do {
        puts("Сколько автомобилей вы собиретесь добавить(не меньше 2)?");
        scanf_s("%d", &k);
        fflush;
    } while (k < 2);
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

