#ifndef serverfunction_h
#define serverfunction_h

#include <QCoreApplication>
#include <QString>
#include <stdio.h>
#include "database.h"
#include "tasks.h"
#include <QDebug>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QCryptographicHash>

/*
parsing is a function that processes client messages: extracts the command and arguments, and then calls the corresponding function
Argument data - message received from the client
Return value is the response of the corresponding function
*/
QByteArray parse(QByteArray request);
QByteArray auth(QJsonObject request);
QByteArray reg(QJsonObject request);
QByteArray getAllStat(QJsonObject request);
QByteArray getUserStat(QJsonObject request);
QByteArray getTask(QJsonObject request);
QByteArray checkTask(QJsonObject request);

bool isTeacher(QString userToken);
#endif
