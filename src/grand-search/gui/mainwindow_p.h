/*
 * Copyright (C) 2021 Uniontech Software Technology Co., Ltd.
 *
 * Author:     wangchunlin<wangchunlin@uniontech.com>
 *
 * Maintainer: wangchunlin<wangchunlin@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MAINWINDOW_P_H
#define MAINWINDOW_P_H

#include "mainwindow.h"

#include <QWidget>


DWIDGET_BEGIN_NAMESPACE
class DLabel;
DWIDGET_END_NAMESPACE
class QVBoxLayout;

namespace GrandSearch {
class EntranceWidget;
class ExhibitionWidget;
class HandleVisibility;
class QueryController;
class MatchController;

class MainWindowPrivate
{
public:
    explicit MainWindowPrivate(MainWindow *parent);

    MainWindow *q_p = nullptr;
    HandleVisibility *m_handleVisibility = nullptr;
    EntranceWidget *m_entranceWidget = nullptr;
    ExhibitionWidget *m_exhibitionWidget = nullptr;
    Dtk::Widget::DLabel *m_searchNoContentWidget = nullptr;
    QVBoxLayout *m_mainLayout = nullptr;
    QueryController *m_queryController = nullptr;
    MatchController *m_matchController = nullptr;
};

}

#endif // MAINWINDOW_P_H
