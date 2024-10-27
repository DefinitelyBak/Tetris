#pragma once

#include "Precompile.h"


namespace Tetris::Data
{

    /// @brief Потокобезопасная реализация очереди с блокировкой 
    /// @tparam T Хранимый тип в очереди
    template <typename T>
    class ThreadsafeQueue
    {
        /// @brief Узел очереди
        struct node
        {
            T data;
            std::unique_ptr<node> next;
            node(T data_): data(std::move(data_)) {}
        };

    public:
        /// @brief Конструктор по умолчанию
        explicit ThreadsafeQueue(): tail(nullptr) {};

        /// @brief Удалённый копирующий конструктор
        /// @param other Копируемый объект
        ThreadsafeQueue(const ThreadsafeQueue &other) = delete;

        /// @brief Удалённый оператор присвоения
        /// @param other Копируемый объект
        /// @return Новая очередь
        ThreadsafeQueue &operator=(const ThreadsafeQueue &other) = delete;

        /// @brief Попробовать получить значение из очереди
        /// @return При неудачи nullptr
        std::shared_ptr<T> try_pop()
        {
            if(!head)
                return std::shared_ptr<T>();
            
            std::shared_ptr<T> const res(
                std::make_shared<T>(std::move(head->data))
            );
            std::unique_ptr<node> const old_head = std::move(head);
            head = std::move(old_head->next);
            if (!head)
                tail = nullptr;

            return res;
        }

        /// @brief Вставить элемент в очередь
        /// @param new_value Новое значение
        void push(T new_value)
        {
            std::unique_ptr<node> p = std::make_unique<node>(std::move(new_value));
            node* const new_tail = p.get();
            if(tail)
                tail->next = std::move(p);
            else
                head = std::move(p);
            
            tail = new_tail;
        }

    private:
        std::unique_ptr<node> head;
        node* tail;
    };

} // namespace  