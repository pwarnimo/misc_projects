#include <QTextStream>
#include <QFileInfo>

int main(int argc, char *argv[]) {
	QTextStream out(stdout);

	if (argc != 2) {
		qWarning("Usage: p1 file");
		return 1;
	}

	QString filename = argv[1];

	if (!QFile(filename).exists()) {
		qWarning("The file does not exist");
		return 1;
	}

	QFileInfo fileinfo(filename);

	qint64 size = fileinfo.size();

	QString str = "The size is %1 bytes";

	out << str.arg(size) << endl;
	
	return 0;
}
