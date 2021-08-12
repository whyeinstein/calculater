#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <sstream>
#include <map>
#include "helpwindow.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void CIN();
    void CIN2();
    void COUT(); //方便debug
    void setA();
    void checkroom(); //判断大小，并将字符串转字符数组（在进行函数计算之前）
    void checkstr0(); //检查是否有非法字符（在计算函数和转换进制之前）

    void checkhex(); //判断是否有非法的十六进制运算
    void calchex(); //将十六进制数字符串转为十进制数字符串

    void checkoct(); //判断是否有非法的八进制运算
    void calcoct(); //将八进制数字符串转为十进制数字符串

    void checkbit(); //判断是否有非法的二进制运算
    void calcbit(); //将二进制数字符串转为十进制数字符串

    void calclog();//对数函数
    void calcpow();//幂函数

    void checkSC();//检查三角函数的合法性：其后必须有一个合法数
    void calcSC();//计算三角函数，用计算后的数替代原算式中的三角函数

    void changenega();	//将所有的负数-a改为(0-a) (在计算函数和转换进制之后)

    void checkstr(); // 检查是否有非法字符（在计算三角函数、幂函数、对数函数之后
                     //此处的非法字符指除四则运算、数字、括号以外的其他任何字符
                     //同时一并检查运算符号是否被适当地使用


    void m_init();//初始化
    void setIN(QString a);
    QString getINPUT(); // 获得检查完毕无非法字符和运算的算式，允许进行四则运算
    void getSuffix();//获取后缀表达式
    double Calc_Suffix();//计算后缀表达式
    void checR();//判断所需输出的进制

    void Calcfun1();//	一元一次函数
    void Calcfun2();//  一元二次函数
    void Calcfun3();//  指数函数1
    void Calcfun4();//  指数函数2
    void Calcfun5();//  对数函数1
    void Calcfun6();//  对数函数2
    void Calcfun7();//  反比例函数


    int checkS();

    QString RADIX(double a);//将结果转换为不同的字符串

    int R=10;//判断输出的进制的变量




private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_compare_clicked();

    void on_solve_clicked();

    void on_pushButton_4_clicked();

    void on_action_triggered();

private:
    Ui::MainWindow *ui;

    QString input;  //输入的字符串
    char in[300];
    bool s=0;

    char IN[100];//输入的表达式
    vector<string> out;//后缀表达式
    stack<char> s1;//中缀表达式转换为后缀表达式时用到的栈
    stack<float> s2;//后缀表达式计算结果时用到的栈
    double result = 0;//计算结果
    double result2 = 0;//计算结果
    double a,b,c;//函数参数

    QPixmap image1;
    void paintEvent(QPaintEvent *event);// 绘制背景图片

    helpwindow hw;
};

#endif // MAINWINDOW_H
