#include <QTextStream>

int main(void) {
	QTextStream out(stdout);

	QString f1 = "Name: ";
	QString f2 = "Occupation: ";
	QString f3 = "Residence: ";
	QString f4 = "Marital status: ";

	int width = f4.size();

	out << f1.rightJustified(width, ' ') << "John\n";
	out << f2.rightJustified(width, ' ') << "Programmer\n";
	out << f3.rightJustified(width, ' ') << "New York\n";
	out << f4.rightJustified(width, ' ') << "Single\n";

	return 0;
}
