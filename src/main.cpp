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

int main(int argc, char** argv)
{
    QApplication app{ argc, argv };

    QGridLayout layout{};
    layout.addWidget(new QLineEdit{}, 0, 0, 1, 3);
    
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int num = i * 3 + j;
            layout.addWidget(new QPushButton{ QString{num} }, i, j);
        }
    }

    QPushButton button{};
    button.show();

    return app.exec();
}