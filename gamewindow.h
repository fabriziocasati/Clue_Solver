#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <newinquirywindow.h>
#include <game.h>
#include <QLabel>
#include <QTableWidget>
#include <inquiryhistorywindow.h>

class Game;
class QPushButton;

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    GameWindow(Game *game, QWidget *parent = 0);

    Game *game;
    QLabel *label;
    QPushButton *m_button2;
    QTableWidget *cardTable;

    void myupdate();

public slots:
    void openQueryListWindow();
    void test();
};

#endif // GAMEWINDOW_H
