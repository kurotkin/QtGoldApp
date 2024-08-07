#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customdelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *connectAction = new QAction("Connect", ui->menubar);
    connect(connectAction, SIGNAL(triggered()), this, SLOT(dbAction()));
    ui->menubar->addAction(connectAction);
}

MainWindow::~MainWindow()
{
    db->closeDataBase();
    delete ui;
}

void MainWindow::dbAction(){
    db = new DataBase();
    db->openDataBase();
    QSqlTableModel* model = new QSqlTableModel(this);
    model->setTable("gold");
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegateForColumn(2, new CustomDelegate(this));
    ui->tableView->setColumnWidth(0, 150);
    model->select();
}
