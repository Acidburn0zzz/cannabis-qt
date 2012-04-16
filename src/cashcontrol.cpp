#include "cashcontrol.h"
#include "cashcontrolmodel.h"

CashControl::CashControl(QWidget *parent) :
    QWidget(parent)
{
    QLabel *dataInicialLabel = new QLabel(tr("Data inicial:"));
    dataInicial = new QDateEdit(QDate::currentDate());
    dataInicial->setDisplayFormat("dd/MM/yyyy");
    dataInicial->setCalendarPopup(true);

    QLabel *dataFinalLabel = new QLabel(tr("Data final:"));
    dataFinal = new QDateEdit(QDate::currentDate());
    dataFinal->setDisplayFormat("dd/MM/yyyy");
    dataFinal->setCalendarPopup(true);

    QPushButton *showButton = new QPushButton(tr("Mostra els moviments!"));
    connect(showButton, SIGNAL(pressed()), this, SLOT(onShow()));

    QVBoxLayout *vbox11 = new QVBoxLayout;
    vbox11->addWidget(dataInicialLabel);
    vbox11->addWidget(dataFinalLabel);

    QVBoxLayout *vbox22 = new QVBoxLayout;
    vbox22->addWidget(dataInicial);
    vbox22->addWidget(dataFinal);





    QHBoxLayout *hbox3 = new QHBoxLayout;
    hbox3->addLayout(vbox11);
    hbox3->addLayout(vbox22);
    hbox3->addWidget(showButton);

    CashControlModel *model = new CashControlModel();

    model->setHeaderData(0, Qt::Horizontal, tr("Data"));
    model->setHeaderData(1, Qt::Horizontal, tr("Grams"));
    model->setHeaderData(2, Qt::Horizontal, tr("Ingressos (cànnabis)"));
    model->setHeaderData(3, Qt::Horizontal, tr("Ingressos (altres)"));
    model->setHeaderData(4, Qt::Horizontal, tr("Ingressos (total)"));

    tableView = new QTableView;
    tableView->setModel(model);
    tableView->setCornerButtonEnabled(false);
    tableView->resizeColumnsToContents();
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->show();

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Help);
    connect(buttonBox, SIGNAL(helpRequested()), this, SLOT(onHelp()));

    QPushButton *printButton = new QPushButton(tr("Imprimeix"));
    connect(printButton, SIGNAL(pressed()), this, SLOT(onPrint()));

    QHBoxLayout *hbox4 = new QHBoxLayout;
    hbox4->addWidget(printButton);
    hbox4->addWidget(buttonBox);


    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addLayout(hbox3);
    vbox->addWidget(showButton);
    vbox->addWidget(tableView);
    vbox->addLayout(hbox4);

    setLayout(vbox);
}

void CashControl::onHelp()
{
    QMessageBox *msgBox = new QMessageBox(this);

    msgBox->setStyleSheet("QLabel { font: 12px; min-height: 30px; max-height: 60px; }");

    msgBox->setText(tr("blah blah blah"));

    msgBox->exec();
}

void CashControl::resizeTableViewToContents()
{
    if (tableView != NULL)
    {
        tableView->resizeColumnsToContents();
    }
}

void CashControl::onShow()
{
    CashControlModel *model = static_cast<CashControlModel *>(tableView->model());

    model->setDates(dataInicial->date().toString("dd/MM/yyyy"), dataFinal->date().toString("dd/MM/yyyy"));


    tableView->resizeColumnsToContents();
    tableView->horizontalHeader()->setStretchLastSection(true);
}

void CashControl::onPrint()
{
}
