#include "SFML/Widget.h"
#include "AbstractModel.h"


namespace Tetris::View::SFML
{
    Widget::Widget(AbstractModelPtr model, const std::string& pathFont)
        : IWidget(),
          _window({600u, 800u}, "Tetris"),
          _controller(model),
          _map(sf::Vector2f(420, 800), true),
          _previewBlock(sf::Vector2f(180, 150), true),
          _score(pathFont, sf::Color::White, sf::Text::Bold | sf::Text::Underlined)
    {
        InitializeScore();
        InitializePreviewBlock();
    }

    void Widget::InitializeScore()
    {
        _score.setPosition(sf::Vector2f(460, 400));
        _score.setString("Score:\n0");
        _score.setCharacterSize(30);
    }

    void Widget::InitializePreviewBlock()
    {
        _previewBlock.setPosition(sf::Vector2f(420, 0));
        _previewBlock.SetBlock(AbstractBlockPtr());
    }

    bool Widget::IsOpen() const
    {
        return _windowOpen;
    }

    void Widget::HandleEvents()
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _window.close();
                _windowOpen = false;
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                HandleKeyPress(event.key.scancode);
            }
        }
    }

    void Widget::HandleKeyPress(sf::Keyboard::Scancode scancode)
    {
        switch (scancode)
        {
        case sf::Keyboard::Scan::Left:
            _controller.Move(Model::Command::Left);
            break;
        case sf::Keyboard::Scan::Right:
            _controller.Move(Model::Command::Right);
            break;
        case sf::Keyboard::Scan::Up:
            _controller.Move(Model::Command::RotateRight);
            break;
        case sf::Keyboard::Scan::Down:
            _controller.Move(Model::Command::Down);
            break;
        default:
            break;
        }
    }

    Model::DescriptionModel Widget::GetDescriptionModel()
    {
        std::lock_guard<std::mutex> l(_mutex);
        return _actualDescription;
    }

    void Widget::Update()
    {
        if (IsOpen())
        {
            HandleEvents();

            Model::DescriptionModel descriptionModel = GetDescriptionModel();
            UpdateMap(descriptionModel);
            UpdatePreviewBlock(descriptionModel);
            UpdateScore(descriptionModel);

            Render();
        }
    }

    void Widget::SlotUpdateWidget(Model::DescriptionModel descp)
    {
        std::lock_guard<std::mutex> l(_mutex);
        _actualDescription = descp;
    }

    void Widget::UpdateMap(const Model::DescriptionModel &descriptionModel)
    {
        _map.SetMap(descriptionModel.map, descriptionModel.size);
    }

    void Widget::UpdatePreviewBlock(const Model::DescriptionModel& descriptionModel)
    {
        if (descriptionModel.nextBlock)
        {
            _previewBlock.SetBlock(descriptionModel.nextBlock);
        }
    }

    void Widget::UpdateScore(const Model::DescriptionModel& descriptionModel)
    {
        if (descriptionModel.score)
        {
            _score.setString("Score:\n" + std::to_string(*descriptionModel.score));
        }
    }

    void Widget::Render()
    {
        _window.clear();
        _window.draw(_map);
        _window.draw(_score);
        _window.draw(_previewBlock);
        _window.display();
    }

    void Widget::SlotCloseWidget()
    {
        _windowOpen = false;
    }
}
