/*
    Cannabis-qt
    Copyright (C) 2012 Karasu

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CHOOSEOPTION_H
#define CHOOSEOPTION_H

#include <QWidget>
#include <QPushButton>
// #include <QToolButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QMap>

class ChooseOption : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseOption(QWidget *parent = 0);

    QMap <QString, QPushButton *> buttons;
    QMap <QString, QLabel *> labels;

protected:
    void setMyStyleSheet(void);

signals:
    
public slots:
};

#endif // CHOOSEOPTION_H
