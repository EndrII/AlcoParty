#include "song.h"

namespace syncLib{

SongHeader::SongHeader()
{
    this->id = -1;
    this->name = "";
    this->size = 0;
}

SongHeader& SongHeader::operator =(const SongHeader& right){
    this->id = right.id;
    this->name = right.name;
    this->size = right.size;
    return *this;
}

bool SongHeader::operator ==(const SongHeader& right){
    return this->name == right.name && this->size == right.size;
}

unsigned int SongHeader::getSize() const{
    QByteArray size;
    QDataStream stream(size);
    stream << id << name << this->size;
    return size.size();
}

bool SongHeader::isValid() const{

    return id > -1 && !name.isEmpty() && size > 0 && name.endsWith(".mp3");

}

SongHeader::~SongHeader(){}



Song::Song():
    SongHeader()
{
    source.clear();
}

QDataStream& operator << (QDataStream& stream, const SongHeader& song){
    stream << song.id;
    stream << song.name;
    stream << song.size;
    return stream;
}
QDataStream& operator >> (QDataStream& stream, SongHeader& song){
    stream >> song.id;
    stream >> song.name;
    stream >> song.size;
    return stream;
}

Song::Song(const SongHeader& from)
    :Song::Song()
{
    this->id = from.id;
    this->name = from.name;
    this->size = from.size;
}

void Song::clear(){
    source.clear();
}

unsigned int Song::getSize() const{
    return SongHeader::getSize() + source.size();
}

const QByteArray& Song::getSource()const{
    return source;
}

bool Song::isValid() const{

    return SongHeader::isValid() && source.size() == size;
}

Song::~Song(){
    source.clear();
}

QDataStream& operator << (QDataStream& stream,const Song& song){
    stream << static_cast<const SongHeader&>(song);
    stream << song.source;
    return stream;
}

QDataStream& operator >> (QDataStream& stream, Song& song){
    stream >> static_cast<SongHeader&>(song);
    stream >> song.source;
    return stream;
}

}
