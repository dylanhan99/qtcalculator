#include <QApplication>
#include <QPushButton>
#include <QObject>
#include <QGridLayout>
#include <QLineEdit>

class CalcNumberButton : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int number READ GetNumber)
public:
    CalcNumberButton(QLineEdit* calcScreen, int num, QWidget* parent = nullptr)
        : QWidget(parent), m_calcScreen(calcScreen), m_number(num)
    {
        m_myButton = new QPushButton{ QString{'0' + GetNumber()}, this };
        connect(m_myButton, &QPushButton::clicked, this, &CalcNumberButton::onButtonPress);
    }

    int GetNumber() const { return m_number; }

public Q_SLOTS:
    void onButtonPress()
    {
        m_calcScreen->setText(m_calcScreen->text() + m_myButton->text());
    }

private:
    QLineEdit* m_calcScreen{};
    QPushButton* m_myButton{};
    int m_number{};
};

// -2 == <
// -1 == <=
//  0 == =
//  1 == >=
//  2 == >
static int CompOperator(char const lhs, char const rhs)
{

}

static bool IsOperand(char const c)
{
    return '0' <= c && c <= '9';
}

static bool IsOperator(char const c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// p > start of string
// numberEnd > number of characters the number is
static int GetNumber_Infix(const char* p, size_t const& startPos, size_t* numLen)
{
    int num{};
    for (size_t i = startPos; ; ++i)
    {

        {

            if (numLen) *numLen = i - startPos;
        }
    }

    return 0;
}

// A*B+C/D
// to
// AB*C+
// infix is assumed to be SPACE separated
std::string InfixToPostfix(std::string const& infix)
{
    std::string postfix{};
    std::stack<int> numberStack{};
    std::stack<OperatorPrecedence> opStack{};
    
    std::stringstream ss{ infix };
    std::string str{};
    while (ss >> str)
    {
        if (str == "(")
        {
            opStack.push(OperatorPrecedence::OpenBracket);
        }
        else if (str == ")")
        {
            opStack.push(OperatorPrecedence::CloseBracket);
        }
        else if (str == "+" || str == "*" || str == "-" || str == "/")
        {
            opStack.push(OperatorPrecedence::CloseBracket);
        }
        else // Is a number
        {

        }

        auto const& c = infix[i];
        if (IsOperand(c))
        {
            size_t numLen{};
            int currNum = GetNumber_Infix(infix.data(), i, &numLen);

            i += numLen;
            continue;
        }
        else if (IsOperator(c))
        {

        }
        else
        {
            // invalid
        }
    }
}

int main(int argc, char** argv)
{
    QApplication app{ argc, argv };

    QWidget* window = new QWidget{};
    QGridLayout* layout = new QGridLayout{window};
    QLineEdit* calcScreen = new QLineEdit{};
    layout->addWidget(calcScreen, 0, 0, 1, 3);
    
    layout->addWidget(new CalcNumberButton{ calcScreen, 7, window }, 1, 0);
    layout->addWidget(new CalcNumberButton{ calcScreen, 8, window }, 1, 1);
    layout->addWidget(new CalcNumberButton{ calcScreen, 9, window }, 1, 2);
    layout->addWidget(new CalcNumberButton{ calcScreen, 4, window }, 2, 0);
    layout->addWidget(new CalcNumberButton{ calcScreen, 5, window }, 2, 1);
    layout->addWidget(new CalcNumberButton{ calcScreen, 6, window }, 2, 2);
    layout->addWidget(new CalcNumberButton{ calcScreen, 1, window }, 3, 0);
    layout->addWidget(new CalcNumberButton{ calcScreen, 2, window }, 3, 1);
    layout->addWidget(new CalcNumberButton{ calcScreen, 3, window }, 3, 2);

    layout->addWidget(new CalcNumberButton{ calcScreen, 0, window }, 4, 0);

    window->show();

    InfixToPostfix();

    return app.exec();
}

#include "main.moc"