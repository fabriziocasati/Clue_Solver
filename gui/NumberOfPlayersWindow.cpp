#include <QtWidgets>
#include "NumberOfPlayersWindow.h"
#include "gui/NamesOfThePlayersWindow.h"
#include <string>
#include <boost/lexical_cast.hpp>

NumberOfPlayersWindow::NumberOfPlayersWindow(NewGameCreator *newGameCreator, QWidget *parent)
    : QDialog(parent) {

    this->newGameCreator = newGameCreator;
    setModal(true);

    //setAttribute(Qt::WA_DeleteOnClose);
    //move(300,300);

    QVBoxLayout *vbox = new QVBoxLayout;

    QLabel *l = new QLabel("Select the number of players for the new game");
    l->setStyleSheet("font-weight: bold;");
    QGroupBox *groupBox = new QGroupBox("Select the number of players");
    //groupBox->setStyleSheet("border: 1px solid gray; border-radius: 9px; font-weight: normal;");
    //groupBox->setFlat(true);

    confirmButton = new QPushButton("Ok", this);
    confirmButton->setDisabled(true);
    connect(confirmButton, SIGNAL (clicked()), this, SLOT (confirmButtonClicked()));
    //connect(m_button, SIGNAL (clicked()), this->parent(), SLOT (setSubwindow(w)));

    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(1);

    QVBoxLayout *hbox = new QVBoxLayout;

    for(int i=0; i<MAX_NUMBER_OF_PLAYERS - MIN_NUMBER_OF_PLAYERS + 1; i++) {
        std::string numberString = boost::lexical_cast<std::string>(i + MIN_NUMBER_OF_PLAYERS) + " players";
        QString numberQString = QString::fromStdString(numberString);
        numberOfPlayersRadioButton[i] = new QRadioButton(numberQString);
        connect(numberOfPlayersRadioButton[i], SIGNAL (clicked()), this, SLOT (enableConfirmButton()));
        hbox->addWidget(numberOfPlayersRadioButton[i]);
        hbox->addStretch(1);
    }

    groupBox->setLayout(hbox);

    vbox->addWidget(groupBox, 0, Qt::AlignCenter);
    vbox->addWidget(confirmButton, 1, Qt::AlignCenter);

    setWindowTitle("Number of Players");

    setLayout(vbox);

    //setWindowFlags( (windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowMaximizeButtonHint);
    //setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    //setWindowFlags(Qt::Dialog | Qt::WindowTitleHint);
    //setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    //setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
}

void NumberOfPlayersWindow::confirmButtonClicked() {
    int numberOfPlayers;
    for(numberOfPlayers = MIN_NUMBER_OF_PLAYERS; numberOfPlayers <= MAX_NUMBER_OF_PLAYERS; numberOfPlayers++) {
        if(numberOfPlayersRadioButton[numberOfPlayers - MIN_NUMBER_OF_PLAYERS]->isChecked())
            break;
    }

    newGameCreator->setNumberOfPlayers(numberOfPlayers);
    newGameCreator->openNextWindow();

    //this->parentWidget()->close();
    close();
    destroy();

}

void NumberOfPlayersWindow::enableConfirmButton() {
    confirmButton->setDisabled(false);
}

void NumberOfPlayersWindow::closeEvent(QCloseEvent *e)
{
    e->ignore();
}

