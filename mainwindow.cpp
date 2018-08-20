#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkRegExp(const QRegExp& reg)
{
    if(!reg.isEmpty() && reg.isValid() && !reg.exactMatch("")){
        return true;
    }

    QMessageBox::information(this, "", trUtf8("Некорректное регулярное выражение!"));
    return false;
}

void MainWindow::on_FindBtn_clicked()
{
    QRegExp reg(ui->RegLineEdit->text());

    if(!checkRegExp(reg)){
        return;
    }

    reg.setMinimal(!ui->checkBox->isChecked());

    ui->MatchesListWidget->clear();

    QString testText = ui->SourceText->toPlainText();
    long int pos = reg.indexIn(testText, 0);

    QString fullMatch(trUtf8("Полное совпадение: \"%1\""));
    QString groupMatch(trUtf8("Группа №%1: \"%2\""));
    while(pos >= 0)
    {
        auto capCount = reg.captureCount();

        ui->MatchesListWidget->addItem(fullMatch.arg(reg.cap(0)));

        for(decltype(capCount) i = 1; i < capCount; ++i)
        {
            ui->MatchesListWidget->addItem((groupMatch.arg(QString::number(i))).arg(reg.cap(i)));
        }

        pos += reg.matchedLength();
        pos = reg.indexIn(testText, pos);
    }
}

void MainWindow::on_ReplaceBtn_clicked()
{
    QRegExp reg(ui->RegLineEdit->text());

    if(!checkRegExp(reg)){
        return;
    }

    reg.setMinimal(!ui->checkBox->isChecked());

    ui->ReplaceTextBrowser->clear();
    ui->ReplaceTextBrowser->setPlainText((ui->SourceText->toPlainText()).replace(reg, ui->ReplaceLineEdit->text()));
}
