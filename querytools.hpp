#ifndef QUERYTOOLS_HPP
#define QUERYTOOLS_HPP

#include <QtSql/QSqlQuery>
#include <QString>
#include <QVariant>

QSqlQuery runQuery(const QString& sql);

QSqlQuery findQuery(const QString& select, const QString& from,
                  const QString& where, const QString& whereItem,
                  const QString& where2 = "", const QString& whereItem2 = "");

#endif // QUERYTOOLS_HPP

