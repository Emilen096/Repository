#include "pch.h"
#include "C:\Users\EMIL\.vscode\c++\Deque.h"
#include "C:\Users\EMIL\.vscode\c++\Deque.cpp"
#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>

#include "Deque.h"
#include <gtest/gtest.h>

// Проверка конструктора со списком инициализации
TEST(DequeTests, InitializerListConstructor) {
    Deque d{1, 2, 3, 4};
    EXPECT_EQ(d.size(), 4);          // Проверка размера
    EXPECT_EQ(d.front(), 1);         // Проверка первого элемента
    EXPECT_EQ(d.back(), 4);          // Проверка последнего элемента
}

// Проверка вставки в начало и в конец
TEST(DequeTests, PushBackAndFront) {
    Deque d;
    d.push_back(10);                 // Добавляем в конец
    d.push_front(5);                 // Добавляем в начало
    EXPECT_EQ(d.size(), 2);          // Размер должен быть 2
    EXPECT_EQ(d.front(), 5);         // Первый — 5
    EXPECT_EQ(d.back(), 10);         // Последний — 10
}

// Проверка удаления с начала и с конца
TEST(DequeTests, PopBackAndFront) {
    Deque d{1, 2, 3};
    d.pop_front();                   // Удаляем первый элемент (1)
    EXPECT_EQ(d.front(), 2);         // Теперь первый — 2
    d.pop_back();                    // Удаляем последний элемент (3)
    EXPECT_EQ(d.back(), 2);          // Теперь остался один элемент — 2
    d.pop_back();                    // Удаляем оставшийся
    EXPECT_TRUE(d.empty());          // Дека должна быть пустой
}

// Проверка конструктора копирования
TEST(DequeTests, CopyConstructor) {
    Deque original{1, 2, 3};
    Deque copy = original;           // Копируем объект
    copy.push_back(100);             // Изменяем копию
    EXPECT_EQ(original.size(), 3);   // Оригинал не должен измениться
    EXPECT_EQ(copy.size(), 4);       // Копия должна быть длиннее
    EXPECT_EQ(copy.back(), 100);     // Проверяем последний элемент копии
}

// Проверка конструктора перемещения
TEST(DequeTests, MoveConstructor) {
    Deque source{4, 5, 6};
    Deque moved = std::move(source); // Перемещаем объект
    EXPECT_EQ(moved.size(), 3);      // Новый объект должен содержать 3 элемента
    EXPECT_TRUE(source.empty());     // Исходный объект должен быть пустым
}

// Проверка оператора присваивания (копирование)
TEST(DequeTests, CopyAssignmentOperator) {
    Deque a{7, 8};
    Deque b;
    b = a;                           // Копируем через оператор =
    EXPECT_EQ(b.size(), 2);          // Размер должен совпадать
    EXPECT_EQ(b.front(), 7);         // Проверка первого элемента
}

// Проверка оператора присваивания (перемещение)
TEST(DequeTests, MoveAssignmentOperator) {
    Deque a{9, 10};
    Deque b;
    b = std::move(a);                // Перемещаем объект
    EXPECT_EQ(b.size(), 2);          // Новый объект должен содержать данные
    EXPECT_TRUE(a.empty());          // Исходный должен быть пустым
}

// Проверка метода toString()
TEST(DequeTests, ToStringOutput) {
    Deque d{1, 2, 3};
    EXPECT_EQ(d.toString(), "[ 1 2 3 ]"); // Ожидаемое строковое представление
}

// Проверка методов empty() и size()
TEST(DequeTests, EmptyAndSize) {
    Deque d;
    EXPECT_TRUE(d.empty());          // Новая дека должна быть пустой
    d.push_back(42);
    EXPECT_FALSE(d.empty());         // Теперь не пустая
    EXPECT_EQ(d.size(), 1);          // Размер = 1
}

// Проверка переполнения дека (capacity = 100)
TEST(DequeTests, OverflowThrows) {
    Deque d;
    for (std::size_t i = 0; i < 100; ++i) {
        d.push_back(static_cast<int>(i)); // Заполняем до предела
    }
    EXPECT_THROW(d.push_back(101), std::overflow_error);  // Переполнение через push_back
    EXPECT_THROW(d.push_front(102), std::overflow_error); // Переполнение через push_front
}

// Проверка исключений при доступе к пустому деку
TEST(DequeTests, FrontBackThrowsOnEmpty) {
    Deque d;
    EXPECT_THROW(d.front(), std::out_of_range); // front() при пустом деке
    EXPECT_THROW(d.back(), std::out_of_range);  // back() при пустом деке
}

// Смешанные операции push/pop и проверка целостности
TEST(DequeTests, MixedOperationsStability) {
    Deque d;
    d.push_back(1);     // [1]
    d.push_front(2);    // [2, 1]
    d.push_back(3);     // [2, 1, 3]
    d.pop_front();      // [1, 3]
    d.push_front(4);    // [4, 1, 3]
    d.pop_back();       // [4, 1]

    EXPECT_EQ(d.size(), 2);              // Размер = 2
    EXPECT_EQ(d.front(), 4);             // Первый — 4
    EXPECT_EQ(d.back(), 1);              // Последний — 1
    EXPECT_EQ(d.toString(), "[ 4 1 ]");  // Проверка содержимого
}


// Main entry for Google Test
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
