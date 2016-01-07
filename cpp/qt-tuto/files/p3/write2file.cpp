#include <QTextStream>
#include <QFile>

int main(void) {
	QTextStream out(stdout);

	QString filename = "distros";
	QFile file(filename);

	if (file.open(QIODevice::WriteOnly)) {
		QTextStream out(&file);

		out << "Xubuntu" << endl;
		out << "Debian" << endl;
		out << "Slackware" << endl;
	}
	else {
		qWarning("Could not open file");
	}

	file.close();

	return 0;
}
