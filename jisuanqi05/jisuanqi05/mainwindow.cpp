#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <config.h>
#include <iostream>
#include <qpainter.h>

void MainWindow::CIN()
{
    input=ui->lineEdit->text();
}

void MainWindow::CIN2()
{
    input=ui->lineEdit_2->text();
}

void MainWindow::COUT()
{
    if(s==1)
        ui->lineEdit_2->setText(input);
    else
        return;
}

void MainWindow::setA()
{
    in[0]='\0';
}

int MainWindow::checkS() {

    if (MainWindow::s == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void MainWindow::checkroom()
{
    QString a=input;
    if(a.size()>99)
    {
        ui->lineEdit_3->setText("计算式过长，请重新输入！");
        s=0;
    }
    else if(a.size()<1)
    {
        ui->lineEdit_3->setText("计算式过短，请重新输入！");
        s=0;
    }
    else
    {
        s=1;

        //string转char数组
        QByteArray ba=a.toLocal8Bit();
        memcpy(in,ba.data(),ba.size()+1);

        ui->lineEdit_3->setText("计算ing");
    }
}

void MainWindow::checkstr0()
{
    if (s)
    {
        for (int i = 0; i < input.size(); i++)
            {
                if ((int)in[i] <= 57 && (int)in[i] >= 48) //数字1～9
                {
                    continue;
                }
                else if (in[i] == '+')
                {
                    continue;
                }
                else if (in[i] == '-')
                {
                    continue;
                }
                else if (in[i] == '*')
                {
                    continue;
                }
                else if (in[i] == '/')
                {
                    continue;
                }
                else if (in[i] == '(')
                {
                    continue;
                }
                else if (in[i] == ')')
                {
                    continue;
                }
                else if (in[i] == '.')
                {
                    continue;
                }
                else if (in[i] == '^')
                {
                    continue;
                }
                else if (in[i] <= 'z' && in[i] >= 'a') //英文小写字母
                {
                    continue;
                }
                else if (in[i] <= 'Z' && in[i] >= 'A') //英文大写字母
                {
                    continue;
                }
                else
                {
                    ui->lineEdit_3->setText("计算式中含有非法字符！");
                    in[0] = '\0';
                    s = 0;
                    return;
                }
            }
    }
    else
        return;

}

void MainWindow::checkhex()
{
    if (s)
    {
        in[0] = '\0';
        int d = 0;

        //strcpy(in, INPUT.c_str()); 兼容c语言的拷贝
        //string拷贝至char

        QByteArray ba=input.toLocal8Bit();
        memcpy(in,ba.data(),ba.size()+1);

        for (int i = 0; i < input.size(); i++)
        {
            if (in[i] == 'H')
            {
                d = 0;

                if (i == input.size() - 1)
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 2");
                    s = 0;
                    return;
                }

                for (int x = i + 1; x < input.size(); x++)
                {
                    if (((int)in[x] <= 57 && (int)in[x] >= 48) || (in[x] <= 'f' && in[x] >= 'a')) //数字或小写字母a到f
                    {
                        continue;
                    }
                    else if (in[x] >= 'A' && in[x] <= 'F') //大写字母A到F
                    {
                        in[x] += 32;
                        continue;
                    }
                    else if ((in[x] > 'f' && in[x] <= 'z') || (in[x] > 'F' && in[x] <= 'Z'))	//小写或大写的G到Z
                    {
                        ui->lineEdit_3->setText("输入的算式不符合规范 3");
                        s = 0;
                        return;
                    }
                    else
                    {
                        if (x == i + 1)
                        {
                            ui->lineEdit_3->setText("输入的算式不符合规范 4");
                            s = 0;
                            return;
                        }
                        else if (in[x] == '.')
                        {
                            d++;
                            if (x == input.size() - 1)
                            {
                                ui->lineEdit_3->setText("输入的算式不符合规范 5");
                                s = 0;
                                return;	//小数点不能为最后一位
                            }
                            else if (d == 1)
                            {
                                continue;
                            }
                            else
                            {
                                ui->lineEdit_3->setText("输入的算式不符合规范 6");
                                s = 0;
                                return;	//不能含有多个小数点
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        in[0] = '\0';
    }
    else  return;
}

void MainWindow::calchex()
{
    if (s)
    {
        char Input[100];
        Input[0] = '\0';
        in[0] = '\0';
        double n = 0;
        int p = 0;
        int x,y;
        int i;


        QByteArray ba=input.toLocal8Bit();
        memcpy(in,ba.data(),ba.size()+1);


        for ( i = 0; i < input.size(); i++)
        {
            if (in[i] == 'H')
            {
                for ( x = i + 1; x < input.size(); x++)
                {

                       if (in[x] >= 'a' && in[x] <= 'f')
                        {
                            n = 16 * n + (10 + ((double)in[x] - (double)'a'));

                            if (x == input.size() - 1)	//	若是最后一位
                            {
                                p = x - i + 1;
                                break;
                            }
                        }
                        else if (in[x] >= '0' && in[x] <= '9')
                        {
                            n = 16 * n + ((double)in[x] - (double)'0');

                            if (x == input.size() - 1)	//	若是最后一位
                            {
                                p = x - i + 1;
                                break;
                            }
                        }

                    else if (in[x] == '.')
                    {
                        double a;

                        for ( y = x + 1; y < input.size(); y++)
                        {
                            a = (double)y - (double)x;

                            if (in[y] >= 'a' && in[y] <= 'f')
                            {
                                n = n + (10 + (double)in[y] - (double)'a') * pow(0.0625, a);

                                if (y == input.size() - 1)	//	若是最后一位
                                {
                                    p = y - i + 1;
                                    break;
                                }

                            }
                            else if (in[y] >= '0' && in[y] <= '9')
                            {
                                n = n + ((double)in[y] - (double)'0') * pow(0.0625, a);

                                if (y == input.size() - 1)	//	若是最后一位
                                {
                                    p = y - i + 1;
                                    break;
                                }
                            }
                            else
                            {
                                p = y - i;
                                break;
                            }

                        }

                        break;
                    }
                    else
                    {
                        p = x - i;
                        break;
                    }

                }

                sprintf(Input, "%.6lf", n);

                input.replace(i,p,Input);

                i+=p;
                i++;
                p=0;
            }
        }
    }
}

void MainWindow::checkoct()
{
    if (s)
    {
        in[0] = '\0';
        int d = 0;

        //strcpy(in, INPUT.c_str());
        QByteArray ba=input.toLocal8Bit();
        memcpy(in,ba.data(),ba.size()+1);

        for (int i = 0; i < input.size(); i++)
        {
            if (in[i] == 'O')
            {
                d = 0;

                if (i == input.size() - 1)
                {
                    //cout << "输入的算式不符合规范！7" << endl;
                    ui->lineEdit_3->setText("输入的算式不符合规范！7");
                    s = 0;
                    return;
                }

                for (int x = i + 1; x < input.size(); x++)
                {
                    if ((int)in[x] <= 55 && (int)in[x] >= 48) //数字0-7
                    {
                        continue;
                    }
                    else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z') || ((int)in[x] >= 56 && (int)in[x] <= 57))
                    {
                        //cout << "输入的算式不符合规范！8" << endl;
                        ui->lineEdit_3->setText("输入的算式不符合规范！8");
                        s = 0;
                        return;
                    }
                    else
                    {
                        if (x == i + 1)
                        {
                            //cout << "输入的算式不符合规范！9" << endl;
                            ui->lineEdit_3->setText("输入的算式不符合规范！9");
                            s = 0;
                            return;
                        }
                        else if (in[x] == '.')
                        {
                            d++;
                            if (x == input.size() - 1)
                            {
                                //cout << "输入的算式不符合规范！10" << endl;
                                ui->lineEdit_3->setText("输入的算式不符合规范！10");
                                s = 0;
                                return;	//小数点不能为最后一位
                            }
                            else if (d == 1)
                            {
                                continue;
                            }
                            else
                            {
                                //cout << "输入的算式不符合规范！11" << endl;
                                ui->lineEdit_3->setText("输入的算式不符合规范！11");
                                s = 0;
                                return; //不能含有多个小数点
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        in[0] = '\0';
    }
    else  return;
}

void MainWindow::calcoct()
{
    if (s)
    {
        char Input[100];
        Input[0] = '\0';
        in[0] = '\0';
        double n = 0;
        int p;
        int x,y;
        int i;

        //strcpy(in, INPUT.c_str());
        QByteArray ba=input.toLocal8Bit();
        memcpy(in,ba.data(),ba.size()+1);


        for (i = 0; i < input.size(); i++)
        {
            if (in[i] == 'O')
            {
                for (x = i + 1;; x++)
                {

                    if (in[x] >= '0' && in[x] <= '7')
                    {

                        n = 8 * n + ((double)in[x] - (double)'0');

                        if (x == input.size() - 1)	//	若是最后一位
                        {
                            p = x - i + 1;
                            break;
                        }

                    }
                    else if (in[x] == '.')
                    {
                        double a;
                        for ( y = x + 1;; y++)
                        {
                            a = (double)y - (double)x;

                            if (in[y] >= '0' && in[y] <= '7')
                            {
                                n = n + ((double)in[y] - (double)'0') * pow(0.125, a);

                                if (y == input.size() - 1)	//	若是最后一位
                                {
                                    p = y - i + 1;
                                    break;
                                }
                            }
                            else
                            {
                                p = y - i;
                                break;
                            }
                        }

                        break;
                    }
                    else
                    {
                        p = x - i;
                        break;
                    }

                }

                sprintf(Input, "%.6lf", n);

                input.replace(i, p, Input);

                i+=p;
                i++;
                p=0;
            }

        }
    }
}

void MainWindow::checkbit()
{
    if (s)
    {
        in[0] = '\0';
        int d = 0;

        //strcpy(in, input.c_str());
        QByteArray ba=input.toLocal8Bit();
        memcpy(in,ba.data(),ba.size()+1);

        for (int i = 0; i < input.size(); i++)
        {
            if (in[i] == 'B')
            {
                d = 0;

                if (i == input.size() - 1)
                {
                     ui->lineEdit_3->setText("输入的算式不符合规范！12");
                    s = 0;
                    return;
                }

                for (int x = i + 1; x < input.size(); x++)
                {
                    if (in[x] == '0' || in[x] == '1') //数字0或1
                    {
                        continue;
                    }
                    else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z') || ((int)in[x] <= 57 && (int)in[x] >= 51))
                    {
                        ui->lineEdit_3->setText("输入的算式不符合规范！13");
                        s = 0;
                        return;
                    }
                    else
                    {
                        if (x == i + 1)
                        {
                            ui->lineEdit_3->setText("输入的算式不符合规范！14");
                            s = 0;
                            return;
                        }
                        else if (in[x] == '.')
                        {
                            d++;
                            if (x == input.size() - 1)
                            {
                                ui->lineEdit_3->setText("输入的算式不符合规范！15");
                                s = 0;
                                return;	//小数点不能为最后一位
                            }
                            else if (d == 1)
                            {
                                continue;
                            }
                            else
                            {
                                ui->lineEdit_3->setText("输入的算式不符合规范！16");
                                s = 0;
                                return; //不能含有多个小数点
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        in[0] = '\0';
    }
    else  return;
}

void MainWindow::calcbit()
{
    if (s)
    {
        char Input[100];
        Input[0] = '\0';
        in[0] = '\0';
        double n = 0;
        int p;
        int x,y;
        int i;

        //strcpy(in, INPUT.c_str());
        QByteArray ba=input.toLocal8Bit();
        memcpy(in,ba.data(),ba.size()+1);

        for (i = 0; i < input.size(); i++)
        {
            if (in[i] == 'B')
            {
                for (x = i + 1;; x++)
                {

                    if (in[x] == '0' || in[x] == '1')
                    {

                        n = 2 * n + ((double)in[x] - (double)'0');

                        if (x == input.size() - 1)	//	若是最后一位
                        {
                            p = x - i + 1;
                            break;
                        }

                    }
                    else if (in[x] == '.')
                    {
                        double a;
                        for (y = x + 1;; y++)
                        {
                            a = (double)y - (double)x;

                            if (in[y] == '0' || in[y] == '1')
                            {
                                n = n + ((double)in[y] - (double)'0') * pow(0.5, a);

                                if (y == input.size() - 1)	//	若是最后一位
                                {
                                    p = y - i + 1;
                                    break;
                                }
                            }
                            else
                            {
                                p = y - i;
                                break;
                            }
                        }

                        break;
                    }
                    else
                    {
                        p = x - i;
                        break;
                    }

                }

                sprintf(Input, "%.6lf", n);

                input.replace(i, p, Input);

                i+=p;
                i++;
                p=0;

            }

        }
    }
}

void MainWindow::calclog()
{
    if (s)
    {
        QString LOG = "log";

        int pos;
        int q1 = 0, q2 = 0;
        double v1 = 0, v2 = 0, resultlog;
        QString L1;
        char Input[300];
        in[0] = '\0';
        //strcpy(in, INPUT.c_str());
        QByteArray ba=input.toLocal8Bit();
        memcpy(in,ba.data(),ba.size()+1);


        pos = input.indexOf(LOG);

        int p = pos + 3, p2 = 0;

        while (pos != -1)
        {
            if (pos == input.size() - 3)
            {
                //cout << "输入的算式不符合规范！33" << endl;
                ui->lineEdit_3->setText("输入的算式不符合规范！33");
                s = 0;
                return;
            }


            for (int x = pos + 3; x < input.size(); x++)
            {
                if ((in[x] <= '9' && in[x] >= '0') || in[x] == '.') //数字0-9或小数点
                {
                    if (x == input.size() - 1)
                    {
                        //cout << "输入的算式不符合规范！34" << endl;
                        ui->lineEdit_3->setText("输入的算式不符合规范！34");
                        s = 0;
                        return;
                    }
                    else
                        continue;
                }
                else if (in[x] == '(' && x != input.size() - 1)
                {
                    if (in[x - 1] == 'g')
                    {
                        //cout << "输入的算式不符合规范！35" << endl;
                        ui->lineEdit_3->setText("输入的算式不符合规范！35");
                        s = 0;
                        return;	//log后不可直接跟'('
                    }
                    else
                    {
                        p2 = x + 1;
                        q1 = x - p;	//第一个参数的长度

                        for (int y = x + 1; y < input.size(); y++)
                        {
                            if (((int)in[y] <= 57 && (int)in[y] >= 48) || in[y] == '.') //数字0-9或小数点
                            {
                                if (y == input.size() - 1)
                                {
                                    //cout << "输入的算式不符合规范！36" << endl;
                                    ui->lineEdit_3->setText("输入的算式不符合规范！36");
                                    s = 0;
                                    return;
                                }
                                else
                                    continue;
                            }
                            else if (in[y] == ')')
                            {
                                q2 = y - x - 1;	//第二个参数的长度
                                break;

                            }
                            else
                            {
                                //cout << "输入的算式不符合规范！37" << endl;
                                ui->lineEdit_3->setText("输入的算式不符合规范！37");
                                s = 0;
                                return;
                            }
                        }
                    }
                    break;
                }
                else
                {
                    //cout << "输入的算式不符合规范！38" << endl;
                    ui->lineEdit_3->setText("输入的算式不符合规范！38");
                    s = 0;
                    return;
                }
            }
            v1 = 0;
            v2 = 0;
            input[0] = '\0';

            L1 = input.mid(p, q1);
            //convertFromString(v1, L1);
            v1=L1.toDouble();

            L1 = input.mid(p2, q2);
            //convertFromString(v2, L1);
            v2=L1.toDouble();

            resultlog = log(v2) / log(v1);

            sprintf(Input, "%.6lf", resultlog);

            input.replace(pos, q1 + q2 + 5, Input);

            in[0] = '\0';
            //strcpy(in, INPUT.c_str());
            QByteArray ba=input.toLocal8Bit();
            memcpy(in,ba.data(),ba.size()+1);

            pos = input.indexOf(LOG);
            p = pos + 3, p2 = 0;

        }

    }

}

void MainWindow::checkSC()
{
    if (s)
    {
        in[0] = '\0';
        int d = 0;

        QByteArray ba=input.toLocal8Bit();
        memcpy(in,ba.data(),ba.size()+1);


        for (int i = 0; i < input.size() - 2 && input.size() >3; i++)
        {
            if (input.mid(i, 3) == "sin" && i < input.size() - 2)
            {
                d = 0;

                if (i == input.size() - 3)
                {
                     ui->lineEdit_3->setText("输入的算式不符合规范 17");
                    s = 0;
                    return;

                    //sin不能作为字符串的结尾
                }

                for (int x = i + 3; x < input.size(); x++)
                {
                    if ((int)in[x] <= 57 && (int)in[x] >= 48) //数字0-9
                    {
                        continue;
                    }
                    else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z'))
                    {
                         ui->lineEdit_3->setText("输入的算式不符合规范 18");
                        s = 0;
                        return;
                    }
                    else
                    {
                        if (x == i + 3)
                        {
                            ui->lineEdit_3->setText("输入的算式不符合规范 19");
                            s = 0;
                            return;
                            //sin后没有数值，直接是 '+''(' 等非法字符
                        }
                        else if (in[x] == '.')
                        {
                            d++;
                            if (x == input.size() - 1)
                            {
                                ui->lineEdit_3->setText("输入的算式不符合规范 20");
                                s = 0;
                                return;
                                //小数点不能为最后一位
                            }
                            else if (d == 1)
                            {
                                continue;
                            }
                            else
                            {
                                ui->lineEdit_3->setText("输入的算式不符合规范 21");
                                s = 0;
                                return; //不能含有多个小数点
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        in[0] = '\0';

        // 检查sin的合法性



        for (int i = 0; i < input.size() - 2 && input.size() >3; i++)
        {
            if (input.mid(i, 3) == "cos" && input.size() > 3)
            {
                d = 0;

                if (i == input.size() - 3)
                {
                     ui->lineEdit_3->setText("输入的算式不符合规范 22");
                    s = 0;
                    return;	//cos不能作为字符串的结尾
                }

                for (int x = i + 3; x < input.size(); x++)
                {
                    if ((int)in[x] <= 57 && (int)in[x] >= 48) //数字0-9
                    {
                        continue;
                    }
                    else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z'))
                    {
                         ui->lineEdit_3->setText("输入的算式不符合规范 23");
                        s = 0;
                        return;
                    }
                    else
                    {
                        if (x == i + 3)
                        {
                             ui->lineEdit_3->setText("输入的算式不符合规范 24");
                            s = 0;
                            return;
                            //cos后没有数值，直接是 '+''(' 等非法字符
                        }
                        else if (in[x] == '.')
                        {
                            d++;
                            if (x == input.size() - 1)
                            {
                                 ui->lineEdit_3->setText("输入的算式不符合规范 25");
                                s = 0;
                                return;	//小数点不能为最后一位
                            }
                            else if (d == 1)
                            {
                                continue;
                            }
                            else
                            {
                                 ui->lineEdit_3->setText("输入的算式不符合规范 26");
                                s = 0;
                                return; //不能含有多个小数点
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        in[0] = '\0';

        // 检查cos的合法性




        for (int i = 0; i < input.size() - 2 && input.size() >3; i++)
        {
            if (input.mid(i, 3) == "tan" && input.size() > 3)
            {
                d = 0;

                if (i == input.size() - 3)
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 27");;
                    s = 0;
                    return;

                   // tan不能作为字符串的结尾
                }

                for (int x = i + 3; x < input.size(); x++)
                {
                    if ((int)in[x] <= 57 && (int)in[x] >= 48) //数字0-9
                    {
                        continue;
                    }
                    else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z'))
                    {
                        ui->lineEdit_3->setText("输入的算式不符合规范 28");
                        s = 0;
                        return;
                    }
                    else
                    {
                        if (x == i + 3)
                        {
                            ui->lineEdit_3->setText("输入的算式不符合规范 29");;
                            s = 0;
                            return;
                            //tan后没有数值，直接是'+''('等非法字符
                        }
                        else if (in[x] == '.')
                        {
                            d++;
                            if (x == input.size() - 1)
                            {
                                ui->lineEdit_3->setText("输入的算式不符合规范 30");
                                s = 0;
                                return;	//小数点不能为最后一位
                            }
                            else if (d == 1)
                            {
                                continue;
                            }
                            else
                            {
                                ui->lineEdit_3->setText("输入的算式不符合规范 31");
                                s = 0;
                                return; //不能含有多个小数点
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        in[0] = '\0';

        // 检查tan的合法性
    }
    else return;

}

void MainWindow::calcSC()
{
    if (s)
    {
        QString SIN = "sin";
        QString COS = "cos";
        QString TAN = "tan";

        int pos;
        int q = 0;
        double v = 0, resultSC;
        QString SC;
        char Input[100];

        QByteArray ba=input.toLocal8Bit();
        memcpy(in,ba.data(),ba.size()+1);


        pos = input.indexOf(SIN);	//计算sin

        int p = pos + 3;

        while (pos != -1)
        {
            for (int x = pos + 3; x < input.size(); x++)
            {
                if ((in[x] <= '9' && in[x] >= '0') || in[x] == '.') //数字0-9或小数点
                {
                    if (x == input.size() - 1)
                    {
                        q = x - p + 1;
                        break;
                    }
                    else
                        continue;
                }
                else
                {
                    q = x - p;
                    break;
                }
            }
            v = 0;
            Input[0] = '\0';

            SC = input.mid(p, q);
            //convertFromString(v, SC);
            v=SC.toDouble();

            resultSC = sin(v);

            sprintf(Input, "%.6lf", resultSC);

            input.replace(pos, q + 3, Input);

            p = 0; q = 0; v = 0;
            in[0] = '\0';

            //strcpy(in, INPUT.c_str());
            QByteArray ba2=input.toLocal8Bit();
            memcpy(in,ba2.data(),ba2.size()+1);

            pos = input.indexOf(SIN);
            p = pos + 3;
        }


        in[0] = '\0';
        //strcpy(in, INPUT.c_str());
        QByteArray ba3=input.toLocal8Bit();
        memcpy(in,ba3.data(),ba3.size()+1);

        pos = input.indexOf(COS);	//计算cos
        p = pos + 3;

        while (pos != -1)
        {
            for (int x = pos + 3; x < input.size(); x++)
            {
                if ((in[x] <= '9' && in[x] >= '0') || in[x] == '.') //数字0-9或小数点
                {
                    if (x == input.size() - 1)
                    {
                        q = x - p + 1;
                        break;
                    }
                    else
                        continue;
                }
                else
                {
                    q = x - p;
                    break;
                }
            }
            v = 0;
            Input[0] = '\0';

            //SC = INPUT.substr(p, q);
            SC=input.mid(p,q);

            //convertFromString(v, SC);
            v=SC.toDouble();

            resultSC = cos(v);
            sprintf(Input, "%.6lf", resultSC);

            input.replace(pos, q + 3, Input);

            p = 0; q = 0; v = 0;
            in[0] = '\0';

            QByteArray ba4=input.toLocal8Bit();
            memcpy(in,ba4.data(),ba4.size()+1);

            pos = input.indexOf(COS);
            p = pos + 3;
        }


        in[0] = '\0';
        //strcpy(in, INPUT.c_str());
        QByteArray ba5=input.toLocal8Bit();
        memcpy(in,ba5.data(),ba5.size()+1);

        pos = input.indexOf(TAN);	//计算tan
        p = pos + 3;

        while (pos != -1)
        {
            for (int x = pos + 3; x < input.size(); x++)
            {
                if (((int)in[x] <= 57 && (int)in[x] >= 48) || in[x] == '.') //数字0-9或小数点
                {
                    if (x == input.size() - 1)
                    {
                        q = x - p + 1;
                        break;
                    }
                    else
                        continue;
                }
                else
                {
                    q = x - p;
                    break;
                }
            }
            v = 0;
            Input[0] = '\0';

            //SC = INPUT.substr(p, q);
            SC=input.mid(p,q);

            //convertFromString(v, SC);
            v=SC.toDouble();

            if (cos(v) == 0)
            {
                ui->lineEdit_3->setText("输入的算式不符合规范 32");
                s = 0;
                return;
            }
            else
                resultSC = tan(v);

            sprintf(Input, "%.6lf", resultSC);
            input.replace(pos, q + 3, input);

            p = 0; q = 0; v = 0;
            in[0] = '\0';
            //strcpy(in, INPUT.c_str());
            QByteArray ba6=input.toLocal8Bit();
            memcpy(in,ba6.data(),ba6.size()+1);

            pos = input.indexOf(TAN);
            p = pos + 3;
        }
    }
}

void MainWindow::changenega()
{
    if (s)
    {
        //int p1, p2, p;
        //int q1, q2;
        //double v1 = 0, v2 = 0, result;
        //char Input[100];

        QString L, L1 = "(0", L2 = ")";

        in[0] = '\0';

        //strcpy(in, INPUT.c_str());
        QByteArray ba6=input.toLocal8Bit();
        memcpy(in,ba6.data(),ba6.size()+1);

        if (in[0] == '-' && input.size() > 1)
        {
            for (int i = 1; i < input.size(); i++)
            {

                if (((in[i] >= '0' && in[i] <= '9') || in[i] == '.') && i < input.size() - 1)
                {
                    continue;
                }
                else if (((in[i] >= '0' && in[i] <= '9') || in[i] == '.') && i == input.size() - 1)
                {
                    L = input.mid(0, i + 1);

                    L1.append(L);
                    L1.append(L2);

                    input.replace(0, i + 1, L1);
                    in[0] = '\0';

                    //strcpy(in, INPUT.c_str());
                    QByteArray ba7=input.toLocal8Bit();
                    memcpy(in,ba7.data(),ba7.size()+1);

                    L1 = "(0";
                    break;
                }
                else
                {
                    L = input.mid(0, i);
                    L1.append(L);
                    L1.append(L2);
                    input.replace(0, i, L1);
                    in[0] = '\0';
                    //strcpy(in, INPUT.c_str());
                    QByteArray ba8=input.toLocal8Bit();
                    memcpy(in,ba8.data(),ba8.size()+1);

                    L1 = "(0";
                    break;
                }
            }
        }

        for (int i = 1; i < input.size(); i++)
        {
            if (in[i] == '-' && (in[i - 1] > '9' || in[i - 1] < '0') && in[i - 1] != ')' && i!=input.size()-1)
            {
                for (int x = i + 1; x < input.size(); x++)
                {
                    if (((in[x] >= '0' && in[x] <= '9') || in[x] == '.') && x < input.size() - 1)
                    {
                        continue;
                    }
                    else if (((in[x] >= '0' && in[x] <= '9') || in[x] == '.') && x == input.size() - 1)
                    {
                        L = input.mid(i, x - i + 1);

                        L1.append(L);
                        L1.append(L2);

                        input.replace(i, x - i + 1, L1);
                        in[0] = '\0';

                        //strcpy(in, INPUT.c_str());
                        QByteArray ba9=input.toLocal8Bit();
                        memcpy(in,ba9.data(),ba9.size()+1);

                        L1 = "(0";
                        break;
                    }
                    else
                    {
                        L = input.mid(i, x-i);
                        L1.append(L);
                        L1.append(L2);

                        input.replace(i, x-i, L1);
                        in[0] = '\0';
                        //strcpy(in, INPUT.c_str());
                        QByteArray ba5=input.toLocal8Bit();
                        memcpy(in,ba5.data(),ba5.size()+1);

                        L1 = "(0";
                        break;
                    }
                }
            }
        }
    }
}

void MainWindow::checkstr()
{
    if (s)
    {

        in[0] = '\0';

        //strcpy(in, INPUT.c_str());
        QByteArray ba=input.toLocal8Bit();
        memcpy(in,ba.data(),ba.size()+1);

        int front = 0, back = 0;	//	前后括号个数

        for (int i = 0; i < input.size(); i++)
        {
            if ((int)in[i] <= 57 && (int)in[i] >= 48) //数字0～9
            {
                continue;
            }
            else if (in[i] == '+')
            {
                if (i == 0 || i == input.size() - 1)
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 42");
                    s = 0;
                    return;
                    // '+'不可以作为第一个字符或最后一个字符
                }
                else if ((in[i + 1] > '9' || in[i + 1]< '0') && in[i + 1]!= '(')
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 43");
                    s = 0;
                    return;
                    //'+'号后面不可以有除数字和'('以外的其他字符
                }
                else
                    continue;
            }
            else if (in[i] == '-')
            {
                if (i == 0 || i == input.size() - 1)
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 44");
                    s = 0;
                    return;
                    // '-'不可以作为第一个或最后一个字符
                }
                else if ((in[i+1]>'9' || in[i + 1]< '0') && in[i+1]!='(')
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 45");
                    s = 0;
                    return;
                    //'-'号后面不可以有除数字和'('以外的其他字符
                }
                else
                    continue;
            }
            else if (in[i] == '*')
            {
                if (i == 0 || i == input.size() - 1)
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 46");
                    s = 0;
                    return;
                    // '*'不可以作为第一个字符或最后一个字符
                }
                else if ((in[i + 1] > '9' || in[i + 1] < '0') && in[i + 1] != '(')
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 47");
                    s = 0;
                    return;
                    //'*'号后面不可以有除数字以外和'('以外的其他字符
                }
                else
                    continue;
            }
            else if (in[i] == '/')
            {
                if (i == 0 || i == input.size() - 1)
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 48");
                    s = 0;
                    return;
                    // '/'不可以作为第一个字符或最后一个字符
                }
                else if ((in[i + 1] > '9' || in[i + 1] < '0') && in[i + 1] != '(')
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 49");
                    s = 0;
                    return;
                    //'/'号后面不可以有除数字以外和'('以外的其他字符
                }
                else if ((int)in[i + 1] - (int)in[i] == 1)
                {
                    int w = 1;
                    for (int x = i + 1; x < input.size(); x++)
                    {
                        if (in[x] == '0' || in[x] == '.')
                        {
                            continue;
                        }
                        else if (in[x] <= '9' && in[x] >= '1')
                        {
                            w = 0;
                            continue;
                        }
                        else
                        {
                            break;
                        }

                    }

                    if (w) {
                        ui->lineEdit_3->setText("输入的算式不符合规范 50");
                        s = 0;
                        return;
                        // '/'号后面的数值不可以是'0'
                    }


                }
                else
                    continue;
            }
            else if (in[i] == '(')
            {
                front++;

                if (i == 0)
                {
                    if (in[i+1]>'9' || in[i + 1]<'0')
                    {
                        ui->lineEdit_3->setText("输入的算式不符合规范 51");
                        s = 0;
                        return;
                        //'('号后面不可以有除数字以外的其他字符
                    }
                    else
                        continue;
                }
                else if (i == input.size() - 1)
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 52");
                    s = 0;
                    return;
                    //'('不可以是最后一个字符
                }
                else
                {
                    if (in[i - 1] > '0' && in[i - 1] < '9')
                    {
                        ui->lineEdit_3->setText("输入的算式不符合规范 53");
                        s = 0;
                        return;
                        //'('号前面不可以有数字
                    }
                    else if ((in[i + 1] > '9' || in[i + 1] < '0') && in[i+1] != '(')
                    {
                        ui->lineEdit_3->setText("输入的算式不符合规范 54");
                        s = 0;
                        return;
                        //'('号后面不可以有除数字以外的其他字符
                    }
                    else
                        continue;
                }

            }
            else if (in[i] == ')')
            {
                back++;

                if (i == 0)
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 55");
                    s = 0;
                    return;
                    // ')'号不可以作为第一个字符
                }
                else if (i == input.size() - 1)
                {
                    if (in[i - 1]<'0' || in[i - 1]>'9')
                    {
                        ui->lineEdit_3->setText("输入的算式不符合规范 56");
                        s = 0;
                        return;
                        // ')'号前面不可以有除数字以外的其他字符
                    }
                    else
                        continue;

                }
                else if (in[i - 1]<'0' || in[i - 1]>'9' || (in[i + 1] >= '0' && in[i + 1] <= '9'))
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 57");
                    s = 0;
                    return;
                    // ')'号前面不可以有数字以外的其他字符,后面不可以有数字
                }
                else if (front < back)
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 58");
                    s = 0;
                    return;	// ')'号的个数不能比现有的'('个数要多
                }
                else
                    continue;

            }
            else if (in[i] == '.')
            {
                if (i == 0 || i == input.size() - 1)
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 59");
                    s = 0;
                    return;
                    // 小数点不可以作为第一个字符或最后一个字符
                }
                else if (in[i + 1]<'0' || in[i + 1]>'9')
                {
                    ui->lineEdit_3->setText("输入的算式不符合规范 60");
                    s = 0;
                    return;	//小数点后面不可以有数字以外的其他字符
                }
                else
                {
                    for (int x = i + 1; x < input.size(); x++)
                    {
                        if ((in[x]<'0' || in[x]>'9') && in[x] != '.')
                        {
                            break;
                        }
                        else if (in[x] == '.')
                        {
                            ui->lineEdit_3->setText("输入的算式不符合规范 61");
                            s = 0;
                            return;
                            //一串数字中不可以有多个小数点
                        }
                    }
                    continue;
                }


            }
            else
            {
                ui->lineEdit_3->setText("输入的算式不符合规范 62");
                s = 0;
                return;	//含有四则运算符和数字以外的非法字符
            }
        }
        if (front != back)
        {
            ui->lineEdit_3->setText("输入的算式不符合规范 63");
            s = 0;
            return;	//前后括号个数不等
        }
    }
    else  return;
}

void MainWindow::m_init()
{
    IN[0] = '\0';
    out.clear();
}

void MainWindow::setIN(QString a)
{
    //strcpy(IN, a.c_str());

    QByteArray ba=a.toLocal8Bit();
    memcpy(IN,ba.data(),ba.size()+1);
}

QString MainWindow::getINPUT()
{
    if (s)
        {
            return input;
        }
        else return "0";
}

void MainWindow::getSuffix()
{
    for (int i = 0; IN[i] != '\0'; i++)
    {
        if ((IN[i] >= '0' && IN[i] <= '9') || IN[i] == '.')//1,数字直接输出
        {
            string str;
            for (; (IN[i] >= '0' && IN[i] <= '9') || IN[i] == '.'; i++)
            {
                //将一个数字存储到字符串中
                char s = IN[i];
                str.push_back(s);
            }
            //将字符串输出
            out.push_back(str);
            i--;
        }
        else if (s1.empty())//2,遇见非数字时, 如果堆栈为空，则直接把该字符放入堆栈
        {
            s1.push(IN[i]);
        }
        else if (IN[i] == '+' || IN[i] == '-')
            //2.1,如果是+或- 那么遍历堆栈栈顶元素 一直输出优先级>=加减的 即输出栈顶的+-*/,
            //当遇到其他字符时（如左括号）或堆栈空时break
        {
            while (!s1.empty()) {
                if (s1.top() == '+' || s1.top() == '-' || s1.top() == '*' || s1.top() == '/')
                {
                    //把字符转换为字符串输出
                    char x;
                    x = s1.top();
                    s1.pop();
                    string str;
                    str.push_back(x);
                    out.push_back(str);
                }
                else break;
            }
            s1.push(IN[i]);
        }
        else if (IN[i] == '*' || IN[i] == '/')
            //2.2,如果是*或/ 那么遍历堆栈栈顶元素 一直输出优先级>=乘除的 即输出栈顶的*/,
            //当遇到其他字符时（如左括号，减号，加号）或堆栈空时break
        {
            while (!s1.empty())
            {
                if (s1.top() == '*' || s1.top() == '/')
                {
                    //把字符转换为字符串输出
                    char x;
                    x = s1.top();
                    s1.pop();
                    string str;
                    str.push_back(x);
                    out.push_back(str);
                }
                else break;
            }
            s1.push(IN[i]);
        }
        else if (IN[i] == ')')
            //2.3,如果该字符是右括号时，一直输出栈顶元素，直到遇见左括号为止break:
        {
            while (!s1.empty()) {
                if (s1.top() == '(')
                {
                    s1.pop();
                    break;
                }
                //把字符转换为字符串输出
                char x;
                x = s1.top();
                s1.pop();
                string str;
                str.push_back(x);
                out.push_back(str);
            }
        }
        else if (IN[i] == '(')
            //2.4,如果该字符是左括号时，直接放入堆栈
        {
            s1.push(IN[i]);
        }
    }
    //字符串循环结束后 再输出堆栈中剩余的数据
    while (!s1.empty())
    {
        //把字符转换为字符串输出
        char x;
        x = s1.top();
        s1.pop();
        string str;
        str.push_back(x);
        out.push_back(str);
    }
}

double MainWindow::Calc_Suffix()
{
    MainWindow::getSuffix();
    for (int i = 0; i < out.size(); i++)
    {
        stringstream s3(out[i]);
        float t;
        //如果是数字，直接入栈
        if (s3 >> t)
        {
            s2.push(t);
        }
        else if (out[i] == "+" || out[i] == "-" || out[i] == "*" || out[i] == "/")//如果是运算符，弹栈两次，并进行运算，运算后，结果入栈
        {
            float x = s2.top();
            s2.pop();
            float y = s2.top();
            s2.pop();
            if (out[i] == "+")
            {
                s2.push(y + x);
            }
            else if (out[i] == "-")
            {
                s2.push(y - x);
            }
            else if (out[i] == "*")
            {
                s2.push(y * x);
            }
            else if (out[i] == "/")
            {
                if (x == 0) {
                    ui->lineEdit_3->setText("输入的算式不符合规范,结果已置零");
                    s=0;
                    return 0;
                }
                else
                    s2.push(y / x);
            }
        }
    }
    double z = s2.top();
    s2.pop();
    result = z;
    return result;
}

void MainWindow::checR()
{
    if(ui->comboBox->currentIndex()==0)  R=10;
    if(ui->comboBox->currentIndex()==1)  R=2;
    if(ui->comboBox->currentIndex()==2)  R=8;
    if(ui->comboBox->currentIndex()==3)  R=16;
}

QString MainWindow::RADIX(double a)
{

    int G = 0;
    int f, g;
    double g2;
    char N11[6] = { 0,0,0,0,0,0 };
    QString P11 = ".";
    QString res;

    if (a < 0)
    {
        G = 1; a = -a;
        res.append('-');
    }

    int P1 = a;	//整数部分
    double N1 = a - P1;//小数部分

    //二进制
    if(R==2)
    {
        res.append('B');

        for (int i = 0;; i++)
        {
            f = P1 / 2;
            g = P1 % 2;
            P1 = f;

            if (g == 0)
            {
                P11 = "0" + P11;
            }
            else if (g == 1)
            {
                P11 = "1" + P11;
            }

            if (f < 1)
            {
                res.append(P11);
                break;
            }
        }

        for (int i = 0; i < 6; i++)
        {
            g2 = pow(0.5, i + 1);
            f = N1 / g2;
            N1 = N1 - g2 * f;

            if (f == 0)
            {
                N11[i] = '0';
            }
            else if (f == 1)
            {
                N11[i] = '1';
            }
        }
        for (int i = 0; i < 6; i++)
        {
            //cout << N11[i];
            res.append(N11[i]);
        }
        return res;
    }
    else if(R==8)//八进制
    {
        //cout << "O";
        res.append('O');

            for (int i = 0;; i++)
            {
                f = P1 / 8;
                g = P1 % 8;
                P1 = f;

                if (g == 0)
                {
                    P11 = "0" + P11;
                }
                else if (g == 1)
                {
                    P11 = "1" + P11;
                }
                else if (g == 2)
                {
                    P11 = "2" + P11;
                }
                else if (g == 3)
                {
                    P11 = "3" + P11;
                }
                else if (g == 4)
                {
                    P11 = "4" + P11;
                }
                else if (g == 5)
                {
                    P11 = "5" + P11;
                }
                else if (g == 6)
                {
                    P11 = "6" + P11;
                }
                else if (g == 7)
                {
                    P11 = "7" + P11;
                }

                if (f < 1)
                {
                    //cout << P11;
                    res.append(P11);
                    break;
                }
            }

            for (int i = 0; i < 6; i++)
            {
                g2 = pow(0.125, i + 1);
                f = N1 / g2;
                N1 = N1 - g2 * f;

                if (f == 0)
                {
                    N11[i] = '0';
                }
                else if (f == 1)
                {
                    N11[i] = '1';
                }
                else if (f == 2)
                {
                    N11[i] = '2';
                }
                else if (f == 3)
                {
                    N11[i] = '3';
                }
                else if (f == 4)
                {
                    N11[i] = '4';
                }
                else if (f == 5)
                {
                    N11[i] = '5';
                }
                else if (f == 6)
                {
                    N11[i] = '6';
                }
                else if (f == 7)
                {
                    N11[i] = '7';
                }
            }
            for (int i = 0; i < 6; i++)
            {
                //cout << N11[i];
                 res.append(N11[i]);
            }
            return res;
    }
    else if(R==16)
    {
        //cout << "H";
        res.append('H');
        for (int i = 0;; i++)
        {
            f = P1 / 16;
            g = P1 % 16;
            P1 = f;

            if (g == 0)
            {
                P11 = "0" + P11;
            }
            else if (g == 1)
            {
                P11 = "1" + P11;
            }
            else if (g == 2)
            {
                P11 = "2" + P11;
            }
            else if (g == 3)
            {
                P11 = "3" + P11;
            }
            else if (g == 4)
            {
                P11 = "4" + P11;
            }
            else if (g == 5)
            {
                P11 = "5" + P11;
            }
            else if (g == 6)
            {
                P11 = "6" + P11;
            }
            else if (g == 7)
            {
                P11 = "7" + P11;
            }
            else if (g == 8)
            {
                P11 = "8" + P11;
            }
            else if (g == 9)
            {
                P11 = "9" + P11;
            }
            else if (g == 10)
            {
                P11 = "a" + P11;
            }
            else if (g == 11)
            {
                P11 = "b" + P11;
            }
            else if (g == 12)
            {
                P11 = "c" + P11;
            }
            else if (g == 13)
            {
                P11 = "d" + P11;
            }
            else if (g == 14)
            {
                P11 = "e" + P11;
            }
            else if (g == 15)
            {
                P11 = "f" + P11;
            }

            if (f < 1)
            {
                //cout << P11;
                res.append(P11);
                break;
            }
        }

        for (int i = 0; i < 6; i++)
        {
            g2 = pow(0.0625, i + 1);
            f = N1 / g2;
            N1 = N1 - g2 * f;

            if (f == 0)
            {
                N11[i] = '0';
            }
            else if (f == 1)
            {
                N11[i] = '1';
            }
            else if (f == 2)
            {
                N11[i] = '2';
            }
            else if (f == 3)
            {
                N11[i] = '3';
            }
            else if (f == 4)
            {
                N11[i] = '4';
            }
            else if (f == 5)
            {
                N11[i] = '5';
            }
            else if (f == 6)
            {
                N11[i] = '6';
            }
            else if (f == 7)
            {
                N11[i] = '7';
            }
            else if (f == 8)
            {
                N11[i] = '8';
            }
            else if (f == 9)
            {
                N11[i] = '9';
            }
            else if (f == 10)
            {
                N11[i] = 'a';
            }
            else if (f == 11)
            {
                N11[i] = 'b';
            }
            else if (f == 12)
            {
                N11[i] = 'c';
            }
            else if (f == 13)
            {
                N11[i] = 'd';
            }
            else if (f == 14)
            {
                N11[i] = 'e';
            }
            else if (f == 15)
            {
                N11[i] = 'f';
            }
        }
        for (int i = 0; i < 6; i++)
        {
            //cout << N11[i];
            res.append(N11[i]);
        }
        return res;
    }
    else//十进制
    {
        res = QString::number(a, 'f', 3);
        return res;
    }
}

void MainWindow::Calcfun1()
{
     result=0;
     a=ui->lineEdit->text().toDouble();
     b=ui->lineEdit_2->text().toDouble();
     if(a==0)
     {
         ui->lineEdit_4->setText("请重新输入");
         return;
     }
     else
     {
         result=-b/a;
         QString res = QString::number(result,'f',3);
         ui->lineEdit_4->setText(res);
         return;
     }

}

void MainWindow::Calcfun2()
{
    a=0;b=0;c=0;
    result=0;
    result2=0;
    a=ui->lineEdit->text().toDouble();
    b=ui->lineEdit_2->text().toDouble();
    c=ui->lineEdit_3->text().toDouble();
    double T1, T2, T3;
    if (a == 0 && b == 0)
    {
        //cout << "方程式错误，无法求解。" << endl;
        ui->lineEdit_4->setText("方程式错误，无法求解。");
        return;
    }
    else if (a == 0 && b != 0)
    {
        result = -c / b;
        //cout << "解得x=" << result << endl;
        //	只有a为0时，为一元一次方程
        QString res = QString::number(result,'f',3);
        ui->lineEdit_4->setText(res);
    }
    else {
        T1 = b * b - 4 * a * c;

        if (T1 == 0) {
            result = -b / 2 * a;
            //cout << "解得x=" << result << endl;
            QString res = QString::number(result,'f',3);
            ui->lineEdit_4->setText(res);
        }
        else if (T1 < 0) {
            //cout << "方程式错误，无法求解。" << endl;
            ui->lineEdit_4->setText("方程式错误，无法求解。");
            return;
        }
        else
        {
            T2 = -b + pow(T1, 0.5);
            T3 = -b - pow(T1, 0.5);
            result = T2 / 2 * a;
            result2 = T3 / 2 * a;

            QString res = QString::number(result,'f',3);
            QString res2 = QString::number(result2,'f',3);
            res.append(" , ");
            res.append(res2);

            ui->lineEdit_4->setText(res);

            //cout << "解得x=" << result << " 或x=" << result2 << endl;
        }
    }
}

void MainWindow::Calcfun3()
{
    result = 0;
    a = 0; b = 0; c = 0;
    a=ui->lineEdit->text().toDouble();
    b=ui->lineEdit_2->text().toDouble();


    if (a == 0 || b == 0 || a <= 0 || b <= 0 || a == 1)
    {
        //cout << "方程式错误，无法求解。" << endl;
        ui->lineEdit_4->setText("方程式错误，无法求解。");
        return;
    }
    else
    {
        result = log(b) / log(a);
        //cout << "解得x=" << result << endl;
        QString res = QString::number(result,'f',3);
        ui->lineEdit_4->setText(res);
        return;
    }
}

void MainWindow::Calcfun4()
{
    result = 0;
    a = 0; b = 0; c = 0;

    a=ui->lineEdit->text().toDouble();
    b=ui->lineEdit_2->text().toDouble();

    if (a == 0 || b < 0)
    {
        ui->lineEdit_4->setText("方程式错误，无法求解。");
        return;
    }
    else if (b == 0)
    {
        //cout << "解得x=0" << endl;
        ui->lineEdit_4->setText(" 0 ");
    }
    else
    {
        result = pow(b, 1 / a);

        if (a == (double)((int)a) && (int)a % 2 == 0)
        {
            //cout << "解得x= " << result << " 或 " << -result << endl;
            result2 = 0 - result;
            QString res = QString::number(result,'f',3);
            QString res2 = QString::number(result2,'f',3);
            res.append(" , ");
            res.append(res2);

            ui->lineEdit_4->setText(res);
        }
        else
        {
            //cout << "解得x=" << result << endl;
             QString res = QString::number(result,'f',3);
             ui->lineEdit_4->setText(res);
        }

    }
}

void MainWindow::Calcfun5()
{

    result=0;
    a = 0; b = 0; c = 0;

    a=ui->lineEdit->text().toDouble();
    b=ui->lineEdit_2->text().toDouble();

    if (b == 0 || a <= 0)
    {
        ui->lineEdit_4->setText("方程式错误，无法求解。");
        return;
    }
    else if (a == 0)
    {
        ui->lineEdit_4->setText(" 0 ");
        return;

    }
    else
    {
        result = pow(a, 1 / b);
        if (b == (double)((int)b) && (int)b % 2 == 0)
        {
            result2 = 0 - result;
            QString res = QString::number(result,'f',3);
            QString res2 = QString::number(result2,'f',3);
            res.append(" , ");
            res.append(res2);

            ui->lineEdit_4->setText(res);
        }
        else
        {
            QString res = QString::number(result,'f',3);
            ui->lineEdit_4->setText(res);
        }
    }
}

void MainWindow::Calcfun6()
{
    result = 0;
    a = 0; b = 0; c = 0;

    a=ui->lineEdit->text().toDouble();
    b=ui->lineEdit_2->text().toDouble();

    if (a < 0 || (a == 0 && b == 0))
    {
        ui->lineEdit_4->setText("方程式错误，无法求解。");
        return;
    }
    else if (a == 0 && b != 0)
    {
        ui->lineEdit_4->setText(" 0 ");
        return;

    }
    else if (b == 0 && a != 0)
    {
        ui->lineEdit_4->setText(" 1 ");
        return;
    }
    else
    {
        result = pow(a, b);
        QString res = QString::number(result,'f',3);
        ui->lineEdit_4->setText(res);
    }
}

void MainWindow::Calcfun7()
{

    result = 0;
    a = 0; b = 0; c = 0;

    a=ui->lineEdit->text().toDouble();
    b=ui->lineEdit_2->text().toDouble();

    if (a == 0 || b == 0)
    {
        ui->lineEdit_4->setText("方程式错误，无法求解。");
        return;
    }
    result = -a / b;
    QString res = QString::number(result,'f',3);
    ui->lineEdit_4->setText(res);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    image1.load(":/res/background");
    painter.drawPixmap(0 , 0 , 500 , 500 , image1);
}

//初始化计算器界面
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //设置大小和位置
    ui->setupUi(this);
    //this->resize(WIDTH,HEIGHT);
    this->setFixedSize(WIDTH,HEIGHT);
    this->move(POS_X,POS_Y);



    ui->lineEdit->show();
    ui->label_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();

    ui->comboBox->show();
    ui->comboBox_2->hide();

    ui->label_2->setText("计算状态");
    ui->label_3->setText("请输入计算式");
    ui->label_4->setText("计算结果为");
    ui->label_5->hide();
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText(" ");

    ui->pushButton->show();
    ui->compare->hide();
    ui->solve->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    MainWindow::setA();
    MainWindow::CIN();
    MainWindow::checkroom();
    MainWindow::checkstr0();

    MainWindow::checkhex();
    MainWindow::calchex();

    MainWindow::checkoct();
    MainWindow::calcoct();

    MainWindow::checkbit();
    MainWindow::calcbit();

    MainWindow::checkSC();
    MainWindow::calcSC();

    MainWindow::calclog();

    MainWindow::changenega();
    MainWindow::checkstr();
    MainWindow::m_init();
    MainWindow::setIN(MainWindow::getINPUT());
    MainWindow::getSuffix();
    MainWindow::checR();

    //结果输出
    double result=MainWindow::Calc_Suffix();
    QString str = QString::number(result, 'f', 3);
    ui->lineEdit_2->setText(str);

    //转换不同进制输出
    QString str2 = MainWindow::RADIX(result);
    ui->lineEdit_4->setText(str2);


    //ui->doubleSpinBox->setValue(result);

    //QString str2 = QString::number((int)result,8);
    //ui->lineEdit_4->setText(str2);

    //MainWindow::COUT(); 方便debug
}



void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit_4->hide();
    ui->comboBox->hide();
    ui->pushButton->hide();
    ui->compare->show();
    ui->solve->hide();
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText(" ");

    ui->label_2->setText("较大的数是");
    ui->label_3->setText("请输入比较的数");
    ui->label_4->setText("请输入比较的数");
    ui->label_5->hide();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->show();
    ui->label_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();

    ui->comboBox->show();
    ui->comboBox_2->hide();

    ui->label_2->setText("计算状态");
    ui->label_3->setText("请输入计算式");
    ui->label_4->setText("计算结果为");
    ui->label_5->hide();
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText(" ");

    ui->pushButton->show();
    ui->compare->hide();
    ui->solve->hide();
}

void MainWindow::on_compare_clicked()
{
    double A2, B2;
    bool S1, S2;

    //cout << "请输入要比较的数A：" << endl;
    MainWindow::setA();
    MainWindow::CIN();//输入

    MainWindow::checkroom();// 判断大小，并将字符串转字符数组（在进行函数计算之前
    MainWindow::checkstr0();	//检查是否有非法字符（在计算函数和转换进制之前

    MainWindow::checkhex(); //判断是否有非法的进制运算
    MainWindow::calchex(); //将十六进制数字符串转为十进制数字符串

    MainWindow::checkoct(); //判断是否有非法的进制运算
    MainWindow::calcoct(); //将八进制数字符串转为十进制数字符串

    MainWindow::checkbit(); //判断是否有非法的进制运算
    MainWindow::calcbit(); //将二进制数字符串转为十进制数字符串

    //C.calclog();//对数函数

    //C.calcpow();//幂函数

    MainWindow::checkSC();//检查三角函数的合法性：其后必须有一个合法数
    MainWindow::calcSC();//计算三角函数，用计算后的数替代原算式中的三角函数

    MainWindow::changenega();	//将所有的负数-a改为(0-a) (在计算函数和转换进制之后

    MainWindow::checkstr(); // 检查是否有非法字符（在计算三角函数、幂函数、对数函数之后
                     //此处的非法字符指除四则运算、数字、括号以外的其他任何字符
                     //同时一并检查运算符号是否被适当地使用



    MainWindow::m_init();//初始化

    MainWindow::setIN(MainWindow::getINPUT());
    MainWindow::getSuffix();//获取后缀表达式

    MainWindow::getSuffix();//计算后缀表达式

    A2 = MainWindow::Calc_Suffix();
    S1 = MainWindow::checkS();
    //cout<<A2;

    //cout << "请输入要比较的数B：" << endl;

    MainWindow::setA();
    MainWindow::CIN2();//输入

    MainWindow::checkroom();// 判断大小，并将字符串转字符数组（在进行函数计算之前
    MainWindow::checkstr0();	//检查是否有非法字符（在计算函数和转换进制之前

    MainWindow::checkhex(); //判断是否有非法的进制运算
    MainWindow::calchex(); //将十六进制数字符串转为十进制数字符串

    MainWindow::checkoct(); //判断是否有非法的进制运算
    MainWindow::calcoct(); //将八进制数字符串转为十进制数字符串

    MainWindow::checkbit(); //判断是否有非法的进制运算
    MainWindow::calcbit(); //将二进制数字符串转为十进制数字符串

    //C.calclog();//对数函数

    //C.calcpow();//幂函数

    MainWindow::checkSC();//检查三角函数的合法性：其后必须有一个合法数
    MainWindow::calcSC();//计算三角函数，用计算后的数替代原算式中的三角函数

    MainWindow::changenega();	//将所有的负数-a改为(0-a) (在计算函数和转换进制之后

    MainWindow::checkstr(); // 检查是否有非法字符（在计算三角函数、幂函数、对数函数之后
                     //此处的非法字符指除四则运算、数字、括号以外的其他任何字符
                     //同时一并检查运算符号是否被适当地使用



    MainWindow::m_init();//初始化

    MainWindow::setIN(MainWindow::getINPUT());
    MainWindow::getSuffix();//获取后缀表达式

    MainWindow::getSuffix();//计算后缀表达式

    B2 = MainWindow::Calc_Suffix();
    S2 = MainWindow::checkS();
    //cout<<B2;



    if (S1 != 0 && S2 != 0)
    {

        if (A2 > B2)
        {
            ui->lineEdit_3->setText(ui->lineEdit->text());
        }
        else if (A2 < B2)
        {
            ui->lineEdit_3->setText(ui->lineEdit_2->text());
        }
        else if (A2 == B2)
        {
           ui->lineEdit_3->setText(ui->lineEdit->text());
        }
    }

}

void MainWindow::on_solve_clicked()
{
    int index = ui->comboBox_2->currentIndex();
    switch (index)
    {
        case 0:
        {
            MainWindow::Calcfun1();
            break;
        }
        case 1:
        {
            MainWindow::Calcfun2();
            break;
        }
        case 2:
        {
            MainWindow::Calcfun3();
            break;
        }
        case 3:
        {
            MainWindow::Calcfun4();
            break;
        }
        case 4:
        {
            MainWindow::Calcfun5();
            break;
        }
        case 5:
        {
            MainWindow::Calcfun6();
            break;
        }
        case 6:
        {
            MainWindow::Calcfun7();
            break;
        }
        default:
            break;
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->show();
    ui->label_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();

    ui->comboBox->hide();
    ui->comboBox_2->show();

    ui->label_2->setText("请输入c");
    ui->label_3->setText("请输入a");
    ui->label_4->setText("请输入b");
    ui->label_5->show();
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText(" ");

    ui->pushButton->hide();
    ui->compare->hide();
    ui->solve->show();

}

void MainWindow::on_action_triggered()
{
    hw.show();
}
