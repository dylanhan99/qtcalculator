#include <QApplication>
#include <QPushButton>
#include <QObject>
#include <QGridLayout>
#include <QLineEdit>

//class Counter : public QObject
//{
//    Q_OBJECT;
//    Q_PROPERTY(int Value READ getValue WRITE setValue NOTIFY valueChanged);
//
//signals:
//    inline void valueChanged(int val)
//    {
//        
//    }
//
//private:
//	int m_Value{ 0 };
//};

class CalcNumberButton : public QWidget
{
    //Q_OBJECT
    //Q_PROPERTY(int number READ GetNumber)
public:
    CalcNumberButton(int num, QWidget* parent = nullptr)
        : QWidget(parent), m_number(num)
    {
        QPushButton* button = new QPushButton{ QString{'0' + GetNumber()}, this};
        connect(button, &QPushButton::clicked, this, &CalcNumberButton::onButtonPress);
    }

    int GetNumber() const { return m_number; }

public slots:
    void onButtonPress()
    {
        std::cout << GetNumber() << std::endl;
    }

private:
    int m_number{};
};

int main(int argc, char** argv)
{
    QApplication app{ argc, argv };

    QWidget window{};
    QGridLayout layout{&window};
    layout.addWidget(new QLineEdit{}, 0, 0, 1, 3);
    
    for (int i = 0; i < 3; ++i)
    {
        int row = i + 1;
        for (int j = 0; j < 3; ++j)
        {
            int col = j;
            int num = i * 3 + j;
            //layout.addWidget(new QPushButton{ QString{'0' + num}}, row, col);
            layout.addWidget(new CalcNumberButton{ num });
        }
    }


    window.show();
    //QPushButton button{};
    //button.show();

    return app.exec();
}