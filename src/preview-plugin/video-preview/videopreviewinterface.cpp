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
#include "videopreview_global.h"
#include "videopreviewinterface.h"
#include "videopreviewplugin.h"

GRANDSEARCH_USE_NAMESPACE
using namespace GrandSearch::video_preview;

VideoPreviewInterface::VideoPreviewInterface(QObject *parent)
  : QObject(parent)
  , PreviewPluginInterface()
{

}

PreviewPlugin *VideoPreviewInterface::create(const QString &mimetype)
{
    return new VideoPreviewPlugin();
}
