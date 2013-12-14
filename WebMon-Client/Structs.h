#ifndef STRUCTS_H
#define STRUCTS_H
const QString path = "./Resources/gifs/";
const QString background = "./Resources/Pictures/Battle.png";
struct PokemonInfo
{
QString name;
int level;
int hp;
QList<QString> moves;
};

#endif // STRUCTS_H
