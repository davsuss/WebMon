#ifndef XMLTODATABASE_H
#define XMLTODATABASE_H

#include <QSqlDatabase>
#include <QSqlField>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

#include <QFile>
#include <QtXmlPatterns/QXmlSchema>
#include <QtXml/QXmlStreamReader>
#include <QtXmlPatterns/QXmlSchemaValidator>

void updateDatabase(QString pathToDatabaseFile);
void createTables();
void updateTables();
void clearTables();
bool validateXML();
void readALLPokemon();
void readALLMoves();
void readALLTypeEffectiveness();

#endif // XMLTODATABASE_H
