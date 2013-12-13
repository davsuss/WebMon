#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include "server.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
QT_END_NAMESPACE

/**
 * @brief : Provides an UI for the user
 *
 */
class Dialog : public QWidget
{
    Q_OBJECT

public:
    /**
    * @brief : create the dialog
    *
    * @param parent : parent
    */
    Dialog(QWidget *parent = 0);

public slots:
    /**
     * @brief : invoked whent he quit button is clicked.
     *          ends all threads
     */
    void finishedwithwork();

private:
    QLabel *statusLabel; /**< Label for update statuses */
    QPushButton *quitButton; /**< quit button */
    server GameServer; /**< server object that takes care of all incoming connections */
};

#endif
