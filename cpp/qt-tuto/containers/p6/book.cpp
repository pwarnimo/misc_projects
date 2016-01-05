#include <QString>
#include "book.h"

Book::Book(QString authr, QString titl) {
	author = authr;
	title = titl;
}

QString Book::getAuthor() const {
	return author;
}

QString Book::getTitle() const {
	return title;
}
