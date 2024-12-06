#pragma once

#include "Types.h"


namespace Tetris::Model
{
    class AbstractWidget
    {
    public:
        virtual ~AbstractWidget() = default;

        virtual void Update()
        {
            {
                std::lock_guard<std::mutex> loc(_mutex);
                UpdateWidget();
            }
            ProcessingEvents(); 
        };

        virtual bool IsOpen() const = 0;

        void SlotUpdateView(Model::DescriptionModel descp)
        {
            std::lock_guard<std::mutex> loc(_mutex);
            UpdateView(descp);
        };

    protected:

        virtual void UpdateWidget() = 0;

        virtual void ProcessingEvents() = 0;

        virtual void UpdateView(DescriptionModel) = 0;

    private:
        std::mutex _mutex;
    };
}