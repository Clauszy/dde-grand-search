/*
 * Copyright (C) 2021 Uniontech Software Technology Co., Ltd.
 *
 * Author:     zhangyu<zhangyub@uniontech.com>
 *
 * Maintainer: zhangyu<zhangyub@uniontech.com>
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

#ifndef TASKCOMMANDER_H
#define TASKCOMMANDER_H

#include "global/matcheditem.h"

#include <QObject>

namespace GrandSearch {

class ProxyWorker;
class TaskCommanderPrivate;
class TaskCommander : public QObject
{
    Q_OBJECT
    friend class TaskCommanderPrivate;
public:
    explicit TaskCommander(const QString &content, QObject *parent = nullptr);
    QString taskID() const;
    QString content() const;
    void setContent(const QString &content);
    bool start();
    void stop();
    MatchedItemMap getResults() const;
    MatchedItemMap readBuffer() const;
    bool isEmptyBuffer() const;
    bool join(ProxyWorker *);
    void deleteSelf();
    bool isFinished() const;
protected:
    ~TaskCommander();
signals:
    void matched();
    void finished();
private:
    TaskCommanderPrivate *d;
};

}

#endif // TASKCOMMANDER_H
