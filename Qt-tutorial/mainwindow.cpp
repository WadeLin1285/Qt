#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->card_1->setCheckable(true);
    ui->card_2->setCheckable(true);
    ui->card_3->setCheckable(true);
    ui->card_4->setCheckable(true);
    ui->card_5->setCheckable(true);
    ui->card_6->setCheckable(true);
    ui->card_7->setCheckable(true);
    ui->card_8->setCheckable(true);
    connect(ui->card_1,SIGNAL(pressed()) ,this,SLOT (PressButton1()));
    connect(ui->card_2,SIGNAL(pressed()) ,this,SLOT (PressButton2()));
    connect(ui->card_3,SIGNAL(pressed()) ,this,SLOT (PressButton3()));
    connect(ui->card_4,SIGNAL(pressed()) ,this,SLOT (PressButton4()));
    connect(ui->card_5,SIGNAL(pressed()) ,this,SLOT (PressButton5()));
    connect(ui->card_6,SIGNAL(pressed()) ,this,SLOT (PressButton6()));
    connect(ui->card_7,SIGNAL(pressed()) ,this,SLOT (PressButton7()));
    connect(ui->card_8,SIGNAL(pressed()) ,this,SLOT (PressButton8()));
    ui->card_display_1->setText("0");
    ui->card_display_2->setText("0");
    ui->card_display_3->setText("0");
    ui->card_display_4->setText("0");
    ui->card_display_1->setAlignment(Qt::AlignCenter);
    ui->card_display_2->setAlignment(Qt::AlignCenter);
    ui->card_display_3->setAlignment(Qt::AlignCenter);
    ui->card_display_4->setAlignment(Qt::AlignCenter);
    connect(ui->playButton,SIGNAL(pressed()) ,this,SLOT (OpenGameWindow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setName(const QString &name)
{
    ui->lineEdit->setText(name);
    ui->player->setText(name);
}

void MainWindow::PressButton1()
{
    if (ui->card_1->text() == "01") ui->card_1->setText("Seleted");
    else ui->card_1->setText("01");
    SelectedCard(1);
}
void MainWindow::PressButton2()
{
    if (ui->card_2->text() == "02") ui->card_2->setText("Seleted");
    else ui->card_2->setText("02");
    SelectedCard(2);
}
void MainWindow::PressButton3()
{
    if (ui->card_3->text() == "03") ui->card_3->setText("Seleted");
    else ui->card_3->setText("03");
    SelectedCard(3);
}
void MainWindow::PressButton4()
{
    if (ui->card_4->text() == "04") ui->card_4->setText("Seleted");
    else ui->card_4->setText("04");
    SelectedCard(4);
}
void MainWindow::PressButton5()
{
    if (ui->card_5->text() == "05") ui->card_5->setText("Seleted");
    else ui->card_5->setText("05");
    SelectedCard(5);
}
void MainWindow::PressButton6()
{
    if (ui->card_6->text() == "06") ui->card_6->setText("Seleted");
    else ui->card_6->setText("06");
    SelectedCard(6);
}
void MainWindow::PressButton7()
{
    if (ui->card_7->text() == "07") ui->card_7->setText("Seleted");
    else ui->card_7->setText("07");
    SelectedCard(7);
}
void MainWindow::PressButton8()
{
    if (ui->card_8->text() == "08") ui->card_8->setText("Seleted");
    else ui->card_8->setText("08");
    SelectedCard(8);
}
void MainWindow::SelectedCard(int card){
    static int SelectedC[4]={0,0,0,0};
    int position = 0;
    // find the input card exists or not
    if (SelectedC[0] == card) position = 1;
    if (SelectedC[1] == card) position = 2;
    if (SelectedC[2] == card) position = 3;
    if (SelectedC[3] == card) position = 4;
    // set the selected card
    if (position == 0){
        for (int i = 0; i<4 ; ++i)
            if (SelectedC[i] == 0){
                SelectedC[i] = card;
                break;
            }
    }
    else {
        if (position == 1){
            SelectedC[0] = SelectedC[1];
            SelectedC[1] = SelectedC[2];
            SelectedC[2] = SelectedC[3];
            SelectedC[3] = 0;
        }
        else if (position == 2){
            SelectedC[1] = SelectedC[2];
            SelectedC[2] = SelectedC[3];
            SelectedC[3] = 0;
        }
        else if (position == 3){
            SelectedC[2] = SelectedC[3];
            SelectedC[3] = 0;
        }
        else {
            SelectedC[3] = 0;
        }
    }
    // display the card
    ui->card_display_1->setText(QString("%1").arg(SelectedC[0]));
    ui->card_display_2->setText(QString("%1").arg(SelectedC[1]));
    ui->card_display_3->setText(QString("%1").arg(SelectedC[2]));
    ui->card_display_4->setText(QString("%1").arg(SelectedC[3]));
    ui->card_display_1->setAlignment(Qt::AlignCenter);
    ui->card_display_2->setAlignment(Qt::AlignCenter);
    ui->card_display_3->setAlignment(Qt::AlignCenter);
    ui->card_display_4->setAlignment(Qt::AlignCenter);
    // checked the number of selected card
    int n = 0,Check[8]={0,0,0,0,0,0,0,0};
    for (int i = 0; i < 4 ; ++i)
        if (SelectedC[i] != 0){
            n++;
            Check[SelectedC[i]-1] = 1;
        }
    if (n >= 4){
        if (Check[0] == 0) ui->card_1->setEnabled(false);
        if (Check[1] == 0) ui->card_2->setEnabled(false);
        if (Check[2] == 0) ui->card_3->setEnabled(false);
        if (Check[3] == 0) ui->card_4->setEnabled(false);
        if (Check[4] == 0) ui->card_5->setEnabled(false);
        if (Check[5] == 0) ui->card_6->setEnabled(false);
        if (Check[6] == 0) ui->card_7->setEnabled(false);
        if (Check[7] == 0) ui->card_8->setEnabled(false);
    }
    else {
        ui->card_1->setEnabled(true);
        ui->card_2->setEnabled(true);
        ui->card_3->setEnabled(true);
        ui->card_4->setEnabled(true);
        ui->card_5->setEnabled(true);
        ui->card_6->setEnabled(true);
        ui->card_7->setEnabled(true);
        ui->card_8->setEnabled(true);
    }
}

void MainWindow::OpenGameWindow(){
    Game = new GameWindow();
    Game->show();
}

QString MainWindow::name() const
{
    return ui->lineEdit->text();
}
