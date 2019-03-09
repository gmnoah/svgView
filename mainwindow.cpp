#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle (tr("SVG Viewer"));
    svgWindow = new SvgWindow;
    setCentralWidget (svgWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString name = QFileDialog::getOpenFileName (this, "打开", "/", "svg file(*.svg)");
    svgWindow->setFile (name);
//        QPrinter printer;
//      printer.setPageSize(QPrinter::A4);
//      printer.setOutputFormat(QPrinter::PdfFormat);
//      QString filepath = QFileDialog::getSaveFileName(this, tr("保存为..."), tr("D://成绩.pdf"), tr("PDF格式(*.pdf)"));
//      printer.setOutputFileName(filepath);
//      QTextDocument textDocument;
//      textDocument.setHtml(MakeDataToHtml());
//      textDocument.print(&printer);
//      QMessageBox::about(this, tr("提示"), tr("保存成功"));
}
QString MainWindow::MakeDataToHtml()
{
    //表头
    //html = "<table width=100% border=1 cellspacing=0 text-align=center style=border-collapse:collapse>";
    //html += "<tr>";
    //html += "<th>编号</th>";
    //html += "<th>姓名</th>";
    //html += "<th>头部成绩</th>";
    //html += "<th>胸部成绩</th>";
    //html += "</tr>";
    ////数据
    //html += "<tr>";
    //html += "<td align=center>1</td>";
    //html += "<td align=center>赵六</td>";
    //html += "<td align=center>100</td>";
    //html += "<td align=center>400</td>";
    //html += "</tr>";
    //html += "</table>";
    QString html;
    html = "<table width=100% border=1 cellspacing=0 text-align=center style=border-collapse:collapse>";
    html += "<tr>";
    html += "<th>编号</th>";
    html += "<th>姓名</th>";
    html += "<th>头部成绩</th>";
    html += "<th>胸部成绩</th>";
    html += "</tr>";
    QStringList dataStringList;
    QStringList rowInfoList;
    html += "<tr>";
    foreach(QString str, dataStringList)
    {
        rowInfoList = str.split(",");
        for(int i = 0; i < 8; i += 2)
        {
            if(rowInfoList[i] == "number")
            {
                html = html + "<td align=center>" + rowInfoList[i + i] + "</td>";
            }
            else if(rowInfoList[i] == "name")
            {
                html = html + "<td align=center>" + rowInfoList[i + i] + "</td>";
            }
            else if(rowInfoList[i] == "headscore")
            {
                html = html + "<td align=center>" + rowInfoList[i + i] + "</td>";
            }
            else if(rowInfoList[i] == "bodyscore")
            {
                html = html + "<td align=center>" + rowInfoList[i + i] + "</td>";
            }
        }
    }
    html += "</tr>";
    html += "</table>";
    return html;
}

void MainWindow::on_actionAsdf_triggered()
{
    QString name = QFileDialog::getOpenFileName (this, "打开", "/", "svg file(*.svg)");
    svgWindow->setFile (name);
}
