#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExp>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_FindBtn_clicked();

    void on_ReplaceBtn_clicked();

private:
    Ui::MainWindow *ui;
    bool checkRegExp(const QRegExp& reg);
};

#endif // MAINWINDOW_H
