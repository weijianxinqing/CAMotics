/******************************************************************************\

    CAMotics is an Open-Source simulation and CAM software.
    Copyright (C) 2011-2017 Joseph Coffland <joseph@cauldrondevelopment.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#pragma once

#include <cbang/json/JSON.h>

#include <QObject>
#include <QtWebSockets/QtWebSockets>

class QNetworkAccessManager;


namespace CAMotics {
  class QtWin;

  class BBCtrlAPI : public QObject {
    Q_OBJECT;

    QtWin *parent;
    QNetworkAccessManager *netManager;

    bool active;
    bool _connected;
    uint64_t lastMessage;
    QTimer updateTimer;
    QTimer reconnectTimer;

    QWebSocket webSocket;
    QUrl url;
    std::string filename;

    cb::JSON::Dict vars;

  public:
    BBCtrlAPI(QtWin *parent);

    bool isConnected() const {return _connected;}

    void connectCNC(const QString &address);
    void disconnectCNC();
    void reconnect();
    void setFilename(const std::string &filename) {this->filename = filename;}
    void uploadGCode(const char *data, unsigned length);

  signals:
    void connected();
    void disconnected();

  protected slots:
    void onError(QAbstractSocket::SocketError error);
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(const QString &message);
    void onUpdate();
    void onReconnect();
  };
}
