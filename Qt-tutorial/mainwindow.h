#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "gamewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setName(const QString &name);
    QString name() const;
    QPushButton *card_1,*card_2,*card_3,*card_4,*card_5,*card_6,*card_7,*card_8;

private slots:
    void PressButton1();
    void PressButton2();
    void PressButton3();
    void PressButton4();
    void PressButton5();
    void PressButton6();
    void PressButton7();
    void PressButton8();
    void SelectedCard(int card);
    void OpenGameWindow();

private:
    Ui::MainWindow *ui;
    GameWindow *Game;

};

#endif // MAINWINDOW_H
