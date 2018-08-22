#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExp>
#include <QMessageBox>
#include "regexphighlighter.h"

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

    void on_RegLineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    RegExpHighlighter* highlighter;
    bool checkRegExp(const QRegExp& reg);
};

#endif // MAINWINDOW_H
