#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QDesktopServices>
#include <QStandardPaths>
#include <QClipboard>
#include <QDebug>
#include <QContextMenuEvent>
#include <QMenu>
#include <QAction>
#include <QCursor>
#include <QProcess>
// storageLocation

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void contextMenuEvent(QContextMenuEvent *event);
private slots:
    void on_newScreenShotButton_clicked();
    void shotScreenSlot();
    void savePictureSolt();
    void startNotepadSlot();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QPixmap pixmap;
};

#endif // MAINWINDOW_H
