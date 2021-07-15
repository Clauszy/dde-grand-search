/*
 * Copyright (C) 2021 Uniontech Software Technology Co., Ltd.
 *
 * Author:     wangchunlin<wangchunlin@uniontech.com>
 *
 * Maintainer: wangchunlin<wangchunlin@uniontech.com>
 *             houchengqiu<houchengqiu@uniontech.com>
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
#include "exhibitionwidget_p.h"
#include "exhibitionwidget.h"
#include "matchresult/matchwidget.h"

#include <QPalette>
#include <QHBoxLayout>
#include <QPainter>
#include <QPushButton>

DWIDGET_USE_NAMESPACE
using namespace GrandSearch;

ExhibitionWidgetPrivate::ExhibitionWidgetPrivate(ExhibitionWidget *parent)
    : q_p(parent)
{

}

ExhibitionWidget::ExhibitionWidget(QWidget *parent)
    : DWidget(parent)
    , d_p(new ExhibitionWidgetPrivate(this))
{
    initUi();
    initConnect();

    //test_search();
}

ExhibitionWidget::~ExhibitionWidget()
{

}

void ExhibitionWidget::connectToController()
{
    m_matchWidget->connectToController();
}

void ExhibitionWidget::test_search()
{

    MatchedItemMap matchedData;

    int nAppCount = 4;
    int nFolderCount = 5;
    int nFileCount = 6;

    // app
    matchedData[GroupHash_App].clear();
    for (int i = 0; i < nAppCount; i++) {
        MatchedItem item;
        item.name = QString("%1%2").arg(GroupName_App).arg(i + 1);
        matchedData[GroupHash_App].push_back(item);
    }

    // folder
    matchedData[GroupHash_Folder].clear();
    for (int i = 0; i < nFolderCount; i++) {
        MatchedItem item;
        item.name = QString("%1%2").arg(GroupName_Folder).arg(i + 1);
        matchedData[GroupHash_Folder].push_back(item);
    }

    // file
    matchedData[GroupHash_File].clear();
    for (int i = 0; i < nFileCount; i++) {
        MatchedItem item;
        item.name = QString("%1%2").arg(GroupName_File).arg(i + 1);
        matchedData[GroupHash_File].push_back(item);
    }

    if (m_matchWidget)
        m_matchWidget->setMatchedData(matchedData);
}

void ExhibitionWidget::test_clear()
{
    MatchedItemMap matchedData;
    matchedData.clear();

    if (m_matchWidget)
        m_matchWidget->setMatchedData(matchedData);
}

void ExhibitionWidget::initUi()
{
    m_hLayout = new QHBoxLayout(this);
    m_hLayout->setContentsMargins(8, 0, 0, 8);
    m_hLayout->setSpacing(0);
    this->setLayout(m_hLayout);

    m_matchWidget = new MatchWidget(this);
    m_hLayout->addWidget(m_matchWidget);
}

void ExhibitionWidget::initConnect()
{

}

void ExhibitionWidget::paintEvent(QPaintEvent *event)
{
#ifdef SHOW_BACKCOLOR
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setBrush(Qt::yellow);
    painter.drawRect(rect());
#else
    DWidget::paintEvent(event);
#endif
}


