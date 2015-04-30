#include "querytools.hpp"

QSqlQuery runQuery(const QString& sql)
{
    QSqlQuery query(sql);
    query.exec();
    return query;
}


QSqlQuery findQuery(const QString& select, const QString& from,
                  const QString& where, const QString& whereItem,
                  const QString& where2, const QString& whereItem2)
{
    QString sql;
    QSqlQuery query;

    sql = "SELECT \"";
    sql.append(select);
    sql.append("\" FROM ");
    sql.append(from);
    sql.append(" WHERE \"");
    sql.append(where);
    sql.append("\"=\"");
    sql.append(whereItem);
    if (where2 != "")
    {
        sql.append("\" AND \"");
        sql.append(where2);
        sql.append("\"=\"");
        sql.append(whereItem2);
    }
    sql.append("\"");
    query = runQuery(sql);
    query.next();

    return query;
}
