#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customdelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = new DataBase();
    db->openDataBase();

    model = new QSqlTableModel(this);
    model->setTable("gold");


    ui->tableView->setModel(model);

    model->select();

    ui->tableView->setItemDelegateForColumn(2, new CustomDelegate(this));
    ui->tableView->setColumnWidth(0, 150);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}
