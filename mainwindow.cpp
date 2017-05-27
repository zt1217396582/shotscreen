#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->savePictureButton,SIGNAL(clicked(bool)),this,SLOT(savePictureSolt()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newScreenShotButton_clicked()
{
    if(ui->checkBox->isChecked())
    {
        //this->hide(); // this->show();
        this->timer = new QTimer;
        QObject::connect(this->timer,SIGNAL(timeout()),this,SLOT(shotScreenSlot()));
                this->timer->start(1000/5);
    }else
    {
        qApp->beep(); // 警告声
    }
}

void MainWindow::shotScreenSlot()
{
    //pixmap
    this->pixmap = QPixmap::grabWindow(QApplication::desktop()->winId()); //截取当前桌面图片
    ui->screenLabel->setPixmap(this->pixmap.scaled(ui->screenLabel->size()));//设置截图到屏幕标签
    QClipboard *clipboard = QApplication::clipboard();//初始化剪切板
    //QString originalText = clipboard->text();
    //qDebug()<<"current clipboard text is "<<originalText;
    clipboard->setPixmap(this->pixmap);//把截图暂存到剪切板
    //this->show();
    //this->timer->stop();
}

void MainWindow::savePictureSolt()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save File",QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));
    this->pixmap.save(fileName);
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu = new QMenu(this);//创建右键菜单
    QAction *action = new QAction(this);//action一旦建立，加上连接
    QAction *processAction = new QAction(this);//两个action
    QObject::connect(processAction,SIGNAL(triggered(bool)),this,SLOT(startNotepadSlot()));
    QObject::connect(action,SIGNAL(triggered(bool)),this,SLOT(savePictureSolt()));
    action->setText("Save As");
    processAction->setText("start notepad");
    menu->addAction(action);
    menu->addAction(processAction);
    menu->exec(QCursor::pos());
}

void MainWindow::startNotepadSlot()
{
    QProcess *process = new QProcess;
    process->start("notepad.exe");
}









