#include "inquiryhistorywindow.h"
#include <boost/lexical_cast.hpp>

InquiryHistoryWindow::InquiryHistoryWindow(Game *g, QWidget *parent)
    : QWidget(parent)
{

    this->g = g;

    inquiryHistoryTable = new QTableWidget(this);

    inquiryHistoryTable->setRowCount(100);
    inquiryHistoryTable->setColumnCount(3);
    //inquiryHistoryTable<<"#"<<"Name"<<"Text";
    //inquiryHistoryTable->setHorizontalHeaderLabels(m_TableHeader);
    //inquiryHistoryTable->verticalHeader()->setVisible(false);
    //inquiryHistoryTable->verticalScrollBar()->setEnabled(true);
    inquiryHistoryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    inquiryHistoryTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    inquiryHistoryTable->setSelectionMode(QAbstractItemView::SingleSelection);
    //inquiryHistoryTable->setShowGrid(false);
    //inquiryHistoryTable->setStyleSheet("QTableView {selection-background-color: red; color: yellow; background: blue; border: 1px solid white}");
    inquiryHistoryTable->resize(400,200);

    resize(600,400);


    std::string numberString = boost::lexical_cast<std::string>(g->inquiryList->front()->i) ;
    QString numberQString = QString::fromStdString(numberString);

    inquiryHistoryTable->setItem(0, 0, new QTableWidgetItem("Hello"));
    //inquiryHistoryTable->setItem(0, 1, new QTableWidgetItem("Hello"));
    inquiryHistoryTable->setItem(0, 1, new QTableWidgetItem(numberQString));

    std::list<Inquiry*>::iterator it=g->inquiryList->begin();
    int index=0;
    for (; it != g->inquiryList->end(); index++, ++it) {
        std::string numberString = boost::lexical_cast<std::string>((*it)->i) ;
        QString numberQString = QString::fromStdString(numberString);

        inquiryHistoryTable->setItem(index, 0, new QTableWidgetItem("Hello"));
        inquiryHistoryTable->setItem(index, 1, new QTableWidgetItem(numberQString));
    }


    // constructors used in the same order as described above:
      std::list<int> first;                                // empty list of ints
      std::list<int> second (4,100);                       // four ints with value 100
      std::list<int> third (second.begin(),second.end());  // iterating through second
      std::list<int> fourth (third);                       // a copy of third

      // the iterator constructor can also be used to construct from arrays:
      int myints[] = {16,2,77,29};
      std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

      std::cout << "The contents of fifth are: ";
      for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
        std::cout << *it << ' ';

      std::cout << '\n';
}

