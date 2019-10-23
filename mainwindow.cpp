#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtTest>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QColor color = QColor(Qt::black);
       QPalette p = this->palette();
       p.setColor(QPalette::Window,color);
       this->setPalette(p);

    pForm = new Form(this);
    pForm->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveEvent(QMoveEvent *event)
{
    pForm->move(mapToGlobal(QPoint(0,0)));
}

void MainWindow::hideEvent(QHideEvent *event)
{
    pForm->hide();
}

void MainWindow::showEvent(QShowEvent *event)
{
    pForm->hide();
    QMainWindow::showEvent(event);
    m_bIsFormShow = true;
    update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if(m_bIsFormShow){
        QTest::qSleep(220);
        pForm->show();
        m_bIsFormShow = false;
    }
}
